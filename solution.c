#include <stdio.h>

float min(int size, float arr[]){
    float min=10;
    for(int i=0;i<size;i++)
        if(arr[i]!=0 && arr[i]<min) min=arr[i];
    return min;
};

float max(int size, float arr[]){
    float max=1;
    for(int i=0;i<size;i++)
        if(arr[i]!=0 && arr[i]>max) max=arr[i];
    return max;
};

float average(float arr[20]){
    float sum=0;
    for (int i=0;i<20;i++) sum+=arr[i];
    return sum/14;
}

void print_judges(int size, float arr[], float min, float max){
    for (int i=0; i<size; i++)
        if(arr[i]==min)
            printf("%d ", (i%10)+1);
    for (int i=0; i<size; i++)
        if(arr[i]==max)
            printf("%d ", (i%10)+1);
    printf("\n");
}

void remove_once(int size, float arr[], float target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            arr[i]=0;
            return;
        }
    }
}

void perform_scoring(){
    // float scores[2][10] = {{5,5,7,7,6,6,8,8,7,6},{5,5,5,5,6,5,6,6,6,7}};
    float scores[2][10]; //[centre or remote][judges]
    // for every gymnast's centre
    for(int i=0; i<10; i++) scanf("%f", &scores[0][i]);
    // for every gymnast's remote
    for(int i=0; i<10; i++) scanf("%f", &scores[1][i]);

    float combined[20];
    int size_remote = sizeof(scores[0])/sizeof(float);
    int size_centre = sizeof(scores[1])/sizeof(float);
    int size_combined = sizeof(combined)/sizeof(float);

    float min1 = min(size_remote, scores[0]);
    float max1 = max(size_remote, scores[0]);
    float min2 = min(size_centre, scores[1]);
    float max2 = max(size_centre, scores[1]);
    print_judges(size_remote, scores[0], min1, max1);
    print_judges(size_centre, scores[1], min2, max2);

    remove_once(size_remote, scores[0], min1);
    remove_once(size_remote, scores[0], max1);
    remove_once(size_centre, scores[1], min2);
    remove_once(size_centre, scores[1], max2);

    for(int i=0; i<10; i++) combined[i] = scores[0][i];
    for(int i=10; i<20; i++) combined[i] = scores[1][i%10];
    float min_combined = min(size_combined, combined);
    float max_combined = max(size_combined, combined);
    print_judges(size_combined, combined, min_combined, max_combined);

    remove_once(size_combined, combined, min_combined);
    remove_once(size_combined, combined, max_combined);
    printf("%.2f\n", average(combined));
};

int main(){
    // int g=1;
    int g; scanf("%d", &g);
    for(int i=0; i<g; i++) perform_scoring();

    return 0;
}