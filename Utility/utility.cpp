#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
int getch()
{
	struct termios tm,tm_old;
	int fd = STDIN_FILENO,c;
	if(tcgetattr(fd,&tm)<0)
	{
		return -1;
	}
	tm_old=tm;
	cfmakeraw(&tm);
	if(tcsetattr(fd,TCSANOW,&tm)<0)
    {
        return -1;
	}
	c = fgetc(stdin);
	if(tcsetattr(fd,TCSANOW,&tm_old) < 0)
	{
		return -1;
	}
	return c;
}
