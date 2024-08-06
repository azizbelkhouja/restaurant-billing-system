#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void generateBillHeader(char name[50],char date[30]);
void generateBillBody(char item[30],int qty, float price);
void generateBillFooter(float total);

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

int main()
{
    
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y',contFlag = 'y';
    char name[50];
    FILE *fp;
    
    while(contFlag == 'y')
    {
    system("cls");
    float total = 0;
    int invoiceFound = 0;
    printf("\n********** Ristorante Unife **********\n");
    printf("\nseleziona l'operazione desiderata");
    printf("\n\n1.Genera Fattura");
    printf("\n2.Mostra tutte le Fatture");
    printf("\n3.Cerca Fattura");
    printf("\n4.Esci");

    printf("\n\nLa tua scelta: ");
    scanf("%d",&opt);
    fgetc(stdin);

    system("cls");

    switch(opt)
    {
        case 1:
        system("cls");
        printf("\ninserisci il nome del cliente:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date,__DATE__);
        printf("\ninserisci il numero di articoli:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("inserisci l'articolo %d:\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("inserisci la quantità:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("inserisci il prezzo unitario:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customer,ord.date);

        for(int i=0;i<ord.numOfItems;i++)
        {
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("\nVuoi salvare la fattura [y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill == 'y')
        {
            fp = fopen("RestaurantBill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nSalvato con successo");
            else 
            printf("\nErrore durante il salvataggio");
            fclose(fp);
        }
        break;

        case 2:
        system("cls");
        fp = fopen("RestaurantBill.dat","r");
        printf("\n  *****Le tue fatture precedenti*****\n");
        while(fread(&order,sizeof(struct orders),1,fp))
        {
            float tot = 0;
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
        }

        fclose(fp);
        break;

        case 3:
        printf("Inserisci il nome del cliente:\t");
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        system("cls");
        fp = fopen("RestaurantBill.dat","r");
        printf("\t*****Fattura di %s*****",name);
        while(fread(&order,sizeof(struct orders),1,fp))
        {
            float tot = 0;
            if(!strcmp(order.customer,name)){
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
            invoiceFound = 1;
            }
        }
        if(!invoiceFound)
        {
            printf("la fattura per %s non esiste",name);
        }

        fclose(fp);
        break;

    case 4:
    printf("\n\t\t Grazie :)");
    exit(0);
    break;

    default:
    printf("opzione non valida");
    break;
    }
    printf("\nVuoi eseguire un'altra operazione?[y/n]:\t");
    scanf("%s",&contFlag);
    }
    printf("\n\t\t Grazie :)");
    printf("\n\n");

    return 0;
}

void generateBillHeader(char name[50],char date[30])
{
    printf("\n\n");
        printf("\n********** Ristorante Unife **********\n");
        printf("--------------------------------------\n");
        printf("Data: %s",date);
        printf("\nFattura a: %s",name);
        printf("\n\n");
        printf("--------------------------------------\n");
        printf("Articoli\t\tQtà\t\tTotale\t\t\n");
        printf("--------------------------------------\n");
        printf("\n");
}

void generateBillBody(char item[30],int qty, float price)
{
    printf("%s\t\t",item); 
    printf("%d\t\t",qty); 
    printf("%.2f\t\t",qty * price); 
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float iva = 0.07 * total;
    printf("--------------------------------------\n");
    printf("TOTALE COMPLESSIVO\t %0.2f", total);
    printf("\nDi cui IVA\t\t %0.2f\n", iva);
}
