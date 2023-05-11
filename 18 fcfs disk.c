#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, k, head, seek_time = 0, diff;
    float avg_seek_time;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int queue[n+1];
    printf("Enter the queue of requests: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &queue[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    queue[0] = head;
    printf("\n");

    // Calculate seek time
    for(j = 0; j < n; j++)
    {
        diff = abs(queue[j+1] - queue[j]);
        seek_time += diff;
        printf("Move from %d to %d with seek time %d\n", queue[j], queue[j+1], diff);
    }

    printf("\nTotal seek time = %d\n", seek_time);
    avg_seek_time = (float) seek_time / n;
    printf("Average seek time = %.2f\n", avg_seek_time);
    return 0;
}
