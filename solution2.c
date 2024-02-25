#include <stdio.h>

float min(int size, float arr[]){
    float min=10;
    for(int i=0;i<size;i++)
        if(arr[i]!=0 && arr[i]<min)
            min=arr[i];
    return min;
};

float max(int size, float arr[]){
    float max=1;
    for(int i=0;i<size;i++)
        if(arr[i]!=0 && arr[i]>max)
            max=arr[i];
    return max;
};

float average(float arr[20]){
    float sum=0;
    for (int i=0;i<20;i++) sum+=arr[i];
    return sum/14;
}

void print_judges_and_remove_min_max_just_once(int size, float arr[]){
    // uses bit logic and bit operation. 'removed' is a 2-bit flag
    int removed=0;
    float _min=min(size,arr), _max=max(size,arr);
    for (int i=0; i<size; i++)
        if(arr[i]==_min){
            printf("%d ",(i%10)+1);
            if((removed&1)!=1){
                removed|=1;
                arr[i]=0;
            }
        }
    for (int i=0; i<size; i++)
        if(arr[i]==_max){
            printf("%d ",(i%10)+1);
            if((removed&2)!=2){
                removed|=2;
                arr[i]=0;
            }
        }
    printf("\n");
}

int main(){
    // int g=4;
    // float scores[4][2][10] =
    //     {{{5,5,7,7,6,6,8,8,7,6},
    //       {5,5,5,5,6,5,6,6,6,7}},
    //      {{9,9,9,9,9,10,9,10,10,9},
    //       {9,9,9,9,9,8,9,10,10,10}},
    //      {{7,8,7,8,6,8,6,8,7,7},
    //       {6,6,8,6,6,8,8,6,7,6}},
    //      {{10,10,10,10,10,10,10,10,9,10},
    //       {9,9,9,10,9,9,9,9,9,8}}};

    int g; scanf("%d", &g); //gymnasts
    int s=10, c=20; //size of judges, combined judges
    
    float scores[g][2][10];
    for(int i=0;i<g;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<s;k++)
                scanf("%f",&scores[i][j][k]);

    for(int i=0;i<g;i++){
        int _min,_max;
        float combined[20];
        for(int j=0;j<2;j++) {
            print_judges_and_remove_min_max_just_once(s,scores[i][j]);
            for(int k=0;k<s;k++) combined[k+j*s]=scores[i][j][k];
        }
        print_judges_and_remove_min_max_just_once(c,combined);
        printf("%.2f\n", average(combined));
    }

    // getchar(); getchar();
    return 0;
}