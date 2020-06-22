//Bezier Curves Generation

//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

//Function for generating bezier curves
void bezier(float xa, float ya, float xb, float yb, float xc, float yc, float xd, float yd, int cnt)	//(xa,ya), (xb,yb), (xc,yc), (xd,yd) are 4 control points, cnt is counter
{
	//only while counter is greater than zero find the next midpoints
	if(cnt > 0)
	{
		float xp, yp, xq, yq, xr, yr, xs, ys, xu, yu, xt, yt;

		//P is mid pt of A & B
		xp = (xa + xb) / 2;
		yp = (ya + yb) / 2;

		//Q is mid pt of B & C
		xq = (xb + xc) / 2;
		yq = (yb + yc) / 2;

		//R is mid pt of C & D
		xr = (xc + xd) / 2;
		yr = (yc + yd) / 2;

		//S is mid pt of P & Q
		xs = (xp + xq) / 2;
		ys = (yp + yq) / 2;

		//U is mid pt of Q & R
		xu = (xq + xr) / 2;
		yu = (yq + yr) / 2;

		//T is mid pt of S & U
		xt = (xs + xu) / 2;
		yt = (ys + yu) / 2;
		//T is a point on the curve

		cnt--;

		//find next points taking A, P, S, T & T, U, R, D as new control points
		bezier(xa, ya, xp, yp, xs, ys, xt, yt, cnt);
		bezier(xt, yt, xu, yu, xr, yr, xd, yd, cnt);
	}
	else //if last points are found
	{
		//plot lines from A to B, B to C and C to D
		glBegin(GL_LINE_STRIP);	//GL_LINE_STRIP prints a line between the points in order
		glVertex2f(xa, ya);
		glVertex2f(xb, yb);
		glVertex2f(xc, yc);
		glVertex2f(xd, yd);
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

	//Call the function with coordinates of A, B, C and D and count(8)
	bezier(50, 50, 150, 300, 450, 250, 400, 50, 8);

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Bezier Curves Generation");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}