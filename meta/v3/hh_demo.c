#define PRAGMA_PATH "bmaps"

#include <acknex.h>
#include <windows.h>
#include <mtlfx.c>
#include <default.c>

#define set2(obj,flag) obj->flags2|=(flag)
#define reset2(obj,flag) obj->flags2&=~(flag)
var temp,scene,scenefade,clock;
VECTOR vec;
ENTITY* data[79];
VIEW* tv[2];


VIEW* heavencam;

function part_alphafade(PARTICLE* p){p.alpha=maxv(p.alpha-2*time_step,0);}
function effect_explo(PARTICLE* p){if((p.event=part_alphafade)&&(set(p,TRANSLUCENT|BRIGHT|STREAK|MOVE)))p.alpha=25+random(25)+0*(vec_add(p.vel_x,vec_normalize(vector(random(2)-1,random(2)-1,random(20)),random(50)))).x*(vec_set(p.blue,vector(20,110,150))).x;}

function move_waterpart(PARTICLE* p){p.vel_z-=0.1*time_step;}

function Xparticle_event(PARTICLE* p) {
	p.red=62;
	p.green=80;
	p.blue=180;
	p.size=2;
	p.vel_z=3.5+random(1.5);
	p.vel_x=-1+random(2);
	p.vel_y=-1+random(2);
	set(p, MOVE|STREAK);
	p.alpha=45;
	p.lifespan=60;
	p.event=move_waterpart;
}

function effect_snow(PARTICLE* p)
{
	p.x += random(220) - 110;
	p.y += random(1400) - 700;
	p.vel_z*=8+random(4);
	p.alpha = 20 + random(10);
	vec_set(p.blue,vector(255,255,255));
	p.size=4;
	set(p,STREAK|MOVE|BRIGHT);
	p.event=NULL;
}

function effect_intro(PARTICLE* p)
{
	vec.x = random(2) - 1;
	vec.y = random(2) - 1;
	vec.z = random(2) - 1;
	vec_normalize(vec.x,random(150));
	vec_add(p.vel_x,vec.x);
	p.alpha = 25 + random(25);
	p.red=255;
	p.green=255;
	p.blue=255;
	p.size=2;
	set(p,STREAK|BRIGHT);
	p.event = part_alphafade;
}

void fader()
{
	tv[0].alpha=/*tv[1].alpha=*/100;
	tv[0].fog_end=tv[1].fog_end=1100;
	wait(1);
	fog_color=data[3].skill[5];
	temp=10;
	while(data[temp]!=NULL)
	{
		set2(data[temp],SHOW);
		data[temp].alpha=data[temp].skill[0];
		temp++;
	}

	while(scenefade<4)
	{
//		while(clock<data[3].skill[scenefade+1]){
		while(clock<10+10*scenefade){
			wait(1);
		}
		scenefade++;
		wait(1);
		temp=10+5*scenefade;
		while(data[temp]!=NULL)
		{
			set2(data[temp],SHOW);
			temp++;
		}
		set(tv[scenefade%2],TRANSLUCENT);
		set(tv[1-scenefade%2],SHOW);
		tv[1-scenefade%2].fog_start=1000;
		while(tv[scenefade%2].alpha>0)
		{
			tv[scenefade%2].alpha=maxv(0,tv[scenefade%2].alpha-2*time_step);
			fog_color=data[3].skill[scenefade+4+(tv[scenefade%2].alpha<=50)];
			tv[scenefade%2].fog_start=tv[1-scenefade%2].fog_start=1000-abs(tv[scenefade%2].alpha-50)*16;


			temp=10+5*scenefade;
			while(data[temp]!=NULL)
			{
				data[temp].alpha=minv(data[temp].skill[0],data[temp].alpha+2*time_step);
				temp++;
			}
			temp=5+5*scenefade;
			while(data[temp]!=NULL)
			{
				data[temp].alpha=maxv(0,data[temp].alpha-2*time_step);
				temp++;
			}

			wait(1);
		}
		temp=5+5*scenefade;
		while(data[temp]!=NULL)
		{
			reset2(data[temp],SHOW);
			temp++;
		}
		reset(tv[scenefade%2],SHOW|TRANSLUCENT);
		tv[scenefade%2].alpha=100;
		layer_sort(tv[scenefade%2],-1);
		layer_sort(tv[1-scenefade%2],1);
		scene++;
	}
	while(clock<252)wait(1);
//while(clock<60)wait(1);
	set(tv[1],TRANSLUCENT);
	tv[1].alpha=100;
	while (tv[1].alpha>0)
	{
		wait (1);
		tv[1].alpha-=2*time_step;
	}
	reset(tv[1],SHOW);
	wait (-2.5);
	sys_exit("");
}

