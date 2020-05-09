#include "game_service.hpp"
#include <random>
#include <algorithm>
#include <chrono>
#include "deck.hpp"
#include <iostream>

GameService::GameService()
{
  this->m_deck = new Deck();
  this->Initialize();
}


GameService::~GameService()
{
  delete this->m_deck;
}    


void GameService::Play()
{
  this->m_is_playing = true;

  while(this->m_is_playing){
    //check if player one has cards
    if(!this->m_playerOne->HasCards()){
      this->m_is_playing = false;
      std::cout << "Player One Loses" << std::endl;
    }
    //check if player two has cards
    else if(!this->m_playerTwo->HasCards()){
      this->m_is_playing = false;
      std::cout << "Player Two Loses" << std::endl;
    }
    else {
      Card * playerOneTopCard = this->m_playerOne->PlayTopCard();

      Card * playerTwoTopCard = this->m_playerTwo->PlayTopCard();

      std::vector<Card *> * pot = new std::vector<Card *>();
      
    }
    
  }
}

void GameService::compare_cards(Card * playerOneTopCard, Card * playerTwoTopCard,
                                std::vector<Card *> * pot)
{
  if(playerOneTopCard->rank_order == playerTwoTopCard->rank_order){
    pot->push_back(playerOneTopCard);
    pot->push_back(playerTwoTopCard);
    Card * newPlayerOneTopCard = this->m_playerOne->PlayTopCard();
    Card * newPlayerTwoTopCard = this->m_playerTwo->PlayTopCard();
    this->compare_cards(newPlayerOneTopCard, newPlayerTwoTopCard, pot);
  }
  return;
}

void GameService::Initialize()
{
  std::vector<Card *> *playerOneCards = new std::vector<Card *>();

  for (int i = 0; i < PLAYER_CARDS; i++) {
    Card *card = this->m_deck->get_cards()->at(i);
    playerOneCards->push_back(card);
  }

  std::vector<Card *> *playerTwoCards = new std::vector<Card *>();
  for (int i = 27; i < MAX_CARDS; i++) {
    Card *card = this->m_deck->get_cards()->at(i);
    playerTwoCards->push_back(card);
  }

  Player *playerOne = new Player("Player One", playerOneCards);
  PlayerService *playerOneService = new PlayerService(playerOne);

  Player *playerTwo = new Player("Player Two", playerTwoCards);
  PlayerService *playerTwoService = new PlayerService(playerTwo);

  this->m_playerOne = playerOneService;
  this->m_playerTwo = playerTwoService;
}
