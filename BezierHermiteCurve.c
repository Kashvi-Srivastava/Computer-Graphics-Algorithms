#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

struct point {
	int x, y;
};

void draw_bezier(int x[4], int y[4]) {
	double u;
	for (u = 0.0; u < 1.0; u += 0.0005) {
		double xu = pow(1 - u, 3) * x[0] + 3 * u * pow(1 - u, 2) * x[1] + 3 * pow(u, 2) * (1 - u) * x[2] + pow(u, 3) * x[3];
		double yu = pow(1 - u, 3) * y[0] + 3 * u * pow(1 - u, 2) * y[1] + 3 * pow(u, 2) * (1 - u) * y[2] + pow(u, 3) * y[3];
		putpixel(xu, yu, WHITE);
	}
	for (int i = 0; i < 4; i++) 
		putpixel(x[i], y[i], YELLOW);
	getch();
	closegraph();
	return;
}

void hermite(point p1, point p2, point t1, point t2) {
	float x, y, u;
	for (u = 0.0; u <= 1.0; u += 0.001) {
		x = (2 * u*u*u - 3 * u*u + 1)*p1.x + (-2 * u*u*u + 3 * u*u)*p2.x + (u*u*u - 2 * u*u + u)*t1.x + (u*u*u - u * u)*t2.x;
		y = (2 * u*u*u - 3 * u*u + 1)*p1.y + (-2 * u*u*u + 3 * u*u)*p2.y + (u*u*u - 2 * u*u + u)*t2.y + (u*u*u - u * u)*t2.y;
		putpixel(x, y, YELLOW);
	}
}

int main() {
	int gd = DETECT, gm;
	int x[4], y[4];
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cout << "Enter the x- and y-coordinates of the four control points-\n";
	for (int i = 0; i < 4; i++)
		cin >> x[i] >> y[i];
	for (int j = 0; j < 3; j++)
		line(x[j], y[j], x[j + 1], y[j + 1]);
	draw_bezier(x, y);
	getch();
	cleardevice();
	double r1, r4;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	point p1, p2, t1, t2;
	cout << "Enter 2 hermite points: \n";
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cout << "Enter the tangents at p1, p2: \n";
	cin >> t1.x >> t1.y >> t2.x >> t2.y;
	hermite(p1, p2, t1, t2);
	putpixel(p1.x, p1.y, GREEN);
	putpixel(p2.x, p2.y, GREEN);
	putpixel(t1.x, t1.y, GREEN);
	putpixel(t2.x, t2.y, GREEN);
	line(p1.x, p1.y, t1.x, t1.y);
	line(p2.x, p2.y, t2.x, t2.y);
	outtextxy(p1.x - 10, p1.y + 10, "P1");
	outtextxy(p2.x - 10, p2.y + 10, "P2");
	outtextxy(t1.x + 10, t1.y + 10, "T1");
	outtextxy(t2.x + 10, t2.y + 10, "T2");
	getch();
	closegraph();
	return 0;
}
