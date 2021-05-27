#include "Game.h"

// Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(400, 700), "SFML", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("resimler/uzay/bullet.png");
	this->textures["BULLET_RED"] = new sf::Texture();
	this->textures["BULLET_RED"]->loadFromFile("resimler/uzay/bullet_red.png");
	this->textures["EXPLOSION"] = new sf::Texture();
	this->textures["EXPLOSION"]->loadFromFile("resimler/uzay/Effects/1_0.png");
	this->textures["EXPLOSION1"] = new sf::Texture();
	this->textures["EXPLOSION1"]->loadFromFile("resimler/uzay/Effects/1_1.png");
	this->textures["EXPLOSION2"] = new sf::Texture();
	this->textures["EXPLOSION2"]->loadFromFile("resimler/uzay/Effects/1_2.png");
	this->textures["EXPLOSION3"] = new sf::Texture();
	this->textures["EXPLOSION3"]->loadFromFile("resimler/uzay/Effects/1_3.png");
	this->textures["EXPLOSION4"] = new sf::Texture();
	this->textures["EXPLOSION4"]->loadFromFile("resimler/uzay/Effects/1_4.png");
	this->textures["EXPLOSION5"] = new sf::Texture();
	this->textures["EXPLOSION5"]->loadFromFile("resimler/uzay/Effects/1_5.png");
	this->textures["EXPLOSION6"] = new sf::Texture();
	this->textures["EXPLOSION6"]->loadFromFile("resimler/uzay/Effects/1_6.png");
	this->textures["EXPLOSION7"] = new sf::Texture();
	this->textures["EXPLOSION7"]->loadFromFile("resimler/uzay/Effects/1_7.png");
	this->textures["EXPLOSION8"] = new sf::Texture();
	this->textures["EXPLOSION8"]->loadFromFile("resimler/uzay/Effects/1_8.png");
	this->textures["EXPLOSION9"] = new sf::Texture();
	this->textures["EXPLOSION9"]->loadFromFile("resimler/uzay/Effects/1_9.png");
	this->textures["EXPLOSION10"] = new sf::Texture();
	this->textures["EXPLOSION10"]->loadFromFile("resimler/uzay/Effects/1_10.png");
	this->textures["EXPLOSION11"] = new sf::Texture();
	this->textures["EXPLOSION11"]->loadFromFile("resimler/uzay/Effects/1_11.png");
	this->textures["EXPLOSION12"] = new sf::Texture();
	this->textures["EXPLOSION12"]->loadFromFile("resimler/uzay/Effects/1_12.png");
	this->textures["EXPLOSION13"] = new sf::Texture();
	this->textures["EXPLOSION13"]->loadFromFile("resimler/uzay/Effects/1_13.png");
	this->textures["EXPLOSION14"] = new sf::Texture();
	this->textures["EXPLOSION14"]->loadFromFile("resimler/uzay/Effects/1_14.png");
	this->textures["EXPLOSION15"] = new sf::Texture();
	this->textures["EXPLOSION15"]->loadFromFile("resimler/uzay/Effects/1_15.png");
	this->textures["EXPLOSION16"] = new sf::Texture();
	this->textures["EXPLOSION16"]->loadFromFile("resimler/uzay/Effects/1_16.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initGUI()
{
	gs = GameState::START;

	// Load font

	// Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(24);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setPosition(20.f, 50.f);

	// Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::White);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
								   this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	// Init player hp bar
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::initWorld()
{
}



// Con / Des
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
	this->initGUI();
	this->initWorld();
}

Game::~Game() {
	delete this->window;
	delete this->player;

	for (auto& texture : this->textures) {
		delete texture.second;
	}

	for (auto* bullet : this->bullets) {
		delete bullet;
	}

	for (auto* asteroid : this->enemies) {
		delete asteroid;
	}
}

// Functions


void Game::run() {
	while (this->window->isOpen()) {
		this->updatePollEvents();

		this->update();

		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;

	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed ||
			(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape))
		{
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	// Move player
	//player->update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	this->player->move(0.f, -1.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	this->player->move(0.f, 1.f);


	// Shoot
	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		&& this->player->canAttack())
	{
		Bullet* left = new Bullet(this->textures["BULLET"],
								  this->player->getPos().x + this->player->getBounds().width / 2.f - 20.f,
								  this->player->getPos().y,
								  0.f, -1.f, 5.f,1);

		this->bullets.push_back(left);
	}
}

void Game::updateBullets()
{
	for (size_t i = 0; i < this->bullets.size(); i++) {
		bullets[i]->update();

		// Bullet culling (top of screen)
		if (bullets[i]->getBounds().top + bullets[i]->getBounds().height < 0.f)
		{
			// Delete bullet
			delete this->bullets[i];
			this->bullets.erase(this->bullets.begin() + i);
		}

	}
}

void Game::animatePlayer()
{
	this->player->animatetime += 0.5f;
	if (this->player->animatetime >= this->player->animatetimeMax) {
		this->player->spinTexture();
		this->player->animatetime = 0.0f;
	}

}

void Game::animateExp()
{
	for (auto* explosion : this->explosions) 
	{

		while (1)
		{
			if (explosion->currentsprite == 1)
			{
				explosion->currentsprite = 2;
				explosion->animateSprite(this->textures["EXPLOSION1"]);
				break;
			}
			if (explosion->currentsprite == 2)
			{
				explosion->currentsprite = 3;
				explosion->animateSprite(this->textures["EXPLOSION2"]);
				break;
			}
			if (explosion->currentsprite == 3)
			{
				explosion->currentsprite = 4;
				explosion->animateSprite(this->textures["EXPLOSION3"]);
				break;
			}
			if (explosion->currentsprite == 4)
			{
				explosion->currentsprite = 5;
				explosion->animateSprite(this->textures["EXPLOSION4"]);
				break;
			}
			if (explosion->currentsprite == 5)
			{
				explosion->currentsprite = 6;
				explosion->animateSprite(this->textures["EXPLOSION5"]);
				break;
			}
			if (explosion->currentsprite == 6)
			{
				explosion->currentsprite = 7;
				explosion->animateSprite(this->textures["EXPLOSION6"]);
				break;
			}
			if (explosion->currentsprite == 7)
			{
				explosion->currentsprite = 8;
				explosion->animateSprite(this->textures["EXPLOSION7"]);
				break;
			}
			if (explosion->currentsprite == 8)
			{
				explosion->currentsprite = 9;
				explosion->animateSprite(this->textures["EXPLOSION8"]);
				break;
			}
			if (explosion->currentsprite == 9)
			{
				explosion->currentsprite = 10;
				explosion->animateSprite(this->textures["EXPLOSION9"]);
				break;
			}
			if (explosion->currentsprite == 10)
			{
				explosion->currentsprite = 11;
				explosion->animateSprite(this->textures["EXPLOSION10"]);
				break;
			}
			if (explosion->currentsprite == 11)
			{
				explosion->currentsprite = 12;
				explosion->animateSprite(this->textures["EXPLOSION11"]);
				break;
			}
			if (explosion->currentsprite == 12)
			{
				explosion->currentsprite = 13;
				explosion->animateSprite(this->textures["EXPLOSION12"]);
				break;
			}
			if (explosion->currentsprite == 13)
			{
				explosion->currentsprite = 14;
				explosion->animateSprite(this->textures["EXPLOSION13"]);
				break;
			}
			if (explosion->currentsprite == 14)
			{
				explosion->currentsprite = 15;
				explosion->animateSprite(this->textures["EXPLOSION14"]);
				break;
			}
			if (explosion->currentsprite == 15)
			{
				explosion->currentsprite = 16;
				explosion->animateSprite(this->textures["EXPLOSION15"]);
				break;
			}
			if (explosion->currentsprite == 16)
			{
				explosion->currentsprite = 1;
				explosion->animateSprite(this->textures["EXPLOSION16"]);
				break;
			}
			break;
		}
	}
}



void Game::updateEnemies()
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax) {
		this->enemies.push_back(new Asteroid(20.f, -100.f));
		this->spawnTimer = 0.f;
	}


	for (size_t i = 0; i < enemies.size(); i++) 
	{
		bool asteroid_removed = false;
		enemies[i]->update();

		this->enemies[i]->animatetime += 0.5f;
		if (this->enemies[i]->animatetime >= this->enemies[i]->animatetimeMax) {
			this->enemies[i]->spinTexture();
			this->enemies[i]->animatetime = 0.0f;
		}

		if (enemies[i]->type == 1 || enemies[i]->type == 4)
		{
			this->enemies[i]->bullettime += 0.5f;
			if (this->enemies[i]->bullettime >= this->enemies[i]->bullettimeMax) {
				
				Bullet* left = new Bullet(this->textures["BULLET_RED"],
					this->enemies[i]->getPos().x - 45.0f,
					this->enemies[i]->getPos().y,
					0.f, 1.f, 5.f,2);

				this->bullets.push_back(left);
				this->enemies[i]->bullettime = 0.0f;
			}
		}

		for (size_t k = 0; k < this->bullets.size() && !asteroid_removed; k++) 
		{
			if (bullets[k]->typebullet == 2)
			{
				if (this->bullets[k]->getBounds().intersects(this->player->getBounds()))
				{
					this->gs = GameState::END;
				}
			}
			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds()) && bullets[k]->typebullet == 1) 
			{


				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				sf::Vector2f enemyCenter = sf::Vector2f(this->enemies[i]->getBounds().width / 4, this->enemies[i]->getBounds().height / 4);
				sf::Vector2f enemyPos = this->enemies[i]->getPos();
				float enemySpeed = this->enemies[i]->getSpeed();
				if (enemies[i]->type == 1)
					this->explosions.push_back(new Explosion(this->textures["EXPLOSION"], enemies[i]->getPos().x - 80, enemies[i]->getPos().y - 80, enemySpeed));
				if (enemies[i]->type == 2)
					this->explosions.push_back(new Explosion(this->textures["EXPLOSION"], enemies[i]->getPos().x - 30, enemies[i]->getPos().y - 30, enemySpeed));
				if (enemies[i]->type == 3)
					this->explosions.push_back(new Explosion(this->textures["EXPLOSION"], enemies[i]->getPos().x - 30, enemies[i]->getPos().y - 30, enemySpeed));
				if (enemies[i]->type == 4)
					this->explosions.push_back(new Explosion(this->textures["EXPLOSION"], enemies[i]->getPos().x - 100, enemies[i]->getPos().y - 100, enemySpeed));
				if (enemies[i]->type == 5)
					this->explosions.push_back(new Explosion(this->textures["EXPLOSION"], enemies[i]->getPos().x - 30, enemies[i]->getPos().y - 30, enemySpeed));
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				asteroid_removed = true;
			}

		}

	}
}


