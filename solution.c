#include <stdio.h>

int min(int size, int arr[]){
    if(size==0) return 0;
    if(size==1) return arr[0];
    int min=arr[0];
    for(int i=0;i<size;i++)
        if(arr[i]<min) min=arr[i];
    return min;
};

int max(int size, int arr[]){
    if(size==0) return 0;
    if(size==1) return arr[0];
    int max=arr[0];
    for(int i=0;i<size;i++)
        if(arr[i]<max) max=arr[i];
    return max;
};

void print_1d_array(int size, int arr[]){
    for (int i=0; i<size; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void perform_scoring(){
    int scores[2][10]; //[centre or remote][judges]
    // for every gymnast's centre
    for(int i=0; i<10; i++){
        scanf("%d", &scores[0][i]);
    }
    // for every gymnast's remote
    for(int i=0; i<10; i++){
        scanf("%d", &scores[1][i]);
    }

    int min1 = min(sizeof(scores[0])/sizeof(int), scores[0]);
    int min1 = max(sizeof(scores[0])/sizeof(int), scores[0]);
    int max2 = min(sizeof(scores[1])/sizeof(int), scores[1]);
    int max2 = max(sizeof(scores[1])/sizeof(int), scores[1]);

    // single pass for scores[0]
    // single pass for scores[1]
    
};

// void perform_scoring(){
//     int centre[10], remote[10];
//     for(int i=0;i<10;i++) scanf("%d",&centre[i]);
//     for(int i=0;i<10;i++) scanf("%d",&remote[i]);

// };

int main(){
    int g; scanf("%d", &g);
    for(int i=0; i<g; i++) perform_scoring();

    return 0;
}