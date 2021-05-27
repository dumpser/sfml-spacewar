#include "Player.h"

void Player::initVariables()
{
	this->moveSpeed = 3.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	// Load a texture from file
	if (!this->texture1.loadFromFile("resimler/uzay/user/1.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture2.loadFromFile("resimler/uzay/user/2.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture3.loadFromFile("resimler/uzay/user/3.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture4.loadFromFile("resimler/uzay/user/4.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture5.loadFromFile("resimler/uzay/user/5.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture6.loadFromFile("resimler/uzay/user/6.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture7.loadFromFile("resimler/uzay/user/7.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
	if (!this->texture8.loadFromFile("resimler/uzay/user/8.png")) {
		std::cout << "ERROR::Player::InitTexture::Could not load texture file.\n";
	}
}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture1);

	// Resize the sprite
	this->sprite.setScale(0.1f, 0.09f);
	//this->sprite.setOrigin(this->sprite.getTextureRect().width / 2.f, this->sprite.getTextureRect().height / 2.f);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();

	this->sprite.setPosition(200, 700);
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0) this->hp = 0;
	//std::cout << hp << ", " << hpMax << std::endl;
}

void Player::update()
{
	this->updateAttack();
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::spinTexture()
{

	while (1)
	{
		if (currentsprite == 1)
		{
			currentsprite = 2;
			sprite.setTexture(texture2);
			break;
		}
		if (currentsprite == 2)
		{
			currentsprite = 3;
			sprite.setTexture(texture3);
			break;
		}
		if (currentsprite == 3)
		{
			currentsprite = 4;
			sprite.setTexture(texture4);
			break;
		}
		if (currentsprite == 4)
		{
			currentsprite = 5;
			sprite.setTexture(texture5);
			break;
		}
		if (currentsprite == 5)
		{
			currentsprite = 6;
			sprite.setTexture(texture6);
			break;
		}
		if (currentsprite == 6)
		{
			currentsprite = 7;
			sprite.setTexture(texture7);
			break;
		}
		if (currentsprite == 7)
		{
			currentsprite = 8;
			sprite.setTexture(texture8);
			break;
		}
		if (currentsprite == 8)
		{
			currentsprite = 1;
			sprite.setTexture(texture1);
			break;
		}
	}
}
