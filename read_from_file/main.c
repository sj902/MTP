#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: ./read_from_file file1 file2");
        exit(0);
    }

    FILE *in_file;
    int number1, ch, arr[100], arr2[100], i = 0;

    in_file = fopen(argv[1], "r");
    ch = getc(in_file);

    if (in_file == NULL)
    {
        printf("Can't open file 1 for reading.\n");
    }

    while(ch !=  EOF)
    {
        fscanf(in_file, "%d", &number1);
        arr[i++] = number1;
        printf("%d\n", number1);
        ch = getc(in_file);
    }
    fclose(in_file);


    printf("Now processing file 2\n");

    in_file = fopen(argv[2], "r");
    ch = getc(in_file);


    if (in_file == NULL)
    {
        printf("Can't open file 2 for reading.\n");
    }

    i = 0;

    while(ch!=EOF)
    {
        fscanf(in_file, "%d", &number1);
        arr2[i++] = number1;
        printf("%d\n", number1);
        ch = getc(in_file);
    }

    fclose(in_file);
    return 0;
}
