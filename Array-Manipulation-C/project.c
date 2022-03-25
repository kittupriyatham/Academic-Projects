#include<stdio.h>
#include<stdlib.h>

int insert(int a[100]);

int deletion(int a[100]);

int searching(int a[100]);

int sorting(int a[100]);

int main ()

{
	
int arr[100],c,i,n,s;

while (1)

{
	
printf("enter choice\n");

printf("1.insertion\n");

printf("2.deletion\n");

printf("3.searching\n");

printf("4.sorting\n");

printf("5.exiting\n");

scanf("%d",&c);

switch (c)

{
	
case 1: insert(arr[100]);

    break;
    
case 2: deletion(arr[100]);

    break;   
    
case 3:  searching(arr[100]);

    break; 

case 4:  sorting(arr[100]);

    break; 
case 5:  exit(1);

    break;   
}

printf("enter any number to clear the screen\n");

scanf("%d",&s);

	system("cls");  
}

}




int insert(int a[100])
{
 	
  int p,i,k,j,x,n;
  
  
  printf("Enter number of elements in array\n");
  
  
   scanf("%d", &n);
   
   
  printf("Enter %d elements\n", n);
  
  
   for (i=0;i<n;i++)
   
      scanf("%d", &a[i]);
      
      
      
   printf("Enter the location where you wish to insert an element\n");
   
   scanf("%d", &p);
   
 
   printf("Enter the value to insert\n");
   
   scanf("%d", &x);
 
   for (k=n-1;k>=p-1;k--)
   
      a[k+1] = a[k];
 
   a[p-1]=x;
 
   printf("Resultant array is\n");
 
   for (j=0;j<=n;j++)
   
      printf("%d\n", a[j]);
      
      return 0;
      
 }
 
 
 
 
 
int deletion(int a[100])
{
 	
  int p,i,k,j,n;
  
  printf("Enter number of elements in array\n");
  
   scanf("%d", &n);
   
  printf("Enter %d elements\n", n);
  
  
   for (i=0;i<n;i++)
   
      scanf("%d", &a[i]);
      
      
   printf("Enter the location where you wish to delete element\n");
   
   scanf("%d", &p);
 
   if (p>= n+1)
   
      printf("Deletion not possible.\n");
      
   else
    {
      for (k=p-1;k<n-1;k++)
      
         a[k] = a[k+1];
 
      printf("Resultant array:\n");
 
      for (j=0;j<n-1;j++)
      
         printf("%d\n",a[j]);
         
   }
   
   return 0;
}




int searching(int a[100])
{
	int n,i,num,pos,found;
	
	 printf("Enter number of elements in array\n");
  
   scanf("%d", &n);
   
  printf("Enter %d elements\n", n);
  
  
   for (i=0;i<n;i++)
   
      scanf("%d", &a[i]);
    
	  printf("Enter the number to be searched\n");
    scanf("%d",&num);
    for (i=0;i<n;i++)
    {
    	if(a[i]==num)
    	{
    		found=1;
    		pos=i;
    		printf("%d is found in array at position %d\n",num,i+1);
    		break;
		}
		else
		{
			found=0;
		}
	}
	if (found==0)
	{
		printf("%d doesnt exist in array\n",num);
		return 0;      
	}
}




int sorting(int a[100])
{
	int n,i,j,temp;
	 printf("Enter number of elements in array\n");
  
   scanf("%d", &n);
   
  printf("Enter %d elements\n", n);
  
  
   for (i=0;i<n;i++)
   scanf("%d", &a[i]);
   for(i=0;i<n-1;i++)
    {
      	for(j=0;j<n-i-1;j++)
      	{
      		if(a[j]>a[j+1])
      		{
      		temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;	
			}
		}
	}
	printf("the array sorted in ascending order is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
