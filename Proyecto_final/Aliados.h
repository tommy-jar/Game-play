#pragma once
#include"Character.h"
#include"Lider.h"
#include"Habitantes.h"


class Aliados : public Character {
private:
	int index;
	int hp;

public:
	Aliados(int width, int height, int index) : Character(width, height) {
		this->index = index;
		idy = idx = 4;
		dx = dy = 3;
		x = 770;
		y = 10;
		
	}

	~Aliados() {}


	void draw(Graphics^ g, Bitmap^ bmp) {

		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);

		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);

		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

	}
	void move(Graphics^ g, Habitantes* habitantes) {
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

		case 2:
			if (x == habitantes->getX()) {
				x += 0;
			}
			else if (x > habitantes->getX()) {
				x -= dx;
				idy = 1;
			}
			else if (x < habitantes->getX()) {
				x += dx;
				idy = 2;
			}

			if (y == habitantes->getY()) {
				y += 0;
			}
			else if (y > habitantes->getY()) {
				y -= dy;
				idy = 3;
			}
			else if (y < habitantes->getY()) {
				y += dy;
			}
		}


		idx++;
		if (idx > 3)idx = 0;
	}
	int getIndex() { return index; }


	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.04, height * 0.04);
	}

	int getXWidth() { return x + width * 0.04; }
	int getYHeight() { return y + height * 0.04; }


	int gethp() { return hp; }
	void loseHp() { hp--; }
};

