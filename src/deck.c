
#include "../include/util.h"
#include "../include/deck.h"
#include <stdlib.h>
#include <time.h>


// Creates a deck and returns SUCCESS or ERROR.
int init_deck(deck_t *deck) {
    enum rank_e rank_idx;
    enum suit_e suit_idx;
    int deck_idx = 0;
    log_debug(__func__, "Called");

    if (!deck) {
        log_error(__func__, "Deck is NULL");
        return ERROR;
    }

    for (suit_idx = Clubs; suit_idx <= Spades; suit_idx++) {
        for (rank_idx = Two; rank_idx <= Ace; rank_idx++) {
            deck->cards[deck_idx].rank = rank_idx;
            deck->cards[deck_idx].suit = suit_idx;
            deck_idx++;
        }
    }
    log_debug(__func__, "Deck Initialized");
    return SUCCESS;
}

int shuffle_deck(deck_t *deck) {
    int first_card_idx = 0;
    int second_card_idx = 0;
    card_t temp;
    log_debug(__func__, "Called");

    if (!deck) {
        log_error(__func__, "Deck is NULL");
        return ERROR;
    }

    /* initialize random seed: */
    srand(time(NULL));
    /* Fisher-Yates Shuffle */
    for (first_card_idx = CARDS_PER_DECK - 1; first_card_idx >= 0; first_card_idx--) {
        /* generate secret number between 0 and first_card_idx */
        second_card_idx = rand() % (first_card_idx + 1);
        printf("Swapping %d with %d\n", first_card_idx, second_card_idx);
        /* swap */
        temp = deck->cards[first_card_idx];
        deck->cards[first_card_idx] = deck->cards[second_card_idx];
        deck->cards[second_card_idx] = temp;
    }

    return SUCCESS;
}

int cut_deck(void) {
    int last_card = 0;
    srand(time(NULL));
    last_card = rand() % (CARDS_PER_DECK);
    if (last_card < CARDS_PER_DECK / 2) {
        last_card = CARDS_PER_DECK - last_card;
    }
    return last_card;
}
