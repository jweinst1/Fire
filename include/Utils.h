#ifndef FIRE_UTILS_H
#define FIRE_UTILS_H
//contains util macros

#include <math.h>

#define Utils_DBL_IS_INT(num) (num - floor(num) == 0.0)

//macro for preventing a zero number
#define Utils_NO_ZERO(num) (num ? num : 1)


#endif
