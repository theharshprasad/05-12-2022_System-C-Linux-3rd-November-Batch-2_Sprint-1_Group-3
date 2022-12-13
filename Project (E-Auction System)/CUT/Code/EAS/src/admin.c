#include <common.h>
#include <admin.h>

int checkAdmin()
{   system("clear");
    char *c= malloc(10 *sizeof(char));
    char *p= malloc(10 *sizeof(char));
    printf("Enter userName:");
    scanf("%s",c);
    printf("\n Enter password:");
    scanf("%s",p);
//	printf("%s",c);	   
   if((!(strcmp(c,"admin")) && !(strcmp(p,"admin"))))
    { 
	   // printf("2");

        adminMenu();
        return 0;
    }
    //return FAILURE;
     return 1;
}
/****************************************************************************************/

int adminMenu()
{
	while(1)
	{system("clear");
	int ch;
	printf("\n\t==================Admin's Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. Add Items");
	printf("\n\t2. Add Auction");
	printf("\n\t3. Display Auctions");
	printf("\n\t4. Sell Items");
   	printf("\n\t5. Send messages");
    	printf("\n\t6. Log Out");
	printf("\n\tEnter Your Choice: ");
	scanf("%d",&ch);
//	printf("%d",ch);
	adminSelect(ch);
	if(ch==6)
		break;
	}
    return 0;
}
/***********************************************************/

int adminSelect(int ch){
    switch(ch){
        case 1:addItem(loadItemDetails());
	      
        break;
        case 2:addAuction(loadAuctionDetails());
        break;
        case 3:dispAuction(loadAuctionDetails(),loadItemDetails());
        break;
        case 4:sellItem();
        break;
        case 5:sendMessage();
        break;
	case 6://Quit
        break;
        default:invalid();
		return 0;
        break;

    }
return 0;
}
