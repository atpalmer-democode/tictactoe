#ifndef PLAYER_H
#define PLAYER_H

typedef struct player Player;

char Player_getSymbol(const Player *this);
const Player *Player_getFromSymbol(char symbol);
void Player_next(const Player **playerPtr);

#endif
