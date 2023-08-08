#include "../include/util.h"

void log_error(const char *func_name, const char *msg) {
    printf("%s: ERROR - %s\n", func_name, msg);
}

void log_debug(const char *func_name, const char *msg) {
    printf("%s: TRACE - %s\n", func_name, msg);
}