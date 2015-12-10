#ifndef __START_SCREEN_HPP__
#define __START_SCREEN_HPP__

#include "State/State.hpp"

class StartScreen : public State {
  private:
    sf::Sprite m_player;
    sf::Texture m_playerTexture;

    sf::Font font;
    sf::Text text1;

    sf::Texture bgT;
    sf::Sprite bg;

  public:
    StartScreen(sf::RenderWindow* window, EventManager* events, StateManager* states);
    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~StartScreen();
};

#endif // __START_SCREEN_HPP__
