#ifndef __TOKENS_H__
#define __TOKENS_H__

#ifndef TOKEN_MAX_LEN
#define TOKEN_MAX_LEN 20
#endif //TOKEN_MAX_LEN 

struct tokens
{
	int max;
	char tokens[TOKEN_MAX_LEN][20];
	int ac[TOKEN_MAX_LEN];
	
};
struct tokens tkRepo;

int tokenInit();
char *id2Token(int id);
int token2Id(const char *token);

int tokenPush(unsigned int *tp,unsigned int id);
unsigned int tokenPop(unsigned int *tp);

#endif // __TOKENS_H__

