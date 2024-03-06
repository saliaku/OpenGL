/*Write a program in which you can make strokes by holding down the mouse left
button, dragging and releasing. The path (stroke) traced out by the mouse
pointer between the events of mouse's left button click and the eventual release
of the left click needs to be plotted. There can be any number of strokes. Using
this concept write your name on the screen. Make the background white and
the strokes black in color.*/


#include <GL/glut.h>
#include <stdio.h>

#define MAX_POINTS 1000

// Structure to store a point's coordinates
struct Point {
    GLfloat x, y;
};

struct Point points[MAX_POINTS]; // Array to store points
int numPoints = 0; // Number of points in the current stroke

// Function to draw strokes
void drawStrokes() {
    glColor3f(0.0, 0.0, 0.0); // Set color to black
    glBegin(GL_LINE_STRIP); // Begin drawing line strip

    // Loop through points and draw line strip
    for (int i = 0; i < numPoints; i++) {
        glVertex2f(points[i].x, points[i].y);
    }

    glEnd(); // End drawing line strip
}

// Display callback function
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);

    drawStrokes(); // Draw strokes

    glFlush(); // Flush OpenGL pipeline
}

// Mouse callback function for handling mouse button events
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // Mouse button pressed, start new stroke
            numPoints = 0;
            points[numPoints].x = x;
            points[numPoints].y = glutGet(GLUT_WINDOW_HEIGHT) - y;
            numPoints++;
        } else if (state == GLUT_UP) {
            // Mouse button released, end stroke
            glutPostRedisplay(); // Trigger redrawing
        }
    }
}

// Mouse motion callback function for handling mouse drag events
void motion(int x, int y) {
    points[numPoints].x = x;
    points[numPoints].y = glutGet(GLUT_WINDOW_HEIGHT) - y;
    numPoints++;
    glutPostRedisplay(); // Trigger redrawing
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Your Name");

    // Register display callback function
    glutDisplayFunc(display);
    
    // Register mouse callback functions
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
