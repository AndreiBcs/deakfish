#include <stdio.h>
#include "bitboard.h"

const char *square_to_coordinates[64] = {
    "a8","b8","c8","d8","e8","f8","g8","h8",
    "a7","b7","c7","d7","e7","f7","g7","h7",
    "a6","b6","c6","d6","e6","f6","g6","h6",
    "a5","b5","c5","d5","e5","f5","g5","h5",
    "a4","b4","c4","d4","e4","f4","g4","h4",
    "a3","b3","c3","d3","e3","f3","g3","h3",
    "a2","b2","c2","d2","e2","f2","g2","h2",
    "a1","b1","c1","d1","e1","f1","g1","h1"
};

static Bitboard wPawns;
static Bitboard wKnights;
static Bitboard wBishops;
static Bitboard wRooks;
static Bitboard wQueens;
static Bitboard wKing;
static Bitboard bPawns;
static Bitboard bKnights;
static Bitboard bBishops;
static Bitboard bRooks;
static Bitboard bQueens;
static Bitboard bKing;
static Bitboard wPieces;
static Bitboard bPieces;
static Bitboard pieces;

Bitboard *whitePawns = &wPawns;
Bitboard *whiteKnights = &wKnights;
Bitboard *whiteBishops = &wBishops;
Bitboard *whiteRooks = &wRooks;
Bitboard *whiteQueens = &wQueens;
Bitboard *whiteKing = &wKing;
Bitboard *blackPawns = &bPawns;
Bitboard *blackKnights = &bKnights;
Bitboard *blackBishops = &bBishops;
Bitboard *blackRooks = &bRooks;
Bitboard *blackQueens = &bQueens;
Bitboard *blackKing = &bKing;
Bitboard *whitePieces = &wPieces;
Bitboard *blackPieces = &bPieces;
Bitboard *allPieces = &pieces;


void printBitboard(Bitboard* bb)
{
    for (int rank = 0; rank < 8; rank++) 
    {
        for (int file = 0; file < 8; file++) 
        {
            int square = rank * 8 + file;

            if (get_bit(bb, square)) 
            {
                printf("1 ");
            } 
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void initBitboards()
{
    *whitePawns = (255ULL << 48);
    *blackPawns = (255ULL << 8);
    *whiteKnights = (1ULL << 57) | (1ULL << 62);
    *blackKnights = (1ULL << 1) | (1ULL << 6);
    *whiteBishops = (1ULL << 58) | (1ULL << 61);
    *blackBishops = (1ULL << 2) | (1ULL << 5);
    *whiteRooks = (1ULL << 56) | (1ULL << 63);
    *blackRooks = (1ULL << 0) | (1ULL << 7);
    *whiteQueens = (1ULL << 59);
    *blackQueens = (1ULL << 3);
    *whiteKing = (1ULL << 60);
    *blackKing = (1ULL << 4);
    *whitePieces = *whitePawns | *whiteKnights | *whiteBishops | *whiteRooks | *whiteQueens | *whiteKing;
    *blackPieces = *blackPawns | *blackKnights | *blackBishops | *blackRooks | *blackQueens | *blackKing;
    *allPieces = *whitePieces | *blackPieces;
}