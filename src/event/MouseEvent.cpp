#include "./includes/Event.hpp"
#include "../extern/Extern.hpp"

void mouseEvent(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        grid._active[1][2] = true;
        glutPostRedisplay();
    }
}