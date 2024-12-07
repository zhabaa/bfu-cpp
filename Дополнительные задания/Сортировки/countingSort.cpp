
void CountingSort(int *a, int *c, int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[a[i]] = c[a[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        while (c[j] != 0)
        {
            a[i] = j;
            c[j]--;
            i++;
        }
    }
}