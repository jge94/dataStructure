//#include "stdafx.h"
// enums.h

// types we created for nice names (rather than using integers)

#ifndef ENUMS
#define ENUMS

enum OBJECT  {ROCK='r',  HOLE='h',  GOAL='G', OPEN='.',  UNKNOWN='u', ROBOT='@', BEENHERE='x'};

enum DIRECTIONS {right=0, up = 1, left = 3, down = 4};

#endif
