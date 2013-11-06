/*
ID: myzhk111
LANG: C
PROG: beads
*/
#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    
    int len;
    char necklace[400], necklaces[800];
    fscanf(fin, "%d %s", &len, necklace);
    
    strcpy(necklaces, necklace);
    strcat(necklaces, necklace);
    
    int left[800][2], right[800][2];
    left[0][0] = left[0][0] = 0;
    int i;
    for(i = 1; i < 2*len-1; i++) {
       if (necklaces[i - 1] == 'b') {
          left[i][1] = left[i - 1][1] + 1;
          left[i][0] = 0;
       }
       else if (necklaces[i - 1] == 'r') {
           left[i][0] = left[i - 1][0] + 1;
           left[i][1] = 0;
       }
       else {
            left[i][0] = left[i - 1][0] + 1;
            left[i][1] = left[i - 1][1] + 1;
       }
    }
    
    right[2*len][0] = right[2*len][1] = 0;
    for (i = 2*len - 1; i >=0; i--) {
        if (necklaces[i] == 'b') {
           right[i][1] = right[i + 1][1] + 1;
           right[i][0] = 0;
        }
        else if (necklaces[i] == 'r') {
             right[i][0] = right[i + 1][0] + 1;
             right[i][1] = 0;
        }
        else {
             right[i][0] = right[i + 1][0] + 1;
             right[i][1] = right[i + 1][1] + 1;     
        }   
    }
    
    int maximum = 0;
    for (i = 0; i < 2*len -1; i++)
       maximum = max(maximum, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
    if (maximum > len)
       maximum = len;
    fprintf(fout, "%d\n", maximum);
//    system("pause");
//    return 0;
    exit(0);
}
