#include "utils.h"

Texture2D LoadTextureFromPNG(char* file_path, Texture2D* texture) {
    Image image = LoadImage(file_path);
    *texture = LoadTextureFromImage(image);
}