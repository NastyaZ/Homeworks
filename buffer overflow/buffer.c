#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



void func( char *argv[])
{
	char buf[5];
	strcpy(buf, argv);
}

int main() 
{
   char c[] = "abracadabra"
              "\x34\x87\x87\x09\x76";
   printf("0x%x\n%x", &main, &func);
   func(c);
   return 0;
}
