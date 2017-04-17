path "models";        // Path to model subdirectory
path "sounds";        // Path to sound subdirectory
path "bmaps";                // Path to graphics subdirectory
Path "d:\\A4BETA\\template";        // Path to WDL templates subdirectory

include <hh_ent.wdl>;

var video_mode = 7;
var video_depth = 16;
var compatibility=0;	//old (buggy) way of displaying entity panels
			//demo was created with older version
                        //so this setting is required

//definitions for commandline options

ifdef HICOLOR;
        var VIDEO_DEPTH=32;
endif;
ifdef VIDEO1;
        var VIDEO_MODE = 1;    // V320x200
endif;
ifdef VIDEO2;
        var VIDEO_MODE = 2;    // V320x240
endif;
ifdef VIDEO3;
        var VIDEO_MODE = 3;    // V320x400
endif;
ifdef VIDEO4;
        var VIDEO_MODE = 4;    // V400x300
endif;
ifdef VIDEO5;
        var VIDEO_MODE = 5;    // V512x384
endif;
ifdef VIDEO6;
        var VIDEO_MODE = 6;    // V640x480
endif;
ifdef VIDEO7;
        var VIDEO_MODE = 7;    // V800x600
endif;
ifdef VIDEO8;
        var VIDEO_MODE = 8;    // V1024x768
endif;
ifdef VIDEO9;
        var VIDEO_MODE = 9;    // V1280x960
endif;
ifdef VIDEO10;
        var VIDEO_MODE = 10;   // V1600x1200
endif;

//bind external bitmaps to resource

bind <msg1.pcx>;
bind <msg2.pcx>;
bind <msg3.pcx>;
bind <msg4.pcx>;
bind <msg5.pcx>;
bind <msg6.pcx>;
bind <msg7.pcx>;
bind <msg8.pcx>;
bind <msg9.pcx>;
bind <msg10.pcx>;
bind <msg11.pcx>;
bind <msg12.pcx>;
bind <msg13.pcx>;
bind <msg14.pcx>;
bind <msg15.pcx>;
bind <msg16.pcx>;
bind <msg17.pcx>;
bind <msg18.pcx>;

bind <gchar1.pcx>;
bind <gchar2.pcx>;
bind <gchar3.pcx>;
bind <gchar4.pcx>;
bind <gchar5.pcx>;
bind <gchar6.pcx>;
bind <echar1.pcx>;
bind <echar2.pcx>;
bind <echar3.pcx>;
bind <echar4.pcx>;
bind <echar5.pcx>;
bind <echar6.pcx>;

bind <good1.pcx>;
bind <good2.pcx>;
bind <good3.pcx>;
bind <good4.pcx>;
bind <good5.pcx>;
bind <good6.pcx>;

bind <evil1.pcx>;
bind <evil2.pcx>;
bind <evil3.pcx>;
bind <evil4.pcx>;
bind <evil5.pcx>;
bind <evil6.pcx>;

bind <hell1.pcx>;
bind <hell2.pcx>;
bind <hell3.pcx>;
bind <hell4.pcx>;
bind <hell5.pcx>;
bind <hell6.pcx>;
bind <hell7.pcx>;
bind <hell8.pcx>;

bind <credits1.pcx>;
bind <credits2.pcx>;
bind <credits3.pcx>;
bind <credits4.pcx>;
bind <credits5.pcx>;
bind <credits6.pcx>;

bind <ackfont.pcx>; //font is never needed in the demo - bug?

var timer=0;
var helltimer=0;
var heaventimer=0;
//var fps_max=30; //fps were limited because of possible bad scripting
var scene=0;
var scenefade=0;
var sndhandle;
var clock_abs;
var clock;
var clock_setoff;
var warn_level=2;
var msgposx[20];
var msgposy[20];
var msgfx[20];
sound bg_music, <nb_clysm.wav>;

//additional views

view heavencam
{
        arc 60;
        layer 8;
        fog=50;
}

view fadecam
{
        arc 60;
        layer 8;
        fog=50;
}

///////////////////

function main()
{

        if (video_depth<16)
        {
		//highcolor only, because of fading fx
                wait (1);
                exit;
        }
	//setting position and effect for messages
        msgposx[2]=50; msgposy[2]=50; msgfx[2]=2;
        msgposx[3]=70; msgposy[3]=30; msgfx[3]=1;
        msgposx[4]=-10; msgposy[4]=-10; msgfx[4]=4;
        msgposx[5]=-30; msgposy[5]=-30; msgfx[5]=3;
        msgposx[6]=-50; msgposy[6]=-50;
        msgposx[7]=-70; msgposy[7]=-70; msgfx[7]=2;
        msgfx[8]=4;
        msgfx[9]=2;
        msgposx[10]=50; msgposy[10]=50; msgfx[10]=4;
        msgposx[11]=70; msgposy[11]=30; msgfx[11]=1;
        msgposx[12]=-10; msgposy[12]=-10; msgfx[12]=3;
        msgposx[13]=-30; msgposy[13]=-30; msgfx[13]=4;
        msgposx[14]=-50; msgposy[14]=-50;
        msgfx[15]=3;
        msgposx[16]=-70; msgposy[7]=-70; msgfx[7]=2;
        msgfx[17]=4;
        msgposx[18]=0; msgposy[18]=0; msgfx[18]=1;


	//init views
        camera.pos_x=0;
        camera.pos_y=screen_size.y/6;
        camera.size_x=screen_size.x;
        camera.size_y=screen_size.y/3*2;
        camera.aspect=0.67;
        heavencam.pos_x=0;
        heavencam.pos_y=screen_size.y/6;
        heavencam.size_x=screen_size.x;
        heavencam.size_y=screen_size.y/3*2;
        heavencam.aspect=0.67;
        tex_share = on;

        wait(3);

        play_sound  (bg_music,10);
        sndhandle=result;
        wait 1;
        stop_sound (sndhandle);
	//dummy sfx playback to load sound into memory at startup
        load_level(<hh_demo.wmb>);
	while(1)
	{
		timer+=time;
		helltimer+=time;
		heaventimer+=time;
		wait (1);
		//timers used to start certain effects time corrected
                //required to stay in touch with bgm
	}
}

