#include "../Main.hpp"
#include <iostream>


void Grid::DrawGrid() {
    _height = window.GetHeight() / _rows;
    _width = window.GetWidth() / _columns;
    float gridSize = window.GetWidth() * GetSize();

    float offsetX = (window.GetWidth() - gridSize * GetColumns()) / 2;
    float offsetY = (window.GetHeight() - gridSize * GetRows()) / 2;

    for (int i = 0; i < GetColumns(); i++) {
        for (int j = 0; j < GetRows(); j++) {
            float x = offsetX + i * gridSize;
            float y = offsetY + j * gridSize;
            DrawUnitGrid(x, y, GetSize(), _active[i][j]);
    }
    }
}

void Grid::DrawUnitGrid(float x, float y, float size, bool filled) {
    float resize = window.GetWidth() * size;
    if (filled) {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x, y);
        glVertex2f(x + resize, y);
        glVertex2f(x + resize, y + resize);
        glVertex2f(x, y + resize);
        glEnd();
    } else {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(x, y);
        glVertex2f(x + resize, y);

        glVertex2f(x + resize, y);
        glVertex2f(x + resize, y + resize);

        glVertex2f(x + resize, y + resize);
        glVertex2f(x, y + resize);

        glVertex2f(x, y + resize);
        glVertex2f(x, y);
        glEnd();
        }
    }

