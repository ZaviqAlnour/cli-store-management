#include <stdio.h>

void task();
void addNewProduct();
void viewAllProduct();
void updateProductPrice();
void removeAProduct();

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
        fprintf(fName, "%s\n", name);
        fprintf(fPrice, "%.2f\n", price);
        fprintf(fStock, "%d\n", stock);

        fprintf(fHistory, "Name: %s | price: %.2f | Stock: %d\n", name, price, stock);

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
    printf("Not available View products\n"); 
}

void updateProductPrice() {
     printf("Not available Update price\n"); 
}

void removeAProduct() {
     printf("Not available Remove product\n"); 
}
