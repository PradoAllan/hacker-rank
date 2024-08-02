int	get_highest_candle(int candles, int *arr)
{
	int	i;
	int	num;

	i = 0;
	num = arr[i];
	while (i < candles)
	{
		if (arr[i] > num)
			num = arr[i];
		i++;
	}
	return (num);
}

int	birthdayCakeCandles(int candles_count, int *candles)
{
	int	qtd;
	int	i;
	int	highest;

	i = 0;
	qtd = 0;
	highest = get_highest_candle(candles_count, candles);
	while (i < candles_count)
	{
		if (candles[i] == highest)
			qtd++;
		i++;
	}
	return (qtd);
}
