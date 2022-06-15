#pragma once
#include "Character.h"

class Lider : public Character {
	int direction;
	int hp;
public:
	Lider(int width, int height) : Character(width, height) {
		dx = dy = 15;
		x = 455;
		y = 10;
		this->hp=10;
	}

	~Lider() {}

	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
		}

		idx++;
		if (idx > 3)idx = 0;
	}
	char getDirection() { return direction; }

	int gethp() {
		return hp;
	}
	void loseHP() {
		hp = hp - 4;
		hp--;
	}
	void towinHp() {
		hp = hp + 9;
		hp++;
	}
};