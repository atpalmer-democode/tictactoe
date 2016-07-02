#include <assert.h>
#include <stdlib.h>
#include "player.h"

struct player {
    const char symbol;
};

static const struct {
    const Player x;
    const Player o;
} players = {
    .x = {.symbol = 'X'},
    .o = {.symbol = 'O'},
};

char Player_getSymbol(const Player *player) {
    assert(player != NULL);
    return player->symbol;
}

const Player *Player_getFromSymbol(char symbol) {
    assert(symbol == players.o.symbol || symbol == players.x.symbol);
    return (players.o.symbol == symbol) ? &players.o : &players.x;
}

void Player_next(const Player **playerPtr) {
    assert(playerPtr != NULL);
    assert(*playerPtr == &players.x || *playerPtr == &players.o);

    *playerPtr = (&players.x == *playerPtr) ? &players.o : &players.x;
}
