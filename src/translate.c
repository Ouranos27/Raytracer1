/*
** translate.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sat Feb 18 19:57:02 2017 philippe kam
** Last update Sat Feb 18 20:50:44 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x = to_translate.x + translations.x;
  to_translate.y = to_translate.y + translations.y;
  to_translate.z = to_translate.z + translations.z;
  return (to_translate);
}

sfVector3f	inv_translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x = to_translate.x - translations.x;
  to_translate.y = to_translate.y - translations.y;
  to_translate.z = to_translate.z - translations.z;
  return (to_translate);
}
