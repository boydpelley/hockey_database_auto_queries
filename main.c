#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    printf("How many values per row is there?\nPlease enter a positive number.\n");
    short num_vals_per_row = 0;
    while (num_vals_per_row < 1) {
        scanf("%hd", &num_vals_per_row);
    }

    printf("\n\nWhat are the values in each row?\ni.e enter \"SSII\" for String String Int Int, etc.\n");

    char order_of_types[num_vals_per_row];

    for (int i = 0; i < num_vals_per_row; i++) {
        scanf(" %c", &order_of_types[i]);
    }


    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Error with opening file.\n");
        return 1;
    }



}
