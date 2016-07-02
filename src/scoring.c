#include <assert.h>
#include "scoring.h"

#define ARRAY_SIZE(array) (int)(sizeof(array) / sizeof(*array))

static const int winPatterns[][BOARD_SIZE] = {
    /* across */
    {
        1, 1, 1,
        0, 0, 0,
        0, 0, 0,
    },

    {
        0, 0, 0,
        1, 1, 1,
        0, 0, 0,
    },

    {
        0, 0, 0,
        0, 0, 0,
        1, 1, 1,
    },

    /* down */
    {
        1, 0, 0,
        1, 0, 0,
        1, 0, 0,
    },

    {    
        0, 1, 0,
        0, 1, 0,
        0, 1, 0,
    },

    {
        0, 0, 1, 
        0, 0, 1, 
        0, 0, 1,
    },

    /* diag */
    {
        1, 0, 0, 
        0, 1, 0, 
        0, 0, 1,
    },

    {
        0, 0, 1, 
        0, 1, 0, 
        1, 0, 0,
    },
};

static bool patternIsMatch(const int pattern[], const Board *board, const Player *player) {
    for(int i = 0; i < ARRAY_SIZE(*winPatterns); ++i) {
        if(pattern[i] && !Board_hasPlayerAt(board, i, player)) {
            return false;
        }
    }

    return true;
}

bool Scoring_isWinner(const Board *board, const Player *player) {
    assert(board != NULL);
    assert(player != NULL);

    for(int i = 0; i < ARRAY_SIZE(winPatterns); ++i) {
        if(patternIsMatch(winPatterns[i], board, player)) {
            return true;
        }
    }

    return false;
}
