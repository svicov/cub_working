#ifndef CUB3D_H
#define CUB3D_H

#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef PI
#	define PI 3.14159265
# endif

# ifndef alfa
#	define alfa 30 
# endif

# define KEY_ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_LEFT	123
# define KEY_RIGTH	124

typedef struct s_texture
{
	int		x;
	int		y;
	void	*img;
	char	*file;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture;


typedef struct s_conf
{
	int width;
	int heigth;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	int f;
	int c;
	int r;
	int n;
	

} t_conf;

typedef struct s_text
{
	void *pno;
	void *pso;
	void *pwe;
	void *pea;
	unsigned int *no;
	unsigned int *so;
	unsigned int *we;
	unsigned int *ea;
	int xres;
	int yres;
	int bit;
	int len;
	int end;
}	t_text;

 typedef struct s_sp
 {
	int		*n_sp;
	double	*r_sp;
	int		*nr_sp;
	double	**map_sp;
 } t_sp;

typedef struct s_mn
{
	t_conf conf;
	t_text text;

	double pl_x;
	double pl_y;
	double	pl_ugol;
	double	pl_ugol_;
	double	ro;
	char **map;
	int	num_s;
	int num_s0;
	int num_s1;
	int	maxlen;
	char **tmap;
	int zp[8];
	int cols;
	int rows;
	int max_cols;
	int max_rows;
	int	player; /* встретился игрок и сколько раз < 3 */
	int count_sp;
	t_sp	sp;
	void *mlxp;
	void *winp;

	void *imgp;
	int		*data;
	int bits_per_pixel;
	int linelen;
	int endian;

	int key_w;
	int key_a;
	int key_s;
	int key_d;
	int key_left;
	int key_right;

	int temp;
	char *line;
	float ray_x;
	float ray_y;
	char	side;
	double	pl_u;
	int	a;
	int	b;

	t_texture north;
	t_texture south;
	t_texture west;
	t_texture east;
	t_texture sprite;
	double walldistance;
} t_mn;

// Функций которые используется в гнл
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memmove(void *dst, const void *src, size_t n);
int					get_next_line(int fd, char **line);
int					pars1(char **line, t_mn *mn);
void				init_st_conf(t_conf *ddd);
void				init_zp(t_mn *pzp);
int					digit_of_a_number(int n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					completion0(char **line, int i, t_mn *mn);
int					completion(char **line, int i, int j, t_mn *mn);
int					completion1(char **line, int i, t_mn *mn);
int					completion1(char **line, int i, t_mn *mn);
int					completion2(char **line, int i, t_mn *mn);
int					completion3(char **line, int i, t_mn *mn);
int					completion4(char **line, int i, t_mn *mn);
int					completion5(char **line, int i, t_mn *mn);
int					completion6(char **line, int i, t_mn *mn);
int					completion7(char **line, int i, t_mn *mn);
int pars2(int fd, t_mn *mn);
int true_map(t_mn *mn);
void ft_maxlen(t_mn *mn, char **line);
void rtue_mat2(t_mn *mn);
int ft_error(int i);
int			valid_map(t_mn *mn);
int pl_s_above(t_mn *mn, int i, int j);
int		pl_s_below(t_mn *mn, int i, int j);
int		pl_s_right(t_mn *mn, int i, int j);
int pl_s_leftward(t_mn *mn, int i, int j);
int counting1(t_mn *mn);
int mall_sp(t_mn *mn);
int	position_sp(t_mn *mn);
int fff(t_mn *mn);
int key_pressed(int key, t_mn *mn);
int key_released(int key, t_mn *mn);
void exit_game(t_mn *mn);

int cub_draw(t_mn *mn, int color, int count, int i);
void cub_square1(t_mn *mn, int color, int x1, int y1, int x2, int y2);
void	risuet_stolbec(t_mn *mn, int color, int ddx, int ddh, t_texture tex);
//float	valid_ugol(float ug);
float ray_1(t_mn *mn);
int  scan1(t_mn *mn);
char	determining_orientation(t_mn *mn);
char	determining_orientation1(float x, float y);


double ro_sp(double pl_x, double pl_y, t_mn *mn);
int no_min (t_mn *mn, double xxx, double yyy);
int	pl_w(t_mn *mn);
int	pl_a(t_mn *mn);
int	pl_s(t_mn *mn);
int	pl_d(t_mn *mn);



#endif