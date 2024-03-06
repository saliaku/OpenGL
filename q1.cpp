#include <GL/freeglut.h>
#include <GL/gl.h>
/*Display a set of 7 clearly visibile points : 4 points just
near the corners of the OpenGL window
and three
points distributed far apart from each other in the interior
of the window.*/
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set point size for better visibility
    glPointSize(5.0);

    // Draw four points near the corners of the window
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(-0.9, 0.9);   // Top-left corner
    glVertex2f(0.9, 0.9);    // Top-right corner
    glVertex2f(-0.9, -0.9);  // Bottom-left corner
    glVertex2f(0.9, -0.9);   // Bottom-right corner
    
    // Draw three points distributed far apart in the interior of the window
    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2f(0.0, 0.0);     // Center point
    glVertex2f(-0.5, 0.5);    // Upper-left interior point
    glVertex2f(0.5, -0.5);    // Lower-right interior point
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Point Demo");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

    glutMainLoop();
    return 0;
}
