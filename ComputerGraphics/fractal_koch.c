//Fractal Generation - Koch Curves
//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>	//you need for calculating sin and cos

//Function for generating fractcals - Koch Curves
void koch(int x1, int y1, int x2, int y2, int it)	//(x1, y1) and (x2,y2) are start and end points of the line, it is the iteration counter
{
	float angle = 60*M_PI/180;	//calculate angle of 60deg in radians

	//divide the line into 3 parts, from (x1,y1)---(x3,y3)---(x4,y4)---(x2,y2)
	int x3 = (2*x1 + x2)/3;
	int y3 = (2*y1 + y2)/3;

	int x4 = (x1 + 2*x2)/3;
	int y4 = (y1 + 2*y2)/3;

	//make an equilateral triangle from (x3,y3) to (x4,y4)
	//(x,y) is the third vertice
	int x = x3 + (x4 - x3)*cos(angle) - (y4 - y3)*sin(angle);
	int y = y3 + (x4 - x3)*sin(angle) + (y4 - y3)*cos(angle);

	//for printinf the line segments(only the last iteration segments are displayed)
	if(it > 0)
	{
		//create same fractal for the 4 new line segments
		koch(x1, y1, x3, y3, it-1);
		koch(x3, y3, x, y, it-1);
		koch(x, y, x4, y4, it-1);
		koch(x4, y4, x2, y2, it-1);
	}
	else
	{
		//print these line segments
		glBegin(GL_LINE_STRIP);	//GL_LINE_STRIP prints a line between the points in order
		glVertex2f(x1, y1);
		glVertex2f(x3, y3);
		glVertex2f(x, y);
		glVertex2f(x4, y4);
		glVertex2f(x2, y2);
		glEnd();
	 }
}

//Display Function(given)
//Functions you have created above will be called here for displaying on the window
void disp()
{
	//sets the background color (red, green, blue, alpha)
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);

	//Sets color for next lines (red, green, blue)
	glColor3f(0, 0, 0);		//color selected is black

	//call function with x1, y1, x2, y2 and it as inputs
	koch(10, 250, 490, 250, 4);

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Fractal Generation");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}