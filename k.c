#include <stdio.h>
#include<string.h>
int find_world(char *s,char *w);
int main(int argc, const char *argv[])
{
    char str[]="This is my girlfriend!";
    char s[]="is";
    int num = find_world(str,s);
    if(num<0)
    {
        printf("NO such a word\n");
    }
    else
    {
        printf("%d\n",num);
        printf("press enter to test...\n");
        getchar();
        printf("%s\n",str+num);
    }


    return 0;
}

int find_world(char *s,char *w)
{
        int i = 0;
        while (s[i] != '\0') 
        {
            if(strncmp(s+i,w,strlen(w))==0)
            {
                    return i;     
            }
            i++;
        }
        return -1;
        

}
