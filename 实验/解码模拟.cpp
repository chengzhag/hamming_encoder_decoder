#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
char s[1000];
int l=0,la;
char a[100010];
int main()
{
	freopen("（收）01流.txt","r",stdin);
	freopen("接受内容.txt","w",stdout); 
	
	while(scanf("%s",a)==1)
	{
		la=strlen(a);
		
		for(int i=0;i<la;i++)
		{
			if(i%8==0) continue;
			s[l]<<=1;
			s[l]+=a[i]-'0';
			if(i%8 == 7)
			{
				if(a[i-7]=='1') s[l]=-s[l];
				l++;
				continue;
			}
		}
		
		for(int i=0;i<la;i++) a[i]=0;
	}
	
	printf("%s\n",s);
	return 0;
} 
