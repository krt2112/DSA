#include<stdio.h>
typedef struct
{
	int sid;
	char *cname;
	char *pname;
	int qty;
	int tam;
}sale;

void merge(sale s[],int l,int mid,int r)
{
	int n1,n2,i,j,k;
	
	n1 = mid-l+1;
	n2 = r-mid;
	
	sale a[n1],b[n2];
	
	for(i=0;i<n1;i++)
	{
		a[i] = s[l+i];
	}
	for(i=0;i<n2;i++)
	{
		b[i] = s[mid+1+i];
	}
	
	i=0,j=0,k=l;
	
	while(i<n1 && j<n2)
	{
		if(a[i].tam>b[j].tam)
		{
			s[k] = a[i];
			k++;
			i++;
		}
		else
		{
			s[k] = b[j];
			k++;
			j++;
		}
	}
	
	while(i<n1)
	{
		s[k] = a[i];
		k++;
		i++;
	}
	
	while(j<n2)
	{
		s[k] = b[j];
		k++;
		j++;
	}
}


void divide(sale s[],int l,int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		divide(s,l,mid);
		divide(s,mid+1,r);
		merge(s,l,mid,r);
	}
}

int main()
{
	int l=0,r=5,i;
	sale s[5];
	
	s[0].sid = 101;
	s[0].cname = "Suyog";
	s[0].pname = "Pen";
	s[0].qty = 5;
	s[0].tam = 50;
	
	s[1].sid = 102;
	s[1].cname = "Sujit";
	s[1].pname = "Box";
	s[1].qty = 5;
	s[1].tam = 55;
	
	s[2].sid = 103;
	s[2].cname = "Rohit";
	s[2].pname = "Pencil";
	s[2].qty = 3;
	s[2].tam = 60;
	
	s[3].sid = 104;
	s[3].cname = "Akash";
	s[3].pname = "Rubber";
	s[3].qty = 6;
	s[3].tam = 30;
	
	s[4].sid = 105;
	s[4].cname = "Shivam";
	s[4].pname = "Sharpner";
	s[4].qty = 4;
	s[4].tam = 40;
	
	divide(s,l,r);
	
	for(i=0;i<5;i++)
	{
		printf("\n SID : %d",s[i].sid);
		printf("\n C.NAME : %s",s[i].cname);
		printf("\n P.NAME : %s",s[i].pname);
		printf("\n QUANTITY : %d",s[i].qty);
		printf("\n TOTAL AMOUNT : %d\n",s[i].tam);
		
	}
	return 0;
}

