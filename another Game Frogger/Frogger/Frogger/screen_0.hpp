#include"player.h"
#include <iostream>
#include "cScreen.hpp"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
// using inheritance to bring in variables and methods from the base class cScreen.
class screen_0 : public cScreen

{
private:
    
    bool playing;
public:
    screen_0(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_0::screen_0(void)
{
    
    playing = false;
}

int screen_0::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    
    sf::Font Font;
    sf::Text froggerTitle;
    sf::Text Menu1;
    sf::Text Menu2;
    sf::Text Menu3;
    sf::Text instructions;
    sf::Text pointTable;
    std::stringstream str1;
    std::stringstream str2;
    
    int menu = 0;
    // IF FILES DO NOT OPEN CORRECTLY OR IF THE FILES ARE NOT FOUND WITHIN THE DIRECTORY THEN WE WILL
    // AUTOMATICALLY EXIT THE GAME.
    /*
     if (!Texture.loadFromFile("background.jpg"))
     {
     std::cerr << "Error loading .png" << std::endl;
     return (-1);
     }
     */
    
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255));
    if (!Font.loadFromFile(resourcePath() + "PressStart2P.ttf"))
    {
        std::cerr << "Error loading .ttf" << std::endl;
        return (-1);
    }
    
    froggerTitle.setFont(Font);
    froggerTitle.setCharacterSize(110);
    froggerTitle.setString("FROGGER");
    froggerTitle.setPosition({ 30, 90 });
    froggerTitle.setColor(sf::Color::Green);
    
    str1<< "Object is to safely manuever frog\n"
        << " to its home within alloted time\n"
        << " \t~60 beats on the timer~\n\n";
    instructions.setFont(Font);
    instructions.setCharacterSize(20);
    instructions.setString( str1.str() );
    instructions.setPosition(55, 220);
    instructions.setColor(sf::Color::Red);
    
    str2<< "\n\t\t  -Point Table-\n\n"
        << "\t10 points for every step\n\n"
        << "\t50 points for every frog\n \tarrived home safely\n\n"
        << "\t1000 points for saving frogs\n \tinto five homes";
    pointTable.setFont(Font);
    pointTable.setCharacterSize(20);
    pointTable.setString( str2.str() );
    pointTable.setPosition(55, 290);
    
    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("PLAY");
    Menu1.setPosition({ 335, 540 });
    
    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setString("EXIT");
    Menu2.setPosition({ 335, 570 });
    
    
    
    
    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        menu = 1;
                        break;
                    case sf::Keyboard::Return:
                        if (menu == 0)
                        {
                            cout <<" lets get play !" << endl;
                            playing = true;
                            return (1);
                        }
                        else
                        {
                            //Let's get work...
                            return (-1);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        //When getting at alpha_max, we stop modifying the sprite
        
        Sprite.setColor(sf::Color(255, 255, 255));
        if (menu == 0)
        {
            Menu1.setColor(sf::Color(255, 0, 0, 255));
            Menu2.setColor(sf::Color(255, 255, 255, 255));
            Menu3.setColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            Menu1.setColor(sf::Color(255, 255, 255, 255));
            Menu2.setColor(sf::Color(255, 0, 0, 255));
            Menu3.setColor(sf::Color(255, 255, 255, 255));
        }
        
        //Clearing screen
        App.clear();
        //Drawing
        App.draw(Sprite);
        
        if (playing)
        {
            App.draw(Menu3);
        }
        else
        {
            App.draw(instructions);
            App.draw(froggerTitle);
            App.draw(pointTable);
            App.draw(Menu1);
        }
        App.draw(Menu2);
        
        App.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}