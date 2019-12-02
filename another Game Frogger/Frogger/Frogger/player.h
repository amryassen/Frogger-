#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
using namespace std;

class Player
{
protected:
    string playerName;
    int numLives;
    bool isHit;
    
public:
    Player();
    Player(string playerName, int numLives, bool isHit);
    void setPlayerName(string playerName);
    void setNumLives(int numLives);
    void setIsHit(bool isHit);
    
    string getPlayerName() {return playerName;}
    int getNumLives() { return numLives; }
    bool getIsHit() { return isHit; }
    
    
    
    
};
#endif