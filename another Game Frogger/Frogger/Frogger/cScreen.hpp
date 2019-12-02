// This will be my super class.
/*

	When speaking about screens, I mean Menu screen, Config screen, Game screen, etc... Those screens you 
	find in every games. 
	The problem here is that each screen can be compared to a small SFML application : 
	Each screen will have its own events and will use some variables useless for other screens.
	So, we need to separate each screen in order to avoid conflicts. With SFML, it's very simple to do that! 
	You just have to create a cScreen class which will represent each screen. 
	This is an virtual object and it's containing only one method:
*/
#pragma once
#ifndef C_SCREEN
#define C_SCREEN
class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};
#endif