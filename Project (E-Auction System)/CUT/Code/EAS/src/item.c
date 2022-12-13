#include<common.h>
#include<item.h>


int addItem(ITEM * head)
{
	ITEM *newNode = NULL;
	ITEM *tmpNode = NULL;
	tmpNode = head;
	int i=1;
	newNode = (ITEM*)malloc(sizeof(ITEM));
	newNode->next = NULL;
       	 if(head == NULL)
	{
		tmpNode = newNode;
		head = newNode;
	}
	else
	{
		while(head->next != NULL){
			i++;
			head = head->next;
		}

		head->next = newNode;
		head = head->next;
	}

	printf("\n\t============Item============\n");
	printf("\n\tEnter,");
	//printf("\n\tItem ID: ");
	newNode->_id=i+1;
	printf("\n\tItem Name: ");
	//getch();
	scanf("%s",newNode->name);
	printf("\n\tItem Des: ");
	scanf("%s",newNode->item_des);
	printf("\n\tPerchase Price");
	getchar();
	scanf("%d",&newNode->p_price);
	//printf("\n\tMinimum Price ");
	//getchar();
	//scanf("%d",&newNode->min_price);
	//printf("\n\tTravel Date: ");
	//getchar();
	//scanf("%[^\n]s", newNode->tdate);
	

	
//	* _id =  newNode->tid;
     writeItem(tmpNode);

	return 0;
}


int writeItem(ITEM* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/items.txt","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t No Records Present\n");
		
	}
	while(head != NULL){
		fprintf(fp,"%d,%s,%s,%d,0,0,0,noBidder.\n",head->_id,head->name,head->item_des,head->p_price);
		head = head->next;
	}
	fclose(fp);
	return 0;
}
/*************************************************************************/
ITEM* loadItemDetails()
{
	FILE *fp = NULL;
	ITEM *newNode = NULL;
	ITEM *head = NULL;
	ITEM *item;
	int _fSize = 0;
	int MAX=1024;
	char tmpBuff[1024] = {'\0', };

	fp = fopen("./data/Items.txt","r+");
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
				newNode = (ITEM *)malloc(sizeof(ITEM));
				newNode->next = NULL;
				head = newNode;
				item = newNode;
			tokenizeITEM(newNode, tmpBuff);

			}
			else
			{
				newNode = (ITEM *)malloc(sizeof(ITEM));
				newNode->next = NULL;
				item->next = newNode;
				tokenizeITEM(newNode, tmpBuff);
				item = item->next;
			}

			memset(tmpBuff,'\0', MAX);


		}

	}

	fclose(fp);
	return head;
}

/***********************************************************************/

int sellItem()
{

    
    	ITEM *headi=loadItemDetails();
	AUCTION *heada=loadAuctionDetails();
   //USER *headu=loadUserDetails();
    	time_t tim =time(NULL);
   	 struct tm *tm=localtime(&tim);

    	char s[15];
    	strftime(s,15,"%d/%m/%Y",tm);
    	while(heada!=NULL){
        if (!strcmp(heada->tdate,s))
        {
    
    		FILE *fp = NULL;
    		fp = fopen("./data/sales.txt","w+");
		if(fp == NULL)
		{
		
			perror("\n\tfopen() ");
			return -1;
	
		}
		fseek(fp, 0L, SEEK_END);
		int i=0;
		printf("ITEM ID    User Name    Sell Price\n");
		while(heada->i_id[i]!=0){
			while(headi != NULL)
			{
				if (heada->i_id[i]==headi->_id ){
					printf("%d,%s,%d.\n",headi->_id,headi->userName,headi->sellPrice);
				}

				if(heada->i_id[i]==headi->_id && headi->sellPrice!=0){
					fprintf(fp,"%d%s%d%d,%s,%d.\n",heada->_auid,s,headi->userId,headi->_id,headi->userName,headi->sellPrice);
				}
			 headi= headi->next;

			}
		i++;
               }
	fclose(fp);
	}
	heada=heada->next;
	}
	sleep(10);
    return 0;
}


/************************************************************************/
int tokenizeITEM(ITEM *_item, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL){
		tokens = strtok(tmpBuff,",");
		_item->_id = atoi(tokens);

		tokens = strtok(NULL,",");
		strcpy(_item->name,tokens);

		tokens = strtok(NULL,",");
		strcpy(_item->item_des,tokens);
		
		tokens = strtok(NULL,",");
		_item->p_price=atoi(tokens);

		tokens = strtok(NULL,",");
		_item->min_price=atoi(tokens);

		tokens = strtok(NULL,",");
		_item->userId=atoi(tokens);

		tokens = strtok(NULL,",");
		_item->sellPrice=atoi(tokens);

		tokens = strtok(NULL,".");
		strcpy(_item->userName,tokens);
	}
	return 0;
}
