/*
** EPITECH PROJECT, 2017
** windows.c
** File description:
** CPool_Day13_2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <Vector2.h>


int main()
{
	window();
}

int window()
{
	sfVideoMode mode = {800, 600, 32};
	sfEvent event;
	sfRenderWindow* window;

	window = sfRenderWindow_create(mode, "SFML windows", sfResize | sfClose, NULL);
	if (!window)
		return (84);
	array_pix();
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
		while (sfRenderWindow_waitEvent(window, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(window);
			}
		}
	}

}

int *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t	*fb;
	sfUint8 	*pixels;

	pixels = malloc(sizeof(sfUint8) * width * height * 4)
	if (pixels == 0)
		return (84);
	fb->width = width;
	fb->height = height;
	fb->pixels = pixels;
	memset(pixels, 0, width * height * 4);
	return (fb);
}