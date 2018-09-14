/*
** finders.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
**
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
**
** Started on  Sun Mar 19 19:45:05 2017 philippe kam
** Last update Sun Mar 19 19:45:05 2017 philippe kam
*/

#include "raytracer1.h"

t_obj	*obj_between_light(t_obj *obj, t_vec *vec)
{
  int	i;

  i = 0;
  while (i < NB_LIGHT)
    {
      if ((obj->klight[i] = malloc(sizeof(t_obj))) == NULL)
	return (NULL);
      obj->klight[i][0] = intersect_plane(vec->point, vec->light_vector[i]);
      obj->klight[i][1] = intersect_sphere(vec->point,
					   vec->light_vector[i], S_RADIUS);
      obj->klight[i][2] = intersect_cylinder(vec->point,
					     vec->light_vector[i], C_RADIUS);
      obj->klight[i][3] = intersect_cone(vec->point,
					 vec->light_vector[i], SEMIANGLE);
      ++i;
    }
  return (obj);
}

t_obj	*use_coef(t_obj *obj)
{
  int	i;

  i = 0;
  while (i < NB_LIGHT)
    {
      if ((obj->klight[i][0] > 0.0000009f && obj->klight[i][0] < 0.99f)
	  || (obj->klight[i][1] > 0.0000009f && obj->klight[i][1] < 0.99f)
	  || (obj->klight[i][2] > 0.0000009f && obj->klight[i][2] < 0.99f)
	  || (obj->klight[i][3] > 0.0000009f && obj->klight[i][3] < 0.99f))
	{
	  obj->color.r *= obj->spots_coef;
	  obj->color.g *= obj->spots_coef;
	  obj->color.b *= obj->spots_coef;
	}
      ++i;
    }
  obj->spots_coef += (obj->spots_coef < 0.9f) ? 0.1f : 1 - obj->spots_coef;
  obj->color.r = obj->color.r + obj->color.r * obj->spots_coef;
  obj->color.g = obj->color.g + obj->color.g * obj->spots_coef;
  obj->color.b = obj->color.b + obj->color.b * obj->spots_coef;
  return (obj);
}


t_obj	*find_the_right_color(t_obj *obj)
{
  if (obj->pos == 0)
    obj->color = sfBlue;
  else if (obj->pos == 1)
    obj->color = sfRed;
  else if (obj->pos == 2)
    obj->color = sfGreen;
  else if (obj->pos == 3)
    obj->color = sfYellow;
  obj = use_coef(obj);
  return (obj);
}

t_vec	*find_the_normal(t_vec *vec, t_obj *obj)
{
  int	i;

  if (obj->pos == 0)
    {
      if (vec->eye_pos[0].z > 0.0f)
	i = 1;
      else
	i = 0;
      vec->normal = get_normal_plane(i);
    }
  else if (obj->pos == 1)
    vec->normal = get_normal_sphere(vec->point);
  else if (obj->pos == 2)
    vec->normal = get_normal_cylinder(vec->point);
  else if (obj->pos == 3)
    vec->normal = get_normal_cone(vec->point, SEMIANGLE);
  return (vec);
}

t_obj	*find_the_right_k(t_obj *obj, t_vec *vec)
{
  int   i;

  i = 0;
  obj->k = -0.99f;
  obj->pos = 0;
  while (i < NB_OBJ)
    {
      if (obj->k_obj[i] > 0.0f)
	{
	  if (obj->k < 0.0f || obj->k > obj->k_obj[i])
	    {
	      obj->k = obj->k_obj[i];
	      vec->point = get_inters(obj->k, vec->eye_pos[i], vec->dir_vector);
	      obj->pos = i;
	    }
	}
      ++i;
    }
  return (obj);
}
