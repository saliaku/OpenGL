#include <GL/freeglut.h>
#include <GL/gl.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw a filled polygon with green color
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // Green color
    
    // Define vertices of the polygon
    glVertex2f(-0.6, 0.7);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.3, -0.5);
    glVertex2f(-0.3, -0.7);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.4, 0.6);
    glEnd();

    // Draw the boundary of the polygon with red color
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0); // Red color
    
    // Define vertices of the polygon
    glVertex2f(-0.6, 0.7);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.3, -0.5);
    glVertex2f(-0.3, -0.7);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.4, 0.6);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Polygon Demo");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white

    glutMainLoop();
    return 0;
}
