#include <stdio.h>
#include <string.h>
#include "storeitem.h"

STOREITEM items[50];
int itemcount;

char filename[]="./storeitems.dat";
void  InitializeItems()
{
	STOREITEM item;
	FILE *f;
	f=fopen(filename,"rb");
	itemcount=0;
	while(fread(&item , sizeof(STOREITEM),1,f))
	{
		items[itemcount].itemcode = item.itemcode;
		strcpy(items[itemcount].itemname,item.itemname);
		itemcount++;
	}
	fclose(f);
}


void ListItems()
{
	int i;
	STOREITEM item;
	printf("\n List of Items \n");
	for(i=0;i<itemcount;i++)
	{
	
		item = items[i];
	
		printf("\n%3d  %-30s",item.itemcode,item.itemname);
	}
}


void AddItems()
{
	FILE *f;
	STOREITEM item;
	printf("\nEnter Item code ");
	scanf("%d",&item.itemcode);
	fflush(stdin);
	
	printf("\nEnter Item name ");
	gets(item.itemname);
	
	f=fopen(filename, "ab");
	fwrite(&item,sizeof(STOREITEM),1,f);
	
	fclose(f);
}

int ReadItemname(int itemcode , char *itemname)
{
	int itemfound = 0;
	int i;
	for(i=0 ; i<itemcount; i++)
	{
		if(itemcode == items[i].itemcode)
		{
			strcpy(itemname,items[i].itemname);
			itemfound=1;
			break;
		}
	}
	return itemfound;
}

