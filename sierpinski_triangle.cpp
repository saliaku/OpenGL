#include <GL/glut.h>

// Function to draw Sierpinski triangle
void drawSierpinskiTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int depth) {
    if (depth == 0) {
        // Draw filled triangle
        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
    } else {
        // Calculate midpoints of sides
        float midx1 = (x1 + x2) / 2;
        float midy1 = (y1 + y2) / 2;
        float midx2 = (x2 + x3) / 2;
        float midy2 = (y2 + y3) / 2;
        float midx3 = (x3 + x1) / 2;
        float midy3 = (y3 + y1) / 2;

        // Recursively draw smaller triangles
        drawSierpinskiTriangle(x1, y1, midx1, midy1, midx3, midy3, depth - 1);
        drawSierpinskiTriangle(midx1, midy1, x2, y2, midx2, midy2, depth - 1);
        drawSierpinskiTriangle(midx3, midy3, midx2, midy2, x3, y3, depth - 1);
    }
}

// Display callback function
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to black
    float vertices[] = {0.0, 0.0, 200.0, 400.0, 400.0, 0.0}; // Initial triangle vertices
    drawSierpinskiTriangle(vertices[0], vertices[1], vertices[2], vertices[3], vertices[4], vertices[5], 5); // Draw Sierpinski triangle

    glFlush(); // Flush OpenGL pipeline
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sierpinski Triangle");

    // Set up the OpenGL projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400); // Set up a 2D orthographic projection

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
