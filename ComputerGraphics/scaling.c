//Scaling Transformation

//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

//function to perform matrix multiplication
void mat_multiply(float a[][3], float b[][3], float c[][3])
{
	for (int i = 0; i < 4; i++)		//i = rows of matrix A
	{
		for (int j = 0; j < 3; j++)		//j = columns of matrix B
		{
			for (int k = 0; k < 3; k++)		//k = column of matrix A / row of matrix B
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
		}
	}
}

//Function for performing scaling of the polygon
void scaling()
{

//	p matrix	vertices		scaling matrix
//	10	10	1	(10,10)			Sx	0	0		Sx = 2, Sy = 2
//	100	10	1	(100,10)		0	Sy	0
//	100	100	1	(100,100)		0	0	1
//	10	100	1	(10,100)

	float p[4][3] = {{10, 10, 1}, {100, 10, 1}, {100, 100, 1}, {10, 100, 1}};	//enter the vertices of square/rectangle here
	float scale[3][3] = {{2, 0, 0}, {0, 2, 0}, {0, 0, 1}};	//we will scale the polygon to twice its size
	float r[4][3] = {0};	//result matrix - the scaled vertices are stored here

	//Display Original Polygon
	glBegin (GL_POLYGON);		//GL_POLYGON indicates the points we plot will join to make a polygon with the points as vertices

	//glVertex2f(x,y) allows use to plot float values without conversion. This is the PutPixel for OpenGL
	//Plot each vertice given, 4 vertices means a square/rectangle will be plotted automatically
	glVertex2f(p[0][0], p[0][1]);
	glVertex2f(p[1][0], p[1][1]);
	glVertex2f(p[2][0], p[2][1]);
	glVertex2f(p[3][0], p[3][1]);

	glEnd();	//to end the plotting sequence

	//perform matrix multiplication
	mat_multiply(p, scale, r);

	glColor3f(0, 1, 0);	//color selected is green
	//Display Scaled Polygon
	glBegin(GL_POLYGON);
	glVertex2f(r[0][0], r[0][1]);
	glVertex2f(r[1][0], r[1][1]);
	glVertex2f(r[2][0], r[2][1]);
	glVertex2f(r[3][0], r[3][1]);
	glEnd();
}

//Display Function(given)
//Functions you have created above will be called here for displaying on the window
void disp()
{
	//sets the background color (red, green, blue, alpha)
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);

	//Sets color for next lines (red, green, blue)
	glColor3f(1, 0, 0);		//color selected is red

	//Call the scaling function
	scaling();

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(300, 300);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Scaling Transformation");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 300, 0, 300);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}