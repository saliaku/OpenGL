#include <GL/freeglut.h>
#include <GL/gl.h>
/*display 3 line segments of different lengths and colors*/
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw three line segments of different lengths and colors
    glBegin(GL_LINES);
    
    // Line segment 1: Red color, horizontal line
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(-0.9, 0.0);
    glVertex2f(0.9, 0.0);
    
    // Line segment 2: Green color, vertical line
    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2f(0.0, -0.9);
    glVertex2f(0.0, 0.9);
    
    // Line segment 3: Blue color, diagonal line
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glVertex2f(-0.9, -0.9);
    glVertex2f(0.9, 0.9);
    
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Line Segment Demo");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

    glutMainLoop();
    return 0;
}
