#include <stdio.h>

#define val 29  

int main()
{
	#ifdef val
		printf("\"val\" Macro is defined\n");
	#else
		printf("\"val\" Macro is not defined\n");
	#endif
	
	#ifndef  max
		printf("\"max\" Macro is not defined\n");
	#else
		printf("\"max\" Macro is not defined\n");
	#endif		
	
	#if val >= 30
		printf("less than 30\n");
	#elif val == 29
		printf("Equal to 30\n");
	#else
		printf("Greater than 30\n");
	#endif	
	
	printf("Hello world\n");
}
