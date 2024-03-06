#include <GL/freeglut.h>
#include <GL/gl.h>

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    // Add your OpenGL drawing commands here
    
    glFlush(); // Flush the rendering pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // glutInit initializes the
    // GLUT library and negotiate a session with the window system.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); /*
      *This can be used to select the features we
      would want a window to have.

      *It can be the color system we are using,
      the frame buffers needed etc.
    */
    glutInitWindowSize(500, 500);/*    
    The intent of the initial window position
    and size values is to provide a suggestion
    to the window system for a window's initial size.
    */
    glutInitWindowPosition(100, 100); //set the initial window position.
    glutCreateWindow("OpenGL - First window demo"); //The parameter will be used to set the window name.
    
    // Register display callback function
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

