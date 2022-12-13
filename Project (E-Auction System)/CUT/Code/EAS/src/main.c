#include<stdio.h>
#include<stdlib.h>
#include<user.h>
#include<admin.h>
#include<auction.h>
#include<item.h>
int main()
{
	while(1)
	{
		char c;
		system("clear");
		printf("welcome to auction\n");
	
		printf("press enter to proceed or q to quit\n");
		getchar();
		c=fgetc(stdin);
		
		if(c == 0x0A)
		{
			while(1)
			{
				
				system("clear");
				printf("|- login page-|\n");
				printf("ARE U A--\n");
				printf("1.ADMIN\n");
				printf("2.USER\n");
				printf("3.NEW USER\n");
				printf("4.QUIT\n");
				int i;
				scanf("%d",&i);
				
				switch(i){
					case 1:checkAdmin();	
			 		        //printf("1");
						break;
					case 2: checkUser();
						printf("2");
						break;
					case 3: //NEW_USER();
						printf("3");
						break;
					case 4:	printf("4");
	 					return 0;
					default: printf("enter correct option...");
						 break;

					}
			
			}
		}
		else if( c== 'q')return 0;
	}
	return 0;
}