var msgcount=0;
var msgbase=42;
var msgtotal=42;

function show_message(msgcount)
{
	while(msgtotal<msgbase+msgcount)
	{
		msgtotal+=1;
		set2(data[msgtotal],SHOW);
		while(data[msgtotal].alpha<data[msgtotal].skill[1])
		{
			wait (1);
			data[msgtotal].alpha=minv(data[msgtotal].alpha+2*time_step,data[msgtotal].skill[1]);
		}
		wait(data[msgtotal].skill[2]);
		while(data[msgtotal].alpha>0)
		{
			wait (1);
			data[msgtotal].alpha=maxv(data[msgtotal].alpha-time_step,0);
			if (data[msgtotal].skill[0]==4)
			{
				data[msgtotal].scale_x+=0.1*time_step;
				data[msgtotal].x+=15*time_step;
			}
			if (data[msgtotal].skill[0]==1)
			{
				data[msgtotal].x-=10*time_step;
			}
			if (data[msgtotal].skill[0]==2)
			{
				data[msgtotal].x+=10*time_step;
			}
			if (data[msgtotal].skill[0]==3)
			{
				data[msgtotal].scale_x-=0.01*time_step;
			}
		}
		reset2(data[msgtotal],SHOW);
		wait (-1);
	}
	msgbase=msgtotal;
}

function show_msg()
{
	var cnt=66;
	//wait(1);
	data[12].alpha=80;
	data[13].alpha=70;
	set2(data[12],SHOW);

	wait (-2);
	while (data[12].alpha>0)
	{
		wait (1);
		data[12].alpha-=3*time_step;
		data[12].scale_x+=time_step*0.05;
		data[12].scale_y-=time_step*0.02;
	}
	data[12].alpha=0;
	reset2(data[12],SHOW);
	wait (-1);

	set2(data[13],SHOW);
	while (data[13].skill[11]<32)
	{
		wait (-0.125);
		data[13].skill[11]++;
		data[13].scale_x=0.5+random(0.5)-0.25;
		data[13].scale_y=0.5+random(0.5)-0.25;
	}
	data[13].scale_x=0.5;
	data[13].scale_y=0.5;
	wait (-0.5);
	while (data[13].alpha>0)
	{
		wait (1);
		data[13].alpha-=6*time_step;
	}
	data[13].alpha=0;
	reset2(data[13], SHOW);
	wait (-2);
	show_message(8);
	
	while (clock<125) {wait (1);}
	show_message(6);
	while (clock<153) {wait (1);}

	me=data[cnt];
	you=data[++cnt];
	my.roll=-45;
	my.alpha=you.alpha=100;
	set2(me,SHOW);
	set2(you,SHOW);
	while(cnt<80)
	{
		if (my.skill[0]==0)
		{
			data[66].skill[1]=my.roll;
			while(my.alpha>0)
			{
				you.alpha=my.alpha=maxv(0,my.alpha-4*time_step);
				you.roll=my.roll+=0.5*time_step;
				wait(1);
			}	
			reset2(me,SHOW);
			reset2(you,SHOW);
			wait(-1);
			me=data[++cnt];
			you=data[++cnt];
			set2(me,SHOW);
			set2(you,SHOW);
			you.alpha=my.alpha=100;
			my.roll=data[66].skill[1]+60;
		}
		my.skill[0] = maxv(0,my.skill[0]-25*time_step);
		vec_set(vec,vector(0,0,my.skill[0]));
		vec_rotate(vec,my.pan);
		my.y=-vec.y;
		my.z=vec.z;
		you.y=-my.y;
		you.z=-my.z;
		you.roll=my.roll;
		wait(1);
	}
	show_message(4);
		
	while(scene<4){wait(1);}
	show_message(5);
}

