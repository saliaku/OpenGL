#include <GL/freeglut.h>
#include <GL/gl.h>

// Display callback function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    // Add your OpenGL drawing commands here

    glFlush(); // Flush the rendering pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    // Register display callback function
    glutDisplayFunc(display);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - First window demo");
    
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();

    

    glutMainLoop();
    return 0;
}