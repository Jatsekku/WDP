#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct __digits
{
    int* content;
    size_t len;
}digit_t;

digit_t* RandomDigit(int min, int max, size_t n_of_digits)
{
  digit_t* result = malloc(sizeof(digit_t));
  result->content = malloc(sizeof(int)*n_of_digits);
  result->len = n_of_digits;

  int tmp;
  if (max>=min)
    max-= min;
  else
  {
    tmp= min - max;
    min= max;
    max= tmp;
  }

  for(size_t it = 0; it < n_of_digits; it++)
     result->content[it] = max ? (rand() % max + min) : min;

  return result;
}


void _Qsort(int* target, int left, int right)
{
  if(left >= right) return;
  int it1 = left;
  int it2 = right;
  int tmp, pivot = target[it1];
  while(1)
  {
    while(target[it1] < pivot)
      it1++;
    while(pivot < target[it2])
      it2--;
    if(it1 >= it2)
      break;

    //swap
    tmp = target[it1];
    target[it1] = target[it2];
    target[it2] = tmp;

    it1++;
    it2--;
  }
  _Qsort(target, left, it1-1);
  _Qsort(target, it2+1, right);
}

void Qsort(digit_t* data)
{
  _Qsort(data->content, 0, data->len);
}

void DisplayDigit(digit_t* data)
{
    for(int it = 0; it < data->len; it++)
      printf("%d\t#\t%d\n", it, data->content[it]);
}



uint8_t isDataSorted(digit_t* data)
{
  int old_val = -100;
  size_t ok = 0;

  for(int it = 0; it < data->len; it++)
  {
    if(data->content[it] >= old_val)
      ok++;
    else
      break;
    old_val = data->content[it];
  }

  if(ok == data->len)
    return 1;
  else
    return 0;
}

void _MergeSort(int* array, int start_idx, int end_idx)
{
	int left_idx, sym_idx, right_idx;
	int idx_tmp1, idx_tmp2, idx_tmp3;

	sym_idx = (start_idx + end_idx) / 2;

	if(start_idx != end_idx)
	{
		_MergeSort(array, start_idx, sym_idx);
		_MergeSort(array, sym_idx+1, end_idx);

		int* array_tmp = malloc(sizeof(int)* (end_idx - start_idx +1));
		idx_tmp1 = 0;
		left_idx = start_idx;
		right_idx = sym_idx+1;

		while(left_idx <= sym_idx && right_idx <= end_idx)
		{
			if(array[left_idx] < array[right_idx])
				array_tmp[idx_tmp1] = array[left_idx++];
			else
				array_tmp[idx_tmp1] = array[right_idx++];
			idx_tmp1++;
		}

		while(left_idx <= sym_idx)
			array_tmp[idx_tmp1++] = array[left_idx++];

		while(right_idx <= end_idx)
			array_tmp[idx_tmp1++] = array[right_idx++];

		for(idx_tmp2 = start_idx, idx_tmp3 = 0; idx_tmp2 <= end_idx; idx_tmp2++, idx_tmp3++)
			array[idx_tmp2] = array_tmp[idx_tmp3];
		free(array_tmp);												//Zwolnienie pamiêci
	}
}

void Msort(digit_t* data)
{
    _MergeSort(data->content, 0, data->len);
}

int main(void)
{
  //Qsort
  digit_t* data_Q = RandomDigit(1,100,100);
  printf("Q Nieposrtowane dane:\n");
  DisplayDigit(data_Q);
  Qsort(data_Q);
  printf("Q Posortowane dane:\n");
  DisplayDigit(data_Q);
  printf("### Q Sprawdzenie: ###\n");
  if(isDataSorted(data_Q))
    printf("Q Posortowane\n");
  else
    printf("Q NIEposrtowane\n");

  //Msort
  digit_t* data_M = RandomDigit(1,100,100);
  printf("M Nieposrtowane dane:\n");
  DisplayDigit(data_M);
  Msort(data_M);
  printf("M Posortowane dane:\n");
  DisplayDigit(data_M);
  printf("### M Sprawdzenie: ###\n");
  if(isDataSorted(data_M))
    printf("M Posortowane\n");
  else
    printf("M NIEposrtowane\n");

}
