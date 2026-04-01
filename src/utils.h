#pragma once
#include <raylib.h>
#include <string>  
#include "settings.h"

void LoadTextureFromPNG(std::string file_path, Texture2D* texture);

Direction GetDirectionPos(Vector2 pos1, Vector2 pos2);