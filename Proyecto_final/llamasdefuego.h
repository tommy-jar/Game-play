#pragma once
#pragma once
#include "Character.h"

class Llamas : public Character {
private:
	int index;

public:
	Llamas(int width, int height, int index) : Character(width, height) {
		this->index = index;
		dx = dy = 3;
		x = 0;
		y = rand() % 35 * 10;
	}

	~Llamas() {}

	void move(Graphics^ g) {
		switch (index)
		{
		case 0: //Horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idy = 0;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;



		}


		idx++;
		if (idx > 3)idx = 0;
	}
	int getIndex() { return index; }
};
