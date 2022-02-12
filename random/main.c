#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));
    int r;
    for (int i = 0; i<10; ++i)
    {
        r = rand();
        printf("%d\n", r);
    }
    return 0;
}