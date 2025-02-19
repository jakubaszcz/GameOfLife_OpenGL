#include "./includes/Event.hpp"
#include "../class/Grid.hpp"
#include "../extern/Extern.hpp"
#include <random>
#include <iostream>

void selectGrid(int mouseX, int mouseY) {
    float gridSize = window.GetWidth() * grid.GetSize();
    float sizeColumns = gridSize * grid.GetColumns();
    float sizeRows = gridSize * grid.GetRows();

    float offsetX = (window.GetWidth() - sizeColumns) / 2;
    float offsetY = (window.GetHeight() - sizeRows) / 2;

    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;

    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeColumns &&
        adjMouseY >= offsetY && adjMouseY <= offsetY + sizeRows) {
        int column = (adjMouseX - offsetX) / gridSize;
        int row = (adjMouseY - offsetY) / gridSize;
        grid.SwitchUnitState(column, row);
    }
}

void resizeColumnsGrid(int mouseX, int mouseY) {
    float size = window.GetWidth() * grid.GetSize();
    int length = 0;
    for (; length < 5; length++)
      if (grid.GetColumns() == grid._columnsSize[length]) break;
    int index = (length + 1) % 5;
    float sizeHeight = size * grid.gridSize[length];
    float sizeWidth = size;
    float offsetX = 10;
    float offsetY = 10 + size * grid.gridSize[length];
    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;
    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeWidth &&
        adjMouseY >= offsetX && adjMouseY <= offsetY) {
        grid.ResizeGrid(grid._columnsSize[index], grid.GetRows());
        }
}

void resizeRowsGrid(int mouseX, int mouseY) {
    float size = window.GetWidth() * grid.GetSize();
    float gap = window.GetWidth() * 0.04;
    int length = 0;
    for (; length < 5; length++) {
              if (grid.GetRows() == grid._rowsSize[length]) break;

    }
    int index = (length + 1) % 5;
    float sizeHeight = size * grid.gridSize[length];
    float sizeWidth = size;
    float offsetX = gap;
    float offsetY = 10;
    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;
    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeWidth &&
        adjMouseY >= offsetY && adjMouseY <= offsetY + size * grid.gridSize[length])
        grid.ResizeGrid(grid.GetColumns(), grid._rowsSize[index]);
}

void mouseEvent(int button, int state, int mouseX, int mouseY) {
    if (!processor._SimulationProgram() && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        selectGrid(mouseX, mouseY);
        resizeColumnsGrid(mouseX, mouseY);
        resizeRowsGrid(mouseX, mouseY);
        glutPostRedisplay();
    }
}