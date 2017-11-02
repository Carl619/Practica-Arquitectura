#include "math.h"
#include <math.h>

double Distance(double x1, double y1, double x2, double y2) {
	double distancia = 0;
	distancia = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	distancia = sqrt(distancia);
	return distancia;
}

bool PointInRect(double x, double y, double rectx, double recty, double width, double height) {
	if (x > rectx && x < rectx + width)
		if (y > recty && y < recty + height)
			return true;
	return false;
}

void ClosestPointToRect(double x, double y, double rectx, double recty, double width, double height, double* outx, double* outy) {
	*outx = (x < rectx) ? rectx : (x > rectx+width) ? rectx+width : x;
	*outy = (y < recty) ? recty : (y > recty+height) ? recty+height : y;
}

bool CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh)
{
	double x = 0, y = 0, d = 0;
	if (PointInRect(cx + cr, cy + cr * 2, rx, ry, rw, rh))
		return true;
	ClosestPointToRect(cx + cr, cy + cr * 2, rx, ry, rw, rh, &x, &y);
	d = Distance(cx + cr, cy + cr*2, x, y);
	if (d < cr)
		return true;
	return false;
}

bool valueInRange(float value, float min, float max)
{
	return (value >= min) && (value <= max);
}

bool rectOverlap(Rect A, Rect B)
{
	bool xOverlap = valueInRange(A.getX() - A.getWidth() / 2, B.getX() - B.getWidth() / 2, B.getX() + B.getWidth()/2) ||
		valueInRange(B.getX() - B.getWidth() / 2, A.getX() - A.getWidth() / 2, A.getX() + A.getWidth()/2);

	bool yOverlap = valueInRange(A.getY() - A.getHeight() / 2, B.getY() - B.getHeight() / 2, B.getY() + B.getHeight()/2) ||
		valueInRange(B.getY() - B.getHeight() / 2, A.getY() - A.getHeight() / 2, A.getY() + A.getHeight()/2);

	return xOverlap && yOverlap;
}