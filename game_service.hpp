#ifndef GAME_SERVICE_HPP
#define GAME_SERVICE_HPP

#include "player.hpp"
#include "card.hpp"
#include "player_service.hpp"

#define MAX_CARDS 52
#define PLAYER_CARDS 26

#include"deck.hpp"

class GameService
{
private:
  //members
  PlayerService * m_playerOne;
  PlayerService * m_playerTwo;
  Deck * m_deck;

  bool m_is_playing;
  //functions
  void Initialize();
  void compare_cards(Card * playerOneTopCard, Card *playerTwoTopCard, std::vector<Card *> * pot);
public:

  GameService();

  ~GameService();

  void Play();
};    

#endif
