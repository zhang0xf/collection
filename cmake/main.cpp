#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../build/config.h"

#ifdef USE_MYMATH
#include "./mymath/mymath.h"
#else
#include <math.h>
#endif

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        // print version info
        printf("%s version %d.%d\n", argv[0], main_VERSION_MAJOR_TEST, main_VERSION_MINOR_TEST);
        printf("Usage:%s a b\n", argv[0]);
        return 1;
    }
    int ret = 0;

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

#ifdef USE_MYMATH
    printf("use ourself library\n");
    ret = mypow(a, b);
    printf("a + b is %d\n", ret);
#else
    printf("use system library\n");
#endif

#ifdef HAVE_POW
    printf("use standard lib : pow\n");
#else
    printf("use ourself lib : mypow\n");
#endif

    return 0;
}