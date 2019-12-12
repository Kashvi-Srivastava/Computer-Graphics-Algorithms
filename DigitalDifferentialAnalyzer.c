#include<stdio.h> 
#include<graphics.h> 
#include <conio.h>
int abs (int n) 
{ 
    return ( n>0 ? n : -n); 
}  
void DDA (int X0, int Y0, int X1, int Y1) 
{ 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
    float m_x = dx / (float) steps; 
    float m_y = dy / (float) steps; 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        putpixel (X,Y,RED); 
        X += m_x;           
        Y += m_y;            
        delay(100); 
    } 
} 
int main() 
{ 
    int gd = DETECT, gm; 
    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");    
    DDA(30,200,80,240);
    DDA(80,240,130,200);
    DDA(130,200,80,30);
    DDA(80,30,30,200);
    getch();
    closegraph(); 
    return 0; 
}  
