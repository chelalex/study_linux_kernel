# Studing Linux Kernel History

## 13 Feb 2026

Trying to use UNIX syscalls to “ping-pong” a byte between two processes over a pair of pipes, one for each direction.
I've used syscalls such as: fork(), pipe(), clock_gettime(), read() and write().
Manipulating with file descriptors