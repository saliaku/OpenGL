#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

// Structure to store a point's coordinates
struct Point {
    GLfloat x, y;
};

struct Point points[100]; // Array to store points
int numPoints = 0; // Number of points read from file

// Display callback function
void display() 
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    // Add your OpenGL drawing commands here
    glColor3f(0.0,0.0,0.0);

    FILE *fptr=fopen("input_q22.txt","r");
    while (fscanf(fptr, "%f %f", &points[numPoints].x, &points[numPoints].y) == 2)
    {
        numPoints++;
    }

    fclose(fptr);

    glBegin(GL_LINE_STRIP); // Begin drawing line strip

    // Loop through points and draw line strip
    for (int i = 0; i < numPoints; i++) {
        glVertex2f(points[i].x, points[i].y);
    }

    glEnd(); // End drawing line strip

    glFlush(); // Flush the rendering pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("read cordinates and make a line");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}