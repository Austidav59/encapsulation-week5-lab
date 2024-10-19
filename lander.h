/***********************************************************************
 * Header File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/
#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "thrust.h"
#include "uiDraw.h"

enum Status { PLAYING, SAFE, DEAD };

class TestLander;

class Lander
{
   friend TestLander;
   
public:
   // Constructor
   Lander(const Position & posUpperRight);

   // Getters
   bool isDead() const { return status == DEAD; }
   bool isLanded() const { return status == SAFE; }
   bool isFlying() const { return status == PLAYING; }
   Position getPosition() const { return pos; }
   double getSpeed() const { return velocity.getSpeed(); }
   int getFuel() const { return static_cast<int>(fuel); }
   int getWidth() const { return 20; }
   double getMaxSpeed() const { return 4.0; }

   // Setters
   void reset(const Position& posUpperRight);
   void land();
   void crash();

   // Draw the lander
   void draw(const Thrust & thrust, ogstream & gout) const;
 
   // Handle input and physics
   Acceleration input(const Thrust & thrust, double gravity);
   void coast(Acceleration & acceleration, double time);

private:
   Status status;
   Position pos;
   Velocity velocity;
   Angle angle;
   double fuel;
};
