#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct __digits
{
    int* content;
    size_t len;
}digit_t;

int Min(digit_t* data)
{
  int min_tmp = INT_MAX;

  for(size_t it = 0; it < data->len ; it++)
    if(data->content[it] < min_tmp)
      min_tmp = data->content[it];

  return min_tmp;
}

int Max(digit_t* data)
{
  int max_tmp = INT_MIN;

  for(size_t it = 0; it < data->len; it++)
    if(data->content[it] > max_tmp)
      max_tmp = data->content[it];


  return max_tmp;
}

double Ave(digit_t* data)
{
  int sum = 0;

  for(size_t it = 0; it < data->len; it++)
    sum += data->content[it];

  return (double)(sum/data->len);
}

void Qsort(int* target, int left, int right)
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
  Qsort(target, left, it1-1);
  Qsort(target, it2+1, right);
}

double Med(digit_t* data)
{
  double result;
  size_t n = data->len;
  Qsort(data->content, 0, n);

  if(n%2)
    result = (data->content[(n/2)+1]);
  else
    result = (double)(data->content[n/2] + data->content[n/2-1])/2;

  return result;
}

double Std_Dev(digit_t* data)
{
  double sd;
  int half_result = 0;
  double ave = Ave(data);

  for(size_t it = 0; it < data->len; it++)
    half_result += pow(abs((ave-data->content[it])),2);

  sd = sqrt(half_result/(data->len-1));
  return sd;
}


digit_t* Histogram(digit_t* data)
{
  digit_t* result = malloc(sizeof(digit_t));
  result->content = malloc(sizeof(int)*data->len);

  for(size_t it = 0; it < data->len; it++)
    result->content[it] = 0;


  for(size_t it = 0; it < data->len; it++)
    result->content[data->content[it]] ++;

  result->len = data->len;

  return result;
}

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

void DisplayDigit(digit_t* data)
{
    for(int it = 0; it < data->len; it++)
      printf("%d\t#\t%d\n", it, data->content[it]);
}

void DisplayHoriChart(digit_t* data)
{
    for(size_t it = 0; it < data->len; it++)
    {
      printf("%zd [%d]\t|",it, data->content[it] );
      for(int it2 = 0; it2 < data->content[it]; it2++)
        putchar('#');
      putchar('\n');
    }
}

int main(void)
{
  digit_t* data = RandomDigit(1,10,10000);
  printf("dane:\n");
  DisplayDigit(data);
  printf("MIN:%d\n", Min(data));
  printf("MAX:%d\n", Max(data));
  printf("AVE:%f\n", Ave(data));
  printf("MED:%f\n", Med(data));
  printf("STD_DEV:%f\n", Std_Dev(data));

  return 0;
}
