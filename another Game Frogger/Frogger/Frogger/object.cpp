
#include "ResourcePath.hpp"
#include "object.h"
using namespace std;

Object::Object(double posX, double posY, double speed)
{
    this->speed = speed;
    this->posX = posX;
    this->posY = posY;
}
void Object::moveRight(sf::Sprite &obj)
{
    sf::Vector2f position = obj.getPosition();
    if (position.x >= 799)
    {
        setPosX(-150);
        setPosY(position.y);
        obj.setPosition(posX, posY);
        obj.move(speed, 0);
    }
    else
        obj.move(speed, 0);
}
void Object::moveLeft(sf::Sprite &obj)
{
    sf::Vector2f position = obj.getPosition();
    if (position.x <= -170)
    {
        setPosX(799);
        setPosY(position.y);
        obj.setPosition(posX, posY);
        obj.move(-speed, 0);
    }
    else
        obj.move(-speed, 0);
}
void Object::setPosX(double posX)
{
    this->posX = posX;
}
void Object::setPosY(double posY)
{
    this->posY = posY;
}
void Object::setSpeed(double speed)
{
    this->speed = speed;
}
