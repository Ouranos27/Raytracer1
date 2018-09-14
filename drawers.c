/*
** drawers.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Mon May 22 13:36:58 2017 philippe kam
** Last update Mon May 22 13:36:58 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	*all_light_vectors(t_vec *vec)
{
  int		i;

  i = 0;
  while (i < NB_LIGHT)
    {
      vec->light_vector[i] = get_light_vector(vec->light[i], vec->point);
      vec->light_vector[i] = rotate_zyx(vec->light_vector[i], vec->angles);
      ++i;
    }
  return (vec->light_vector);
}

float		*all_light_coefs(t_obj *obj, t_vec *vec)
{
  int		i;

  i = 0;
  while (i < NB_LIGHT)
    {
      obj->light_coef[i] = get_light_coef(vec->light_vector[i], vec->normal);
      ++i;
    }
  return (obj->light_coef);
}

float		spots_coef(t_obj *obj)
{
  float		coef;
  int		i;

  i = 0;
  coef = 0;
  while (i < NB_LIGHT)
    {
      coef += obj->light_coef[i];
      ++i;
    }
  coef /= NB_LIGHT;
  return (coef);
}

void		draw_scene(t_my_framebuffer *framebuffer, t_obj *obj,
		   t_vec *vec, sfVector2f screen_pos)
{
  obj = find_the_right_k(obj, vec);
  if (obj->k > 0.00001f)
    {
      vec->light_vector = all_light_vectors(vec);
      vec = find_the_normal(vec, obj);
      vec->normal = rotate_zyx(vec->normal, vec->angles);
      vec->normal = normalizer(vec->normal);
      //vec->reflection = get_reflection_vector(vec->dir_vector, vec->normal);
      obj->light_coef = all_light_coefs(obj, vec);
      obj->spots_coef = spots_coef(obj);
      obj = obj_between_light(obj, vec);
      //vec->point_reflection = get_inters(obj->k, vec->point, vec->reflection);
      obj = find_the_right_color(obj);
    }
  else
    obj->color = sfBlack;
  my_put_pixel(framebuffer, screen_pos.x, screen_pos.y, obj->color);
}

int		draw_all(t_my_framebuffer *framebuffer, t_vec *vec)
{
  t_obj		*obj;
  float		spots_coef(t_obj *obj)
  sfVector2i	screen_size;
  sfVector2f	screen_pos;

  if ((obj = malloc(sizeof(t_obj))) == NULL
      || (obj->k_obj = malloc(sizeof(t_obj))) == NULL
      || (obj->klight = malloc(sizeof(t_obj *))) == NULL
      || (obj->light_coef = malloc(sizeof(t_obj))) == NULL)
    return (ERROR);
  screen_pos.y = 0;
  screen_size.x = SCREEN_WIDTH;
  screen_size.y = SCREEN_HEIGHT;
  while (screen_pos.y < SCREEN_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < SCREEN_WIDTH)
	{
	  vec->dir_vector = calc_dir_vector((float)375,
					    screen_size, screen_pos);
	  //vec->dir_vector = rotate_zyx(vec->dir_vector, vec->angles);
	  obj = my_put_obj(vec, obj);
	  draw_scene(framebuffer, obj, vec, screen_pos);
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
  free(obj->k_obj);
  free(obj->klight);
  free(obj->light_coef);
  free(obj);
  return (0);
}
