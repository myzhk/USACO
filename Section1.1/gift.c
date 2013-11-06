/*
ID: myzhk111
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <string.h>
int lookup(char a[][14], char b[], int);
int main()
{
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    
    char people[10][14] = {0};
    int money[10] = {0};
    int np;
    
    fscanf(fin, "%d", &np);
    int i, j, give, divide;
    char giver[14] = {0};
    for (i = 0; i < np; i++) {
        fscanf(fin, "%s", people[i]);
    }
    
    for (i = 0; i < np; i++) {
        fscanf(fin, "%s %d %d", giver, &give, &divide);
        
        if (give == 0 || divide ==0)
           continue;
           
        money[lookup(people, giver, np)] -= give / divide * divide;
        for (j = 0; j < divide; j++) {
            char receiver[14] = {0};
            fscanf(fin, "%s", receiver);
            money[lookup(people, receiver, np)] += give / divide;
        }
    }
    
    for (i = 0; i < np; i++) {
        fprintf(fout, "%s %d\n", people[i], money[i]);
    }
    
    exit(0);
}

int lookup(char people[][14], char name[], int np)
{
    int i;
    for (i = 0; i < np; i++)
        if (strcmp(people[i], name) == 0)
           return i;
    
}
