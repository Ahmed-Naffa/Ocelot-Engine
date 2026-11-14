#pragma once
#include <Core/Types.h>

void Init_Player(my_Player* player);
void Move_Player(my_Player* player, float delta);
void Player_Animate(my_Player* player);
void Unload_Player(my_Player* player);
