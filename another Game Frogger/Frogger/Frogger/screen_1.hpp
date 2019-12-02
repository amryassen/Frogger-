#include <iostream>
#include "cScreen.hpp"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include "player.h"
#include <SFML/Audio.hpp>
#include "create.h"
#include "points.h"
class screen_1 : public cScreen
{
private:
    //sf::RectangleShape Rectangle;
    sf::Sprite river;
    sf::Sprite frogger;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::IntRect rectSourceSprite;
    sf::IntRect rectSource;
    sf::Sprite background;
    sf::Texture bg;
    sf::Sprite truck;
    sf::Sprite truck2;
    sf::Sprite car;
    sf::Sprite car2;
    sf::Sprite car3;
    
    // Logs
    sf::Sprite shortLog;
    sf::Sprite shortLog2;
    sf::Sprite shortLog3;
    sf::Sprite longLog;
    sf::Sprite longLog2;
    
    // Lilypads
    sf::Sprite lillypad;
    sf::Sprite lillypad2;
    sf::Sprite lillypad3;
    sf::Sprite lillypad4;
    sf::Sprite lillypad5;
    
    sf::Sprite life;
    sf::Sprite death;
    sf::Sprite occupied1;
    sf::Sprite occupied2;
    sf::Sprite occupied3;
    sf::Sprite occupied4;
    sf::Sprite occupied5;
    
    // Lives
    sf::Texture hearts;
    
    // Frog for Lilypad
    sf::Texture oneFrog;
    
    bool frogOnLily1 = false;
    bool frogOnLily2 = false;
    bool frogOnLily3 = false;
    bool frogOnLily4 = false;
    bool frogOnLily5 = false;
    
    // Timer
    sf::Sprite timer;
    sf::IntRect timeRect;
    sf::Texture texture3;
    
    // Player
    Player mainPlayer;
    
    // Log booleans
    bool isOnLog;
    bool isOnLog2;
    bool isOnLog3;
    bool isOnLog4;
    bool isOnLog5;
    
    // Lilypad booleans
    bool isOnLily;
    bool isOnLily2;
    bool isOnLily3;
    bool isOnLily4;
    bool isOnLily5;
    
    // Frog booleans
    bool froggerLanded;
    
    // Lives
    int lives;
    
    // Sound
    sf::SoundBuffer hopFile;
    sf::Sound hop;
    
    sf::SoundBuffer truckedFile;
    sf::Sound trucked;
    
    sf::SoundBuffer dunkedFile;
    sf::Sound dunked;
    
