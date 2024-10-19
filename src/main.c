#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "logger.h"

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s [options]\n", program_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -h, --help              Display this help message and exit\n");
    fprintf(stderr, "  -l, --log <log_level>   Set the log level (TRACE, DEBUG, INFO, WARNING, ERROR, FATAL)\n");
}

int parse_args(int argc, char* argv[]) {
    int err_code = 1;
    int opt;
    static struct option long_options[] = {
        {"log", required_argument, 0, 'l'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "l:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 'l':
                logger_set_level(logger_level_from_string(optarg));
                err_code = 0;
                break;
            case 'h':
                print_usage(argv[0]);
                exit(0);
            default:
                print_usage(argv[0]);
                err_code = 1;
                break;
        }
    }

    return err_code;
}

int main(int argc, char* argv[]) {
    int err_code = 0;

    err_code = parse_args(argc, argv);
    if (err_code != 0) {
        return err_code;
    }

    logger(TRACE, __func__, "Trace");
    logger(DEBUG, __func__, "Debug");
    logger(INFO, __func__, "Info");
    logger(WARNING, __func__, "Warning");
    logger(ERROR, __func__, "Error");
    logger(FATAL, __func__, "Fatal");

    logger(INFO, __func__, "Placeholder test: %d + %d = %d", 2, 3, 2 + 3);
    logger(INFO, __func__, "Placeholder test: %c", 'c');
    logger(INFO, __func__, "Placeholder test: %s", "string");

    return 0;
}
