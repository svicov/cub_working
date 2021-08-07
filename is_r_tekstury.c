#include "cub3d.h"
#include "mlx.h"
#include "math.h" // УДАЛИТЬ ПЕРЕД ФИНАЛЬНОЙ СДАЧЕЙ ЕСЛИ НЕ НУЖЕН

void exit_game(t_mn *mn)
{
	// FREE
	mn->temp = 0;
	exit(0);
}

int no_min (t_mn *mn, double xxx, double yyy)
{
	int i;
	int j;

	j = trunc(yyy);
	i = trunc(xxx);
	if (mn->map[j][i] == '1')
	{
		//printf("no_m20   %c", mn->map[j][i]);
		return (0);
	}
		//printf("no_m23  %c\n", mn->map[j][i]);
	return (1);
}

int pl_dynamics_1(t_mn *mn, char c)
{
	if (c =='w')
	{
		pl_w(mn);
	}
	if (c =='s')
	{
		pl_s(mn);
	}
	if (c =='a')
	{
		pl_a(mn);
	}
	if (c =='d')
	{
		pl_d(mn);
	}
	return (2345);
}

int	pl_w(t_mn *mn)
{
	double	k;
	double	xxx;
	double	yyy;

	k = 0.1;
	xxx = mn->pl_x + 2 * k * cos(mn->pl_ugol);
	yyy = mn->pl_y + 2 * k * sin(mn->pl_ugol);
	if (no_min(mn, xxx, mn->pl_y))
		mn->pl_x = mn->pl_x + k * cos(mn->pl_ugol);
	if (no_min(mn, mn->pl_x, yyy))
		mn->pl_y = mn->pl_y + k * sin(mn->pl_ugol);
	return (345);
}

int	pl_s(t_mn *mn)
{
	double	k;
	double	xxx;
	double	yyy;

	k = 0.2;
	xxx = mn->pl_x - 2 * k * cos(mn->pl_ugol);
	yyy = mn->pl_y - 2 * k * sin(mn->pl_ugol);
	if (no_min(mn, xxx, mn->pl_y))
		mn->pl_x = mn->pl_x - k * cos(mn->pl_ugol);
	if (no_min(mn, mn->pl_x, yyy))
		mn->pl_y = mn->pl_y - k * sin(mn->pl_ugol);
	return (345);

	//if (no_min(mn, xxx, mn->pl_y) || no_min(mn, mn->pl_x, yyy) || no_min (mn, xxx, yyy))
	//{
	//	mn->pl_x = xxx;
	////if (no_min(mn, mn->pl_x, yyy))
	//	mn->pl_y = yyy;
	//}
	//	mn->pl_x = xxx;
	//if (no_min(mn, mn->pl_x, yyy))
	//	mn->pl_y = yyy;
	//return (345);
}

int	pl_a(t_mn *mn)
{
	double	k;
	double	xxx;
	double	yyy;

	k = 0.1;
	xxx = mn->pl_x + 2 * k * sin(mn->pl_ugol);
	yyy = mn->pl_y - 2 * k * cos(mn->pl_ugol);
	if (no_min(mn, xxx, mn->pl_y))
		mn->pl_x = mn->pl_x + k * sin(mn->pl_ugol);
	if (no_min(mn, mn->pl_x, yyy))
		mn->pl_y = mn->pl_y - k * cos(mn->pl_ugol);
	return (345);
	//if (no_min(mn, xxx, mn->pl_y))
	//	mn->pl_x = xxx;
	//else
	//	mn->pl_x = mn->pl_x;
	//if (no_min(mn, mn->pl_x, yyy))
	//	mn->pl_y = yyy;
	//else
	//	mn->pl_y = mn->pl_y;
	return (345);
}

int	pl_d(t_mn *mn)
{
	double	k;
	double	xxx;
	double	yyy;

	k = 0.1;
	xxx = mn->pl_x - 2 * k * sin(mn->pl_ugol);
	yyy = mn->pl_y + 2 * k * cos(mn->pl_ugol);
	if (no_min(mn, xxx, mn->pl_y))
		mn->pl_x = mn->pl_x - k * sin(mn->pl_ugol);
	if (no_min(mn, mn->pl_x, yyy))
		mn->pl_y = mn->pl_y + k * cos(mn->pl_ugol);
	return (345);
}

