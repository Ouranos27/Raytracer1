/*
** plane.c for braytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/braytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed Feb  8 14:26:16 2017 philippe kam
** Last update Sat Feb 25 13:47:41 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	norm;

  norm.x = 0;
  norm.y = 0;
  norm.z = (upward == 1) ? 100 : -100;
  return (norm);
}

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float		k;

  if (dir_vector.z == 0)
    return (-1);
  k = -1 * eye_pos.z / dir_vector.z;
  if (k <= 0)
    return (-0.99f);
  return (k);
}
