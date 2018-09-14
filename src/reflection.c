/*
** reflection.c for raytracer in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Tue Apr 11 16:35:38 2017 philippe kam
** Last update Tue Apr 11 16:35:38 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	reflection_vector(sfVector3f dir_vector,
				  sfVector3f normal_vector)
{
  sfVector3f	reflection;
  float		scal;

  scal = (normal_vector.x * dir_vector.x) +
    (normal_vector.y * dir_vector.y) +
    (normal_vector.z * dir_vector.z);
  reflection.x = -2 * normal_vector.x * scal + dir_vector.x;
  reflection.y = -2 * normal_vector.y * scal + dir_vector.y;
  reflection.z = -2 * normal_vector.z * scal + dir_vector.z;
  return (reflection);
}
