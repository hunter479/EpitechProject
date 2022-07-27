/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** Header for the my_cook project
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

typedef struct	stage
{
	sfTexture	*texture;
	sfIntRect	box;
	char		*type;
	char		*class;
	float		x;
	float		y;
	float		scale;
	char		*scene;
	struct stage	*next;
}		stage;

typedef struct	audio_s
{
	int	mute;
	int	volume;
	sfMusic	*theme;
}		audio_s;

typedef struct	meal_s
{
	sfTexture	*texture;
	float	y;
	float	x;
	float	scale;
	struct meal_s	*next;
}		meal_s;

typedef struct	gameplay
{
	sfClock		*timer;
	int		timer_top;
	int		timer_left;
	int		score;
	int		score_animation;
	int		score_alpha;
	float		score_y;
	int		minutes;
	int		hours;
	char		*recipe;
	sfTexture	*order;
	char		*meal;
	int		is_pause;
	sfClock		*cy;
	struct meal_s	*cur_meal;
}		gameplay;

typedef struct	window_s
{
	float	width;
	float	height;
	int	ratio;
	sfVideoMode	mode;
	sfRenderWindow	*window;
	int	fullscreen;
	sfEvent	evt;
	stage	scene;
	char	*cur_scene;
	char	*select;
	char	*class_select;
	int	alpha;
	int	loop;
	int	x_mouse;
	int	y_mouse;
	struct audio_s	audio;
	struct gameplay	game;
}		window_s;

sfVector2u	create_vector2u(float, float);
sfVector2f	create_vector(float, float);
float		cut_param(int *, char *);
char		*cut_text(int *, char *);
char		*int_in_char(int);
char		*concatenate(char *, char *);
char		*concat_strings(char *, char *);
int		same_strings(char *, char *);
sfIntRect	set_box(int *, char *);
void		add_food(meal_s **, sfTexture *);
void		suppr_meal(meal_s **);
void		add_object(stage **, char *);
stage		init_menu(stage *);
void		init_pre_play(window_s *);
void		suppr_object(stage **);
void		suppr_stage(stage **);
char		**get_name(char **);
sfColor		fade_in(window_s *);
sfColor		fade_out(window_s *);
void		reset_buttons(window_s *);
void		check_button_pressed(window_s *);
void		check_events(window_s *);
void		render_mouse(window_s *);
void		display_score(window_s *);
void		display_order(window_s *);
void		render_meal(window_s *);
void		render_sprite(window_s *, stage *);
void		render(window_s *);
void		check_select_pause(window_s *);
void		pause_game(window_s *);
void		check_select_play(window_s *);
void		check_select(window_s *);
int		check(int, char **, char **);
stage		init_menu(stage *);
void		play(window_s *);
audio_s		init_audio(char *path);
void		settings(window_s *);
window_s	init_window(window_s w);
void		prepare_game(void);
int		my_strncmp(char const *, char const *, int);
int		my_putstr(char const *);
int		my_strlen(char const *);
int		display_ashe(void);
char		*my_strdup(char *src);


#endif /* !PROTO_H_ */