//   int pl_dynamics_2(t_mn *mn, char c)
//   {
//   	double	k;
//   	double	xxx;
//   	double	yyy;
//   
//   	pl_dynamics_1(mn, c);
//   	k = 0.3;
//   	xxx = mn->pl_x + mn->a * k * cos(mn->pl_ugol); printf("%d", no_min(mn, xxx, mn->pl_y));
//   	yyy = mn->pl_y + mn->b * k * sin(mn->pl_ugol);
//   	if (no_min(mn, xxx, mn->pl_y))
//   		mn->pl_x = xxx;
//   	if (no_min(mn, mn->pl_x, yyy))
//   		mn->pl_y = yyy;
//   	return (345);
//   }

int fff(t_mn *mn) 
{
	if (mn->key_d)
		mn->pl_x += 0.2;
	if (mn->key_a)
		mn->pl_x -= 0.2;
	if (mn->key_w)
		mn->pl_y -= 0.2;
	if (mn->key_s)
		mn->pl_y += 0.2;
	//put_frame(mn);
	printf("fff\n");
	return (0);
}

int key_pressed(int key, t_mn *mn)
{
	if (key == 53)
		exit_game(0);
	if (key == 13)
	{
		mn->key_w = 1;
	}
	if (key == KEY_A)
		pl_dynamics_1(mn, 'a');
		//mn->pl_x -= 0.1;
		// mn->key_a = 1;
	if (key == KEY_W)
		pl_dynamics_1(mn, 'w');
	if (key == KEY_S)
		pl_dynamics_1(mn, 's');
	if (key == KEY_D)
		pl_dynamics_1(mn, 'd');
		// mn->key_d = 1;
	if (key == KEY_LEFT)
		mn->pl_ugol = mn->pl_ugol - 0.03;
	if (key == KEY_RIGTH)
		mn->pl_ugol = mn->pl_ugol + 0.03;
//	fff(mn);
	return (0);
}

int		draw_image(t_mn *mn)
{
	mn->imgp = mlx_new_image(mn->mlxp, mn->conf.width, mn->conf.heigth);
	mn->data = (int *)mlx_get_data_addr(mn->imgp, &mn->bits_per_pixel, &mn->linelen,&mn->endian);

	scan1(mn);
	
	mlx_put_image_to_window(mn->mlxp, mn->winp, mn->imgp, 0, 0);
	mlx_destroy_image(mn->mlxp, mn->imgp);
	mlx_put_image_to_window(mn, mn->winp, mn->north.img,0,0);
	return (0);
}

int key_released(int key, t_mn *mn)
{
	if (key == 13)
		mn->key_w = 0;
	if (key == 0)
		mn->key_a = 0;
	if (key == 1)
		mn->key_s = 0;
	if (key == 2)
		mn->key_d = 0;
	if (key == 123)
		mn->key_left = 0;
	if (key == 124)
		mn->key_right = 0;
	return (0);
}



void cub_square1(t_mn *mn, int color, int x1, int y1, int x2, int y2)
{
	int i;
	int index;
	int y;
	int clr;

	clr = 0;
	y = y1;
	while (y < y2)
	{
		i = x1;
		while (i < x2)
		{
			color = mn->text.we[clr];
			//	color = 00556677;
			index = mn->conf.width * y + i;
			mn->data[index] = color;
			// mn->data[index] = mn->text.we[//индекс пикселя текстуры];
			i++;
			clr++;
		}
		y++;

	}

	//y = -1;
	//while (++y < h)
	//{
	//	x = 0;
	//	while (x < mn->conf.width)
	//	{
	//		mn->data[y * mn->conf.width + mn->conf.width * posy + x] = color;
	//		x++;
	//	}
	//}
}

