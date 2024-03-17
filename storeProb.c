#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_PRODUCT_LENGTH 30
#define MAX_UNIT_LENGTH 20
#define MAX_ID_LENGTH 10

// Define a structure to represent each product
typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    char product[MAX_PRODUCT_LENGTH];
    char unit[MAX_UNIT_LENGTH];
    double price;
    int quantity;
    char id[MAX_ID_LENGTH];
} Product;

// Function prototypes
void addProduct(Product inventory[], int *numProducts);
void sellProduct(Product inventory[], int *numProducts);
void displayInventory(Product inventory[], int numProducts);
void deleteProduct(Product inventory[], int *numProducts, char itemId[]);

int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;

    // Initialize products
    // Example products are initialized here
    strcpy(inventory[numProducts].category, "Rice");
    strcpy(inventory[numProducts].product, "Rice");
    strcpy(inventory[numProducts].unit, "Kilo");
    inventory[numProducts].price = 50.00;
    inventory[numProducts].quantity = 20;
    strcpy(inventory[numProducts].id, "RRPK");
    numProducts++;

    strcpy(inventory[numProducts].category, "Rice");
    strcpy(inventory[numProducts].product, "Rice");
    strcpy(inventory[numProducts].unit, "Sack");
    inventory[numProducts].price = 2500.00;
    inventory[numProducts].quantity = 15;
    strcpy(inventory[numProducts].id, "RRPS");
    numProducts++;

    strcpy(inventory[numProducts].category, "Food Product");
    strcpy(inventory[numProducts].product, "Magic Sarap");
    strcpy(inventory[numProducts].unit, "Piece");
    inventory[numProducts].price = 5.00;
    inventory[numProducts].quantity = 17;
    strcpy(inventory[numProducts].id, "FPMSPP");
    numProducts++;

    strcpy(inventory[numProducts].category, "Laundry Product");
    strcpy(inventory[numProducts].product, "Surf");
    strcpy(inventory[numProducts].unit, "Pack");
    inventory[numProducts].price = 10.00;
    inventory[numProducts].quantity = 30;
    strcpy(inventory[numProducts].id, "LPSPP");
    numProducts++;

    strcpy(inventory[numProducts].category, "Home Care Products");
    strcpy(inventory[numProducts].product, "Broom");
    strcpy(inventory[numProducts].unit, "Piece");
    inventory[numProducts].price = 30.00;
    inventory[numProducts].quantity = 10;
    strcpy(inventory[numProducts].id, "HPBPP");
    numProducts++;                  
              
    //Looped menu
    do {
        // Display menu
        printf("-------------------------------");
        printf("\n1. Add Product\n");
        printf("2. Sell Product\n");
        printf("3. Display Inventory\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-------------------------------\n");

        //User's Choices
        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                sellProduct(inventory, &numProducts);
                break;
            case 3:
                displayInventory(inventory, numProducts);
                break;
            case 4:
                printf("Enter item ID to delete: ");
                char itemId[MAX_ID_LENGTH];
                scanf("%s", itemId);
                deleteProduct(inventory, &numProducts, itemId);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a product to inventory
void addProduct(Product inventory[], int *numProducts) { //using pointer to edit the quantity of the specific product
    //If number of products exceed the set maxed products it will print something.
    if (*numProducts == MAX_PRODUCTS) {
        printf("Inventory full. Cannot add more products.\n");
        return;
    }

    Product newProduct; //call out the struct name it "newProduct"

    //multiple scanf's for storing the product's detail
    printf("Enter product category: ");
    scanf(" %[^\n]", newProduct.category);

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.product);

    printf("Enter unit of measure: ");
    scanf(" %[^\n]", newProduct.unit);

    printf("Enter price: ");
    scanf("%lf", &newProduct.price);

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product ID: ");
    scanf(" %[^\n]", newProduct.id);

    inventory[*numProducts] = newProduct;
    (*numProducts)++;

    printf("Product added successfully.\n");
}

// Function to sell a product
void sellProduct(Product inventory[], int *numProducts) {
    //if the item has no quantity then it will print out something.
    if (*numProducts == 0) {
        printf("No items to sell.\n");
        return;
    }

    //calling the dispInv func for easy user experience
    printf("Available Products:\n");
    displayInventory(inventory, *numProducts);

    //asking for the product id to sell
    char id[MAX_ID_LENGTH];
    printf("Enter product ID to sell: ");
    scanf("%s", id);

    //compare the strings to find it easily
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].id, id) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            // to make sure that the user input correctly
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d %s for P%.2f each. all for P%.2lf \n", quantity, inventory[i].product, inventory[i].price, quantity *inventory[i].price);
                return;
            } else {
                printf("Insufficient quantity to sell.\n");
                return;
            }
        }
    }
    // and if the user mistype the id it the program will go back to the menu
    printf("Product with ID %s not found.\n", id);
}

// Function to display the inventory
void displayInventory(Product inventory[], int numProducts) {
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("ID: %s\n", inventory[i].id);
        printf("Category: %s\n", inventory[i].category);
        printf("Product: %s\n", inventory[i].product);
        printf("Unit: %s\n", inventory[i].unit);
        printf("Price: P%.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("\n");
    }
}

// Function to delete a product from inventory
void deleteProduct(Product inventory[], int *numProducts, char itemId[]) {
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].id, itemId) == 0) {                 //Using the item id to help identify what product to remove
            printf("Deleted item: %s\n", inventory[i].product);     
            for (int j = i; j < *numProducts - 1; j++) {            //To shift the array for the removal of product
                inventory[j] = inventory[j + 1];
            }
            (*numProducts)--;
            return;
        }
    }
    printf("Item not found.\n");
}


