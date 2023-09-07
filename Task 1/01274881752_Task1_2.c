#include <stdio.h>
#include <stdlib.h>

int main()
{
    //main answer + bonus
    int count;
    scanf("%d", &count);
    while (count > 0)
    {
        printf("%d\n", count);
        sleep(1);
        count--;
    }
    printf("Blast off to the moon!");
    return 0;
}
