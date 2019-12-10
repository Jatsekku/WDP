#include <stdio.h>
#include <math.h>

void PrimeFactors(unsigned int number)
{
    while ((number % 2) == 0)
    {
      printf("2 ");
      number = (number/2);
    }

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
