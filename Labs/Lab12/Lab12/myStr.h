#ifndef myStr_
#define myStr_

class myStr
{
public:
	myStr();
	short myStrLen(char s[]);
	short myStrLenP(char *ps);
	void myStrCpy(char to[], char from[]);
	void myStrCpyP(char *pTo, char *pFrom);
private:
	char s[20];
};


#endif