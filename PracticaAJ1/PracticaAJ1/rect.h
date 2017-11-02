#pragma once

class Rect
{
public:
	Rect(float x, float y, float w, float h) { inix = x; iniy = y;
	width = w;
	height = h;
	}

	Rect() {
		inix = 0;
		iniy = 0;
		width = 0;
		height = 0;
	}
	void setX(float x) { inix = x; }
	void setY(float y) { iniy = y; }
	void setWidth(float w) { width = w; }
	void setHeight(float h) { height = h; }
	float getX() { return inix; }
	float getY() { return iniy; }
	float getWidth() { return width; }
	float getHeight() { return height; }

private:
	float inix;
	float iniy;
	float width;
	float height;
};

