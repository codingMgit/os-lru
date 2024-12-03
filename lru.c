#include <stdio.h>

int pagelength, pages[1000], frames[100], framelength;

void input();
void displayFrame();
int isPageinFrame(int page);
int LRU(int index);

int main()
{
    int i, pagefaults = 0, framecounter = 0, index;

    input();

    for (i = 0; i < framelength; i++)
        frames[i] = -1;

    for (i = 0; i < pagelength; i++)
    {
        if (isPageinFrame(pages[i]))
            continue;

        pagefaults++;

        if (framecounter != framelength)
            frames[framecounter++] = pages[i];
        else
        {
            printf("Page fault at index = %d\n", i);
            index = LRU(i);
            frames[index] = pages[i];
        }
        displayFrame();
    }
    printf("PAGE FAULTS = %d\n", pagefaults);
    return 0;
}

void input()
{
    int i;
    printf("Enter the number of pages (<1000):\n");
    scanf("%d", &pagelength);
    printf("Enter %d pages:\n", pagelength);
    for (i = 0; i < pagelength; i++)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames (<100):\n");
    scanf("%d", &framelength);
}
void displayFrame()
{
    int k;
    for (k = 0; k < framelength; k++)
    {
        if (frames[k] == -1)
            printf("*\t");
        else
            printf("%d\t", frames[k]);
    }
    printf("\n\n");
}

int isPageinFrame(int page)
{
    int i;
    for (i = 0; i < framelength; i++)
    {
        if (page == frames[i])
            return 1;
    }
    return 0;
}

int LRU(int index)
{
    int i, j, pageindex, frameindex = 0;
    pageindex = pagelength;
    for (i = 0; i < framelength; i++)
        for (j = index - 1; j >= 0; j--)
            if (pages[j] == frames[i])
            {
                if (j < pageindex)
                {
                    pageindex = j;
                    frameindex = i;
                }
                break;
            }
    return frameindex;
}
