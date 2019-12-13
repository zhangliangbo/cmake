#include <cstdio>
#include <cmath>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double input = atof(argv[1]);
#ifdef USE_MYMATH
    double output = sqrt(input);
#else
    double output = sqrt(input);
#endif
    fprintf(stdout, "The square root of %g\n", input, output);
    return 0;
}
