#include "Window.h"
#include "Core/Types.h"

const int window_Width = 800;
const int window_Hieght = 600;
const int window_x = 100;
const int window_y = 100;
const int target_fps = 999;

void Init_Window() {

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(window_Width, window_Hieght, "ASN Game Engine");
	SetTargetFPS(target_fps);
}

//Toggel Fullscreen on off
void Window_Change_Fullscreen() {

	if (IsKeyPressed(KEY_F))
	{
		if (!IsWindowFullscreen()) {
			ToggleFullscreen();
		}
		else
		{
			ToggleBorderlessWindowed();
			SetWindowPosition(window_x, window_y);
			SetWindowSize(window_Width, window_Hieght);
		}
	}
}