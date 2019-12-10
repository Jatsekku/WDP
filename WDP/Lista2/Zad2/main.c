#include <stdio.h>
#include <math.h>

int main(void)
{
  double solution[201][2];
  double x = 0.99;

  for(int it = 0; it < 201; it++, x+=0.0001)
  {
    solution[it][1] = pow((x-1),7);
    solution[it][2] = (pow(x,7) - (7*pow(x,6)) + (21*pow(x,5)) - (35*pow(x,4)) + (35*pow(x,3) - (21*pow(x,2)) +(7*x) - 1));
  }

  printf("Wyniki:\n------\n");

  for(int it = 0; it < 101; it++)
  {
      printf("%d # A:%e\tB:%e\t\t%d # A:%e\tB:%e\n",
             it, solution[it][1], solution[it][2],
             (it+101), solution[it+101][1], solution[it+101][2]);
  }
}
