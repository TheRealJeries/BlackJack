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

    snprintf(buffer, buffer_size, "%s (%d) of %s", rank, card_value(card), suit);
    return SUCCESS;
}

// Returns the card value as an integer or -1 in case of an error
int card_value(card_t *card) {
    int res = -1;
    if (!card) {
        log_error(__func__, "card is NULL");
        return res;
    }

    switch (card->rank) {
        case Two:
            res = 2;
            break;
        case Three:
            res = 3;
            break;
        case Four:
            res = 4;
            break;
        case Five:
            res = 5;
            break;
        case Six:
            res = 6;
            break;
        case Seven:
            res = 7;
            break;
        case Eight:
            res = 8;
            break;
        case Nine:
            res = 9;
            break;
        case Ten:
            res = 10;
            break;
        case Jack:
            res = 10;
            break;
        case Queen:
            res = 10;
            break;
        case King:
            res = 10;
            break;
        case Ace:
            res = 11;
            break;
        default:
            log_error(__func__, "Unexpected card rank");
            res = -1;
    }

    return res;
}

