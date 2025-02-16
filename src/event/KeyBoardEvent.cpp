#include "../class/Command.hpp"
#include "../extern/Extern.hpp"
#include "./includes/Event.hpp"
#include <iostream>

void keyBoardEvent(unsigned char key, int x, int y) {
    (void)x; (void)y;
    auto command = keys.find(key);
    if (command != keys.end()) {
      command->second();
    }
}