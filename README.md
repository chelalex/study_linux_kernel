# Studing Linux Kernel History

## 14 Feb 2026

- *my_sleep.c* is a result of "Implement the UNIX program sleep; your sleep should pause for a user-specified number of ticks. A tick is a notion of time defined by the ~~xv6~~ linux kernel, namely the time between two interrupts from the timer chip."  
In another aspect with default *sleep* command, *my_sleep* launches with only cpu ticks value, then uses *clock_nanosleep* syscall. This code uses C23 standard.  
There is the output results:
```
user@host:~$ ./my_sleep 48000000
[GOOD] my_sleep worked for 1.000000 sec :)
user@host:~$ ./my_sleep 480000000
[GOOD] my_sleep worked for 10.000000 sec :)
user@host:~$ ./my_sleep 480070000
[GOOD] my_sleep worked for 10.001458 sec :)
user@host:~$ ./my_sleep 48000000ede
[ERROR] There is non-digital symbols: ede
user@host:~$ ./my_sleep c48000000
[ERROR] The first symbol of argument isn't digital
user@host:~$ ./my_sleep -480070000
[ERROR] The value must be non-negative
user@host:~$ ./my_sleep 480070000480070000480070000480070000480070000480070000480070000
[ERROR] my_sleep got out-of-range value :(
user@host:~$ ./my_sleep
[ERROR] my_sleep didn't get any arguments :(
user@host:~$ ./my_sleep 48000000 344r5
[ERROR] my_sleep got more than 1 argument :(
```

## 13 Feb 2026

- *ping-pong.c* is a result of "Write a program that uses UNIX system calls to “ping-pong” a byte between two processes
over a pair of pipes, one for each direction. Measure the program’s performance, in ex-
changes per second."  
There is the output result:
```
user@host:~$ ./ping-pong
Performed exchanges per second: 36773.84
Performed exchanges per second: 36775.16
```