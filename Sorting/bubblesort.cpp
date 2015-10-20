/*
	SINWAR PREM
	premsinwar4@gmail.com
	*/
#include<stdio.h>
#include<conio.h>
//function for bubble sorting
void bubblesort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		int t=0;
		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				//variable t will change its value whenever swapping occurs
				t++;
			}
		}
		//break the loop if no swapping is there
		if(t==0)
		break;
	}
}
int main()
{
	int n,a[1000],i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//calling bubblesort function
	bubblesort(a,n);
	printf("sorted elements by bubblesort\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
