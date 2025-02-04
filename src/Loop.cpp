#include "../Main.hpp"

Window window;

void reshape(int width, int height) {
  window.updateWindowSize(width, height);
}

void loop(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(window._width, window._height);
    glutCreateWindow("OpenGL Triangle");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
}