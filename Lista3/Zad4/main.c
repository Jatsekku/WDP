#include<stdio.h>
#include<stdlib.h>




int main(int argc, char *argv[])
{
  char lut[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //25
  FILE* file_in = fopen(argv[1], "r");
  FILE* file_out = fopen(argv[2], "w");
  int offset = atoi(argv[3]);

  if(file_in == NULL)
  {
    printf("Input file error!\n");
    return -1;
  }

  if(file_out == NULL)
  {
    printf("Output file error!\n");
    return -1;
  }

  offset = offset%25;

  if(offset < 0)
   offset = 26 + offset;


  printf("Key: %d\n", offset);
  char c;
  char d;

  while( (c = fgetc(file_in)) != EOF)
  {

    if((c >= 'a' && c <= 'z'))
    {
      c = c-'a';
      d = (lut[(c + offset)%26]);
      putc(d, file_out);
    }
    else if((c >= 'A' && c <= 'Z'))
    {
      c = c-'A';
      d = (lut[(c + offset)%26] - 'a' + 'A');
      putc(d, file_out);
    }
    else
    {
      putc(c, file_out);
    }
}


  fclose(file_in);
  fclose(file_out);
  printf("Finished!\n");

}
