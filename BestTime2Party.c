#include <stdio.h>

#define CELEBRITIES 15
#define HOURS 24

int max(int size, int arr[]);

typedef struct 
{
    int arrival;
    int departure;
} TimeRange;


int main()
{
    TimeRange visitingHours[] = {
        {18, 19}, {19, 21}, {22, 24}, {20, 22}, {22, 23},
        {23, 24}, {20, 22}, {21, 23}, {19, 22}, {20, 23},
        {18, 21}, {19, 20}, {20, 21}, {22, 24}, {19, 23}
    };

    int celebrityCounts[HOURS] = {0};

    for (int i = 0; i < CELEBRITIES; i++)
    {
        for (int j = visitingHours[i].arrival; j < visitingHours[i].departure; j++)
        {
            celebrityCounts[j]++;
        }
    }

    int bestHour = max(HOURS, celebrityCounts);

    printf("Oi perisoteres diasimotites 8a vriskontai sto party stis %d.\n", bestHour);

    printf("Press ENTER to continue.");
    getchar();

    return 0;
}

int max(int size, int arr[]){
    int max = arr[0];
    int maxIndex = 0;

    for(int i = 1; i < HOURS; i++)
    {
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    
    return maxIndex;
}