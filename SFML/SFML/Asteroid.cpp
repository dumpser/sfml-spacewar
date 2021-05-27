#include "Asteroid.h"

Asteroid::Asteroid(float pos_x, float pos_y)
{

	type = rand() % 4 + 1;
	this->originX = 0;
	this->originY = 0;
	this->rotateTimer = 0;
	this->rotateTimerMax = 50;
	this->initVariables();
	this->initTexture();
	this->initSprite();

	/*type = rand() % 4 + 1;*/

	int v2 = rand() % 400 + 1;
	this->sprite.setPosition(v2, pos_y);
}

Asteroid::~Asteroid()
{
}

void Asteroid::initVariables()
{

	difficulty = 6;
	hpMax = difficulty;
	hp = hpMax;
	damage = difficulty;
	points = difficulty;
	this->speed = static_cast<float>(difficulty / 3);
	this->rotateTimerMax = 10;

	//float scale = static_cast<float>(((double)rand() / RAND_MAX) / 2 + 0.5);

}

void Asteroid::initTexture()
{
	if (type == 1)
	{
		if (!this->textureyarasa1.loadFromFile("resimler/uzay/yarasaucak/1.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureyarasa2.loadFromFile("resimler/uzay/yarasaucak/2.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureyarasa3.loadFromFile("resimler/uzay/yarasaucak/3.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureyarasa4.loadFromFile("resimler/uzay/yarasaucak/4.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		sprite.setScale(sf::Vector2f(0.1f, 0.1f));
		sprite.rotate(180.0f);
	}
	if (type == 2)
	{
		if (!this->texturebomb1.loadFromFile("resimler/uzay/Spacebombs/1.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->texturebomb2.loadFromFile("resimler/uzay/Spacebombs/2.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->texturebomb3.loadFromFile("resimler/uzay/Spacebombs/3.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}
	if (type == 3)
	{
		if (!this->texturemine1.loadFromFile("resimler/uzay/Spacemines/1.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->texturemine2.loadFromFile("resimler/uzay/Spacemines/2.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}
	if (type == 4)
	{
		if (!this->textureship1.loadFromFile("resimler/uzay/smallship/1.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureship2.loadFromFile("resimler/uzay/smallship/2.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureship3.loadFromFile("resimler/uzay/smallship/3.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureship4.loadFromFile("resimler/uzay/smallship/4.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->textureship5.loadFromFile("resimler/uzay/smallship/5.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		sprite.setScale(sf::Vector2f(0.1f, 0.1f));
		sprite.rotate(180.0f);
	}
	if (type == 5)
	{
		if (!this->texturecomm1.loadFromFile("resimler/uzay/comm/1.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->texturecomm2.loadFromFile("resimler/uzay/comm/2.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		if (!this->texturecomm3.loadFromFile("resimler/uzay/comm/3.png")) {
			std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
		}
		sprite.setScale(sf::Vector2f(0.1f, 0.1f));
	}
}

void Asteroid::initSprite()
{
	// Set the texture to the sprite
	if (type == 1)
	{
		this->sprite.setTexture(this->textureyarasa1);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 512, 512));
	}
	if (type == 2)
	{
		this->sprite.setTexture(this->texturebomb1);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 257));
	}
	if (type == 3)
	{
		this->sprite.setTexture(this->texturemine1);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	}
	if (type == 4)
	{
		this->sprite.setTexture(this->textureship1);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 640, 640));
	}
	if (type == 5)
	{
		this->sprite.setTexture(this->texturecomm1);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 1024, 1024));
	}
}

void Asteroid::update()
{
	this->sprite.move(0.f, this->speed);
	this->rotateTimer += 1;

}

void Asteroid::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

sf::FloatRect Asteroid::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Asteroid::getDamage() const
{
	return this->damage;
}

int Asteroid::getPoints() const
{
	return this->points;
}

sf::Vector2f Asteroid::getPos() const
{
	return this->sprite.getPosition();
}

float Asteroid::getSpeed() const
{
	return this->speed;
}

void Asteroid::spinTexture()
{
	while (1)
	{
		if (type == 1)
		{
			if (currentspriteyarasa == 1)
			{
				currentspriteyarasa = 2;
				sprite.setTexture(textureyarasa2);
				break;
			}
			if (currentspriteyarasa == 2)
			{
				currentspriteyarasa = 3;
				sprite.setTexture(textureyarasa3);
				break;
			}
			if (currentspriteyarasa == 3)
			{
				currentspriteyarasa = 4;
				sprite.setTexture(textureyarasa4);
				break;
			}
			if (currentspriteyarasa == 4)
			{
				currentspriteyarasa = 1;
				sprite.setTexture(textureyarasa1);
				break;
			}
		}
		if (type == 2)
		{
			if (currentspritebomb == 1)
			{
				currentspritebomb = 2;
				sprite.setTexture(texturebomb2);
				break;
			}
			if (currentspritebomb == 2)
			{
				currentspritebomb = 3;
				sprite.setTexture(texturebomb3);
				break;
			}
			if (currentspritebomb == 3)
			{
				currentspritebomb = 1;
				sprite.setTexture(texturebomb1);
				break;
			}
		}
		if (type == 3)
		{
			if (currentspritemine == 1)
			{
				currentspritemine = 2;
				sprite.setTexture(texturemine2);
				break;
			}
			if (currentspritemine == 2)
			{
				currentspritemine = 1;
				sprite.setTexture(texturemine1);
				break;
			}
		}
		if (type == 4)
		{
			if (currentspriteship == 1)
			{
				currentspriteship = 2;
				sprite.setTexture(textureship2);
				break;
			}
			if (currentspriteship == 2)
			{
				currentspriteship = 3;
				sprite.setTexture(textureship3);
				break;
			}
			if (currentspriteship == 3)
			{
				currentspriteship = 4;
				sprite.setTexture(textureship4);
				break;
			}
			if (currentspriteship == 4)
			{
				currentspriteship = 5;
				sprite.setTexture(textureship5);
				break;
			}
			if (currentspriteship == 5)
			{
				currentspriteship = 1;
				sprite.setTexture(textureship1);
				break;
			}
		}
		if (type == 5)
		{
			if (currentspritecomm == 1)
			{
				currentspritecomm = 2;
				sprite.setTexture(texturecomm2);
				break;
			}
			if (currentspritecomm == 2)
			{
				currentspritecomm = 3;
				sprite.setTexture(texturecomm3);
				break;
			}
			if (currentspritecomm == 3)
			{
				currentspritecomm = 1;
				sprite.setTexture(texturecomm1);
				break;
			}
		}
	}
}
