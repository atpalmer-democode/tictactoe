#ifndef SCORING_H
#define SCORING_H

#include <stdbool.h>
#include "board.h"
#include "player.h"

bool Scoring_isWinner(const Board *board, const Player *player);

#endif
