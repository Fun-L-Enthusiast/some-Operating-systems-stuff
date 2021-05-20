#include <stdio.h>
#include <stdlib.h>
#define NC 5
#define NR 4


int available[NR];
int main(int argc, char* argv[])
{
    printf("%d\n",argc-1);
    for(int i =1; i<= argc-1; i++){
      available[i-1] = atoi(argv[i]);
      }
    for(int j= 0; j<NR;j++)
      printf("%d\n",available[j]);
    return 0;
        }
