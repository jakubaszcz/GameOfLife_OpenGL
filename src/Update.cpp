#include "./extern/Extern.hpp"
#include "../Main.hpp"

void update() {
    processor.Simulation();
    glutPostRedisplay();
}