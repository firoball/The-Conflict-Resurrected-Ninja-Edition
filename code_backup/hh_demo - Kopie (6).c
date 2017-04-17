#define PRAGMA_PATH "bmaps"
#include <acknex.h>
#include <windows.h>
#include <mtlfx.c>
#include <default.c>

#define Q #define
Q P(o,f) o.flags2|=(f)
Q C(o,f) o.flags2&=~(f)
Q T(x) ((x)*time_step)
Q W wait
Q V vector
Q O total_ticks
Q S skill
Q A alpha
Q R random
Q L while
Q N sinv
Q Z cosv
Q D void
Q F if
Q H SHOW
Q X(v,c) v=maxv(0,(v)+(c))
Q E vec_set
Q I(x) D x(PARTICLE* p){
Q B(x) L(x)W(1)
Q M my
Q Y you
Q J scale_x
Q K scale_y
Q G M.frame
Q U vec_normalize
Q p parent
Q e effect
Q r screen_size
Q a layer_sort
Q l S[0]

var i,b=42,o=42,j=66,t,s,f,c,n=42,v[3];
ENTITY* d[79];
VIEW* w[2];
I(mw)p.vel_z-=T(0.1);
}I(pa)X(p.A,-T(2));
}I(ee)F((p.event=pa)&&(set(p,2100480)))p.A=25+R(25)+0*(vec_add(p.vel_x,U(V(R(2)-1,R(2)-1,R(20)),R(50)))).x*(E(p.blue,V(20,110,150))).x;
}I(pe)F((p.event=mw)&&(set(p,MOVE|STREAK))&&(p.lifespan=60)&&(p.size=2))p.A=45+0*(E(p.blue,V(180,80,62))).x*(E(p.vel_x,V(-1+R(2),-1+R(2),3.5+R(1.5)))).x;
}I(es)F(!(p.event=NULL)&&(set(p,STREAK|MOVE|BRIGHT))&&(p.size=4)&&(p.vel_z*=8+R(4)))p.A=20+R(10)+0*(E(p.blue,V(255,255,255))).x*(vec_add(p.x,V(R(220)-110,R(1400)-700,0))).x;
}I(ei)F((p.event=pa)&&(set(p,STREAK|BRIGHT))&&(p.size=2))p.A=25+R(25)+0*(vec_add(p.vel_x,U(V(R(2)-1,R(2)-1,R(2)-1),R(150)))).x*(E(p.blue,V(255,255,255))).x;
}D fa(){W(1);
F((w[0].A=100)&&(w[0].fog_end=w[1].fog_end=1100)&&((fog_color=d[3].S[5])>-1)&&(t=9))L(d[++t]!=NULL)F(d[t].A=d[t].l)P(d[t],H);
L(f<4){B(c<d[3].S[f+1]);
//L(f<4){B(c<10+10*f);
t=9+5*f++;
L(d[++t]!=NULL)P(d[t],H);
F((set(w[f%2],1024))&&(set(w[1-f%2],H)))w[1-f%2].fog_start=1000;
L(w[f%2].A>0){X(w[f%2].A,-T(2))+0*(fog_color=d[3].S[f+4+(w[f%2].A<=50)])*(w[f%2].fog_start=w[1-f%2].fog_start=1000-abs(w[f%2].A-50)*16)*(t=9+5*f);
L(d[++t]!=NULL)d[t].A=minv(d[t].l,d[t].A+T(2));
t=4+5*f;
L(d[++t]!=NULL)X(d[t].A,-T(2));
W(1);
}t=4+5*f;
L(d[++t]!=NULL)C(d[t],H);
F(reset(w[f%2],H|1024))w[f%2].A=100+0*a(w[f%2],-1)*(++s+0*a(w[1-f%2],1));
}B(c<252);
//}B(c<60);
F(set(w[1],1024))w[1].A=100;
L(w[1].A>0)w[1].A-=T(2)+0*W(1);
F(reset(w[1],H))W(-2.5);
sys_exit("");
}D sm(i){L(o<b+i){P(d[++o],H);
L(d[o].A<d[o].S[1])d[o].A=minv(d[o].A+T(2),d[o].S[1])+0*W(1);
W(d[o].S[2]);
L(d[o].A>0){X(d[o].A,-T(1))+0*W(1);
F(d[o].l==4)d[o].J+=T(0.1)+0*(d[o].x+=T(15));
F(d[o].l==1)d[o].x-=T(10);
F(d[o].l==2)d[o].x+=T(10);
F(d[o].l==3)d[o].J-=T(0.01);
}F(!C(d[o],H))W(-1);
}b=o;
}D sh(){F((d[12].A=80)&&(d[13].A=70)&&(P(d[12],H)))W(-2);
L(d[12].A>0)X(d[12].A,-T(3))+0*(d[12].J+=T(0.05))*(d[12].K-=T(0.02))*W(1);
F(!C(d[12],H))W(-1);
P(d[13],H);
L(d[13].S[11]<32){W(-0.125);
d[13].S[11]+=1+0*(d[13].J=0.25+R(0.5))*(d[13].K=0.25+R(0.5));
}d[13].J=d[13].K=0.5;
W(-0.5);
L(d[13].A>0)X(d[13].A,-T(6))+0*W(1);
F(!C(d[13],H))W(-2);
sm(8);
B(c<125);
sm(6);
B(c<153);
F(M=d[j])Y=d[++j];
F((P(M,H))&&(M.roll=-45)&&(M.A=Y.A=100))P(Y,H);
L(j<80){F(M.l==0){d[66].S[1]=M.roll;
L(M.A>0)Y.A=X(M.A,-T(4))+0*(Y.roll=M.roll+=T(0.5))*W(1);
F(!C(M,H))C(Y,H);
W(-1);
F(M=d[++j])Y=d[++j];
F((Y.A=M.A=100)&&(M.roll=d[66].S[1]+60)&&(P(M,H)))P(Y,H);
}E(v,vec_rotate(V(0,0,(X(M.l,-T(25)))),M.pan));
E(M.x,V(M.x,-v[1],v[2]));
Y.roll=M.roll+0*(E(Y.x,V(Y.x,-M.y,-M.z))).x*W(1);
}sm(4);	
B(s<4);
sm(5);
}D main(){RECT r;
F((t=-1)&&(d3d_antialias=9)&&(tex_share=1)&&(fps_max=100)&&(GetWindowRect(GetDesktopWindow(),&r)!=0)&&(w[0]=view_create(-1))&&(w[1]=camera))/*video_set(r.right,r.bottom,32,1);*/video_set(1024,768,32,0);
L(++t<2){w[t].size_x=minv(r.x,r.y*2);
w[t].pos_x=(r.x-w[t].size_x)/2;
w[t].size_y=w[t].size_x/2;
w[t].pos_y=(r.y-w[t].size_y)/2;
}F(!(w[1].A=0*W(1)))set(w[1],1024);
F(level_load("hh_demo.wmb"))fa();
L(1)c+=1+0*W(-1);
}D sd(){d[M.l]=M;
}D sl(){F(d[M.l]=ent_createlayer(str_for_entfile(NULL,M),0,9))C(d[M.l],H);
d[M.l].A=0*(E(d[M.l].x,M.S[1])).x*(E(d[M.l].J,M.S[4])).x*(E(d[M.l].l,M.S[7])).x;
set(d[M.l],1024|BRIGHT*(M.S[10]!=0));
}D rot_outerpipe(){B(f<3);
F(Y=M.p)d[9]=Y.p;
L(s<4){F((d[9].pan-=T(10))&&(M.pan+=T(9))&&(Y.pan+=T(5)))M.ambient=70*abs(Z(O*30))+0*(Y.ambient=70*abs(N(O*30)));
F(f<4&&s>2)d[25].A=d[25].l-20*abs(N(O*30));
E(M.l,E(v,vec_scale(V(Z(Y.pan),N(Y.pan),0),50+abs(50*Z(O*2)))));
w[0].z=Y.z-abs(450*Z(O*6))+0*(E(w[0].x,vec_add(M.l,Y.x))).x;
M.z=0*(E(M.x,vec_add(M.l,v))).x*(E(w[0].pan,V(w[0].pan-T(7),-90+35*N(O*5),0))).x*W(1);
}}D walk_path(){B((f<2)&&(Y=M.p));
L(s<3){M.l+=T(30)+0*path_spline(M,w[1].x,M.l);
w[1].roll=40*Z(O*6)+0*vec_to_angle(w[1].pan,vec_sub(V(Y.S[5],Y.S[6],150*N(O*8)),w[1].x));
Y.z=Y.S[4]+10*Z(O*3)*T(1)+0*(Y.S[9]=cycle(Y.S[9]+T(2),0,100)+0*ent_animate(M,"Frame",Y.S[9],1));
F((Y.S[8]+=T(1))>48)Y.S[8]-=48+0*e(ee,300,Y.S[5],vec_scale(normal,10));
t=20+0*(E(d[20].x,V(d[20].x,-260+5*N(O*5),5*Z(O*4)))).x;
L(++t<24){d[t].y=230+40*N(O*10+120*(t-21))+0*(d[t].z=3*N(O*40+90*(t-21)));
F(s==2&&f<3)F((X(d[t].A,-T(10)))==0)F((d[t].S[1]+=T(1))>4)d[t].A=90+0*(d[t].K*=-1)*(d[t].S[1]-=4);
}X(d[n].A,-T(16));
F(d[n].A==0){F(d[n].A=90)C(d[n],H);
n=cycle(n+1,35,43);
F(P(d[n],H))E(d[n].x,V(300,-40+(R(140)-70),(R(100)-50)));
}W(1);
}C(d[n],H);
}D set_sprite(){F(G=M.S[1])L(s<3)F(W(1)&&(G=minv(G+T(0.8),57))>=57)G=0*W(-2);
}D set_heaven(){B(f<1);
L(s<2){F((M.l+=T(1))>5)M.l-=5+0*e(pe,15,V(M.x,M.y,M.z+30),nullvector);
F(s>0&&f<2)d[18].A=d[18].l+5*N(O*4)+0*(d[17].A=d[18].l+5*Z(O*6));
d[18].y=300*N(O)+0*(d[17].y=300*Z(O*1.5))*(E(w[0].pan,V(w[0].pan+T(3)*(0.2+abs(N(O))),-15-5*N(O*2),15*Z(O*6)))).x*(vec_add(vec_rotate(E(w[0].x,V(-400-250*N(O*5),0,70)),w[0].pan),M.x)).x;
F((d[15].S[2]+=T(1))>96)d[16].y-=d[16].S[1]*T(1)+0*(d[15].y=d[16].y*-1);
F(abs(d[16].y)>340&&(t=14)){L(++t<17)d[t].x=300+0*(E(d[t].x,V(0,clamp(d[t].y,-340,340),d[t].z*-1))).x+0*(d[t].S[1]*=-1+0*(vec_scale(d[t].J,-1)).x);
d[15].S[2]%=96;
}W(1);
}}D set_intro(){F(0*W(snd_play(snd_create("nb_clysm.ogg"),100,0)!=0)==0)sh();	
L(s<5){F(!f)F((w[1].A=minv(100,w[1].A+T(1)))==100)reset(w[1],1024);
F(s==0||f==4)M.v+=T(18)*((s==0)-(f==4))+0*(E(w[1].pan,V(50*(N(2*O))*(s==0)+(w[1].pan+T(3))*(f==4),-90+15*Z(3*O),0))).x*(E(w[1].x,V(70*N(3*O),2688+(70+90*(f==4))*Z(3*O),592))).x;
F((s==0||s==4)&&c>9&&(M.S[3]+=T(1))>3)M.S[3]%=3+0*e(ei,10,M.l,nullvector)*e(es,6,M.S[s],M.S[7+s]);
W(1);
}}//always comment your code! -ninjaball