#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int maxx, maxy, midx, midy;
void axis()
{
	getch();
	cleardevice();
	line(midx, 0, midx, maxy);
	line(0, midy, maxx, midy);
}
void rotation(int midx, int midy)
{
	int x, y, z, o, x1, x2, y1, y2;
	printf("Enter rotating angle");
	scanf("%d", &o);
	x1 = 50 * cos(o*3.14 / 180) - 100 * sin(o*3.14 / 180);
	y1 = 50 * sin(o*3.14 / 180) + 100 * cos(o*3.14 / 180);
	x2 = 60 * cos(o*3.14 / 180) - 90 * sin(o*3.14 / 180);
	y2 = 60 * sin(o*3.14 / 180) + 90 * cos(o*3.14 / 180);
	printf("After rotation  about x axis");
	bar3d(midx + 50, midy - x1, midx + 60, midy - x2, 5, 1);
	axis();
	getch();
}
void multiply_matrices(const float matrix_1[4], const float matrix_2[4][4], float matrix_3[4])
{
	for (int count_1 = 0; count_1 < 4; count_1++)
	{
		for (int count_2 = 0; count_2 < 4; count_2++)
			matrix_3[count_1] +=
			(matrix_1[count_2] * matrix_2[count_2][count_1]);
	}
}
void shear(int edgepoints[8][3], const float a, const float b)
{
	for (int i = 0; i < 8; i++)
	{
		float matrix_a[4] = { edgepoints[i][0],edgepoints[i][1],edgepoints[i][2],1 };
		float matrix_b[4][4] = { {1,a,b,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
		float matrix_c[4] = { 0 };
		multiply_matrices(matrix_a, matrix_b, matrix_c);

		epdegepoints[i][0] = (int)(matrix_c[0] + 0.5);
		edgepoints[i][1] = (int)(matrix_c[1] + 0.5);
		edgepoints[i][2] = (int)(matrix_c[2] + 0.5);
	}

}
void drawlines(int edgepoints[8][3])
{
	line(edgepoints[0][0], edgepoints[0][1],
		edgepoints[1][0], edgepoints[1][1]);
	line(edgepoints[1][0], edgepoints[1][1],
		edgepoints[2][0], edgepoints[2][1]);
	line(edgepoints[2][0], edgepoints[2][1],
		edgepoints[3][0], edgepoints[3][1]);
	line(edgepoints[3][0], edgepoints[3][1],
		edgepoints[0][0], edgepoints[0][1]);

	line(edgepoints[4][0], edgepoints[4][1],
		edgepoints[5][0], edgepoints[5][1]);
	line(edgepoints[5][0], edgepoints[5][1],
		edgepoints[6][0], edgepoints[6][1]);
	line(edgepoints[6][0], edgepoints[6][1],
		edgepoints[7][0], edgepoints[7][1]);
	line(edgepoints[7][0], edgepoints[7][1],
		edgepoints[4][0], edgepoints[4][1]);


	lone(edgepoints[0][0], edgepoints[0][1],
		edgepoints[4][0], edgepoints[4][1]);
	line(edgepoints[1][0], edgepoints[1][1],
		edgepoints[5][0], edgepoints[5][1]);
	line(edgepoints[2][0], edgepoints[2][1],
		edgepoints[6][0], edgepoints[6][1]);
	line(edgepoints[3][0], edgepoints[3][1],
		edgepoints[7][0], edgepoints[7][1]);


}
void shearing(int midx, int midy)
{
	axis();
	int cube[8][3] = { {midx + 50,midy - 100,15},{midx + 50,midy - 70,15},{midx + 80,midy - 70,15},{midx + 80,midy - 100,15},{midx + 50,midy - 100,5},{midx + 50,midy - 70,5},{midx + 80,midy - 70,5},{midx + 80,midy - 100,5} };
	int edgepoints[8][3];
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		edgepoints[i][0] = cube[i][0];
		edgepoints[i][1] = cube[i][1];
		edgepoints[i][2] = cube[i][2];
	}
	printf("The cube is");
	drawlines(edgepoints);
	axis();
	printf("Applying shearing");
	shear(cube, 0.4, 0.3);

	for (i = 0; i < 8; i++)
	{
		edgepoints[i][0] = cube[i][0];
		edgepoints[i][1] = cube[i][1];
		edgepoints[i][2] = cube[i][2];
	}
	axis();
	printf("The sheared cube is");
	drawlines(edgepoints);


}
void scaling(int midx, int midy)
{
	int x, y, z;
	printf("Enter scaling factors");
	scanf("%d%d%d", &x, &y, &z);
	axis();
	printf("After scaling");
	bar3d(midx + (x * 50), midy - (y * 100), midx + (x * 60), midy - (y * 90), 5 * z, 1);

}
void translation(int midx, int midy)
{
	int x, y;
	printf("Enter translation factor with space in x and y");
	scanf("%d%d", &x, &y);

	printf("After translation:");
	bar3d(midx + x + 50, midy - (y + 100), midx + x + 60, midy - (y + 90), 10, 1);
}

void reflection(int midx, int midy)
{
	axis();
	printf("Reflection about xy plane yields");
	bar3d(midx + 50, midy - 100, midx + 60, midy - 90, 10, 1);
	axis();
	printf("Reflection about yz plane yields");
	bar3d(midx - 60, midy - 100, midx - 50, midy - 90, 10, 1);
	axis();
	printf("Reflection about zx plane yields");
	bar3d(midx + 50, midy + 90, midx + 60, midy + 100, 10, 1);
	getch();
}
void main()   // main function
{
	int x, y, z, o, x1, x2, y1, y2;
	int gd = DETECT, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "c:\\akhildixit\\turboc3\\bgi");
	//setfillstyle(0,getmaxcolor());
	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx / 2;
	midy = maxy / 2;

	axis();

	bar3d(midx + 50, midy - 100, midx + 60, midy - 90, 10, 1


		int n = 0;
	printf("Enter what to do.. 1.Translation \n 2.Scaling \n 3.Rotation \n 4.Reflection \n 5.Shearing");  //Choose
	scanf("%d", &n);
	switch (n)
	{
	case 1: translation(midx, midy);
		break;
	case 2: scaling(midx, midy);
		break;
	case 3: rotation(midx, midy);
		break;
	case 4: reflection(midx, midy);
		break;
	case 5: shearing(midx, midy);
		break;
	}
	getch();
	closegraph();
}
