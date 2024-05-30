/*
    Proiect realizat în cadrul cursului de Priectarea Algoritmior, F.A.C.E., de către Jianu Dragoș Ștefan, student la Calculatoare și Tehnologia Informației cu predare in limba Românî, grupa 1.2A.

    Problema abordată:

    Scopul acestui proiect este transformarea unui fragment de cod, printr-un număr minim de operații, astfel încât să respecte o anumită regulă sintactică.

    Operații disponibile (cost unitar):

    1. Înlocuirea unui caracter
    2. Eliminarea unui caracter
    3. Inserarea unui caracter
    4. Schimbarea poziției a două caractere adiacente (ex: "fnuc" -> "func")

    Exemplu ilustrativ:

    * Regula: func(myFunction)
    * Cod inițial: fnuc(myFuncion
    * Operații necesare:
        1. Inversarea "n" cu "u"
        2. Adăugarea lui "t"
        3. Adăugarea lui ")"
    * Cost total: 3

    Strategia de rezolvare:

    Am ales să aplic programarea dinamică (DP) pentru a găsi soluția optimă. O matrice DP memorează costul minim pentru fiecare subproblemă, adică transformarea fiecărei secvențe din codul inițial în secvența corespunzătoare din regulă.

    Principiul DP:

    Pentru fiecare pereche de subsecvențe, se determină costul minim al transformării, analizând toate operațiile posibile și alegând-o pe cea mai eficientă. Acest proces se repetă iterativ, construind soluția finală pas cu pas.

    Observație importantă:

    Succesul acestei abordări depinde de definirea corectă a relațiilor de recurență și de inițializarea adecvată a matricei DP.

    Autor: Jianu Dragoș Ștefan, Calculatoare și Tehnologia Informației, Română, 1.2A
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "inputgenerator.h"
#include <string.h>
#include <time.h>
#define DIM 100005 //  Dimensiunea maximă a șirurilor este setată la 100.000, dar poate fi ajustată ușor pentru a gestiona și șiruri mai lungi.
char fragment_cod[DIM];
char regula[DIM];
int dp[DIM][DIM];
int MinOfTwo(int a, int b); // Am creat o funcție MinOfTwo pentru a determina minimul dintre două numere întregi, simplificând astfel codul principal.
int NrMinimOperatii(char regula[], char fragment_cod[], int dp[][DIM], int n, int m);



int main ()
{
        /*
        Exemplu de șiruri de intrare :
        fragment_cod: "fnuc(myFuncion"
        regula : "func(myFunction)"
        */
    int chosen_method;
    printf("0 = Exemplu document\n");
    printf("1 = Generare input de mana\n");
    printf("2 = Generare input complet aleatorie\n");
    printf("3 = Generare input aleatorie, dar fragment_cod seamana cu regula_sirului\n");
    printf("Alegeti metoda prin care doriti sa testati (doar numarul acesteia ) : ");
    scanf("%d",&chosen_method);
    printf("\n");
    if(chosen_method==0)
    {
        char regula_exemplu[]="func(myFunction)";
        char fragment_cod_exemplu[]="fnuc(myFuncion";
        int n=strlen(regula_exemplu);
        int m=strlen(fragment_cod_exemplu);
        printf("Sirul regula este: %s",regula_exemplu);
        printf("\nFragmentul de cod este: %s",fragment_cod_exemplu);
        int exemplu_operatii=NrMinimOperatii(regula_exemplu,fragment_cod_exemplu,dp,n,m);
        printf("\nNumarul minim de operatii necesare pentru a transforma fragmentul de cod intr-un cod valid este egal cu : ");
        printf("%d",exemplu_operatii);
        printf("!\n");
    }
    else if(chosen_method==1)
    {
        printf("Introduceti codul care va defini regula programului  : ");
        scanf("%s",regula);
        printf("Introduceti fragmentul de cod dorit: ");
        scanf("%s",fragment_cod);
        int n=strlen(regula); //  Numărul de caractere din șirul care definește regula.
        int m=strlen(fragment_cod); // Numărul total de caractere din șirul ce reprezintă fragmentul de cod de verificat.
        int nr=NrMinimOperatii(regula,fragment_cod,dp,n,m); // Rezultatul final al calculului, reprezentând numărul minim de operații necesare pentru transformare.
        printf("Numarul minim de operatii pentru a ajunge la un cod valid de la fragmentul introdus este egal cu ");
        printf("%d",nr);
        printf("!\n");
    }
    else if(chosen_method==2)
    {
        srand((unsigned int)time(NULL)); // Inițializăm generatorul de numere aleatoare pentru a asigura generarea unor șiruri diferite la fiecare rulare a programului.
        printf("Cat de lung doriti sa fie sirul regula? ");
        int rule_length;
        scanf("%d",&rule_length);
        char *regula_sirului;
        char *cod_proba;
        printf("\nCat de lung doriti sa fie fragmentul de cod? "); // Dimensiunea șirului de caractere.
        int fragment_length;
        scanf("%d",&fragment_length);
        regula_sirului=random_string(rule_length);
        cod_proba=random_string(fragment_length);
        if(regula_sirului)
        {
            printf("Sirul regula generat RANDOM este: ");
            printf("%s",regula_sirului);
            printf("\n");
        }
        else
            printf("Alocarea de memorie a dat GRES!\n");
        if(cod_proba)
        {
            printf("Fragmentul de cod generat RANDOM este: ");
            printf("%s",cod_proba);
            printf("\n");
        }
        else
            printf("Alocarea de memorie a dat GRES!\n");
        printf("Numarul minim de operatii pentru a ajunge la un cod valid de la fragmentul introdus este egal cu: ");
        int number_of_operations=NrMinimOperatii(regula_sirului,cod_proba,dp,rule_length,fragment_length); // Numărul minim de operații necesar pentru a transforma fragmentul de cod în conformitate cu regula.
        printf("%d",number_of_operations);
        printf("!\n");
        free(regula_sirului);
        free(cod_proba);
    }
    else if(chosen_method==3)
    {
        srand((unsigned int)time(NULL)); //  Inițializăm generatorul de numere aleatoare cu time(NULL) pentru a asigura generarea de șiruri diferite la fiecare rulare.
        int lungime_sir_regula;
        printf("Cat de lung doriti sa fie sirul regula? ");
        scanf("%d",&lungime_sir_regula);
        char *sir_regula;
        sir_regula=random_string(lungime_sir_regula);
        char *fragment_cod_similar;
        if(sir_regula)
        {
            printf("Sirul regula generat RANDOM este: ");
            printf("%s",sir_regula);
            printf("\n");
        }
        else
            printf("Alocarea de memorie a dat GRES!\n");
        fragment_cod_similar=similar_string_generator(sir_regula);
        if(fragment_cod_similar)
        {
            printf("Fragmentul de cod generat RANDOM, dar totusi similar cu sirul regula este: ");
            printf("%s",fragment_cod_similar);
            printf("\n");
        }
        else
            printf("Alocarea de memorie a dat GRES!\n");
        int lungime_fragment_cod=strlen(fragment_cod_similar);
        int nr_operations=NrMinimOperatii(sir_regula,fragment_cod_similar,dp,lungime_sir_regula,lungime_fragment_cod);
        printf("Numarul minim de operatii pentru a ajunge la un cod valid de la fragmentul introdus este egal cu: ");
        printf("%d",nr_operations);
        printf("!\n");
        free(sir_regula);
        free(fragment_cod_similar);
    }
    else
    {
        printf("Metoda introdusa nu exista!\n");
        return 0;
    }
    return 0;
}