    // Music
    sf::Music intro;
    sf::Music froggerTheme;
    
public:
	screen_1(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
    // Loads in spritesheet
    texture1.loadFromFile( resourcePath() + "spritesheet.png");
    texture2.loadFromFile( resourcePath() + "vehicles.png");
    texture3.loadFromFile( resourcePath() + "timer.png" );
    hearts.loadFromFile( resourcePath() + "hearts.png");
    
    // *******************************************************************
    // Sets texture to sprites, scale, and pos
    //
    // Create(sf::Sprite &sprite, sf::IntRect &rect, sf::Texture &texture, int left, int top, int width,
    //          int height, double sizeX, double sizeY, double posX, double posY)
    // *******************************************************************
    Create t1(truck, rectSourceSprite, texture2, 0, 24, 130, 73, 1.5, 1.5, 130, 420);
    Create t2(truck2, rectSourceSprite, texture2, 148, 0, 120, 159, 1.5, 1.5, 550, 290);
    Create c1(car, rectSourceSprite, texture2, 310, 0, 146, 149, 1.7, 1.7, -230, 420);
    Create c2(car2, rectSourceSprite, texture2, 460, 0, 146, 149, 1.7, 1.7, 280, 289);
    Create c3(car3, rectSourceSprite, texture2, 460, 0, 146, 149, 1.7, 1.7, 0, 289);
    Create s1(shortLog, rectSourceSprite, texture1, 289, 0, 146, 196, 1, 1, 0, 129);
    Create s2(shortLog2, rectSourceSprite, texture1, 435, 0, 141, 196, 1, 1, 200, 65);
    Create s3(shortLog3, rectSourceSprite, texture1, 289, 0, 146, 196, 1, 1, 300, 8);
    Create l1(longLog, rectSourceSprite, texture1, 577, 0, 205, 196, 1, 1, 799, 8.3);
    Create l2(longLog2, rectSourceSprite, texture1, 577, 0, 205, 196, 1, 1, 500, 138);
    Create leaf(lillypad, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 0, -32);
    Create leaf2(lillypad2, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 167.5, -32);
    Create leaf3(lillypad3, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 335, -32);
    Create leaf4(lillypad4, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 502.5, -32);
    Create leaf5(lillypad5, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 670, -32);

    Create hearts123(life, rectSource, hearts, 0, 0, 116, 30, 1, 1, 10, 600);
    
    //Player ( aka stats )
    mainPlayer.setNumLives(3);
    mainPlayer.setIsHit(false);
    
    // Frogger Sprite
    Create grogger(frogger, rectSourceSprite, texture1, 0, 70, 75, 70, 1, 1, 320, 605);

    // Sets texture to frogs that will go on occupied lilypads
    occupied1.setTexture(texture1);
    occupied1.setTextureRect(rectSourceSprite);
    occupied2.setTexture(texture1);
    occupied2.setTextureRect(rectSourceSprite);
    occupied3.setTexture(texture1);
    occupied3.setTextureRect(rectSourceSprite);
    occupied4.setTexture(texture1);
    occupied4.setTextureRect(rectSourceSprite);
    occupied5.setTexture(texture1);
    occupied5.setTextureRect(rectSourceSprite);
    
    // Sets pos of above frogs
    occupied1.setPosition(-100, -100);
    occupied2.setPosition(-100, -100);
    occupied3.setPosition(-100, -100);
    occupied4.setPosition(-100, -100);
    occupied5.setPosition(-100, -100);
    death.setPosition(-100, -100);
    
    // Timer Rect
    timeRect.left = 297;
    timeRect.top = 43;
    timeRect.width = 143;
    timeRect.height = 14;
    timer.setScale(1.5, 1.5);
    timer.setTexture(texture3, true);
    timer.setTextureRect(timeRect);
    timer.setPosition(10, 648);
    
    // Loads Background Pic
    bg.loadFromFile( resourcePath() + "background.jpg" );
    background.setTexture(bg, true);
    
    // Log Checking
    isOnLog = false;
    isOnLog2 = false;
    isOnLog3 = false;
    isOnLog4 = false;
    isOnLog5 = false;
    
    // Lily Checking
    isOnLily = false;
    isOnLily2 = false;
    isOnLily3 = false;
    isOnLily4 = false;
    isOnLily5 = false;
    
    froggerLanded = false;
    
    // Frogger Theme
    if (!froggerTheme.openFromFile(resourcePath() + "froggerLeche_Remix.ogg"))
        return -1; // error
    froggerTheme.setLoop(true);
    
    // Hop Sound
    if (!hopFile.loadFromFile(resourcePath() + "froggerHop.ogg"))
        return -1;
    
    // Coin Sound
    if (!intro.openFromFile(resourcePath() + "froggerCoin.ogg"))
        return -1;
    
    // Trucked
    if (!truckedFile.loadFromFile(resourcePath() + "froggerTrucked.ogg"))
        return -1;
    
    // Dunked
    if (!dunkedFile.loadFromFile(resourcePath() + "froggerDunked.ogg"))
        return -1;
}

int screen_1::Run(sf::RenderWindow &App)
{
    hop.setBuffer(hopFile);
    trucked.setBuffer(truckedFile);
    dunked.setBuffer(dunkedFile);
    
    // Clock
    sf:: Clock clock;
    sf::Time time;
    sf::Time delay;
    
    // Plays Intro
    intro.play();
    delay = intro.getDuration();
    
    time = clock.getElapsedTime();
    // Music
    while ( clock.getElapsedTime() <= delay )
    {
        //cout << "NO";
    }
    froggerTheme.setVolume(50);
    froggerTheme.play();
    clock.restart();
    
    sf::Event Event;
    
    bool Running = true;
    int sum = 0;// for log testing purposes
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    int sum6 = 0;
    int sum7 = 0;
    int sum8 = 0;
    int sum9 = 0;
    int sum10 = 0;
    
    while (Running)
    {
        // Timer Rect and Clock
        double time = clock.getElapsedTime().asSeconds();
        
        if(time >= 1.5)
        {
            timeRect.width = timeRect.width - 2.383;
            timer.setTextureRect(timeRect);
            clock.restart();
        }
        
        if(timeRect.width <= 0)
        {
            frogOnLily1 = false;
            frogOnLily2 = false;
            frogOnLily3 = false;
            frogOnLily4 = false;
            frogOnLily5 = false;
            mainPlayer.setNumLives(3);
            rectSource.width = 115;
            life.setTextureRect(rectSource);
            occupied1.setPosition(-100, -100);
            occupied2.setPosition(-100, -100);
            occupied3.setPosition(-100, -100);
            occupied4.setPosition(-100, -100);
            occupied5.setPosition(-100, -100);
            froggerTheme.pause();
            clock.restart();
            timeRect.width = 143;
            timer.setTextureRect(timeRect);
            frogger.setPosition(320, 605);
            
            return 2;
        }
        // *********************************************************************
        // Creating the objects of Object class for continuous movement
        //
        // Object(double posX, double posY, double speed)
        // *********************************************************************
        // Trucks
        Object t1(130, 420,0.2 );
        Object t2(550, 290, 0.2);
        // Cars
        Object c1(-50, 420, 0.3);
        Object c2(280, 289, 0.2);
        Object c3(0, 289, 0.2);
        // Short Logs
        Object sl1(0, 125, 0.2);
        Object sl2(200, 61, 0.3);
        Object sl3(300, 8, 0.4);
        // Long Logs
        Object l1(799, 8.3, 0.4);
        Object l2(500, 125, 0.2);
        
        // Sets object's direction
        t1.moveRight(truck);
        t2.moveLeft(truck2);
        c1.moveRight(car);
        c2.moveLeft(car2);
        c3.moveLeft(car3);
        sl1.moveRight(shortLog);
        sl2.moveLeft(shortLog2);
        sl3.moveRight(shortLog3);
        l1.moveRight(longLog);
        l2.moveRight(longLog2);
        
        
        // *********************************************************************
        // The following rectangles are for collision detection
        // *********************************************************************
        // Frog
        sf::RectangleShape rect;
        
        // Trucks
        sf::RectangleShape rect2;
        sf::RectangleShape rect3;
        
        // Cars
        sf::RectangleShape rect4;
        sf::RectangleShape rect5;
        sf::RectangleShape rect6;
        
        // Short Logs
        sf::RectangleShape rect7;
        sf::RectangleShape rect8;
        sf::RectangleShape rect9;
        
        // Long Logs
        sf::RectangleShape rect10;
        sf::RectangleShape rect11;
        
        // River
        sf::RectangleShape rect12;
        
        // Lilypads
        sf::RectangleShape rect13;
        sf::RectangleShape rect14;
        sf::RectangleShape rect15;
        sf::RectangleShape rect16;
        sf::RectangleShape rect17;
        
        // *********************************************************************
        // Setting size of rectangles aka size(width, height)
        // *********************************************************************
        // Frog
        sf::Vector2f size(40, 40);
        
        // Truck
        sf::Vector2f size2(120, 70);
        sf::Vector2f size3(120, 70);
        sf::Vector2f size4(95, 70);
        
        // Cars
        sf::Vector2f size5(95, 70);
        sf::Vector2f size6(95, 70);
        
        // Short Logs
        sf::Vector2f size7(85, 35);
        sf::Vector2f size8(85, 35);
        sf::Vector2f size9(85, 35);
        
        // Long Log
        sf::Vector2f size10(135, 35);
        sf::Vector2f size11(135, 35);
        
        // River
        sf::Vector2f size12(800, 230);
        
        // Lilypads
        sf::Vector2f size13(60, 60);
        sf::Vector2f size14(60, 60);
        sf::Vector2f size15(60, 60);
        sf::Vector2f size16(60, 60);
        sf::Vector2f size17(60, 60);
        
        // *********************************************************************
        // Get pos of every object
        // *********************************************************************
        // Trucks
        sf::Vector2f objectPos = truck.getPosition();
        sf::Vector2f objectPos2 = truck2.getPosition();
        // Cars
        sf::Vector2f objectPos3 = car.getPosition();
        sf::Vector2f objectPos4 = car2.getPosition();
        sf::Vector2f objectPos5 = car3.getPosition();
        // Short Logs
        sf::Vector2f objectPos6 = shortLog.getPosition();
        sf::Vector2f objectPos7 = shortLog2.getPosition();
        sf::Vector2f objectPos8 = shortLog3.getPosition();
        // Long Logs
        sf::Vector2f objectPos9 = longLog.getPosition();
        sf::Vector2f objectPos10 = longLog2.getPosition();
        // Lilypad
        sf::Vector2f objectPos11 = lillypad.getPosition();
        sf::Vector2f objectPos12 = lillypad2.getPosition();
        sf::Vector2f objectPos13 = lillypad3.getPosition();
        sf::Vector2f objectPos14 = lillypad4.getPosition();
        sf::Vector2f objectPos15 = lillypad5.getPosition();
        
        // *********************************************************************
        // Sets boundary settings
        // *********************************************************************
        sf::Vector2f pos = frogger.getPosition();
        
        // Frog
        rect.setPosition(pos.x + 30 , pos.y +10);
        rect.setSize(size);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(5);
        
        // Trucks
        rect2.setPosition(objectPos.x + 40, objectPos.y + 20);
        rect2.setSize(size2);
        rect2.setFillColor(sf::Color::Transparent);
        rect2.setOutlineColor(sf::Color::Red);
        rect2.setOutlineThickness(5);
        
        rect3.setPosition(objectPos2.x + 40, objectPos2.y + 60);
        rect3.setSize(size3);
        rect3.setFillColor(sf::Color::Transparent);
        rect3.setOutlineColor(sf::Color::Red);
        rect3.setOutlineThickness(5);
        
        // Cars
        rect4.setPosition(objectPos3.x + 45, objectPos3.y + 70);
        rect4.setSize(size4);
        rect4.setFillColor(sf::Color::Transparent);
        rect4.setOutlineColor(sf::Color::Red);
        rect4.setOutlineThickness(5);
        
        rect5.setPosition(objectPos4.x + 50, objectPos4.y + 70);
        rect5.setSize(size5);
        rect5.setFillColor(sf::Color::Transparent);
        rect5.setOutlineColor(sf::Color::Red);
        rect5.setOutlineThickness(5);
        
        rect6.setPosition(objectPos5.x + 50, objectPos5.y + 70);
        rect6.setSize(size6);
        rect6.setFillColor(sf::Color::Transparent);
        rect6.setOutlineColor(sf::Color::Red);
        rect6.setOutlineThickness(5);
        
        // Short Logs
        rect7.setPosition(objectPos6.x + 30, objectPos6.y + 80);
        rect7.setSize(size7);
        rect7.setFillColor(sf::Color::Transparent);
        rect7.setOutlineColor(sf::Color::Red);
        rect7.setOutlineThickness(5);
        
        rect8.setPosition(objectPos7.x + 30, objectPos7.y + 80);
        rect8.setSize(size8);
        rect8.setFillColor(sf::Color::Transparent);
        rect8.setOutlineColor(sf::Color::Red);
        rect8.setOutlineThickness(5);
        
        rect9.setPosition(objectPos8.x + 30, objectPos8.y + 80);
        rect9.setSize(size9);
        rect9.setFillColor(sf::Color::Transparent);
        rect9.setOutlineColor(sf::Color::Red);
        rect9.setOutlineThickness(5);
        
        // Long Logs
        rect10.setPosition(objectPos9.x + 35, objectPos9.y + 70);
        rect10.setSize(size10);
        rect10.setFillColor(sf::Color::Transparent);
        rect10.setOutlineColor(sf::Color::Red);
        rect10.setOutlineThickness(5);
        
        rect11.setPosition(objectPos10.x + 35, objectPos10.y + 70);
        rect11.setSize(size11);
        rect11.setFillColor(sf::Color::Transparent);
        rect11.setOutlineColor(sf::Color::Red);
        rect11.setOutlineThickness(5);
        // River
        rect12.setPosition(0, 0);
        rect12.setSize(size12);
        rect12.setFillColor(sf::Color::Transparent);
        rect12.setOutlineColor(sf::Color::Red);
        rect12.setOutlineThickness(5);
        
        // Lilypads
        rect13.setPosition(objectPos11.x + 30, objectPos11.y+40);
        rect13.setSize(size13);
        rect13.setFillColor(sf::Color::Transparent);
        rect13.setOutlineColor(sf::Color::Red);
        rect13.setOutlineThickness(5);
        
        rect14.setPosition(objectPos12.x + 30 , objectPos12.y+40);
        rect14.setSize(size14);
        rect14.setFillColor(sf::Color::Transparent);
        rect14.setOutlineColor(sf::Color::Red);
        rect14.setOutlineThickness(5);
        
        rect15.setPosition(objectPos13.x + 30, objectPos13.y+40);
        rect15.setSize(size15);
        rect15.setFillColor(sf::Color::Transparent);
        rect15.setOutlineColor(sf::Color::Red);
        rect15.setOutlineThickness(5);
        
        rect16.setPosition(objectPos14.x + 30 , objectPos14.y+40);
        rect16.setSize(size16);
        rect16.setFillColor(sf::Color::Transparent);
        rect16.setOutlineColor(sf::Color::Red);
        rect16.setOutlineThickness(5);
        
        rect17.setPosition(objectPos15.x + 30 , objectPos15.y+40);
        rect17.setSize(size17);
        rect17.setFillColor(sf::Color::Transparent);
        rect17.setOutlineColor(sf::Color::Red);
        rect17.setOutlineThickness(5);
        
        // *********************************************************************
        // Frogger Hit Truck 1
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect2.getGlobalBounds()))
            
