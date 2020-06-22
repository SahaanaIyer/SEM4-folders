//Cohen – Sutherland Line Clipping Algorithm

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

//to encode the given point
int code(int x, int y, int xl, int yl, int xh, int yh)
{
	int code = 0;	//0000 means point is inside window

	//|= means to perform bitwise OR operation to add the bits
	if(x < xl)
		code |= 1;	//0001 means point is left side of window
	else if(x > xh)
		code |= 2;	//0010 means point is right side of window
	if(y < yl)
		code |= 4;	//0100 means point is under the window
	else if(y > yh)
		code |= 8;	//1000 means point is above the window
	return code;
}

//Function for clipping algorithm
void clipping(float ax, float ay, float bx, float by, float xl, float yl, float xh, float yh)	//(ax,ay) is point A, (bx, by) is point B, xl,yl,xh,yh define the window rectangle
{
	int a, b;
	float m;
	//
	if(bx - ax == 0)
		m = INT_MAX;
	else
		m = (by - ay) / (bx - ax);

	//obtain outcodes for point A and B
	a = code(ax, ay, xl, yl, xh, yh);
	b = code(bx, by, xl, yl, xh, yh);

	while(1)
	{
		//if the outcodes are zero, it is inside the window so display the line
		if(a == 0 && b == 0)
		{
			line(ax, ay, bx, by);
			return;
		}
		//if A AND B is non-zero, line is definitely outside the window
		else if(a & b)
		{
			printf("Line outside the clipping area.");
			return;
		}
		//else we must evaluate each bit
		else
		{
			int t;
			float x, y;

			//evaluate either a or b till both are inside the window i.e outcode becomes 0000
			if(a != 0)
				t = a;
			else
				t = b;

			//if t is on the left, clip it at xl and find resp value of y
			if(t & 1)
			{
				y = ay + m*(xl - ax);
				x = xl;
			}
			//if t is on the right, clip it at xh and find resp value of y
			else if(t & 2)
			{
				y = ay + m*(xh - ax);
				x = xh;
			}
			//if t is on the bottom, clip it at yl and find resp value of x
			else if(t & 4)
			{
				x = ax + (yl - ay)/m;
				y = yl;
			}
			//if t is on the top, clip it at yh and find resp value of x
			else if(t & 8)
			{
				x = ax + (yh - ay)/m;
				y = yh;
			}

			//reassign x and y to either a or b and find the new outcode
			if(t == a)
			{
				ax = x;
				ay = y;
				a = code(ax, ay, xl, yl, xh, yh);
			}
			else
			{
				bx = x;
				by = y;
				b = code(bx, by, xl, yl, xh, yh);
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

	float xl = 100 , yl = 100, xh = 400, yh = 300, ax = 250, ay = 350, bx = 450, by = 100;

	//Sets color for next lines (red, green, blue)
	glColor3f(1, 0, 0);	// color selected is red
	//display original line
	line(ax, ay, bx, by);

	glColor3f(0, 0, 1);	//color selected is blue
	//display the window
	glBegin(GL_LINE_LOOP);	//GL_LINE_LOOP joins each vertex in order and then join to start vertex
	glVertex2f(xl, yl);
	glVertex2f(xh, yl);
	glVertex2f(xh, yh);
	glVertex2f(xl, yh);
	glEnd();


	glColor3f(0, 1, 0);	//color selected is green
	//call clipping function to display clipped line
	clipping(ax, ay, bx, by, xl, yl, xh, yh);

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Cohen – Sutherland Line Clipping Algorithm");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}