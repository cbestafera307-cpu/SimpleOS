#ifndef SIMPLEOS_CLEAR_H
#define SIMPLEOS_CLEAR_H

#include <stdio.h>

#define clear() printf("\033[2J\033[H")

#endif
