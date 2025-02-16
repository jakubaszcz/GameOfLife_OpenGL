#include "../class/Processor.hpp"
#include "../extern/Extern.hpp"

void CoreAlgorithm() {
    for (int i = 0; i < grid.GetColumns(); i++) {
      for (int j = 0; j < grid.GetRows(); j++) {
        // Game of Life Algorithm
      }
    }
}

void Processor::Simulation() {
    if (_SimulationProgram())
        CoreAlgorithm();
}

