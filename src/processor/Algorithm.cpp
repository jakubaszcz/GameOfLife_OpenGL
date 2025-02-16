#include "../class/Processor.hpp"
#include "../extern/Extern.hpp"
#include "../../Main.hpp"
#include <thread>
#include <chrono>


bool TurnCellDead(int x, int y) {
    int cels = grid.CountNeighbours(x, y);

    if (cels < 2) return true;
    else if (cels == 2 || cels == 3) return false;
    else return true;
}

bool TurnCellAlive(int x, int y) {
    int cels = grid.CountNeighbours(x, y);

    if (cels == 3) return true;
    else return false;
}

void CoreAlgorithm() {
    for (int i = 0; i < grid.GetColumns(); i++) {
      for (int j = 0; j < grid.GetRows(); j++) {
        if (grid._active[i][j]) {
            if (TurnCellDead(i, j)) {
                grid.SwitchUnitState(i, j);
            }
        } else {
            if (TurnCellAlive(i, j)) {
                grid.SwitchUnitState(i, j);
            }
        }
      }
    }
}

void Processor::Simulation() {
  if (_SimulationProgram()) {
        CoreAlgorithm();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

