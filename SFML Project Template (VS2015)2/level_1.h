#pragma once
#include<iostream>
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
#include <set>
using namespace sf;
using namespace std;

class level_1
{
private:
	RenderWindow window;
	int healthcnt;
	int froggernm;
	bool froggerfound;
	bool winsFound[5];
	Event event;
	vector<Sprite>objectsSeaRight;
	vector<Sprite>Froggers;
	vector<Vector2f>positionsSeaRight;
	vector<Sprite>objectsSeaLeft;
	vector<Vector2f>positionsSeaLeft;
	vector<Sprite>objectsRoadRight;
	vector<Vector2f>positionsRoadRight;
	vector<Sprite>objectsRoadLeft;
	vector<Vector2f>positionsRoadLeft;
	vector<Sprite>Wins;
	vector<Sprite>Hearts;
	set<int>countscore;

	//string to display the count the score of frogger 
	string count_score;

	//declaration for road and frogger (textures)
	Texture RoadPH, ForggerPH;

	// declaration for objects (textures) which in water
	Texture Object1PH, Object11PH, Object111PH, Object1111PH, Object2PH, Object22PH, Object222PH, Object2222PH, Object22222PH
		, Object222222PH, Object2222222PH, Object22222222PH, Object222222222PH, Object2222222222PH, Object3PH, Object33PH, Object333PH;

	// declaration for cars (textures) which in road
	Texture car1PH, car11PH, car2PH, car22PH, car3PH, car33PH, car4PH, car44PH;

	// declaration for win place (textures)
	Texture Winplace1, Winplace2, Winplace3, Winplace4, Winplace5;

	// declaration for hearts (texture)
	Texture heart1, heart2, heart3;


	//declaration for road and frogger (sprites)
	Sprite backgroundSprite, froggerSprite;

	//declaration for sprites for objects in water (sprites)
	Sprite object1Sprite, object11Sprite, object111Sprite, object1111Sprite, object2Sprite, object22Sprite, object222Sprite, object2222Sprite
		, object22222Sprite, object222222Sprite, object2222222Sprite, object22222222Sprite, object222222222Sprite, object2222222222Sprite, object3Sprite, object33Sprite, object333Sprite;

	//declaration for sprites for cars in road (sprites)
	Sprite car1Spritesheet, car11Spritesheet, car2Spritesheet, car22Spritesheet, car3Spritesheet, car33Spritesheet, car4Spritesheet, car44Spritesheet;

	//declaration for win place (sprite) 
	Sprite Winplacesprite1, Winplacesprite2, Winplacesprite3, Winplacesprite4, Winplacesprite5;

	//declaration for hearts (sprite)
	Sprite heartsprite1, heartsprite2, heartsprite3;


	// font el score
	Font score_font;
	Text score_text;

	// font (el timer )
	Time elabsed;
	Font timer_font;
	Text timer_text;
	Clock timer_clock;
	Time timer_time;
	string timer_string;


	//3lshan yozbot el background lma tkbr   
	//View view;

	// music in the game
	SoundBuffer mainbuffer;
	Sound mainsound;

	SoundBuffer froggerHops_buffer;
	Sound froggerHop_sound;

public:
	level_1(void);
	void load_from_file();
	void set_texture();
	void playing();
	~level_1(void);
};
namespace Collision {
	//////
	/// Test for a collision between two sprites by comparing the alpha values of overlapping pixels
	/// Supports scaling and rotation
	/// AlphaLimit: The threshold at which a pixel becomes "solid". If AlphaLimit is 127, a pixel with
	/// alpha value 128 will cause a collision and a pixel with alpha value 126 will not.
	/// 
	/// This functions creates bitmasks of the textures of the two sprites by
	/// downloading the textures from the graphics card to memory -> SLOW!
	/// You can avoid this by using the "CreateTextureAndBitmask" function
	//////
	bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
}


