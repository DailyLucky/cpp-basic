#pragma once

class Rect {
public:
    void SetAllPoint(int _x0=0, int _y0=0, int _x1=0, int _y1=0) {
        x0 = _x0; y0 = _y0; x1 = _x1; y1 = _y1;
    }
    int GetX0() {
        return x0;
    }
    int GetY0() {
        return y0;
    }
    int GetX1() {
        return x1;
    }
    int GetY1() {
        return y1;
    }
    int GetArea(); 
    
private:
    int x0;
    int y0;
    int x1;
    int y1;
};