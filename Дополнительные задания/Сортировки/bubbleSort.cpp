void bubble(int *mas, int n)
{
    int tmp = 0, i, j;
    int r = 0;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > r; j++)
        {
            if (mas[j] < mas[j - 1])
            {
                tmp = mas[j];
                mas[j] = mas[j - 1];
                mas[j - 1] = tmp;
            }
        }
        r++;
    }
}