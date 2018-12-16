//bubblesort
void bubblesort(int arr[], int n) {
 	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//insertsort
void InsertSort (int arr[],int n)
 {
   int temp,j;
   for(int i=1;i<n;i++)
   {
     j=i-1;
     temp=a[i];
     while(j>=0 && t<arr[j])
     {
       arr[j+1]=arr[j];
       j--;
     }
     arr[j+1]=temp;
   }
 }
 //selectionSor
 void selectionSort(int arr[], int n)
{
    int min,temp; 
    for (int i=0; i<=n-2; i++) 
    { 
        min = arr[i]; 
        for (int j=i+1; j<=n-1; j++) 
            if (arr[j] < min) 
            { 
                min = arr[j];
                temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp;
            }
    }                     
}
