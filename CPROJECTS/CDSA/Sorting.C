void selectionSort1(int arr[], int size)
{
    for (int i = 0; i < size - 2; i++)
    {
        int t = arr[i];
        int loc = 0;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[j];
                loc = j;
            }
        }
        if (t != arr[i])
        {
            arr[loc] = t;
        }
    }
}

void selectionSort2(int arr[], int size)
{
    for (int i = 0; i < size - 2; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

