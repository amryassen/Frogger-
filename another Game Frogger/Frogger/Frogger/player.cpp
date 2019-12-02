#include"player.h"
#include<iostream>
#include<string>
#include "ResourcePath.hpp"
using namespace std;

Player::Player()
{
    playerName = "player 1";
    numLives = 10;
    isHit = false;
    //cout << "this ran" << endl;
    
}

Player::Player(string playerName, int numLives, bool isHit)
{
    this->playerName = playerName;
    this->numLives = numLives;
    this->isHit = isHit;
    
}

void Player::setPlayerName(string playerName)
{
    this->playerName = playerName;
    
}
void Player::setNumLives(int numLives)
{
    this->numLives = numLives;
    
    
}
void Player::setIsHit(bool isHit)
{
    this->isHit = isHit;
    
    
}