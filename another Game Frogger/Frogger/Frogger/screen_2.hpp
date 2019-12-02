#include"player.h"
#include <iostream>
#include "cScreen.hpp"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include "points.h"
#include <sstream>
// using inheritance to bring in variables and methods from the base class cScreen.
class screen_2 : public cScreen

{
private:
    
    bool playing;
public:
    screen_2(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_2::screen_2(void)
{
    
    playing = false;
}
int screen_2::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    
    sf::Font Font;
    sf::Text GameOver;
    sf::Text win;
    sf::Text playAgain;
    sf::Text exit;
    sf::Text userScore;
    std::stringstream ss;  // #include <sstream>
    
    int menu = 0;
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255));
    if (!Font.loadFromFile(resourcePath() + "PressStart2P.ttf"))
    {
        std::cerr << "Error loading .ttf" << std::endl;
        return (-1);
    }
    if (score >= 10000)
    {
        win.setFont(Font);
        win.setCharacterSize(105);
        win.setString("YOU\nWIN\n");
        win.setPosition({ 250, 110 });
        win.setColor(sf::Color::Red);
    }
    else
    {
        GameOver.setFont(Font);
        GameOver.setCharacterSize(105);
        GameOver.setString("GAME\nOVER\n");
        GameOver.setPosition({ 190, 110 });
        GameOver.setColor(sf::Color::Red);
    }
    
    ss << "\n\nSCORE\t\t..." << score;
    userScore.setFont(Font);
    userScore.setCharacterSize(25);
    userScore.setString( ss.str() );
    userScore.setPosition({ 175, 300 });
    score = 0;
    
    playAgain.setFont(Font);
    playAgain.setCharacterSize(20);
    playAgain.setString("PLAY");
    playAgain.setPosition({ 340, 420 });
    
    exit.setFont(Font);
    exit.setCharacterSize(20);
    exit.setString("EXIT");
    exit.setPosition({ 340, 450 });
    
    
    
    
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
                            cout <<" Let's get play !" << endl;
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
            playAgain.setColor(sf::Color(255, 0, 0, 255));
            exit.setColor(sf::Color(255, 255, 255, 255));
        }
        else
        {
            playAgain.setColor(sf::Color(255, 255, 255, 255));
            exit.setColor(sf::Color(255, 0, 0, 255));
        }
        
        //Clearing screen
        App.clear();
        //Drawing
        App.draw(Sprite);

        App.draw(GameOver);
        App.draw(win);
        App.draw(userScore);
        App.draw(playAgain);
        
        App.draw(exit);
        
        App.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}