/*
ID: myzhk111
LANG: C
PROG: ride
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char comet[7], group[7];
    fscanf(fin, "%s %s", comet, group);
    int i, c = 1, g = 1;
    for (i = 0; i < 7 && comet[i] != '\0'; i++)
        c *= comet[i] - 'A' + 1;
    for (i = 0; i < 7 && group[i] != '\0'; i++)
        g *= group[i] - 'A' + 1;
    if (c % 47 == g % 47)
       fprintf(fout, "GO\n");
    else fprintf(fout,"STAY\n");
    exit(0);
    
    
}
