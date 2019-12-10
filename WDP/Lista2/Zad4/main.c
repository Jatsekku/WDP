#include <stdio.h>
#include <stdlib.h>
#include "math.h"


typedef struct __poly{
  int degree;
  double argument;
  double* factors;
  double result;
}poly_t;

void GetPolyData(poly_t* poly)
{
  printf("Prosze wprowadzic stopien wielomianu:\n");
  scanf("%d",&(poly->degree));
  poly->factors = malloc(sizeof(double)*poly->degree);
  printf("Prosze wprowadzic argument rzeczywisty dla której zostanie obliczona wartość wielomianu:\n");
  scanf("%lf",&(poly->argument));

  for(int it = (poly->degree); 0 <= it ; it--)
  {
    printf("Prosze wprowadzic wartosc wspolczynnika stojącego przy x o potedze [%d]\n", it);
    scanf("%lf",&(poly->factors[it]));
  }
  poly->result = 0;

}

void DisplayPolyData(poly_t* poly)
{
  printf("Stopien wielomianu: %d\n", poly->degree);
  printf("Argument wielomianu %lf\n",poly->argument);

  for(int it = (poly->degree); 0 <= it; it--)
  {
    printf("Wspolczynnik wielomianu dla x do potegi [%d] : %lf\n", it, poly->factors[it] );
  }

  printf("Wynik wielomianu dla zadanych danych:%lf\n", poly->result);
}

double CalcPoly(poly_t* poly)
{
  double result_tmp = 0;
  for(int it = (poly->degree); 0 <= it; it--)
  {
    result_tmp += pow(poly->argument,it) * poly->factors[it];
  }
  poly->result = result_tmp;
}

int main(void)
{
  poly_t poly;

  GetPolyData(&poly);
  CalcPoly(&poly);
  DisplayPolyData(&poly);

}
