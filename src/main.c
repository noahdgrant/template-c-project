#include "logger.h"

int main() {
    logger_set_level(DEBUG);

    logger(DEBUG, __func__, "Debug");
    logger(INFO, __func__, "Info");
    logger(WARNING, __func__, "Warning");
    logger(ERROR, __func__, "Error");

    logger(INFO, __func__, "Placeholder test: %d + %d = %d", 2, 3, 2 + 3);
    logger(INFO, __func__, "Placeholder test: %c", 'c');
    logger(INFO, __func__, "Placeholder test: %s", "string");

    return 0;
}
