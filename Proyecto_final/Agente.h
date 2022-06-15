#pragma once
#include "Character.h"
#include"Aliados.h"
#include "Lider.h"

class Agente : public Character {
private:
	int index;

public:
	Agente(int width, int height, int index) : Character(width, height) {
		this->index = index;
		dx = dy = 3;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
	}

	~Agente() {}


	void move(Graphics^ g) {
		switch (index)
		{
		case 0: //Horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;

		case 1: //Vertical
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)dy *= -1;
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 3;
			}
			y += dy;
			break;
		/*
		case 2:

			if (x == aliados->getX()) {
				x += 0;
			}
			else if (x > aliados->getX()) {
				x -= dx;
				idy = 1;
			}
			else if (x < aliados->getX()) {
				x += dx;
				idy = 2;
			}

			if (y == aliados->getY()) {
				y += 0;
			}
			else if (y > aliados->getY()) {
				y -= dy;
				idy = 3;
			}
			else if (y < aliados->getY()) {
				y += dy;
			}
			break;
			*/
		}
		

		idx++;
		if (idx > 3)idx = 0;
	}
	int getIndex() { return index; }
};
