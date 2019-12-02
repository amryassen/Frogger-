//
//  create.h
//  Frogger
//
//  Created by Kristine Laranjo on 5/3/16.
//  Copyright © 2016 Kristine Laranjo. All rights reserved.
//

#ifndef CREATE_H
#define CREATE_H
#include "object.h"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using namespace std;

class Create : public sf::Sprite
{
    protected:
        int left, top, width, height;
        double posX, posY, sizeX, sizeY;
    public:
        Create(sf::Sprite &sprite, sf::IntRect &rect, sf::Texture &texture, int left, int top, int width,
               int height, double sizeX, double sizeY, double posX, double posY);
        void setLeft(int left) {this->left = left;}
        void setTop(int top) {this->top = top;}
        void setWidth(int width) {this->width = width;}
        void setHeight(int height) {this->height = height;}
        void setSizeX(double sizeX) {this->sizeX = sizeX;}
        void setSizeY(double sizeY) {this->sizeY = sizeY;}
        int getLeft() const {return left;}
        int getTop() const {return top;}
        int getWidth() const {return width;}
        int getHeight() const {return height;}
        double getSizeX() const {return sizeX;}
        double getSizeY() const {return  sizeY;}
};

#endif /* CREATE_H */
