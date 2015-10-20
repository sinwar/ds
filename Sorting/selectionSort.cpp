/*
	SINWAR PREM
	premsinwar4@gmail.com
	*/
	
#include<stdio.h>
#include<conio.h>
//function for selectin sorting in ascending order
void selectionSort(int *a, int n)
{
	int mini,i,j,temp;
	for(i=0;i<n-1;i++)
	{
		mini=i;
		//searching for minimum element
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[mini])
			{
				mini=j;
			}
		}
		//swap this element with a[i]
		temp=a[i];
		a[i]=a[mini];
		a[mini]=temp;
		
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
	//call the selectionSort function
	selectionSort(a,n);
	printf("sorted elements by bubblesort\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
