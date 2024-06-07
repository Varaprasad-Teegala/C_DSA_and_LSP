#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* addBinary(char* a, char* b) 
{
	int l=0;
	for(int i=0;i<strlen(a);i++)
		if(a[i] == '1')
		{
			l = 1;
			break;
		}
	for(int j=0;j<strlen(b);j++)
		if(b[j] == '1')
		{
			l = 1;
			break;
		}
	

	if(l == 0)
	{
		char *q = (char *) malloc(2);
		q[0] = '0';
		q[1] = '\0';
		return q;
	}	
	else
	{
		char * p;
         	int c = 0,s = 0;
		int t = 0;
		if(strlen(a) > strlen(b))
    		{
        		p = (char * )calloc(strlen(a)+1,1);
			for(int i = 0 ; i < strlen(a)+1 ;i++)
				p[i] = '0';
			for(int i=0 ; i<strlen(b);i++)
				p[strlen(a) - strlen(b) + i +1 ] = b[i];
	
			for(int i=strlen(a)-1 ;i>=0 ;i--)
			{
				s = ((int)a[i]-48) ^ (int)(p[i+1]-48) ^ c;
				c = ((int)(a[i]-48))&((int)(p[i+1]-48))  |  (int)(p[i+1]-48)&c   |   c&(int)(a[i]-48);
				p[i+1] = s+48;
			}
    		}
   		else //if (strlen(a) < strlen(b))
    		{
       			p = (char * )calloc(strlen(b)+1,1);
        		for(int i =0 ;i<strlen(b)+1 ;i++)
                		p[i] = '0';
        		for(int i=0 ; i<strlen(a);i++)
                		p[strlen(b) - strlen(a) + i +1 ] = a[i];
        		for(int i=strlen(b)-1 ;i>=0 ;i--)
        		{
                		s = ((int)b[i]-48) ^ (int)(p[i+1]-48) ^ c;
                		c = ((int)(b[i]-48))&((int)(p[i+1]-48))  |  (int)(p[i+1]-48)&c   |   c&(int)(b[i]-48);
                		p[i+1] = s+48;
        		}
    		}
    		if(c == 1)
    			p[0] = '1';
    		else
   		{
	    		while((p[0]-48)!=1)
	    		{
        			for(int i=0;i<strlen(p)-1;i++)
     	   				p[i] = p[i+1];
				p[strlen(p)-1] = '\0';
	    		}
    		}
    		return p;
	}
}

int main()
{
    printf("\n string : %s\n",addBinary("11","1") );
    return 0;
}

