#ifndef ADMIN_H
#define ADMIN_H
//#define MAX 1024

/*typedef struct admin 
{
	int _id;                  
    	int date;
    	int p_price;
    	int min_price;
	char item_des[20];
	struct admin *next;
}ADMIN;

ADMIN* signUpAdmin(ADMIN*, int *); 
int    signInAdmin(ADMIN*);
void   dispAdmin(ADMIN*);
int    updateItems(ADMIN*);
int    adminMainMenu();
int     writeAdminDetails(ADMIN* );
ADMIN*  loadAdminDetails();
int tokenizeADMIN(ADMIN*, char *);*/
int checkAdmin();
int adminMenu();
int adminSelect(int);
int send_message();
#endif
