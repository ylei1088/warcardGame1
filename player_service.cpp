#include "player_service.hpp"

PlayerService::PlayerService(Player *player)
{
  this->m_player = player;
}

PlayerService::~PlayerService()
{
  delete this->m_player;
}

Card * PlayerService::PlayTopCard(){
  Card * topCard = this->m_player->cards->at(0);
  std::vector<Card*>::iterator it = this->m_player->cards->begin();
  this->m_player->cards->erase(it);
  return topCard;
}

void PlayerService::AddWinningCards(std::vector<Card *> *cards)
{
  for(Card * card : *cards){
    this->m_player->cards->push_back(card);
  }
}

bool PlayerService::HasCards()
{
  //empty returns true if there are no elements,
  //then we negate that to satisfy the method
  return !this->m_player->cards->empty();
}
