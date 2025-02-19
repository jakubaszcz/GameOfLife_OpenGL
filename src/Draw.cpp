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

void Draw::DrawColumnsChanger() {
    float size = window.GetWidth() * 0.02;
    int length = 0;
    for (; length < 5; length++) {
        if (grid.GetColumns() == grid._columnsSize[length]) break;
    }
    glBegin(GL_QUADS);
    if (length == 4) {
        glColor3f(0.0f, 1.0f, 0.0f);
    } else if (length == 0) {
        glColor3f(1.0f, 0.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2f(10, 10);
    glVertex2f(10 + size, 10);
    glVertex2f(10 + size, 10 + size * grid.gridSize[length]);
    glVertex2f(10, 10 + size  * grid.gridSize[length]);
    glEnd();
}

void Draw::DrawRowsChanger() {
    float size = window.GetWidth() * 0.02;
    int length = 0;

    float gap = window.GetHeight() * 0.04;

    for (; length < 5; length++)
        if (grid.GetRows() == grid._rowsSize[length]) break;
    glBegin(GL_QUADS);
    if (length == 4) {
        glColor3f(0.0f, 1.0f, 0.0f);
    } else if (length == 0) {
        glColor3f(1.0f, 0.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2f(10 + gap, 10);
    glVertex2f(10 + gap + size, 10);
    glVertex2f(10 + gap + size, 10 + size * grid.gridSize[length]);
    glVertex2f(10 + gap, 10 + size * grid.gridSize[length]);
    glEnd();
}