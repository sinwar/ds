/*
	SINWAR PREM
	premsinwar4@gmail.com
	*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//it sorts array such that the elements less than pivot are left side(one side) of array 
int partition(int a[], int p, int r)
{
  int i, j, pivot, temp;
  pivot = a[p];
  i = p;
  j = r;
  while(1)
  {
   while(a[i] < pivot && a[i] != pivot)
   i++;//increament in pivot index if element less than pivot element
   while(a[j] > pivot && a[j] != pivot)
   j--;//vice versa of above comment
   if(i < j)//swap elements so that lesser elements come one side
   {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
   }
   else
   {
    return j;
   }
  }
}


//function for quickSorting
//p and q are start and end indexes of a array to be sorted

void quicksort(int *a, int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r); //calling partition function
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
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
	//calling quicksort function
	quicksort(a,0,n-1);
	printf("sorted elements by quicksort\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}

