/*
** cone.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Feb 22 17:05:12 2017 philippe kam
** Last update Thu Feb 23 23:06:59 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	norm;
  float		tang;

  tang = tan((semiangle * M_PI) / 180);
  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = -tang * intersection_point.y;
  return (norm);
}

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		tang;

  if (semiangle == 90)
    return (-1);
  tang = tan((semiangle * M_PI) / 180);
  a = powf(dir_vector.x, 2) + powf(dir_vector.y, 2)
    - (powf(dir_vector.z, 2) * tang);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y)
	   - ((eye_pos.z * dir_vector.z)
	      * tang));
  c = powf(eye_pos.x, 2) + powf(eye_pos.y, 2)
    - (powf(eye_pos.z, 2) * tang);
  delta = powf(b, 2) - (4 * a * c);
  return (handler(a, b, delta) + 0.000009);
}
