#include "../class/Command.hpp"
#include "Extern.hpp"

Window window;
Grid grid;
Command command;
Processor processor;
std::map<unsigned char, std::function<void()>> keys {
        {'g', []() { command.Simulation(); }},
        {'q', []() { command.Quit(); }}
};