#include "../Main.hpp"

void Window::updateWindowSize(int width, int height) {
  _width = width;
  _height = height;
  glViewport(0, 0, width, height);
}