function clock_control() {
        clock_abs=sys_hours*3600+sys_minutes*60+sys_seconds;
        clock_setoff=clock_abs;
        while(1)
        {
                clock_abs=sys_hours*3600+sys_minutes*60+sys_seconds;
                clock=clock_abs-clock_setoff;
                wait (1);
        }
	//calculate demo running time in seconds
}


//start window definition

window winstart
{
        title "The Conflict";
        size 370,297;
        mode image;

        bg_color rgb(0,0,0);
        bg_pattern <logo.pcx>,opaque;
}




var speed[3];

//defines for moving entities
define speedX,SKILL33;
define speedY,SKILL34;
define speedZ,SKILL35;
define targetX,SKILL43;
define targetY,SKILL44;
define targetZ,SKILL45;
define forceX,SKILL30;
define forceY,SKILL31;
define forceZ,SKILL32;


//animate layers on left side in hell part
function swap_layers()
{
        while (scene<=2)
        {
                hell_ent.scale_y*=-1;
                hell2_ent.scale_y*=-1;
                hell3_ent.scale_y*=-1;
                hell4_ent.scale_y*=-1;
                waitt (4);
        }
}

function anim_layer()
{
        while (scene<2) {wait (1);}
        hell_ent.visible=1;
        hell2_ent.visible=1;
        hell_ent.alpha=40;
        hell2_ent.alpha=20;
        hell3_ent.alpha=0;
        hell4_ent.alpha=0;
        swap_layers();
        while (scene==2)
        {
		//fade out layers on left side of hell part
                //when switching to next scene
                hell_ent.alpha-=time+time+time;
                hell2_ent.alpha-=time+time+time;
                hell3_ent.alpha-=time+time+time;
                hell4_ent.alpha-=time+time+time;
                hell_ent.y=250+20*sin(timer*14+30);
                hell2_ent.y=250+20*cos(timer*14+60);
                hell3_ent.y=250+20*sin(timer*14+90);
                hell4_ent.y=250+20*cos(timer*14+120);
                if (hell_ent.alpha<=25 && hell2_ent.visible==0)
                {
                        hell2_ent.alpha=40;
                        hell2_ent.visible=1;
                }
                if (hell2_ent.alpha<=25 && hell3_ent.visible==0)
                {
                        hell3_ent.alpha=40;
                        hell3_ent.visible=1;
                }
                if (hell3_ent.alpha<=25 && hell4_ent.visible==0)
                {
                        hell4_ent.alpha=40;
                        hell4_ent.visible=1;
                }
                if (hell4_ent.alpha<=25 && hell_ent.visible==0)
                {
                        hell_ent.alpha=40;
                        hell_ent.visible=1;
                }

                if (hell_ent.alpha<=0) {hell_ent.visible=0;}
                if (hell2_ent.alpha<=0) {hell2_ent.visible=0;}
                if (hell3_ent.alpha<=0) {hell3_ent.visible=0;}
                if (hell4_ent.alpha<=0) {hell3_ent.visible=0;}
                wait (1);
        }
        hell_ent.visible=0;
        hell2_ent.visible=0;
        hell3_ent.visible=0;
        hell4_ent.visible=0;
}

//hell part particle fountain
function vec_randomize(&vec,range)
{
	vec[0] = random(2) - 1;
	vec[1] = random(2) - 1;
	vec[2] = random(20);
	vec_normalize(vec,random(range));
}

function part_alphafade()
{
	my.alpha -= time+time;
	if (my.alpha <= 0) { my.lifespan = 0; }
}

function effect_explo()
{
	vec_randomize(temp,50);
	vec_add(my.vel_x,temp);
	my.alpha = 25 + random(25);
	my.red=150;
	my.green=110;
	my.blue=20;
	my.flare = on;
	my.bright = on;
	my.streak = on; //pro version only
	my.move = on;
	my.function = part_alphafade;
}


function particle_emitter()
{
	my.invisible=1;
	my.passable=1;
	my.z=-200;
	wait (1);
	while(scene<=2)
	{
		vec_scale(normal,10);
		effect(effect_explo,300,my.x,normal);
		waitt (48); //not very accurate, bad style
	}
}

var count=0;
string file_str,"123456789012";
string hell_str,"hell";
string pcx_str, ".pcx";
string number_str," ";

