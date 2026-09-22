#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
above #ifndef, #define, and lastly, #endif is helping us to guard against multi file declration or inclusion of classess/definations/variables.. this would only define once, no matter how many times you put it in.. compiler preprocessor would handle it. and no error would be thrown..

if you look closely, #include "constants.h" is put into main.cpp AND cylinder.h file as well. it could've caused problem but not anymore..

*/

const double PI{3.1415926536};

#endif