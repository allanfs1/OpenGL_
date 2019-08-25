/*
 * GL01Hello.cpp: Test OpenGL C/C++ Setup
 */
#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <stdlib.h> 
#include <stdio.h>  
 
 
 
int             Width;                          /* Width of window */
int             Height;                         /* Height of window */
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glShadeModel(GL_SMOOTH);  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);
      // Each set of 4 vertices form a quad
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
 
   glFlush();  // Render now
}

 void display_line(void){
   glShadeModel(GL_SMOOTH);  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);    
   glDisable(GL_POLYGON_STIPPLE);
 

  glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

   glEnd();
   
     glFlush();  // Render now
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 65:
	exit(0);
	break;
  case 90:
    exit(0);
	break;	
  }
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   GLfloat r=1.0, g=0.5, b=0.0;	
   glutInit(&argc, argv);   
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);              // Initialize GLUT
   glutCreateWindow ("GLopen"); // Create a window with the given title
   glutInitWindowSize(1024, 780);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  // glShadeModel (GL_FLAT);
   //glOrtho (0, 5, 0, 5, -1 ,1);
   //glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
