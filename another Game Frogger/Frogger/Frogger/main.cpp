// Kristine Laranjo, Jesus Perez, Emily Garcia
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"
int main(int argc, char** argv)
{
    //Applications variables
    std::vector<cScreen*> Screens;// creating an object of type cScreen pointer  that is called screens
    // Without the asterisk we get a nasty error.
    int screen = 0;
    
    //Window creation
    sf::RenderWindow App(sf::VideoMode(799, 675, 76), "FROGGER DEMO");
    
    //Mouse cursor no more visible
    //App.setMouseCursorVisible(false);
    
    //Screens preparations
    screen_0 s0;
    Screens.push_back(&s0);
    screen_1 s1;
    Screens.push_back(&s1);
    screen_2 s2;
    Screens.push_back(&s2);
    
    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
        cout << screen << endl;
    }
    
    return EXIT_SUCCESS;
}