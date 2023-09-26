#ifndef MAIN_H
#define MAIN_H

#define STDIN_FD 0
#define STDOUT_FD 1
#define STDERR_FD 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmjkio.h"
#include "libmjkstd.h"
#include "ssd.h"

enum command_type
{
    NONVALID,
    WRITE,
    READ
};

int valid_command(const int argc, const char **argv);

#endif
