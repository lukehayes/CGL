#ifndef XX_SHADER_H
#define XX_SHADER_H

typedef struct GLShader
{
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;

} GLShader;


/**
 * initialize a shader.
 *
 * @return glshader
*/
GLShader GLShaderInit();


/* ----------------------------------------------------------------------------
:  Shader Uniforms
-----------------------------------------------------------------------------*/
/**
 * Set 1 uniform float.
 *
 * @param GLShader* shader.
 * @param const char* name.
 * @param float v1.
 *
 * @return void.
 */
void GLShaderUniform1F(GLShader* shader, const char* name, float v1);

/**
 * Set 2 uniform floats.
 *
 * @param GLShader* shader.
 * @param const char* name.
 * @param float v1.
 * @param float v2.
 *
 * @return void.
 */
void GLShaderUniform2F(GLShader* shader, const char* name, float v1, float v2);
void GLShaderUniform3F(GLShader* shader, const char* name, float v1, float v2, float v3);
void GLShaderUniform4F(GLShader* shader, const char* name, float v1, float v2, float v3, float v4);

#endif // XX_SHADER_H
