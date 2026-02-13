#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define TEST_COUNT 1000000

int main(int argc, char* argv[])
{   
    char buf = 'a';
    struct timespec t_start, t_end;
    int pipe1[2], pipe2[2];
    int count = 0;

    pipe(pipe1);
    pipe(pipe2);
    pid_t child_pid = fork();
    clock_gettime(CLOCK_MONOTONIC, &t_start);
    for(long i = 0; i < TEST_COUNT; ++i) {
        if(child_pid == 0) {
            read(pipe1[0], &buf, sizeof(buf));
            write(pipe2[1], &buf, sizeof(buf));
        } else {
            write(pipe1[1], &buf, sizeof(buf));
            read(pipe2[0], &buf, sizeof(buf));
        }
        count++;
    }
    clock_gettime(CLOCK_MONOTONIC, &t_end);
    double time_elapsed = ((t_end.tv_sec - t_start.tv_sec) + (t_end.tv_nsec - t_start.tv_nsec)/1e9);
    double result = count / time_elapsed;
    printf("Performed exchanges per second: %.2lf\n", result);
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);
}