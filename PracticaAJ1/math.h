#ifndef MATH_H
#define MATH_H

#include "rect.h"

double Distance(double x1, double y1, double x2, double y2);
bool PointInRect(double x, double y, double rectx, double recty, double width, double height);
void ClosestPointToRect(double x, double y, double rectx, double recty, double width, double height, double* outx, double* outy);
bool CircleToRect(double cx, double cy, double cr, double rx, double ry, double rw, double rh);
bool rectOverlap(Rect A, Rect B);
bool valueInRange(float value, float min, float max);

#endif
