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

void selectSquareColor(int mouseX, int mouseY) {
    float gridSize = window.GetWidth() * grid.GetSize();
    float gap = window.GetWidth() * 0.04;
    float sizeColumns = gridSize * 7;

    float offsetX = (window.GetWidth() - sizeColumns) / 2.0f;
    float offsetY = 10;

    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;

    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeColumns &&
        adjMouseY >= offsetY && adjMouseY <= offsetY + gridSize) {
        int column = (adjMouseX - offsetX) / gridSize;
        colorSquare = column;
        }
}

void selectGridColor(int mouseX, int mouseY) {
    float gridSize = window.GetWidth() * grid.GetSize();
    float gap = window.GetWidth() * 0.04;
    float sizeColumns = gridSize * 7;

    float offsetX = (window.GetWidth() - sizeColumns) / 2.0f;
    float offsetY = 10.0f + ((gridSize * 2) + gap) + gridSize;

    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;

    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeColumns &&
        adjMouseY <= offsetY && adjMouseY >= offsetY - gridSize) {
        int column = (adjMouseX - offsetX) / gridSize;
        colorGrid = column;
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
    for (; length < 5; length++)
        if (grid.GetRows() == grid._rowsSize[length]) break;
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

void changeSimulationSpeed(int mouseX, int mouseY) {
    int resize[6] = {1, 2, 3, 4, 5, 6};
    float size = window.GetWidth() * 0.02;
    float gap = window.GetHeight() * 0.04;
    int length = 0;
    for (; length < 6; length++)
        if (speed == speeds[length]) break;
    int index = (length + 1) % 6;
    float sizeHeight = size * resize[index];
    float sizeWidth = size;
    float offsetX = gap;
    float offsetY = 10 + window.GetHeight();
    float adjMouseX = (float)mouseX;
    float adjMouseY = window.GetHeight() - (float)mouseY;
    if (adjMouseX >= offsetX && adjMouseX <= offsetX + sizeWidth &&
        adjMouseY >= offsetY && adjMouseY <= offsetY + size * grid.gridSize[length])
        processor.ChangeSimulationSpeed();
}

void mouseEvent(int button, int state, int mouseX, int mouseY) {
    if (!processor._SimulationProgram() && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        selectGrid(mouseX, mouseY);
        resizeColumnsGrid(mouseX, mouseY);
        resizeRowsGrid(mouseX, mouseY);
        changeSimulationSpeed(mouseX, mouseY);
        selectSquareColor(mouseX, mouseY);
        selectGridColor(mouseX, mouseY);
        glutPostRedisplay();
    }
}