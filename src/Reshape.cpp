#include "../Main.hpp"

void reshape(int width, int height) {
    window.UpdateWindowSize(width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, window.GetWidth(), 0, window.GetHeight());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}