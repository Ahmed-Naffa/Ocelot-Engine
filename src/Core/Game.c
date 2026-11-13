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
	Init_Player();
	Init_Enemy();
	InitAudioDevice();
	Init_Sound();

	while (!WindowShouldClose())
	{
		//update
		delta = GetFrameTime();
		Window_Change_Fullscreen();
		Player_Animate();
		Move_Player();
		Play_Sound();
		Move_Enemy();
		Enemy_Animate();

		//draw
		Draw();

	}
	Unload_Sound();
}