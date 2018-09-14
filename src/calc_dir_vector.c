/*
** calc_dir_vector.c for braytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/braytracer1/src
**
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
**
** Started on  Tue Feb  7 19:30:30 2017 philippe kam
** Last update Thu Feb 23 22:33:05 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2f screen_pos)
{
  sfVector3f	vdir;

  vdir.x = dist_to_plane;//-(screen_size.x / (2 * tan(30/2)));
  vdir.y = (screen_size.x / 2) - screen_pos.x;
  vdir.z = (screen_size.y / 2) - screen_pos.y;
  vdir = normalizer(vdir);
  return (vdir);
}
