#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) 
{
    for(int i=0;i<=strlen(s);i++)
    {
        for(int j=0;j <= strlen(s);j++)
        {
            if(s[j] == ' ')
                i = j;
            else if (s[j] == '\0')
                return (j-i-1);    
        }
    }
}

int main()
{
    printf("%d",lengthOfLastWord(" "));
    return 0;
}
