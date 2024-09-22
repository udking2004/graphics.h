// rectangle shape screen saver
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
	int gd=DETECT, gm, x, y, x2, y2, smx, smy, xt, yt, R;
	int i=0, sx=50, sy=100, ex=550, ey=400, H=0, False=0, True=1;
	char ch;
	xt = True;
	yt = True;
	x = 90;
	y = 100;
	R=10;
	x2 = x+R;
	y2 = y+R;
	smx = getmaxx();
	smy = getmaxy();
//      ex = smx;
//	ey=smy;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	while(True){
		/*
		some basic setup for the screen layout, rectangle
		,delay and cleardevice before print everthing on
		the screen
		*/
		delay(10);
		cleardevice();
		layout(sx,sy,ex,ey);
//		setfillstyle(SOLID_FILL, RED);
		rectangle(x,y,x2,y2);
		/*
		following conditions are for whether the rectangle
		is hiting any side of the fixed layout or not if yes
		then xt and yt tag become False and H variable will
		be incremented
		*/
		if(y>=(ey-R)){
			yt=False;
			H++;
		}else if (y<=sy){
			yt=True;
		}
		if (x>=(ex-R)){
			xt=False;
			H++;
		}else if (x<=sx){
			xt=True;
			H++;
		}
		/*
		the following condition is checking whether the both
		x,y and x2,y2 hit any corner coordinate, if they do
		program breaks
		*/
		if ((x==sx || x==(ex-R)) && (y==sy || y==(ey-R))){
			printf("%d",H);
			break;
		}
		/*
		the following conditions are using xt and yt tag
		to decide whether x,x2 and y,y2 should increment
		or decrement
		*/
		if (yt==False){
			y--;
			y2--;
		}else{
			y++;
			y2++;
		}
		if (xt==False){
			x--;
			x2--;
		}else{
			x++;
			x2++;
		}
		/*
		the following condition is used for the special
		condition if somehow coordinates goes out the
		fixed layout and the main screen then program
		breaks itself
		*/
		if (x==smx || y==smy)
			break;

	}
	getch();
	closegraph();
}