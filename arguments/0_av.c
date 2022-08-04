#include <stdlib.h>
#include <stdio.h>

/**
 * main - print arguments without the use of ac
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
   int pos;

   pos = 0;

   while (av[pos] != NULL)
   {
		printf("%s\n", av[pos]);
		pos++;
   }
	return 0;
}
