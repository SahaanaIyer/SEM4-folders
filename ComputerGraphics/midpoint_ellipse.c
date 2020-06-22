//Mid-Point Ellipse Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void plotpoints(int xc, int yc, int x, int y)	//(xc, yc) is the center of the ellipse, (x,y) is the point to plot for circle at origin (0,0)
{
	//1st Quadrant
	glVertex2d(xc + x, yc + y);		//for x,y point

	//2nd Quadrant
	glVertex2d(xc - x, yc + y);		//for -x,y point

	//3rd Quadrant
	glVertex2d(xc - x, yc - y);		//for -x,-y point

	//4th Quadrant
	glVertex2d(xc + x, yc - y);		//for x,-y point
}

void ellipse(int xc, int yc, int rx, int ry)	//(xc,yc) is centre of ellipse, rx, ry are the semi-axes of ellipse
{
	//first plot ellipse at origin then shift to (xc,yc)
	int x = 0, y = ry, p;	//set initial value of x,y to (0,ry) (similar to circle)
	glBegin(GL_POINTS);

	//In Ellipse each quadrant as 2 regions so we must plot points separately for both regions
	//Region 1 initial value of decision parameter p
	p = pow(ry, 2) + pow(rx, 2)*(-ry + 0.25);

	//for region 1 i.e. from (0,ry) to point where slope is -1 i.e. where slope = -(2*ry^2*x)/(2*rx^2*y)
	while( (2*x*pow(ry, 2)) < (2*y*pow(rx, 2)) )
	{
		plotpoints(xc, yc, x, y);
		x = x + 1;
		if(p < 0)
			p = p + pow(ry, 2)*(2*x + 1);
		else
		{
			y = y - 1;
			p = p + pow(ry, 2)*(2*x + 1) - 2*pow(rx, 2)*y;
		}
	}

	//Region 2 initial value of decision parameter p
	p = pow(ry, 2)*pow(x + 0.5, 2) + pow(rx, 2)*pow(y - 1, 2) - pow(rx, 2)*pow(ry, 2);

	//for region 2 from point where slope is -1 to the x axis i.e. as long as y is not -ve
	while(y >= 0)
	{
		plotpoints(xc, yc, x, y);
		y = y - 1;
		if(p > 0)
			p = p + pow(rx, 2)*(-2*y + 1);
		else
		{
			x = x + 1;
			p = p + pow(rx, 2)*(-2*y + 1) + 2*pow(ry, 2)*x;
		}
	}
	glEnd();
}

void disp()
{
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);		//color selected is black
	ellipse(250, 250, 200, 100);
	glFlush();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Mid-Point Ellipse Algorithm");
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
