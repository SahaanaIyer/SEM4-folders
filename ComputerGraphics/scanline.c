//Scanline Polygon Filling Algorithm

//Header files for initialization - (given)
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<limits.h>		//for infinity

//Function for executing scanline filling algorithm
void scanline(int xx[], int yy[], int n)	//xx and yy store coordinates of the vertices, n stores number of vertices
{
	int y, ymax = 0, ymin = 500, dx, dy;
	float m[50];	//m stores 1/slope of each edge/line

	//to find ymax and ymin from array yy[] and 1/slope of each line
	for(int i=0;i<n;i++)
	{
		if(yy[i] >= ymax)
			ymax = yy[i];
		if(yy[i] <= ymin)
			ymin = yy[i];

		//calculate dx and dy of the line
		dx = xx[i+1] - xx[i];
		dy = yy[i+1] - yy[i];

		//storing dx/dy value so if dy=0 then slope is 0 so store INT_MAX (infinity)
		// if dx is 0 slope is infinite so 1/slope is 0
		if(dx == 0)
			m[i] = 0;
		else if(dy == 0)
			m[i] = INT_MAX;
		else if(dx != 0 && dy != 0)
			m[i] = (float) dx / dy;
	}

	//inter_x stores the start and end points which the scanline should print
	int inter_x[50], temp;

	//for every scanline of the polygon (from ymax to ymin)
	for(y=ymax;y>=ymin;y--)
	{
		int cnt = 0;

		//evaluate every pair of lines
		for(int i=0;i<n;i++)
		{
			//check if the line intersects with the scanline (y line)
			if((yy[i] > y && yy[i+1] <= y) || (yy[i] <= y && yy[i+1] > y))
			{
				//store the x cordinate of the intersection
				inter_x[cnt] = (xx[i] + (m[i] * (y - yy[i])));	// xx + m * (y - yy) = xx + (x - xx) = x
				cnt++;
			}
		}

		//sorting x points in increasing order (bubble sort)
		for(int k=0;k<cnt-1;k++)
		{
			for(int i=0;i<cnt-1-k;i++)
			{
				if(inter_x[i] > inter_x[i+1])
				{
					temp = inter_x[i];
					inter_x[i] = inter_x[i+1];
					inter_x[i+1] = temp;
				}
			}
		}

		printf("\nFor scanline y=%d\nCount = %d\n",y,cnt); //for debugging

		//print each pair of line on the same scan line
		for(int i=0;i<cnt-1;i+=2)
		{
			printf("%d-%d\n",inter_x[i],inter_x[i+1]);		//debug
			glBegin(GL_LINES);	//GL_LINE indicates the points we plot will join to make lines with the points as start and end points

			//glVertex2f(x,y) allows use to plot float values without conversion. This is the PutPixel for OpenGL
			glVertex2f(inter_x[i], y);
			glVertex2f(inter_x[i+1], y);

			glEnd();	//to end the plotting sequence
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

	//Sets color for next lines (red, green, blue)
	glColor3f(1, 0, 0);		//color selected is red

	//enter distinct vertices
	//store x and y coordinates of the vertices in xx[] and y[] - (add extra index which stores first vertice again)
	int xx[] = {200, 300, 350, 400, 100, 200};
	int yy[] = {10, 100, 50, 150, 80, 10};

	//Call the scanline function
	scanline(xx, yy, 5);

	glFlush();	//always call when you finish calling all functions
}


//Main Function(given)
int main(int argv, char **argc)
{
	glutInit(&argv, argc);

	//the initial size of the window when you run
	glutInitWindowSize(500, 500);	//syntax - glutInitWindowSize(width, height)

	//for the window title name
	glutCreateWindow("Scanline Polygon Filling");		//syntax - glutCreateWindow("window title here")

	//determine the coordinates of the window border pixels
	gluOrtho2D(0, 500, 0, 500);		//syntax - gluOrtho2D(left, right, bottom, top)

	//put the display function name in the parameters of below function to display the contents on the window
	glutDisplayFunc(disp);		//syntax - glutDisplayFunc(display_function_name)

	glutMainLoop();
	return 0;
}