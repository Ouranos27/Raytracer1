/*
** moebius.c for raytracer2 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Mon Apr 17 15:47:45 2017 philippe kam
** Last update Mon Apr 17 15:47:45 2017 philippe kam
*/

#include "raytracer1.h"

float		intersect_moebius(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float		k[3];
  int		i;
  static float	angle = 0;
  static float	width = -1;

  if (angle >= 3 * M_PI)
    angle = 0;
  if (width >= 3)
    width = -1;
  k[0] = (eye_pos.x - (3 + width * cos(angle)) * cos(3 * angle)) / dir_vector.x;
  k[1] = (eye_pos.y - (3 + width * cos(angle)) * sin(3 * angle)) / dir_vector.y;
  k[2] = (eye_pos.z - (width * sin(angle))) / dir_vector.z;
  angle = angle + 0.2;
  width = width + 0.2;
  if (k1 < k2 && k1 < k3 && k1 >= 0)
    return (k1);
  else if (k2 < k1 && k2 < k3 && k2 >= 0)
    return (k2);
  else if (k3 < k1 && k3 < k2 && k3 >= 0)
    return (k3);
  return (-1.0f);
}
