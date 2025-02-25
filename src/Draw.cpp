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

void Draw::DrawSpeedChanger() {
    int resize[6] = {1, 2, 3, 4, 5, 6};
    float size = window.GetWidth() * 0.02;
    float gap = window.GetHeight() * 0.04;
    int length = 0;
    for (; length < 6; length++)
        if (speed == speeds[length]) break;
    glBegin(GL_QUADS);
    if (length == 5) {
        glColor3f(0.0f, 1.0f, 0.0f);
    } else if (length == 0) {
        glColor3f(1.0f, 0.0f, 0.0f);
    } else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glVertex2f(10 + gap, window.GetHeight() - 10);
    glVertex2f(10 + size + gap * resize[length], window.GetHeight() - 10);
    glVertex2f(10 + size + gap * resize[length], window.GetHeight() - 10 - size);
    glVertex2f(10 + gap, window.GetHeight() - 10 - size);
    glEnd();
}


void Draw::DrawUnitSquareColorChanger(int x, int y, int size, int pos) {
    glBegin(GL_QUADS);
    float sizer = window.GetWidth() * 0.03;

    if (pos == colorSquare) {
        glColor3f(colors[pos][0], colors[pos][1], colors[pos][2]);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + sizer);
        glVertex2f(x, y + sizer);
    } else {
        glColor3f(colors[pos][0], colors[pos][1], colors[pos][2]);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    }
    glEnd();
}

void Draw::DrawColorSquareChanger() {
    int size = window.GetWidth() * 0.02;
    int gap = window.GetHeight() * 0.04;

    float offsetX = (window.GetWidth() - size * 6) / 2.0f;
    float offsetY = 10.0f;
    for (int i = 0; i < 7; i++) {
        float x = offsetX + i * size;
        DrawUnitSquareColorChanger(x, offsetY, size, i);
    }
}

void Draw::DrawUnitGridColorChanger(int x, int y, int size, int pos) {
    glBegin(GL_QUADS);
    float sizer = window.GetWidth() * 0.03;

    if (pos == colorGrid) {
        glColor3f(colors[pos][0], colors[pos][1], colors[pos][2]);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - sizer);
        glVertex2f(x, y - sizer);
    } else {
        glColor3f(colors[pos][0], colors[pos][1], colors[pos][2]);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
    }
    glEnd();
}

void Draw::DrawColorGridChanger() {
    int size = window.GetWidth() * 0.02;
    int gap = window.GetHeight() * 0.04;

    float offsetX = (window.GetWidth() - size * 6) / 2.0f;
    float offsetY = 10.0f + ((size * 2) + gap) + size;

    for (int i = 0; i < 7; i++) {
        float x = offsetX + i * size;
        DrawUnitGridColorChanger(x, offsetY, size, i);
    }
}