int MinOfTwo(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int NrMinimOperatii(char regula[DIM], char fragment_cod[DIM], int dp[DIM][DIM], int n, int m)
{
    // Inițializăm matricea dp. Prima linie și prima coloană reprezintă costurile de transformare a unui șir vid în prefixele șirului regula și, respectiv, fragment_cod.
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    //  Iterăm prin fiecare caracter al șirului regula și al șirului fragment_cod.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (regula[i] == fragment_cod[j]) // Verificăm dacă al i - lea caracter din regula este identic cu al j - lea caracter din fragment_cod.În caz afirmativ, nu este necesară nicio operație suplimentară pentru a ajunge la această poziție în matricea dp.

                dp[i + 1][j + 1] = dp[i][j];
            else
            {
                // În cazul în care caracterele analizate diferă, calculăm costul minim de transformare necesar pentru a face ca al j - lea caracter din fragment_cod să corespundă cu al i - lea caracter din regula.Luăm în considerare următoarele operații : înlocuire, ștergere, inserare și, opțional, inversiunea a două caractere adiacente.
                int insert_cost = dp[i + 1][j] + 1;
                int delete_cost = dp[i][j + 1] + 1;
                int replace_cost = dp[i][j] + 1;
                // Calculăm și costul asociat operației de inversiune a două caractere adiacente, dacă este cazul.
                if (regula[i - 1] == fragment_cod[j] && regula[i] == fragment_cod[j - 1])
                {
                    int swap_cost = dp[i - 1][j - 1] + 1; // Inversarea caracterelor adiacente este o funcționalitate adăugată față de algoritmul standard "Edit Distance", oferind mai multă flexibilitate în transformarea șirurilor.
                    replace_cost = MinOfTwo(replace_cost, swap_cost);
                }
                /*
                  Explicație detaliată a liniei:

                  Această linie calculează costul minim de transformare pentru a ajunge la poziția (i+1, j+1) în matricea dp. Aceasta reprezintă costul de a transforma primele i+1 caractere din șirul `regula` în primele j+1 caractere din șirul `fragment_cod`.

                  Pentru a înțelege mai bine, să analizăm fiecare componentă:

                  1. dp[i+1][j]: Reprezintă costul minim de transformare până la poziția (i+1, j) în matrice. Aceasta înseamnă că am transformat deja primele i+1 caractere din `regula`, dar nu am luat încă în considerare caracterul j+1 din `fragment_cod`.

                  2. dp[i][j+1]: Similar, reprezintă costul minim de transformare până la poziția (i, j+1). Am transformat primele j+1 caractere din `fragment_cod`, dar nu am luat în considerare caracterul i+1 din `regula`.

                  3. dp[i][j]: Reprezintă costul minim de transformare până la poziția (i, j), adică am transformat deja primele i caractere din `regula` în primele j caractere din `fragment_cod`.

                  4. +1: Adăugăm 1 la valoarea minimă dintre cele trei opțiuni de mai sus. Acest +1 reprezintă costul unei operații suplimentare (inserare, ștergere sau înlocuire) necesară pentru a transforma caracterul de la poziția (i+1, j+1) din `fragment_cod` în caracterul corespunzător din `regula`.

                  În concluzie, această linie calculează costul minim de a transforma prefixele celor două șiruri până la poziția curentă, luând în considerare toate operațiile posibile și alegând varianta cu costul cel mai mic.
               */

                dp[i + 1][j + 1] = MinOfTwo(MinOfTwo(insert_cost, delete_cost), replace_cost);
            }
        }
    }
    // Se returnează valoarea calculată, reprezentând numărul optim de operații pentru a transforma șirul fragment_cod în șirul regula.
    return dp[n][m];
}
