#pragma once

#include <raylib.h>

#define VZERO {0, 0}

typedef struct {

	Sound sound;
	char* path;
	float volume;
	float pitch;

} my_Sound;

typedef struct {

	Music music;
	char* path;
	float volume;
	float pitch;

} my_Music;

typedef struct {

	Texture2D text;
	Vector2 pos;
	Rectangle rect;
	Color color;

} my_Texture;

typedef struct {

	Camera2D cam;
	float speed;

} my_Camera;

typedef struct {

	Font font;
	const char* path;
	const char* msg;
	Vector2 pos;
	float size;
	float spacing;
	Color tint;

} my_Font;

typedef struct {

	my_Texture playertext;
    float player_Speed;
	bool is_Active;

} my_Player;

typedef struct {

	my_Texture enemytext;
    float enemy_Speed;
	bool is_Active;

} my_Enemy;

extern my_Player Hero;

extern my_Enemy Man;

extern my_Sound drop_Sound;
extern my_Sound Pick_Sound;
extern my_Sound press_Sound;

extern my_Music maiden_Voyage;

extern Color space_Color;

extern my_Texture art_Clouds;

extern my_Font fontTTF;

extern my_Camera camera;

extern const int window_Width;
extern const int window_Hieght;
extern const int window_x;
extern const int window_y;
extern const int target_fps;

extern int currentFrame;
extern int framesCounter;
extern int framesSpeed;

extern int currentFrameE;
extern int framesCounterE;
extern int framesSpeedE;

extern float delta;