function hell_msg()
{
        while (scene<2) {wait (1);}
        waitt (48);
        while (scene==2 &&scenefade<3)
        {
		//create filenames and load pcx files
                wait (1);
                count+=1;
                if (count>8)
                {
                        count=1;
                }
                str_for_num(number_str,count);
                str_cpy(file_str,hell_str);
                str_cat(file_str,number_str);
                str_cat(file_str,pcx_str);
                wait (1);
                ent_morph(hellmsg_ent,file_str);
                hellmsg_ent.alpha=50;
                hellmsg_ent.y=-40+(random(140)-70);
                hellmsg_ent.z=(random(100)-50);
                hellmsg_ent.visible=1;
                while (hellmsg_ent.alpha>0)
                {
                        wait (1);
                        hellmsg_ent.alpha-=time*7;
                }
                hellmsg_ent.visible=0;
                ent_purge(hellmsg_ent);
        }
        hellmsg_ent.visible=0;
        ent_purge(hellmsg_ent);

}

//applied to terrain for hell part
action terrain_center
{
	while (scenefade!=2) {wait 1;}
	my.invisible=1;
	my.passable=1;
	create <cube.wmb>,my.pos,particle_emitter(); //old style
	while (scene<=2)
	{
		//make camera look to particle emitter
		my.z=200*sin(timer*8);
		temp.x = my.x - camera.x;
		temp.y = my.y - camera.y;
		temp.z = my.z - camera.z;
		vec_to_angle(my_angle.pan,temp);
		camera.pan += 0.1*ang(my_angle.pan-camera.pan)*min(1,time);
		camera.tilt += 0.1*ang(my_angle.tilt-camera.tilt)*min(1,time);
		wait (1);
	}
}

function fade_in_border()
{
        hellborder_ent.alpha=0;
        hellborder_ent.visible=1;
        hellborder_ent.transparent=1;
        while(hellborder_ent.alpha<100)
        {
                wait (1);
                hellborder_ent.alpha+=time+time;
        }
        hellborder_ent.alpha=50;
        hellborder_ent.transparent=0;
}

//attached to dummy entity which is following a path
//camera is dragged along seperately because
//otherwise movement is too limited
action walk_path
{
	while (scenefade!=2) {wait 1;}
	//init basic functions (see above)
	fade_in_hell();
	hell_msg();
	anim_layer();
	fade_in_border();
	helltimer=0; //reset timer
	my.oriented=1;
	my.invisible=1; //dummy entity only
	my.forcex=12;
	//scan nearest path
	temp.pan = 360;
	temp.tilt = 180;
	temp.z = 1000;
	result = scan_path(my.x,temp);
	if (result == 0) { return; }
	ent_waypoint(my.targetx,1);
	while (scene<=2)
	{
		my.forcex=12+7*sin(helltimer*7);
		temp.x = my.targetx - my.x;
		temp.y = my.targety - my.y;
		temp.z = my.targetz - my.z;
		result = vec_to_angle(my_angle.pan,temp);
		//waypoint reached?
		if (result < 50) {
			ent_nextpoint(my.targetx);
		}
		camera.roll=40*cos(helltimer*6);
		my.pan=my_angle.pan;
		my.tilt=my_angle.tilt;
		//movement stuff taken from templates
	        temp = min(time*0.55,1);
	        my.speedx += (time * my.forcex) - (temp * my.speedx);
	        my.speedy += (time * my.forcey) - (temp * my.speedy);
	        my.speedz += (time * my.forcez) - (temp * my.speedz);
	        speed.x=my.speedx*time;
	        speed.y=my.speedy*time;
	        speed.z=my.speedz*time;
	        you=null;
	        move me,speed,nullvector; //old syntax
	        vec_set(temp.x,my.x);
	        vec_set(camera.x,temp.x);
                temp.x=0.01*(my.x-camera.x);
                temp.y=0.01*(my.y-camera.y);
                temp.z=0.01*(my.z-camera.z);

                move_view camera,nullvector,temp; //old syntax

		wait(1);
	}
	//only visible on right side during hell part
	hellborder_ent.visible=0;
}

//fade over to hell scene
function fade_in_hell()
{
	//fade out heaven part view, pro version only
        heavencam.transparent=1;
        camera.visible=1; //make hell view visible behind heaven view
        camera.fog=0;
	//now we fade out heaven view
        //hell part slowly gets visible
        while(heavencam.alpha>0)
        {
                wait 1;
                heavencam.alpha-=time+time;
                if (heavencam.alpha<=50)
                {
                        camera.fog+=time+time; //slowly add red hell fog
                        fog_color=1;
                        heavencam.fog=0;
                }
                else
                {
                        heavencam.fog-=time+time;
                }

        }
        camera.fog=50;
        heavencam.alpha=0;
        heavencam.transparent=0;
        heavencam.visible=0;
        scene=2; //fading done, change scene indicator variable
}

