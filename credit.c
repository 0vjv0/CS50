/**
 * credit.c
 *
 * Víctor J. Valbuena
 * victor.j.valbuena@gmail.com
 *
 * Pide un número de tarjeta de crédito y determina si es 
 * válido o no (suma de los dígitos en posiciones impares + 
 * dígitos impares multiplicados por dos, y la suma de los
 * dígitos de los resultados si son más de 1)
 * e indica si es Master (empieza por 50, 51, 52, 53, 54 o
 * 55), Amex (empieza por 34 o 37) o Visa (empieza por 4) 
 *
 * PST01 Hacker1 CS50.
**/


#include <stdio.h>
#include <cs50.h>

int main(void)
{

// Pide número de tarjeta
    printf("Number: \n");
    long long numero = GetLongLong();

    int impar, par, parb, sumaimpar=0, sumapar=0, suma=0, decenas, unidades;

// Comienza loop hasta final de número de dígitos
    do
    {

// Define dígitos en posiciones impares (primero, tercero...) y las suma
        impar = numero % 10;
	sumaimpar = sumaimpar + impar;

// Divide por 10 para eliminar un dígito del número de la tarjeta
        numero = numero / 10;
		
// Define dígitos en posiciones pares, los multiplica por dos, suma sus dígitos si son más de 1 y obtiene la suma total 
        if (numero % 10 != 0)
	{
	    par = numero % 10;
	    parb = par * 2;
            if (parb > 9)
            {
                decenas = parb / 10;
                unidades = parb % 10;
                parb = decenas + unidades;
            }
            sumapar = sumapar + parb;
        }

// Divide por 10 para eliminar un dígito
        numero = numero / 10;
    }
    while (numero > 0);

//Suma total
 suma = sumapar + sumaimpar;

// Define si el número es válido o no
    if (suma % 10 != 0)
    {
	printf("INVALID\n");
    }

//Determina de qué compañía es la tarjeta
        if (par == 5 && impar > 0 && impar < 6)
        {
            printf("MASTERCARD\n");
        }

        if ((impar == 3 && par == 4) || (impar ==3 && par == 7))
        {
            printf("AMEX\n");
        }

        if (par == 4 || impar == 4)
        {
            printf("VISA\n");
        }

    
}//main
