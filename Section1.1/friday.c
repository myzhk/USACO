/*
ID: myzhk111
LANG: C
PROG: friday
*/
#include <stdio.h>
#include <string.h>
int days[7] = {0, 0, 0, 0, 0, 0, 0}; 
int isLeapYear(int);
int main()
{
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    
    int N;
    fscanf(fin, "%d", &N);
    
    int i, j;
    int alldays = 0;
    for (i = 1900; i < 1900+N; i++)
        for (j = 1; j <= 12; j++) {
            switch(j - 1) {
                case 0: 
                     if (i > 1900)
                        alldays += 31;
                     break;
                case 1: case 3: case 5: case 7:
                case 8: case 10:
                     alldays += 31;
                     break;
                case 2:
                     if (isLeapYear(i))
                        alldays += 29;
                     else alldays += 28;
                     break;
                default: alldays += 30; break;
            }
            alldays += 14;
            days[alldays % 7] ++;
            alldays -= 14;
        }

    for (i = 0; i < 6; i++)
       fprintf(fout, "%d ", days[i]);
    fprintf(fout, "%d\n", days[i]);
    exit(0);
}

int isLeapYear(int year)
{
    return ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) ? 1 : 0;
}
