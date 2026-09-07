#include <stdio.h>
#include "bitboard.h"

int main(void)
{
    Bitboard bb = 0ULL;
    
    set_bit(bb, e4);
    set_bit(bb, d5);
    set_bit(bb, f6);

    printf("Bitboard representation:\n");
    print_bitboard(bb);

    printf("\nNumber of bits set: %d\n", count_bits(bb));

    return 0;
}