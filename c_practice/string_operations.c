#include <stdio.h>
#include <string.h>

int my_atoi(const char *str)
{
	return (int)(*str)-48;
}

char my_strcat(char *d, const char *s)
{
	int dl = strlen(d);
	int sl = strlen(s);
	for(int i=0;i<sl;i++)
	{
		d[dl+i] = s[i];
		d[dl+i+1] = '\0';
	}
	return 1;
}

char my_strchr(const char *str, int c)
{

}

int my_strcmp (const char* str1, const char* str2)
{

}

int main()
{
	printf("atoi : %d\n",my_atoi("9"));
	char d[100]="hello";
	char s[]="! How are u";
	my_strcat(d,s);
	printf("strcat : %s\n",d);
	return 0;
}
