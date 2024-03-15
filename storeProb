#include <stdio.h>
#include <string.h>

typedef struct{
    char category[20];
    char product [20];
    char unit [20];
    float price;
    int pieces;
    int id; 
}goods;

void store(goods goods[], int pieces);
void sell(goods goods[], int pieces);

int main (){
    int no_goods;
    int op1;
    int allprods = 0; 

    goods goods[50];
    printf("-----------------------------------------\n");
    printf("1. Refill stock \n");
    printf("2. Buy goods\n");
    printf("3. Value of all items\n");
    printf("4. Print Inventory\n");
    printf("5. Delete Item\n");
    printf("6. Exit..\n");
    printf("-----------------------------------------\n");
    scanf("%d", &op1);

    switch (op1)
    {
    case 1:
        printf("How many products will you store?");
        scanf("%d", &no_goods);
        store(goods, no_goods);
        break;
    
    default:
        break;
    }
    

    return 0;
}


void store(goods goods[], int pieces){
    int opt1;
    
    for(int i = 0; i < pieces; i++){
        printf("------------------------------\n");
        printf("Select what product you will restock:\n");
        printf("1. Rice\n");
        printf("2. Laundry products\n");
        printf("3. Food Products\n");
        printf("4. Home Care Products\n");
        printf("5. Exit..\n");
        printf("------------------------------\n");
        scanf("%d", &opt1);
        switch (opt1)
        {
        case 1:
            int skr;
            int skr1;
            printf("1. Rice by kilos\n");
            printf("2. Rice by Sack\n");
            scanf("%d", &skr);
            if (skr == 1)
            {
                printf("Kilos of rice will be added:\n");
                scanf("%d", &skr1);
                for (int i = 0; i < skr1; i++)
                {
                *goods[pieces].category = "rice";
                *goods[pieces].product = "rice";
                *goods[pieces].unit = "kilo";
                goods[pieces].price = 50.00;
                goods[pieces].pieces++;
                goods[pieces].id = "rpk";
                }
                pieces -= skr1;
                
            }else if (skr == 2)
            {
                printf("Sacks of rice will be added:\n");
                scanf("%d", &skr1);
                for (int i = 0; i < skr1; i++)
                {
                *goods[pieces].category = "rice";
                *goods[pieces].product = "rice";
                *goods[pieces].unit = "sack";
                goods[pieces].price = 2500.00;
                goods[pieces].pieces++;
                goods[pieces].id = "rps";
                }
                
                
                pieces -= skr1;
            }
            break;
        case 2: 
            int ldprod;
            printf("Laundry product will be added:\n");
            scanf("%d", &ldprod);
            for (int i = 0; i < ldprod ; i++)
            {
            *goods[pieces].category = "Laundry Products";
            printf("What is the name of the product?\n");
            scanf("% [^\n]", goods[pieces].product);
            printf("This is measured per:\n");
            scanf("% [^\n]", goods[pieces].unit);
            printf("Set price:\n");
            scanf("%lf",& goods[pieces].price); 
            goods[pieces].pieces++;
            printf("Set a unique id for this kind of product:");
            scanf("% [^\n]", goods[pieces].id);
            }
        break;
        //more cases
        default:
            break;
        }
        
    }
}

