#include "player.hpp"
#include "card.hpp"

class PlayerService
{
public:
  PlayerService(Player * player);
  ~PlayerService();

  Card * PlayTopCard();
  void AddWinningCards(std::vector<Card *> *cards);
  bool HasCards();
private:
  Player *m_player;
};    

