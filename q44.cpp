#include<GL/gl.h>
#include<GL/freeglut.h>
#include<stdio.h>

struct Point 
{
    GLfloat x,y;
};

struct Point points[100];
int numPoints=0;

void display()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

    FILE *fptr=fopen("input_q44.txt","r");
    while(fscanf(fptr,"%f %f", &points[numPoints].x, &points[numPoints].y)==2)
    {
        numPoints++;
    }

    glBegin(GL_POLYGON);

    for(int i=0;i<numPoints;i++)
    {
        glVertex2f(points[i].x,points[i].y);
    }
    glEnd();



    glFlush();

}

int main( int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("rectangle from points in red");

    glutDisplayFunc(display);
    glutMainLoop();

}


