#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

char s[1000];
int l,num1;


int main()
{
	freopen("（发）01流（+汉明编码）.txt","r",stdin);
	freopen("01流（已包装）.txt","w",stdout);
	while(scanf("%s",s)==1)
	{
		l=strlen(s);
		printf("01111110");
		for(int i=0;i<l;i++)
		{
			printf("%c",s[i]);
			if(s[i]=='1')
			{
				num1++;
				if(num1==5)
				{
					printf("0");
					num1=0;
				}
			}
			else num1=0;
		}
		printf("01111110\n");
		for(int i=0;i<l;i++) s[i]=0;
		num1=0;
	}
	return 0;
}
