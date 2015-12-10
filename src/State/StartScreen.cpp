#include "State/StartScreen.hpp"
#include "State/MainGame.hpp"

StartScreen::StartScreen (sf::RenderWindow* window, EventManager* events, StateManager* states) {
  this->m_window = window;
  this->m_eventmng = events;
  this->m_statemng = states;

  this->font.loadFromFile("Data/font.ttf");
  this->text1.setFont(this->font);
  this->text1.setPosition(40, 250);
  this->text1.setColor(sf::Color::White);

  this->text1.setString("Press Enter to Start");

  bgT.loadFromFile("Data/MainScreen.png");
  bg.setTexture(bgT);
}

StartScreen::~StartScreen() {}

void StartScreen::update (sf::Time deltatime) {
  if (!this->m_eventmng->isFocused()) return;

  if (this->m_eventmng->getKey(sf::Keyboard::Return))
    this->m_statemng->pushLooped(new MainGame(m_window, m_eventmng, m_statemng));
}

void StartScreen::render (sf::Time deltatime) {
  this->m_window->draw(bg);
  this->m_window->draw(text1);
}
