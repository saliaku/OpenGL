#include <GL/glut.h>
#include <math.h>

// Function to draw a circle
void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    //glVertex2f(cx, cy); // Center of circle
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float x = radius * cosf(theta); // Calculate x component
        float y = radius * sinf(theta); // Calculate y component
        glVertex2f(cx + x, cy + y); // Output vertex
    }
    glEnd();
}

// Display callback function
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // Set color to white
    drawCircle(250, 250, 100, 100); // Draw circle with center (250, 250) and radius 100

    glFlush(); // Flush OpenGL pipeline
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle Drawing");

    // Set up the OpenGL projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500); // Set up a 2D orthographic projection

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
