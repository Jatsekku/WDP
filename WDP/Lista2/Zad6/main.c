#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint8_t ArrGetBit(uint8_t* arr, uint64_t n)
{
  return (arr[n/8] & (1<<(n%8)));
}

void ArrSetBit(uint8_t* arr, uint64_t n, uint8_t state)
{
  uint8_t byte_tmp = arr[n/8];

  if(state)
    byte_tmp |= (1<<(n%8));
  else
    byte_tmp &= ~(1<<(n%8));

  arr[n/8] = byte_tmp;
}

uint8_t* AllocTab(uint64_t n)
{
    n = (n/8) + ((n%8)? 1:0);
    uint8_t *buff;

    if( (buff = malloc(sizeof(uint8_t) * n)) == NULL)
      perror("Nie udało się zaalokować pamieci dla tablicy obliczeniowej");

    for(uint64_t it = 0; it <n; it++)
      buff[it] = 0xFF;

    return buff;
}

void ArrDisplay(uint8_t* arr, uint64_t len)
{
  for(uint64_t it = 0; it < len; it++)
  {
    if(ArrGetBit(arr,it))
      putchar('1');
    else
    putchar('0');
  }
  putchar('\n');
}

uint8_t* Erastotenes(uint64_t n)
{
  uint8_t* buff = AllocTab(n+1);
  uint64_t limit = floor(sqrt(n));
  uint64_t tmp;


  for(uint64_t it = 2; it <=limit ; it++)
  {
    if(ArrGetBit(buff, it))
    {
      tmp = it+it;
      while(tmp<=n)
      {
        ArrSetBit(buff,tmp,0);
        tmp +=it;
      }
    }
  }


  //ArrDisplay(buff,n);

  for(uint64_t it = 2, tmp = 0; it < n; it++)
  {
    if(ArrGetBit(buff, it))
    {
      printf("\t%lu\t", it);
      tmp++;
    }

    if(tmp > 3)
    {
      putchar('\n');
      tmp = 0;
    }
  }
  putchar('\n');

  return buff;
}



int main(void)
{
  uint64_t num;

  printf("Prosze podac liczbe, dla ktorej zostana wyswietlone wszystkie liczby pierwsze ");
  scanf("%lu", &num);
  free(Erastotenes(num));


}
