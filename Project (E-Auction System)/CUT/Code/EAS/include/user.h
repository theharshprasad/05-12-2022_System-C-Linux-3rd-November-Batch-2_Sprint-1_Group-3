#ifndef USER_H
#define USER_H
//#define MAX 1024
int checkUser();
int userLog(int);
typedef struct user
{
	int _id;
	char name[20];
	char phone[11];
	char gender[7];
	char userName[20];
	char userPasswd[10];
	struct user *next;

} USER;
int writeUserDetails(USER*);
USER *loadUserDetails();
USER *userSignUp(USER*);
//int   writeUserDetails(USER*);
USER* loadUserDetails();
int tokenizeUSER(USER *, char *);
int userSignIn(USER*);
int userMenu();
int bidSelect();
int userBidMenu();
int userDisplay();

#endif
