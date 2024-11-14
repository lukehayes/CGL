#ifndef MATH_RAND_H
#define MATH_RAND_H

#include "stdlib.h"
#include "time.h"

int RandRangeI(int min, int max)
{
    return (int)(min + rand() % ( max - min + 1 ));
}

#endif // !MATH_RAND_H
