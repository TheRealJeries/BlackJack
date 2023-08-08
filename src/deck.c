
#include "../include/util.h"
#include "../include/deck.h"

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
