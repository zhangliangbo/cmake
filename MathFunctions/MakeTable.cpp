//
// Created by Admin on 2019/12/13.
//
// A simple program that builds a sqrt table
#include <cstdio>
#include <cmath>

int main(int argc, char *argv[]) {

    // make sure we have enough arguments
    if (argc < 2) {
        return 1;
    }

    double result;

    // open the output file
    FILE *fo = fopen(argv[1], "w");
    if (!fo) {
        return 1;
    }

    // create a source file with a table of square roots
    fprintf(fo, "double sqrtTable[] = {\n");
    int i;
    for (i = 0; i < 10; ++i) {
        result = sqrt(static_cast<double>(i));
        fprintf(fo, "%g,\n", result);
    }

    // close the table with a zero
    fprintf(fo, "0};\n");
    fclose(fo);
    return 0;
}
