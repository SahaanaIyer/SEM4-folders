// DDA Line Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

 void DDA(int x1, int y1, int x2, int y2)	// (x1,y1) are the starting coordinates
                                            // (x2,y2) are the end coordinates
{
	int dx, dy, steps, i;
	float xinc, yinc, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	//determining whether to draw points along x axis(if dx is greater) or y axis(if dy is greater)
	//storing the greater value is steps variable
	if(abs(dx) > abs(dy))	//compare non sign values only
		steps = abs(dx);
	else
		steps = abs(dy);

	//xinc and yinc are the values by which we increase x and y as we plot the line
	xinc = dx / steps;
	yinc = dy / steps;

	//set first points as starting points given
	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	glVertex2f(x, y);

	for(i = 0; i < steps; i++)
	{
		//increment x and y values as per xinc and yinc
		x = x + xinc;
		y = y + yinc;
		glVertex2f(x, y);
	}

	glEnd(); //to end the plotting sequence
}
void disp()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);		//color selected is black
	//drawing the box of house
	DDA(50, 80, 90, 80);
	DDA(90, 80, 90, 40);
	DDA(90, 40, 50, 40);
	DDA(50, 40, 50, 80);

	glColor3f(1, 0, 0);		//color selected is red
	//drawing the roof of house
	DDA(50, 80, 70, 100);
	DDA(90, 80, 70, 100);

	glColor3f(0, 0, 0);		//color selected is black
	//drawing the door of house
	DDA(65, 40, 65, 60);
	DDA(75, 40, 75, 60);
	DDA(65, 60, 75, 60);

	glFlush();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(300, 300);
	glutCreateWindow("DDA Line Algorithm");
	gluOrtho2D(0, 300, 0, 300);
	glutDisplayFunc(disp);	glutMainLoop();
	return 0;
}