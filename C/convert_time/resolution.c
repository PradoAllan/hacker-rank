static int    is_negative(long n)
{
    if (n < 0)
        return (1);
    return (0);
}

static int    int_len(long n)
{
    long    len;

    len = 1;
    if (n < 0)
    {
        n *= -1;
        len = 2;
    }
    while (n > 9)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char    *result;
    int        neg;
    int        qtd;
    long    newn;

    newn = n;
    neg = is_negative(newn);
    qtd = int_len(newn);
    result = (char *)malloc(sizeof(char) * (qtd + 1));
    if (result == NULL)
        return (NULL);
    result[qtd] = '\0';
    if (neg == 1)
    {
        *result = '-';
        result[--qtd] = -(newn % 10) + '0';
        newn = -(newn / 10);
    }
    while (qtd-- - neg)
    {
        result[qtd] = newn % 10 + '0';
        newn = newn / 10;
    }
    return (result);
}

char *getNumbersToConvert(char *s)
{
    char *numbers;
    
    numbers = malloc(sizeof(char) * (2 + 1));
    if (!numbers)
        return (NULL);
    numbers[2] = '\0';
    numbers[0] = s[0];
    numbers[1] = s[1];
    return (numbers);
}

char *amTimeConversion(char *s)
{   
    char *times;
    char *n;
    int numbers;
    int i;
    
    times = malloc(sizeof(char) * (8 + 1));
    if (!times)
        return (NULL);
    times[8] = '\0';
    i = 2;
    while (i < 8)
    {
        times[i] = s[i];
        i++;
    }
    n = getNumbersToConvert(s);
    numbers = atoi(n);
    free(n);
    if (numbers == 12)
    {
        times[0] = '0';
        times[1] = '0';
        return (times);
    }
    n = ft_itoa(numbers);
    if (numbers < 10)
    {
        times[0] = '0';
        times[1] = n[0];
        return (times);
    }
    i = 0;
    while (i < 2)
    {
        times[i] = n[i];
        i++;
    }
    return (times);  
}

char *pmTimeConversion(char *s)
{
    char *times;
    char *n;
    int numbers;
    int i;
    
    times = malloc(sizeof(char) * (8 + 1));
    if (!times)
        return (NULL);
    times[8] = '\0';
    i = 2;
    while (i < 8)
    {
        times[i] = s[i];
        i++;
    }
    n = getNumbersToConvert(s);
    numbers = atoi(n) + 12;
    free(n);
    if (numbers == 24)
    {
        times[0] = '1';
        times[1] = '2';
        return (times);
    }
    n = ft_itoa(numbers);
    i = 0;
    while (n[i])
    {
        times[i] = n[i];
        i++;
    }
    return (times);   
}

char* timeConversion(char* s) 
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] == 'P' || s[i] == 'p')
            return (pmTimeConversion(s));
        else if (s[i] == 'A' || s[i] == 'a')
            return (amTimeConversion(s));
        i++;
    }
    return (NULL);
}
