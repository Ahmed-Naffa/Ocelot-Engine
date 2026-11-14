#include "Enemy.h"
#include <Core/Types.h>

my_Enemy Man;

 int currentFrameE = 0;
 int framesCounterE = 0;
 int framesSpeedE = 8;

void Init_Enemy(my_Enemy* enemy) {
	enemy->enemy_Speed = 500;
}

void Move_Enemy(my_Enemy* enemy) {

}

void Enemy_Animate(my_Enemy* enemy)
{
	framesCounterE++;

	if (framesCounterE >= (target_fps / framesSpeedE))
	{
		framesCounterE = 0;

		currentFrameE++;

		if (currentFrameE >= 6) currentFrameE = 0;

		enemy->enemytext.rect.x = currentFrameE *enemy->enemytext.rect.width;
	}
}

void Unload_Enemy(my_Enemy* enemy) {

	*enemy = (my_Enemy){0};
}