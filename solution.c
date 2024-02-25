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

int main(){
    int g; scanf("%d", &g);

    float centre[g][10]; //[gymnasts][judges]
    float remote[g][10]; //[gymnasts][judges]
    float combined[20];
    
    int size_centre = sizeof(centre[0])/sizeof(float);
    int size_remote = sizeof(remote[0])/sizeof(float);
    int size_combined = sizeof(combined)/sizeof(float);

    for (int i=0; i<g; i++){
        for(int j=0; j<10; j++) scanf("%f", &centre[i][j]);
        for(int j=0; j<10; j++) scanf("%f", &remote[i][j]);
    }

    for (int i=0; i<g; i++){
        float min1 = min(size_centre, centre[i]);
        float max1 = max(size_centre, centre[i]);
        float min2 = min(size_remote, remote[i]);
        float max2 = max(size_remote, remote[i]);
        print_judges(size_centre, centre[i], min1, max1);
        print_judges(size_remote, remote[i], min2, max2);

        remove_once(size_centre, centre[i], min1);
        remove_once(size_centre, centre[i], max1);
        remove_once(size_remote, remote[i], min2);
        remove_once(size_remote, remote[i], max2);

        for(int j=0; j<10; j++) combined[j] = centre[i][j];
        for(int j=10; j<20; j++) combined[j] = remote[i][j%10];
        float min_combined = min(size_combined, combined);
        float max_combined = max(size_combined, combined);
        print_judges(size_combined, combined, min_combined, max_combined);

        remove_once(size_combined, combined, min_combined);
        remove_once(size_combined, combined, max_combined);
        printf("%.2f\n", average(combined));
    }

    // getchar(); getchar();
    return 0;
}