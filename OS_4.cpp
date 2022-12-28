#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

Display *display;
Window window;
GC gc;

void DrawTableLeg(int startX, int startY, int endY) 
{
	int index = 0;
	for (int y = startY; y >= endY; y--) 
    {
		for (int x = startX - index; x <= startX + index; x++) 
        {
			if (x == startX) 
            {
			    XSetForeground(display, gc, 0x000000);
			    XDrawPoint(display, window, gc, x, y);
			}
			else 
            {
			    XSetForeground(display, gc, 0x685a2c);
			    XDrawPoint(display, window, gc, x, y);
			}
		}
		if (index < 25) 
            index++;
	}
}

void DrawAshtrays(int x, int y) 
{
    XSetForeground(display, gc, 0x000000);
    XDrawRectangle(display, window, gc, x, y, 150, 20);
    XSetForeground(display, gc, 0xC0C0C0);
    XFillRectangle(display, window, gc, x, y, 150, 20);
	
    XSetForeground(display, gc, 0x000000);
    XDrawArc(display, window, gc, x, y, 150, 40, 360*64, 360*64); 
    XSetForeground(display, gc, 0xC0C0C0);
    XFillArc(display, window, gc, x, y, 150, 40, 360*64, 360*64);
    
	XSetForeground(display, gc, 0x000000);
    XDrawArc(display, window, gc, x, y - 20, 150, 40, 360*64, 360*64); 
    XSetForeground(display, gc, 0xC0C0C0);
    XFillArc(display, window, gc, x, y - 20, 150, 40, 360*64, 360*64);
    
    XSetForeground(display, gc, 0x000000);
    XDrawArc(display, window, gc, x + 10, y, 130, 20, 360*64, 360*64); 
    XSetForeground(display, gc, 0x808080);
    XFillArc(display, window, gc, x + 10, y, 130, 20, 360*64, 360*64);
	
    XSetForeground(display, gc, 0x000000);
    XDrawArc(display, window, gc, x + 65, y+15, 15, 15, 180*64, 0); 
    XSetForeground(display, gc, 0x808080);
    XFillArc(display, window, gc, x + 65, y+15, 15, 15, 360*64, 360*64);

    XSetForeground(display, gc, 0x000000);
    XDrawArc(display, window, gc, x + 65, y-25, 15, 15, 180*64, 0); 
    XSetForeground(display, gc, 0x685a2c);
    XFillArc(display, window, gc, x + 65, y-25, 15, 15, 360*64, 360*64);
}

void DrawCigarette(int x, int y) 
{
	XSetForeground(display, gc, 0x000000);
	XDrawArc(display, window, gc, x, y, 20, 20, 360*64, 360*64);
    XSetForeground(display, gc, 0xFFFFFF);
    XFillArc(display, window, gc, x, y, 20, 20, 360*64, 360*64);
	
    XPoint pt[4]; 
    pt[0].x = (x + x + 20) / 2; pt[0].y = y;
	pt[1].x = (x + x + 20) / 2; pt[1].y = y + 20;
	pt[2].x = (x + x + 100) / 2; pt[2].y = y + 60;
	pt[3].x = (x + x + 100) / 2; pt[3].y = y + 40;
    XSetForeground(display, gc, 0x000000);
 	//XDrawPolygon(display, window, gc, pt, 4, Complex, CoordModeOrigin);
    XSetForeground(display, gc, 0xFFFFFF);
    XFillPolygon(display, window, gc, pt, 4, Complex, CoordModeOrigin);

    XSetForeground(display, gc, 0x000000);
	XDrawArc(display, window, gc, x+40, y+40, 20, 20, 360*64, 360*64);
    XSetForeground(display, gc, 0xFFFCF47);
    XFillArc(display, window, gc, x+40, y+40, 20, 20, 360*64, 360*64);
	
    pt[0].x = (x + x + 100) / 2; pt[0].y = y + 40;
	pt[1].x = (x + x + 100) / 2; pt[1].y = y + 60;
	pt[2].x = (x + x + 140) / 2; pt[2].y = y + 80;
	pt[3].x = (x + x + 140) / 2; pt[3].y = y + 60;
    XSetForeground(display, gc, 0x000000);
 	//XDrawPolygon(display, window, gc, pt, 4, Complex, CoordModeOrigin);
    XSetForeground(display, gc, 0xFFFCF47);
    XFillPolygon(display, window, gc, pt, 4, Complex, CoordModeOrigin);

    XSetForeground(display, gc, 0x000000);
	XDrawArc(display, window, gc, x+60, y+60, 20, 20, 360*64, 360*64);
    XSetForeground(display, gc, 0x808080);
    XFillArc(display, window, gc, x+60, y+60, 20, 20, 360*64, 360*64);
}

void MyDraw() 
{

    DrawTableLeg(170, 500, 200);
    DrawTableLeg(670, 500, 200);
    DrawTableLeg(370, 700, 400);
    DrawTableLeg(870, 700, 400);

    XSetForeground(display, gc, 0x685a2c);
    int index = 0;
    for (int y = 191; y < 420; y++) 
    {
        for (int x = 131 + index; x < 700 + index; x++) 
            XDrawPoint(display, window, gc, x, y);
	    index++;
	}
    
    XSetForeground(display, gc, 0x000000);
    XDrawLine(display, window, gc, 130, 191, 359, 420);
    XDrawLine(display, window, gc, 359, 420, 928, 420);
    XDrawLine(display, window, gc, 928, 420, 698, 191);
    XDrawLine(display, window, gc, 698, 191, 130, 191);
    
    XSetForeground(display, gc, 0x685a2c);
    for (int x = 0, y = 0; x < 10 && y < 10; x++, y++) 
        XDrawLine(display, window, gc, 130, 192 + y, 359, 421 + y);

    XSetForeground(display, gc, 0x000000);
    XDrawLine(display, window, gc, 130, 202, 359, 431);
    
    XSetForeground(display, gc, 0x685a2c);
    for (int x = 0, y = 0; x < 10 && y < 10; x++, y++)
	    XDrawLine(display, window, gc, 359, 421 + y, 928, 421 + y);
    
    XSetForeground(display, gc, 0x000000);
    XDrawLine(display, window, gc, 359, 431, 928, 431);
    XDrawLine(display, window, gc, 359, 431, 359, 420);
    XDrawLine(display, window, gc, 928, 431, 928, 420);
    XDrawLine(display, window, gc, 130, 191, 130, 202);
    
    DrawAshtrays(450, 275);
    DrawCigarette(500, 275);
}

int main(void) 
{
    XEvent e; 
    int s;

    if ((display = XOpenDisplay(getenv("DISPLAY"))) == NULL) 
        exit(1);

    s = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 1000, 800, 1, 0xFFFFFF, 0xFFFFFF);
    XSelectInput(display, window, ExposureMask|KeyPressMask|ButtonPressMask);
    XMapWindow(display, window);
    gc = XCreateGC(display, DefaultRootWindow(display), 0, 0);

    while (1) 
    {
        XNextEvent(display, &e);
        if (e.type == Expose) 
            MyDraw();
        if ((e.type == KeyPress)&&(XLookupKeysym(&e.xkey,0)==XK_Escape)) 
            break;
        if ((e.type == ButtonPress)&&(e.xbutton.x<10)&&(e.xbutton.y<10)) 
            break;
    }

    XCloseDisplay(display);
}
