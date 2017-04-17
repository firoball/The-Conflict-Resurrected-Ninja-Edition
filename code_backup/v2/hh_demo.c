#define PRAGMA_PATH "bmaps"
#define PRAGMA_PATH "d:\\acknex8\code\\"

#include <acknex.h>
#include <mtlfx.c>
#include <default.c>
function fade_in_hell();
function create_flowers();
function fade_in_heaven();
function move_layers();
function heaven_cam();
function scroll_text();
function place_flower();
function show_msg();
function set_extro();
function fade_in_extro();
function show_credits();
function fade_in_scene3();
function show_images();

#define set2(obj,flag) obj->flags2 |= (flag)
#define reset2(obj,flag) obj->flags2 &= ~(flag)
#define is2(obj,flag) (obj->flags2 & (flag))


//entity panel definitions
ENTITY* intro_ent =
{
        type="intro.tga";
        x=533;
        y=0;
        z=0;
        scale_y=1.2;
        scale_x=5;
        alpha=50;
        layer=9;
//        flags flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* message_ent=
{
        type="msg1.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1;
        scale_x=1;
        alpha=35;
        layer=10;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* acknex_ent=
{
        type="acknex.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1.2;
        scale_x=1.3;
        alpha=100;
        layer=10;
//        flags transparent, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* conflict_ent=
{
        type="conflict.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1.1;
        scale_x=1.1;
        alpha=35;
        layer=10;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* msg_ent=
{
        type="msg1.pcx";
        x=450;
        y=0;
        z=0;
        scale_y=1;
        scale_x=1;
        alpha=35;
        layer=10;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* hell_ent=
{
        type="layer.pcx";
        x=533;
        y=250;
        scale_y=1.2;
        scale_x=0.7;
        z=0;
        alpha=40;
//        flags transparent, flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* hell2_ent=
{
        type="layer.pcx";
        x=533;
        y=450;
        z=0;
        scale_y=-1.2;
        scale_x=0.7;
        alpha=40;
//        flags transparent, flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* hell3_ent=
{
        type="layer.pcx";
        x=533;
        y=350;
        z=0;
        scale_y=1.2;
        scale_x=-0.7;
        alpha=40;
//        flags transparent, flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* hell4_ent=
{
        type="layer.pcx";
        x=533;
        y=350;
        z=0;
        scale_y=-1.2;
        scale_x=-0.7;
        alpha=40;
//        flags transparent, flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* hellborder_ent=
{
        type="hellbrd.pcx";
        layer=9;
        x=533;
        y=-270;
        z=0;
        scale_y=1.2;
//        flags=oriented;
//flags = TRANSLUCENT;
}

ENTITY* hellmsg_ent=
{
        type="hell1.pcx";
        layer=8;
        x=300;
        y=0;
        z=0;
//        flags=oriented,flare,transparent;
//flags = TRANSLUCENT;
}

ENTITY* heaven_ent=
{
        type="clouds.tga";
        x=533;
        y=0;
        scale_y=1.2;
        scale_x=7;
        z=0;
        alpha=25;
        layer=8;
//        flags flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* heaven2_ent=
{
        type="clouds.tga";
        x=533;
        y=450;
        z=0;
        scale_y=-1.2;
        scale_x=-7;
        alpha=25;
        layer=10;
//        flags flare, oriented;
//flags = TRANSLUCENT;
}

ENTITY* heavenmsg1_ent=
{
        type="heaven1.pcx";
        x=300;
        y=340;
        z=-70;
        scale_y=1.3;
        scale_x=1.3;
        layer=19;
        alpha=30;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* heavenmsg2_ent=
{
        type="heaven2.pcx";
        x=300;
        y=-340;
        z=70;
        scale_y=-1.3;
        scale_x=-1.3;
        layer=19;
        alpha=30;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* chao_ent=
{
        type="chao.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1;
        scale_x=1;
        layer=9;
        alpha=100;
//        flags transparent, oriented, bright;
//flags = TRANSLUCENT;
}


ENTITY* evil1_ent=
{
        type="gchar1.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=0.6;
        scale_x=0.6;
        layer=9;
        alpha=70;
//        flags transparent, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* evil2_ent=
{
        type="gchar1.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1;
        scale_x=1;
        layer=9;
        alpha=50;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}
ENTITY* good1_ent=
{
        type="gchar1.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=0.6;
        scale_x=0.6;
        layer=9;
        alpha=50;
//        flags transparent, oriented, bright;
//flags = TRANSLUCENT;
}
ENTITY* good2_ent=
{
        type="gchar1.pcx";
        x=533;
        y=0;
        z=0;
        scale_y=1;
        scale_x=1;
        layer=9;
        alpha=50;
//        flags flare, oriented, bright;
//flags = TRANSLUCENT;
}

ENTITY* scene3_ent=
{
        type="scene3.tga";
        x=533;
        y=0;
        scale_y=1.2;
        scale_x=6;
        z=0;
        alpha=0;
        layer=7;
//        flags flare, oriented;
//flags = TRANSLUCENT;
}

var xtimer=0;
var helltimer=0;
var heaventimer=0;
//var fps_max=30; //fps were limited because of possible bad scripting
var scene=0;
var scenefade=0;
var sndhandle;
var clock_abs;
var clock;
//var clock_setoff;
var msgposx[20];
var msgposy[20];
var msgfx[20];
SOUND* bg_music = "nb_clysm.wav";

//additional views

VIEW* heavencam =
{
        arc=60;
        layer=8;
        fog=50;
}

VIEW* fadecam =
{
        arc=60;
        layer=8;
        fog=50;
}

///////////////////

function main()
{
fps_max=100;
warn_level=2;
video_set(1024,768,32,0);

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
        //camera.aspect=0.67;
        heavencam.pos_x=0;
        heavencam.pos_y=screen_size.y/6;
        heavencam.size_x=screen_size.x;
        heavencam.size_y=screen_size.y/3*2;
        //heavencam.aspect=0.67;
        tex_share = 1;

        wait(3);

        sndhandle=snd_play(bg_music,10,0);
        wait (1);
        snd_stop(sndhandle);
	//dummy sfx playback to load sound into memory at startup
        level_load("hh_demo.wmb");
	while(1)
	{
		xtimer+=time_step;
		helltimer+=time_step;
		heaventimer+=time_step;
		wait (1);
		//timers used to start certain effects time_step corrected
                //required to stay in touch with bgm
	}
}

function clock_control() {

	clock_abs=xtimer;
//        clock_abs=sys_hours*3600+sys_minutes*60+sys_seconds;
//        clock_setoff=clock_abs; //hack
        while(1)
        {
	clock=(xtimer-clock_abs)/16;
//                clock_abs=sys_hours*3600+sys_minutes*60+sys_seconds;
//                clock=clock_abs-clock_setoff;
                wait (1);
//DEBUG_VAR(integer(clock),123);
//DEBUG_VAR(sys_seconds,143);
        }
	//calculate demo running time_step in seconds
}




var speed[3];

//defines for moving entities
#define speedX skill33
#define speedY skill34
#define speedZ skill35
#define targetX skill43
#define targetY skill44
#define targetZ skill45
#define forceX skill30
#define forceY skill31
#define forceZ skill32


//animate layers on left side in hell part
//Hell scene - left side layers
function swap_layers()
{
        while (scene<=2)
        {
                hell_ent.scale_y*=-1;
                hell2_ent.scale_y*=-1;
                hell3_ent.scale_y*=-1;
                hell4_ent.scale_y*=-1;
                wait (-0.25);
        }
}

//Hell scene - left side layers
function anim_layer()
{
        while (scene<2) {wait (1);}
        set2(hell_ent,SHOW);
        set2(hell2_ent,SHOW);
        hell_ent.alpha=40;
        hell2_ent.alpha=20;
        hell3_ent.alpha=0;
        hell4_ent.alpha=0;
        swap_layers();
        while (scene==2)
        {
		//fade out layers on left side of hell part
                //when switching to next scene
                hell_ent.alpha-=time_step+time_step+time_step;
                hell2_ent.alpha-=time_step+time_step+time_step;
                hell3_ent.alpha-=time_step+time_step+time_step;
                hell4_ent.alpha-=time_step+time_step+time_step;
                hell_ent.y=250+20*sinv(xtimer*14+30);
                hell2_ent.y=250+20*cosv(xtimer*14+60);
                hell3_ent.y=250+20*sinv(xtimer*14+90);
                hell4_ent.y=250+20*cosv(xtimer*14+120);
                if (hell_ent.alpha<=25 && !is2(hell2_ent, SHOW))
                {
                        hell2_ent.alpha=40;
                        set2(hell2_ent,SHOW);
                }
                if (hell2_ent.alpha<=25 && !is2(hell3_ent, SHOW))
                {
                        hell3_ent.alpha=40;
                        set2(hell3_ent,SHOW);
                }
                if (hell3_ent.alpha<=25 && !is2(hell4_ent, SHOW))
                {
                        hell4_ent.alpha=40;
                        set2(hell4_ent,SHOW);
                }
                if (hell4_ent.alpha<=25 && !is2(hell_ent, SHOW))
                {
                        hell_ent.alpha=40;
                        set2(hell_ent,SHOW);
                }

                if (hell_ent.alpha<=0) {reset2(hell_ent,SHOW);}
                if (hell2_ent.alpha<=0) {reset2(hell2_ent,SHOW);}
                if (hell3_ent.alpha<=0) {reset2(hell3_ent,SHOW);}
                if (hell4_ent.alpha<=0) {reset2(hell3_ent,SHOW);}
                wait (1);
        }
        reset2(hell_ent,SHOW);
        reset2(hell2_ent,SHOW);
        reset2(hell3_ent,SHOW);
        reset2(hell4_ent,SHOW);
}

//hell part particle fountain
function vec_randomize(var* vec, var range)
{
	vec[0] = random(2) - 1;
	vec[1] = random(2) - 1;
	vec[2] = random(20);
	vec_normalize(vec,random(range));
}

function part_alphafade(PARTICLE* p)
{
	p.alpha -= time_step+time_step;
	if (p.alpha <= 0) { p.lifespan = 0; }
}

function effect_explo(PARTICLE* p)
{
	VECTOR temp;
	vec_randomize(temp,50);
	vec_add(p.vel_x,temp);
	p.alpha = 25 + random(25);
	p.red=150;
	p.green=110;
	p.blue=20;
	set(p, TRANSLUCENT|BRIGHT|STREAK|MOVE);
	p.event = part_alphafade;
}


function particle_emitter()
{
	set(my,INVISIBLE,PASSABLE);
	my.z=-200;
	wait (1);
	while(scene<=2)
	{
		vec_scale(normal,10); //check how to replace
		effect(effect_explo,300,my.x,normal);
		wait (-3); //not very accurate, bad style
	}
}

var count=0;

//Hell Scene - keywords
function hell_msg()
{
STRING* file_str=str_create("123456789012");
STRING* hell_str=str_create("hell");
STRING* pcx_str=str_create(".pcx");
STRING* number_str=str_create(" ");
        while (scene<2) {wait (1);}
        wait (-3);
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
                set2(hellmsg_ent,SHOW);
                while (hellmsg_ent.alpha>0)
                {
                        wait (1);
                        hellmsg_ent.alpha-=time_step*7;
                }
                reset2(hellmsg_ent,SHOW);
                ent_purge(hellmsg_ent);
        }
        reset2(hellmsg_ent,SHOW);
        ent_purge(hellmsg_ent);

}

//applied to terrain for hell part
action terrain_center()
{
	VECTOR temp;
	ANGLE my_angle;
	while (scenefade!=2) {wait (1);}
	set(my, INVISIBLE|PASSABLE);
	ent_create("cube.wmb",my.x,particle_emitter);
	while (scene<=2)
	{
		//make camera look to particle emitter
		my.z=200*sinv(xtimer*8);
		temp.x = my.x - camera.x;
		temp.y = my.y - camera.y;
		temp.z = my.z - camera.z;
		vec_to_angle(my_angle.pan,temp);
		camera.pan += 0.1*ang(my_angle.pan-camera.pan)*minv(1,time_step);
		camera.tilt += 0.1*ang(my_angle.tilt-camera.tilt)*minv(1,time_step);
		wait (1);
	}
}

//Hell Scene - right border
function fade_in_border()
{
        hellborder_ent.alpha=0;
        set2(hellborder_ent, SHOW);//|TRANSLUCENT);
        while(hellborder_ent.alpha<100)
        {
                wait (1);
                hellborder_ent.alpha+=time_step+time_step;
        }
        hellborder_ent.alpha=50;
//        reset2(hellborder_ent, TRANSLUCENT);
}

//attached to dummy entity which is following a path
//camera is dragged along seperately because
//otherwise movement is too limited
action walk_path()
{
	VECTOR temp;
	while (scenefade!=2) {wait (1);}
	//init basic functions (see above)
	fade_in_hell();
	hell_msg();
	anim_layer();
	fade_in_border();
	helltimer=0; //resetxtimerr
	//my.oriented=1;
	//my.invisible=1; //dummy entity only
	set(my,INVISIBLE);
	my.forceX=12;
	//scan nearest path
	temp.x = 360;//pan
	temp.y = 180;//tilt
	temp.z = 1000;
path_set(me,"path");
var dist = 0;
	while (scene<=2)
	{
		path_spline(me,camera.x,dist);
		dist += 30*time_step;
		camera.roll=40*cosv(helltimer*6);
		wait(1);
	}
	//only visible on right side during hell part
	reset2(hellborder_ent,SHOW);
}

//fade over to hell scene
function fade_in_hell()
{
	//fade out heaven part view, pro version only
        set(heavencam,TRANSLUCENT);
        set(camera,SHOW); //make hell view visible behind heaven view
        camera.fog_start=100;
	//now we fade out heaven view
        //hell part slowly gets visible
        while(heavencam.alpha>0)
        {
                wait (1);
                heavencam.alpha-=time_step+time_step;
                if (heavencam.alpha<=50)
                {
                        camera.fog_start-=time_step+time_step; //slowly add red hell fog
                        fog_color=1;
                        heavencam.fog_start=100;
                }
                else
                {
                        heavencam.fog_start-=time_step+time_step;
                }

        }
        camera.fog_start=50;
        heavencam.alpha=0;
reset(heavencam, TRANSLUCENT|SHOW);
        scene=2; //fading done, change scene indicator variable
}

//applied to smoke sprites in hell part
action set_sprite()
{
var temp;
	//my.flare=1;
	set(my, TRANSLUCENT);
	my.ambient=100;
	my.scale_x=3;
	my.scale_y=3;
	temp=random(56);
	my.frame=temp;
	while (scenefade<2) {wait (1);}
	while (scene<=2)
        {
		my.frame+=time_step*0.8;
		if (my.frame>my.skill1-1)
		{
			//last frame reached
			set(my,INVISIBLE);
			my.frame=0;
			wait (-2);
			//start again after a small pause
			reset(my,INVISIBLE);
		}
		wait (1);
	}
	set(my,INVISIBLE);
	ent_purge(me);
}

//animate lava terrain
action set_lava()
{
my.skill41=floatv(100);
my.skill42=floatv(100);
my.skill43=floatv(100);
my.material = mtl_turbulence;
//	my.tex_scale=1.5;
	set(my, TRANSLUCENT);
	my.alpha = 60;
	my.scale_z=5;
	my.ambient=0;
	my.albedo=0;
	my.skill40=my.z;
	while (scene<=2)
	{
		my.z=my.skill40+10*cosv(helltimer*3)*time_step;
ent_animate(me,"Frame",my.skill1,ANM_CYCLE);
my.skill1 = cycle(my.skill1+time_step*2,0,100);
		wait (1);
	}
}

action deform_me()
{
	//adjust tex_scale of terrain
//	my.tex_scale=1.5;
fx_terraintex();
}

//initalize heaven part
action set_heaven()
{
        while (scenefade!=1) {wait (1);}
        heaventimer=0; //resetxtimerr
        create_flowers(); //randomly place flower models
        fade_in_heaven(); //start fading
        move_layers(); //init cloud layers
        heaven_cam(); //camera movement
        wait (-6);
        scroll_text(); //start scrolling text on bottom and top
}

function fade_in_heaven()
{
        heavencam.alpha=0;
        set(heavencam, TRANSLUCENT|SHOW);
        heavencam.fog_start=100;
        while(heavencam.alpha<100)
        {
                wait (1);
                heavencam.alpha+=time_step+time_step;
                intro_ent.alpha-=time_step;
                if (heavencam.alpha<=50)
                {
                        camera.fog_start-=time_step+time_step;//inverted?
                }
                else
                {
                        fog_color=2;
                        heavencam.fog_start+=time_step+time_step;//inverted?
                        camera.fog_start=100;
                }
        }
        heavencam.fog_start=50;//fixme maybe
        heavencam.alpha=100;
        reset(heavencam,TRANSLUCENT);
        reset(camera,SHOW|TRANSLUCENT);
        scene=1; //set scene indicator variable
}

var camera_dist;
function heaven_cam()
{
VECTOR temp;
        while (scene<=1)
        {
	        camera_dist=400+250*sinv(heaventimer*5);
	        heavencam.roll=15*cosv(heaventimer*6);

	        heavencam.pan+=3*time_step*(0.2+abs(sinv(heaventimer)));
	        heavencam.tilt=-15-5*sinv(heaventimer*2);
                temp.x=my.x-camera_dist*cosv(heavencam.pan)*cosv(heavencam.tilt);//-heavencam.x;
                temp.y=my.y-camera_dist*sinv(heavencam.pan)*cosv(heavencam.tilt);//-heavencam.y;
                temp.z=my.z-camera_dist*sinv(heavencam.tilt)+70;//-heavencam.z;
			vec_set(heavencam.x,temp.x);
                //move_view heavencam,nullskill,temp; //old style
                wait (1);
        }
}


//Heaven scene - scroll text
function scroll_text()
{
        set2(heavenmsg1_ent,SHOW);
        set2(heavenmsg2_ent,SHOW);
        heavenmsg1_ent.forceY=-6;
        heavenmsg2_ent.forceY=6;

        while(scene<=1)
        {
heavenmsg1_ent.y += heavenmsg1_ent.forceY * time_step;
heavenmsg2_ent.y += heavenmsg2_ent.forceY * time_step;
		//reached outside of screen - now set new position
                if (heavenmsg1_ent.y>340)
                {
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
                        wait (-6);
                }
                if (heavenmsg1_ent.y<-340)
                {
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
                        wait (-4);
                }
                wait(1);
        }
        reset2(heavenmsg1_ent,SHOW);
        reset2(heavenmsg2_ent,SHOW);
        ent_purge (heavenmsg1_ent);
        ent_purge (heavenmsg2_ent);

}

//Heaven scene - cloud layers 
function move_layers()
{
        set2(heaven_ent,SHOW);
        set2(heaven2_ent,SHOW);
        heaven_ent.alpha=0;
        heaven2_ent.alpha=0;
        while(heaven_ent.alpha<20)
        {
                heaven_ent.alpha+=time_step;
                heaven2_ent.alpha+=time_step;
                wait (1);
        }
	//move panels as long as fading to hell part
        //has NOT started
        while (scenefade<2)
        {
                heaven_ent.y=300*sinv(heaventimer);//*time_step;
                heaven2_ent.y=300*cosv(heaventimer*1.5);//*time_step;
                heaven_ent.alpha=20+5*sinv(heaventimer*4);//*time_step;
                heaven2_ent.alpha=30+5*cosv(heaventimer*6);//*time_step;
                wait (1);
        }
	//fading in hell part has started, now fade out clouds
        while (heaven_ent.alpha>0 || heaven2_ent.alpha>0)
        {
                wait (1);
                heaven_ent.alpha-=time_step;
                heaven_ent.alpha=maxv(0,heaven_ent.alpha);
                heaven2_ent.alpha-=time_step;
                heaven2_ent.alpha=maxv(0,heaven_ent.alpha);
        }
	//done, remove panels
        reset2(heaven_ent,SHOW);
        reset2(heaven2_ent,SHOW);
        ent_purge (heaven_ent);
        ent_purge (heaven2_ent);

}

//Heaven scene - flowers
var flowercount=0;
function create_flowers()
{
VECTOR temp;
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

                        ent_create ("flower01.mdl",temp,place_flower);
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
VECTOR temp;
vec_set(temp, my.x);
temp.z-=500;
c_trace(my.x,temp,0);
//        sonar me, 500;
        my.z=hit.z-my.min_z;
        my.pan=random(360);
}


//var turb_speed=0.3;	//default animation speed of turbulent
			//surfaces is wayyy to fast

//particles for heaven part
function move_waterpart(PARTICLE* p)
{
	//decrease z speed, until it is negative
        //-> particles are falling down again
        p.vel_z-=0.1*time_step;
}

BMAP* blue_particle_map = "part_blu.pcx";
function Xparticle_event(PARTICLE* p) {
	p.red=62;
        p.green=80;
        p.blue=180;
        p.bmap=blue_particle_map;
        p.size=2;
	//random speed
        p.vel_z=3.5+random(1.5);
        p.vel_x=-1+random(2);
        p.vel_y=-1+random(2);
	set(p, MOVE|BEAM);//|TRANSLUCENT);
        p.alpha=45;
        p.lifespan=60;
        p.event=move_waterpart;
}

// attached to water entity
action set_water()
{
fx_turbulence();
var temp;
VECTOR my_pos;
my.skill41=floatv(200);
my.skill42=floatv(200);
my.skill43=floatv(200);
my.material = mtl_turbulence;
	set(my, TRANSLUCENT);
        my.alpha=50;//95;
        my.ambient=100;
        while (scene<=1&& scenefade<=1)
        {
                temp=15;//*time_step;
                vec_set(my_pos,my.x);
                my_pos.z+=30;
                effect(Xparticle_event,temp,my_pos,nullvector);
                wait (-0.3125);
        }
}

//"snowflakes" showing up in intro and extro
BMAP* white_particle_map= "part_whi.pcx";
function effect_snow(PARTICLE* p)
{
        p.x += random(220) - 110;
        p.y += random(1400) - 700;
        p.vel_z=8+random(4);
        p.alpha = 20 + random(10);
        p.red=255;
        p.green=255;
        p.blue=255;
        p.bmap=white_particle_map;
        p.size=2;
set(p,MOVE|BEAM|BRIGHT);//|TRANSLUCENT);
        p.event = NULL;
}

//different direction for extro
//just copied function from above
//dirty and quick solution :-)
function effect_snow2(PARTICLE* p)
{
        p.x += random(220) - 110;
        p.y += random(1400) - 700;
        p.vel_z=-8-random(4);
        p.alpha = 20 + random(10);
        p.red=255;
        p.green=255;
        p.blue=255;
        p.bmap=white_particle_map;
        p.size=2;
set(p,MOVE|BEAM|BRIGHT);//|TRANSLUCENT);
        p.event = NULL;
}

//streak particles for intro
function effect_intro(PARTICLE* p)
{
VECTOR my_pos;
        my_pos.x = random(2) - 1;
        my_pos.y = random(2) - 1;
        my_pos.z = random(2) - 1;
        vec_normalize(my_pos.x,random(150));
        vec_add(p.vel_x,my_pos.x);
        p.alpha = 25 + random(25);
        p.red=255;
        p.green=255;
        p.blue=255;
        p.size=2;
set(p,STREAK|BRIGHT);//|TRANSLUCENT);
        p.event = part_alphafade;
}

VECTOR campos;
VECTOR particlepos;
action set_intro_coords()
{
	var temp;
	set(my,INVISIBLE|PASSABLE);
        vec_set (campos,my.x);
        vec_set (camera.x,my.x);
        vec_set(particlepos.x,my.x);
        particlepos.z-=800;
        while(clock<10) {wait (1);}
	//create particles
        //problems with time_step correction
        while(scene==0)
        {
                temp=10;//*time_step;
                vec_scale(normal,10);
                effect(effect_intro,temp,particlepos,nullvector);
                temp=6;//*time_step;
                effect(effect_snow,temp,particlepos,nullvector);
                wait (-0.1875);
        }
	//let routine sleep until extro starts
        //again dirty and quick solution
        while (scene!=4) {wait (1);}
        particlepos.z+=800;
        while (scene==4)
        {
                particlepos.z-=800;
                temp=10;//*time_step;
                vec_scale(normal,10);
                effect(effect_intro,temp,particlepos,nullvector);
                particlepos.z+=800;
                temp=6;//*time_step;
                effect(effect_snow2,temp,particlepos,nullvector);
                wait (-0.1875);
        }
}

action set_intro()
{
        wait (1);
        fog_color=1;
        set2(intro_ent,SHOW);
        xtimer=0; //reset xtimer
        my.ambient=0;
        camera.z=campos.z;
        show_msg(); //show text messages
        while(scene==0)
        {
                my.v+=18*time_step;
                camera.x=campos.x+70*sinv(3*xtimer);
                camera.y=campos.y+70*cosv(3*xtimer);
                camera.pan=50*(sinv(2*xtimer));
                camera.tilt=-90+15*cosv(3*xtimer);
                wait (1);
        }
        reset2(intro_ent,SHOW);
        set_extro();
        //everything done here, start extro init
}


//create filename and load pcx file
var msgcount=0;
var msgbase=0;
var msgtotal=0;

function show_message(msgcount)
{
STRING* msgfile_str=str_create("123456789012");
STRING* msg_str=str_create("msg");
STRING* msgnumber_str=str_create("  ");
STRING* pcx_str=str_create(".pcx");
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
                set2(msg_ent,SHOW);
                while(msg_ent.alpha<35)
                {
                        wait (1);
                        msg_ent.alpha+=time_step+time_step;
                }
                msg_ent.alpha=35;
                while(msg_ent.alpha>0)
                {
                        wait (1);
                        msg_ent.alpha-=time_step;
			//some simple effect types for fading out text
                        if (msgfx[msgtotal]==4)
                        {
                                msg_ent.scale_x+=0.2*time_step;
                                msg_ent.x+=15*time_step;
                        }
                        if (msgfx[msgtotal]==1)
                        {
                                msg_ent.x-=10*time_step;
                        }
                        if (msgfx[msgtotal]==2)
                        {
                                msg_ent.x+=10*time_step;
                        }
                        if (msgfx[msgtotal]==3)
                        {
                                msg_ent.scale_x-=0.02*time_step;
                        }
                }
                reset2(msg_ent,SHOW);
                ent_purge(msg_ent);
                wait (-1);
        }
        reset2(msg_ent,SHOW);
        ent_purge(msg_ent);
        msgbase=msgtotal;
}

function show_msg()
{
        set2(acknex_ent,SHOW);
        wait (-2);
        snd_play  (bg_music,80,0);
        sndhandle=result;
        clock_control();
        while (acknex_ent.alpha>0)
        {
                wait (1);
                acknex_ent.alpha-=time_step+time_step+time_step;
                acknex_ent.scale_x+=time_step*0.05;
                acknex_ent.scale_y-=time_step*0.02;
        }
        acknex_ent.alpha=0;
        reset2(acknex_ent,SHOW);
        ent_purge (acknex_ent);
        wait (-2);

        set2(conflict_ent,SHOW);
        while (conflict_ent.skill12<16)
        {
		//this is not time_step corrected properly!!
                wait (-0.125);
                conflict_ent.skill12+=0.5;//time_step;
                conflict_ent.scale_x=1+random(1)-0.5;
                conflict_ent.scale_y=1+random(1)-0.5;
        }
        conflict_ent.scale_x=1;
        conflict_ent.scale_y=1;
        wait (-0.5);
        while (conflict_ent.alpha>0)
        {
                wait (1);
                conflict_ent.alpha-=time_step+time_step;
        }
        conflict_ent.alpha=0;
        reset2(conflict_ent, SHOW);
        ent_purge (conflict_ent);
        wait (-2);
        show_message(8); //start to show next 8 messages
	//synched with bgm
//        scenefade=1;
        while (clock<47)
        {
                wait (1);
        }
        scenefade=1;
        while (clock<85)
        {
                wait (1);
        }
        scenefade=2;
        while (clock<122)
        {
                wait (1);
        }

        scenefade= 3;
        while (clock<197)
        {
                wait (1);
        }

       scenefade=4;
}

function set_extro()
{
	//don't start before extro is fading in
        //yesyes... quick and dirty...
        while (scenefade<4) {wait (1);}
        fade_in_extro(); //get the thing running
        helltimer=0; //resetxtimerr, we can re-use hell xtimer
        my.ambient=0;
        camera.z=campos.z;
        show_credits(); //who did this stuff?
        while(scene<=4)
        {
                my.v-=18*time_step;
                camera.x=campos.x+70*sinv(3*helltimer);
                camera.y=campos.y+160*cosv(3*helltimer);
                camera.pan+=3*time_step;
                camera.tilt=-90+15*cosv(3*helltimer);
                wait (1);
        }
        reset(intro_ent,SHOW);
}

//same filename creation method from above
//it allows showing different bitmaps
//in a while loop without having
//a lot of script
var credits=0;
function show_credits()
{
STRING* crdfile_str=str_create("123456789012");
STRING* crd_str=str_create("credits");
STRING* crdnumber_str=str_create("  ");
STRING* pcx_str=str_create(".pcx");
        wait (-6);
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
                set2(msg_ent,SHOW);
                while(msg_ent.alpha<35)
                {
                        wait (1);
                        msg_ent.alpha+=time_step+time_step;
                }
                msg_ent.alpha=35;
                wait (-6);
                while(msg_ent.alpha>0)
                {
                        wait (1);
                        msg_ent.alpha-=time_step;
                }
                reset2(msg_ent,SHOW);
                ent_purge(msg_ent);
                wait (-1);
        }
        reset2(msg_ent,SHOW);
        ent_purge(msg_ent);
        fadecam.alpha=0;
        set(fadecam,SHOW|TRANSLUCENT);
        while (fadecam.alpha<100)
        {
                wait (1);
                fadecam.alpha+=time_step+time_step;
        }
        reset(fadecam,TRANSLUCENT);
        wait (-0.5);
	//we did it, return to Windows
        sys_exit("");
}

//confrontation part, view init
action set_fadecam()
{
        //my.invisible=1;
        //my.passable=1;
        vec_set (fadecam.x, my.x);
        vec_set (fadecam.pan, nullvector);
}

VECTOR pipecenter;
ENTITY* innerpipe;

action rot_plate()
{
	wait (3);
        while (scene<=3)
        {
                my.pan-=10*time_step;
                wait (1);
        }
}

//assigned to inner pipe
action rot_innerpipe()
{
        while (scenefade<3) {wait (1);}
        fade_in_scene3(); //scene3 is starting now
        innerpipe=me; //entity pointer ened for positioning outer pipe
        set(my,PASSABLE);
        vec_set (camera.x,my.x);
        vec_set (camera.x,nullvector);
        vec_set (pipecenter.x,my.x);
        while (scene<=3)
        {
                my.pan+=5*time_step;
                my.skill10+=5*time_step;
                my.ambient=70*abs(sinv(xtimer*30));
                scene3_ent.alpha=50*abs(sinv(xtimer*30));
                wait (1);
        }
}

//assigned to outer pipe
action rot_outerpipe()
{
VECTOR* pipe_dist=vector(150,100,0);
VECTOR temp;
        while (scenefade<3) {wait (1);}
        set(my,PASSABLE);
        show_images(); //start fading in images
        vec_set (my.x,pipecenter);
        camera.z=pipecenter.z;
        while(scene<=3)
        {
	        fog_color=0;
                pipe_dist.x=100+abs(100*cosv(xtimer*2));
                pipe_dist.y=pipe_dist.x/2;
                temp.x=pipecenter.x+pipe_dist.x*cosv(innerpipe.pan)-my.x;
                temp.y=pipecenter.y+pipe_dist.x*sinv(innerpipe.pan)-my.y;
                temp.z=0;
                c_move(me,nullvector,temp,IGNORE_WORLD|IGNORE_MAPS);
                //move me,nullvector,temp; //old style
                pipe_dist.x=150+abs(150*cosv(xtimer*2));
                temp.x=pipecenter.x+pipe_dist.y*cosv(innerpipe.skill10);//-heavencam.x;
                temp.y=pipecenter.y+pipe_dist.y*sinv(innerpipe.skill10);//-heavencam.y;
                temp.z=0;
                vec_set(heavencam.x, temp);
                //move_view heavencam,nullvector,temp; // old style
                my.pan+=9*time_step;
                my.ambient=70*abs(cosv(xtimer*30));
                heavencam.pan-=7*time_step;
                heavencam.tilt=-90+35*sinv(xtimer*5);
                heavencam.z=pipecenter.z-abs(450*cosv(xtimer*6));
                wait (1);

        }
}

//show entities at predefined positions
//again, the filename is constructed
var imagenr;


function show_images()
{
VECTOR* pos1=vector(533, 120, -70);
VECTOR* pos2=vector(533, 120, 70);
VECTOR* pos3=vector(533, -120, -70);
VECTOR* pos4=vector(533, -120, 70);

STRING* goodfile1_str=str_create("123456789012");
STRING* goodfile2_str=str_create("123456789012");
STRING* evilfile1_str=str_create("123456789012");
STRING* evilfile2_str=str_create("123456789012");
STRING* good2_str=str_create("good");
STRING* good1_str=str_create("gchar");
STRING* evil2_str=str_create("evil");
STRING* evil1_str=str_create("echar");
STRING* imgnumber_str=str_create("  ");
STRING* pcx_str=str_create(".pcx");
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
                set2(evil1_ent,SHOW);
                evil1_ent.alpha=100;
                set2(evil2_ent,SHOW);
                evil2_ent.alpha=50;
                set2(good1_ent,SHOW);
                good1_ent.alpha=100;
                set2(good2_ent,SHOW);
                good2_ent.alpha=50;
                while (evil1_ent.alpha>0)
                {
                        wait (1);
                        evil1_ent.alpha-=time_step+time_step;
                        evil2_ent.alpha-=time_step;
                        good1_ent.alpha-=time_step+time_step;
                        good2_ent.alpha-=time_step;
                        good1_ent.x+=10*time_step;
                        evil1_ent.x+=10*time_step;
                        good2_ent.scale_x+=0.05*time_step;
                        evil2_ent.scale_x+=0.05*time_step;

                }
                reset2(evil1_ent,SHOW);
                reset2(evil2_ent,SHOW);
                reset2(good1_ent,SHOW);
                reset2(good2_ent,SHOW);
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
        set2(chao_ent,SHOW);
        while (chao_ent.alpha>0)
        {
                wait (1);
                chao_ent.alpha-=time_step+time_step;
                chao_ent.x+=25*time_step;
        }
        reset2(chao_ent,SHOW);
        ent_purge (chao_ent);
        wait (1);
        show_message(4); //next 4 text messages
}

function fade_in_scene3()
{
        heavencam.alpha=0;
	set(heavencam, TRANSLUCENT|SHOW);
        heavencam.fog_start=100;//fixme
        hellborder_ent.alpha=100;
	set2(hellborder_ent, TRANSLUCENT);
        reset2(hell_ent,SHOW);
        reset2(hell2_ent,SHOW);
        reset2(hell3_ent,SHOW);
        reset2(hell4_ent,SHOW);
        while(heavencam.alpha<100)
        {
                wait (1);
                heavencam.alpha+=time_step+time_step;
                hellborder_ent.alpha-=4*time_step;
                hellborder_ent.alpha=maxv(0,hellborder_ent.alpha);
                if (heavencam.alpha<=50)
                {
                        camera.fog_start+=time_step+time_step;
                }
                else
                {
                        set2(scene3_ent,SHOW);
                        camera.fog_start=100;
                }
        }
        heavencam.alpha=100;
	reset(heavencam, TRANSLUCENT);
	reset(camera, SHOW);
        scene=3; //set scene indicator variable
}

//extro fading function
function fade_in_extro()
{
set(heavencam,TRANSLUCENT );
        heavencam.alpha=100;
        intro_ent.alpha=0;
set2(intro_ent,SHOW);
set(camera,SHOW);
        camera.fog_start=100; //fixme
        camera.alpha=0;
        while(heavencam.alpha>0)
        {
                wait (1);
                heavencam.alpha-=time_step+time_step;
                camera.alpha+=time_step+time_step;
                if (heavencam.alpha<=50)
                {
                        reset2(scene3_ent,SHOW);
                        camera.fog_start-=time_step+time_step;
                        fog_color=1;
                        intro_ent.alpha+=time_step;
                        intro_ent.alpha=minv(50,intro_ent.alpha);

                }

        }
reset(camera,TRANSLUCENT );
        camera.fog_start=50;
        heavencam.alpha=0;
reset(heavencam,TRANSLUCENT|SHOW);
        scene=4; // set scene indicator variable
}
