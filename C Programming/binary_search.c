int binary_search(int key, int a[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
void main()
{
    int i, key, a[20], n, item, pos;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements in increasing order\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the item to be searched\n");
    scanf("%d", &item);
    pos = binary_search(item, a, n);
    if (pos == -1)
    {
        printf("Item not found\n");
    }
    else
    {
        printf("Item found at position : %d\n", pos);
    }
}
