
#ifndef BOB_H_
#define BOB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void creafile(char *name, int sep, int nb);
char *cfile(char *name);

void createmakefile(char *binary, char *main, int sep, char *list);
char *makestr(char *binary, char *name, int issep, char *list);

int FillDate(char *str, int i);
int FillFiles(char *str, int i, char *name, char *list, int sep);
int FillFolder(char *str, int i);
int FillNames(char *str, int i, int nb);

#endif /* !BOB_H_ */