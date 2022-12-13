#ifndef AUCTION_H
#define AUCTION_H
//#define MAX 1024
/***************************************************************************
*                       HEADER FILES
***************************************************************************/

#include <common.h>
#include <user.h>
#include <admin.h>
#include <item.h>
typedef struct auction                   
{   
       // int _id;
	int _auid;                            
	char tdate[10];            
	int _adid;
	//int status;
	//char src[20];
	//char dst[20];
	int minprice[10];
	//int maxPrice;
	int i_id[10];
	struct auction *next;

} AUCTION;
/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/

int addAuction(AUCTION *);                 
//void printAuction(AUCTION*, USER*, ADMIN*, int);
int dispAuction(AUCTION *, ITEM *);
//int  sellItem(AUCTION *);
int  writeAuction(AUCTION* ,int );
AUCTION* loadAuctionDetails();
int tokenizeAUCTION(AUCTION*, char *);

#endif