//applied to smoke sprites in hell part
action set_sprite
{
	my.flare=1;
	my.ambient=100;
	my.scale_x=3;
	my.scale_y=3;
	temp=random(56);
	my.frame=temp;
	while (scenefade<2) {wait 1;}
	while (scene<=2)
        {
		my.frame+=time*0.8;
		if (my.frame>MY.SKILL1-1)
		{
			//last frame reached
			my.invisible=1;
			my.frame=0;
			waitt (32);
			//start again after a small pause
			my.invisible=0;
		}
		wait (1);
	}
	my.invisible=1;
	ent_purge(me);
}

//animate lava terrain
action set_lava
{
	my.tex_scale=1.5;
	my.transparent=0;
	my.scale_z=5;
	my.ambient=0;
	my.albedo=0;
	my.SKILL40=my.z;
	while (scene<=2)
	{
		my.z=my.skill40+10*cos(helltimer*3);
		my.frame+=time/2;
		if(my.frame>=36)
		{
        		my.frame-=36;
			//loop
		}

		wait (1);
	}
}

action deform_me
{
	//adjust tex_scale of terrain
	my.tex_scale=1.5;
}

//initalize heaven part
action set_heaven
{
        while (scenefade!=1) {wait 1;}
        heaventimer=0; //reset timer
        create_flowers(); //randomly place flower models
        fade_in_heaven(); //start fading
        move_layers(); //init cloud layers
        heaven_cam(); //camera movement
        waitt (96);
        scroll_text(); //start scrolling text on bottom and top
}

function fade_in_heaven()
{
        heavencam.alpha=0;
        heavencam.transparent=1;
        heavencam.visible=1;
        heavencam.fog=0;
        while(heavencam.alpha<100)
        {
                wait 1;
                heavencam.alpha+=time+time;
                intro_ent.alpha-=time;
                if (heavencam.alpha<=50)
                {
                        camera.fog-=time+time;
                }
                else
                {
                        fog_color=2;
                        heavencam.fog+=time+time;
                        camera.fog=0;
                }
        }
        heavencam.fog=50;
        heavencam.alpha=100;
        heavencam.transparent=0;
        camera.visible=0;
        scene=1; //set scene indicator variable
}

var camera_dist;
function heaven_cam()
{
        while (scene<=1)
        {
	        camera_dist=400+250*sin(heaventimer*5);
	        heavencam.roll=15*cos(heaventimer*6);

	        heavencam.pan+=3*time*(0.2+abs(sin(heaventimer)));
	        heavencam.tilt=-15-5*sin(heaventimer*2);
                temp.x=my.x-camera_dist*cos(heavencam.pan)*cos(heavencam.tilt)-heavencam.x;
                temp.y=my.y-camera_dist*sin(heavencam.pan)*cos(heavencam.tilt)-heavencam.y;
                temp.z=my.z-camera_dist*sin(heavencam.tilt)-heavencam.z+70;
                move_view heavencam,nullskill,temp; //old style
                wait (1);
        }
}


function scroll_text()
{
        heavenmsg1_ent.visible=1;
        heavenmsg2_ent.visible=1;
        heavenmsg1_ent.forcey=-6;
        heavenmsg2_ent.forcey=6;

        while(scene<=1)
        {
		//!!!DO NOT USE CODE BELOW!!!
                //it does not work very well
                //use direct position modification instead
                //e.g.: my.y+=25*time;
                wait (1);
                speed.x=0;
                speed.y=0;
                speed.z=0;
		//again code is taken from template movement
                temp = min(time*0.55,1);
                heavenmsg1_ent.speedY += (time * heavenmsg1_ent.forceY) - (temp * heavenmsg1_ent.speedY);
                speed.y=heavenmsg1_ent.speedy*time;
                move heavenmsg1_ent,nullvector,speed;
                heavenmsg2_ent.speedY += (time * heavenmsg2_ent.forceY) - (temp * heavenmsg2_ent.speedY);
                speed.y=heavenmsg2_ent.speedY*time;
                move heavenmsg2_ent,nullvector,speed;

		//reached outside of screen - now set new position
                if (heavenmsg1_ent.y>340)
                {
                        heavenmsg1_ent.speedY=0;
                        heavenmsg2_ent.speedY=0;
                        heavenmsg1_ent.y=340;
                        heavenmsg1_ent.z=-70;
                        heavenmsg1_ent.forceY*=-1;
                        heavenmsg1_ent.scale_x*=-1;
                        heavenmsg1_ent.scale_y*=-1;
                        heavenmsg2_ent.y=-340;
                        heavenmsg2_ent.z=70;
                        heavenmsg2_ent.forceY*=-1;
                        heavenmsg2_ent.scale_x*=-1;
                        heavenmsg2_ent.scale_y*=-1;
                        waitt (96);
                }
                if (heavenmsg1_ent.y<-340)
                {
                        heavenmsg1_ent.speedY=0;
                        heavenmsg2_ent.speedY=0;
                        heavenmsg2_ent.y=340;
                        heavenmsg2_ent.z=-70;
                        heavenmsg2_ent.forceY*=-1;
                        heavenmsg2_ent.scale_x*=-1;
                        heavenmsg2_ent.scale_y*=-1;
                        heavenmsg1_ent.y=-340;
                        heavenmsg1_ent.z=70;
                        heavenmsg1_ent.forceY*=-1;
                        heavenmsg1_ent.scale_x*=-1;
                        heavenmsg1_ent.scale_y*=-1;
                        waitt (64);
                }
        }
        heavenmsg1_ent.visible=0;
        heavenmsg2_ent.visible=0;
        ent_purge (heavenmsg1_ent);
        ent_purge (heavenmsg2_ent);

}

