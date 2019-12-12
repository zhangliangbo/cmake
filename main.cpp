#include <cstdio>
#include <cmath>
#include "TutorialConfig.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout,"%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double input = atof(argv[1]);
    double output = sqrt(input);
    fprintf(stdout, "The square root of %g\n", input, output);
    return 0;
}
