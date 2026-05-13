#include <stdio.h>

int main()
{
    int p, f;
    int index = 0, faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int pages[p], frames[f], last_used[f], freq[f];

    printf("Enter reference string: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &pages[i]);

    // Initialize frames
    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        last_used[i] = 0;
        freq[i] = 0;
    }

    for (int i = 0; i < p; i++)
    {
        found = 0;

        // Check if page already exists
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;

                // Update data for algorithms
                freq[j]++;
                last_used[j] = i + 1;

                break;
            }
        }

        if (!found)
        {
            // Check for empty frame first
            int empty = -1;
            for (int j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if (empty != -1)
            {
                frames[empty] = pages[i];
                freq[empty] = 1;
                last_used[empty] = i + 1;
                faults++;
            }
            else
            {
                // ---------------- FIFO ----------------
                /*
                frames[index] = pages[i];
                index = (index + 1) % f;
                faults++;
                */

                // ---------------- LRU ----------------
                /*
                int min_index = 0;
                for (int k = 1; k < f; k++)
                {
                    if (last_used[k] < last_used[min_index])
                        min_index = k;
                }

                frames[min_index] = pages[i];
                last_used[min_index] = i + 1;
                freq[min_index] = 1;
                faults++;
                */

                // ---------------- LFU ----------------
                int min_index = 0;
                for (int k = 1; k < f; k++)
                {
                    if (freq[k] < freq[min_index])
                        min_index = k;
                }

                frames[min_index] = pages[i];
                freq[min_index] = 1;
                last_used[min_index] = i + 1;
                faults++;
            }
        }
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
