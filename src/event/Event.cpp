#include "./includes/Event.hpp"

void event() {
    glutMouseFunc(mouseEvent);
    glutKeyboardFunc(keyBoardEvent);
}