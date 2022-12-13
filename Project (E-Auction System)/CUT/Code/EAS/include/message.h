#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct message
{
	int uId;
	int _auid;
	int item_id;
	int sellPrice;
	struct message *next;
} MESSAGE;

int sendMessage();
MESSAGE* loadMessageDetails();
int tokenizeMESSAGE(MESSAGE *_message, char *tmpBuff);








#endif
