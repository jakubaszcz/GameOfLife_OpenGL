#include "Window.hpp"

#ifndef GRID_HPP
#define GRID_HPP

class Grid {
  public:
    int _rows = 10;
    int _columns = 10;
    int _height, _width;
    float _size = 0.02;
    bool _active[10][10] = {false};
    Grid() = default;
	int SetGrid(int rows, int columns) { return _rows = rows, _columns = columns; };
	int GetColumns() const { return _columns; };
	int GetRows() const { return _rows; };
    int GetHeight() const { return _height; };
    int GetWidth() const { return _width; };
    float GetSize() const { return _size; };
    void DrawUnitGrid(float x, float y, float size, bool filled);
    void SwitchUnitState(int x, int y) { _active[x][y] = !_active[x][y]; };
    void DrawGrid();
};

#endif
