/*
** EPITECH PROJECT, 2017
** framebuffer
** File description:
** Day13
*/

#ifndef FRAMEBUFFER_H_
	#define FRAMEBUFFER_H_

	#define	WIDTH 	(1280)
	#define	HEIGHT 	(720)
	#define FG "./sprite/Foreground.png"
	#define BG "./sprite/Background.png"
	#define PR "./sprite/player.png"
	#define OB1 "./sprite/spike/spike.png"
	#define OB2 "./sprite/spike/spikeA.png"
	#define DEATH sfTime_asSeconds(sfClock_getElapsedTime(game->timer_end))

typedef struct			s_obs
{
	sfSprite 		*s;
	sfTexture		*t;
	float			x;
	float			y;
	struct	s_obs		*next;
}				obs_t;

typedef	struct			s_game
{

	float			x;
	float			y;
	float			x_bg;
	float			x_fg;
	char			*map;
	int			score;
	int			dead;
	int			to_time;
	sfRenderWindow		*w;
	sfEvent 		event;
	sfSprite 		*sp;
	sfTexture		*tp;
	sfTexture		*tb;
	sfSprite 		*sb;
	sfTexture		*tb2;
	sfSprite 		*sb2;
	sfSprite 		*s_fg;
	sfTexture		*t_fg;
	sfSprite 		*s_fg2;
	sfTexture		*t_fg2;
	sfClock			*timer_obs;
	sfClock			*timer_p;
	sfClock			*timer_bg;
	sfClock			*timer_fg;
	sfClock			*timer_end;
	sfText			*text;
	sfText			*sc;
	sfFont			*font;
}				game_t;

/*	Animation	*/
void		animation_player( int *, game_t *);
void		animation_bg(game_t *);
void		animation_fg(game_t *);
void		animation_obs(game_t *, obs_t *);
void		jump(game_t *, float, float);

/*	Set	*/
void		set_bg(game_t *);
void		set_fg(game_t *);
void		set_p(game_t *);
void		set_obs(game_t *, obs_t *);
void		stg(game_t *, obs_t **);
void		set_txt(game_t *);

int		my_printf(char *, ...);
void		clean(game_t *);

/*	Tools	*/
void		up(game_t *, obs_t *, int *);
char		*int_to_charstr(int);
sfIntRect	int_rec(int, int, int, int);
sfVector2f	vec(float x, float y);
int		read_map(char *, game_t *);

/*	Obstacle	*/
void		use_map(game_t *game, obs_t **obs);

#endif /* !FRAMEBUFFER_H_ */