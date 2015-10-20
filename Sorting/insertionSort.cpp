/*
	SINWAR PREM
	premsinwar4@gmail.com
	*/
#include<stdio.h>
#include<conio.h>
//function for insertion sorting
void insertionSort(int *a,int n)
{
	int i,j,k;
	//in insertion sorting shifting of elements takes place so here loop start with second element of array
	for(i=1;i<n;i++)
	{
		k=a[i];
		//compare the elements having index less than i
		j=i-1;
		while(j>=0 && k<a[j])
		{
			//shift the elements
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
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
	//call the insertionSort function
	insertionSort(a,n);
	printf("sorted elements by bubblesort\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
