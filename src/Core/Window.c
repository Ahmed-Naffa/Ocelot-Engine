#include "Window.h"
#include "Core/Types.h"

const int window_Width = 800;
const int window_Hieght = 600;
const int target_fps = 999;

void Init_Window() {

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(window_Width, window_Hieght, "ASN Game Engine");
	SetTargetFPS(target_fps);

	viewport = LoadRenderTexture(viewport_Width, viewport_Hieght);
	SetTextureFilter(viewport.texture, TEXTURE_FILTER_POINT);
}

//Toggel Fullscreen on off
void Window_Change_Fullscreen() {

	if (IsKeyPressed(KEY_F)) {
        ToggleBorderlessWindowed();
    }
}