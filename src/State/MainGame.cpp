#include "State/MainGame.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

MainGame::MainGame(sf::RenderWindow* window, EventManager* events, StateManager* states) {
    this->m_window = window;
    this->m_eventmng = events;
    this->m_statemng = states;

    std::srand (std::time(nullptr));

    this->m_playerTexture.loadFromFile("Data/Player.png");
    this->m_sTexture.loadFromFile("Data/S.png");
    this->m_player.setTexture(this->m_playerTexture);
    this->m_player.setPosition(832/2 - 32, 512/2 - 32);
    this->m_s.setTexture(this->m_sTexture);
    this->m_s.setPosition(-64,-64);
    this->m_elapsedTime = sf::Time::Zero;
    i = 0;
    playerDir = 0;
    this->m_player.setTextureRect(sf::IntRect(0,0,64,64));

    shoot = false;
    lives = 10;
    Puntos = 0;

    this->pixeled.loadFromFile("Data/font.ttf");
    this->Vidas.setFont(this->pixeled);
    this->Vidas.setColor(sf::Color::White);
    this->puntos.setFont(this->pixeled);
    this->puntos.setColor(sf::Color::White);
    Vidas.setCharacterSize(15);
    Vidas.setPosition(30,30);
    puntos.setCharacterSize(15);
    puntos.setPosition(30,60);

    bgT.loadFromFile("Data/River.png");
    bg.setTexture(bgT);
}

#define SPEED 8

void MainGame::update (sf::Time deltatime) {
  if (!this->m_eventmng->isFocused()) return;
  /*this->m_elapsedTime += deltatime;
  if (this->m_elapsedTime >= sf::seconds(0.2)) {
    this->m_elapsedTime = sf::Time::Zero;
    i = (i + 1) % 4;
    this->m_player.setTextureRect(sf::IntRect(0,i*64,64,64));
  }*/

  if (lives <= 0) this->m_statemng->popLooped();

  if (!shoot) {
    dirShoot = rand() % 4;
    if (dirShoot == 0) {
      this->m_s.setPosition(832/2 - 16, -64);
      this->m_s.setRotation(270);
    }
    else if (dirShoot == 1) {
      this->m_s.setPosition(832/2 + 16, 512);
      this->m_s.setRotation(90);
    }
    else if (dirShoot == 2) {
      this->m_s.setPosition(0, 512/2 + 16);
      this->m_s.setRotation(180);
    }
    else if (dirShoot == 3) {
      this->m_s.setPosition(832 - 64, 512/2 - 16);
      this->m_s.setRotation(0);
    }
    shoot = true;
  }
  else {
    if (dirShoot == 0) {
      this->m_s.move(0, SPEED);
    }
    else if (dirShoot == 1) {
      this->m_s.move(0, -SPEED);
    }
    else if (dirShoot == 2) {
      this->m_s.move(SPEED, 0);
    }
    else if (dirShoot == 3) {
      this->m_s.move(-SPEED, 0);
    }

    if (this->m_s.getGlobalBounds().intersects(this->m_player.getGlobalBounds()))
    {
      shoot = false;
      if (dirShoot != playerDir)
        lives--;
      else
        Puntos++;
    }
  }

  std::stringstream sstm;
  sstm << "Vidas: " << lives;
  Vidas.setString(sstm.str());

  std::stringstream sstm2;
  sstm2 << "Puntos: " << Puntos;
  puntos.setString(sstm2.str());

  if (this->m_eventmng->getKey(sf::Keyboard::Up)) {
    playerDir = 0;
    this->m_player.setTextureRect(sf::IntRect(0,0,64,64));
  }
  else if (this->m_eventmng->getKey(sf::Keyboard::Down)) {
    playerDir = 1;
    this->m_player.setTextureRect(sf::IntRect(0,128,64,64));
  }
  else if (this->m_eventmng->getKey(sf::Keyboard::Left)) {
    playerDir = 2;
    this->m_player.setTextureRect(sf::IntRect(0,192,64,64));
  }
  else if (this->m_eventmng->getKey(sf::Keyboard::Right)) {
    playerDir = 3;
    this->m_player.setTextureRect(sf::IntRect(0,64,64,64));
  }
}

void MainGame::render (sf::Time deltatime) {
  this->m_window->draw(bg);
  this->m_window->draw(this->m_s);
  this->m_window->draw(this->m_player);
  this->m_window->draw(this->Vidas);
  this->m_window->draw(this->puntos);
}

MainGame::~MainGame() {

}
