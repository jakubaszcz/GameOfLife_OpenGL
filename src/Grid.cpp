#include "../Main.hpp"
#include <iostream>


void Grid::DrawGrid() {
	_active[8][6] = true;
	_active[4][6] = true;
	float size = 0.02;
	float padding = window.GetWidth() * size;
	for (int i = 0; i < GetColumns(); i++) {
          for (int j = 0; j < GetRows(); j++) {
            float x = i * padding - (GetRows() / 2.0) * padding;
            float y = j * padding - (GetColumns() / 2.0) * padding;
			DrawUnitGrid(x, y, size, (_active[i][j] ? true : false));
          }
	}
}

void Grid::DrawUnitGrid(float x, float y, float size, bool filled) {
  float resize = window.GetWidth() * size;
  float centerX = window.GetWidth() / 2 ;
  float centerY = window.GetHeight() / 2;
  if (filled) {
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(centerX - resize / 2 + x, centerY - resize / 2 + y);
	glVertex2f(centerX + resize / 2 + x, centerY - resize / 2 + y);
	glVertex2f(centerX + resize / 2 + x, centerY + resize / 2 + y);
	glVertex2f(centerX - resize / 2 + x, centerY + resize / 2 + y);
	glEnd();
  } else {
    glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(centerX - resize / 2 + x, centerY - resize / 2 + y);
	glVertex2f(centerX + resize / 2 + x, centerY - resize / 2 + y);

	glVertex2f(centerX + resize / 2 + x, centerY - resize / 2 + y);
	glVertex2f(centerX + resize / 2 + x, centerY + resize / 2 + y);

	glVertex2f(centerX + resize / 2 + x, centerY + resize / 2 + y);
	glVertex2f(centerX - resize / 2 + x, centerY + resize / 2 + y);

	glVertex2f(centerX - resize / 2 + x, centerY + resize / 2 + y);
	glVertex2f(centerX - resize / 2 + x, centerY - resize / 2 + y);
  glEnd();
  }
}

