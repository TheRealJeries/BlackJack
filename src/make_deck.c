
#include "../include/deck.h"
#include "../include/util.h"

int main() {
    int card_idx = 0;
    int res = SUCCESS;
    char buffer[64];
    deck_t deck = {0};
    res = init_deck(&deck);

    if (res != SUCCESS) {
        return res;
    }

    for (card_idx = 0; card_idx < CARDS_PER_DECK; card_idx++) {
        memset(buffer, 0, sizeof(buffer));
        res = card_to_string(buffer, sizeof(buffer), &deck.cards[card_idx]);
        if (res != SUCCESS) {
            return res;
        }
        printf("Got %s\n", buffer);
    }
    return res;
}