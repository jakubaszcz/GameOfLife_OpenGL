#include "Window.hpp"
#include <vector>
#ifndef GRID_HPP
#define GRID_HPP

class Grid {
  public:
    int _rows = 25;
    int _columns = 25;
    int _height, _width;
    int _columnsSize[5] = {5, 10, 15, 20, 25};
    int _rowsSize[5] = {5, 10, 15, 20, 25};
    int gridSize[5] = {1, 2, 3, 4, 5};
    float _size = 0.02;
    bool **_active = nullptr;
    Grid() { ResizeGrid(_columns, _rows); };
    ~Grid() { DeleteGrid(); };
	int SetGrid(int rows, int columns) { return _rows = rows, _columns = columns; };
	int GetColumns() const { return _columns; };
	int GetRows() const { return _rows; };
    int GetHeight() const { return _height; };
    int GetWidth() const { return _width; };
    float GetSize() const { return _size; };
    void ResizeGrid(int columns, int rows);
    void DeleteGrid();
    void DrawUnitGrid(float x, float y, float size, bool filled);
    void SwitchUnitState(int x, int y) { _active[x][y] = !_active[x][y]; };
    int CountNeighbours(int x, int y);
    void DrawGrid();
};

#endif
