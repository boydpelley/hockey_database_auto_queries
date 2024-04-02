#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char* argv[])
{

    printf("How many values per row is there?\nPlease enter a positive number.\n");
    short num_vals_per_row = 0;
    while (num_vals_per_row < 1) {
        scanf("%hd", &num_vals_per_row);
    }

    printf("\nWhat is the name of the database the data will be inserted into?\n");
    char database_name[50];
    fgets(database_name, sizeof(database_name), stdin);





    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Error with opening file.\n");
        return 1;
    }

}