function main()
{
   RECT r;
	d3d_antialias=9;
	tex_share = 1;
	fps_max=100;
	//warn_level=2;
	GetWindowRect(GetDesktopWindow(),&r);
	video_set(r.right,r.bottom,32,1); 
	
	//video_set(1024,768,32,0);
	tv[0]=heavencam=view_create(-1);
	tv[1]=camera;
	temp=-1;
	while(++temp<2)
	{
		tv[temp].size_x=minv(screen_size.x,screen_size.y*2);
		tv[temp].pos_x=(screen_size.x-tv[temp].size_x)/2;
		tv[temp].size_y=tv[temp].size_x/2;
		tv[temp].pos_y=(screen_size.y-tv[temp].size_y)/2;
	}
	wait(1);
	camera.alpha=0;
	set(camera,TRANSLUCENT);

	level_load("hh_demo.wmb");

	fader();
	while(1)
	{
		wait (-1);
		clock++;
	}
}

action sd() 
{data[my.skill[0]]=me;}

action sl() 
{
	data[my.skill[0]]=ent_createlayer(str_for_entfile(NULL,me),0,9);
	data[my.skill[0]].alpha=0*(vec_set(data[my.skill[0]].x,my.skill[1])).x*(vec_set(data[my.skill[0]].scale_x,my.skill[4])).x*(vec_set(data[my.skill[0]].skill[0],my.skill[7])).x;
	reset2(data[my.skill[0]],SHOW);
	set(data[my.skill[0]],TRANSLUCENT|BRIGHT*(my.skill[10]!=0));
}

action rot_outerpipe()
{
	while (scenefade<3){wait(1);}
	you=my.parent;
	data[9]=you.parent;
	while(scene<4)
	{
		if((data[9].pan-=10*time_step)&&(my.pan+=9*time_step)&&(you.pan+=5*time_step)){}
		my.ambient=70*abs(cosv(total_ticks*30));
		you.ambient=70*abs(sinv(total_ticks*30));
		if(scenefade<4&&scene==3)data[25].alpha=data[25].skill[0]-20*abs(sinv(total_ticks*30));
		vec_set(my.skill[0],vec_set(vec,vec_scale(vector(cosv(you.pan),sinv(you.pan),0),50+abs(50*cosv(total_ticks*2)))));
		heavencam.z=you.z-abs(450*cosv(total_ticks*6))+0*(vec_set(heavencam.x,vec_add(my.skill[0],you.x))).x;
		my.z=0*(vec_set(my.x,vec_add(my.skill[0],vec))).x*(vec_set(heavencam.pan,vector(heavencam.pan-7*time_step,-90+35*sinv(total_ticks*5),0))).x;
		wait (1);
	}
}

