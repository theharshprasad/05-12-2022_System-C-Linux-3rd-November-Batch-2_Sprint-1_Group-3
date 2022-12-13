#include<common.h>
#include<message.h>
#define MAX 1024
int sendMessage()
{  
    SALES * heads = loadSalesDetails();
  //  AUCTION * heada =loadAuctionDetails();
//ITEM *headi=loadItemDetails();	
	int _id;
	printf("Enter Auction Id:\n");
	scanf("%d",&_id);
	
	FILE *fp = NULL;

	fp = fopen("./data/message.txt","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(heads == NULL){
		printf("\n\t no bidding \n");
		
	}
	while(heads != NULL){
if (_id == heads->_auid){
		fprintf(fp,"%d,%d,%d ,%d.",heads->userId,heads->_auid,heads->i_id,heads->sellPrice);
		}
		heads= heads->next;
	}
	fclose(fp);
	return 0;
}


MESSAGE* loadMessageDetails()
{
	FILE *fp = NULL;
	MESSAGE *newNode = NULL;
	MESSAGE *head = NULL;
	MESSAGE *message; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("./data/message.txt","r+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', MAX);
		
		while(fgets(tmpBuff, MAX, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (MESSAGE *)malloc(sizeof(MESSAGE));
				newNode->next = NULL;
				head = newNode;
				message = newNode;
				tokenizeMESSAGE(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (MESSAGE *)malloc(sizeof(MESSAGE));
				newNode->next = NULL;
				message->next = newNode;
				tokenizeMESSAGE(newNode, tmpBuff);
				message = message->next;	
			}
			memset(tmpBuff,'\0', MAX);
			

		}

	}

	fclose(fp);	
	return head;
}

/******************************************************************************
*
*       Function Name   : tokenizeTRIP
*
*       Description     : Tokenize the details of Trip by comma
*
*       Returns         : Success
*
*******************************************************************************/

int tokenizeMESSAGE(MESSAGE *_user, char *tmpBuff)
{
        char *tokens;
        if(tmpBuff != NULL){
                tokens = strtok(tmpBuff,",");
                _user->uId = atoi(tokens);

                tokens = strtok(NULL,",");
                _user->_auid = atoi(tokens);
               
                tokens = strtok(NULL,",");
               _user->item_id = atoi(tokens);
               
                tokens = strtok(NULL,".");
                _user->sellPrice = atoi(tokens);
        }
        return 0;
}
