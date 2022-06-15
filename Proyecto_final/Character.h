#pragma once
#include <iostream>

using namespace System::Drawing;

class Character {
protected:
	int x, y; //Coordinates
	int dx, dy; //Movement
	int width, height;
	int idx, idy; //Indexes
	bool visible;

public:
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
	}

	~Character() {}

	void draw(Graphics^ g, Bitmap^ bmp) {

		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);

		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);

		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move() {}


	int getX() { return x; }
	int getY() { return y; }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }

	void changeDxDirection() { dx *= -1; }

	void changeDyDirection() { dy *= -1; }
	
	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

};