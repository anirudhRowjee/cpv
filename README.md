# cpv - a C++ clone of `pv`

This is a very WIP project I'm building to learn how to use and write C++.

## Why

Writing a systems-level program like a pipeviewer clone is a great way to get
used to the basics in any systems programming language, as it teaches you

1. I/O Buffering and handling
2. Parallelism and Memory Sharing between threads
3. Structures

## Usage

Ensure that you have a functioning C++ build toolchain. As of right now I have
no clue what this means, so I'll update this when I learn more.

To compile -

```bash
$ make
g++ main.cpp -o main
```

To use -

```bash
$ ./main < /usr/bin/yes > /dev/null
# lots of stuff
# ...
20999 Bytes in 0 seconds
```

## Refactor Plan

1. Implement Reader loop, metrics proc loop, writer loop
2. Implement Ring Buffer / Channel Abstraction
   (https://youtu.be/KBZlN0izeiY?si=qw5ae03yOfdoCx5M&t=291)
3. Channel: RingBuffer, Mutex, Start and End index
4. Implement consecutive thread spawning and waiting
