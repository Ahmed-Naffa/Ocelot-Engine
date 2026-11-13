#include "Player.h"
#include <Core/Types.h>
#include <raymath.h>

my_Player Hero;

int currentFrame = 0;
int framesCounter = 0;
int framesSpeed = 8;

bool col = false;
bool ismoving = false;

void Init_Player() {
    Hero.player_Speed = 0;            
    Hero.player_Walk_Speed = 500;
    Hero.player_Max_Speed = 700;
    Hero.player_Min_Speed = 0;
    Hero.player_Acceleration = 1200;
    Hero.player_Deceleration = 1500;
}

void Move_Player() {
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

    float target_Speed = Hero.player_Min_Speed;
    if ( ismoving ){
        target_Speed = IsKeyDown(KEY_LEFT_SHIFT) ? Hero.player_Max_Speed : Hero.player_Walk_Speed;
    }

    if ( Hero.player_Speed<target_Speed ){
        Hero.player_Speed += Hero.player_Acceleration*delta;
        if ( Hero.player_Speed>target_Speed ){
            Hero.player_Speed = target_Speed;
        }
    }
    else if ( Hero.player_Speed>target_Speed ){
        Hero.player_Speed -= Hero.player_Deceleration*delta;
        if ( Hero.player_Speed<target_Speed ){
            Hero.player_Speed = target_Speed;
        }
    }

    // 3. Apply movement along the active/last direction
    Hero.playertext.pos.x += move_Dir.x*Hero.player_Speed*delta;
    Hero.playertext.pos.y += move_Dir.y*Hero.player_Speed*delta;

	if (IsKeyPressed(KEY_EIGHT)) {
		Unload_Player();
	}
	col = CheckCollisionRecs(HBounds, EBounds);
	if (col) {

		Unload_Player();
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
}

void Unload_Player() {

	Hero = (my_Player){0};
}