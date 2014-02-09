/**
 * mario.c
 *
 * Víctor J. Valbuena
 * victor@guegue.com
 *
 * Imprime una pirámide con la altura (>=0 <=23) definida por
 * la persona usuaria y dos espacios en el centro
 *
 * PST01 Hacker1 CS50.
**/

#include <stdio.h>
#include "cs50.h"

int main(void)
{

// Ask and check height
int height;

    do
    {
        printf("Height: ");
        height = GetInt(); 
    }
    while (height < 0 || height > 23);

//Loop of lines
    for (int lines = 1; lines <= height; lines++)
    {

//Print spaces
        for (int spaces = height -lines; spaces != 0; spaces--)
        {
            printf(" ");
	}
        
//Print hash
	int hash = lines;
	while (hash > 0)
	{
	    printf("#");
	    hash--;
	}

//Print spaces in between
    printf("  ");
