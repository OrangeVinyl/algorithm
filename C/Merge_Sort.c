#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8

int sorted[MAX_SIZE]; // 추가 공간이 필요
int list[MAX_SIZE];
int n;

// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    // 분할 정렬된 list의 합병
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    // 남아 있는 레코드의 일괄 복사
    if (i > mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else // 남아 있는 레코드의 일괄 복사
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    // 배열 sorted[]의 리스트를 배열 list[]로 복사
    for (l = left; l <= right; l++)
        list[l] = sorted[l];

    printf("\n");

    for (int m = 0; m < right + 1; m++)
        printf("%d  ", list[m]);
    printf("\n");
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    int k;

    printf("(list[], %d, %d) 호출\n", left, right);
    for (k = left; k < right + 1; k++)
        printf("[%d] %d  ", k, list[k]);
    printf("\n");

    if (left < right)
    {
        mid = (left + right) / 2;         // 리스트의 균등분할
        merge_sort(list, left, mid);      // 부분리스트 정렬
        merge_sort(list, mid + 1, right); //부분리스트 정렬
        merge(list, left, mid, right);    // 합병
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0; i < n; i++)     // 난수 생성 및 출력
        list[i] = rand() % 100; // 난수 발생 범위 0~99

    // int n = MAX_SIZE;
    // int list[n] = {21, 10, 12, 20, 25, 13, 15, 22};

    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    merge_sort(list, 0, n - 1);
}
