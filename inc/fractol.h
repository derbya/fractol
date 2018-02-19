/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:42:38 by aderby            #+#    #+#             */
/*   Updated: 2017/08/16 13:38:37 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../miniLibx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_H 600
# define WIN_L 600
# define RED 11
# define GREEN 255
# define BLUE 160
# define NORMSUCKS boring_fractal_loop(nr, ni, f)
# define X_COMPLEX(x) 1.5 * (x - WIN_H / 2) / (0.5 * f->zoom * WIN_H)
# define Y_COMPLEX(y) 1.5 * (y - WIN_L / 2) / (0.5 * f->zoom * WIN_L)

typedef struct		s_image
{
	void			*img;
	int				bpp;
	int				line;
	int				e;
	char			*data;
}					t_image;

typedef struct		s_frac
{
	int				type;
	void			*win;
	void			*mlx;
	double			zoom;
	double			c_re;
	double			c_im;
	double			movex;
	double			movey;
	int				b;
	int				*color;
	int				iter;
	struct s_image	*img;
	struct s_frac	*next;
}					t_frac;

typedef struct		s_wincon
{
	void			*mlx;
	t_frac			*fractal;
}					t_wincon;

int					expose_hook(t_frac *f);
int					*fill_color_arr(double r, double g, double b, int i);
int					fractal_loop(double nr, double ni, t_frac *f);
int					l_fractal_loop(double nr, double ni, t_frac *f);
int					w_fractal_loop(double nr, double ni, t_frac *f);
int					z_fractal_loop(double nr, double ni, t_frac *f);
int					boring_fractal_loop(double nr, double ni, t_frac *f);
int					b_fractal_loop(double nr, double ni, t_frac *f);
int					m_fractal_loop(double nr, double ni, t_frac *f);
int					r_fractal_loop(double nr, double ni, t_frac *f);
double				get_movex(int x);
double				get_movey(int y);
void				ship(t_frac *f, int x, int y);
void				right(t_frac *f, int x, int y);
void				mountain(t_frac *f, int x, int y);
void				draw_stuff(t_frac *f, int x, int y);
void				initialize_wincon(t_wincon *w, int ac, char **av);
t_image				*create_image(t_wincon w);
void				custom(t_frac *f);
void				initialize_images(t_wincon *w);
void				img_clear(t_image *img);
void				julia(t_frac *f, int x, int y);
void				juliav2(t_frac *f, int x, int y);
void				juliav3(t_frac *f, int x, int y);
void				web(t_frac *f, int x, int y);
void				circles(t_frac *f, int x, int y);
void				mandelbrot(t_frac *f, int x, int y);
void				pixel_to_image(t_image *img, int x, int y, int color);
void				initialize_hooks(t_frac *f);
int					key_press(int keycode, t_frac *f);
int					additional_hooks(int k, t_frac *f);
int					exit_program(t_frac *f);
int					pick_color(t_frac *f, int i);
int					mouse_release(int button, int x, int y, t_frac *f);
int					mouse_press(int button, int x, int y, t_frac *f);
int					mouse_move(int x, int y, t_frac *f);

#endif
