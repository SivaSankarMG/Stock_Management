#include <stdio.h>
#include "storeitem.h"
#include "Stock Transactions.h"
void Menu();

int main()
{
	InitializeItems();
	Menu();
}

void Menu()
{	
	int opt;
	while(1)
	{
		system("cls");
		printf("\nPM STORES");
		printf("\n\nStock Management");
		printf("\n1. Receipt Entry");
		printf("\n2. Issue Entry");
		printf("\n3. Available Stock");
		printf("\n4. Stock Transaction Report");
		printf("\n5. View Items");
		printf("\n6. Add Items");
		printf("\n7. Exit");
		printf("\n\nEnter a value (1-7): ");
		scanf("%d",&opt);
		fflush(stdin);
		
		switch(opt)
		{
			case 1:
				ReceiptEntry();
				break;
			case 2:
				IssueEntry();
				break;
			case 3:
				AvailableStock();
				break;
			case 4:
				StockTransactionReport();
				break;
			case 5:
				ListItems();
				break;
			case 6:
				AddItems();
				InitializeItems();
				break;
			case 7:
				return;
				break;
			default:
				printf("\nInvalid\n");
		}
		printf("\nPress any key to continue....");
		getch();
	}
}

