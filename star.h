

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

/*****************************************************
* STAR
* A star that twinkles
*****************************************************/
class Star
{
public:
    Star() : pos(), phase(0) {}

    void reset(double width, double height) {
        pos.setX(random(0.0, width));
        pos.setY(random(0.0, height));
        phase = 0;
    }

    void draw(ogstream& gout) {
        gout.drawStar(pos, phase++);
    }

private:
    Position pos;
    unsigned char phase;
};
