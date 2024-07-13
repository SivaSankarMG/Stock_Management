#include <stdio.h>

#include "Stock Transactions.h"

char TransactionFilename[]="./Transactions.bin";
void ReceiptEntry()
{
	STOCK stk;
	int opt,itemfound;
	char itemname[30];
	FILE *f;
	printf("\nEnter Item code ");
	scanf("%d",&stk.itemcode);
	fflush(stdin);
	
	itemfound=ReadItemname(stk.itemcode,itemname);
	if(itemfound==0)
	{
		printf("Invalid item code ");
		return;
	}
	printf("Item name : %-s",itemname );
	printf("\nIs this item name correct? (y/n) ");
	opt=getchar();
	if(opt=='n' || opt=='N')
	{
		return;
	}
	
	
	printf("\nReceipt Quantity ");
	scanf("%d",&stk.qty);
	fflush(stdin);
	stk.Bal+=stk.qty;	 
	stk.txn='R';
	
	f=fopen(TransactionFilename,"ab");
	fwrite(&stk,sizeof(STOCK),1,f);
	fclose(f);
}

void IssueEntry()
{
	STOCK stk;
	int opt,itemfound;
	char itemname[30];
	FILE *f;
	printf("\nEnter Item code ");
	scanf("%d",&stk.itemcode);
	fflush(stdin);
	
	itemfound=ReadItemname(stk.itemcode,itemname);
	if(itemfound==0)
	{
		printf("Invalid item code ");
		return;
	}
	printf("Item name : %-s",itemname );
	printf("\nIs this item name correct? (y/n) ");
	opt=getchar();
	if(opt=='n' || opt=='N')
	{
		return;
	}
	
	
	printf("\nIssued Quantity ");
	scanf("%d",&stk.qty);
	fflush(stdin);
	stk.Bal-=stk.qty;
	stk.txn = 'I';
	
	f=fopen(TransactionFilename,"ab");
	fwrite(&stk,sizeof(STOCK),1,f);
	fclose(f);
}

void StockTransactionReport()
{
	char itemname[31];
	int itemcode,itemfound;
	long RT=0;long IT=0;
	STOCK item;
	FILE *f;
	printf("\nEnter Item code ");
	scanf("%d",&itemcode);
	
	
	itemfound=ReadItemname(itemcode,itemname);
	if(itemfound==0)
	{
		printf("Invalid item code ");
		return;
	}
	printf("Item name : %-s",itemname );
	
	
	f = fopen(TransactionFilename,"rb");
	while(fread(&item,sizeof(STOCK),1,f))
	{
		if(item.itemcode==itemcode)
		{	
			if(item.txn=='I')
			{	printf("\n  Issue:  %-6d",item.qty);
				IT+=item.qty;
			}
				
			if(item.txn=='R')
			{	printf("\nReceipt:  %14d",item.qty);
				RT+=item.qty;
			}
			
		}
	}
	
	printf("\n-------------------------");
	printf("\nTotal  :  %-6d  %6d",IT,RT);
	printf("\nBalance:  %d",RT-IT);
	fclose(f);

}

void AvailableStock()
{	
	char itemname[31];
	int itemcode,itemfound;
	long Bal=0;
	STOCK dis;
	FILE *f;
	int j;
	for(j=1 ; j<=500 ; j++)
	{	
		itemcode = j;
		itemfound=ReadItemname(itemcode,itemname);
		if(itemfound==0)
		{
		 
			return;
		}
		printf("Item name : %-15s",itemname );
		f = fopen(TransactionFilename,"rb");
		while(fread(&dis,sizeof(STOCK),1,f))
		{
			if(dis.itemcode==itemcode)
		    {
				if(dis.txn=='I')
				{	
					Bal+=dis.qty;
				}
				
				if(dis.txn=='R')
				{	
					Bal-=dis.qty;
				}
			}
		}
		printf(" %10d\n",Bal);
		Bal=0;	  
	}
	fclose(f);	    
}

