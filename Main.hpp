#include <GL/glut.h>
#include "./src/class/Window.hpp"

#include "./src/class/Grid.hpp"
#include "./src/extern/Extern.hpp"
#include "./src/event/includes/Event.hpp"
#include "./src/processor/include/Processor.hpp"


#ifndef MAIN_HPP
    #define MAIN_HPP

void loop(int argc, char * argv[]);
void update();
void reshape(int width, int height);
void display();

#endif