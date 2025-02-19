#include "./extern/Extern.hpp"
#include "./class/Command.hpp"
#include "./class/Processor.hpp"
#include "../Main.hpp"


void Command::Simulation() { processor.ToggleSimulation(); }
void Command::Quit() { processor.OnProgramQuit(); }
void Command::Forward() {};
void Command::Backward() {};
void Command::SizeColumns() {
    if (processor._SimulationProgram()) return;
    int length = 0;
    for (; length < 5; length++) {
        if (grid.GetColumns() == grid._columnsSize[length]) break;
    }
    int index = (length + 1) % 5;
    grid.ResizeGrid(grid._columnsSize[index], grid.GetRows());
    glutPostRedisplay();
}
void Command::SizeRows() {
    if (processor._SimulationProgram()) return;
    int length = 0;
    for (; length < 5; length++) {
        if (grid.GetRows() == grid._rowsSize[length]) break;
    }
    int index = (length + 1) % 5;
    grid.ResizeGrid(grid.GetColumns(), grid._rowsSize[index]);
    glutPostRedisplay();
}
void Command::Reset() {
    for (int i = 0; i < grid.GetColumns(); i++) {
      for (int j = 0; j < grid.GetRows(); j++) {
        grid._active[i][j] = false;
      }
    }
};
