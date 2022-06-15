#pragma once
#include "Character.h"
#include"Aliados.h"
#include "Lider.h"

class Comodin : public Character {
private:

public:
	Comodin(int width, int height) : Character(width, height) {
		x = rand() % 65 * 10;
		y = rand() % 40 * 10;
	}

	~Comodin() {}

	void move() {}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.04, height * 0.04);
	}

	int getXWidth() { return x + width * 0.04; }
	int getYHeight() { return y + height * 0.04; }

};