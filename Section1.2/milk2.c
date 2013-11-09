/*
ID: myzhk111
LANG: C
PROG: milk2
*/
#include <stdio.h>
#include <stdlib.h>
#define maxnum  5000
int milk[maxnum][2];
int len;

int max(int a, int b)
{
    return a > b? a : b;
}

int comp(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

int main()
{
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    
    fscanf(fin, "%d", &len);
    int i;
    for (i = 0; i < len; i++)
        fscanf(fin, "%d %d", milk[i], milk[i] + 1);
    
    
    qsort(milk, len, sizeof(int) * 2, comp);
    
    int start, end, startM, endM, startNM = 0, endNM = 0;
    int maxM = 0, maxNM = 0;
    int *last = milk[0];
    for (i = 1; i < len; i++) {
        if (milk[i][0] > *(last + 1)) {
           int temp = milk[i][0] - *(last + 1);
           maxNM = max(maxNM, temp);
           temp = *(last + 1) - *last;
           maxM = max(temp, maxM);
           last = milk[i];
        }
        else {
             *(last + 1) = max(*(last + 1), milk[i][1]);
        }
           
    }
    maxM = max(maxM, *(last + 1) - *last);
    fprintf(fout, "%d %d\n", maxM, maxNM);
    fclose(fin);
    fclose(fout);
    exit(0);
    //system("pause");
//    return 0;
}
