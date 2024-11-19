#ifndef GL_CAMERA3D_H
#define GL_CAMERA3D_H

#include "xx/gl/shader.h"
#include <cglm/vec3.h>

typedef struct Camera3D
{
    vec3 position;
    vec3 front;
    vec3 up;
    mat4 projectionMatrix;
    mat4 viewMatrix;

} Camera3D;

/**
* Create an instance of a 3D camera.
*
* @param vec3 position.
*
* @return Camera3D.
*/
Camera3D Camera3DCreate(vec3 position);

/**
* Update a Camera3D - the projection and view matricies.
*
* @param Camera3D camera.
* @param GLShader* shader.
*
* @return void.
*/
void Camera3DUpdate(Camera3D* camera, GLShader* shader);

#endif //GL_CAMERA3D_H
