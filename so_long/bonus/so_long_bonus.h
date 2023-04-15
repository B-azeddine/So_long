/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:00:17 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 22:45:33 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*m;
	void	*w;
	void	*img;
	void	*fv;
	void	*bg;
	void	*wall;
	void	*s;
	void	*c;
	void	*o;
	char	**map;
	int		x;
	int		y;
	int		count;
	int		x_pl;
	int		y_pl;
	int		x_map;
	int		y_map;
	int		direction;
	int		move;
}			t_vars;

typedef struct s_arg
{
	int		i;
	int		j;
	int		exit;
	int		player;
	int		count;
}			t_arg;

typedef struct s_arg1
{
	int		i;
	int		j;
	int		fline_x;
	int		s_fline_x;
	int		fline_y;
	int		s_fline_y;
}			t_arg1;

typedef struct s_arg2
{
	int		changed;
	int		i;
	int		j;
}			t_arg2;

typedef struct s_readf
{
	int		fd;
	char	*line;
	char	**bointer;
	char	*f;
}			t_readf;

char		**read_file_1(char *map_name);
char		**ft_split(char *s, char c);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			check_uniq_items(char **map, int x_map, int y_map);
int			check_map(t_vars *tv);
int			close_win(void);
int			key_hook(int keycode, t_vars *tv);
int			ff(t_vars *tv);
int			check_valid_map(char **map);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		**read_file_1(char *map_name);
char		*ft_itoa(int n);
void		free_map(char **map);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int a);
void		print_element(t_vars *t, int i, int j, int nm);
void		check_extention(char *map_name);
void		bg_screen(t_vars *tv);
void		chek_mouvement_far(char **map, t_arg2 *arg2);
void		put_items(t_arg1 *a, t_vars *t);
void		wall_lines(t_arg1 *a, t_vars *t);
void		check_line_length(t_arg1 *a, t_vars *t);
void		wall_screen(t_arg1 *a, t_vars *t);
void		send_t_rf(t_readf *rf);
void		print_caracters(t_vars *t, int i, int j, int bn);
void		send_to_check_valid(char **map);
void		send_put_items(t_arg1 *a, t_vars *t);
int			allocation(t_vars *t);
void		send_to_allocation(t_vars *t);
void		send_to_allocation2(t_vars *t);
void		send_to_allocation3(t_vars *t);
void		destroy_bg(t_vars *t);
void		destroy_img(t_vars *t);
void		destroy_wall(t_vars *t);
void		destroy_sheese(t_vars *t);
void		destroy_closed(t_vars *t);
void		destroy_opened(t_vars *t);

#endif