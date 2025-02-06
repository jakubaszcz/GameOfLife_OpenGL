#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
    public:
      int _width, _height;
      Window(int width = 800, int height = 600) : _width(width), _height(height) {};
      ~Window() = default;
      int GetWidth() const { return _width; }
      int GetHeight() const { return _height; }
      void UpdateWindowSize(int width, int height);
};

#endif
