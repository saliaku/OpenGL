#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

struct point{
    GLfloat x,y;
};

struct point points[100];
int numPoints=0;

void display()
{
    glClearColor(1.0,1.0,1.0,1.0);//set background when glclear is called
    glClear(GL_COLOR_BUFFER_BIT);// sets color specified by clearcolor
    glColor3f(0.0,0.0,0.0);//set pen color

    FILE *fptr=fopen("input_q33.txt","r");
    while(fscanf(fptr,"%f %f",&points[numPoints].x,&points[numPoints].y)==2)
    {
        numPoints++;
    }
    fclose(fptr);

    glBegin(GL_POLYGON);
    for(int i=0;i<numPoints;i++)
    {
        glVertex2f(points[i].x,points[i].y);
    }
    glEnd( );

    glColor3f(0.0,1.0,0.0);//set pen color

    glBegin(GL_LINES);
    for(int i=0;i<numPoints-1;i++)
    {
        for(int j=1;j<numPoints;j++)
        {
            glVertex2f(points[i].x,points[i].y);
            glVertex2f(points[j].x,points[j].y);
        }
    }
    glEnd( );


    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("read cordinates and make a polygon");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

