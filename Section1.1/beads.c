/*
ID: myzhk111
LANG: C
PROG: beads
*/
#include <stdio.h>
#include <string.h>
char necklace[400];
int len;

int getNextLoc(int i)
{
    if (i < 0)
       i += len;
    return i % len;
}

int getLeft(int p)
{
    int i;
    int pos = getNextLoc(p - 1);
    char color = 'w';
    for (i = 0; i < len; i++, pos = getNextLoc(--pos)) {
       if (color == 'w' && necklace[pos] != 'w')
          color = necklace[pos];
       else if (necklace[pos] != 'w' && color != 'w' && color != necklace[pos])
               break;
    }
    return i;
}

int getRight(int p)
{
    int i;
    int pos = p;
    char color = 'w';
    for (i = 0; i < len; i++, pos = getNextLoc(++pos)) {
        if (color == 'w' && necklace[pos] != 'w')
           color = necklace[pos];
        else if (necklace[pos] != 'w' && color != 'w' && color != necklace[pos])
             break;
    }
    return i;
}

int main()
{
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    
    fscanf(fin, "%d %s", &len, necklace);
    printf("%d\n%s\n", len, necklace);
    int i;
    int maximum = 0;
    for(i = 0; i < len; i++) {
       int m;
       m = getLeft(i) + getRight(i);
       if (m > maximum)   
       maximum = m;
    }
    if (maximum > len)
       maximum = len;
    fprintf(fout, "%d\n", maximum);
    exit(0);
}
