
#include "BOB.h"

void creafile(char *name, int sep, int nb)
{
    char *nbstr;
    FILE *fileptr;

    if (strcmp(name, "main") == 0 && sep == 0) {
        strcat(name, "_");
    }
    strcat(name, ".c");
    fileptr = fopen(name, "w");
    if (fileptr == NULL) {
        printf("Echec de la création du fichier %s :/\n Arret du programme.\n", name);
        exit(84);
    }
    fputs(cfile(name), fileptr);
    fclose(fileptr);
    printf("Fichier %s bien écrit!\n", name);
}


char *cfile(char *name)
{
    return ("this is a C file!");
}