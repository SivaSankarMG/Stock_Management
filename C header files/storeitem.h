typedef struct storeitem{
	int itemcode;
	char itemname[31];
}STOREITEM;

void InitializeItems();
int ReadItemname(int itemcode , char *itemname);
void ListItems();
void AddItems();


STOREITEM *GetStoreItems();
int GetItemscount();

