#include<common.h>

/*int writeSales()
{  
    //SALES * heads = loadSalesDetails();
    AUCTION * heada =loadAuctionDetails();
	
	int _id;
	printf("Enter Auction Id:\n");
	scanf("%d",_id);
	while(heada!= NULL){
    
	if (_id == heada->_auid){
	
	FILE *fp = NULL;

	fp = fopen("./data/sales.txt","w+");
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
		fprintf(fp,"%d, %s",head->_auid,head->tdate);
        for(int i=0;i<n;i++)
            fprintf(fp," %d,%d\n",head->i_id[i],head->minprice[i]);
		head = head->next;
	}
	fclose(fp);
	heada=heada->next;
	return 0;
}
*/

SALES* loadSalesDetails()
{	
	int MAX=1024;
	FILE *fp = NULL;
	SALES *newNode = NULL;
	SALES *head = NULL;
	SALES *sales; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("./data/sales.txt","r+");
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
				newNode = (SALES *)malloc(sizeof(SALES));
				newNode->next = NULL;
				head = newNode;
				sales = newNode;
				tokenizeSALES(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (SALES *)malloc(sizeof(SALES));
				newNode->next = NULL;
				sales->next = newNode;
				tokenizeSALES(newNode, tmpBuff);
				sales = sales->next;	
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

int tokenizeSALES(SALES *_user, char *tmpBuff)
{
        char *tokens;
        if(tmpBuff != NULL){
                tokens = strtok(tmpBuff,",");
                _user->_auid = atoi(tokens);

                tokens = strtok(NULL,",");
                strcpy(_user->date,tokens);
               
                tokens = strtok(NULL,",");
               _user->userId = atoi(tokens);
               
                tokens = strtok(NULL,",");
               _user->i_id= atoi(tokens);

                tokens = strtok(NULL,",");
                strcpy(_user->userName,tokens);

                tokens = strtok(NULL,".");
                _user->sellPrice = atoi(tokens);
        }
        return 0;
}
