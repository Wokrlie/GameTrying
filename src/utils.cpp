#include "utils.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

void LoadTextureFromPNG(std::string file_path, Texture2D *texture) {
    Image image = LoadImage((char *)file_path.c_str());
    if (image.data == nullptr) {
        TraceLog(LOG_WARNING, "The image data is empty, is it a default constructor?");
    }
    *texture = LoadTextureFromImage(image);
}
