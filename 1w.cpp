#include <stdio.h>
int main()
{
    unsigned short n = 12345;
    unsigned short r = 0;
    while (n) {
        r = (r * 10) + (n % 10);
        n = n / 10;
    }
    printf("%d", r);
    return 0;
}
