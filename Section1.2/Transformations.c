/*
ID: myzhk111
LANG: C
PROG: transform
*/
#include <stdio.h>
int N;
char square_before[10][10];
char square_after[10][10];

void getSquare(int N, char p[][10], FILE *fin) {
     int i, j;
     for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            p[i][j] = getc(fin);
            if (j == N-1) getc(fin);
        }
}

int array_equal(char a[][10], char b[][10])
{
    int i,j;
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++)
        {
         if (a[i][j] != b[i][j])
            return 0;
        }
    return 1;
}

void printSquare(int N, char p[][10])
{
      int i, j;
      for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            printf("%c%c", p[i][j], j == N-1 ? '\n' : ' ');
      printf("\n");
}

void Rotation90(int N, char p[][10], char temp[][10])
{
     int i, j;
     for (i = 0; i < N; i++)
         for (j = 0; j < N; j++) {
             temp[j][N-i-1] = p[i][j];
         }
     //printSquare(N, temp);
} 

void Rotation180(int N, char p[][10], char temp[][10])
{
     int i, j;
     for (i = 0; i < N; i++)
         for (j = 0; j < N; j++) {
             temp[N-1-i][N-1-j] = p[i][j];
         }
     //printSquare(N, temp);
}

void Reflection(int N, char p[][10], char temp[][10])
{
     int i, j;
     for (i = 0; i < N; i++)
         for (j = 0; j < N; j++) {
             temp[i][N-1-j] = p[i][j];
         }
     //printSquare(N, temp);
}

void Rotation270(int N, char p[][10], char temp[][10])
{
     int i, j;
     for (i = 0; i < N; i++)
         for (j = 0; j < N; j++) {
             temp[N-1-j][i] = p[i][j];
         }
     //printSquare(N, temp);
}

int main()
{
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    

    
    fscanf(fin, "%d", &N);
    getc(fin);
    
    getSquare(N, square_before, fin);
    getSquare(N, square_after, fin);
    
    int type;
    char trans[10][10];
    
    Rotation90(N, square_before, trans);
    if (array_equal(square_after, trans))
       type = 1;
    else{
         Rotation180(N, square_before, trans);
         if (array_equal(square_after, trans))
            type = 2;
         else {
              Rotation270(N, square_before, trans);
              if (array_equal(square_after, trans))
                 type = 3;
              else {
                  Reflection(N, square_before, trans);
                  if (array_equal(square_after, trans))
                     type = 4;
                  else {
                       char temp[10][10];
                       Reflection(N, square_before, trans);
                       Rotation90(N, trans, temp);
                       if (array_equal(square_after, temp))
                          type = 5;
                       else {
                            Reflection(N, square_before, trans);
                            Rotation180(N, trans, temp);
                            if (array_equal(square_after, temp))
                               type = 5;
                            else {
                                 Reflection(N, square_before, trans);
                                 Rotation270(N, trans, temp);
                                 if (array_equal(square_after, temp))
                                    type = 5;
                                 else {
                                      if (array_equal(square_before, square_after))
                                         type = 6;
                                      else {
                                           type = 7;
                                      }
                                 }
                            }
                       }
                  }
              }
         }
    } 
    fprintf(fout, "%d\n", type);
  //  printf("%d\n", type);
//    system("pause");
//    return 0;

    exit(0);
}