function move_layers()
{
        heaven_ent.visible=1;
        heaven2_ent.visible=1;
        heaven_ent.alpha=0;
        heaven2_ent.alpha=0;
        while(heaven_ent.alpha<20)
        {
                heaven_ent.alpha+=time;
                heaven2_ent.alpha+=time;
                wait (1);
        }
	//move panels as long as fading to hell part
        //has NOT started
        while (scenefade<2)
        {
                heaven_ent.y=300*sin(heaventimer);
                heaven2_ent.y=300*cos(heaventimer*1.5);
                heaven_ent.alpha=20+5*sin(heaventimer*4);
                heaven2_ent.alpha=30+5*cos(heaventimer*6);
                wait (1);
        }
	//fading in hell part has started, now fade out clouds
        while (heaven_ent.alpha>0 || heaven2_ent.alpha>0)
        {
                wait (1);
                heaven_ent.alpha-=time;
                heaven_ent.alpha=max(0,heaven_ent.alpha);
                heaven2_ent.alpha-=time;
                heaven2_ent.alpha=max(0,heaven_ent.alpha);
        }
	//done, remove panels
        heaven_ent.visible=0;
        heaven2_ent.visible=0;
        ent_purge (heaven_ent);
        ent_purge (heaven2_ent);

}

var flowercount=0;
function create_flowers
{
// The version The Conflict was released with
// did not allow while without wait
// the code was changed to use goto
// this is not needed anymore
// NEVER use goto

        while (flowercount<50)
        {
//                loop:
                temp.x=2600+(random(1600)-800);
                temp.y=-130+(random(1600)-800);
                if (!(temp.y <170 && temp.y>-430 && temp.x <2900 && temp.x>2300))
                {

                        temp.z=0;

                        create <flower01.mdl>,temp,place_flower; // old style
                        flowercount+=1;
                }
//                if (flowercount<50) {goto loop;}
        }
}

function place_flower()
{
	//place to floor and choose random angle
        //why place flowers randomly?
        //simple answer - less work ;-)
        sonar me, 500;
        my.z-=result;
        my.pan=random(360);
}


var turb_speed=0.3;	//default animation speed of turbulent
			//surfaces is wayyy to fast

//particles for heaven part
function move_waterpart()
{
	//decrease z speed, until it is negative
        //-> particles are falling down again
        my.vel_z-=0.1*time;
}

bmap blue_particle_map <part_blu.pcx>;
function Xparticle_event() {
	my.red=62;
        my.green=80;
        my.blue=180;
        my.bmap=blue_particle_map;
        my.size=2;
	//random speed
        my.vel_Z=3.5+random(1.5);
        my.vel_X=-1+random(2);
        my.vel_Y=-1+random(2);
        my.move=on;
        my.beam=on; //pro version only
        my.flare=on;
        my.alpha=45;
        my.lifespan=60;
        my.function=move_waterpart;
}

// attached to water entity
action set_water
{
        my.transparent=1;
        my.alpha=95;
        my.ambient=100;
        while (scene<=1&& scenefade<=1)
        {
                temp=15;//*time;
                vec_set(my_pos,my.x);
                my_pos.z+=30;
                effect(xparticle_event,temp,my_pos,nullvector);
                waitt (5);
        }
}

//"snowflakes" showing up in intro and extro
bmap white_particle_map, <part_whi.pcx>;
function effect_snow()
{
        my.x += random(220) - 110;
        my.y += random(1400) - 700;
        my.vel_z=8+random(4);
        my.alpha = 20 + random(10);
        my.red=255;
        my.green=255;
        my.blue=255;
        my.bmap=white_particle_map;
        my.size=2;
        my.flare = on;
        my.bright = on;
        my.beam = on;
        my.move = on;
        my.function = null;
}

//different direction for extro
//just copied function from above
//dirty and quick solution :-)
function effect_snow2()
{
        my.x += random(220) - 110;
        my.y += random(1400) - 700;
        my.vel_z=-8-random(4);
        my.alpha = 20 + random(10);
        my.red=255;
        my.green=255;
        my.blue=255;
        my.bmap=white_particle_map;
        my.size=2;
        my.flare = on;
        my.bright = on;
        my.beam = on;
        my.move = on;
        my.function = null;
}

//streak particles for intro
function effect_intro()
{
        my_pos.x = random(2) - 1;
        my_pos.y = random(2) - 1;
        my_pos.z = random(2) - 1;
        vec_normalize(my_pos.x,random(150));
        vec_add(my.vel_x,my_pos.x);
        my.alpha = 25 + random(25);
        my.red=255;
        my.green=255;
        my.blue=255;
        my.size=2;
        my.flare = on;
        my.bright = on;
        my.streak=on;
        my.function = part_alphafade;
}

