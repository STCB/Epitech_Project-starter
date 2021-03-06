#include "BOB.h"

void createmakefile(char *binary, char *main, int sep, char *list)
{
    FILE *fileptr;

    printf("Test a la creation du Makefile\n");
    fileptr = fopen("tests/Makefile", "w");
    if (fileptr == NULL) {
        printf("Echec de la création du Makefile !\n Arret du programme.\n");
        exit(84);
    }
    fputs(makestr(binary, main, sep, list), fileptr);
    fclose(fileptr);
    printf("Makefile bien créé!\n");
}

char *makestr(char *binary, char *name, int issep, char *list)
{
    // F is for Folders, f for files, b for binaries and y for the year

    int nb = 0;
    int u = 0;
    char *fullstr;
    char *init = "##\n"
                "## EPITECH PROJECT, %y\n"
                "## %F\n"
                "## File description:\n"
                "## %f\n"
                "##\n"
                "\n"
                "SRC			=			%f\n"
                "\n"
                "NAME		=			%b\n"
                "\n"
                "all:\n"
                "                        gcc $(SRC) -o $(NAME)\n"
                "\n"
                "clean:\n"
                "                        rm $(NAME)\n"
                "\n"
                "fclean:					clean\n"
                "\n"
                "re:						clean all\n"
                "\n"
                "val:\n"
                "                        gcc $(SRC) -g3 -o $(NAME)\n"
                "                        valgrind ./$(NAME)";

    fullstr = malloc(sizeof(init) + sizeof(init) / 2);
    for (int i = 0; init[i] != '\0'; i++) {
        fullstr[nb] = init[i];
        if (init[i] == '%') {
            switch (init[i + 1]) {
                case 'y': nb = FillDate(fullstr, nb); break;
                case 'F': nb = FillFolder(fullstr, nb); break;
                case 'f': nb = FillFiles(fullstr, nb, name, list, issep); break;
                case 'b': nb = FillNames(fullstr, nb, u); break;
                default: puts("\nLe makefile de référence contient une erreur.\n");
            }
            i++;
        }
        nb++;
    }
    return (fullstr);
}

int FillDate(char *str, int i)
{
    int stop = i + 4;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int year = tm.tm_year + 1900;

    str[i] = 48 + (year / 1000);
    str[i + 1] = 48 + (year - (year / 1000)* 1000) / 100;
    str[i + 2] = 48 + (year - (year / 100)* 100) / 10;
    str[i + 3] = 48 + (year - (year / 10) * 10);
    return (i + 3);
}

int FillFiles(char *str, int i, char *name, char *list, int sep)
{
    printf("oui\n");
    return (i);
}

int FillFolder(char *str, int i)
{
    DIR *d;

    struct dirent *dir;
    d = opendir(".");
    dir = readdir(d);
    for (int i = 0; i != 10; i++)
        printf("\nDossier d'execution: %s\n", dir->d_name);
    return (i);
}

int FillNames(char *str, int i, int nb)
{
    return (i);
}