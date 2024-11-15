#ifndef XX_SHADER_H
#define XX_SHADER_H

typedef struct GLShader
{
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

} GLShader;


GLShader GLShaderInit();

#endif // XX_SHADER_H
