//Polygon generation using mouse interaction

//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

//Display Function(given)
//Functions you have created above will be called here for displaying on the window
void disp()
{
	//sets the background color (red, green, blue, alpha)
	glClearColor(1, 1, 1, 1);	//makes background white
	glClear(GL_COLOR_BUFFER_BIT);

	//Sets color for next lines (red, green, blue)
	glColor3f(0, 0, 0);		//color selected is black

	glFlush();	//always call when you finish calling all functions
}

//basic structure to store x,y value of each point
typedef struct{
   float x, y;
 }Point2D;
 Point2D P[100];
 int cnt = 0;	//counter to store number of points

 //this function will draw the polygon based on the input values given
void drawpolygon()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); //GL_POLYGON create a solid color polygon following the order of points plotted
    for(int i=0;i<cnt;i++)
		glVertex2f(P[i].x, P[i].y);
	glEnd();

	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	//press left click to select a point
    if(button == GLUT_LEFT_BUTTON)	//checks if button press was left button
    {
        if(state == GLUT_DOWN)		//checks if it was a click
        {
            P[cnt].x = x;
            P[cnt].y = 500 - y;	//for mouse function the y starts from top to bottom, but for coordinates it is from bottom to top, so we correct it
            printf("x = %f, y = %f\n", P[cnt].x, P[cnt].y);
            cnt++;
        }
    }
    //press and hold right click to display the polygon
    else if(button == GLUT_RIGHT_BUTTON)	//checks if button press was right button
    {
    	if(state == GLUT_DOWN)		//checks if it was a click
    		drawpolygon(P, cnt);	//polygon will be shown on screen as long as hold right click
    	cnt = 0;	//reset to counter to zero
    }
}

//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Polygon generation using mouse interaction");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMouseFunc(mouse);	//to track mouse inputs

	glutMainLoop();
	return 0;
}
