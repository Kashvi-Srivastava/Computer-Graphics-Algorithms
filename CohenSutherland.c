#include <graphics.h>
#include <conio.h>
typedef unsigned int outcode;
enum{TOP=0x1,BOTTOM=0x2,RIGHT=0x4,LEFT=0x8};
outcode Outcode(double x, double y, double xmin, double xmax, double ymin, double ymax)
{
	outcode code = 0;
	if (y > ymax)
		code |= TOP;
	else if (y < ymin)
		code |= BOTTOM;
	if (x > xmax)
		code |= RIGHT;
	else if (x < xmin)
		code |= LEFT;
	return code;
}
int * CohenSutherland(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax)
{
	outcode outcode0, outcode1, outcodeOUT;
	int accept = 0, done = 0;
	outcode0 = Outcode(x0, y0, xmin, xmax, ymin, ymax);
	outcode1 = Outcode(x1, y1, xmin, xmax, ymin, ymax);
	do {
		if (!(outcode0 | outcode1))
		{
			accept = 1;
			done = 1;
		}
		else if (outcode0 & outcode1)
			done = 1;
		else
		{
			double x, y;
			outcodeOUT = outcode0 ? outcode0 : outcode1;
			if (outcodeOUT & TOP)
			{
				x = x0 + (x1 - x0)*(ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (outcodeOUT & BOTTOM)
			{
				x = x0 + (x1 - x0)*(ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (outcodeOUT & RIGHT)
			{
				y = y0 + (y1 - y0)*(xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else
			{
				y = y0 + (y1 - y0)*(xmin - x0) / (x1 - x0);
				x = xmin;
			}
			if (outcodeOUT == outcode0)
			{
				x0 = x;
				y0 = y;
				outcode0 = Outcode(x0, y0, xmin, xmax, ymin, ymax);
			}
			else
			{
				x1 = x;
				y1 = y;
				outcode1 = Outcode(x1, y1, xmin, xmax, ymin, ymax);
			}
		}
	} while (done == 0);
	if (accept)
	{
		int p[4] = { x0,y0,x1,y1 };
		return p;
	}
	else
		return NULL;
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	rectangle(200,200,400,400);
	int * p;
	p = CohenSutherland(150,350,350,100,200,400,200,400);
	if (p != NULL)
	{
		setlinestyle(1, 0, 1);
		line(*(p), *(p + 1), *(p + 2), *(p + 3));
	}
	p = CohenSutherland(150, 350, 450, 300, 200, 400, 200, 400);
	if (p != NULL)
	{
		setlinestyle(3, 0, 1);
		line(*(p), *(p + 1), *(p + 2), *(p + 3));
	}
	p = CohenSutherland(300, 420, 450, 410, 200, 400, 200, 400);
	if (p != NULL)
	{
		setlinestyle(2, 0, 1);
		line(*(p), *(p + 1), *(p + 2), *(p + 3));
	}
	getch();
	closegraph();
	return 0;
}
