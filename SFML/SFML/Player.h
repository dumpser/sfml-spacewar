#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
public:
	Player();
	~Player();

	// Functions
	void move(const float dirX, const float dirY);

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	// Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	void update();
	float animatetimeMax = 10.0f;
	float animatetime = 0.0f;
	void updateAttack();
	void render(sf::RenderTarget* target);
	const bool canAttack();
	void spinTexture();
	int currentsprite = 1;
private:
	sf::Sprite sprite;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;
	sf::Texture texture6;
	sf::Texture texture7;
	sf::Texture texture8;
	float moveSpeed;
	//float moveAccel;
	//float moveDeaccel;
	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;


	// Private functions
	void initVariables();
	void initTexture();
	void initSprite();
};