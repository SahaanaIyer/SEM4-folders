//Bresenham Line Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int sign(int diff)	//function will return the sign of the diff integer
{
	if(diff < 0)
		return -1;
	else if(diff > 0)
		return 1;
	else
		return 0;
}

void bres(int x1, int y1, int x2, int y2)	// (x1,y1) are the starting coordinates, (x2,y2) are the end coordinates
{
	int dx, dy, g, xinc, yinc, i;

\	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	//xinc and yinc are the values by which we increase/decrease x and y as we plot the line
	\xinc = sign(x2 - x1);
	yinc = sign(y2 - y1);

    glBegin(GL_POINTS);

    //if m<1 i.e. dy<dx (gentle slope case)	we increase x every time
    if(dy < dx)
    {
    	g = 2*dy - dx;	//initial value of G (decision parameter)

    	i=0;	//set a counter

        while(i <= dx)		//repeat dx times i.e. from x1 to x2
    	{
    		glVertex2d(x1, y1);		//glVertex2d(x,y) allows us to plot decimal values. This is the PutPixel for OpenGL (You can also use glVertex2f)

    		x1 = x1 + xinc;		//increment x every time

           	if(g >= 0)		//if g>=0, increment y and update G as G = G+2Dy-2Dx
           	{
        		y1 = y1 + yinc;
        		g = g + 2*dy - 2*dx;
           	}
           	else		//if g<0 don't update y and update G as G=G+2Dy
          		g = g + 2*dy;

           	i++;	//update counter
    	}
    }
    //if m>=1 (steep slope case) interchange x and y notations
    else
    {
    	g = 2*dx - dy;

    	i=0;

    	while(i <= dy)
    	{
    		glVertex2d(x1, y1);

    		y1 = y1 + yinc;

    	    if(g >= 0)
    	    {
    	    	x1 = x1 + xinc;
    	        g = g + 2*dx - 2*dy;
    	    }
    	    else
    	    	g = g + 2*dx;

    	    i++;
    	}
    }

   glEnd();
}

void disp()
{
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);		//color selected is black

	//line for m<1 (towards x axis)
	bres(0, 0, 100, 50);

	//line for m>1 (towards y axis)
	bres(0, 0, 50, 100);

	glFlush();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Bresenham Line Algorithm");
	gluOrtho2D(0, 300, 0, 300);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}