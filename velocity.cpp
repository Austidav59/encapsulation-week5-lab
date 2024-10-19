/***********************************************************************
* Source File:
* VELOCITY
* Author:
* Br. Helfrich
* Summary:
* Everything we need to know about speed
************************************************************************/
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include <math.h> // for sqrt()


/*********************************************
* VELOCITY : ADD
* v = v_0 + a t
*********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
    // Add horizontal and vertical components of velocity based on acceleration and time
    dx += acceleration.getDDX() * time;
    dy += acceleration.getDDY() * time;
}


/*********************************************
* VELOCITY : SET
* set from angle and magnitude
*********************************************/
void Velocity::set(const Angle& angle, double magnitude)
{
    double radians = angle.getRadians();
    // Calculate dx and dy using the magnitude and angle
    dx = magnitude * sin(radians); // Horizontal component
    dy = magnitude * cos(radians); // Vertical component
}
