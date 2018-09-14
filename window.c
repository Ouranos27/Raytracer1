/*
1;4205;0c** window.c for window in /home/pipolm.pk/C_Graphical_Prog
** 
** Made by Philippe KAM
** Login   <pipolm.pk@epitech.net>
** 
** Started on  Tue Nov  8 09:39:15 2016 Philippe KAM
** Last update Sat Feb 25 14:48:56 2017 philippe kam
*/

#include "raytracer1.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit (EXIT_FAILURE);
  return (window);
}

sfUint8		*create_pixel_buffer(int width, int height)
{
  int		i;
  sfUint8	*pixels;

  pixels = malloc(width * height * 4 * sizeof(pixels));
  if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}

void	window_main(t_my_framebuffer *framebuffer, t_sfml *sfml,t_vec *vec)
{
  if (sfml->window == NULL)
    exit (EXIT_FAILURE);
  while (sfRenderWindow_isOpen(sfml->window))
    {
      if (sfRenderWindow_pollEvent(sfml->window, &sfml->event))
	{
	  if (sfml->event.type == sfEvtClosed)
	    sfRenderWindow_close(sfml->window);
	  if (sfml->event.type == sfEvtKeyPressed)
	    {
	      if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(sfml->window);
	      if (moves(vec) == 0)
		draw_all(framebuffer, vec);
	      sfTexture_updateFromPixels(sfml->texture, framebuffer->pixels,
	      SCREEN_WIDTH, SCREEN_HEIGHT, 0 , 0);
	    }
	}
      sfRenderWindow_clear(sfml->window, sfBlack);
      sfRenderWindow_drawSprite(sfml->window, sfml->sprite, NULL);
      sfRenderWindow_display(sfml->window);
    }
  sfRenderWindow_destroy(sfml->window);
}

t_vec			*init_vec(t_vec *vec)
{
  if ((vec->eye_pos = malloc(sizeof(t_vec))) == NULL
      || (vec->light  = malloc(sizeof(t_vec))) == NULL
      || (vec->light_vector = malloc(sizeof(t_vec))) == NULL)
    return (NULL);
  vec->eye_pos[0].x = -200;
  vec->eye_pos[0].y = 0;
  vec->eye_pos[0].z = 55;
  vec->eye_pos[1].x = -200;
  vec->eye_pos[1].y = 0;
  vec->eye_pos[1].z = 55;
  vec->eye_pos[2].x = -200;
  vec->eye_pos[2].y = 0;
  vec->eye_pos[2].z = 55;
  vec->eye_pos[3].x = -200;
  vec->eye_pos[3].y = 0;
  vec->eye_pos[3].z = 55;
  vec->angles.x = 0;
  vec->angles.y = 1;
  vec->angles.z = 0;
  vec->light[0].x = -200;
  vec->light[0].y = -95;
  vec->light[0].z = 75;
  vec->light[1].x = -200;
  vec->light[1].y = 95;
  vec->light[1].z = 75;
  return (vec);
}

void	free_all(t_my_framebuffer *framebuffer, t_vec *vec, t_sfml *sfml)
{
  free(framebuffer->pixels);
  free(vec->eye_pos);
  free(vec->light);
  free(vec->light_vector);
  free(framebuffer);
  free(vec);
  free(sfml);
}

int			main()
{
  t_sfml		*sfml;
   t_my_framebuffer	*framebuffer;
  t_vec			*vec;

  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL
      || (vec = malloc(sizeof(t_vec))) == NULL
      || (sfml = malloc(sizeof(t_sfml))) == NULL)
    return (84);
  vec = init_vec(vec);
  sfml->window = create_window("Rayyyyyytracer!!!", SCREEN_WIDTH, SCREEN_HEIGHT);
  sfml->sprite = sfSprite_create();
  sfml->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  framebuffer->pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sfml->sprite, sfml->texture, sfTrue);
  if (draw_all(framebuffer, vec) == ERROR)
    return (84);
  sfTexture_updateFromPixels(sfml->texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  window_main(framebuffer, sfml, vec);
  free_all(framebuffer, vec, sfml);
  return (0);
}
