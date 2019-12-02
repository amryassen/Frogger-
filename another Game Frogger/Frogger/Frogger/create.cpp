//
//  create.cpp
//  Frogger
//
//  Created by Kristine Laranjo on 5/3/16.
//  Copyright © 2016 Kristine Laranjo. All rights reserved.
//
#include "ResourcePath.hpp"
#include "create.h"
using namespace std;

Create::Create(sf::Sprite &sprite, sf::IntRect &rect, sf::Texture &texture, int left, int top, int width,
               int height, double sizeX, double sizeY, double posX, double posY)
{
    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(sizeX, sizeY);
    sprite.setPosition(posX, posY);
}