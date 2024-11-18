#ifndef GL_TEXUTRE_H
#define GL_TEXUTRE_H

#include "stddef.h"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


typedef struct Texture 
{
    int width;
    int height;
    int nrChannels;
    unsigned int texture;

} Texture;

void _TextureLoad(Texture* texture, const char* image)
{
    unsigned char *data = stbi_load(image, &texture->width, &texture->height, &texture->nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture:%s\n", image);
    }
    stbi_image_free(data);
}

void _TextureSetFilter()
{
    // Set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

Texture TextureCreate(const char* image)
{
    Texture texture;
    glGenTextures(1, &texture.texture);
    glBindTexture(GL_TEXTURE_2D, texture.texture);

    //_TextureSetFilter();

    _TextureLoad(&texture, image);

    return texture;
}

void TextureDestroy(Texture* texture)
{
    glDeleteTextures(1, &texture->texture);
}
#endif // GL_TEXUTRE_H
