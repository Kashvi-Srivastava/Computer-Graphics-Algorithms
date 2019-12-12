#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void EllipsePoints(int x, int y, int x_c, int y_c)
{
	putpixel(x + x_c, y + y_c, RED);
	putpixel(x + x_c, -y + y_c, RED);
	putpixel(-x + x_c, -y + y_c, RED);
	putpixel(-x + x_c, y + y_c, RED);
}
void Ellipse(int x_c, int y_c, int a, int b)
{
	float x = 0;
	float y = b;
	double d = b * b - a * a*b + 0.25*a*a;
	EllipsePoints(x, y, x_c, y_c);
	while ((a*a*(y - 0.5)) > (b*b*(x + 1)))
	{
		if (d < 0)
			d += b * b*(2 * x + 3);
		else
		{
			d += b * b*(2 * x + 3) + a * a*(-2 * y + 2);
			y--;
		}
		x++;
		EllipsePoints(x, y, x_c, y_c);
	}
	double d2 = 0.25*b*b + a * a - a * b*b;
	while (y >= 0)
	{
		if (d2 <= 0)
		{
			d2 += b * b*(2 * x + 2) + a * a*(-2 * y + 3);
			x++;
		}
		else
			d2 += a * a*(-2 * y + 3);
		y--;
		EllipsePoints(x, y, x_c, y_c);
	}
}
void CirclePoints(int x, int y, int x_c, int y_c)
{
	putpixel(x + x_c, y + y_c, RED);
	putpixel(y + x_c, x + y_c, RED);
	putpixel(y + x_c, x + y_c, RED);
	putpixel(y + x_c, -x + y_c, RED);
	putpixel(x + x_c, -y + y_c, RED);
	putpixel(-x + x_c, -y + y_c, RED);
	putpixel(-y + x_c, -x + y_c, RED);
	putpixel(-y + x_c, x + y_c, RED);
	putpixel(-x + x_c, y + y_c, RED);
}
void Circle(int x_c, int y_c, int R)
{
	int x = 0;
	int y = R;
	int d = 1 - R;
	int dE = 3;
	int dSE = -2 * R + 5;
	while (y > x)
	{
		CirclePoints(x, y, x_c, y_c);
		if (d < 0)
		{
			d += dE;
			dE += 2;
			dSE += 2;
		}
		else
		{
			d += dSE;
			dE += 2;
			dSE += 4;
			y--;
		}
		x++;
	}
}
void BresenHam(int x1, int y1, int x2, int y2)
{
	float m = (y2 - y1) / (float)(x2 - x1);
	if (m >= 0 && m <= 1)
	{
		int d1 = 2 * (y2 - y1);
		int d = d1 - (x2 - x1);
		for (int x = x1, y = y1; x <= x2; x++)
		{
			putpixel(x, y, RED);
			if (d > 0)
			{
				y++;
				d -= 2 * (x2 - x1);
			}
			d += d1;
		}
	}
	else if (m > 1)
	{
		int d1 = -2 * (x2 - x1);
		int d = d1 + (y2 - y1);
		for (int y = y1, x = x1; y <= y2; y++)
		{
			putpixel(x, y, RED);
			if (d < 0)
			{
				x++;
				d += 2 * (y2 - y1);
			}
			d += d1;
		}
	}
	else if (m < -1)
	{
		int d1 = 2 * (x2 - x1);
		int d = d1 - (y2 - y1);
		for (int y = y1, x = x1; y <= y2; y++)
		{
			putpixel(x, y, RED);
			if (d > 0)
			{
				x--;
				d -= 2 * (y2 - y1);
			}
			d -= d1;
		}
	}
	else
	{
		int d1 = -2 * (y2 - y1);
		int d = d1 - (x2 - x1);
		for (int x = x1, y = y1; x >= x2; x--)
		{
			putpixel(x, y, RED);
			if (d < 0)
			{
				y++;
				d -= 2 * (x2 - x1);
			}
			d += d1;
		}
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	Ellipse(250, 200, 50, 75);
	BresenHam(270, 269, 285, 350);
	BresenHam(230, 269, 215, 350);
	BresenHam(325, 330, 285, 350);
	BresenHam(175, 330, 215, 350);
	BresenHam(352, 140, 292, 160);
	BresenHam(148, 140, 208, 160);
	Circle(250, 80, 45);
	Ellipse(280, 25, 8, 20);
	Ellipse(220, 25, 8, 20);
	Circle(230, 60, 12);
	Circle(270, 60, 12);
	Circle(250, 80, 5);
	Ellipse(250, 100, 25, 12);
	getch();
	closegraph();
	return 0;} 
