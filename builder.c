
#include "BOB.h"

int main(int argc, char **argv)
{
    char main[500];
    char binary[500];
    char temp[500];
    char *endptr;
    int temp_i = 0;
    int separatedMain = 0;
    char *list;

    createmakefile("testmakefile", "main", 0, "liste");
    //FillDate("issou", 3);
    return (0);
    strcat(list, "starting");
    if (argc == 1) {
        printf("Entre le nom de ton fichier principal: ");
        scanf("%s", main);
        printf("\nEntre le nom de ton binaire: ");
        scanf("%s", binary);
        printf("Veux-tu un fichier main séparé? (0 = non / 1 = oui): ");
        scanf("%d", &separatedMain);
        printf("\nVeux-tu d'autres fichiers? : ");
        scanf("%s", temp);
        if (strcmp(temp, "1") == 0) {
            printf("\nNouveau fichier (STOP pour arreter) :  ");
            scanf("%s", temp);
            while (strcmp(temp, "STOP") != 0) {
                creafile(temp, separatedMain, 0);
                list = malloc(sizeof(char) * (strlen(temp) + strlen(list)));
                strcat(list, "|");
                strcat(list, temp);
                printf("\nNouveau fichier (STOP pour arreter) :  ");
                scanf("%s", temp);
            }
        }
    } else {
        strcpy(main, argv[1]);
        strcpy(binary, argv[2]);
        separatedMain = strtol(argv[3], &endptr, 10);
        while (separatedMain != 0 && separatedMain != 1) {
            printf("La derniere valeur rentrée est incorrecte, repond 1 ou 0: ");
            scanf("%d", &separatedMain);
            putchar('\n');
        }
    }
    printf("Main = %s; Binary = %s; sep main = %d\n", main, binary, separatedMain);
    if (separatedMain == 1)
        creafile("main", 0, 0);
    creafile(main, 0, 0);
    createmakefile(binary, main, separatedMain, list);
    printf("Fini!\n");
}