#define PRAGMA_PATH "bmaps"
#include <acknex.h>
#include <windows.h>
#include <mtlfx.c>
#include <default.c>
#define P(o,f) o.flags2|=(f)
#define C(o,f) o.flags2&=~(f)
#define T(x) ((x)*time_step)
#define W wait
#define V vector
#define O total_ticks
#define S skill
#define A alpha
#define R random
#define L while
#define N sinv
#define Z cosv
#define D void
#define F if
#define H SHOW
#define X(v,c) v=maxv(0,(v)+(c))
#define E vec_set
#define I PARTICLE* p
#define B(x) L(x)W(1)

var i,b=42,o=42,j=66,t,s,f,c,n=42;
VECTOR v;
ENTITY* d[79];
VIEW* w[2];
D mw(I){p.vel_z-=T(0.1);
}D pa(I){p.A=maxv(p.A-T(2),0);
}D ee(I){F((p.event=pa)&&(set(p,TRANSLUCENT|BRIGHT|STREAK|MOVE)))p.A=25+R(25)+0*(vec_add(p.vel_x,vec_normalize(V(R(2)-1,R(2)-1,R(20)),R(50)))).x*(E(p.blue,V(20,110,150))).x;
}D pe(I){F((p.event=mw)&&(set(p,MOVE|STREAK))&&(p.lifespan=60)&&(p.size=2))p.A=45+0*(E(p.blue,V(180,80,62))).x*(E(p.vel_x,V(-1+R(2),-1+R(2),3.5+R(1.5)))).x;
}D es(I){F(!(p.event=NULL)&&(set(p,STREAK|MOVE|BRIGHT))&&(p.size=4)&&(p.vel_z*=8+R(4)))p.A=20+R(10)+0*(E(p.blue,V(255,255,255))).x*(vec_add(p.x,V(R(220)-110,R(1400)-700,0))).x;
}D ei(I){F((p.event=pa)&&(set(p,STREAK|BRIGHT))&&(p.size=2))p.A=25+R(25)+0*(vec_add(p.vel_x,vec_normalize(V(R(2)-1,R(2)-1,R(2)-1),R(150)))).x*(E(p.blue,V(255,255,255))).x;
}D fa(){W(1);
F((w[0].A=100)&&(w[0].fog_end=w[1].fog_end=1100)&&((fog_color=d[3].S[5])>-1)&&(t=9))L(d[++t]!=NULL)F(d[t].A=d[t].S[0])P(d[t],H);
L(f<4){L(c<d[3].S[f+1])W(1);
//L(f<4){L(c<10+10*f)W(1);
t=9+5*f++;
L(d[++t]!=NULL)P(d[t],H);
F((set(w[f%2],1024))&&(set(w[1-f%2],H)))w[1-f%2].fog_start=1000;
L(w[f%2].A>0){w[f%2].A=maxv(0,w[f%2].A-T(2))+0*(fog_color=d[3].S[f+4+(w[f%2].A<=50)])*(w[f%2].fog_start=w[1-f%2].fog_start=1000-abs(w[f%2].A-50)*16)*(t=9+5*f);
L(d[++t]!=NULL)d[t].A=minv(d[t].S[0],d[t].A+T(2));
t=4+5*f;
L(d[++t]!=NULL)d[t].A=maxv(0,d[t].A-T(2));
W(1);
}t=4+5*f;
L(d[++t]!=NULL)C(d[t],H);
F(reset(w[f%2],H|1024))w[f%2].A=100+0*layer_sort(w[f%2],-1)*(s+=1+0*layer_sort(w[1-f%2],1));
}L(c<252)W(1);
//}L(c<60)W(1);
F(set(w[1],1024))w[1].A=100;
L(w[1].A>0)w[1].A-=T(2)+0*W(1);
F(reset(w[1],H))W(-2.5);
sys_exit("");
}D sm(i){L(o<b+i){P(d[++o],H);
L(d[o].A<d[o].S[1])d[o].A=minv(d[o].A+T(2),d[o].S[1])+0*W(1);
W(d[o].S[2]);
L(d[o].A>0){d[o].A=maxv(d[o].A-T(1),0)+0*W(1);
F(d[o].S[0]==4)d[o].scale_x+=T(0.1)+0*(d[o].x+=T(15));
F(d[o].S[0]==1)d[o].x-=T(10);
F(d[o].S[0]==2)d[o].x+=T(10);
F(d[o].S[0]==3)d[o].scale_x-=T(0.01);
}F(!C(d[o],H))W(-1);
}b=o;
}D sh(){F((d[12].A=80)&&(d[13].A=70)&&(P(d[12],H)))W(-2);
L(d[12].A>0)d[12].A=maxv(0,d[12].A-T(3))+0*(d[12].scale_x+=T(0.05))*(d[12].scale_y-=T(0.02))*W(1);
F(!C(d[12],H))W(-1);
P(d[13],H);
L(d[13].S[11]<32){W(-0.125);
d[13].S[11]+=1+0*(d[13].scale_x=0.25+R(0.5))*(d[13].scale_y=0.25+R(0.5));
}d[13].scale_x=d[13].scale_y=0.5;
W(-0.5);
L(d[13].A>0)d[13].A=maxv(0,d[13].A-T(6))+0*W(1);
F(!C(d[13],H))W(-2);
sm(8);
L(c<125)W(1);
sm(6);
L(c<153)W(1);
F(me=d[j])you=d[++j];
F((P(me,H))&&(my.roll=-45)&&(my.A=you.A=100))P(you,H);
L(j<80){F(my.S[0]==0){d[66].S[1]=my.roll;
L(my.A>0)you.A=my.A=maxv(0,my.A-T(4))+0*(you.roll=my.roll+=T(0.5))*W(1);
F(!C(me,H))C(you,H);
W(-1);
F(me=d[++j])you=d[++j];
F((you.A=my.A=100)&&(my.roll=d[66].S[1]+60)&&(P(me,H)))P(you,H);
}E(v,vec_rotate(V(0,0,(my.S[0]=maxv(0,my.S[0]-T(25)))),my.pan));
E(my.x,V(my.x,-v.y,v.z));
you.roll=my.roll+0*(E(you.x,V(you.x,-my.y,-my.z))).x*W(1);
}sm(4);	
L(s<4)W(1);
sm(5);
}D main(){RECT r;
F((t=-1)&&(d3d_antialias=9)&&(tex_share=1)&&(fps_max=100)&&(GetWindowRect(GetDesktopWindow(),&r)!=0)&&(w[0]=view_create(-1))&&(w[1]=camera))/*video_set(r.right,r.bottom,32,1);*/video_set(1024,768,32,0);
L(++t<2){w[t].size_x=minv(screen_size.x,screen_size.y*2);
w[t].pos_x=(screen_size.x-w[t].size_x)/2;
w[t].size_y=w[t].size_x/2;
w[t].pos_y=(screen_size.y-w[t].size_y)/2;
}F(!(w[1].A=0*W(1)))set(w[1],1024);
F(level_load("hh_demo.wmb"))fa();
L(1)c+=1+0*W(-1);
}D sd(){d[my.S[0]]=me;
}D sl(){F(d[my.S[0]]=ent_createlayer(str_for_entfile(NULL,me),0,9))C(d[my.S[0]],H);
d[my.S[0]].A=0*(E(d[my.S[0]].x,my.S[1])).x*(E(d[my.S[0]].scale_x,my.S[4])).x*(E(d[my.S[0]].S[0],my.S[7])).x;
set(d[my.S[0]],1024|BRIGHT*(my.S[10]!=0));
}D rot_outerpipe(){L(f<3)W(1);
F(you=my.parent)d[9]=you.parent;
L(s<4){F((d[9].pan-=T(10))&&(my.pan+=T(9))&&(you.pan+=T(5)))my.ambient=70*abs(Z(O*30))+0*(you.ambient=70*abs(N(O*30)));
F(f<4&&s>2)d[25].A=d[25].S[0]-20*abs(N(O*30));
E(my.S[0],E(v,vec_scale(V(Z(you.pan),N(you.pan),0),50+abs(50*Z(O*2)))));
w[0].z=you.z-abs(450*Z(O*6))+0*(E(w[0].x,vec_add(my.S[0],you.x))).x;
my.z=0*(E(my.x,vec_add(my.S[0],v))).x*(E(w[0].pan,V(w[0].pan-T(7),-90+35*N(O*5),0))).x*W(1);
}}D walk_path(){L((f<2)&&(you=my.parent))W(1);
L(s<3){my.S[0]+=T(30)+0*path_spline(me,w[1].x,my.S[0]);
w[1].roll=40*Z(O*6)+0*vec_to_angle(w[1].pan,vec_sub(V(you.S[5],you.S[6],150*N(O*8)),w[1].x));
you.z=you.S[4]+10*Z(O*3)*T(1)+0*(you.S[9]=cycle(you.S[9]+T(2),0,100)+0*ent_animate(me,"Frame",you.S[9],1));
F((you.S[8]+=T(1))>48)you.S[8]-=48+0*effect(ee,300,you.S[5],vec_scale(normal,10));
t=20+0*(E(d[20].x,V(d[20].x,-260+5*N(O*5),5*Z(O*4)))).x;
L(++t<24){d[t].y=230+40*N(O*10+120*(t-21))+0*(d[t].z=3*N(O*40+90*(t-21)));
F(s==2&&f<3)F((d[t].A=maxv(0,d[t].A-T(10)))==0)F((d[t].S[1]+=T(1))>4)d[t].A=90+0*(d[t].scale_y*=-1)*(d[t].S[1]-=4);
}d[n].A=maxv(0,d[n].A-T(16));
F(d[n].A==0){F(d[n].A=90)C(d[n],H);
n=cycle(n+1,35,43);
F(P(d[n],H))E(d[n].x,V(300,-40+(R(140)-70),(R(100)-50)));
}W(1);
}C(d[n],H);
}D set_sprite(){F(my.frame=my.S[1])L(s<3)F(W(1)&&(my.frame=minv(my.frame+T(0.8),57))>=57)my.frame=0*W(-2);
}D set_heaven(){L(f<1)W(1);
L(s<2){F((my.S[0]+=T(1))>5)my.S[0]-=5+0*effect(pe,15,V(my.x,my.y,my.z+30),nullvector);
F(s>0&&f<2)d[18].A=d[18].S[0]+5*N(O*4)+0*(d[17].A=d[18].S[0]+5*Z(O*6));
d[18].y=300*N(O)+0*(d[17].y=300*Z(O*1.5))*(E(w[0].pan,V(w[0].pan+T(3)*(0.2+abs(N(O))),-15-5*N(O*2),15*Z(O*6)))).x*(vec_add(vec_rotate(E(w[0].x,V(-400-250*N(O*5),0,70)),w[0].pan),my.x)).x;
F((d[15].S[2]+=T(1))>96)d[16].y-=d[16].S[1]*T(1)+0*(d[15].y=d[16].y*-1);
F(abs(d[16].y)>340&&(t=14)){L(++t<17)d[t].x=300+0*(E(d[t].x,V(0,clamp(d[t].y,-340,340),d[t].z*-1))).x+0*(d[t].S[1]*=-1+0*(vec_scale(d[t].scale_x,-1)).x);
d[15].S[2]%=96;
}W(1);
}}D set_intro(){F(0*W(snd_play(snd_create("nb_clysm.ogg"),100,0)!=0)==0)sh();	
L(s<5){F(!f)F((w[1].A=minv(100,w[1].A+T(1)))==100)reset(w[1],1024);
F(s==0||f==4)my.v+=T(18)*((s==0)-(f==4))+0*(E(w[1].pan,V(50*(N(2*O))*(s==0)+(w[1].pan+T(3))*(f==4),-90+15*Z(3*O),0))).x*(E(w[1].x,V(70*N(3*O),2688+(70+90*(f==4))*Z(3*O),592))).x;
F((s==0||s==4)&&c>9&&(my.S[3]+=T(1))>3)my.S[3]%=3+0*effect(ei,10,my.S[0],nullvector)*effect(es,6,my.S[s],my.S[7+s]);
W(1);
}}//always comment your code! -ninjaball