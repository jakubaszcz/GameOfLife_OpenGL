#include "../class/Command.hpp"
#include "Extern.hpp"

Window window;
Grid grid;
Command command;
Processor processor;
Draw draw;
std::map<unsigned char, std::function<void()>> keys {
        {'g', []() { command.Simulation(); }},
        {'q', []() { command.Quit(); }},
        {'r', []() { command.Reset(); }},
        {'a', []() { command.Backward(); }},
        {'e', []() { command.Forward(); }},
        {'p', []() { command.SizeColumns(); }},
        {'o', []() { command.SizeRows(); }},
};