#include "./class/Draw.hpp"
#include "../Main.hpp"
#include "./extern/Extern.hpp"

void Draw::DrawSimulateLight() {
    float gridSize = window.GetWidth() * 0.02;

    glBegin(GL_QUADS);

    if (processor._SimulationProgram()) {
        glColor3f(0.0f, 1.0f, 0.0f);
    } else {
        glColor3f(1.0f, 0.0f, 0.0f);
    }

    glVertex2f(10, 10);
    glVertex2f(10 + gridSize, 10);
    glVertex2f(10 + gridSize, 10 + gridSize);
    glVertex2f(10, 10 + gridSize);

    glEnd();
}
