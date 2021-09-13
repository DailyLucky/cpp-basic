#include "Rect.h"

int Rect::GetArea() {
    int length = (x0>x1) ? (x0-x1) : (x1-x0);
    int width = (y0>y1) ? (y0-y1) : (y1-y0);
    return length*width;
}