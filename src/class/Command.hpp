#include <iostream>

#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
  public:
    Command() = default;
    void Simulation();
    void Quit();
    void Forward();
    void Backward();
    void SizeColumns();
    void SizeRows();
    void Reset();
};

#endif //COMMAND_HPP
