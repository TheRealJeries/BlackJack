#include "../include/deck.h"
#include "../include/util.h"
#include "../include/hand.h"



int put_card_away(card_t *card, deck_t *end_deck) {
    
}

int play_game(deck_t *deck, deck_t *end_deck) {
    int card_idx = 0;
    hand_t dealer = {0};
    hand_t player = {0};
    hand_t *turn = &player;
    int res = SUCCESS;
    char buffer[64];
    memset(buffer, 0, sizeof(buffer));

    put_card_away()
    for (card_idx = 0; card_idx < CARDS_PER_DECK; card_idx++) {

    }

}

int main() {
    int res = SUCCESS;
    deck_t deck = {0};
    deck_t end_deck = {0};
    int last_card = 0;

    res = init_deck(&deck);

    if (res != SUCCESS) {
        return res;
    }

    printf("Shuffling\n");
    shuffle_deck(&deck);
    last_card = cut_deck();
    
    play_game(&deck);

    return res;
}