#include "utils.h"

#include <stdexcept>

void LoadTextureFromPNG(std::string file_path, Texture2D* texture) {
    Image image = LoadImage((char*)file_path.c_str());
    if (image.data == nullptr) {
        TraceLog(LOG_WARNING, "The image data is empty, is it a default constructor?");
    }
    *texture = LoadTextureFromImage(image);
}

Direction GetDirectionPos(Vector2 pos1, Vector2 pos2) {
    if (pos1.x > pos2.x) return Right;
    if (pos1.x < pos2.x) return Left;
    if (pos1.y > pos2.y) return Up;
    if (pos1.y < pos2.y) return Down;
    
    return None;
}