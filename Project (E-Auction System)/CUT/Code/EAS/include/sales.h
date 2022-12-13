#ifndef SALES_H
#define SALES_H

typedef struct sales
{
int _auid;
char date[11];
	int userId;
	int i_id;
	char userName[20];
	int sellPrice;
	struct sales *next;
} SALES;

SALES* loadSalesDetails();
int tokenizeSALES(SALES *_sales, char *tmpBuff);








#endif
