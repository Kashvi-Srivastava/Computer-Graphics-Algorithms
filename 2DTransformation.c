#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

#define COS(x) cos(x*3.14/180)
#define SIN(x) sin(x*3.14/180) 

void rotation (int x[], int y[], int x_pivot, int y_pivot, int degrees, int cx, int cy, int r)
{
	//Rotate circle
	int cxs = cx - x_pivot;
	int cys = cy - y_pivot;
	cx = x_pivot + (cxs*COS(degrees) - cys * SIN(degrees));
	cy = y_pivot + (cxs*SIN(degrees) + cys * COS(degrees));
	circle(cx, cy, r);
	//Rotate lines
	for (int i = 0; i < 18; i++)
	{
		int xs = x[i] - x_pivot;
		int ys = y[i] - y_pivot;
		x[i] = x_pivot + (xs*COS(degrees) - ys * SIN(degrees));
		y[i] = y_pivot + (xs*SIN(degrees) + ys * COS(degrees));
	}
	for (int j = 0; j < 18; j+=2)
	{
		line(x[j], y[j], x[j + 1], y[j + 1]);
	}
}

void reflection(int x[], int y[], int x_pivot, int y_pivot, int cx, int cy, int r)
{
	//Reflect circle about x-axis
	int cxs = cx - x_pivot;
	int cys = cy - y_pivot;
	cx = x_pivot + cxs;
	cy = y_pivot - cys;
	circle(cx, cy, r);
	//Reflect lines about x-axis
	for (int i = 0; i < 18; i++)
	{
		int xs = x[i] - x_pivot;
		int ys = y[i] - y_pivot;
		x[i] = x_pivot + xs;
		y[i] = y_pivot - ys;
	}
	for (int j = 0; j < 18; j += 2)
	{
		line(x[j], y[j], x[j + 1], y[j + 1]);
	}
}

void reflection2(int x[], int y[], int cx, int cy, int r, float m, float c)
{
	//Reflect circle about arbitrary line
	int cxs = ((1 - m * m)*cx + 2 * m*cy - 2 * m*c) / (1 + m * m);
	int cys = (2 * m*cx + (m*m - 1)*cy + 2 * c) / (1 + m * m);
	circle(cxs, cys, r);
	//Reflect lines about arbitrary line
	int x_shifted[18];
	int y_shifted[18];
	for (int i = 0; i < 18; i++)
	{
		x_shifted[i] = ((1 - m * m)*x[i] + 2 * m*y[i] - 2 * m*c) / (1 + m * m);
		y_shifted[i] = (2 * m*x[i] + (m*m - 1)*y[i] + 2 * c) / (1 + m * m);
	}
	for (int j = 0; j < 18; j += 2)
	{
		line(x_shifted[j], y_shifted[j], x_shifted[j + 1], y_shifted[j + 1]);
	}
}

void translation(int x[], int y[], int tx, int ty, int cx, int cy, int r)
{
	//Translate Lines
	for (int i = 0; i < 18; i++)
	{
		x[i] = x[i] + tx;
	}
	for (int j = 0; j < 18; j++)
	{
		y[j] = y[j] + ty;
	}
	for (int m = 0; m < 18; m += 2)
	{
		line(x[m], y[m], x[m + 1], y[m + 1]);
	}
	//Translate circle
	cx += tx;
	cy += ty;
	circle(cx, cy, r);
}

void shearing(int x[], int y[], int cx, int cy, int r, int sx)
{
	
	//Circle shearing
	int r1 = r * r;
	int xc, yc;
	cx += cy * sx;
	for (xc = 1; xc <= r; xc++)
	{
		yc = (int)(sqrt(r1 - xc * xc));
		xc += yc * sx;
		putpixel(cx + xc, cy + yc, 111);
		putpixel(cx + xc, cy - yc, 111);
		putpixel(cx - xc, cy + yc, 111);
		putpixel(cx - xc, cy - yc, 111);
	}
	//Line shearing
	for (int i = 0; i < 18; i++)
	{
		x[i] += y[i] * sx;
	}
	for (int p = 0; p < 18; p += 2)
	{
		line(x[p], y[p], x[p + 1], y[p + 1]);
	}
}

void scale(int x[], int y[], float sx, float sy, int x_pivot, int y_pivot, int cx, int cy, int r)
{
	//Scale lines
	for (int i = 0; i < 18; i++)
	{
		x[i] = x[i] * sx + x_pivot * (1 - sx);
		y[i] = y[i] * sy + y_pivot * (1 - sy);
	}
	for (int m = 0; m < 18; m += 2)
	{
		line(x[m], y[m], x[m + 1], y[m + 1]);
	}
	//Scale circle
	cx = cx * sx + x_pivot * (1 - sx);
	cy = cy * sy + y_pivot * (1 - sy);
	r = r * sx;
	circle(cx, cy, r);
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TURBOC3//BGI");

	int x[] = {320,400,320,360,360,400,400,400,320,320,340,340,340,380,380,380,320,400 };
	int y[] = { 240,240,90,30,30,90,90,240,240,90,240,180,180,180,180,240,90,90 };
	//rectangle(320, 240, 400, 90);
	//rectangle(340, 240, 380, 180);
	//line(360, 30, 320, 90);
	//line(360, 30, 400, 90);
	//circle(360, 65, 15);
	//rotation(x, y, 320, 240, 210, 360, 65, 15);
	//reflection(x, y, 320, 240, 360, 65, 15);
	//reflection2(x, y, 360, 65, 15, 1, 20);
	//translation(x, y, -220, 140, 360, 65, 15);
	//shearing(x, y, 360, 65, 15, 1);
	scale(x, y, 0.5, 0.5, 320, 240, 360, 65, 15);
	getch();
	closegraph();
	return 0;
}
