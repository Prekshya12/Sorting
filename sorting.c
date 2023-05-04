#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void ShellSort(int arr[], int size)
{
    for (int interval = size / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void swap(int *a, int *b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;

    if (largest != i)
    {

        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void quicksort(int number[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n=6;
    int arr[]={15,10,24,26,2,18};
    
    int op_no;
    while (op_no != 8)
    {
        printf("\nSelect any of following operations:\n");
        printf("1-> Insertion Sort\n");
        printf("2-> Shell Sort\n");        
        printf("3-> Merge Sort\n");
        printf("4-> Heap Sort\n");
        printf("5-> Bubble Sort\n");        
        printf("6-> Quick Sort\n");
        printf("7-> Display\n");
        printf("8-> Exit from program\n");
        scanf("%d", &op_no);

        if (op_no == 1)
        {
            InsertionSort(arr,n);
        }
        else if (op_no == 2)
        {
            ShellSort(arr,n);
        }
        else if (op_no == 3)
        {
            mergeSort(arr,0,n-1);
        }
        else if (op_no == 4)
        {
            heapSort(arr, n);
        }
        else if (op_no == 5)
        {
            BubbleSort(arr,n);
        }
        else if (op_no == 6)
        {
            quicksort(arr,0,n-1);
        }
        else if (op_no == 7)
        {
            Display(arr, n);
        }
        else if (op_no == 8)
        {
            printf("Program executes here\n");
        }
        else
        {
            printf("Enter correct operation\n");
        }
    }

    return 0;
}
