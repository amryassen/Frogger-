#include<iostream>
#include<vector>
#include<ctime>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include<SFML\Window.hpp>
#include<vector>
using namespace sf;
using namespace std;
int main()
{
	RenderWindow window(VideoMode(800, 676), "frogger");
	Event event;
	vector<Sprite>objectsRight;
	vector<Vector2f>positionsRight;
	vector<Sprite>objectsLeft;
	vector<Vector2f>positionsLeft;


	//background
	Texture RoadPH;
	RoadPH.loadFromFile("background.png");
	Sprite backgroundSprite;
	backgroundSprite.setTexture(RoadPH);




	//frogger
	Texture ForggerPH;
	ForggerPH.loadFromFile("froggers.png");
	Sprite froggerSprite;
	froggerSprite.setTexture(ForggerPH);
	froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
	froggerSprite.setPosition(Vector2f(300.f, 630.f));

	//Object1 in water
	Texture Object1PH;
	Object1PH.loadFromFile("objects.png");
	Sprite object1Sprite;
	object1Sprite.setTexture(Object1PH);
	object1Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1Sprite.setPosition(Vector2f(552.f, 25.f));
	objectsLeft.push_back(object1Sprite);
	positionsLeft.push_back(Vector2f( 552.f, 25.f));


	//Object11 in water
	Texture Object11PH;
	Object11PH.loadFromFile("objects.png");
	Sprite object11Sprite;
	object11Sprite.setTexture(Object11PH);
	object11Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object11Sprite.setPosition(Vector2f(250.f, 25.f));
	objectsLeft.push_back(object11Sprite);
	positionsLeft.push_back(Vector2f(250.f, 25.f));


	//Object111 in water
	Texture Object111PH;
	Object111PH.loadFromFile("objects.png");
	Sprite object111Sprite;
	object111Sprite.setTexture(Object111PH);
	object111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object111Sprite.setPosition(Vector2f(850.f, 25.f));
	objectsLeft.push_back(object111Sprite);
	positionsLeft.push_back(Vector2f(850.f, 25.f));



	//Object1111 in water
	Texture Object1111PH;
	Object1111PH.loadFromFile("objects.png");
	Sprite object1111Sprite;
	object1111Sprite.setTexture(Object1111PH);
	object1111Sprite.setTextureRect(IntRect(520, 290, 200, 75));
	object1111Sprite.setPosition(Vector2f(1100.f, 25.f));
	objectsLeft.push_back(object1111Sprite);
	positionsLeft.push_back(Vector2f(1100.f, 25.f));




	//Object 2 in water
	Texture Object2PH;
	Object2PH.loadFromFile("objects.png");
	Sprite object2Sprite;
	object2Sprite.setTexture(Object2PH);
	object2Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2Sprite.setPosition(Vector2f(-100.f, 90.f));
	objectsRight.push_back(object2Sprite);
	positionsRight.push_back(Vector2f (-100.f, 90.f));



	//Object 22 in water
	Texture Object22PH;
	Object22PH.loadFromFile("objects.png");
	Sprite object22Sprite;
	object22Sprite.setTexture(Object22PH);
	object22Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22Sprite.setPosition(Vector2f(-300.f, 90.f));
	objectsRight.push_back(object22Sprite);
	positionsRight.push_back(Vector2f(-300.f, 90.f));


	//Object 222 in water
	Texture Object222PH;
	Object222PH.loadFromFile("objects.png");
	Sprite object222Sprite;
	object222Sprite.setTexture(Object222PH);
	object222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222Sprite.setPosition(Vector2f(-420.f, 90.f));
	objectsRight.push_back(object222Sprite);
	positionsRight.push_back(Vector2f(-420.f, 90.f));


	//Object 2222 in water
	Texture Object2222PH;
	Object2222PH.loadFromFile("objects.png");
	Sprite object2222Sprite;
	object2222Sprite.setTexture(Object2222PH);
	object2222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object2222Sprite.setPosition(Vector2f(-520.f, 90.f));
	objectsRight.push_back(object2222Sprite);
	positionsRight.push_back(Vector2f(-520.f, 90.f));



	//Object 22222 in water
	Texture Object22222PH;
	Object22222PH.loadFromFile("objects.png");
	Sprite object22222Sprite;
	object22222Sprite.setTexture(Object22222PH);
	object22222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object22222Sprite.setPosition(Vector2f(-620.f, 90.f));
	objectsRight.push_back(object22222Sprite);
	positionsRight.push_back(Vector2f(-620.f, 90.f));




	//Object 222222 in water
	Texture Object222222PH;
	Object222222PH.loadFromFile("objects.png");
	Sprite object222222Sprite;
	object222222Sprite.setTexture(Object222222PH);
	object222222Sprite.setTextureRect(IntRect(60, 120, 160, 80));
	object222222Sprite.setPosition(Vector2f(-780.f, 90.f));
	objectsRight.push_back(object222222Sprite);
	positionsRight.push_back(Vector2f(-780.f, 90.f));





	//Object 3 in water
	Texture Object3PH;
	Object3PH.loadFromFile("objects.png");
	Sprite object3Sprite;
	object3Sprite.setTexture(Object3PH);
	object3Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object3Sprite.setPosition(Vector2f(555.f, 160.f));
	objectsLeft.push_back(object3Sprite);
	positionsLeft.push_back(Vector2f(555.f, 160.f));





	//Object 33 in water
	Texture Object33PH;
	Object33PH.loadFromFile("objects.png");
	Sprite object33Sprite;
	object33Sprite.setTexture(Object33PH);
	object33Sprite.setTextureRect(IntRect(150, 370, 280, 75));
	object33Sprite.setPosition(Vector2f(150.f, 160.f));
	objectsLeft.push_back(object33Sprite);
	positionsLeft.push_back(Vector2f(150.f, 160.f));



	//Object 4 in water
	Texture Object4PH;
	Object4PH.loadFromFile("objects.png");
	Sprite object4Sprite;
	object4Sprite.setTexture(Object4PH);
	object4Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object4Sprite.setPosition(Vector2f(-58.f, 200.f));
	objectsRight.push_back(object4Sprite);
	positionsRight.push_back(Vector2f( -58.f, 200.f));



	//Object 44 in water
	Texture Object44PH;
	Object44PH.loadFromFile("objects.png");
	Sprite object44Sprite;
	object44Sprite.setTexture(Object44PH);
	object44Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object44Sprite.setPosition(Vector2f(-160.f, 200.f));
	objectsRight.push_back(object44Sprite);
	positionsRight.push_back(Vector2f (-160.f, 200.f));



	//Object 444 in water
	Texture Object444PH;
	Object444PH.loadFromFile("objects.png");
	Sprite object444Sprite;
	object444Sprite.setTexture(Object444PH);
	object444Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object444Sprite.setPosition(Vector2f(-250.f, 200.f));
	objectsRight.push_back(object444Sprite);
	positionsRight.push_back(Vector2f(-250.f, 200.f));




	//Object 4444 in water
	Texture Object4444PH;
	Object4444PH.loadFromFile("objects.png");
	Sprite object4444Sprite;
	object4444Sprite.setTexture(Object4444PH);
	object4444Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object4444Sprite.setPosition(Vector2f(-420.f, 200.f));
	objectsRight.push_back(object4444Sprite);
	positionsRight.push_back(Vector2f(-420.f, 200.f));



	//Object 44444 in water
	Texture Object44444PH;
	Object44444PH.loadFromFile("objects.png");
	Sprite object44444Sprite;
	object44444Sprite.setTexture(Object44444PH);
	object44444Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object44444Sprite.setPosition(Vector2f(-500.f, 200.f));
	objectsRight.push_back(object44444Sprite);
	positionsRight.push_back(Vector2f(-500.f, 200.f));




	//Object 444444 in water
	Texture Object444444PH;
	Object444444PH.loadFromFile("objects.png");
	Sprite object444444Sprite;
	object444444Sprite.setTexture(Object444444PH);
	object444444Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object444444Sprite.setPosition(Vector2f(-580.f, 200.f));
	objectsRight.push_back(object444444Sprite);
	positionsRight.push_back(Vector2f(-580.f, 200.f));




	//Object 4444444 in water
	Texture Object4444444PH;
	Object4444444PH.loadFromFile("objects.png");
	Sprite object4444444Sprite;
	object4444444Sprite.setTexture(Object4444444PH);
	object4444444Sprite.setTextureRect(IntRect(520, 120, 60, 75));
	object4444444Sprite.setPosition(Vector2f(-680.f, 200.f));
	objectsRight.push_back(object4444444Sprite);
	positionsRight.push_back(Vector2f(-680.f, 200.f));



	//First car1
	Texture car1PH;
	car1PH.loadFromFile("objects.png");
	Sprite car1Spritesheet;
	car1Spritesheet.setTexture(car1PH);
	car1Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car1Spritesheet.setPosition(Vector2f(100.f, 360.f));
	objectsRight.push_back(car1Spritesheet);
	positionsRight.push_back(Vector2f( 100.f, 360.f));



	//First car11
	Texture car11PH;
	car11PH.loadFromFile("objects.png");
	Sprite car11Spritesheet;
	car11Spritesheet.setTexture(car11PH);
	car11Spritesheet.setTextureRect(IntRect(120, 440, 215, 70));
	car11Spritesheet.setPosition(Vector2f(-300.f, 360.f));
	objectsRight.push_back(car11Spritesheet);
	positionsRight.push_back(Vector2f(-300.f, 360.f));




	//second car2
	Texture car2PH;
	car2PH.loadFromFile("cars.png");
	Sprite car2Spritesheet;
	car2Spritesheet.setTexture(car2PH);
	car2Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car2Spritesheet.setPosition(Vector2f(400.f, 430.f));
	objectsLeft.push_back(car2Spritesheet);
	positionsLeft.push_back(Vector2f(400.f, 430.f));



	//second car22
	Texture car22PH;
	car22PH.loadFromFile("cars.png");
	Sprite car22Spritesheet;
	car22Spritesheet.setTexture(car22PH);
	car22Spritesheet.setTextureRect(IntRect(70, 80, 65, 40));
	car22Spritesheet.setPosition(Vector2f(180.f, 430.f));
	objectsLeft.push_back(car22Spritesheet);
	positionsLeft.push_back(Vector2f(180.f, 430.f));


	//third car3
	Texture car3PH;
	car3PH.loadFromFile("objects.png");
	Sprite car3Spritesheet;
	car3Spritesheet.setTexture(car3PH);
	car3Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car3Spritesheet.setPosition(Vector2f(-160.f, 465.f));
	objectsRight.push_back(car3Spritesheet);
	positionsRight.push_back(Vector2f( -160.f, 465.f));





	//third car33
	Texture car33PH;
	car33PH.loadFromFile("objects.png");
	Sprite car33Spritesheet;
	car33Spritesheet.setTexture(car33PH);
	car33Spritesheet.setTextureRect(IntRect(280, 520, 160, 70));
	car33Spritesheet.setPosition(Vector2f(-450.f, 465.f));
	objectsRight.push_back(car33Spritesheet);
	positionsRight.push_back(Vector2f(-450.f, 465.f));



	//fourth car4
	Texture car4PH;
	car4PH.loadFromFile("cars1.png");
	Sprite car4Spritesheet;
	car4Spritesheet.setTexture(car4PH);
	car4Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car4Spritesheet.setPosition(Vector2f(554.f, 515.f));
	objectsLeft.push_back(car4Spritesheet);
	positionsLeft.push_back(Vector2f( 554.f, 515.f));




	//fourth car44
	Texture car44PH;
	car44PH.loadFromFile("cars1.png");
	Sprite car44Spritesheet;
	car44Spritesheet.setTexture(car44PH);
	car44Spritesheet.setTextureRect(IntRect(5, 75, 70, 60));
	car44Spritesheet.setPosition(Vector2f(280.f, 515.f));
	objectsLeft.push_back(car44Spritesheet);
	positionsLeft.push_back(Vector2f(280.f, 515.f));



	while (window.isOpen()) {

		// to change position of frogger
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Right) {
					//aly 3ayzeno
					froggerSprite.move(Vector2f(40, 0));
					froggerSprite.setTextureRect(IntRect( 50*2, 50* 2, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect((50 * 1) + 5, 50 * 2, 50, 40));
				}

				else if (event.key.code == Keyboard::Left) {
					froggerSprite.move(Vector2f(-40, 0));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 1, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect((50 * 1) + 3, 50 * 1, 50, 40));
				}

				else if (event.key.code == Keyboard::Up) {
					froggerSprite.move(Vector2f(0, -40));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 3, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect(50 * 1, 50 * 3, 50, 40));
				}

				else if (event.key.code == Keyboard::Down) {
					froggerSprite.move(Vector2f(0, 40));
					froggerSprite.setTextureRect(IntRect(50 * 2, 50 * 0, 50, 40));
					window.draw(froggerSprite);
					window.display();
					froggerSprite.setTextureRect(IntRect(50 * 1, 0, 50, 40));
				}
				else if (event.key.code == Keyboard::Escape) { window.close(); }

			}

		}


		window.clear();
		window.draw(backgroundSprite);
		//window.draw(seaSprite);

		for (auto i : objectsRight) {
			window.draw(i);
		}
		for (auto i : objectsLeft) {
			window.draw(i);
		}
		window.draw(froggerSprite);
		window.display();
		for (int i = 0; i<objectsRight.size(); i++) {
			objectsRight[i].move(2.f, 0.f);
			if (objectsRight[i].getPosition().x >  window.getSize().x + 70) {
				objectsRight[i].setPosition(-180.f, positionsRight[i].y);
			}
		}
		for (int i = 0; i<objectsLeft.size(); i++) {
			objectsLeft[i].move(-2.f, 0.f);
			if (objectsLeft[i].getPosition().x <0 - 280.f) {
				objectsLeft[i].setPosition(window.getSize().x + 80.f, positionsLeft[i].y);
			}
		}
	}

	
	return 0;
}
/*RenderWindow window(VideoMode(500,600), "ANA GAMED AWY");
window.setFramerateLimit(60);
Event ev;
RectangleShape enemy;
vector<RectangleShape>enemies;
srand(static_cast<unsigned>(time(NULL)));
float EnemySpawnTimer = 1.f;
int maxenemies =10 ;
int points = 0;
enemy.setSize(Vector2f(60.f, 60.f));
enemy.setFillColor(Color::Red);
//enemy.setPosition(Vector2f(100.f, 8.f));
while (window.isOpen()) {
while (window.pollEvent(ev)) {
if (ev.type == Event::Closed)
window.close();
if (ev.type==Event::KeyPressed) {
if (ev.key.code == Keyboard::Escape) {
window.close();
}
}
}

window.clear();
// clear and display
for (auto i : enemies) {
window.draw(i);
}
window.display();
Vector2i mousepos = Mouse::getPosition(window);
Vector2f mouseposview =window.mapPixelToCoords(mousepos);
if (enemies.size() < maxenemies) {
if (EnemySpawnTimer >= 20.f) {
enemy.setPosition(
0.f,
static_cast<float>(rand() % static_cast<int>(window.getSize().y - enemy.getSize().y))
);
enemies.push_back(enemy);
EnemySpawnTimer = 0.f;
}
else {
EnemySpawnTimer += 1.f;
}
}
for (int i = 0;i<enemies.size();i++) {
enemies[i].move(5.f, 0.f);
bool isfound = false;
if (Mouse::isButtonPressed(Mouse::Left)) {
if (enemies[i].getGlobalBounds().contains(mouseposview)) {
isfound = 1;
points += 1.f;
}
}
if (!isfound) {
if (enemies[i].getPosition().x > window.getPosition().x+100.f)
{
isfound = 1;
}
}
if(isfound)enemies.erase(enemies.begin() + i);
}
cout << points << endl;
}
*/