#include <iostream>

#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
  public:
    Command() = default;
    void Simulation();
    void Quit();
};

#endif //COMMAND_HPP
