#include <stdio.h>

float min(int start, int end, float* scores){
    float lowest = 10;
    
    for(; start!=end; start++){
        if(scores[start]==0) continue;
        if(scores[start] < lowest) lowest = scores[start];
    }
    
    return lowest;
}

float max(int start, int end, float* scores){
    float biggest = 0;
    
    for(; start!=end; start++){
        if(scores[start] > biggest) biggest = scores[start];
    }
    
    return biggest;
}

int main(){
    int gymnasts = 0;
    
    scanf("%i", &gymnasts);
    
    float scores[20*gymnasts];
    for(int i=0; i<20*gymnasts; i++) scanf("%f", &scores[i]);
    
    for(int i=0; i<gymnasts; i++){
        int start;
        int end;
        float lowest;
        float highest;
        int lowEx;
        int highEx;
        
        // arena and remote scores
        for(int j=0; j<2; j++){
            start = 0+10*j+20*i;
            end = 10+10*j+20*i;
            
            lowest = min(start, end, scores);
            highest = max(start, end, scores);
            lowEx = 0;
            highEx = 0; 
        
            //lowest
            for(int k=start; k<end; k++){
                if(scores[k]==lowest){
                    printf("%i ", (k%10)+1);
                    if(lowEx==0){
                        scores[k] = 0;
                        lowEx = 1;
                    }
                }
            }
            //highest
            for(int k=start; k<end; k++){
                if(scores[k]==highest){
                    printf("%i ", (k%10)+1);
                    if(highEx==0){
                        scores[k] = 0;
                        highEx = 1;
                    }
                }
            }
            
            printf("\n");
        }
        
        start = 0+20*i;
        end = 20+20*i;
        
        lowest = min(start, end, scores);
        highest = max(start, end, scores);
        lowEx = 0;
        highEx = 0; 
        
        // combined scores
        //lowest
        for(int j=start; j<end; j++){
            if(scores[j]==lowest){
                printf("%i ", (j%10)+1);
                if(lowEx==0){
                    scores[j] = 0;
                    lowEx = 1;
                }
            } 
        }
        //highest
         for(int j=start; j<end; j++){
            if(scores[j]==highest){
                printf("%i ", (j%10)+1);
                if(highEx==0){
                    scores[j] = 0;
                    highEx = 1;
                }
            } 
        }
        
        printf("\n");
        
        // average
        float average = 0.0;
        for(int j=start; j<end; j++){
            average += scores[j];
            if(j==end-1) average /= 14.0;
        }
        printf("%.2f\n", average);
    }

    return 0;
}