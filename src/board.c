#include <assert.h>
#include "board.h"

struct board {
    const Player *squares[BOARD_SIZE];
};

static const char defaultDisplay[BOARD_SIZE] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9',
};

Board *Board_new(void) {
    Board *new = calloc(BOARD_SIZE, sizeof(Player *));
    return new;
}

void Board_destroy(const Board *this) {
    assert(this != NULL);
    free((void *)this);
}

bool Board_tryMark(Board *this, int square, const Player *player) {
    assert(this != NULL);
    assert(BOARD_IS_VALID_INDEX(square));

    if(Board_isSetAt(this, square)) {
        return false;
    }

    this->squares[square] = player;
    return true;
}

const Player *Board_getAt(const Board *this, int square) {
    assert(this != NULL);
    assert(BOARD_IS_VALID_INDEX(square));

    return this->squares[square];
}

bool Board_isSetAt(const Board *this, int square) {
    return Board_getAt(this, square) != NULL;
}

bool Board_hasPlayerAt(const Board *this, int square, const Player *player) {
    return Board_getAt(this, square) == player;
}

bool Board_isGameover(const Board *this) {
    assert(this != NULL);

    for(int i = 0; i < BOARD_SIZE; ++i) {
        if(!Board_isSetAt(this, i)) {
            return false;
        }
    }   

    return true;
}

char *Board_toString(const Board *this) {
    static const int charsPerSquare = 3; /* display as left bracket, number, and right bracket, e.g. "[n]" */
    static const int rowLength = 3;

    assert(this != NULL);

    /* allocate room for each square, plus newlines, plus terminating nul */
    char *result = malloc(((BOARD_SIZE * charsPerSquare) + (BOARD_SIZE / rowLength) + 1) * sizeof(char));
    char *p = result;

    for(int i = 0; i < BOARD_SIZE; ++i) {
        char c = Board_isSetAt(this, i)
            ? Player_getSymbol(Board_getAt(this, i))
            : defaultDisplay[i];

        *p++ = '[';
        *p++ = c;
        *p++ = ']';

        /* append newline at the end of each row */
        if(i % rowLength == rowLength - 1) {
            *p++ = '\n';
        }   
    }   

    *p = '\0';
    return result;
}
