#include <stdio.h>
#include <string.h>
#define NR 4
void in();
int main()
{
  in();
  return 0;
}
void in()
{
  char array[4];
  int nums[NR +1 ];
  while(1){
    printf("Hello:\n");
    scanf("%s",array);
    for(int i = 0; i<= NR; i++)
      scanf("%d", &nums[i]);
    printf("%s\n",array);
    for(int j = 0; j<= NR; j++)
      printf("%d\n",nums[j]);
    if( (strcmp(array, "RQ")) == 0)
      printf("hay deadlock\n");
    else printf("Hola\n");
  }
}
