#include <iostream>

#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
  public:
    Command() = default;
    void Simulation() { std::cout << "Simulation" << std::endl; };
};

#endif //COMMAND_HPP
