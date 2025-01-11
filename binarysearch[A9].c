#include <stdio.h>
struct student
{
	int rno;
	char name[10];
	float per;	
}s[10];
void create()
{	
	int i;
	for(i=0;i<10;i++)
	{
		printf("\n Enter a roll no:");
		scanf("%d",&s[i].rno);
		printf("\n Enter a name:");
		scanf("%s",&s[i].name);
		printf("\n Enter a Percentage:");
		scanf("%f",&s[i].per);
	}
	for(i=0;i<10;i++)
	{
		printf("\n------------");
		printf("\n Roll no:%d""Name:%s""Percentage:%f",s[i].rno,s[i].name,s[i].per);
	}
}

int search()
{
	int key,mid,st,ed;
	
	printf("\n \n Enter a roll no to search:");
	scanf("%d",&key);
	st=0;
	ed=10;
	
	while(st!=mid || ed!=mid)
	{

	mid = (st+ed)/2;
	if(key==s[mid].rno)
	
	{
			printf("\n Roll no:%d\n Name:%s\n Percentage:%f",s[mid].rno,s[mid].name,s[mid].per);
			return;	
	}
	else if(key>s[mid].rno)
	{
		st = mid+1;	
	}
	else
	{
		ed = mid-1;
	}
}
}
int main(){
	create();
	search();
	return 0;
	
}
