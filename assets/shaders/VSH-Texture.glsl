#version 460 core

layout (location = 0) in vec3 vtx_position;
layout (location = 1) in vec2 tex_coord;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;


out vec2 TexCoord;

void main()
{
    gl_Position = projection * view * model * vec4(vtx_position, 1.0f);
    TexCoord = tex_coord;
}
