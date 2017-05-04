#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[1000];
int l;
int flag=0;
int main()
{
	freopen("发送内容.txt","r",stdin); 
	freopen("（发）01流.txt","w",stdout);
	
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]>=0) printf("0");
		else printf("1");
		
		s[i]=abs(s[i]);
		printf("%d",s[i]/64);s[i]%=64;
		printf("%d",s[i]/32);s[i]%=32;
		printf("%d",s[i]/16);s[i]%=16;
		printf("%d",s[i]/8);s[i]%=8;
		printf("%d",s[i]/4);s[i]%=4;
		printf("%d",s[i]/2);s[i]%=2;
		printf("%d",s[i]);
		
		
		if(flag < 1) flag++;
		else 
		{
			printf("\n");
			flag=0;	
		}
	}
	printf("\n");
	return 0;
} 
