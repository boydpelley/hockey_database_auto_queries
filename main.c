#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_team_name(char * buffer)
{
    char * name = NULL;
    char * delim = " ";
    char * token;
    char * last_s = NULL;
    char * temp;

    token = strtok((char *)buffer, delim);

    while (token != NULL)
    {
        if (token[strlen(token) - 1] == 's')
        {
            last_s = token;
        }
        token = strtok(NULL, delim);
    }

    if (last_s != NULL)
    {
        size_t length = last_s - buffer + strlen(last_s);

        name = (char *)malloc(length + 1);

        strncpy(name, buffer, length);
        name[length] = '\0';
    }

    return name;
}

void print_line(char * order_types, FILE * input)
{
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), input))
    {

    }
}

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
