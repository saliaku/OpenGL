#include <GL/gl.h>       // Include OpenGL header
#include <GL/freeglut.h> // Include FreeGLUT header
#include <stdio.h>       // Include standard I/O header for file operations

float r = 0.0, g = 0.0, b = 0.0, a = 0.0; // Define global variables to store RGBA color components

void display()
{
    FILE *fptr = fopen("input_q11.txt", "r");    // Open file "input_q11.txt" for reading
    fscanf(fptr, "%f %f %f %f", &r, &g, &b, &a); // Read RGBA color components from the file

    glClearColor(r, g, b, a);     // Set the clear color for the window
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with the specified clear color
    glFlush();                    // Flush OpenGL commands to the rendering pipeline
    fclose(fptr);                 // Close the file
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize FreeGLUT library

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB color mode

    glutInitWindowSize(500, 500); // Set window size

    glutInitWindowPosition(100, 100); // Set window position

    glutCreateWindow("question 1"); // Create a window with the title "question 1"

    glutDisplayFunc(display); // Set display callback function to display()

    glutMainLoop(); // Enter the main event processing loop

    return 0; // Return from main function
}
