/***********************************************************************
* Header File:
*    Thrust : Represents activation of thrusters
* Author:
*    Br. Helfrich
* Summary:
*    down, clockwise, and counterclockwise
************************************************************************/
 
#pragma once
 
#include "uiInteract.h"  // for Interface
 
class TestLander;
class TestThrust;
 
/*****************************************************
  * THRUST
  * Represents activation of thrusters
  *****************************************************/
class Thrust
{
   friend TestLander;
   friend TestThrust;
public:
   Thrust(bool mainEngine = false, bool clockwise = false, bool counterClockwise = false)
      : mainEngine(mainEngine), clockwise(clockwise), counterClockwise(counterClockwise) {}
 
   // Get rotation in radians per second
   double rotation() const {
      if (clockwise && counterClockwise)
         return 0.0;
      if (clockwise)
         return 0.1;
      else if (counterClockwise)
         return -0.1;
      else
         return 0.0;
   }
 
   // get main engine thrust in  m / s ^ 2
   double mainEngineThrust() const {
      const double force = 45000.0; // Newtons
      const double mass = 15103.0;  // Kilograms
      return mainEngine ? (force / mass) : 0.0;
   }
 
   // reflect what is firing
   bool isMain()    const { return mainEngine; }
   bool isClock()   const { return clockwise; }
   bool isCounter() const { return counterClockwise; }
 
   // set the thrusters
   void set(const Interface * pUI) {
      mainEngine = pUI->isDown();
 
      clockwise = pUI->isLeft();
      counterClockwise = pUI->isRight();
   }
 
private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
};
