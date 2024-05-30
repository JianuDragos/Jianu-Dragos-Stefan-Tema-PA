// Explicațiile pentru fiecare funcție in parte sunt mai jos de program.


#include <stdio.h>
#include <stdlib.h>
#include "inputgenerator.h"
#include <time.h>
char *random_string(size_t length)
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!(){}`><-+@$%^&*~/:;\\";
    char *randomString = NULL;

    if (length)
    {
        randomString = malloc(length + 1);
        if (randomString)
        {
            for (size_t i = 0; i < length; i++)
            {
                int key = rand() % (sizeof(charset) - 1);
                randomString[i] = charset[key];
            }
            randomString[length] = '\0';
        }
    }

    return randomString;
}
char *similar_string_generator(char *source)
{
    size_t length = strlen(source);
    char *similarString = malloc(length + 1);
    if (!similarString)
    {
        return NULL;
    }
    strcpy(similarString, source);
    int num_errors = (rand() % length) + 1;
    for (int i = 0; i < num_errors; i++)
    {
        int error_type = rand() % 3;
        int pos = rand() % length;

        if (error_type == 0 && pos < length - 1)
        {
            char temp = similarString[pos];
            similarString[pos] = similarString[pos + 1];
            similarString[pos + 1] = temp;
        }
        else if (error_type == 1 && length > 1)
        {
            memmove(&similarString[pos], &similarString[pos + 1], length - pos);
            similarString[length - 1] = '\0';
            length--;
        }
        else if (error_type == 2)
        {
            similarString[pos] = 'a' + (rand() % 26);
        }
    }
    return similarString;
}
/*
    Funcția `random_string`:

    Această funcție generează un șir aleatoriu de caractere de lungimea specificată. Setul de caractere include litere (mici și mari), cifre și diverse simboluri.

    Pași:

    1. Inițializare:
        - Se primește lungimea dorită a șirului.
        - Se definește un set de caractere valide (static).
    2. Alocare memorie:
        - Se alocă memorie pentru șirul rezultat (plus un caracter pentru terminatorul nul).
    3. Generare caractere aleatoare:
        - Se parcurge fiecare poziție a șirului.
        - Se generează un index aleator în cadrul setului de caractere.
        - Se copiază caracterul corespunzător în șirul rezultat.
    4. Finalizare:
        - Se adaugă terminatorul nul la finalul șirului.
    5. Returnare:
        - Se returnează șirul generat.

    Funcția `similar_string_generator`:

    Această funcție creează un șir similar cu cel dat ca intrare, dar cu un număr aleatoriu de erori (inversări, ștergeri sau înlocuiri de caractere).

    Pași:

    1. Inițializare:
        - Se calculează lungimea șirului sursă.
    2. Alocare memorie:
        - Se alocă memorie pentru șirul similar.
    3. Copiere șir sursă:
        - Se copiază șirul sursă în șirul rezultat.
    4. Generare număr erori:
        - Se generează un număr aleator de erori (între 1 și lungimea șirului).
    5. Introducere erori:
        - Se iterează de atâtea ori câte erori trebuie introduse.
        - Se alege aleator tipul de eroare (inversare, ștergere, înlocuire).
        - Se introduce eroarea în șirul rezultat.
    6. Returnare:
        - Se returnează șirul modificat.
*/

