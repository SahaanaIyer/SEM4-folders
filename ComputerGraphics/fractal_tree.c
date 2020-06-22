//Fractal Generation - Tree
//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>	//you need for calculating sin and cos

//Function for generating fractcals - Koch Curves
void tree(int x1, int y1, int x2, int y2, int it)	//(x1, y1) and (x2,y2) are root and top points, it is the iteration counter
{
	//display the line
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();

	//while counter is not zero
	if(it > 0)
	{
		float angle = 30*M_PI/180;	//calculate angle of 30deg in radians

		int x3 = 0.67*(x2 - x1);	//extend the line to a dist about 0.67 times the original length
		int y3 = 0.67*(y2 - y1);

		//rotate the line by 30deg to the left and right and translate w.r.to x2,y2
		int xr = x2 + x3*cos(angle) - y3*sin(angle);
		int yr = y2 + x3*sin(angle) + y3*cos(angle);

		int xl = x2 + x3*cos(angle) + y3*sin(angle);
		int yl = y2 - x3*sin(angle) + y3*cos(angle);

		//takee these points and x2,y2 as new root go to next iteration
		tree(x2, y2, xr, yr, it-1);
		tree(x2, y2, xl, yl, it-1);
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
	tree(250, 0, 250, 100, 10);

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