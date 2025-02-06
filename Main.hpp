#include <GL/glut.h>
#include "./src/class/Window.hpp"

#include "./src/class/Grid.hpp"
#include "./src/extern/Extern.hpp"


#ifndef MAIN_HPP
    #define MAIN_HPP

void loop(int argc, char * argv[]);
void reshape(int width, int height);
void display();

#endif