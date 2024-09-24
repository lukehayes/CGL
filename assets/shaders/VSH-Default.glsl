#version 460 core

layout (location = 0) in vec3 vtx_position;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
    //gl_Position = projection * view * model * vec4(vtx_position, 1.0f);
    gl_Position = vec4(vtx_position, 1.0f);
}
