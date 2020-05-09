#include "player.hpp"

Player::Player(std::string name, std::vector<Card *> *cards)
{
  this->name = name;
  this->cards = cards;
}

Player::~Player()
{
  delete this->cards;
}
