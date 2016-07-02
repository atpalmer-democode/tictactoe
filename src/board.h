#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdlib.h>
#include "player.h"

#define BOARD_SIZE 9

#define BOARD_IS_VALID_INDEX(index) ((index) >= 0 && (index) <= 8)

typedef struct board Board;

Board *Board_new(void);
void Board_destroy(const Board *this);
bool Board_tryMark(Board *this, int square, const Player *player);
const Player *Board_getAt(const Board *this, int square);
bool Board_isSetAt(const Board *this, int square);
bool Board_hasPlayerAt(const Board *this, int square, const Player *player);
char *Board_toString(const Board *this);
bool Board_isGameover(const Board *this);

#endif
