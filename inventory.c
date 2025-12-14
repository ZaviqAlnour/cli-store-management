#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task();
void addNewProduct();
void viewAllProduct();
void updateProductInsight();
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
    printf("3. Update product insight\n");
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
            updateProductInsight();
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


void updateProductInsight() {
    FILE *fName = fopen("product_names.txt", "r");
    if(!fName)
    {
        printf("\nNo products found!\n");
        return;
    }

    int ids[100];
    char names[100][100];
    int count = 0;

    while (fscanf(fName, "%d | %[^\n]\n", &ids[count], names[count]) == 2)
    {
        printf("%d. %s\n", count + 1, names[count]);
        count++;
    }

    fclose(fName);

    if (count == 0)
    {
        printf("\nNo products available.\n");
        return;
    }

    int choice;
    printf("\nSelect product number: ");
    scanf("%d", &choice);

    if(choice < 1 || choice > count)
    {
        printf("Invalid selection.\n");
        return;
    }

    int selectID  = ids[choice - 1];

    printf("\nWhat do you want to change?\n");
    printf("1. Change price\n");
    printf("2. Change stock\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        float newPrice;
        printf("Enter new price: ");
        scanf("%f", &newPrice);

        FILE *fp = fopen("product_prices.txt", "r");
        FILE *temp = fopen("temp.txt", "w");

        int id;
        float price;

        while (fscanf(fp, "%d|%f\n", &id, &price) == 2)
        {
            if(id == selectID)
            {
                fprintf(temp, "%d|%f\n", &id, &price);
            }
            else
            {
                fprintf(temp, "%d|%.2f\n", id, price);
            }
        }

        fclose(fp);
        fclose(temp);
        remove("product_prices.txt");
        rename("temp.txt", "product_prices.txt");
        
        printf("Price updated successfully.\n");
    }

    else if(choice == 2)
    {
        int newStock;
        printf("Enter new stock: ");
        scanf("%d", &newStock);

        FILE *fs = fopen("product_stock.txt", "r");
        FILE *temp = fopen("temp.txt", "w");

        int id, stock;

        while (fscanf(fs, "%d|%d\n", &id, &stock) == 2)
        {
            if(id == selectID)
                fprintf(temp, "%d|%d\n", id, newStock);
            else
                fprintf(temp, "%d|%d\n", id, stock);
        }

        fclose(fs);
        fclose(temp);
        remove("product_stock.txt");
        rename("temp.txt", "product_stock.txt");

        printf("Stock updated successfully.\n");
    }

    else{
        printf("Invalid option.\n");
    }
}


void removeAProduct() {
     printf("Not available Remove product\n"); 
}
