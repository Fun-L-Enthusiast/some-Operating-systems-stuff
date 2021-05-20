#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NC 5 /*Number of customers*/
#define NR 4 /*Number of resources*/

/* the available amount of each resource */
int available[NR];

/*the maximum demand of each customer */
int maximum[NC][NR];

/* the amount currently allocated to each customer */
int allocation[NC][NR];

/* the remaining need of each customer */
int need[NC][NR];

int request_resources(int customer_num, int request[]);
void release_resources(int customer_num, int release[]);

void fileRead(FILE *fp, char * filename);

int main(int argc, char *argv[])
{
    printf("%d\n",argc-1);
        for(int i =1; i<= argc-1; i++){
        available[i-1] = atoi(argv[i]);
        }
        for(int j= 0; j<NR;j++)
        printf("%d\n",available[j]);
    FILE *fp;
    fileRead(fp, "in.txt");
    return 0;

}

void fileRead(FILE *fp, char * filename)
{
    if ((fp = fopen(filename, "r")) == NULL){
        printf("can't open file.\n");
        return;
    }else{
        for(int i = 0; i< NC; i++)
            for(int j = 0; j<NR; j++){
                if( j == NR-1)
                    fscanf(fp, "%d",&maximum[i][j]);
                else
                    fscanf(fp, "%d,",&maximum[i][j]);
            }
    }
    for(int r = 0; r< NC; r++){
        for(int q = 0; q<NR; q++)
            printf("%d\t",maximum[r][q]);
        printf("\n");
    }
}

void release_resources(int customer_num, int release[])
{
    if(customer_num<NC){
        for(int w = 0; w<NR; w++){
            if(allocation[customer_num][w]>= release[w])
                allocation[customer_num][w] -= release[w];
            else{
                printf("You want to release %d resources of type %d.\n",release[w], w + 1);
                printf("But can't do that, the customer %d only has %d resource(s) of type %d\n", customer_num, allocation[customer_num][w], w +1);
                return ;
            }
        }
    }
    else{
        printf("The customer number is invalid, we only have %d customers.\n",NC);
        }
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
/*     if( (strcmp(array, "RQ")) == 0)
      printf("hay deadlock\n");
    else printf("Hola\n"); */
  }
}