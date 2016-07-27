#include <iostream>

using namespace std;

void print_array(int array[], int n)
{
	int i = 0;
	for(i = 0; i < n; ++i)
		cout<<array[i]<<" ";
	cout<<endl;
}

void swap(int array[], int a, int b)
{
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

int partition(int array[], int left, int right)
{
	int pivot = array[left];
	int i;
	int j = left;

	for(i = left+1; i < right; ++i){
		if(array[i] < pivot){
			j++;
			swap(array, i, j);
		}
	}
	swap(array, left, j);
	return j;
}
void qsort(int array[], int left, int right)
{
	int pivot = 0;

	if(left < right){
		pivot = partition(array, left, right);
		qsort(array, left, pivot);
		qsort(array, pivot+1, right);
	}
}


int main()
{

	int array[] = { 3,2,1,0};
	int size = sizeof(array)/sizeof(array[0]);
	qsort(array, 0, size);
	print_array(array, size);
	return 0;
}