action walk_path()
{
	var count=42;
	while (scenefade<2) {wait (1);}
	you=my.parent;
	while (scene<3)
	{

		//wait(1);
		my.skill[0]+=30*time_step+0*path_spline(me,camera.x,my.skill[0]);
		camera.roll=40*cosv(total_ticks*6)+0*vec_to_angle(camera.pan,vec_sub(vector(you.skill[5],you.skill[6],150*sinv(total_ticks*8)),camera.x));
		you.z=you.skill[4]+10*cosv(total_ticks*3)*time_step;
		you.skill[9]=cycle(you.skill[9]+time_step*2,0,100)+0*ent_animate(me,"Frame",you.skill[9],ANM_CYCLE);
		if((you.skill[8]+=time_step)>48)you.skill[8]-=48+0*effect(effect_explo,300,you.skill[5],vec_scale(normal,10));
		vec_set(data[20].x,vector(data[20].x,-260+5*sinv(total_ticks*5),5*cosv(total_ticks*4)));
		temp=20;
		while(++temp<24)
		{
			data[temp].y=230+40*sinv(total_ticks*10+120*(temp-21));
			data[temp].z=3*sinv(total_ticks*40+90*(temp-21));
			if(scene==2&&scenefade<3)
			{
				data[temp].alpha=maxv(0,data[temp].alpha-10*time_step);
				if(data[temp].alpha==0)
				{
					if((data[temp].skill[1]+=time_step)>4)
					{
						data[temp].alpha=90;
						data[temp].scale_y*=-1;
						data[temp].skill[1]-=4;
					}
				}
			}
		}
		data[count].alpha=maxv(0,data[count].alpha-16*time_step);
		if(data[count].alpha==0)
		{
			reset2(data[count],SHOW);
			data[count].alpha=90;
			count=cycle(count+1,35,43);
			vec_set(data[count].x,vector(300,-40+(random(140)-70),(random(100)-50)));
			set2(data[count],SHOW);
		}
		wait(1);
	}
	reset2(data[count],SHOW);
}

action set_sprite()
{
	my.frame=my.skill[1];
	while(scene<3)if(wait(1)&&(my.frame=minv(my.frame+time_step*0.8,57))>=57)my.frame=0*wait(-2);
}

action set_heaven()
{
	while (scenefade!=1) {wait(1);}
	data[16].skill[1]=10;

	while (scene<2)
	{
		if((my.skill[0]+=time_step)>5)my.skill[0]-=5+0*effect(Xparticle_event,15,vector(my.x,my.y,my.z+30),nullvector);
		data[18].y=300*sinv(total_ticks);
		data[17].y=300*cosv(total_ticks*1.5);
		if(scenefade<2)
		{
			data[18].alpha=data[18].skill[0]+5*sinv(total_ticks*4);
			data[17].alpha=data[18].skill[0]+5*cosv(total_ticks*6);
		}
		vec_set(heavencam.pan,vector(heavencam.pan+3*time_step*(0.2+abs(sinv(total_ticks))),-15-5*sinv(total_ticks*2),15*cosv(total_ticks*6)));
		vec_set(heavencam.x,vector(-400-250*sinv(total_ticks*5),0,70));
		vec_rotate(heavencam.x,heavencam.pan);
		vec_add(heavencam.x,my.x);
		if((data[15].skill[2]+=time_step)>96)
		{
			data[16].y-=data[16].skill[1]*time_step;
			data[15].y=data[16].y*-1;
		}
		if (abs(data[16].y)>340&&(temp=14))
		{
			while(++temp<17)
			{
				data[temp].x=300+0*(vec_set(data[temp].x,vector(0,clamp(data[temp].y,-340,340),data[temp].z*-1))).x;
				data[temp].skill[1]*=-1+0*(vec_scale(data[temp].scale_x,-1)).x;
			}
			data[15].skill[2]%=96;
		}
		wait (1);
	}
}

action set_intro()
{
	snd_play(snd_create("nb_clysm.ogg"),100,0);
	wait (1);
	show_msg();
	while(scene<5)
	{
		if(!scenefade)
			if((camera.alpha=minv(100,camera.alpha+1.5*time_step))==100)reset(camera,TRANSLUCENT);
		if((scene==0)||(scenefade==4))
		{
			my.v+=18*time_step*((scene==0)-(scenefade==4));
			vec_set(camera.pan,vector(50*(sinv(2*total_ticks))*(scene==0)+(camera.pan+3*time_step)*(scenefade==4),-90+15*cosv(3*total_ticks),0));
			vec_set(camera.x,vector(70*sinv(3*total_ticks),2688+(70+90*(scenefade==4))*cosv(3*total_ticks),592));
		}
		if((scene==0||scene==4)&&clock>9&&(my.skill[3]+=time_step)>3)
		{
			effect(effect_intro,10,my.skill[0],nullvector);
			effect(effect_snow,6,my.skill[scene],my.skill[7+scene]);
			my.skill[3]%=3;
		}
		wait(1);
		DEBUG_VAR(clock, 23);
	}
}