void Game::updateExplosions() {

	for (size_t i = 0; i < this->explosions.size(); i++) 
	{
		explosions[i]->explodeTimerpub += 1;
		if (explosions[i]->explodeTimerpub >= explosions[i]->explodeTimerMaxpub) {
			delete this->explosions[i];
			this->explosions.erase(this->explosions.begin() + i);
		}

	}
}

void Game::updateCollision()
{
	// Left world boundary
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	// Right world boundary
	if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	// Bottom world boundary
	if (this->player->getBounds().top + this->player->getBounds().height > this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateWorld()
{
	if (this->player->getHp() <= 0)
	{
		this->gs = GameState::END;
	}
}



void Game::update() {
	if (this->gs == GameState::START) {
		gs = GameState::GAME;
	}
	else if (this->gs == GameState::GAME) {
		this->updateInput();
		this->player->update();
		this->updateWorld();
		this->updateCollision();
		this->updateBullets();
		this->animatePlayer();
		this->animateExp();
		this->updateEnemies();
		this->updateExplosions();
	}
	else if (this->gs == GameState::END) {

	}
}


void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render() {
	this->window->clear();

	// Draw stuff
	if (gs == GameState::START) {

	}
	else if (this->gs == GameState::GAME) {

		renderWorld();

		player->render(this->window);

		for (auto* bullet : this->bullets) {
			bullet->render(this->window);
		}

		for (auto* asteroid : this->enemies) {
			asteroid->render(this->window);
		}

		for (auto* explosion : this->explosions) {
			explosion->render(this->window);
		}


		if (this->player->getHp() <= 0) {
			this->window->draw(this->gameOverText);
		}
	}
	else if (gs == GameState::END) {

	}

	this->window->display();
}