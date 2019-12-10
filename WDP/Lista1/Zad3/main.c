#include <stdio.h>

void swap(int *arr, int x, int y)
{
	int tmp;

	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

void sort(int *arr)
{
	if(arr[0] > arr[1])
		swap(arr,0,1);
	if(arr[3] > arr[4])
		swap(arr,3,4);
	if(arr[1] > arr[4])
	{
		swap(arr,1,4);
		swap(arr,0,3);
	}

	if(arr[2] < arr[1])
	{
		if(arr[2] < arr[0])
		{
			swap(arr,2,1);
			swap(arr,1,0);
		}
		else
			swap(arr,1,2);
	}
	else
		if(arr[2] > arr[4])
			swap(arr,2,4);

	if(arr[3] < arr[1])
	{
		if(arr[3] < arr[0])
		{
			swap(arr,3,2);
			swap(arr,2,1);
			swap(arr,1,0);
		}
		else
		{
			swap(arr,3,2);
			swap(arr,2,1);
		}
	}
	else
		if(arr[3] < arr[2])
			swap(arr,2,3);

}



int main(void)
{
	int numbers[5];
	char numbers_name[5][10] = {"pierwszą", "drugą", "trzecią", "czwartą", "piatą"};

	for(int i = 0; i < 5; i++)
	{
		printf("Proszę wprowdzić %s liczbę\n>", numbers_name[i]);
		scanf("%d", &numbers[i]);
	}

	sort(numbers);

	printf("Wprowadzone liczby posortowane w kolejności rosnącej:\n");
	for(int i = 0; i < 5 ;i++)
		printf("%d.\t%d\n", 1+i, numbers[i]);
}
