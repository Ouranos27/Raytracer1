/*
** light.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sat Feb 18 20:06:26 2017 philippe kam
** Last update Sat Feb 25 13:31:49 2017 philippe kam
*/

#include "raytracer1.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	light;
  float	sc_light;
  float	sc_vector;

  sc_light = sqrtf(powf(light_vector.x, 2)
		   + powf(light_vector.y, 2)
		   + powf(light_vector.z, 2));
  sc_vector = sqrtf(powf(normal_vector.x, 2)
		    + powf(normal_vector.y, 2)
		    + powf(normal_vector.z, 2));
  light = (normal_vector.x * light_vector.x)
    + (normal_vector.y * light_vector.y)
    + (normal_vector.z * light_vector.z);
  sc_light = sc_light * sc_vector;
  if (sc_light == 0)
    return (light);
  else
    light = light / sc_light;
  if (light < 0)
    return (0.00009f);
  return (light);
}
