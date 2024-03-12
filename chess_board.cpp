#include <GL/glut.h>

// Function to draw a square
void drawSquare(float x, float y, float size, int isBlack) {
    if (isBlack)
        glColor3f(0.0, 0.0, 0.0); // Set color to black
    else
        glColor3f(1.0, 1.0, 1.0); // Set color to white

    glBegin(GL_QUADS); // Begin drawing quadrilateral
    glVertex2f(x, y); // Bottom-left vertex
    glVertex2f(x + size, y); // Bottom-right vertex
    glVertex2f(x + size, y + size); // Top-right vertex
    glVertex2f(x, y + size); // Top-left vertex
    glEnd(); // End drawing quadrilateral
}

// Display callback function
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glClear(GL_COLOR_BUFFER_BIT);

    float squareSize = 50.0; // Size of each square
    float xOffset, yOffset; // Offset for drawing squares

    // Draw the chessboard
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            xOffset = j * squareSize;
            yOffset = i * squareSize;
            drawSquare(xOffset, yOffset, squareSize, (i + j) % 2);
        }
    }

    glFlush(); // Flush OpenGL pipeline
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chessboard");

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
