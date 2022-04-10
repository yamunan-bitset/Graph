#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

#if 1 // 0
#define DEBUG_GRAPH
#endif
#ifdef DEBUG_GRAPH
#define DEBUG(msg) std::cout << "\033[95m" \
  << "Reached: " << "\033[31m"		   \
  << msg << "\033[97m" << std::endl
#else
#define DEBUG(msg) std::cout << ""
#endif

void init()
{
  DEBUG("init");
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

void DrawAxes()
{
  DEBUG("Draw Axes");
  
  glColor3f(0.9,0.4,0.2);
  glPointSize(1.0);
  
  glBegin(GL_LINES);
  glVertex2d(500, 0);
  glVertex2d(500, 1000);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex2d(0, 500);
  glVertex2d(1000, 500);
  glEnd();
}

void DrawGraph(int _x1, int _x2, int _y1, int _y2)
{
  // Offsets
  int x1 = _x1*10 + 500;
  int x2 = _x2*10 + 500;
  int y1 = _y1 + 500;
  int y2 = _y2 + 500;
  
  PutPixel(x1, y1);
  PutPixel(x2, y2);

  glColor3f(0.0,0.4,0.2); 
  glPointSize(3.0);  

  glBegin(GL_LINES);
  glVertex2d(x1, y1);
  glVertex2d(x2, y2);
  glEnd();
}

int y[1001];

void display()
{
  DEBUG("Display");
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  DrawAxes();
  
  for (unsigned i = 0; i < 100; i++)
    DrawGraph(i, i + 1, y[i], y[i + 1]);
  
  glutSwapBuffers();
  return;
}

void reshape(int w, int h)
{ DEBUG("Reshape: \033[36m" << w << ',' << ' ' << h); glutReshapeWindow(1000, 1000); }

std::string ReadNthLine(std::ifstream* in, int N, unsigned lines)
{
  std::string s;
  s.reserve(lines);

  for (unsigned i = 0; i < N; ++i)
    std::getline(*in, s);

  std::getline(*in, s);
  return s; 
}

unsigned LineNumber(std::istream& in)
{
  unsigned lines = 1;
  in.clear();
  auto originalPos = in.tellg();
  if (originalPos < 0) return 0;
  in.seekg(0);
  char c;
  while ((in.tellg() < originalPos) && in.get(c))
    if (c == '\n') ++lines;
  return lines;
}

int main(int argc, char** argv)
{
  DEBUG("DEBUG on");
  if (argc < 2)
    {
      DEBUG("Read 'example.dat'");
      using namespace std;
      /* 1, 2, 4, 9, 16, 25, 36, 49, 64, 81, 100, ... => y = x^2*/
      for (unsigned x = 0; x < 1000; x++)
	y[x] =
#include "example.dat"

    }
  else if (std::string(argv[1]) == "-h") goto Usage;
  else
    {
      std::ifstream in(argv[1]);
      unsigned lines = LineNumber(in);
      while (lines != 0)
	for (unsigned i = 0; i < lines; i++)
	  {
	    y[i] = std::atoi(ReadNthLine(&in, i, lines).c_str());
	    std::cout << y[i] << std::endl;
	  }
    }
  DEBUG("GLUT init");
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Graph");
  init();

  DEBUG("Linking Display, Reshape");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;

 Usage:
  DEBUG("USAGE");
  std::cout << "USAGE: ./graph <filename>" << std::endl
	    << "If filename not specified, then default will be y = x^2"
	    << std::endl;
  return 0;
}
