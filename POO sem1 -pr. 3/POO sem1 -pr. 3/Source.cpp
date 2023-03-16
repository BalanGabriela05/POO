#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char sentence[1000];

    printf("Propozitia citita : ");

    scanf("%[^\n]s", sentence);
    char* words[100];
    int poz = 0;
    char* a = strtok(sentence, " ");
    while (a != NULL)
    {
        words[poz++] = a;
        a = strtok(NULL, " ");
    }
    for (int i = 0; i < poz; i++)
    {
        for (int j = i + 1; j < poz; j++)
        {
            if (strlen(words[i]) < strlen(words[j]))
            {
                char* aux = words[i];
                words[i] = words[j];
                words[j] = aux;
            }
            else if (strlen(words[i]) == strlen(words[j]) && strcmp(words[i], words[j]) > 0)
            {
                char* aux = words[i];
                words[i] = words[j];
                words[j] = aux;
            }
        }
    }
    for (int i = 0; i < poz; i++)
        printf("%s\n", words[i]);
    return 0;
}