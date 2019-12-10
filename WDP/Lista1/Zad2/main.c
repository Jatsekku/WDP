#include <stdio.h>

int main(void)
{
	float fahrenheit_data_in;
	float  celsjusz_data_out;

	printf("Prosze podac temperature w stopniach Fahrenheita:\n>");
	scanf("%f", &fahrenheit_data_in);
	celsjusz_data_out = ((fahrenheit_data_in - 32) * (5.0/9.0));
	printf("Wartosc tej temepratury w stopniach Celsjusza to: %f\n", celsjusz_data_out);

	return 0;
}
