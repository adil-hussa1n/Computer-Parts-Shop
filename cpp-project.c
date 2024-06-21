#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR "cls"
#define MAX 50

typedef struct items
{
    char itemCode[MAX];
    char itemName[MAX];
    char price[MAX];
    char description[MAX];
} Item;

Item item;

void options();
int isCodeAvailable();
void addProd();
void deleteProd();
void editProd();
void display();
int b;

int main()
{
    options();
    system(CLEAR);
    return 0;
}

void options()
{
    {
        /* char id[50],a[10];
        Start:
         printf("\n\t\t\t\t\t*****Welcome To APMRS Tech Shop*****\n");
         printf("\t\t\t\t\t\t  1. Shopping\n");
         printf("\t\t\t\t\t\t  2. Admin Login\n");

         printf("\t\t\t\t\t\tEnter your choice : ");
         scanf("%s",&a);

         if (strcmp(a,"2")==0)
             goto User;
         else
         {
             printf("\t\t\t\t\t\t Enter number 1 or 2\n");
             goto Start;
         }
        User:
         printf("\n\t\t\t\t\t\tEnter Admin ID : ");
         scanf("%s", &id);

         if (strcmp(id,"apmrs")==0)
         {
             printf("\t\t\t\t\t\tId is correct\n");
         }
         else
         {
             printf("\t\t\t\t\t\tAccess Denied\n\t\t\t\t\t\tPlease enter ID again\n");
             goto User;
         }
         char pass[50];

        pass:
         printf("\t\t\t\t\t\tEnter password : ");
         scanf("%s", &pass);

         if(strcmp(pass,"12345")==0)
         {
             printf("\t\t\t\t\t\tWelcome. Login successful...\n\n");
         }
         else
         {
             printf("\t\t\t\t\t\tAccess Denied\n\t\t\t\t\t\tEnter password again\n");
             goto pass;
         }*/
    }
    int choice;

    do
    {
        printf("\t\t\t\t\t******Welcome To APMRS Admin Panel******");
        printf("\n\t\t\t\t\t---------------------------------------");
        printf("\n\t\t\t\t\t\t1. ADD A PRODUCT");
        printf("\n\t\t\t\t\t\t2. DELETE A PRODUCT");
        printf("\n\t\t\t\t\t\t3. EDIT A PRODUCT");
        printf("\n\t\t\t\t\t\t4. DISPLAY Shop");
        printf("\n\t\t\t\t\t\t5. EXIT THE RROGRAM");
        printf("\n\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\tEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            system(CLEAR);
            addProd();
            break;
        case 2:
            system(CLEAR);
            deleteProd();
            break;
        case 3:
            system(CLEAR);
            editProd();
            break;
        case 4:
            system(CLEAR);
            display();
            break;
        case 5:
            system(CLEAR);
            printf("\n\n\n\n\n\n\n\n\n\n");
            printf("\n\n\n\t\t\t\t\t    Thanks for using my program!\n\n\n");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\t\tWrong input. Please enter a number between 1 & 5\n\n\n");
            break;
        }
    }
    while (choice != 5);
}

