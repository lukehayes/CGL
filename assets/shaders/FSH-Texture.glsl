#version 460 core

out vec4 FragColor;

in vec3 Color;
in vec2 TexCoord;

uniform vec3 uColor;
uniform sampler2D ourTexture;
  
void main()
{
    FragColor = texture(ourTexture, TexCoord) * vec4(uColor, 1.0f);
} 
