#include "../Main.hpp"


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  grid.DrawGrid();
  draw.DrawSimulateLight();
  draw.DrawColumnsChanger();
  draw.DrawRowsChanger();
  draw.DrawSpeedChanger();
  draw.DrawColorSquareChanger();
  draw.DrawColorGridChanger();
  glFlush();
}

void loop(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glClearColor(0, 0, 0, 1);
    glutInitWindowSize(window._width, window._height);
    glutCreateWindow("GoL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(update);
    event();
    glutMainLoop();
}