#include "cub3d.h"

int counting1(t_mn *mn)
{
	int		i;
	int		j;
	
	mn->count_sp = 0;
	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		i = 0;
		while (i < mn->maxlen)
		{
			if (mn->map[j][i] == '2')
			{
				mn->count_sp++;
			}
			
			i++;
		}
		j++;
	}
	return (0);
}

int mall_sp(t_mn *mn)
{
	int	i;

	mn->sp.map_sp = (double **)malloc((mn->count_sp + 1) * sizeof(double *));
	if(mn->sp.map_sp == NULL)
		return (-1);
	i = 0;
	while (i < mn->count_sp)
	{
		mn->sp.map_sp[i] = (double *)malloc(2 * sizeof(double));
		if (mn->sp.map_sp[i] == NULL)
			return (-1);		
		i++;
	}
	mn->sp.n_sp = (int *)malloc((mn->count_sp + 1) * sizeof(int));
	mn->sp.nr_sp = (int *)malloc((mn->count_sp + 1) * sizeof(int));
	mn->sp.r_sp = (double *)malloc((mn->count_sp + 1) * sizeof(double));
	if (mn->sp.n_sp == NULL || mn->sp.nr_sp == NULL || mn->sp.r_sp == NULL)
		return (-1);
	return (0);
}

int	position_sp(t_mn *mn)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j < (mn->num_s - mn->num_s0))
	{
		i = 0;
		while (i < mn->maxlen)
		{
			if (mn->map[j][i] == '2' && k < mn->count_sp)
			{
				mn->sp.map_sp[k][0] = i + 0.5;
				mn->sp.map_sp[k][1] = j + 0.5;
				(mn->sp.n_sp[k]) = k;
				k++;
			}			
			i++;
		}
		j++;
	}

	k = 0;
	while (k < mn->count_sp)
	{
		printf("uuuuu spr  %d    %f  %f\n", k, mn->sp.map_sp[k][0], mn->sp.map_sp[k][1]);
		k++;
	}	
	return (0);
}

double ro_sp(double pl_x, double pl_y, t_mn *mn)
{
	int i;

	i = 0;
	while (i < mn->count_sp)
	{
		mn->sp.r_sp[i] = hypot((mn->sp.map_sp[i][0] - pl_x), (mn->sp.map_sp[i][1] - pl_y));
		
		printf("hypot %d  =%f\n",i , mn->sp.r_sp[i]);
		i++;
	}
	return (0);
}

