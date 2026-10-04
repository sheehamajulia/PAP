#include <stdio.h>
#include <string.h>

#include "SupplierManagement.h"

#define MAX_SUPPLIER 100
#define STR_LEN 100

//Global Arrays
char supplierID[MAX_SUPPLIER][15];
char supplierName[MAX_SUPPLIER][STR_LEN];
char supplierEmail[MAX_SUPPLIER][STR_LEN];
char supplierTelephone[MAX_SUPPLIER][20];
char supplierLocation[MAX_SUPPLIER][STR_LEN];

int supplierCount = 0;

void supplierMenu(void);
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
void compareSupplier(void);



void supplierMenu(void) {

        char choice;

        do {

        puts("=============================================");
        puts("--------- SUPPLIER MANAGEMENT MENU ----------");
        puts("=============================================");

        puts("1. Add Supplier");
        puts("2. Display Supplier");
        puts("3. Search Supplier");
        puts("4. Compare Supplier");
        puts("5. Exit the supplier");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
               addSupplier();
                break;
            case '2':
               displaySupplier();
                break;
            case '3':
               searchSupplier();
                break;
            case '4':
                compareSupplier();
                break;
            case '5':
                puts("Exiting the Supplier module");
                break;
            default:
                puts("[!] Invalid choice, select between 1 to 5 [!]");
                puts("");
        }

    } while (choice != '5');
}

void addSupplier () {

    if (supplierCount >= MAX_SUPPLIER) {
        puts("[!] Database is full, cant add more supplier. [!]");
        return;
    }

    
    printf("\n-------- ADD SUPPLIER ----------\n");

    //1.supplier ID
    printf("Enter Supplier ID: ");
    scanf("%9s", supplierID[supplierCount]);

    getchar();

    //2.Supplier name
    printf("Enter supplier name: ");
    fgets(supplierName[supplierCount], sizeof(supplierName[supplierCount]), stdin);

    supplierName[supplierCount][strcspn(supplierName[supplierCount], "\n")] = '\0';

    //3.supplier email
    printf("Enter supplier email: ");
    fgets(supplierEmail[supplierCount], sizeof(supplierEmail[supplierCount]), stdin);
     
    supplierEmail[supplierCount][strcspn(supplierEmail[supplierCount], "\n")] = '\0';

    //4.supplier Telephone
    printf("Enter  Supplier telephone: ");
    fgets(supplierTelephone[supplierCount], sizeof(supplierTelephone[supplierCount]), stdin);

    supplierTelephone[supplierCount][strcspn(supplierTelephone[supplierCount], "\n")] = '\0';

    //5. Town / Location
    printf("Enter supplier town/location: ");
    fgets(supplierLocation[supplierCount], sizeof(supplierLocation[supplierCount]), stdin);

    supplierLocation[supplierCount][strcspn(supplierLocation[supplierCount], "\n")] = '\0';

    //Varification
    printf("\n Supplier %s is added succefully\n", supplierName[supplierCount]);
    printf("\n\n");

    supplierCount++;


}

void displaySupplier (void) {
    if (supplierCount == 0) {
        puts("[!] No supplier registered in the system [!]");
        return;
    }
    puts("");
    puts("Suppliers in the system");
    puts("===============================================");

    for (int i = 0; i < supplierCount; i++) {

        printf("No:                 %d\n", i+1);
        printf("Supplier ID:        %s\n", supplierID[i]);
        printf("Supplier Name:      %s\n", supplierName[i]);
        printf("Supplier Email:     %s\n", supplierEmail[i]);
        printf("Supplier Telephone: %s\n", supplierTelephone[i]);
        printf("Supplier Location:  %s\n", supplierLocation[i]);

        puts("**********************************************");

    }


}

void searchSupplier(void) {

    if (supplierCount == 0) {
        puts("[!] No Supplier registered in the system [!]");
        return;
    }

    char searchKey[STR_LEN];
    int found = 0;

    while (getchar() != '\n');
    printf("\n------------- Search Supplier -----------\n");

    printf("Enter the Supplier ID or Name to search: ");
    fgets(searchKey, sizeof(searchKey), stdin);

    searchKey[strcspn(searchKey, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++) {

        if (strcmp(supplierID[i], searchKey) == 0 || strcmp(supplierName[i], searchKey) == 0) {
            
            puts("Supplier found ");
            printf("ID:         %s\n", supplierID[i]);
            printf("Name:       %s\n", supplierName[i]);
            printf("Email:      %s\n", supplierEmail[i]);
            printf("Telephone:  %s\n", supplierTelephone[i]);
            printf("Location:   %s\n", supplierLocation[i]);
            puts("---------------------------------------------------");

            found = 1;
            break;
        }

    }

        if (!found) {
            printf("No supplier found matching ID or Name '%s' \n", searchKey);
        }
    

}

void compareSupplier(void) {
    if (supplierCount == 0) {
        puts("No suppliers regitered in the system");
        return;
    }

    puts("************************************************");

    printf("\nCOMPARE SUPPLIERS BY LOCATION\n");

    char searchLocation[STR_LEN];
    int found = 0;

    while (getchar() != '\n');


    printf("Enter Location to compare suppliers: ");
    fgets(searchLocation, sizeof(searchLocation), stdin);

    searchLocation[strcspn(searchLocation, "\n")] = '\0';
    
    printf("\nSuppliers operating in '%s':\n", searchLocation);

    for (int i = 0; i < supplierCount; i++) {
        
        if (strcmp(supplierLocation[i], searchLocation) == 0) {
            printf("ID:         %s\n",supplierID[i]);
            printf("Name:       %s\n", supplierName[i]); 
            printf("Email:      %s\n", supplierEmail[i]); 
            printf("Telephone:  %s\n",supplierTelephone[i]);
            puts("---------------------------------------------");
            found = 1;
        }
    }

    

    if (!found) {
        printf("[!] No suppliers found located in '%s'.\n[!]", searchLocation);
    }
}
