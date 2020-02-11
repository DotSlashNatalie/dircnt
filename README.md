# dircnt

Very fast file/directory counter on Linux

It takes in a parameter of the folder you want to count. The program does not traverse into subdirectories.

Please note: If you use this program on a network mounted drive - it may count everything as unknown.

To compile:

`gcc -o dircnt dircnt.c`

Example output:

```
$ /volume1/homes/nadams/dircnt .
File stats
Block device - 0
Character device - 0
Directory - 445859
Named pipe - 0
Symbolic link - 0
Regular file - 0
Domain socket - 0
Unknown - 0
```