#ifndef __DECK_H__
#define __DECK_H__

#include "card.h"

#define CARDS_PER_SUIT 13
#define SUITS_PER_DECK 4
#define CARDS_PER_DECK (CARDS_PER_SUIT * SUITS_PER_DECK)

typedef struct deck_s {
   card_t cards[CARDS_PER_DECK];
} deck_t;

int init_deck(deck_t *deck);

#endif
