#include <stdio.h>

int main(void)
{
	const double C = 299792458;		//Prędkość światła w próżni [m/s]
        const double e = 1.602176634e-19;	//Ładunek elementarny [C]
        const double  F = 96485.339924;		//Stała Faradaya [C/mol]
        const double k = 1.380649e-23;		//Stała Boltzmana [J/K] 

        printf("Tabela stalych fizycznych\n\
                Nazwa\t Wartosc\t Jednostka\t Opis\n\
                C\t %e\t [m/s]\t\t Predkosc swiatla w prozni\n\
                e\t %e\t [C]\t\t Ladunek elementarny\n\
                F\t %e\t [F]\t\t Stala Faradaya\n\
                k\t %e\t [J/K]\t\t Stala Boltzmana\n", C,e,F,k);

        return 0;
}

