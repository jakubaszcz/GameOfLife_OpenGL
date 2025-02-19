#include "../class/Processor.hpp"
#include "../extern/Extern.hpp"

void Processor::ChangeSimulationSpeed() {
    int length = 0;
    for (; length < 6; length++)
      if (speeds[length] == speed) break;
    int index = (length + 1) % 6;
    speed = speeds[index];
}