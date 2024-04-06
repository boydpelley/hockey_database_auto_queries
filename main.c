#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void generateSQLInsert(const char *data[], int numColumns) {
    printf("(");
    for (int i = 0; i < numColumns; ++i) {
        printf("'%s'", data[i]);
        if (i < numColumns - 1)
            printf(", ");
    }
    printf("),\n");
}


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

    FILE *csvFile = fopen(argv[1], "r");

    if (csvFile == NULL)
    {
        printf("Error with opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    printf("INSERT INTO defence (team_name, player_name, position, games_played, icetime_min, goals, "
           "assists, first_assists, second_assists, points, shifts, expected_goals, shots_on_goal)\nVALUES\n");
    while (fgets(line, sizeof(line), csvFile) && lineCount < 200) {
        char *token;
        const char *data[num_vals_per_row]; // Assuming maximum of 20 columns

        // Parse CSV line
        int numColumns = 0;
        token = strtok(line, ",");
        while (token != NULL && numColumns < num_vals_per_row) {
            data[numColumns++] = token;
            token = strtok(NULL, ",");
        }

        // Generate SQL INSERT statement
        generateSQLInsert(data, numColumns);

        lineCount++;
    }
    fclose(csvFile);
    return 0;

}
