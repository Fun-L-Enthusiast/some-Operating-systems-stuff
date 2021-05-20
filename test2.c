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
void print_available(int arr[]);
void print_matrix(int arr[NC][NR]);
void release_resources(int customer_num, int release[]);
int is_safe();
void fileRead(FILE *fp, char * filename);
void in();

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
    in();
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
            if(allocation[customer_num][w]>= release[w]){
                allocation[customer_num][w] -= release[w];
                available[w] += release[w];
            }
            else{
                printf("You want to release %d resources of type %d.\n",release[w], w + 1);
                printf("But can't do that, the customer %d only has %d resource(s) of type %d\n", customer_num, allocation[customer_num][w], w +1);
                return ;
            }
        }
        printf("The resources were correctly released.\n");
    }
    else{
        printf("The customer number is invalid, we only have %d customers.\n",NC);
        }
}

int request_resources(int customer_num, int request[])
{
    int temp[NR];
    for(int i = 0; i<NR; i++)
        temp[i] = available[i];
    for(int t = 0; t<NR ;t++){
        if(request[t] > need[customer_num][t])
            return -1;
    }
    for(int g = 0; g<NR ;g++)
        if(request[g] > available[g])
            return -1;
    for(int b = 0; b<NR; b++)
        available[b] -= request[b];
    for(int h = 0; h<NR; h++)
        allocation[customer_num][h] += request[h];
    for(int p = 0; p<NR; p++)
        need[customer_num][p] -= request[p];
    if(is_safe() == 0){
        for(int n = 0; n<NR; n++)
            available[n] = temp[n];
        return -1;
    }
    return 0;
}


void in(){

  char array[3];
  int nums[NR +1 ];
  while(1){
    for(int f = 0; f<NC; f++)
        for(int c = 0; c<NR; c++)
            need[f][c] = maximum[f][c] - allocation[f][c];
    printf("Que necesitas:\n");
    scanf("%s",array);
    if( (strcmp(array, "*")) != 0){
        for(int i = 0; i<= NR; i++)
            scanf("%d", &nums[i]);
        printf("%s\n",array);
        for(int j = 0; j<= NR; j++)
            printf("%d\n",nums[j]);
        if( (strcmp(array, "RQ")) == 0)
            if(request_resources(nums[0],&nums[1]) == -1)
                printf("Unable to allocate resources, the customer %d must wait until resources become available.\n", nums[0]);
            else if(request_resources(nums[0],&nums[1]) == 0)
                printf("Allocation was successful!\n");
        else if( (strcmp(array, "RL")) == 0)
            release_resources(nums[0],&nums[1]);
    }
    else if( (strcmp(array, "*")) == 0){
        printf("Available: \n");
        print_available(available);
        printf("Maximum: \n");
        print_matrix(maximum);
        printf("Allocation: \n");
        print_matrix(allocation);
        printf("Need: \n");
        print_matrix(need);
    }


  }
}

void print_available(int arr[])
{
    for(int i = 0; i<NR; i++)
        printf("%d\t",arr[i]);
    printf("\n");

}
void print_matrix(int arr[NC][NR])
{
    for(int j = 0; j<NC; j++){
        for(int i = 0; i<NR; i++)
            printf("%d\t",arr[j][i]);
        printf("\n");
    }
}
int is_safe()
{
    int Work[NR]; 
    for(int i = 0; i<NR; i++)
        Work[i] = available[i];
    int Finish[NC] = {0};
    for(int i = 0; i<NC; i++){
        for(int t = 0; t<NR ;t++){
            if(Finish[i] == 1)
                break;
            else if(need[i][t] <= Work[t])
                if(t == NR-1){
                    for(int j = 0; j<NR; j++)
                        Work[j] += allocation[i][j];
                    Finish[i] = 1; 
                    i = 0;
                    break;
                }
            else break;
        }
    }
    for(int a = 0; a<NC; a++)
        if(Finish[a] == 0)
            return 0;
    return 1;
}