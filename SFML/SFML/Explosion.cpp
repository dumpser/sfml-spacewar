#include "Explosion.h"

Explosion::Explosion(sf::Texture* texture, float pos_x, float pos_y, float speed)
{
	this->originX = 0;
	this->originY = 0;
	this->explodeTimer = 0;
	this->explodeTimerMax = 10;
	this->speed = speed;
	this->initSprite(texture);

	this->sprite.setPosition(pos_x, pos_y);
}

Explosion::~Explosion()
{
}

void Explosion::update()
{

}

void Explosion::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

bool Explosion::isDone() const
{
	return this->done;
}

void Explosion::animateSprite(sf::Texture* texture)
{
	//// Set the texture to the sprite
	this->sprite.setTexture(*texture);

	//this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
}

void Explosion::initSprite(sf::Texture* texture)
{
	// Set the texture to the sprite
	this->sprite.setTexture(*texture);

	this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	this->sprite.setScale(0.5f, 0.5f);
}