        {
            
            froggerTheme.pause();
            trucked.play();
            
            lives = mainPlayer.getNumLives();
            mainPlayer.setNumLives(lives - 1);
            mainPlayer.setIsHit(true);
            rectSource.width -= 38.3;
            life.setTextureRect(rectSource);
         
            froggerTheme.play();
            //death.setPosition(-100,-100);
        }
        // *********************************************************************
        // Frogger Hit Truck 2
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect3.getGlobalBounds()))
        {
            froggerTheme.pause();
            trucked.play();
            
            lives = mainPlayer.getNumLives();
            mainPlayer.setNumLives(lives - 1);
            mainPlayer.setIsHit(true);
            rectSource.width -= 38.3;
            life.setTextureRect(rectSource);
            
            sf::Vector2f pos = frogger.getPosition();
            death.setPosition(pos);
            
            froggerTheme.play();
            death.setPosition(-100,-100);
            
        }
        // *********************************************************************
        // Frogger Hit Car 1
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect4.getGlobalBounds()))
        {
            froggerTheme.pause();
            trucked.play();
            
            lives = mainPlayer.getNumLives();
            mainPlayer.setNumLives(lives - 1);
            mainPlayer.setIsHit(true);
            rectSource.width -= 38.3;
            life.setTextureRect(rectSource);
            
            sf::Vector2f pos = frogger.getPosition();
            death.setPosition(pos);
            
            froggerTheme.play();
            death.setPosition(-100,-100);
            
        }
        // *********************************************************************
        // Frogger Hit Car 2
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect5.getGlobalBounds()))
        {
            froggerTheme.pause();
            trucked.play();
            
            lives = mainPlayer.getNumLives();
            mainPlayer.setNumLives(lives - 1);
            mainPlayer.setIsHit(true);
            rectSource.width -= 38.3;
            life.setTextureRect(rectSource);
            
            sf::Vector2f pos = frogger.getPosition();
            death.setPosition(pos);
            
            froggerTheme.play();
            death.setPosition(-100,-100);
            
        }
        // *********************************************************************
        // Frogger Hit Car 3
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect6.getGlobalBounds()))
        {
            froggerTheme.pause();
            trucked.play();
            
            lives = mainPlayer.getNumLives();
            mainPlayer.setNumLives(lives - 1);
            mainPlayer.setIsHit(true);
            rectSource.width -= 38.3;
            life.setTextureRect(rectSource);
            
            sf::Vector2f pos = frogger.getPosition();
            death.setPosition(pos);
            
            froggerTheme.play();
            death.setPosition(-100,-100);
            
        }
        
        // *********************************************************************
        // Below this line will be log collision checking
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect7.getGlobalBounds()))
        {
            frogger.setPosition(objectPos6.x + 45 + sum2 , objectPos6.y + 80 + sum);
            isOnLog = true;
        }
        else
        {
            isOnLog = false;
            sum = 0;
            sum2 = 0;
        }
        
        if (rect.getGlobalBounds().intersects(rect8.getGlobalBounds()))
        {
            
            frogger.setPosition(objectPos7.x + 45 + sum4, objectPos7.y + 80 + sum3);
            isOnLog2 = true;
        }
        else
        {
            isOnLog2 = false;
            sum3 = 0;
            sum4 = 0;
        }
        if (rect.getGlobalBounds().intersects(rect9.getGlobalBounds()))
        {
            frogger.setPosition(objectPos8.x + 45+sum6, objectPos8.y + 80+sum5);
            isOnLog3 = true;
        }
        else
        {
            isOnLog3 = false;
            sum5 = 0;
            sum6 = 0;
            
        }
        if (rect.getGlobalBounds().intersects(rect10.getGlobalBounds()))
        {
            frogger.setPosition(objectPos9.x + 45 + sum8, objectPos9.y + 70+ sum7);
            isOnLog4 = true;
            
        }
        else
        {
            isOnLog4 = false;
            sum7 = 0;
            sum8 = 0;
        }
        if (rect.getGlobalBounds().intersects(rect11.getGlobalBounds()))
        {
            frogger.setPosition(objectPos10.x + 45+ sum10, objectPos10.y + 70+sum9);
            isOnLog5 = true;
        }
        else
        {
            isOnLog5 = false;
            sum9 = 0;
            sum10 = 0;
        }
        
        // *********************************************************************
        // Below this line will be lily collision checking
        // *********************************************************************
        if (rect.getGlobalBounds().intersects(rect13.getGlobalBounds()))
        {
            isOnLily = true;
            if (frogOnLily1 == false)
            {
                score += 50;
            }
            frogOnLily1 = true;
            sf::Vector2f lilyPos = rect13.getPosition();
            occupied1.setPosition(lilyPos);
            
        }
        if (rect.getGlobalBounds().intersects(rect14.getGlobalBounds()))
        {
            isOnLily = true;
            if (frogOnLily2 == false)
            {
                score += 50;
            }
            frogOnLily2 = true;
            sf::Vector2f lilyPos = rect14.getPosition();
            occupied2.setPosition(lilyPos);
        }
        if (rect.getGlobalBounds().intersects(rect15.getGlobalBounds()))
        {
            isOnLily = true;
            if (frogOnLily3 == false)
            {
                score += 50;
            }
            frogOnLily3 = true;
            sf::Vector2f lilyPos = rect15.getPosition();
            occupied3.setPosition(lilyPos);
            
        }
        if (rect.getGlobalBounds().intersects(rect16.getGlobalBounds()))
        {
            isOnLily = true;
            if (frogOnLily4 == false)
            {
                score += 50;
            }
            frogOnLily4 = true;
            sf::Vector2f lilyPos = rect16.getPosition();
            occupied4.setPosition(lilyPos);
        }
        if (rect.getGlobalBounds().intersects(rect17.getGlobalBounds()))
        {
            isOnLily = true;
            if (frogOnLily5 == false)
            {
                score += 50;
            }
            frogOnLily5 = true;
            sf::Vector2f lilyPos = rect17.getPosition();
            occupied5.setPosition(lilyPos);
        }
        
        // *********************************************************************
        // Checks if frogger is on log AND goes outside screen boundaries
        //  if so frogger dies
        // *********************************************************************
        sf::Vector2f location = frogger.getPosition();
        // Checks if frogger went out of bounds
        if (rect.getGlobalBounds().intersects(rect12.getGlobalBounds()))
        {
            if ((isOnLog || isOnLog2 || isOnLog3 || isOnLog4 || isOnLog5) && (location.x >= 740 || location.x < -40))
            {
                mainPlayer.setIsHit(true);
                lives = mainPlayer.getNumLives();
                mainPlayer.setNumLives(lives - 1);
                rectSource.width -= 38.3;
                life.setTextureRect(rectSource);
                
            }
        }
        // Checks if frogger is on the logs not the water
        if (rect.getGlobalBounds().intersects(rect12.getGlobalBounds()))
        {
            if (isOnLog || isOnLog2 || isOnLog3 || isOnLog4 || isOnLog5)
            {
                //this frogger is on the logs not the water
            }
            else
            {
                froggerTheme.pause();
                dunked.play();
                froggerTheme.play();
                mainPlayer.setIsHit(true);
                lives = mainPlayer.getNumLives();
                mainPlayer.setNumLives(lives - 1);
                rectSource.width -= 38.3;
                life.setTextureRect(rectSource);
            }
            
        }
        // Checks if the frog has landed on a lilypad
        if (isOnLily || isOnLily2 || isOnLily3 || isOnLily4 || isOnLily5)
        {
            // the frog has landed on the lily pad
            froggerLanded = true;
        }
        // *********************************************************************
        // Checks if the frog has landed on all 5 lilypads if so you win
        // *********************************************************************
        if (frogOnLily1 && frogOnLily2 && frogOnLily3 && frogOnLily4 && frogOnLily5)
        {
            score += 10000;
            
            frogOnLily1 = false;
            frogOnLily2 = false;
            frogOnLily3 = false;
            frogOnLily4 = false;
            frogOnLily5 = false;
            
            mainPlayer.setNumLives(3);
            rectSource.width = 115;
            life.setTextureRect(rectSource);
            occupied1.setPosition(-100, -100);
            occupied2.setPosition(-100, -100);
            occupied3.setPosition(-100, -100);
            occupied4.setPosition(-100, -100);
            occupied5.setPosition(-100, -100);
            froggerTheme.pause();
            clock.restart();
            timeRect.width = 143;
            timer.setTextureRect(timeRect);
            frogger.setPosition(320, 605);
            
            return 2;
        }
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            // *********************************************************************
            // LEFT
            // *********************************************************************
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                
                if (isOnLog)
                {
                    sum2 = (sum2 + (20 * -1));
                }
                if (isOnLog2)
                {
                    sum4 = (sum4 + (20 * -1));
                }
                if (isOnLog3)
                {
                    sum6 = (sum6 + (20 * -1));
                }
                if (isOnLog4)
                {
                    sum8 = (sum8 + (20 * -1));
                }
                if (isOnLog5)
                {
                    sum10 = (sum10 + (20 * -1));
                }
                
                
                sf::Vector2f pos = frogger.getPosition();
                
                
                if (pos.x < 0)
                {
                    frogger.move(0, 0);
                }
                else
                {
                    if (rectSourceSprite.left != 216)
                    {
                        rectSourceSprite.left = 216;
                        rectSourceSprite.width = 55;
                        frogger.setTextureRect(rectSourceSprite);
                    }
                    score += 10;
                    froggerTheme.setVolume(0);
                    hop.play();
                    frogger.move(-40, 0);
                    froggerTheme.setVolume(50);
                    
                }
            }
            // *********************************************************************
            // RIGHT
            // *********************************************************************
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (isOnLog)
                {
                    sum2 = (sum2 + (20));
                }
                if (isOnLog2)
                {
                    sum4 = (sum4 + (20));
                }
                if (isOnLog3)
                {
                    sum6 = (sum6 + (20));
                }
                if (isOnLog4)
                {
                    sum8 = (sum8 + (20));
                }
                if (isOnLog5)
                {
                    sum10 = (sum10 + (20));
                }
                
                sf::Vector2f pos = frogger.getPosition();
                
                if (pos.x >= 640)
                {
                    frogger.move(0, 0);
                }
                else
                {
                    if (rectSourceSprite.left != 89)
                    {
                        rectSourceSprite.left = 89;
                        rectSourceSprite.width = 60;
                        frogger.setTextureRect(rectSourceSprite);
                    }
                    score += 10;
                    froggerTheme.setVolume(0);
                    hop.play();
                    frogger.move(40, 0);
                    froggerTheme.setVolume(50);
                }
            }
            // *********************************************************************
            // UP
            // *********************************************************************
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                
                
                if (isOnLog)
                {
                    sum = (sum + (20 * -1));
                }
                
                if (isOnLog2)
                {
                    sum3 = (sum3 + (20 * -1));
                }
                if (isOnLog3)
                {
                    sum5 = (sum5 + (20 * -1));
                }
                if (isOnLog4)
                {
                    sum7 = (sum7 + (20 * -1));
                }
                if (isOnLog5)
                {
                    sum9 = (sum9 + (20 * -1));
                }
                
                
                if (pos.y <= -35)
                {
                    frogger.move(0, 0);
                }
                else
                {
                    if (rectSourceSprite.left != 0)
                    {
                        rectSourceSprite.left = 0;
                        rectSourceSprite.width = 89;
                        frogger.setTextureRect(rectSourceSprite);
                    }
                    score += 10;
                    froggerTheme.setVolume(0);
                    hop.play();
                    frogger.move(0, -40);
                    froggerTheme.setVolume(50);
                }
            }
            // *********************************************************************
            // DOWN
            // *********************************************************************
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                
                
                if (isOnLog)
                {
                    sum = (sum + 20);
                }
                
                if (isOnLog2)
                {
                    sum3 = (sum3 + 20);
                }
                if (isOnLog3)
                {
                    sum5 = (sum5 + 20);
                }
                
                if (isOnLog4)
                {
                    sum7 = (sum7 + 20);
                }
                if (isOnLog5)
                {
                    sum9 = (sum9 + 20);
                }
                sf::Vector2f pos = frogger.getPosition();
                if (pos.y >= 650)
                {
                    frogger.move(0, 0);
                }
                else
                {
                    if (rectSourceSprite.left != 149)
                    {
                        rectSourceSprite.left = 149;
                        rectSourceSprite.width = 67;
                        frogger.setTextureRect(rectSourceSprite);
                    }
                    score += 10;
                    froggerTheme.setVolume(0);
                    hop.play();
                    frogger.move(0, 40);
                    froggerTheme.setVolume(50);
                }
            }
        }
        
        // *********************************************************************
        // Checks if player has been hit
        // *********************************************************************
        if (mainPlayer.getIsHit() == true)
        {
            cout << " Number of lives" << mainPlayer.getNumLives() << endl;
            mainPlayer.setIsHit(false);
            rectSourceSprite.left = 0;
            rectSourceSprite.width = 89;
            frogger.setTextureRect(rectSourceSprite);
            frogger.setPosition(320, 605);
        }
        // *********************************************************************
        // Checks if player landed on lily
        // *********************************************************************
        if (froggerLanded == true)
        {
            froggerLanded = false;
            rectSourceSprite.left = 0;
            rectSourceSprite.width = 89;
            frogger.setTextureRect(rectSourceSprite);
            frogger.setPosition(320, 605);
            isOnLily = false;
            isOnLily2 = false;
            isOnLily3 = false;
            isOnLily4 = false;
            isOnLily5 = false;
        }
        // *********************************************************************
        // Checks if player has run out of lives
        // *********************************************************************
        if (mainPlayer.getNumLives() < 1)
        {
            frogOnLily1 = false;
            frogOnLily2 = false;
            frogOnLily3 = false;
            frogOnLily4 = false;
            frogOnLily5 = false;
            mainPlayer.setNumLives(3);
            rectSource.width = 115;
            life.setTextureRect(rectSource);
            occupied1.setPosition(-100, -100);
            occupied2.setPosition(-100, -100);
            occupied3.setPosition(-100, -100);
            occupied4.setPosition(-100, -100);
            occupied5.setPosition(-100, -100);
            froggerTheme.pause();
            clock.restart();
            timeRect.width = 143;
            timer.setTextureRect(timeRect);
            frogger.setPosition(320, 605);
            
            return 2;
            
        }
        
        App.clear(sf::Color(0, 0, 0, 0));
        //Drawing
        App.draw(background);
        App.draw(car2);
        App.draw(car3);
        App.draw(truck2);
        App.draw(truck);
        App.draw(car);
        App.draw(longLog);
        App.draw(longLog2);
        App.draw(shortLog);
        App.draw(shortLog2);
        App.draw(shortLog3);
        App.draw(lillypad);
        App.draw(lillypad2);
        App.draw(lillypad3);
        App.draw(lillypad4);
        App.draw(lillypad5);
        App.draw(life);
        App.draw(timer);
        App.draw(frogger);
        App.draw(occupied1);
        App.draw(occupied2);
        App.draw(occupied3);
        App.draw(occupied4);
        App.draw(occupied5);

        // *********************************************************************
        // The following are for testing purposes only
        // Draws the boundary box
        // *********************************************************************
        App.draw(rect);
        App.draw(rect2);
        App.draw(rect3);
        App.draw(rect4);
        App.draw(rect5);
        App.draw(rect6);
        App.draw(rect7);
        App.draw(rect8);
        App.draw(rect9);
        App.draw(rect10);
        App.draw(rect11);
        App.draw(rect12);
        App.draw(rect13);
        App.draw(rect14);
        App.draw(rect15);
        App.draw(rect16);
        App.draw(rect17);
        
        App.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}