#include <common.h>
#include <auction.h>

/******************************************************************/

int addAuction(AUCTION * head)
{
        char *date=malloc(10*sizeof(char));
        printf("Enter A Date\n ");
	scanf("%s",date);
	getchar();
	AUCTION *newNode = NULL;
	AUCTION *tmpNode = NULL;
	tmpNode = head;

	newNode = (AUCTION*)malloc(sizeof(AUCTION));
	newNode->next = NULL;

	if(head == NULL)
	{
		tmpNode = newNode;
		head = newNode;
	}
	else
	{
		while(head->next != NULL && head->tdate != date ){

			head = head->next;
		}
        if(head != NULL)
	{
		printf(" Date already exist");
        return 0;
	}
		head->next = newNode;
		head = head->next;
	}
        int n;
	printf("\n\t============Booking============\n");
	printf("\n\tEnter,");
	printf("\n\tAuction ID: ");
	scanf("%d",&newNode->_auid);
	strcpy(newNode->tdate,date);
        printf("\n\tenter no of item list ");
	scanf("%d",&n);
	int i;
        for( i=0;i<n;i++)
   	{
        printf("\n\tenter Item %d: ",i+1);
	scanf("%d",&newNode->i_id[i]);
        printf("\n\tenter min sell price for Item %d: ",i+1);
        scanf("%d",&newNode->minprice[i]);
	}   
        newNode->i_id[i]=0;
	//int _id;
	//*_id =  newNode->_auid;

        writeAuction(tmpNode,n);
        return 0;
}

/*********************************************************************/

int writeAuction(AUCTION* head, int n)
{
	FILE *fp = NULL;

	fp = fopen("./data/auction.txt","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t Creating New FILE...\n");

	}
	while(head != NULL){
		fprintf(fp,"%d,%s,",head->_auid,head->tdate);
		for(int i=0;i<n;i++){
            		fprintf(fp,"%d,%d,",head->i_id[i],head->minprice[i]);
		}
			fprintf(fp,"0,\n");
		head = head->next;
	}
	fclose(fp);
	return 0;
}


/***********************************************************************/


int dispAuction(AUCTION *ahead,ITEM *ihead)
	
{
//	AUCTION *_dd;
	char *date=malloc(10*sizeof(char));
	//AUCTION _dd;
	printf("\n\t Enter date :");
	getchar();
	scanf("%s",date);
	while(ahead != NULL)
	{
		if(!strcmp(ahead->tdate,date))
		{	
			printf("\n\tAuction ID:%d",ahead->_auid);              			    printf("\t\tDate:%s\n",ahead->tdate);
			printf("item id----item name-----description--- purchase price-----minimum sell price-------");


            		for(int i=0;i!='x';i++)
            		{
                		while(ihead->next != NULL)
                		{
                    		if(ahead->i_id[i] == ihead->_id)
                    		{   
                        	printf("\n%d",ahead->i_id[i]);
                      		printf("\t%s",ihead->name);
				printf("\t%s",ihead->item_des);
                        	printf("\t%d",ihead->p_price);
                        	printf("\t%d\n",ihead->min_price );
			        }
                   		 ihead = ihead->next;
               		 	}
           		}
		}
		ahead = ahead->next;
		sleep(6);
	}return 0;
}
/************************************************************************/
AUCTION* loadAuctionDetails()
{
	FILE *fp = NULL;
	AUCTION *newNode = NULL;
	AUCTION *head = NULL;
	AUCTION *auction;
	int _fSize = 0;
	int MAX=1024;
	char tmpBuff[1024] = {'\0',};

	fp = fopen("./data/auction.txt","r+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);

	if(_fSize == 0) 
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', MAX);

		while(fgets(tmpBuff, MAX, fp)){

			if(head == NULL)
			{
				newNode = (AUCTION *)malloc(sizeof(AUCTION));
				newNode->next = NULL;
				head = newNode;
				auction = newNode;
				tokenizeAUCTION(newNode, tmpBuff);

			}
			else
			{
				newNode = (AUCTION *)malloc(sizeof(AUCTION));
				newNode->next = NULL;
				auction->next = newNode;
				tokenizeAUCTION(newNode, tmpBuff);
				auction = auction->next;
			}
			memset(tmpBuff,'\0', MAX);


		}

	}

	fclose(fp);
	return head;
}

/***************************************************************************/


int tokenizeAUCTION(AUCTION *_auction, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL)
	{
		tokens = strtok(tmpBuff, ",");
		_auction->_auid=atoi(tokens);
		
		tokens = strtok(NULL, ",");
		strcpy(_auction->tdate,tokens);

		tokens = strtok(NULL, ",");
		int i=0;
		while(tokens!=0)
		{
		_auction->i_id[i]=atoi(tokens);
		
		tokens = strtok(NULL, ",");
		
		_auction->minprice[i]=atoi(tokens);
		tokens = strtok(NULL, ",");
		i++;
		}
		//tokens = strtok(tmpBuff, ",");
		//removeLeading(tokens,auction->src);
		
		//tokens = strtok(tmpBuff, ",");
		//removeLeading(tokens,auction->dst);
		//tokens = strtok(tmpBuff, ".");
		//removeLeading(tokens,auction->tdate);
	}
    return 0;
}

