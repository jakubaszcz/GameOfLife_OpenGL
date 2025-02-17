#include "./extern/Extern.hpp"
#include "./class/Command.hpp"


void Command::Simulation() { processor.ToggleSimulation(); }
void Command::Quit() { processor.OnProgramQuit(); }
void Command::Forward() {};
void Command::Backward() {};
void Command::Reset() {
    for (int i = 0; i < grid.GetColumns(); i++) {
      for (int j = 0; j < grid.GetRows(); j++) {
        grid._active[i][j] = false;
      }
    }
};