void display()
{
    int count = 0,b;
    FILE *file;
    printf("\n\t\t\t\t\t\t1. Laptop\n");
    printf("\t\t\t\t\t\t2. Monitor\n");
    printf("\t\t\t\t\t\t3. MotherBoard\n");
    printf("\t\t\t\t\t\t4. Ram\n");
    printf("\t\t\t\t\t\t5. Storage\n");
    printf("\t\t\t\t\t\t6. CPU\n");
    printf("\t\t\t\t\t\t7. PowerSupply\n");
    printf("\t\t\t\t\t\t8. Accessories\n");
    printf("\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&b);
 display:
    switch(b)
    {
    case 1:
        file = fopen("laptop.txt", "r");

        break;
    case 2:
        file = fopen("monitor.txt", "r");

        break;
    case 3:
        file = fopen("motherboard.txt", "r");

    case 4:
        file = fopen("ram.txt", "r");

        break;
    case 5:
        file = fopen("storage.txt", "r");

        break;
    case 6:
        file = fopen("cpu.txt", "r");

        break;
    case 7:
        file = fopen("power.txt", "r");

        break;
    case 8:
        file = fopen("accessories.txt", "r");

        break;

    /*case 0:
        system("cls");
        firstPortion();
        break;*/
    default:
        printf("Sorry, Wrong choice... Try Again...");
        display();
    }

    printf("\t\t\t\t\t\t    AVAILABLE PRODUCTS\n");
    printf("\t\t\t\t\t\t***************************\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf(" CODE\t\t||    NAME\t\t||     price\t||      \tDESCRIPTION\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    while (fread(&item, sizeof(item), 1, file))
    {
        printf("  %s\t\t||   %s\t||     %s\t||     %s\t\t\n", item.itemCode, item.itemName, item.price, item.description);

        count++;
    }
    printf("--------------------------------------------------------------------------------------------------------------------------\n\n\n");

    if (count == 0)
    {
        system(CLEAR);
        printf("\n\t\t\t\t\t   No products available in store\n\n\n");
    }
    fclose(file);
}


int isCodeAvailable(char code[])
{
    FILE *file;
    file = fopen("Record.txt", "r");

    while (fread(&item, sizeof(item), 1, file))
    {
        if(strcmp(code, item.itemCode) == 0)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void addProd()
{
    char code[MAX];
    int b;
    FILE *file;

    printf("\n\t\t\t\t\t\t1. Laptop\n");
    printf("\t\t\t\t\t\t2. Monitor\n");
    printf("\t\t\t\t\t\t3. MotherBoard\n");
    printf("\t\t\t\t\t\t4. Ram\n");
    printf("\t\t\t\t\t\t5. Storage\n");
    printf("\t\t\t\t\t\t6. CPU\n");
    printf("\t\t\t\t\t\t7. PowerSupply\n");
    printf("\t\t\t\t\t\t8. Accessories\n");
    printf("\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&b);

    switch(b)
    {
    case 1:
        file = fopen("laptop.txt", "a");

        break;
    case 2:
        file = fopen("monitor.txt", "a");

        break;
    case 3:
        file = fopen("motherboard.txt", "a");

        break;
    case 4:
        file = fopen("ram.txt", "a");

        break;
    case 5:
        file = fopen("storage.txt", "a");

        break;
    case 6:
        file = fopen("cpu.txt", "a");

        break;
    case 7:
        file = fopen("power.txt", "a");

        break;
    case 8:
        file = fopen("accessories.txt", "a");

        break;

    /*case 0:
        system("cls");
        firstPortion();
        break;*/
    default:
        printf("Sorry, Wrong choice... Try Again...");
        break;
    }

    //display();
jump:
    printf("\t\t\t\t\t    *****ADDING A PRODUCT*****\n\n");
    printf("\t\t\t\t   Enter \"end\" if you want to go back to main menu\n\n");
    printf("\t\t\t\t\t\tProduct Code:");
    scanf("%s", code);

    if (strcmp(code, "end") == 0)
    {
        system(CLEAR);
        options();
    }

    /*if(isCodeAvailable(code) == 1)
    {
        printf("\n\n\t\t\t\t\tProduct already exists!\n\n\n");
        goto jump;
    }*/

    strcpy(item.itemCode, code);

    printf("\t\t\t\t\t\tProduct Name:");
    scanf("%s", item.itemName);

    printf("\t\t\t\t\t\tProduct price:");
    scanf("%s", &item.price);

    printf("\t\t\t\t\t\tDescription:");
    scanf("%s", item.description);

    if(fwrite(&item, sizeof(item), 1, file))
    {
        printf("\n\t\t\t\t\t\tproduct added successfully!\n\n\n");
    }
    fclose(file);
}

void deleteProd()
{
    FILE *file1, *file2;
    char code[MAX];
    /*int b;
    printf("\n\t\t\t\t\t\t1. Laptop\n");
    printf("\t\t\t\t\t\t2. Monitor\n");
    printf("\t\t\t\t\t\t3. MotherBoard\n");
    printf("\t\t\t\t\t\t4. Ram\n");
    printf("\t\t\t\t\t\t5. Storage\n");
    printf("\t\t\t\t\t\t6. CPU\n");
    printf("\t\t\t\t\t\t7. PowerSupply\n");
    printf("\t\t\t\t\t\t8. Accessories\n");
    printf("\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&b);
 //goto display;
    switch(b)
    {
    case 1:
        file1 = fopen("laptop.txt", "r");
        break;
    case 2:
        file1 = fopen("monitor.txt", "r");
        break;
    case 3:
        file1 = fopen("motherboard.txt", "r");
    case 4:
        file1 = fopen("ram.txt", "r");
        break;
    case 5:
        file1 = fopen("storage.txt", "r");
        break;
    case 6:
        file1 = fopen("cpu.txt", "r");
        break;
    case 7:
        file1 = fopen("power.txt", "r");
        break;
    case 8:
        file1 = fopen("accessories.txt", "r");
        break;
    default:
        printf("Sorry, Wrong choice... Try Again...");
        //display();
    }*/

    file1 = fopen("laptop.txt", "r");
    file2 = fopen("temp.txt", "w");
display();

jump:
    printf("\t\t\t\t\t    *****DELETING A PRODUCT*****\n\n");
    printf("\t\t\t\t   Enter \"end\" if you want to go back to main menu\n\n");
    printf("\t\t\t\t   Enter the code of the product you want to delete: ");
    scanf("%s", code);

    if (strcmp(code, "end") == 0)
    {
        system(CLEAR);
        options();
    }

    if(isCodeAvailable(code) == 0)
    {
        printf("\n\n\t\t\t\t\t\tProduct doesn't exist!\n\n\n");
        goto jump;
    }

    while (fread(&item, sizeof(item), 1, file1))
    {
        if (strcmp(code, item.itemCode) != 0)
        {
            fwrite(&item, sizeof(item), 1, file2);
        }
    }
    fclose(file1);
    fclose(file2);

    file1 = fopen("laptop.txt", "w");
    file2 = fopen("temp.txt", "r");

    while (fread(&item, sizeof(item), 1, file2))
    {
        fwrite(&item, sizeof(item), 1, file1);
    }
    printf("\n\v\t\t\t\t\t\tProduct deleted successfully!\n\n\n\n");

    fclose(file1);
    fclose(file2);
}

void editProd()
{
    char code[MAX];
    FILE *file1, *file2;

    display();
jump:
    printf("\t\t\t\t\t    *****UPDATING A PRODUCT*****\n\n");
    printf("\t\t\t\t   Enter \"end\" if you want to go back to main menu\n\n");
    printf("\t\t\t\t   Enter the code of the product you want to edit: ");
    scanf("%s", code);

    if (strcmp(code, "end") == 0)
    {
        system(CLEAR);
        options();
    }

    if(isCodeAvailable(code) == 0)
    {
        printf("\n\n\t\t\t\t\t\tProduct doesn't exist!\n\n\n");
        goto jump;
    }

    file1 = fopen("Record.txt", "r");
    file2 = fopen("temp.txt", "w");

    while(fread(&item, sizeof(item), 1, file1))
    {

        if(strcmp(code, item.itemCode) != 0)
        {
            fwrite(&item, sizeof(item), 1, file2);
        }
        else
        {
            printf("\t\t\t\t\t\tProduct Name:");
            scanf("%s", item.itemName);

            printf("\t\t\t\t\t\tProduct price:");
            scanf("%s", &item.price);

            printf("\t\t\t\t\t\tDescription:");
            scanf("%s", item.description);

            fwrite(&item, sizeof(item), 1, file2);
        }
    }
    fclose(file1);
    fclose(file2);

    file1 = fopen("Record.txt", "w");
    file2 = fopen("temp.txt", "r");

    while(fread(&item, sizeof(item), 1, file2))
    {
        fwrite(&item, sizeof(item), 1, file1);
    }

    printf("\n\n\t\t\t\t\tData has been updated successfully\n\n\n");

    fclose(file1);
    fclose(file2);
}
