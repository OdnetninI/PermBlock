#ifndef __MAIN_GAME_HPP__
#define __MAIN_GAME_HPP__

#include "State/State.hpp"

class MainGame : public State {
  private:
    sf::Sprite m_player;
    sf::Sprite m_s;
    sf::Texture m_playerTexture;
    sf::Texture m_sTexture;
    int i;
    sf::Time m_elapsedTime;
    int playerDir;
    bool shoot;
    int dirShoot;
    int lives;
    int Puntos;

    sf::Font pixeled;
    sf::Text Vidas;
    sf::Text puntos;

    sf::Texture bgT;
    sf::Sprite bg;

  public:
    MainGame(sf::RenderWindow* window, EventManager* events, StateManager* states);
    void update (sf::Time deltatime);
    void render (sf::Time deltatime);

    ~MainGame();
};

#endif // __MAIN_GAME_HPP__
