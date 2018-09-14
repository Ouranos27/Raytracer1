/*
** utils.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Mar  8 19:11:56 2017 philippe kam
** Last update Wed Mar  8 19:11:56 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	get_inters(float k, sfVector3f point, sfVector3f vector)
{
  sfVector3f	inters_point;

  inters_point.x = point.x + (k * vector.x);
  inters_point.y = point.y + (k * vector.y);
  inters_point.z = point.z + (k * vector.z);
  return (inters_point);
}

sfVector3f	get_light_vector(sfVector3f light, sfVector3f point)
{
  sfVector3f	light_vector;

  light_vector.x = light.x - point.x;
  light_vector.y = light.y - point.y;
  light_vector.z = light.z - point.z;
  return (light_vector);
}

sfVector3f	normalizer(sfVector3f vec)
{
  float		norm;

  norm = sqrtf(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2));
  vec.x /= norm;
  vec.y /= norm;
  vec.z /= norm;
  return (vec);
}

float	handler(float a, float b, float delta)
{
  float k1;
  float k2;

  if (delta < 0.00001f)
    return (-1);
  if (delta == 0.00001f)
    return ((-b) / (2 * a));
  else if (delta > 0.00001f)
    {
      k1 = (-b + sqrt(delta)) / (2 * a);
      k2 = (-b - sqrt(delta)) / (2 * a);
      if (k1 < k2 && k1 > 0.00001f)
	return (k1);
      else if (k2 < k1 && k2 > 0.00001f)
	return (k2);
      else if (k1 > 0.00001f && k2 < 0.00001f)
	return (k1);
      else if (k2 > 0.00001f && k1 < 0.00001f)
	return (k2);
    }
  return (-1.0f);
}
