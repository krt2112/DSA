#include<stdio.h>
struct student
{
	int rno;
	char name;
	float marks;
}s[5],temp;

void accept()
{
	int i;
	
	printf("\n Enter Student Deatils :\n");
	for(i=0;i<5;i++)
	{
		printf("\n Enter %d Student Roll No :",i+1);
		scanf("%d",&s[i].rno);
		
		printf(" Enter %d Student Name :",i+1);
		scanf("%s",&s[i].name);
		
		printf(" Enter %d Student Marks :",i+1);
		scanf("%f",&s[i].marks);
		
	}
}

void display()

{
	int i;
	for(i=0;i<5;i++)
	{
		printf("\n %d Student Roll No :%d",i+1,s[i].rno);
		printf("\n %d Student Name :%c",i+1,s[i].name);
		printf("\n %d Student Marks :%2f%",i+1,s[i].marks);
		
	}
}

void sort()
{
	int i,j;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(s[j].marks>s[j+1].marks)
			{
				temp.rno = s[j].rno;
				temp.name = s[j].name;
				temp.marks = s[j].marks;
				
				s[j].rno = s[j+1].rno;
				s[j].name = s[j+1].name;
				s[j].marks = s[j+1].marks;
				
				s[j+1].rno = temp.rno;
				s[j+1].name = temp.name;
				s[j+1].marks = temp.marks;
				
				
			}
		}
	}
	
	printf("\n Top 3 Students Are :");
	for(i=4;i>1;i--)
	{
		printf("\n %d Student Roll No :%d",i+1,s[i].rno);
		printf("\n %d Student Name :%c",i+1,s[i].name);
		printf("\n %d Student Marks :%2f%",i+1,s[i].marks);
		
	}
}


int main()
{
	
	accept();
	display();
	sort();
	return 0;
}

