#include <stdio.h>
#include <float.h>

int main(void)
{
  printf("Najmniejsza liczba dodatnia dla arytmetyki zminennoprzecinkowej:\n\
           1) Pojedynczej precyzcji [float]:\n\
            1.1) Znormalizowana: %e\n\
            1.2) Zdenormalizowana: %e\n\
          2) Podwojnej precyzji [duoble]:\n\
            2.1) Znormalizowana:%e\n\
            2.2) Zdenormalizowana:%e\n",FLT_MIN,FLT_TRUE_MIN,DBL_MIN,DBL_TRUE_MIN);
}
