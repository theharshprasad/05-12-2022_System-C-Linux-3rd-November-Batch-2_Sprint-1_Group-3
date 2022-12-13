#ifndef ITEM_H
#define ITEM_H


typedef struct item
{
	int _id;
	char name[20];
	char item_des[20];
	//int price;
	int p_price;
	int min_price;
	//int item_id;
	//int _item;
	//int tid;
	int userId;
        int sellPrice;
	char userName[20];
	struct item *next;
} ITEM;
int addItem(ITEM*);
int writeItem(ITEM *);
ITEM * loadItemDetails();
int sellItem();
int tokenizeITEM(ITEM *, char *);

	


#endif
