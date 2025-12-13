#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task();
void addNewProduct();
void viewAllProduct();
void updateProductPrice();
void removeAProduct();

int productID;

int main(void)
{
    task();
    return 0;
}

void task()
{
    printf("Welcome to your store!\n\n");

    printf("What would you like to do?\n\n");
    printf("1. Add a new product\n");
    printf("2. View all products\n");
    printf("3. Update product price\n");
    printf("4. Remove a product\n\n");

    int choice;
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addNewProduct();
            break;
        case 2:
            viewAllProduct();
            break;
        case 3:
            updateProductPrice();
            break;
        case 4:
            removeAProduct();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

}



void addNewProduct()
 {
    char name[100];
    float price;
    int stock;

    srand(time(0));
    productID = 10000000 + rand() % 90000000;

    printf("\nEnter product name: ");
    scanf(" %[^\n]", name);

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter product stock: ");
    scanf("%d", &stock);

    FILE *fName = fopen("product_names.txt", "a");
    FILE *fPrice = fopen("product_prices.txt", "a");
    FILE *fStock = fopen("product_stock.txt", "a");
    FILE *fHistory = fopen("history.txt", "a");

    if (fName && fPrice && fStock && fHistory)
    {
        fprintf(fName, "%d | %s\n", productID, name);
        fprintf(fPrice, "%d | %.2f\n",productID, price);
        fprintf(fStock, "%d | %d\n",productID, stock);

        fprintf(fHistory, "ID: %d | Name: %s | price: %.2f | Stock: %d\n",productID, name, price, stock);

        printf("\nProduct added successfully!\n");
    }

    else{
        printf("\nError opening file\n");
    }
    
    if(fclose) fclose(fName);
    if(fPrice) fclose(fPrice);
    if(fStock) fclose(fStock);
    if(fHistory) fclose(fHistory);
 }

void viewAllProduct() { 
    FILE *fName = fopen("product_names.txt", "r");
    if(!fName)
    {
        printf("\nNo products found!\n");
        return;
    }

    char line[200];
    int id;
    char name[100];

    printf("\n==============================\n");
    printf("      All Products\n");
    printf("==============================\n");
    printf("| %-10s | %-30s | \n", "product Id","Name");
    printf("---------------------------------------------\n");

    while (fgets(line, sizeof(line), fName))
    {
        if(sscanf(line, "%d | %[^\n]", &id, name) == 2)
        {
            printf("| %-10d | %-30s |\n", id , name);
        }
    }

    printf("==============================\n");
    fclose(fName);
}


void updateProductPrice() {
     printf("Not available Update price\n"); 
}

void removeAProduct() {
     printf("Not available Remove product\n"); 
}