var campos[3];
var particlepos[3];
action set_intro_coords
{
        my.invisible=1;
        my.passable=1;
        vec_set (campos,my.x);
        vec_set (camera.x,my.x);
        vec_set(particlepos.x,my.x);
        particlepos.z-=800;
        while(clock<10) {wait 1;}
	//create particles
        //problems with time correction
        while(scene==0)
        {
                temp=10;//*time;
                vec_scale(normal,10);
                effect(effect_intro,temp,particlepos,nullvector);
                temp=6;//*time;
                effect(effect_snow,temp,particlepos,nullvector);
                waitt (3);
        }
	//let routine sleep until extro starts
        //again dirty and quick solution
        while (scene!=4) {wait 1;}
        particlepos.z+=800;
        while (scene==4)
        {
                particlepos.z-=800;
                temp=10;//*time;
                vec_scale(normal,10);
                effect(effect_intro,temp,particlepos,nullvector);
                particlepos.z+=800;
                temp=6;//*time;
                effect(effect_snow2,temp,particlepos,nullvector);
                waitt (3);
        }
}

action set_intro
{
        wait (1);
        fog_color=1;
        intro_ent.visible=1;
        timer=0; //reset timer
        my.ambient=0;
        camera.z=campos.z;
        show_msg(); //show text messages
        while(scene==0)
        {
                my.v+=18*time;
                camera.x=campos.x+70*sin(3*timer);
                camera.y=campos.y+70*cos(3*timer);
                camera.pan=50*(sin(2*timer));
                camera.tilt=-90+15*cos(3*timer);
                wait 1;
        }
        intro_ent.visible=0;
        set_extro();
        //everything done here, start extro init
}


//create filename and load pcx file
var msgcount=0;
var msgbase=0;
var msgtotal=0;
string msgfile_str,"123456789012";
string msg_str,"msg";
string msgnumber_str,"  ";

function show_message(msgcount)
{
        while(msgtotal<msgbase+msgcount)
        {
                msgtotal+=1;

                str_for_num(msgnumber_str,msgtotal);
                str_cpy(msgfile_str,msg_str);
                str_cat(msgfile_str,msgnumber_str);
                str_cat(msgfile_str,pcx_str);
                wait (1);
                ent_morph(msg_ent,msgfile_str);
                msg_ent.alpha=0;
		//remember that I defined positions
                //and effect type in an array at the beginning?
                msg_ent.y=msgposx[msgtotal];
                msg_ent.z=msgposy[msgtotal];
                msg_ent.x=533;
                msg_ent.scale_x=1;
                msg_ent.scale_y=1;
                msg_ent.visible=1;
                while(msg_ent.alpha<35)
                {
                        wait (1);
                        msg_ent.alpha+=time+time;
                }
                msg_ent.alpha=35;
                while(msg_ent.alpha>0)
                {
                        wait (1);
                        msg_ent.alpha-=time;
			//some simple effect types for fading out text
                        if (msgfx[msgtotal]==4)
                        {
                                msg_ent.scale_x+=0.2*time;
                                msg_ent.x+=15*time;
                        }
                        if (msgfx[msgtotal]==1)
                        {
                                msg_ent.x-=10*time;
                        }
                        if (msgfx[msgtotal]==2)
                        {
                                msg_ent.x+=10*time;
                        }
                        if (msgfx[msgtotal]==3)
                        {
                                msg_ent.scale_x-=0.02*time;
                        }
                }
                msg_ent.visible=0;
                ent_purge(msg_ent);
                waitt (16);
        }
        msg_ent.visible=0;
        ent_purge(msg_ent);
        msgbase=msgtotal;
}

function show_msg()
{
        acknex_ent.visible=1;
        waitt (32);
        play_sound  (bg_music,80);
        sndhandle=result;
        clock_control();
        while (acknex_ent.alpha>0)
        {
                wait (1);
                acknex_ent.alpha-=time+time+time;
                acknex_ent.scale_x+=time*0.05;
                acknex_ent.scale_y-=time*0.02;
        }
        acknex_ent.alpha=0;
        acknex_ent.visible=0;
        ent_purge (acknex_ent);
        waitt (32);

        conflict_ent.visible=1;
        while (conflict_ent.skill12<16)
        {
		//this is not time corrected properly!!
                waitt (2);
                conflict_ent.skill12+=0.5;//time;
                conflict_ent.scale_x=1+random(1)-0.5;
                conflict_ent.scale_y=1+random(1)-0.5;
        }
        conflict_ent.scale_x=1;
        conflict_ent.scale_y=1;
        waitt (8);
        while (conflict_ent.alpha>0)
        {
                wait (1);
                conflict_ent.alpha-=time+time;
        }
        conflict_ent.alpha=0;
        conflict_ent.visible=0;
        ent_purge (conflict_ent);
        waitt (32);
        show_message(8); //start to show next 8 messages
	//synched with bgm
        while (clock<47)
        {
                wait 1;
        }
        scenefade=1;
        while (clock<85)
        {
                wait 1;
        }
        scenefade=2;
        while (clock<122)
        {
                wait 1;
        }

        scenefade= 3;
        while (clock<197)
        {
                wait 1;
        }

       scenefade=4;
}

