/*
** sphere.c for braytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/braytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Tue Feb  7 19:39:30 2017 philippe kam
** Last update Thu Feb 23 22:43:11 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	norm;

  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = intersection_point.y;
  return (norm);
}

float	intersect_sphere(sfVector3f eye_pos, sfVector3f	dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;

  a = (powf(dir_vector.x, 2) + powf(dir_vector.y, 2) + powf(dir_vector.z , 2));
  b = 2 * ((eye_pos.x * dir_vector.x) +
	   (eye_pos.y * dir_vector.y) + (eye_pos.z * dir_vector.z));
  c = powf(eye_pos.x, 2) + powf(eye_pos.y, 2) +
    powf(eye_pos.z, 2) - powf(radius, 2);
  delta = powf(b, 2) - (4 * a * c);
  return (handler(a, b, delta) + 0.0000009);
}
