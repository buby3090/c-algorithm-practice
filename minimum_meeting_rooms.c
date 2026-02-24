#include <stdlib.h>
#include <string.h>

// comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getMinRooms(int meetingTimings_rows, int meetingTimings_columns, int** meetingTimings) {
    
    int n = meetingTimings_rows;
    
    if (n == 0)
        return 0;

    int* start = (int*)malloc(n * sizeof(int));
    int* end = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        start[i] = meetingTimings[i][0];
        end[i] = meetingTimings[i][1];
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    free(start);
    free(end);

    return maxRooms;
}
