#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Explosion
{
public:
	Explosion(sf::Texture* texture, float pos_x, float pos_y, float speed);
	~Explosion();

	void update();
	void render(sf::RenderTarget* target);

	//sf::FloatRect getBounds() const;
	int currentsprite = 1;
	int explodeTimerpub = 0;
	int explodeTimerMaxpub = 20;
	bool isDone() const;
	void animateSprite(sf::Texture* texture);
private:
	sf::Sprite sprite;

	// TODO: int type (?)
	int originX, originY;
	int explodeTimer, explodeTimerMax;
	bool done = false;
	float speed;

	void initSprite(sf::Texture* texture);
};

