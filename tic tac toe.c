#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void board(char points[])
{
    system("clear");
    int line = 8, j;
    for (int i = 1; i < 10; i++)
    {
        j = points[i - 1];
        printf("\t%c\t", j);
        if (i % 3 == 0 && i < 8)
        {
            printf("\n\n");
            while (line != 0)
            {
                printf("___   ");
                line--;
            }
            printf("\n\n");
            line = 8;
        }
        else if (i < 9)
        {
            printf("|");
        }
    }
    printf("\n\n");
}

int checkwin(char points[], int *filled)
{
    for (int i = 0; i < 3; i++)
    {
        //if corner is digit, line isn't possible
        if (isdigit(points[i]) || isdigit(points[i * 3]))
        {
            break;
        }
        //horizontal
        else if (points[(i * 3)] == points[(i * 3) + 1] && points[(i * 3) + 1] == points[(i * 3) + 2])
        {
            return 1;
        }
        //vertical
        else if (points[i] == points[i + 3] && points[i + 3] == points[i + 6])
        {
            return 1;
        }
        //diagonal
        else if (i % 2 == 0)
        {
            if (points[i] == points[4])
            {
                if (i == 0 && points[i] == points[8])
                    return 1;
                else if (i == 2 && points[i] == points[6])
                    return 1;
            }
        }
    }
    for (int k= 0; k <= 10; k++)
    {
        if (isdigit(points[k]))
        {
            break;
        }
        if(k == 9){
            *filled = 1;
        }
    }
    return 0;
}

void main()
{
    char points[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turn = 2, choice = 0, filled = 0;
    char current_player = ' ';
    char player1 = 'X', player2 = 'O';
    board(points);
    while (!checkwin(points, &filled) && !filled)
    {
        turn = (turn == 2) ? 1 : 2;
        current_player = (turn == 2) ? player2 : player1;
        printf("\n\nEnter index for %c:\n", current_player);
        while (!choice)
        {
            scanf("%d", &choice);
            if (choice > 0 && choice < 10 && isdigit(points[choice - 1]))
            {
                points[choice - 1] = current_player;
            }
            else
            {
                choice = 0;
                printf("Enter correct position for %c", current_player);
            }
        }
        board(points);
        choice = 0;
    }
    if(!filled)
        printf("\n\n***Player %c has won the game***", current_player);
    else
        printf("\n\n***!!!Draw!!!***");
}