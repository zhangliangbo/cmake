//
// Created by Admin on 2019/12/12.
//
#include <cmath>
#include "TutorialConfig.h"
#include "MathFunctions.h"

double mysqrt(double in) {
    double result;
#if defined(HAVE_LOG) && defined(HAVE_EXP)
    result = exp(log(in) * 0.5);
#else
    result= in;
#endif
    return result;
}
