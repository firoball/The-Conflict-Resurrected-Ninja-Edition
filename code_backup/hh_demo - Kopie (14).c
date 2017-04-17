#define PRAGMA_PATH "bmaps"
#include <acknex.h>
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
Q UU vec_normalize
Q p parent
Q e effect
Q r screen_size
Q LS layer_sort
Q a S[1]
Q l S[0]
Q g d[o]
Q m W(1)
Q h pan
Q j roll
Q kk vec_add
Q MM vec_scale
Q q &&(set(p
Q dd fog_start
Q aa p.event
Q _ &&
Q R2 R(2)-1
Q S3 &&(p.size=3)
Q U 100

var i,b=42,o=42,j=66,t,s,f,c,n=42,v[3];
ENTITY* d[79];
VIEW* w[2];
I(mw)p.vel_z-=T(.1);
}I(pa)X(p.A,-T(2));
}I(ee)F((aa=pa)q,2100480)))p.A=25+R(25);
kk(p.vel_x,UU(V(R2,R2,R(20)),R(50)));
E(p.blue,d[2].a);
}I(pe)F((aa=mw)q,2304))_(p.z+=30)S3)p.A=45;
E(p.blue,d[4].a);
E(p.vel_x,V(R2,R2,3.5+R(1.5)));
}I(es)F(!(aa=0)q,2099456))S3 _(p.vel_z*=8+R(4)))p.A=20+R(10);
E(p.blue,d[1].a);
kk(p.x,V(R(220)-110,R(1400)-700,0));
}I(ei)F((aa=pa)q,2097408))S3)p.A=25+R(25);
kk(p.vel_x,UU(V(R2,R2,R2),R(150)));
E(p.blue,d[1].a);
}D fa(){m;
F((w[0].A=U)_/*(w[0].fog_end=w[1].fog_end=1100)_*/((fog_color=d[3].S[5])>-1)_(t=9))L(d[++t]!=0)F(d[t].A=d[t].l)P(d[t],H);
//L(f<4){B(c<d[3].S[f+1]);
L(f<4){B(c<10+20*f);
t=9+5*f++;
L(d[++t]!=0)P(d[t],H);
F((set(w[f%2],1024))_(set(w[1-f%2],H)))w[1-f%2].dd=1000;
L(w[f%2].A>0){X(w[f%2].A,-T(2))+0*(fog_color=d[3].S[f+4+(w[f%2].A<=50)])*(w[f%2].dd=w[1-f%2].dd=1000-abs(w[f%2].A-50)*16)*(t=9+5*f);
L(d[++t]!=0)d[t].A=minv(d[t].l,d[t].A+T(2));
t=4+5*f;
L(d[++t]!=0)X(d[t].A,-T(2));
m;
}t=4+5*f;
L(d[++t]!=0)C(d[t],H);
F(reset(w[f%2],17408))w[f%2].A=U+0*LS(w[f%2],-1)*(++s+0*LS(w[1-f%2],1));
}B(c<252);
//}B(c<60);
F(set(w[1],1024))w[1].A=U;
L(w[1].A>0)w[1].A-=T(2)+0*m;
F(reset(w[1],H))W(-2.5);
sys_exit("");
}D sm(i){L(o<b+i){P(d[++o],H);
L(g.A<g.a)g.A=minv(g.A+T(2),g.a)+0*m;
W(g.S[2]);
L(g.A>0){X(g.A,-T(1))+0*m;
F(g.l==4)g.J+=T(.1)+0*(g.x+=T(15));
F(g.l==1)g.x-=T(10);
F(g.l==2)g.x+=T(10);
F(g.l==3)g.J-=T(.01);
}F(!C(g,H))W(-1);
}b=o;
}D sh(){F((d[12].A=80)_(d[13].A=70)_(P(d[12],H)))W(-2);
L(d[12].A>0)X(d[12].A,-T(3))+0*(d[12].J+=T(.05))*(d[12].K-=T(.02))*m;
F(!C(d[12],H))W(-1);
P(d[13],H);
L(d[13].S[11]<32){W(-.125);
d[13].S[11]+=1+0*(d[13].J=.25+R(.5))*(d[13].K=.25+R(.5));
}d[13].J=d[13].K=.5;
W(-.5);
L(d[13].A>0)X(d[13].A,-T(6))+0*m;
F(!C(d[13],H))W(-2);
sm(8);
B(c<125);
sm(6);
B(c<153);
F(M=d[j])Y=d[++j];
F((P(M,H))_(M.j=-45)_(M.A=Y.A=U))P(Y,H);
L(j<80){F(M.l==0){d[66].a=M.j;
L(M.A>0)Y.A=X(M.A,-T(4))+0*(Y.j=M.j+=T(.5))*m;
F(!C(M,H))C(Y,H);
W(-1);
F(M=d[++j])Y=d[++j];
F((Y.A=M.A=U)_(M.j=d[66].a+60)_(P(M,H)))P(Y,H);
}E(v,vec_rotate(V(0,0,(X(M.l,-T(25)))),M.h));
E(M.x,V(M.x,-v[1],v[2]));
Y.j=M.j;
E(Y.x,V(Y.x,-M.y,-M.z));
m;
}sm(4);	
B(s<4);
sm(5);
}D main(){F((t=-1)_(video_mode=12*video_screen=1)_(w[0]=view_create(-1))_(w[1]=camera))m;
L(++t<2){w[t].size_x=minv(r.x,r.y*2);
w[t].pos_x=(r.x-w[t].size_x)/2;
w[t].size_y=w[t].size_x/2;
w[t].pos_y=(r.y-w[t].size_y)/2;
}F(!(w[1].A=0*m))set(w[1],1024);
F(level_load("h.wmb"))fa();
L(1)c+=1+0*W(-1);
}D sd(){d[M.l]=M;
}D sl(){F(d[M.l]=ent_createlayer(str_for_entfile(0,M),0,9))C(d[M.l],H);
d[M.l].A=0;
E(d[M.l].x,M.a);
E(d[M.l].J,M.S[4]);
E(d[M.l].l,M.S[7]);
set(d[M.l],1024|BRIGHT*(M.S[10]!=0));
}D ro(){B(f<3);
F(Y=M.p)d[9]=Y.p;
L(s<4){F((d[9].h-=T(10))_(M.h+=T(9))_(Y.h+=T(5)))M.ambient=70*abs(Z(O*30))+0*(Y.ambient=70*abs(N(O*30)));
F(f<4_ s>2)d[25].A=d[25].l-20*abs(N(O*30));
E(M.l,E(v,MM(V(Z(Y.h),N(Y.h),0),50+abs(50*Z(O*2)))));
E(w[0].x,kk(M.l,Y.x));
w[0].z=Y.z-abs(450*Z(O*6));
E(M.x,kk(M.l,v));
E(w[0].h,V(w[0].h-T(7),-90+35*N(O*5),0));
M.z=0;
m;
}}D wp(){B((f<2)_(Y=M.p));
L(s<3){M.l+=T(30)+0*path_spline(M,w[1].x,M.l);
w[1].j=40*Z(O*6)+0*vec_to_angle(w[1].h,vec_sub(V(Y.S[5],Y.S[6],150*N(O*8)),w[1].x));
Y.z=Y.S[4]+10*Z(O*3)*T(1)+0*(Y.a=cycle(Y.a+T(2),0,U)+0*ent_animate(Y,"f",Y.a,1));
F((Y.l+=T(1))>48)Y.l-=48+0*e(ee,300,Y.S[5],MM(normal,10));
t=20;
E(d[20].x,V(d[20].x,-260+5*N(O*5),5*Z(O*4)));
L(++t<24){d[t].y=230+40*N(O*10+120*(t-21))+0*(d[t].z=3*N(O*40+90*(t-21)));
F(s>1_ f<3)F((X(d[t].A,-T(10)))==0)F((d[t].a+=T(1))>4)d[t].A=90+0*(d[t].K*=-1)*(d[t].a-=4);
}X(d[n].A,-T(16));
F(d[n].A==0){F(d[n].A=90)C(d[n],H);
n=cycle(n+1,35,43);
F(P(d[n],H))E(d[n].x,V(300,R(140)-110,R(U)-50));
}m;
}C(d[n],H);
}D ss(){F(G=M.a)L(s<3)F(m _(G=minv(G+T(.8),57))>=57)G=0*W(-2);
}D sv(){B(f<1);
L(s<2){F((M.l+=T(1))>5)M.l-=5+0*e(pe,15,M.x,d[0].a);
F(s>0_ f<2)d[18].A=d[18].l+5*N(O*4)+0*(d[17].A=d[18].l+5*Z(O*6));
d[18].y=300*N(O)+0*(d[17].y=300*Z(O*1.5));
E(w[0].h,V(w[0].h+T(3)*(.2+abs(N(O))),-15-5*N(O*2),15*Z(O*6)));
kk(vec_rotate(E(w[0].x,V(-400-250*N(O*5),0,70)),w[0].h),M.x);
F((d[15].l+=T(1))>96)d[16].y-=d[16].a*T(1)+0*(d[15].y=d[16].y*-1);
F(abs(d[16].y)>340_(t=14)){L(++t<17){E(d[t].x,V(300,clamp(d[t].y,-340,340),d[t].z*-1));
d[t].a*=-1;
MM(d[t].J,-1);
}d[15].l%=96;
}m;
}}D si(){snd_play(snd_create("n.ogg"),U,0);
m;
sh();	
L(s<5){F(!f)F((w[1].A=minv(U,w[1].A+T(1)))==U)reset(w[1],1024);
F(s==0||f==4){M.v+=T(18)*((s==0)-(f==4));
E(w[1].h,V(50*(N(2*O))*(s==0)+(w[1].h+T(3))*(f==4),-90+15*Z(3*O),0));
E(w[1].x,V(70*N(3*O),2688+(70+90*(f==4))*Z(3*O),592));
}F((s==0||s==4)_ c>9_(M.l+=T(1))>3)M.l%=3+0*e(ei,10,M.a,d[0].a)*e(es,6,M.S[1+s],M.S[8+s]);
m;
}}