#include "cub3d.h"

float	valid_ugol(float ug)
{
	if (ug >= 0)
	{
		while (ug >= 2 * PI)
			ug = ug - 2 * PI;
	}	
	else
	{
		ug = -ug;
		while (ug > 2 * PI)
			ug = ug - 2 * PI;
		ug = 2 * PI - ug;		
	}
	
	return (ug);

}

char	determining_orientation1(float x, float y)
{
	if ((x - trunc(x)) < (y - trunc(y)))
		return('w');
	else
		return('n');
}

char	determining_orientation2(float x, float y)
{
	if ((trunc(x) + 1 - x) < (y - trunc(y)))
		return('e');
	else
		return('n');
}

char	determining_orientation3(float x, float y)
{
	if ((trunc(x) + 1 - x) < (trunc(y) + 1 - y))
		return('e');
	else
		return('s');
}

char	determining_orientation4(float x, float y)
{
	if ((x - trunc(x)) < (trunc(y) + 1 - y))
		return('w');
	else
		return('s');
}

char	determining_orientation(t_mn *mn)
{
	
	mn->pl_u = valid_ugol(mn->pl_ugol_);
	if (mn->pl_u >= 0 && mn->pl_u < PI / 2)
		return(determining_orientation1(mn->ray_x, mn->ray_y));
	if (mn->pl_u >= PI / 2 && mn->pl_u < PI)
		return(determining_orientation2(mn->ray_x, mn->ray_y));
	if (mn->pl_u >= PI && mn->pl_u < PI * 1.5)
		return(determining_orientation3(mn->ray_x, mn->ray_y));
	if (mn->pl_u >= PI *1.5 && mn->pl_u < PI * 2)
		return(determining_orientation4(mn->ray_x, mn->ray_y));
	return ('n');
}

float ray_1(t_mn *mn)  /* куда попадает луч от игрока  */
{
	int i;
	int j;
	float	c;
	float	hyp;
	int flag = 1;
	
	hyp = hypot(mn->num_s1, mn->maxlen);
		c = 0;
	while (c < (hyp + 3) )
	{
		mn->ray_x = mn->pl_x + c*cos(mn->pl_ugol_);
		mn->ray_y = mn->pl_y + c*sin(mn->pl_ugol_);
		j = trunc(mn->ray_y);
		i = trunc(mn->ray_x);		
		//printf("||%c|  %f  ||   %f=%d     %f=%d\n", mn->map[j][i], c, mn->pl_x + c*cos(mn->pl_ugol),i, mn->pl_y + c*sin(mn->pl_ugol), j);
		//printf("%c    %d      %d\n", mn->map[j][i], j, i);
		if (mn->map[j][i] == '1')
		{
			mn->side = determining_orientation(mn);
			if (mn->side == 'n' || mn->side == 's')
			{
				mn->walldistance = fabs(mn->ray_x - trunc(mn->ray_x));
			}
			else if (mn->side == 'e' || mn->side == 'w')
			{
				mn->walldistance = fabs(mn->ray_y - trunc(mn->ray_y));
			}
			break;
		}
			
		c = c + 0.005;		
	}
	mn->ro = c;
	//printf("ray===%f %d  %d\n", c, i, j);
	//getchar();
	return (c);  /*  */
}

int  scan1(t_mn *mn)
{
	int	i;
	int		h;
	double	c;
	int		color;
	

	mn->pl_ugol_ = mn->pl_ugol - PI/6;
	
	i = 1;
	while((mn->pl_ugol_ < mn->pl_ugol + PI/6) && (i < 799))
	{
		
		c = ray_1(mn);
		//side = determining_orientation(mn, c);
		h = round(800 / c);
		  
		if (mn->side =='w')
			risuet_stolbec(mn, color, i, h, mn->west);
		if (mn->side =='n')
			risuet_stolbec(mn, color, i, h, mn->north);
		if (mn->side =='e')
			risuet_stolbec(mn, color, i, h, mn->east);
		if (mn->side =='s')
			risuet_stolbec(mn, color, i, h, mn->south);
		
		mn->pl_ugol_ = mn->pl_ugol_ + (PI )/(3 * 800);
		
		i= i + 1;
	}
	return (0);
}