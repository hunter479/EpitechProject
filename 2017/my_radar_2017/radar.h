/*
** EPITECH PROJECT, 2017
** framebuffer
** File description:
** Day13
*/

#ifndef RADAR_H
	#define RADAR_H

	#define	WIDTH 	(1920)
	#define	HEIGHT 	(1080)

typedef	struct			s_game
{

	sfRenderWindow		*w;
	sfEvent 		event;
	sfTexture		*tb;
	sfSprite 		*sb;
}				game_t;

/*	Set	*/
void		set_bg(game_t *);
void		stg(game_t *);

int		my_printf(char *, ...);

/*	Tools	*/
void		up(game_t *);
sfVector2f	vec(float, float);

#endif /* !RADAR_H */