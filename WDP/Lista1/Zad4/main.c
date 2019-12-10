#include <stdio.h>
#include <math.h>

float polynymial_calc(float *factor_arr, float x, int degofpoly )
{
	float result = 0; 
	for(int i = 0; i < degofpoly; i++)
	{
		result += powf(x,i) * factor_arr[i];
	}
	return result;

}

int main(void)
{
	float numbers[5];
	float x;	

	for(int i = 0 ; i < 5; i++)
	{
		printf("Proszę wprowadzić liczbę rzeczywistą będącą wspołczynnikiem poprzedzającym wyrażenie x^%d\n>", i);
		scanf("%f", &numbers[i] );
	}
	
	printf("Proszę dodatkowo wprowadzić liczbę rzeczywistą X dla której ma zostać obliczona wartość wielomianu\n>");
	scanf("%f", &x);

	printf("Wyniki: %f\n", polynymial_calc(numbers, x, 5));

	return 0;
}
