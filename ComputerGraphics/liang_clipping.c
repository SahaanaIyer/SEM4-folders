//Liang-Barsky Line Clipping Algorithm

//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<limits.h>	//for slope condition

//simple function to print the lines
void line(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

//for updating values of t1 and t2 at each boundary
int cliptest(float p, float q, float *t1, float *t2)
{
	float t;	//t will be the parameter for the point where the line meets the boundary
	//flag determines if line completely outside the window or inside
	int flag = 1;

	//if line is entering the boundary		1----|---->2
	if(p < 0.0)
	{
		//calculate value of t at the boundary
		t = q / p;

		//check if t is within t1 and t2 and then assign to t1	(because t1 would be for point outside boundary)
		if(t > *t2) //if t2 is less than t, means line ends before entering boundary
			flag = 0;
		else if(t > *t1)
			*t1 = t;
	}
	//if line is exiting the boundary	2<----|----1
	else if(p > 0.0)
	{
		t = q / p;

		//check if t is within t1 and t2 and then assign to t2 (because t2 would be for point outside boundary)
		if(t < *t1)	//if t is less than t1, means line starts after exiting boundary
			flag = 0;
		else if(t < *t2)
			*t2 = t;
	}
	//line is parallel to boundary
	//then check if line lies inside window side of the boundary i.e. q should be +ve
	else if(q < 0.0)
		flag = 0;

	return flag;
}

//Function for clipping algorithm
void clipping(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax)	//xmin,ymin,xmax,ymax are boundaries of window rectangle
{
	//Parametric equations are X = x1 + t(x2-x1) and Y = y1 + t(y2-y1)
	//t is called parameter of the line
	//for x1,y1 t is 0 and for x2,y2, t is 1
	float t1 = 0.0, t2 = 1.0, dx = x2 - x1, dy;
	//find value of t1 and t2 for left boundary
	if(cliptest(-dx, x1-xmin, &t1, &t2))
	{
		//find value of t1 and t2 for right boundary
		if(cliptest(dx, xmax-x1, &t1, &t2))
		{
			dy = y2 - y1;

			//find value of t1 and t2 for bottom boundary
			if(cliptest(-dy, y1-ymin, &t1, &t2))
			{
				//find value of t1 and t2 for top boundary
				if(cliptest(dy, ymax-y1, &t1, &t2))
				{
					//calculate new value of x2,y2 using t2 only if it changed
					if(t2 < 1.0)
					{
						x2 = x1 + t2*dx;
						y2 = y1 + t2*dy;
					}

					//calculate new value of x1,y1 using t1	only if it changed
					if(t1 > 0.0)
					{
						x1 += t1*dx;
						y1 += t1*dy;
					}

					line(x1, y1, x2, y2);
				}
			}
		}
	}
}

//Display Function(given)
//Functions you have created above will be called here for displaying on the window
void disp()
{
	//sets the background color (red, green, blue, alpha)
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);

	float xmin = 100 , ymin = 100, xmax = 400, ymax = 300, x1 = 250, y1 = 350, x2 = 450, y2 = 100;

	//Sets color for next lines (red, green, blue)
	glColor3f(1, 0, 0);	// color selected is red
	//display original line
	line(x1, y1, x2, y2);

	glColor3f(0, 0, 1);	//color selected is blue
	//display the window
	glBegin(GL_LINE_LOOP);	//GL_LINE_LOOP joins each vertex in order and then join to start vertex
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();

	glColor3f(0, 1, 0);	//color selected is green
	//call clipping function to display clipped line
	clipping(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Liang-Barsky Line Clipping Algorithm");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}
