#include "./includes/Event.hpp"
#include "../extern/Extern.hpp"
#include <random>
#include <iostream>

void mouseEvent(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

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
                glutPostRedisplay();
            }
        }
}