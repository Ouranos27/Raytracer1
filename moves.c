/*
** moves.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sun Mar 19 19:26:08 2017 philippe kam
** Last update Sun Mar 19 19:26:08 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	*y_minus(sfVector3f *object)
{
  int		i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].y -= (float)15.5;
      ++i;
    }
  return (object);
}

sfVector3f	*x_minus(sfVector3f *object)
{
  int		i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].x -= (float)15.5;
      ++i;
    }
  return (object);
}

sfVector3f      *z_minus(sfVector3f *object)
{
  int           i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].z -= (float)15.5;
      ++i;
    }
  return (object);
}

sfVector3f	*y_add(sfVector3f *object)
{
  int		i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].y += (float)15.5;
      ++i;
    }
  return (object);
}

sfVector3f	*x_add(sfVector3f *object)
{
  int		i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].x += (float)15.5;
      ++i;
    }
  return (object);
}

sfVector3f      *z_add(sfVector3f *object)
{
  int           i;

  i = 0;
  while (i < NB_OBJ)
    {
      object[i].z += (float)15.5;
      ++i;
    }
  return (object);
}

int	eye_moves(t_vec *vec)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    vec->eye_pos = y_add(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyRight))
    vec->eye_pos = y_minus(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyUp))
    vec->eye_pos = x_add(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyDown))
    vec->eye_pos = x_minus(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyZ))
    vec->eye_pos = z_add(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyS))
    vec->eye_pos = z_minus(vec->eye_pos);
  else if (sfKeyboard_isKeyPressed(sfKeyQ))
    vec->angles.z += M_PI;
  else if (sfKeyboard_isKeyPressed(sfKeyD))
    vec->angles.z -= M_PI;
  else
    return (-1);
  return (0);
}

int	light_moves(t_vec *vec)
{
  if (sfKeyboard_isKeyPressed(sfKeyO))
    vec->light[0].x += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyL))
    vec->light[0].x -= 30;
  else if (sfKeyboard_isKeyPressed(sfKeyK))
    vec->light[0].y += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyM))
    vec->light[0].y -= 30;
  else if (sfKeyboard_isKeyPressed(sfKeyI))
    vec->light[0].z += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyP))
    vec->light[0].z -= 30;
  else if (sfKeyboard_isKeyPressed(sfKeyT))
    vec->light[1].x += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyG))
    vec->light[1].x -= 30;
  else if (sfKeyboard_isKeyPressed(sfKeyF))
    vec->light[1].y += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyH))
    vec->light[1].y -= 30;
  else if (sfKeyboard_isKeyPressed(sfKeyR))
    vec->light[1].z += 30;
  else if (sfKeyboard_isKeyPressed(sfKeyY))
    vec->light[1].z -= 30;
  else
    return (-1);
  return (0);
}

int	moves(t_vec *vec)
{
  if (eye_moves(vec) == 0)
    return (0);
  else if (light_moves(vec) == 0)
    return (0);
  return (-1);
}
