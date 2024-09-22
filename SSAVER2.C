#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void layout(int x, int y, int x2, int y2){
	line(x,y,x,y2);
	line(x,y,x2,y);
	line(x,y2,x2,y2);
	line(x2,y,x2,y2);
}
void main(){
	int gd=DETECT, gm, x, y, smx, smy, xt, yt;
	int i=0, sx=50, sy=100, ex=550, ey=400, R=10, H=0, False=0, True=1;
	char ch;
	xt = True;
	yt = True;
	x = 90+R+1;
	y = 100+R+1;
	smx = getmaxx();
	smy = getmaxy();
//      ex = smx;
//	ey=smy;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	while(True){
		delay(10);
		cleardevice();
		layout(sx,sy,ex,ey);
//		setfillstyle(SOLID_FILL, RED);
		circle(x,y,R);
		if(y==(ey-R)){
			yt=False;
			H++;
		}else if (y==(sy+R)){
			yt=True;
		}
		if (x==(ex-R)){
			xt=False;
			H++;
		}else if (x==(sx+R)){
			xt=True;
			H++;
		}
		if ((x==(sx+R) || x==(ex-R)) && (y==(sy+R) || y==(ey-R))){
			printf("%d",H);
			break;
		}
		if (yt==False){
			y--;
		}else{
			y++;
		}
		if (xt==False){
			x--;
		}else{
			x++;
		}
		if (x==smx || y==smy)
			break;

	}
	getch();
	closegraph();
}