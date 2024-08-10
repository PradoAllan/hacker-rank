int divisibleSumPairs(int n, int k, int ar_count, int* ar)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (i < ar_count)
    {
        j = 0;
        while (j < ar_count)
        {
            if (i < j && ((ar[i] + ar[j]) % k == 0))
                count++;
            j++;
        }
        i++;
    }
    return (count);
}
