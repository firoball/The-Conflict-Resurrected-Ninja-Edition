#include <acknex.h>
#include <mtlfx.c>
#define Q #define
Q P(o,f) o.flags2|=(f)
Q C(o,f) o.flags2&=~(f)
Q T time_step
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
Q X(v,c) v=maxv(0,v+c)
Q E vec_set
Q I(x) D x(PARTICLE* n){
Q B(x) L(x)W(1)
Q M my
Q Y you
Q J scale_x
Q K scale_y
Q G M.frame
Q UU vec_normalize
Q p Y=M.parent
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
Q q &&(set(n
Q dd fog_start
Q aa n.event
Q _ &&
Q R2 R(2)-1
Q S3 &&(n.size=3)
Q U 100
Q d2 d[12]
Q d3 d[13]
Q pb n.blue
Q dM d[M.l]
Q wt w[t]
Q Fg(x) F(g.l==x)g
Q dt d[t]
Q w0 w[0]
Q w1 w[1]
Q uv T*18*((s<1)-(f>3))
var i,b=42,o=42,j=66,t,s,f,c,n=42,v[3];
ENTITY* d[79];
VIEW* w[2];
I(mw)n.vel_z-=T*.1;
}I(pa)X(n.A,-T*2);
}I(ee)F((aa=pa)q,2100480)))n.A=25+R(25);
kk(n.vel_x,UU(V(R2,R2,R(20)),R(50)));
E(pb,d[2].a);
}I(pe)F((aa=mw)q,2304))_(n.z+=30)S3)n.A=45;
E(pb,d[4].a);
E(n.vel_x,V(R2,R2,3.5+R(1.5)));
}I(es)F(!(aa=0)q,2099456))S3 _(n.vel_z*=8+R(4)))n.A=20+R(9);
E(pb,d[1].a);
kk(n.x,V(R(220)-110,R(1400)-700,0));
}I(ei)F((aa=pa)q,2097408))S3)n.A=25+R(25);
kk(n.vel_x,UU(V(R2,R2,R2),R(150)));
E(pb,d[1].a);
}D fa(){m;
F((w0.A=U)_(w0.fog_end=1100)_((fog_color=d[3].S[5])>-1)_(t=9))L(d[++t]!=0)F(dt.A=dt.l)P(dt,H);
L(f<4){B(c<d[3].S[f+1]);
//L(f<4){B(c<10+20*f);
t=9+5*f++;
L(d[++t]!=0)P(dt,H);
F((set(w[f%2],1024))_(set(w[1-f%2],H)))w[1-f%2].dd=1000;
L(w[f%2].A>0){X(w[f%2].A,-T*2)+0*(fog_color=d[3].S[f+4+(w[f%2].A<=50)])*(w[f%2].dd=w[1-f%2].dd=1000-abs(w[f%2].A-50)*16)*(t=9+5*f);
L(d[++t]!=0)dt.A=minv(dt.l,dt.A+T*2);
t=4+5*f;
L(d[++t]!=0)X(dt.A,-T*2);
m;
}t=4+5*f;
L(d[++t]!=0)C(dt,H);
F(reset(w[f%2],17408))w[f%2].A=U+0*LS(w[f%2],-1)*(++s+0*LS(w[1-f%2],1));
}B(c<252);
F(set(w1,1024))w1.A=U;
L(w1.A>0)w1.A-=T*2+0*m;
F(reset(w1,H))W(-2.5);
sys_exit("");
}D sm(i){L(o<b+i){P(d[++o],H);
L(g.A<g.a)g.A=minv(g.A+T*2,g.a)+0*m;
W(g.S[2]);
L(g.A>0){X(g.A,-T)+0*m;
Fg(4).J+=T*.1+0*(g.x+=T*15);
Fg(1).x-=T*10;
Fg(2).x+=T*10;
Fg(3).J-=T*.01;
}F(!C(g,H))W(-1);
}b=o;
}D sh(){F((d2.A=d3.A=80)_(P(d2,H)))W(-2);
L(d2.A>0)X(d2.A,-T*3)+0*(d2.J+=T/20)*(d2.K-=T*.02)*m;
F(!C(d2,H))W(-1);
P(d3,H);
L(d3.S[11]<32){W(-.125);
d3.S[11]+=1+0*(d3.J=.25+R(.5))*(d3.K=.25+R(.5));
}d3.J=d3.K=.5;
W(-.5);
L(d3.A>0)X(d3.A,-T*6)+0*m;
F(!C(d3,H))W(-2);
sm(8);
B(c<125);
sm(6);
B(c<153);
F(M=d[j])Y=d[++j];
F((P(M,H))_(M.j=-45)_(M.A=Y.A=U))P(Y,H);
L(j<80){F(M.l==0){d[66].a=M.j;
L(M.A>0)Y.A=X(M.A,-T*4)+0*(Y.j=M.j+=T/2)*m;
F(!C(M,H))C(Y,H);
W(-1);
F(M=d[++j])Y=d[++j];
F((Y.A=M.A=U)_(M.j=d[66].a+60)_(P(M,H)))P(Y,H);
}E(v,vec_rotate(V(0,0,(X(M.l,-T*25))),M.h));
E(M.x,V(M.x,-v[1],v[2]));
Y.j=M.j;
E(Y.x,V(Y.x,-M.y,-M.z));
m;
}sm(4);	
B(s<4);
sm(5);
}D main(){F((t=-1)_(video_mode=24*0.5*video_screen=1)_(w0=view_create(-1))_(w1=camera))m;
L(++t<2){wt.size_x=minv(r.x,r.y*2);
wt.pos_x=(r.x-wt.size_x)/2;
wt.size_y=wt.size_x/2;
wt.pos_y=(r.y-wt.size_y)/2;
}F(!(w1.A=0*m))set(w1,1024);
F(level_load("h.wmb"))fa();
L(1)c+=1+0*W(-1);
}D sd(){dM=M;
}D sl(){F(dM=ent_createlayer(str_for_entfile(0,M),0,9))C(dM,H);
dM.A=0;
E(dM.x,M.a);
E(dM.J,M.S[4]);
E(dM.l,M.S[7]);
set(dM,1024|BRIGHT*(M.S[10]!=0));
}D ro(){B(f<3);
p;
L(s<4){F((M.h+=T*9)_(Y.h+=T*5))M.ambient=70*abs(Z(O*30))+0*(Y.ambient=70*abs(N(O*30)));
F(f<4_ s>2)d[25].A=d[25].l-20*abs(N(O*30));
E(M.l,E(v,MM(V(Z(Y.h),N(Y.h),0),50+abs(50*Z(O*2)))));
E(w0.x,kk(M.l,Y.x));
w0.z=Y.z-abs(450*Z(O*6));
E(M.x,kk(M.l,v));
E(w0.h,V(w0.h-T*7,-90+35*N(O*5),0));
M.z=0*m;
}}D wp(){B((f<2)_(p));
L(s<3){M.l+=T*30+0*path_spline(M,w1.x,M.l);
w1.j=40*Z(O*6)+0*vec_to_angle(w1.h,vec_sub(V(Y.S[5],Y.S[6],150*N(O*8)),w1.x));
Y.z=Y.S[4]+10*Z(O*3)*T+0*(Y.S[9]=cycle(Y.S[9]+T*2,0,U));
ent_animate(Y,"f",Y.S[9],1);
F((Y.S[8]+=T)>48)Y.S[8]-=48+0*e(ee,300,Y.S[5],MM(normal,10));
t=20;
E(d[20].x,V(d[20].x,-260+5*N(O*5),5*Z(O*4)));
L(++t<24){dt.y=230+40*N(O*10+120*(t-21))+0*(dt.z=3*N(O*40+90*(t-21)));
F(s>1_ f<3)F((X(dt.A,-T*10))==0)F((dt.a+=T)>4)dt.A=90+0*(dt.K*=-1)*(dt.a-=4);
}X(d[n].A,-T*16);
F(d[n].A==0){F(d[n].A=90)C(d[n],H);
n=cycle(n+1,35,43);
F(P(d[n],H))E(d[n].x,V(300,R(140)-110,R(U)-50));
}m;
}C(d[n],H);
}D ss(){F(G=M.a)L(s<3)F(m _(G=minv(G+T*.8,57))>=57)G=0*W(-2);
}D sv(){B(f<1);
L(s<2){F((M.l+=T)>5)M.l-=5+0*e(pe,15,M.x,d[0].a);
F(s>0_ f<2)d[18].A=d[18].l+5*N(O*4)+0*(d[17].A=d[18].l+5*Z(O*6));
d[18].y=300*N(O)+0*(d[17].y=300*Z(O*1.5));
E(w0.h,V(w0.h+T*3*(.2+abs(N(O))),-15-5*N(O*2),15*Z(O*6)));
kk(vec_rotate(E(w0.x,V(-400-250*N(O*5),0,70)),w0.h),M.x);
F((d[15].l+=T)>96)d[16].y-=d[16].a*T+0*(d[15].y=d[16].y*-1);
F(abs(d[16].y)>340_(t=14)){L(++t<17){E(dt.x,V(300,clamp(dt.y,-340,340),dt.z*-1));
dt.a*=-1;
MM(dt.J,-1);
}d[15].l%=96;
}m;
}}D si(){snd_play(snd_create("n.ogg"),U,0);
m;
sh();	
L(s<5){F(!f)F((w1.A=minv(U,w1.A+T))==U)reset(w1,1024);
F(s<1||f>3){M.v+=uv*2;
E(w1.h,V(50*(N(2*O))*(s==0)+(w1.h+T*3)*(f==4),-90+15*Z(3*O),0));
E(w1.x,V(70*N(3*O),2688+(70+90*(f==4))*Z(3*O),592));
}F((s<1||s>3)_ c>9_(M.l+=T)>3)M.l%=3+0*e(ei,10,M.a,d[0].a)*e(es,6,M.S[1+s],M.S[8+s]);
m;
}}D re(){L(1+m)M.h+=T*M.l;
}D mi(){L(1+m){M.x=M.l+(c>9)*16*N(O*(1+(f>3))*9+M.a)+0*(M.z=cycle(M.z+uv,-272,624));
}}
//comment your code