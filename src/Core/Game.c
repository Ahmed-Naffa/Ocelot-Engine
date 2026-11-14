#include <raylib.h>
#include "Game.h"
#include "Window.h"
#include "Types.h"
#include <Render/Renderer.h>
#include <SandBox/Player.h>
#include <SandBox/Enemy.h>
#include <Audio/Audio.h>

float delta;

void GAME() {

	Init_Window();
	Init_Render();
	Init_Player(&Hero);
	Init_Enemy(&Man);
	InitAudioDevice();
	Load_Audio();

	while (!WindowShouldClose())
	{
		//update
		delta = GetFrameTime();
		Window_Change_Fullscreen();
		Player_Animate(&Hero);
		Move_Player(&Hero, delta);
		Play_Sound();
		Play_Music(&maiden_Voyage);
		Move_Enemy(&Man);
		Enemy_Animate(&Man);

		//draw
		Draw();

	}
	UnLoad_Audio();
	CloseWindow();
}