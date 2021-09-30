#include<stdio.h>
#include<time.h>
#include<sys/time.h>

int search(int arr[], int f, int l, int x)
{
	if(l >= f) {
		int mid = f + (l-1) /2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			return search(arr, f, mid-1, x);
		return search(arr, mid+1, l, x);
	}
	return -1;
}

int main() {
	int n, i, j, temp, x;
		struct timeval start, end;
	
	printf("enter length of array:- ");
	scanf("%d", &n);
	
	int arr[n];
	printf("enter the array elements:- ");
	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(arr[j] > arr[j+1]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
	printf("sorted array: ");
	for(i=0; i<n; i++) {
		printf("%d", arr[i]);
	}
	printf("\nenter element to search:- ");
	scanf("%d", &x);
	
	int f = 0;
	int l = n-1;
	int mid = (f+1)/2;
	
	gettimeofday(&start, NULL);
	
	temp = search(arr, 0, n-1, x);
	
	gettimeofday(&end, NULL);
	
	printf("element found at index number %d", temp+1);
	
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	
	printf("\nthe elapsed time is %d seconds and %d micros\n", seconds, micros);
	
}
