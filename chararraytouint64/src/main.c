#include <stdio.h>

#define __STDC_FORMAT_MACROS
#include <inttypes.h>

int main(void)
{
	int i;
	unsigned char input[8] = {11, 4 ,11, 11, 4, 28, 0, 0 };
	uint64_t paquet = 0;
//	for( i = 6; i >= 0; --i )
//	{
//		paquet <<= 8;
//	    paquet |= (uint64_t)input[i];
//	    printf("%d: %u: %" PRIu64 "\n", i, input[i], paquet);
//	}


	for( i = 0; i < 8; i++ )
		{
			paquet <<= 8;
		    paquet |= (uint64_t)input[i];
		    printf("%d: %u: %" PRIu64 "\n", i, input[i], paquet);
		}
	printf("%" PRIu64 "\n", paquet);

	return 0;
}
