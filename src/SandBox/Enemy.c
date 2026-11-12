#include "Enemy.h"
#include <Core/Types.h>

my_Enemy Man;

 int currentFrameE = 0;
 int framesCounterE = 0;
 int framesSpeedE = 8;

void Init_Enemy() {
	Man.enemy_Speed = 500;
	Man.is_Active = true;
}

void Move_Enemy() {



	if (IsKeyDown(KEY_NINE) && Man.is_Active) {
		Man.is_Active = false;
		Unload_Enemy();
	}
}

void Enemy_Animate()
{
	framesCounterE++;

	if (framesCounterE >= (target_fps / framesSpeedE))
	{
		framesCounterE = 0;

		currentFrameE++;

		if (currentFrameE >= 6) currentFrameE = 0;

		Man.enemytext.rect.x = currentFrameE * Man.enemytext.rect.width;
	}
}

void Unload_Enemy() {

	Man = (my_Enemy){ 0 };
}