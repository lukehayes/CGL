#ifndef GL_TEXUTRE_H
#define GL_TEXUTRE_H

typedef struct Texture 
{
    int width;
    int height;
    int nrChannels;
    unsigned int texture;

} Texture;


Texture* TextureCreate(const char* image);

void TextureDestroy(Texture* texture);

#endif // GL_TEXUTRE_H
