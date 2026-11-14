#include "Player.h"
#include <Core/Types.h>
#include <raymath.h>

my_Player Hero;

int currentFrame = 0;
int framesCounter = 0;
int framesSpeed = 8;

bool isHit = false;
bool ismoving = false;

void Init_Player(my_Player* player) {
    player->player_Speed = 0;
    player->player_Walk_Speed = 250;
    player->player_Max_Speed = 300;
    player->player_Min_Speed = 0;
    player->player_Acceleration = 400;
    player->player_Deceleration = 750;
}

void Move_Player(my_Player* player, float delta) {
    Vector2 input = VZERO;

    if ( IsKeyDown(KEY_A) ) input.x -= 1;
    if ( IsKeyDown(KEY_D) ) input.x += 1;
    if ( IsKeyDown(KEY_W) ) input.y -= 1;
    if ( IsKeyDown(KEY_S) ) input.y += 1;

    ismoving = (input.x!=0||input.y!=0);

    static Vector2 move_Dir = VZERO;
    if ( ismoving ){
        move_Dir = Vector2Normalize(input);
    }

    float target_Speed = player->player_Min_Speed;
    if ( ismoving ){
        target_Speed = IsKeyDown(KEY_LEFT_SHIFT) ? player->player_Max_Speed : player->player_Walk_Speed;
    }

    if ( player->player_Speed<target_Speed ){
        player->player_Speed += player->player_Acceleration*delta;
        if ( player->player_Speed>target_Speed ){
            player->player_Speed = target_Speed;
        }
    }
    else if ( player->player_Speed>target_Speed ){
        player->player_Speed -= player->player_Deceleration*delta;
        if ( player->player_Speed<target_Speed ){
            player->player_Speed = target_Speed;
        }
    }

    player->playertext.pos.x += move_Dir.x*player->player_Speed*delta;
    player->playertext.pos.y += move_Dir.y*player->player_Speed*delta;

	isHit = CheckCollisionRecs(HBounds, EBounds);
	if (isHit) {

		Unload_Player(player);
	}

    // stay in screen
    if ( player->playertext.pos.x < 0 ) player->playertext.pos.x = 0;
    if ( player->playertext.pos.x>viewport_Width-(player->playertext.text.width/6) ) player->playertext.pos.x = viewport_Width-(player->playertext.text.width/6);
    if ( player->playertext.pos.y < 0 ) player->playertext.pos.y = 0;
    if ( player->playertext.pos.y >viewport_Height-player->playertext.text.height) player->playertext.pos.y = viewport_Height-player->playertext.text.height;
}

void Player_Animate(my_Player* player)
{
	framesCounter++;

	if (framesCounter >= (target_fps / framesSpeed))
	{
		framesCounter = 0;

		currentFrame++;

		if (currentFrame >= 6) currentFrame = 0;

        player->playertext.rect.x = currentFrame * player->playertext.rect.width;
	}
}

void Unload_Player(my_Player* player) {

    *player = (my_Player){0};
}