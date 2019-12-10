#include <stdio.h>
#include <math.h>

typedef struct __factors{
  unsigned int value;
  unsigned int fold;
}factor_t



factor_t** PrimeFactors(unsigned int number)
{
    uint8_t div2_flag = 0;

    while ((number % 2) == 0)
    {
      printf(" 2 ");
      div2_flag = 1
      number = (number/2);
    }

    if(div2_flag)
      factor_t** factor_arr = malloc(sizeof(struct_t));

    for (int it = 3; it <= sqrt(number); it += 2)
    {
        while ((number % it) == 0)
        {
          printf("%u ", it);

          number = (number/it);
        }
    }

    if (number > 2)
      printf("%u ", number);
    putchar('\n');
}

int main(void)
{
  unsigned int number;
  printf("Prosze podac liczbe naturalna dla ktorej zostanie przeprowadzony rozklad na czynniki pierwsze:\n");
  scanf("%u", &number);

  PrimeFactors(number);

  return 0;
}
