#include <stdio.h>
#include <stdlib.h>

int main(void){
  char *names[3];
  int days[3];
  int years[3];
  char * p;
  for( int i = 0; i<3; i++){
    p = malloc(sizeof(char) * 4);
    scanf("%d %s %d",&days[i], p, &years[i]);
    names[i] = p;
    } 

  for( int j = 0; j<3; j++)
    printf("%d %s %d\n",days[j], names[j], years[j]);
  
  free(p);
  return 0;
}
