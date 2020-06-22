//Mid-Point Circle Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

void plotpoints(int xc, int yc, int x, int y)	//(xc, yc) is the center of the circle, (x,y) is the point to plot for circle at origin (0,0)
{
	//1st Quadrant
	glVertex2d(xc + x, yc + y);		//for x,y point
	glVertex2d(xc + y, yc + x);		//for y,x point

	//2nd Quadrant
	glVertex2d(xc - x, yc + y);		//for -x,y point
	glVertex2d(xc - y, yc + x);		//for -y,x point

	//3rd Quadrant
	glVertex2d(xc - x, yc - y);		//for -x,-y point
	glVertex2d(xc - y, yc - x);		//for -y,-x point

	//4th Quadrant
	glVertex2d(xc + x, yc - y);		//for x,-y point
	glVertex2d(xc + y, yc - x);		//for y,-x point
}

void midpt(int xc, int yc, int r)	//(xc, yc) is the center of the circle of radius r
{
	int x = 0, y = r, p;

	glBegin(GL_POINTS);
	p = 1 - r;    //initial value of P (decision parameter)
	plotpoints(xc, yc, x, y);      	//plot the initial point(0,r) for all 8 octants

	//loop from line x=0 to x=y	i.e. first octant	i.e. till x is greater than y
	while(x <= y)
	{
		x = x + 1;
		if(p < 0)	      //if P<0 update P=P+2x+1 and don't update y
			p = p + 2*x + 1;
		else		      //if P>=0 update P=P+2x-2y+1 and decrement y
		{
			y = y - 1;
			p = p + 2*(x - y) + 1;
		}
        plotpoints(xc, yc, x, y);
	}
	glEnd();
}

void disp()
{
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);		//color selected is black
	midpt(250, 250, 200);
	glFlush();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Mid-Point Circle Algorithm");
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}