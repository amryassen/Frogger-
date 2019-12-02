#pragma once
//
//  objects.h
//  Frogger
//
//  Created by Kristine Laranjo on 4/16/16.
//  Copyright � 2016 Kristine Laranjo. All rights reserved.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using namespace std;

class Object
{
protected:
    double posX, posY;
    double speed;
    
public:
    Object(double posX, double posY, double speed);
    void moveRight(sf::Sprite &obj);
    void moveLeft(sf::Sprite &obj);
    void setPosX(double posX);
    void setPosY(double posY);
    void setSpeed(double speed);
    double getPosX() const { return posX; }
    double getPosY() const { return posY; }
    double getSpeed() const { return speed; }
    // Get position for
};

#endif /* object_h */
