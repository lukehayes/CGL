#version 460 core

layout (location = 0) in vec3 attrPosition;
layout (location = 1) in vec3 attrColor;
layout (location = 2) in vec2 attrTexCoord;

uniform mat4 uProjection;
uniform mat4 uModel;
uniform mat4 uView;

out vec3 Color;
out vec2 TexCoord;

void main()
{
    gl_Position = uProjection * uView * uModel * vec4(attrPosition, 1.0f);
    TexCoord    = attrTexCoord;
    Color       = attrColor;
}
