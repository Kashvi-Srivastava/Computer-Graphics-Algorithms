#include <stdio.h>
#include <graphics.h>
#include <conio.h>

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
    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");    
    BresenHam (30,200,80,240);
    BresenHam (130,200,80,240);
    BresenHam (80,30,130,200);
    BresenHam (80,30,30,200);
    getch();
    closegraph(); 
    return 0;
}