function set_extro()
{
	//don't start before extro is fading in
        //yesyes... quick and dirty...
        while (scenefade<4) {wait 1;}
        fade_in_extro(); //get the thing running
        helltimer=0; //reset timer, we can re-use hell timer
        my.ambient=0;
        camera.z=campos.z;
        show_credits(); //who did this stuff?
        while(scene<=4)
        {
                my.v-=18*time;
                camera.x=campos.x+70*sin(3*helltimer);
                camera.y=campos.y+160*cos(3*helltimer);
                camera.pan+=3*time;
                camera.tilt=-90+15*cos(3*helltimer);
                wait (1);
        }
        intro_ent.visible=0;
}

//same filename creation method from above
//it allows showing different bitmaps
//in a while loop without having
//a lot of script
string crdfile_str,"123456789012";
string crd_str,"credits";
string crdnumber_str,"  ";
var credits=0;
function show_credits()
{
        waitt (96);
        while(credits<6)
        {
                credits+=1;

                str_for_num(crdnumber_str,credits);
                str_cpy(crdfile_str,crd_str);
                str_cat(crdfile_str,crdnumber_str);
                str_cat(crdfile_str,pcx_str);
                wait (1);
                ent_morph(msg_ent,crdfile_str);
                msg_ent.alpha=0;
                msg_ent.y=0;
                msg_ent.z=0;
                msg_ent.x=533;
                msg_ent.scale_x=1;
                msg_ent.scale_y=1;
                msg_ent.visible=1;
                while(msg_ent.alpha<35)
                {
                        wait (1);
                        msg_ent.alpha+=time+time;
                }
                msg_ent.alpha=35;
                waitt 96;
                while(msg_ent.alpha>0)
                {
                        wait 1;
                        msg_ent.alpha-=time;
                }
                msg_ent.visible=0;
                ent_purge(msg_ent);
                waitt (16);
        }
        msg_ent.visible=0;
        ent_purge(msg_ent);
        fadecam.alpha=0;
        fadecam.transparent=1;
        fadecam.visible=1;
        while (fadecam.alpha<100)
        {
                wait (1);
                fadecam.alpha+=time+time;
        }
        fadecam.transparent=0;
        waitt (8);
	//we did it, return to Windows
        exit;
}

//confrontation part, view init
action set_fadecam
{
        my.invisible=1;
        my.passable=1;
        vec_set (fadecam.x, my.x);
        vec_set (fadecam.pan, nullvector);
}

var pipe_dist[2]=150,100;
var pipecenter[3];
entity* innerpipe;

action rot_plate
{
	wait (3);
        while (scene<=3)
        {
                my.pan-=10*time;
                wait (1);
        }
}

//assigned to inner pipe
action rot_innerpipe
{
        while (scenefade<3) {wait (1);}
        fade_in_scene3(); //scene3 is starting now
        innerpipe=me; //entity pointer ened for positioning outer pipe
        my.passable=1;
        vec_set (camera.x,my.x);
        vec_set (camera.x,nullvector);
        vec_set (pipecenter.x,my.x);
        while (scene<=3)
        {
                my.pan+=5*time;
                my.skill10+=5*time;
                my.ambient=70*abs(sin(timer*30));
                scene3_ent.alpha=50*abs(sin(timer*30));
                wait (1);
        }
}

//assigned to outer pipe
action rot_outerpipe
{
        while (scenefade<3) {wait (1);}
        my.passable=1;
        show_images(); //start fading in images
        vec_set (my.x,pipecenter);
        camera.z=pipecenter.z;
        while(scene<=3)
        {
	        fog_color=0;
                pipe_dist=100+abs(100*cos(timer*2));
                pipe_dist.y=pipe_dist/2;
                temp.x=pipecenter.x+pipe_dist*cos(innerpipe.pan)-my.x;
                temp.y=pipecenter.y+pipe_dist*sin(innerpipe.pan)-my.y;
                temp.z=0;
                move me,nullvector,temp; //old style
                pipe_dist=150+abs(150*cos(timer*2));
                temp.x=pipecenter.x+pipe_dist.y*cos(innerpipe.skill10)-heavencam.x;
                temp.y=pipecenter.y+pipe_dist.y*sin(innerpipe.skill10)-heavencam.y;
                temp.z=0;
                move_view heavencam,nullvector,temp; // old style
                my.pan+=9*time;
                my.ambient=70*abs(cos(timer*30));
                heavencam.pan-=7*time;
                heavencam.tilt=-90+35*sin(timer*5);
                heavencam.z=pipecenter.z-abs(450*cos(timer*6));
                wait (1);

        }
}

//show entities at predefined positions
//again, the filename is constructed
var imagenr;
var pos1[3]=533, 120, -70;
var pos2[3]=533, 120, 70;
var pos3[3]=533, -120, -70;
var pos4[3]=533, -120, 70;

string goodfile1_str,"123456789012";
string goodfile2_str,"123456789012";
string evilfile1_str,"123456789012";
string evilfile2_str,"123456789012";
string good2_str,"good";
string good1_str,"gchar";
string evil2_str,"evil";
string evil1_str,"echar";
string imgnumber_str,"  ";


