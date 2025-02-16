#include "./class/Draw.hpp"
#include "../Main.hpp"
#include "./extern/Extern.hpp"

void Draw::DrawSimulateLight() {
    float size = window.GetWidth() * 0.02;

    glBegin(GL_QUADS);

    if (processor._SimulationProgram()) {
        glColor3f(0.0f, 1.0f, 0.0f);
    } else {
        glColor3f(1.0f, 0.0f, 0.0f);
    }

    glVertex2f(10, window.GetHeight() - 10);
    glVertex2f(10 + size, window.GetHeight() - 10);
    glVertex2f(10 + size, window.GetHeight() - 10 - size);
    glVertex2f(10, window.GetHeight() - 10 - size);
    glEnd();
}
