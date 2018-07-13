#include <stdio.h>
#include<stdlib.h>

    void convertToCharArray(unsigned char *arr, long long a)
    {
        int i = 0;

        for (i = 0; i < 8; ++i)
        {
            arr[i] = (unsigned char)((((unsigned long long) a) >> (56 - (8*i))) & 0xFF);
            printf("arr[%d]=%d\n",i,arr[i]);
        }
    }

    int main()
    {
        long long a = 793771576265539584;
        long long b = 0;
        unsigned char arr[16];
        int i =0;

        convertToCharArray(&arr[0], a);
        convertToCharArray(&arr[8], b);

        printf("a   => %llx\n", a);
        printf("b   => %llx\n", b);

        printf("arr => ");
        for(i = 0; i < 16; ++i)
        {
            printf("%x", arr[i]);
        }
    }
