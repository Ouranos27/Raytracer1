/*
** rotate.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sat Feb 18 19:58:06 2017 philippe kam
** Last update Wed Feb 22 16:17:41 2017 philippe kam
*/

#include "raytracer1.h"

sfVector3f	rotation_x(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	res;
  float		angle;

  angle = (angles.x * M_PI) / 180;
  res.x = to_rotate.x;
  res.y = (cos(angle) * to_rotate.y) + (-sin(angle) * to_rotate.z);
  res.z = (sin(angle) * to_rotate.y) + (cos(angle) * to_rotate.z);
  return (res);
}

sfVector3f	rotation_y(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	res;
  float		angle;

  angle = (angles.y * M_PI) / 180;
  res.x = (cos(angle) * to_rotate.x) + (sin(angle) * to_rotate.z);
  res.y = to_rotate.y;
  res.z = (-sin(angle) * to_rotate.x) + (cos(angle) * to_rotate.z);
  return (res);
}

sfVector3f	rotation_z(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	res;
  float		angle;

  angle = (angles.z * M_PI) / 180;
  res.x = (cos(angle) * to_rotate.x) + (-sin(angle) * to_rotate.y);
  res.y = (sin(angle) * to_rotate.x) + (cos(angle) * to_rotate.y);
  res.z = to_rotate.z;
  return (res);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	rot;

  rot = rotation_x(to_rotate, angles);
  rot = rotation_y(rot, angles);
  rot = rotation_z(rot, angles);
  return (rot);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	rot;

  rot = rotation_z(to_rotate, angles);
  rot = rotation_y(rot, angles);
  rot = rotation_x(rot, angles);
  return (rot);
}
