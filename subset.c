#include <stdio.h>
#include <stdbool.h>
#define MAX 50

int set[MAX];
bool chosen[MAX];
int target, n;

void printsubset(int n)
{
    int i = 0;
    printf("{ ");
    for (i = 0; i < n; i++)
    {
        if (chosen[i])
        {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

void subset(int index, int sum)
{
    if (index == n)
    {
        if (sum == target)
        {
            printsubset(n);
        }
        return;
    }
    // include
    chosen[index] = true;
    subset(index + 1, sum + set[index]);
    // exclude
    chosen[index] = false;
    subset(index + 1, sum);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter target sum: ");
    scanf("%d", &target);
    int i = 0;
    printf("\nEnter elements of set: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("\nPossible subsets are: \n");
    subset(0, 0);
}