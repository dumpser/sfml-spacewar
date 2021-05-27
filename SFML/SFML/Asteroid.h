#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h> 

class Asteroid
{
public:
	Asteroid(float pos_x, float pos_y);
	~Asteroid();
	void update();
	void render(sf::RenderTarget* target);

	sf::FloatRect getBounds() const;
	const int& getDamage() const;

	int getPoints() const;

	sf::Vector2f getPos() const;
	float animatetimeMax = 10.0f;
	float animatetime = 0.0f;

	float bullettimeMax = 40.0f;
	float bullettime = 0.0f;
	float getSpeed() const;
	void spinTexture();
	int currentspriteyarasa = 1;
	int currentspritemine = 1;
	int currentspritebomb = 1;
	int currentspriteship = 1;
	int currentspritecomm = 1;
	int type;
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture textureyarasa1;
	sf::Texture textureyarasa2;
	sf::Texture textureyarasa3;
	sf::Texture textureyarasa4;
	sf::Texture texturemine1;
	sf::Texture texturemine2;
	sf::Texture texturebomb1;
	sf::Texture texturebomb2;
	sf::Texture texturebomb3;
	sf::Texture texturecomm1;
	sf::Texture texturecomm2;
	sf::Texture texturecomm3;
	sf::Texture textureship1;
	sf::Texture textureship2;
	sf::Texture textureship3;
	sf::Texture textureship4;
	sf::Texture textureship5;
	int difficulty;
	int hp;
	int hpMax;
	int damage;
	int points;
	float scale;
	float speed;
	// TODO: int type (?)
	int originX, originY;
	int rotateTimer, rotateTimerMax;

	void initVariables();
	void initSprite();
	void initTexture();

};

