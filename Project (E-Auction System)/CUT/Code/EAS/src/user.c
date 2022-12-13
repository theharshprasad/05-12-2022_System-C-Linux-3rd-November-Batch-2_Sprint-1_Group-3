#include<common.h>
#include<user.h>
#include<auction.h>
int checkUser()
{
	while(1)
	{
	int ch;
	system("clear");
	printf("\n\t select option..");	
	printf("\n\t 1.SignIN");
	printf("\n\t 2.SignUp");
	printf("\n\t 3.Back");
	printf("\n\n\n\t select option..");
	scanf("%d",&ch);
	userLog(ch);
	if(ch == 3)
	{
		break;
	}
	}

	return 0;
}

/*****************************************************************/

int userLog(int ch)
{
//	USER *tt =NULL;
	USER *headu=loadUserDetails();
//	headu=(USER *)malloc(sizeof(USER));

	switch(ch)
	{
		case 1:if(userSignIn(headu)==0)
		       {
				printf("\ninvalid username or password\n");
		       		sleep(2);
		       }
				break;
		case 2:headu=userSignUp(headu);
			break;
		case 3://back
			break;
		default:invalid();
			break;
	}

return 0;
}
/*************************************************************************************/
int userSignIn(USER *head)
{
	char *userN = malloc(10*sizeof(char));
	char *userP = malloc(10*sizeof(char));
	//int flag =0;
	printf("\n\tEnter User Name:");
	getchar();
	scanf("%[^\n]",userN);
	printf("\n\tEnter User Passwrd:");
	getchar();
	scanf("%[^\n]",userP);
	printf("%s %s",userN,userP);
	while(head != NULL)
	{
		if((strcmp(head->userName,userN)==0)&&(strcmp(head->userPasswd,userP)==0))
		{
			
			
			userBidMenu();
			return 1;
			break;
		}
		head = head->next;
	}

	return 0;
}
/*******************************************************************************/
int userBidMenu()
{
	while(1)
	{
	int ch;
	system("clear");
	printf("\n\t -----------------------USER BID MENU--------------------");	
	printf("\n\t 1.Display Today's Auction");
	printf("\n\t 2.Bid For Items");
	printf("\n\t 3.Check Message");
	printf("\n\t 4.Quit");
	printf("\n\n\n\t select option..");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:userDisplay();
			break;
		case 2://headu=userSignUp(headu);
			break;
		case 3:return 0;
			break;
		default:invalid();
			break;
	}
	}
return 1;
}
/*********************************************************************************/
int userDisplay()
{
	int t=0;
	time_t tim =time(NULL);
	struct tm *tm=localtime(&tim);
    	char s[11];
	strftime(s,11,"%d/%m/%Y",tm);
   //	sprintf(s,"%d/%d/%d",tm->tm_mday,tm->tm_mon,tm->tm_year);
   //	printf("\n%s",s);
   	AUCTION *head=loadAuctionDetails();
	ITEM *headi=loadItemDetails();
	printf("item id ----item name---------description--------starting bidding price\n");
	while(head !=NULL)
	{
		if(!strcmp(head->tdate,s))
		{
			int i=0;
			while(head->i_id[i] != 0){
				if(head->i_id[i]==headi->_id)
				{
					printf("%d,%s,%s,%d\n",head->i_id[i],headi->name,headi->item_des,head->minprice[i]);
				}
				i++;
			}
			t=1;
		break;
		}
	head=head->next;
	}
	if(t==0){
		printf("\n\t NO AUCTION TODAY");
		sleep(2);
	}
	sleep(10);
	return 0;
}
/******************************************************************************/

USER * userSignUp(USER *head)
{
	USER *newNode = NULL;
	USER *tmpNode = NULL;
	tmpNode = head;

	newNode = (USER *)malloc(sizeof(USER));
	newNode->next = NULL;

	if(head == NULL)
	{
		tmpNode = newNode;
		head = newNode;
	}
	else
	{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
	//	head = head->next;
	}
	//system("clear");
	printf("\n\tEnter User Details,");
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tName: ");
	getchar();
	scanf("%s",newNode->name);
	printf("\n\tPhone Number: ");
	scanf("%s",newNode->phone);
	printf("\n\tGender: ");
	getchar();
	scanf("%s",newNode->gender);
	printf("\n\tUser Name: ");
	scanf("%s",newNode->userName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->userPasswd);
//	*_id = newNode->_id;
    	writeUserDetails(tmpNode);
  //  printf("%p",newNode);
	return tmpNode;
}
/****************************************************************/
int writeUserDetails(USER* head)
{
	FILE *fp = NULL;
	
	fp = fopen("./data/Users.txt","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t No Records Present\n");

	}
//	fprintf(fp,"%p\n",head);
	while(head != NULL){
		fprintf(fp,"%d,%s,%s,%s,%s,%s.\n",head->_id,head->name,head->phone,head->gender,head->userName,head->userPasswd);
		head = head->next;
	}
	fclose(fp);
	return 0;
}
/*************************************************************************/
USER* loadUserDetails()
{
	FILE *fp = NULL;
	USER *newNode = NULL;
	USER *head = NULL;
	USER *user;
	int _fSize = 0;
	int MAX=1024;
	char tmpBuff[1024] = {'\0', };

	fp = fopen("./data/Users.txt","r+");
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
				newNode = (USER *)malloc(sizeof(USER));
				newNode->next = NULL;
				head = newNode;
				user = newNode;
			tokenizeUSER(newNode, tmpBuff);

			}
			else
			{
				newNode = (USER *)malloc(sizeof(USER));
				newNode->next = NULL;
				user->next = newNode;
				tokenizeUSER(newNode, tmpBuff);
				user = user->next;
			}

			memset(tmpBuff,'\0', MAX);


		}

	}

	fclose(fp);
	return head;
}
int tokenizeUSER(USER *_user, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL){
		tokens = strtok(tmpBuff,",");
		_user->_id = atoi(tokens);
		
		tokens = strtok(NULL,",");
		strcpy(_user->name,tokens);
		//removeLeading(tokens,user->name);
		
		tokens = strtok(NULL,",");
		strcpy(_user->phone,tokens);
		//removeLeading(tokens,user->userName);
		//user->phone = atoi(tokens);
		
		tokens = strtok(NULL,",");
		strcpy(_user->gender,tokens);
		
	//	removeLeading(tokens,user->userName);
		tokens = strtok(NULL,",");
		strcpy(_user->userName,tokens);
		
		tokens = strtok(NULL,".");
		strcpy(_user->userPasswd,tokens);
	//  	removeLeading(tokens,user->userPasswd);
	}
	return 0;
}
