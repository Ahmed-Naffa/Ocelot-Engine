#include "Player.h"
#include <Core/Types.h>

my_Player Hero;

int currentFrame = 0;
int framesCounter = 0;
int framesSpeed = 8;

void Init_Player() {
	Hero.player_Speed = 500;
	Hero.is_Active = true;
}

void Move_Player() {

	Hero.playertext.rect = (Rectangle){ 0, 0, Hero.playertext.text.width / 6, (float)Hero.playertext.text.height };


	if (IsKeyDown(KEY_A)) {
		Hero.playertext.pos.x -= Hero.player_Speed * delta;
	}
	if (IsKeyDown(KEY_D)) {
		Hero.playertext.pos.x += Hero.player_Speed * delta;
	}
	if (IsKeyDown(KEY_W)) {
		Hero.playertext.pos.y -= Hero.player_Speed * delta;
	}

	if (IsKeyDown(KEY_S)) {
		Hero.playertext.pos.y += Hero.player_Speed * delta;
	}

	if (IsKeyDown(KEY_EIGHT) && Hero.is_Active) {
		Hero.is_Active = false;
		Unload_Player();
	}
	if (CheckCollisionRecs(Hero.playertext.rect, Man.enemytext.rect)) {

		Hero.is_Active = false;
		TraceLog(LOG_INFO, "Kill");
	}
}

void Player_Animate()
{
	framesCounter++;

	if (framesCounter >= (target_fps / framesSpeed))
	{
		framesCounter = 0;

		currentFrame++;

		if (currentFrame >= 6) currentFrame = 0;

		Hero.playertext.rect.x = currentFrame * Hero.playertext.rect.width;
	}
	if (!Hero.is_Active) {
		//Unload_Player();
	}

}

void Unload_Player() {

	Hero = (my_Player){ 0 }; 
}