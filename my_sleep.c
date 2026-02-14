#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BOGOMIPS 48000000 // that's BogoMIPS value from /proc/cpuinfo file

int main(int argc, char* argv[]) {
    switch (argc) {
        case 0:
            fprintf(stderr, "[ERROR] Something went wrong with my_sleep :(\n");
            exit(1);
        case 1:
            fprintf(stderr, "[ERROR] my_sleep didn't get any arguments :(\n");
            exit(1);
        case 2: {
            char *endptr;
            errno = 0;
            long cpu_ticks = strtol(argv[1], &endptr, 10);
            if (errno == ERANGE) {
                fprintf(stderr, "[ERROR] my_sleep got out-of-range value :(\n");
                exit(1);
            }
            if (endptr == argv[1]) {
                fprintf(stderr, "[ERROR] The first symbol of argument isn't digital\n");
                exit(1);
            }
            if (*endptr != '\0') {
                fprintf(stderr, "[ERROR] There is non-digital symbols: %s\n", endptr);
                exit(1);
            }
            if (cpu_ticks < 0) {
                fprintf(stderr, "[ERROR] The value must be non-negative\n");
                exit(1);
            }
            struct timespec sleep_time;
            double time = cpu_ticks / (double)BOGOMIPS;
            long time_s = (long) time;
            double time_ns = (time - time_s)*1e9;
            sleep_time.tv_sec = (time_t) time_s;
            sleep_time.tv_nsec = time_ns;
            clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, NULL);
            printf("[GOOD] my_sleep worked for %lf sec :)\n", time);
            exit(0);
        }
        default:
            fprintf(stderr, "[ERROR] my_sleep got more than 1 argument :(\n");
            exit(1);
    }
}