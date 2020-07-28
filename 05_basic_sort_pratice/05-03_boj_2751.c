#include <stdio.h>

int array[1000001];

void quickSort(int* data, int pos_start, int pos_end)
{
    int mLeft = pos_start, mRight = pos_end;
    int pivot = data[(pos_start + pos_end) / 2];
    int temp;

    while (mLeft <= mRight) {
        while (pivot > data[mLeft])
            mLeft++;
        while (pivot < data[mRight])
            mRight--;

        if (mLeft <= mRight) {
            temp = data[mLeft];
            data[mLeft] = data[mRight];
            data[mRight] = temp;
            mLeft++, mRight--;
        }
    }

    if (pos_start < mRight)
        quickSort(data, pos_start, mRight);
    if (mLeft < pos_end)
        quickSort(data, mLeft, pos_end);
}

int main(void)
{
    int number, i;

    scanf("%d", &number);

    for (i = 0; i < number; ++i) {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, number - 1);

    for (i = 0; i < number; ++i)
        printf("%d\n", array[i]);

    return 0;
}