/*
	SINWAR PREM
	premsinwar4@gmail.com
	*/
#include<stdio.h>
#include<conio.h>
//function for quickSorting
void quicksort(int *a, int n)
{
	
}
int main()
{
	int n,a[1000],i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//calling quicksort function
	quicksort(a,n);
	printf("sorted elements by quickesort\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
