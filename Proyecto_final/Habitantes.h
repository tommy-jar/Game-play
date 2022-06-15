#pragma once
#include "Character.h"
#include"Aliados.h"
#include "Lider.h"

class Habitantes : public Character {
private:

public:
	Habitantes(int width, int height) : Character(width, height) {
		x = rand() % 65 * 10;
		y = 370;
	}

	~Habitantes() {}

	void move() {}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.04, height * 0.04);
	}

	int getXWidth() { return x + width * 0.04; }
	int getYHeight() { return y + height * 0.04; }
	
};