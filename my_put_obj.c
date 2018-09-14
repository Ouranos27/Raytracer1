/*
** my_put_obj.c for raytracer1 in /home/ouranos27/my_desktop/C_Graphical_Prog/raytracer1
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sun Mar 19 19:38:34 2017 philippe kam
** Last update Sun Mar 19 19:38:34 2017 philippe kam
*/

#include "raytracer1.h"

t_obj	*my_put_cone(t_vec *vec, t_obj *obj)
{
  /*sfVector3f	eye_pos;

  eye_pos.x = -200;
  eye_pos.y = -120;
  eye_pos.z = -125;*/
  /*vec->eye_pos.z += -90;
    vec->eye_pos.y += -120;*/
  obj->k_obj[3] = intersect_cone(vec->eye_pos[3], vec->dir_vector, SEMIANGLE);
  //vec->point = get_inters(obj->k_obj[3], eye_pos, vec->light_vector[0]);
  /*obj->klight[3] = intersect_cone(vec->point, vec->light_vector[0], SEMIANGLE);
  obj->klight[3] = (obj->klight[3] +
		    intersect_cone(vec->point,
		    vec->light_vector[1], SEMIANGLE)) / 2;*/
  /*vec->eye_pos.z += 90;
    vec->eye_pos.y += 120;*/
  return (obj);
}

t_obj	*my_put_sphere(t_vec *vec, t_obj *obj)
{
  /*sfVector3f    eye_pos;

  eye_pos.x = -200;
  eye_pos.y = 0;
  eye_pos.z = -25;*/
  //vec->eye_pos.z += -30;
  obj->k_obj[1] = intersect_sphere(vec->eye_pos[1], vec->dir_vector, S_RADIUS);
  //vec->point = get_inters(obj->k_obj[1], eye_pos, vec->light_vector[0]);
  /*obj->klight[1] = intersect_sphere(vec->point, vec->light_vector[0], S_RADIUS);
  obj->klight[1] = (obj->klight[1] +
		    intersect_sphere(vec->point,
		    vec->light_vector[1], S_RADIUS)) / 2;*/
  //vec->eye_pos.z += 30;
  return (obj);
}

t_obj	*my_put_cylinder(t_vec *vec, t_obj *obj)
{
  /*sfVector3f    eye_pos;

  eye_pos.x = -150;
  eye_pos.y = 90;
  eye_pos.z = -5;*/
  /*vec->eye_pos.x += 50;
    vec->eye_pos.y += 90;*/
  obj->k_obj[2] = intersect_cylinder(vec->eye_pos[2], vec->dir_vector, C_RADIUS);
  //vec->point = get_inters(obj->k_obj[2], eye_pos, vec->light_vector[0]);
  /*obj->klight[2] = intersect_cylinder(vec->point,
				      vec->light_vector[0], C_RADIUS);
  obj->klight[2] = (obj->klight[2] +
		    intersect_cylinder(vec->point,
		    vec->light_vector[1], C_RADIUS)) / 2;*/
  /*vec->eye_pos.y += -90;
    vec->eye_pos.x += -50;*/
  return (obj);
}

t_obj	*my_put_plane(t_vec *vec, t_obj *obj)
{
  /*sfVector3f    eye_pos;

  eye_pos.x = -200;
  eye_pos.y = 0;
  eye_pos.z = 25;*/
  obj->k_obj[0] = intersect_plane(vec->eye_pos[0], vec->dir_vector);
  //vec->point = get_inters(obj->k_obj[0], eye_pos, vec->light_vector[0]);
  /*obj->klight[0] = intersect_plane(vec->point, vec->light_vector[0]);
  obj->klight[0] = (obj->klight[0] +
  intersect_plane(vec->point, vec->light_vector[1])) / 2;*/
  return (obj);
}

t_obj	*my_put_obj(t_vec *vec, t_obj *obj)
{
  obj = my_put_sphere(vec, obj);
  obj = my_put_plane(vec, obj);
  obj = my_put_cylinder(vec, obj);
  obj = my_put_cone(vec, obj);
  return (obj);
}
