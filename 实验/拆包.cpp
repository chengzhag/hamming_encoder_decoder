#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

char s[1000];
int l,num1;


int main()
{
	freopen("01流（已包装）.txt","r",stdin);
	freopen("（收）01流（+汉明编码）.txt","w",stdout);
	while(scanf("%s",s)==1)
	{
		l=strlen(s);
		for(int i=8;i<l-8;i++)
		{
			printf("%c",s[i]);
			if(s[i]=='1') num1++;
			else num1=0;
			if(num1==5)
			{
				i++;
				num1=0;
			}
		}
		printf("\n");
		for(int i=0;i<l;i++) s[i]=0;
		num1=0;
	}
	return 0;
}
