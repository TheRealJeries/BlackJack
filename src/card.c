#include "../include/card.h"
#include "../include/util.h"

// This function assumes an empty buffer
int card_to_string(char *buffer, size_t buffer_size, card_t *card) {
    char *rank = NULL, *suit = NULL;
    size_t total_size = 0;
    if (!card) {
        log_error(__func__, "card is NULL");
        return ERROR;
    }

    if (!buffer) {
        log_error(__func__, "buffer is NULL");
        return ERROR;
    }

    if (buffer_size == 0) {
        log_error(__func__, "buffer size is 0");
        return ERROR;
    }

    // Do ranks
    switch (card->rank) {
        case Two:
            rank = TWO_STR;
            break;
        case Three:
            rank = THREE_STR;
            break;
        case Four:
            rank = FOUR_STR;
            break;
        case Five:
            rank = FIVE_STR;
            break;
        case Six:
            rank = SIX_STR;
            break;
        case Seven:
            rank = SEVEN_STR;
            break;
        case Eight:
            rank = EIGHT_STR;
            break;
        case Nine:
            rank = NINE_STR;
            break;
        case Ten:
            rank = TEN_STR;
            break;
        case Jack:
            rank = JACK_STR;
            break;
        case Queen:
            rank = QUEEN_STR;
            break;
        case King:
            rank = KING_STR;
            break;
        case Ace:
            rank = ACE_STR;
            break;
        default:
            log_error(__func__, "Unexpected card rank");
            return ERROR;
    }

    // Now do suits
    switch (card->suit) {
        case Clubs:
            suit = CLUBS_STR;
            break;
        case Diamonds:
            suit = DIAMONDS_STR;
            break;
        case Hearts:
            suit = HEARTS_STR;
            break;
        case Spades:
            suit = SPADES_STR;
            break;
        default:
            log_error(__func__, "Unexpected card suit");
            return ERROR;
    }

    total_size = strlen(rank) + strlen("of") + strlen(suit) + 1;
    if (total_size > buffer_size) {
        log_error(__func__, "buffer overflow prevented");
    }

    snprintf(buffer, buffer_size, "%s of %s", rank, suit);
    return SUCCESS;
}
