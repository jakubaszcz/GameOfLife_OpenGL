#include "../class/Command.hpp"
#include "Extern.hpp"

Window window;
Grid grid;
Command command;
Processor processor;
Draw draw;
int speeds[] = {0, 50, 100, 250, 500, 1000};
int speed = speeds[0];
int colorSquare = 6;
int colorGrid = 6;
std::map<unsigned char, std::function<void()>> keys {
        {'g', []() { command.Simulation(); }},
        {'q', []() { command.Quit(); }},
        {'r', []() { command.Reset(); }},
        {'a', []() { command.Backward(); }},
        {'e', []() { command.Forward(); }},
        {'p', []() { command.SizeColumns(); }},
        {'o', []() { command.SizeRows(); }},
        {'m', []() { command.UpSpeed(); }},
        {'l', []() { command.DownSpeed(); }}
};