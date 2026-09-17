#include <stdio.h>
#include "bitboard.h"

int main(void)
{
    initBitboards();

    printBitboard(whitePawns);
    printBitboard(whiteKnights);
    printBitboard(whiteBishops);
    printBitboard(whiteRooks);
    printBitboard(whiteQueens);
    printBitboard(whiteKing);

    return 0;
}