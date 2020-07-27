#include <stdio.h>

static const int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int pos_start, int pos_end)
{
    if (pos_start >= pos_end) { // ���� �ϰ��� �ϴ� ������ ���Ұ� 1���� ���
        return;
    }

    int key = pos_start; // Ű�� ù��° ����
    int i = pos_start + 1;
    int j = pos_end;
    int temp;

    while (i <= j) { // ������ ������ �ݺ�
        while (data[i] <= data[key]) { // Ű ������ ū ���� ���� ������ ���������� �̵�
            i++;
        }
        while (data[j] >= data[key] && j > pos_start) { // Ű ������ ���� ���� ���� ������ �������� �̵�
            j--;
        }
        if (i > j) { // ���� ������ ���¸� Ű ���� ��ü
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

        quickSort(data, pos_start, j - 1);
        quickSort(data, j + 1, pos_end);
    }
}

int main(void)
{
    quickSort(data, 0, number - 1);

    for (int i = 0; i < number; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}