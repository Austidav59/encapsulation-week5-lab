/***********************************************************************
* Source File:
*    LANDER
* Author:
*    Br. Helfrich
* Summary:
*    All the information about the lunar lander
************************************************************************/
#include "lander.h"
#include <cmath>

Lander::Lander(const Position& posUpperRight) : status(DEAD), fuel(-99.0)
{
    reset(posUpperRight);
}

void Lander::reset(const Position& posUpperRight)
{
    status = PLAYING;
    fuel = 5000.0;
    angle.setDegrees(90);
    velocity.setDX(random(-10.0, -4.0));
    velocity.setDY(random(-2.0, 2.0));
    pos.setX(posUpperRight.getX() - 1);
    pos.setY(random(posUpperRight.getY() * 0.75, posUpperRight.getY() * 0.95));
}

void Lander::land()
{
    status = SAFE;
    angle.setDegrees(0);
}

void Lander::crash()
{
    status = DEAD;
    angle.setDegrees(180);
}

void Lander::draw(const Thrust& thrust, ogstream& gout) const
{
    gout.drawLander(pos, angle.getRadians());
    gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), thrust.isCounter(), thrust.isClock());
}

Acceleration Lander::input(const Thrust& thrust, double gravity)
{
    Acceleration acceleration;
    
    if (thrust.isMain() && fuel > 0)
    {
        double thrustForce = thrust.mainEngineThrust();
        acceleration.setDDY(thrustForce * cos(angle.getRadians()));
        acceleration.setDDX(thrustForce * sin(angle.getRadians()));
        fuel -= 1;
    }
    
    acceleration.setDDY(acceleration.getDDY() - gravity);
    
    angle.add(thrust.rotation());
    
    return acceleration;
}

void Lander::coast(Acceleration& acceleration, double time)
{
    velocity.add(acceleration, time);
    pos.addX(velocity.getDX() * time);
    pos.addY(velocity.getDY() * time);
}
