#include <stdio.h>

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;

    printf("Enter the bucket size: ");
    scanf("%d", &cap);

    printf("Enter the processing rate: ");
    scanf("%d", &process);

    printf("Enter the number of seconds you want to simulate: ");
    scanf("%d", &nsec);

    for (i = 0; i < nsec; i++)
    {
        printf("Enter the size of the packet entering at %d sec: ", i + 1);
        scanf("%d", &inp[i]);
    }

    printf("\nSecond | Packet Received | Packet Sent | Packet Left | Dropped\n");
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < nsec; i++)
    {
        count += inp[i];
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }

        printf("%6d | %15d |", i + 1, inp[i]);

        mini = min(count, process);
        printf(" %11d |", mini);

        count = count - mini;
        printf(" %12d | %7d\n", count, drop);
        drop = 0;
    }

    // Process remaining packets after the last second
    for (; count != 0; i++)
    {
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }

        printf("%6d | %15d |", i + 1, 0);

        mini = min(count, process);
        printf(" %11d |", mini);

        count = count - mini;
        printf(" %12d | %7d\n", count, drop);
    }

    return 0;
}

