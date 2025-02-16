#include "./extern/Extern.hpp"
#include "./class/Command.hpp"


void Command::Simulation() { processor.ToggleSimulation(); }
void Command::Quit() { processor.OnProgramQuit(); }