function show_images()
{
        while (clock<125) {wait (1);}
        show_message(6); //show next 6 messages
        while (clock<153) {wait (1);}
                        vec_set (evil1_ent.x,pos4.x);
                        vec_set (evil2_ent.x,pos3.x);
                        vec_set (good1_ent.x,pos1.x);
                        vec_set (good2_ent.x,pos2.x);
        while(imagenr<6)
        {
                imagenr+=1;

		//create filenames
                str_for_num(imgnumber_str,imagenr);
                str_cpy(goodfile1_str,good1_str);
                str_cpy(goodfile2_str,good2_str);
                str_cpy(evilfile1_str,evil1_str);
                str_cpy(evilfile2_str,evil2_str);
                str_cat(goodfile1_str,imgnumber_str);
                str_cat(goodfile2_str,imgnumber_str);
                str_cat(evilfile1_str,imgnumber_str);
                str_cat(evilfile2_str,imgnumber_str);
                str_cat(goodfile1_str,pcx_str);
                str_cat(goodfile2_str,pcx_str);
                str_cat(evilfile1_str,pcx_str);
                str_cat(evilfile2_str,pcx_str);
                good1_ent.x=533;
                evil1_ent.x=533;
                good2_ent.scale_x=1;
                evil2_ent.scale_x=1;

                if (evil1_ent.y==pos3.y && evil1_ent.z==pos3.z)
                {
                        vec_set (evil1_ent.x,pos4.x);
                        vec_set (evil2_ent.x,pos3.x);
                        vec_set (good1_ent.x,pos1.x);
                        vec_set (good2_ent.x,pos2.x);

                }
                else
                {
                        vec_set (evil1_ent.x,pos3.x);
                        vec_set (evil2_ent.x,pos4.x);
                        vec_set (good1_ent.x,pos2.x);
                        vec_set (good2_ent.x,pos1.x);
                }
		// wait was added to reduce "hanging" while
                // entites are loaded into memory
                wait (2);
                ent_morph (evil1_ent,evilfile1_str);
                wait (2);
                ent_morph (evil2_ent,evilfile2_str);
                wait (2);
                ent_morph (good1_ent,goodfile1_str);
                wait (2);
                ent_morph (good2_ent,goodfile2_str);
                evil1_ent.visible=1;
                evil1_ent.alpha=100;
                evil2_ent.visible=1;
                evil2_ent.alpha=50;
                good1_ent.visible=1;
                good1_ent.alpha=100;
                good2_ent.visible=1;
                good2_ent.alpha=50;
                while (evil1_ent.alpha>0)
                {
                        wait (1);
                        evil1_ent.alpha-=time+time;
                        evil2_ent.alpha-=time;
                        good1_ent.alpha-=time+time;
                        good2_ent.alpha-=time;
                        good1_ent.x+=10*time;
                        evil1_ent.x+=10*time;
                        good2_ent.scale_x+=0.05*time;
                        evil2_ent.scale_x+=0.05*time;

                }
                evil1_ent.visible=0;
                evil2_ent.visible=0;
                good1_ent.visible=0;
                good2_ent.visible=0;
                ent_purge(evil1_ent);
                wait (1);
                ent_purge(evil2_ent);
                wait (1);
                ent_purge(good1_ent);
                wait (1);
                ent_purge(good2_ent);
                wait (1);
        }
	//last picture is done seperately
        chao_ent.visible=(1);
        while (chao_ent.alpha>0)
        {
                wait (1);
                chao_ent.alpha-=time+time;
                chao_ent.x+=25*time;
        }
        chao_ent.visible=0;
        ent_purge (chao_ent);
        wait (1);
        show_message(4); //next 4 text messages
}

function fade_in_scene3()
{
        heavencam.alpha=0;
        heavencam.transparent=1;
        heavencam.visible=1;
        heavencam.fog=0;
        hellborder_ent.alpha=100;
        hellborder_ent.transparent=1;
        hell_ent.visible=0;
        hell2_ent.visible=0;
        hell3_ent.visible=0;
        hell4_ent.visible=0;
        while(heavencam.alpha<100)
        {
                wait (1);
                heavencam.alpha+=time+time;
                hellborder_ent.alpha-=4*time;
                hellborder_ent.alpha=max(0,hellborder_ent.alpha);
                if (heavencam.alpha<=50)
                {
                        camera.fog-=time+time;
                }
                else
                {
                        scene3_ent.visible=1;
                        camera.fog=0;
                }
        }
        heavencam.alpha=100;
        heavencam.transparent=0;
        camera.visible=0;
        scene=3; //set scene indicator variable
}

//extro fading function
function fade_in_extro()
{
        heavencam.transparent=1;
        heavencam.alpha=100;
        intro_ent.alpha=0;
        intro_ent.visible=1;
        camera.visible=1;
        camera.fog=0;
        camera.alpha=0;
        while(heavencam.alpha>0)
        {
                wait (1);
                heavencam.alpha-=time+time;
                camera.alpha+=time+time;
                if (heavencam.alpha<=50)
                {
                        scene3_ent.visible=0;
                        camera.fog+=time+time;
                        fog_color=1;
                        intro_ent.alpha+=time;
                        intro_ent.alpha=min(50,intro_ent.alpha);

                }

        }
        camera.transparent=0;
        camera.fog=50;
        heavencam.alpha=0;
        heavencam.transparent=0;
        heavencam.visible=0;
        scene=4; // set scene indicator variable
}


// block default keys

function dummy() {return;}

on_f5 dummy;
on_f10 dummy;
on_tab dummy;
on_0 dummy;
on_f12 dummy;