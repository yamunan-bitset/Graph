#include <GL/glut.h>

/* Draw Line
  glClear(GL_COLOR_BUFFER_BIT);  
  glColor3f(0.0,0.4,0.2); 
  glPointSize(3.0);  

  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);
  glEnd();
*/

void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0); 
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);    
}

void PutPixel(int x, int y)
{
  glColor3f(0.0, 0.9, 0.7);
  glPointSize(1);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void DrawGraph(int x, int y)
{
  PutPixel(x, y);
}

int x = 0;
int arr[11] = {1, 2, 4, 9, 16, 25, 36, 49, 64, 81, 100}; // x**2

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  for (unsigned i = 0; i < sizeof arr; i++)
    { DrawGraph(x, arr[i]); x++; }
  
  glutSwapBuffers();
  return;
}

void reshape(int w, int h) { glutReshapeWindow(500, 500); }

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Graph");
  init();
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
