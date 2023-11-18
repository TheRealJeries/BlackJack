#ifndef __HAND_H__
#define __HAND_H__

#include "card.h"

typedef struct hand_s {
    card_t *cards;
    int num_cards;
}

#endif