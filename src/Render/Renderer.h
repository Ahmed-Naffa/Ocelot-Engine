#pragma once
#include <Core/Types.h>

void Load_Fonts(my_Font* struc, const char* path, const char* msg, Vector2 pos, float size, float spacing, Color tint);
void Load_Texture(my_Texture* struc, Texture2D text, const char* path, Vector2 pos, Rectangle rect, Color color);
void Init_Color_Values();
void Init_Render();
void Draw();
void Unload_Textures();
void Unload_Fonts();