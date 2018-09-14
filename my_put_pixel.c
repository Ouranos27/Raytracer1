/*
** my_put_pixel.c for wireframe in /home/pipolm.pk/C_Graphical_Prog
** 
** Made by Philippe KAM
** Login   <pipolm.pk@epitech.net>
** 
** Started on  Thu Dec  8 14:52:48 2016 Philippe KAM
** Last update Wed Feb  8 15:58:52 2017 philippe kam
*/

#include "raytracer1.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color)
{
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4] = color.r;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = color.a;
}
