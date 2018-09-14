/*
** cylinder.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Thu Feb  9 14:40:11 2017 philippe kam
** Last update Wed Feb 22 14:43:47 2017 philippe kam
*/

#include "raytracer1.h"


sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	norm;

  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = 0;
  return (norm);
}

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
			   float radius)
{
  float		a;
  float		b;
  float		c;
  float		delta;

  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y));
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2) - pow(radius, 2);
  delta = pow(b, 2) - (4 * a * c);
  return (handler(a, b, delta) + 0.0000009);
}
