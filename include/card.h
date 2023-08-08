#ifndef __CARD_H__
#define __CARD_H__

#include "util.h"

#ifndef SUITS_STR
#define SUITS_STR

#define CLUBS_STR "Clubs"
#define DIAMONDS_STR "Diamonds"
#define HEARTS_STR "Hearts"
#define SPADES_STR "Spades"

#endif

#ifndef RANKS_STR
#define RANKS_STR

#define TWO_STR "Two"
#define THREE_STR "Three"
#define FOUR_STR "Four"
#define FIVE_STR "Five"
#define SIX_STR "Six"
#define SEVEN_STR "Seven"
#define EIGHT_STR "Eight"
#define NINE_STR "Nine"
#define TEN_STR "Ten"
#define JACK_STR "Jack"
#define QUEEN_STR "Queen"
#define KING_STR "King"
#define ACE_STR "Ace"

#endif

enum suit_e {Clubs, Diamonds, Hearts, Spades};
enum rank_e {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

typedef struct card_s {
    enum rank_e rank;
    enum suit_e suit; 
} card_t;


// This function assumes an empty buffer
int card_to_string(char *buffer, size_t buffer_size, card_t *card);

#endif
