#include "Window.hpp"

#ifndef GRID_HPP
#define GRID_HPP

class Grid {
  public:
    int _rows = 10;
    int _columns = 10;
    bool _active[10][10] = {false};
    Grid() = default;
	int SetGrid(int rows, int columns) { return _rows = rows, _columns = columns; };
	int GetColumns() { return _columns; };
	int GetRows() { return _rows; };
    void DrawUnitGrid(float x, float y, float size, bool filled);
    void DrawGrid();
};

#endif
