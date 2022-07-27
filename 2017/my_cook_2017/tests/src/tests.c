/*
** EPITECH PROJECT, 2018
** test
** File description:
** function of test
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

Test(return_of_cut_text, check_value_of_cut_text)
{
	int	i = 0;
	char	*tmp = cut_text(&i, "BONJOUR STR");

	cr_assert(i == 8);
	cr_assert(my_strncmp("BONJOUR", tmp, 8) == 0);
}

Test(return_of_init_audio, check_value_of_init_audio)
{
	audio_s	audio = init_audio("./assets/menu.ogg");
	cr_assert(audio.mute != -1);
	sfMusic_destroy(audio.theme);
}

Test(return_of_window, check_of_the_windows)
{
	window_s	w;

	w = init_window(w);
	cr_assert_neq(w.window, NULL);
	sfMusic_destroy(w.audio.theme);
	sfRenderWindow_destroy(w.window);
}