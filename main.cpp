#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <stddef.h>
#include <conio.h>
#include <string.h> 

#include <vector>

#define ROW 5
#define COL 5

#define strBuffer sizeof(char)*16

int main(int argc, char** argv)
{
    // Declare and initialize the bingo board as a 5x5 matrix.
    int mat[ROW][COL] =
    {
        {14, 20, 32, 52, 71,},
        {10, 27, 42, 55, 64,},
        {86, 23,  0, 58, 72,},
        {11, 28, 34, 56, 69,},
        {15, 25, 33, 53, 66}
    };

    // Print out the original bingo board.
    puts("B   I   N   G   O");
    puts("------------------");
    
    int iPrint, jPrint;
    int size = sizeof(int) * 5 / sizeof(int);

    for (iPrint = 0; iPrint < size; iPrint++) 
    {
        for (jPrint = 0; jPrint < size; jPrint++)
        {
            if (mat[iPrint][jPrint] == 7)
            {
                fputs("  ", stdout);
            }

            printf("%d  ", mat[iPrint][jPrint]);
        }
        putchar('\n');
    }
    putchar('\n');


    std::vector<int> store;
    while (store.size() <= 5 || store.capacity() < 8)
    {
        // Generate a random bingo value.
        int i;
        unsigned int tile = rand() % 100 + 1;
        
        const char str_input[strBuffer] = "", str_output[strBuffer] = "roll";
        // Prompt for input and check that 
        fputs("Enter \"roll\" to roll a number: ", stdout);
        scanf_s("%s", &str_input, strBuffer);
    
        if (strcmp(str_input, str_output) == 0) 
        {
            // Roll a random value and print result.
            for (i = 0; i < 1; i++)
            {
                tile;
                printf("You rolled: [%d]\n", tile);
            }
            fflush(stdout);
        }
        else
        {
            putchar('\n');
            puts("[ERROR] unrecognized input");
            return 74;
        }
        putchar('\n');

        // Go through the matrix and check if there is a match on tile.
        int xCheck, yCheck;
        std::vector<int>::iterator iter; 
    
        fputs("Generated rolls: ", stdout); 
        putchar('[');
        for (xCheck = 0; xCheck < size; xCheck++)
        {
            for (yCheck = 0; yCheck < size; yCheck++)
            {
                if (mat[xCheck][yCheck] == tile)
                {
                    store.push_back(tile);
                }
                else if (mat[xCheck][yCheck] != tile)
                {
                    continue; 
                }
            }
        }

        // Print the results
        for (iter = store.begin(); iter != store.end(); iter++)
        {
            printf("%d", *iter);
            if (iter == store.end() - 1)
            {
                break;
            }
            putchar(',');
            putchar(' ');
            if (store.size() > 5  || store.capacity() > 8)
            {
                putchar(']');
                fputs("\n\n", stdout);
                puts("(0xE)_ERROR::OUT::OF::MEMORY");
                puts("ERROR::INSUFFICIENT::BUFFER");
                return 14;
            }
        }
        putchar(']');
        putchar('\n');

        // Print all stored tiles within the vector array
        // as long as the size is 5 or capacity is of size.
        if (store.size() == 5 || store.capacity() == size)
        {
            fputs("Total rolls: ", stdout);
            putchar('[');
            for (iter = store.begin(); iter != store.end(); ++iter)
            {
                printf("%d", *iter);
                if (iter == store.end() - 1)
                {
                    break;
                }
                putchar(',');
                putchar(' ');
            }
            putchar(']');
            fputs("\n\n", stdout);
            printf("Array has reached max capacity: cap.[%zd]", store.size()); 
        }

        // Go through the matrix and replace the elment with a tile.
        int conv_ascii = -1;
        for (xCheck = 0; xCheck < size; xCheck++)
        {
            for (yCheck = 0; yCheck < size; yCheck++)
            {
                if (mat[xCheck][yCheck] == tile)
                {
                    mat[xCheck][yCheck] = (char)conv_ascii;
                    break;
                }
            }
        }
        fputs("\n\n", stdout);
        
        puts("B   I   N   G   O");
        puts("------------------");

        // Print a new matrix with the replaced element.
        for (iPrint = 0; iPrint < size; iPrint++) 
        {
            for (jPrint = 0; jPrint < size; jPrint++)
            {
                if (mat[iPrint][jPrint] == 7)
                {
                    fputs("  ", stdout);
                }
                printf("%d  ", mat[iPrint][jPrint]); 
            }
            putchar('\n');
        }
        putchar('\n');
    }
    putchar('\n');
    return EXIT_SUCCESS;
}