void	my_mlx_pixel_put(t_mn *mn, int x, int y, long color)
{
	char	*dst;

	dst = (char *)mn->data + (y * mn->linelen
			+ x * (mn->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	 cub_square2(t_mn *mn, int color, int ddx, int ddh)
{
	int j;
	//int i;
	int index;
	(void)color;
	j = fmax(0, (mn->conf.heigth - ddh)/2);
	char *col;
	
	while (j < fmin((mn->conf.heigth + ddh)/2, mn->conf.heigth - 1))
	{
		col = (char *)mn->north.addr + (int)(j / (double)ddh * mn->north.y)
		*mn->north.line_length
		+ (int)(mn->walldistance * (mn->north.x))
		*(mn->north.bits_per_pixel / 8);
		if (*(unsigned int *)col == 4278190080)
			*(unsigned int *)col = 0;
		// if (index >= 0 && index < (mn->conf.width - 1) * (mn->conf.heigth - 1))
			index = mn->conf.width * j + ddx;
		my_mlx_pixel_put(mn, ddx, j, *(unsigned int *)col);
		//mn->data[index] = *(unsigned int *)col;
		j++;
	}
}

int cub_draw(t_mn *mn, int color, int count, int i)
{
	// int i = -1;
	while (++i < count)
		mn->data[i] = color;
	return(1);
}

int main(int argc, char **argv)
{
	
	t_mn mn;

	int q;

	char *line2;
	int fd;
	int res_gnl;


	if (argc > 3 || argc < 2)
		return (1);
	
	printf("ABI: %s\n", (*(argv + 1)));
	printf("P:  %s\n", (*(argv + 1) + ft_strlen(*(argv + 1)) - 4));
	if ((ft_strncmp((*(argv + 1) + ft_strlen(*(argv + 1)) - 4), ".cub", 4))) /*  проверка на расширение .cub  */
	{
		printf("incorrect file format \"%s\"\n", *(argv + 1));
		return (3);
	}

	fd = open(*(argv + 1), O_RDONLY);
	if (fd < 0)
		exit_game(&mn);

	init_st_conf(&mn.conf);
	
	q = 0;
	while(q < 8)  
	{
		res_gnl = get_next_line(fd, &line2);
		if (res_gnl < 0)
		{
			printf("Error incorrect format file");
			if (line2)
				free (line2);
			exit_game(&mn);
			return (2);
		}
		printf("ssssssssss   %s\n", line2);
		pars1(&line2, &mn);
		q++;
	}
		
	pars2(fd, &mn);
	
	true_map(&mn);
	
	rtue_mat2(&mn);
	counting1(&mn);
	mall_sp(&mn);
	position_sp(&mn); 
	
	mn.pl_ugol = 0.0; 
	mn.pl_x = 9.5;
	mn.pl_y = 2.5;
	
	mn.mlxp = mlx_init();
	mn.north.file =  "/Users/dbombur/Downloads/cub3d6_2_2_a 2/textures/redbrick.xpm";
	mn.north.img = 
	mlx_xpm_file_to_image(mn.mlxp,mn.north.file, &mn.north.x, &mn.north.y);
	mn.north.addr = mlx_get_data_addr(mn.north.img, &mn.north.bits_per_pixel, &mn.north.line_length, &mn.north.endian);
	mn.winp = mlx_new_window(mn.mlxp, mn.conf.width, mn.conf.heigth, "bombur");
	
	// mn.imgp = mlx_new_image(mn.mlxp, mn.conf.width, mn.conf.heigth);
	// mn.data = (int *)mlx_get_data_addr(mn.imgp, &mn.bits_per_pixel, &mn.linelen,&mn.endian);

	// scan1(&mn);
	

	// mlx_put_image_to_window(mn.mlxp, mn.winp, mn.imgp, 0, 0);

	mlx_hook(mn.winp, 2, 0, &key_pressed, &mn);
	mlx_hook(mn.winp, 3, 0, &key_released, &mn);
	
	mlx_loop_hook(mn.mlxp, &draw_image, &mn);

	mlx_loop(mn.mlxp);
	
	return (0);
	

}