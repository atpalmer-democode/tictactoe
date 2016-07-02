#include <stdio.h>
#include "scoring.h"
#include "board.h"
#include "player.h"

#define PRINTF_HEADING(template, ...) { printf("\n" template "\n" "%s\n", ##__VA_ARGS__, "---------"); }

/*
 * ASCII codes for '1'-'9' have offset of 49 from array indexes 0-8.
 */
#define TO_BOARD_INDEX_FROM_ASCII(input) ((int)input - 49)

static char nextNonNewline(void) {
    char input = getchar();

    /* flush stdin */
    if(input != '\n') {
        while(getchar() != '\n');
    }

    return input;
}

static int getSquareFromConsole(void) {
    printf("%s", "Choose a square> ");
    int square = TO_BOARD_INDEX_FROM_ASCII(nextNonNewline());
    return square;
}

static void boardToConsole(const Board *board) {
    char *boardString = Board_toString(board);
    printf("%s\n", boardString);
    free(boardString);
}

int main(void) {
    Board *board = Board_new();

    for(const Player *currPlayer = Player_getFromSymbol('X');; Player_next(&currPlayer)) {
        PRINTF_HEADING("%c's turn.", Player_getSymbol(currPlayer));
        boardToConsole(board);

        for(;;) {
            int square = getSquareFromConsole();

            if(!BOARD_IS_VALID_INDEX(square)) {
                fprintf(stderr, "%s\n", "Select a number 1-9.");
                continue;
            }

            if(!Board_tryMark(board, square, currPlayer)) {
                fprintf(stderr, "%s\n", "That square is already selected.");
                continue;
            }

            break;
        }

        if(Scoring_isWinner(board, currPlayer)) {
            PRINTF_HEADING("%c WINS!!!", Player_getSymbol(currPlayer));
            boardToConsole(board);
            break;
        }

        if(Board_isGameover(board)) {
            PRINTF_HEADING("%s", "TIE!!!");
            boardToConsole(board);
            break;
        }
    }

    Board_destroy(board);
    puts("GAME OVER!\n");
}
