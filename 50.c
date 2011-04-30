#include <stdio.h>
#include <string.h>

char *find_str(char str1[],char str2[]);

int main(void)
{
	char str1[1024];
	char str2[1024];
	char *p;

	printf("please input str1:\n");

	fgets(str1,1024,stdin);

	printf("please input str2:\n");

	fgets(str2,1024,stdin);


	p = find_str(str1,str2);

	printf("the all chars is :%s\n",p);

	return 0;
}

char *find_str(char *p,char *q)
{
	char stra[1024] = "a";
	char strb[1024] = "a";
	
	int i = 0;
	int j = 0;
	int count = 0;
	char *n = stra;
	char *m = strb;
	char *k;
	k = q;

	while(*p != '\0')
	{
		q = k;
		while(*q != '\0')
		{
			if(*p == *q)
				count++;
			while((*p == *q)&&(*p != '\0')&&(*q != '\0'))
			{
				if(count == 1)
				{	stra[i] = *p;
					q++;
					p++;
					i++;
				}
				else if(count == 2)
				{
					strb[j] = *p;
					p++;
					q++;
					j++;
		
				}
				else if((strlen(stra) > strlen(strb)) && count >= 3)
				{
					strb[j] = *p;
        	                        p++;
        	                        q++;
        	                        j++;
	
				}
				else if((strlen(stra) <= strlen(strb))&& count >= 3)
				{
					stra[i] = *p;
	                                p++;
	                                q++;
	                                i++;
	
				}
				
			}
			 if(*q != '\0')
        	        {
	                        q++;

                	}
			i = 0;
			j = 0;

		}
		if(*p != '\0')
		{
			p++;
		
		}

		i = 0;
		j = 0;
		
	}
	if(strlen(stra) > strlen(strb))
	{
		*(n+strlen(stra)) = '\0';
		return n;
	}
	else if(strlen(stra) <= strlen(strb))
	{
		*(m+strlen(strb)) = '\0';
		return m;
	}

}
