#version 460 core

layout (location = 0) in vec3 vtx_position;

void main()
{
    gl_Position = vec4(vtx_position, 1.0f);
}
