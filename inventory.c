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
     printf("Add product Not available\n");
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
