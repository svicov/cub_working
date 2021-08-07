#include "cub3d.h"

unsigned int	get_pixel(s_mn *mn, double i)
{
	int	index;

	if (floor(mn->ray_y) == mn->ray_y)
	{
		index = 64 * floor(64 * i) + 64 * (mn->ray_x - floor(mn->ray_x));
		if (s->ray.w == 1)
			return (s->tex.so[index]);
		else if (s->ray.w == 0)
			return (s->tex.no[index]);
	}
	else if (floor(s->hit.x) == s->hit.x)
	{
		index = 64 * floor(64 * i) + 64 * (s->hit.y - floor(s->hit.y));
		if (s->ray.v == 1)
			return (s->tex.ea[index]);
		else if (s->ray.v == 0)
			return (s->tex.we[index]);
	}
	return (0x00000000);
}

void	drawlinevert(s_mn *s, int posx, int h, int c)
{
	int	y;
	int	line;
	int	index;
	int	hl;
	int	shift;

	c = 4;
	y = 0;
	hl = h;
	shift = 0;
	if (h > s->win.y)
	{
		hl = s->win.y;
		shift += (h - hl) / 2;
	}
	line = s->mlx.len / (s->mlx.bit / 8);
	while (y < hl)
	{
		index = line * y + line * ((s->win.y - hl) / 2) + posx;
		s->mlx.data[index] = get_pixel(s, (double)(y + shift) / h);
		y++;
	}
}