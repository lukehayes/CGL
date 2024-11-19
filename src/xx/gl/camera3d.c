#include "xx/gl/camera3d.h"

Camera3D Camera3DCreate(vec3 position)
{
    Camera3D camera;
    
    glm_vec3_zero(camera.position);
    glm_vec3_zero(camera.front);
    glm_vec3_zero(camera.up);


    camera.position[0] = position[0];
    camera.position[1] = position[1];
    camera.position[2] = position[2];

    camera.front[0] = 0.0f;
    camera.front[1] = 0.0f;
    camera.front[2] = -1.0f;

    camera.up[0] = 0.0f;
    camera.up[1] = 1.0f;
    camera.up[2] = 0.0f;

    glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, camera.projectionMatrix );

    glm_lookat(
        camera.position,
        camera.front,
        camera.up,
        camera.viewMatrix
    );

    return camera;
}

void Camera3DUpdate(Camera3D* camera, GLShader* shader)
{
    glm_lookat(
        camera->position,
        camera->front,
        camera->up,
        camera->viewMatrix
    );

    GLShaderUniformMat4(shader, "view", camera->viewMatrix);
    GLShaderUniformMat4(shader, "projection", camera->projectionMatrix);
}
