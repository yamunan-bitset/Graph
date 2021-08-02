#include <GL/glut.h>
#include <cmath>

void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0); 
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);    
}

void PutPixel(int x, int y)
{
  glColor3f(0.0, 0.9, 0.7);
  glPointSize(2);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void DrawGraph(int x1, int x2, int y1, int y2)
{
  PutPixel(x1, y1);
  PutPixel(x2, y2);

  glColor3f(0.0,0.4,0.2); 
  glPointSize(3.0);  

  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);
  glEnd();
}

int x = 0;
int arr[1001];

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  for (unsigned i = 0; i < sizeof arr; i++)
    {
      DrawGraph(x, x + 1, arr[i], arr[i + 1]);
      x++;
    }
  
  glutSwapBuffers();
  return;
}

void reshape(int w, int h) { glutReshapeWindow(1000, 1000); }

int main(int argc, char** argv)
{
  /* 1, 2, 4, 9, 16, 25, 36, 49, 64, 81, 100, ... => y = x^2*/
  for (unsigned i = 0; i < 1000; i++)
    arr[i] = std::pow(i, 2);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Graph");
  init();
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
