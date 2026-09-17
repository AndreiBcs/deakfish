#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>

typedef uint64_t Bitboard;

enum 
{
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1, no_sq
};

extern const char *square_to_coordinates[64];

enum
{
    WHITE, BLACK
};

enum
{
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H
};

enum
{
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8
};

enum
{
    PAWN = 1, KNIGHT = 3, BISHOP = 3, ROOK = 5, QUEEN = 9, KING = 1000
};

enum
{
    MOVED, NOT_MOVED
};

int pawnMoves = 8;
int pawnAttacks[2] = {7, 9};
int knightMoves[8] = {6, 10, 15, 17, -6, -10, -15, -17};
int bishopMoves[4] = {7, 9, -7, -9};
int rookMoves[4] = {8, -8, 1, -1};
int queenMoves[8] = {7, 9, -7, -9, 8, -8, 1, -1};
int kingMoves[8] = {7, 9, -7, -9, 8, -8, 1, -1};

extern Bitboard* whitePawns;
extern Bitboard* whiteKnights;
extern Bitboard* whiteBishops;
extern Bitboard* whiteRooks;
extern Bitboard* whiteQueens;
extern Bitboard* whiteKing;

extern Bitboard* blackPawns;
extern Bitboard* blackKnights;
extern Bitboard* blackBishops;
extern Bitboard* blackRooks;
extern Bitboard* blackQueens;
extern Bitboard* blackKing;

extern Bitboard* whiteKingAndRooks;
extern Bitboard* blackKingAndRooks;
extern Bitboard* whitePieces;
extern Bitboard* blackPieces;
extern Bitboard* allPieces;

#define get_bit(bb, sq) ((*(bb)) & (1ULL << (sq)))
#define set_bit(bb, sq) ((*(bb)) |= (1ULL << (sq)))
#define pop_bit(bb, sq) ((*(bb)) &= ~(1ULL << (sq)))
#define count_bits(bb) (__builtin_popcountll(*(bb)))

void printBitboard(Bitboard* bb);
void initBitboards();

#endif