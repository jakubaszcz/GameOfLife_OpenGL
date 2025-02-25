#include "../class/Grid.hpp"
#include "../class/Window.hpp"
#include "../class/Command.hpp"
#include "../class/Processor.hpp"
#include "../class/Draw.hpp"
#include <map>
#include <functional>

#ifndef EXTERN_HPP
#define EXTERN_HPP

extern Window window;
extern Grid grid;
extern Command command;
extern Processor processor;
extern Draw draw;
extern int speeds[];
extern int speed;
extern int colorSquare;
extern int colorGrid;
extern std::map<unsigned char, std::function<void()>> keys;

#endif //EXTERN_HPP
