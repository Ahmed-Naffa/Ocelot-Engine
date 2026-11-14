#include "Audio.h"
#include <raylib.h>

my_Sound drop_Sound;
my_Sound Pick_Sound;
my_Sound press_Sound;
my_Music maiden_Voyage;

void Init_Sound(my_Sound* sound, const char* path, float volume, float pitch) {

	sound->sound = LoadSound(path);
	sound->path = path;
	sound->volume = volume;
	sound->pitch = pitch;
}

void Init_Music(my_Music* music, const char* path, float volume, float pitch) {

	music->music = LoadMusicStream(path);
	music->path = path;
	music->volume = volume;
	music->pitch = pitch;
	PlayMusicStream(music->music);
}

void Load_Audio(){
	
	Init_Sound(&drop_Sound, "resources/Sounds/Sfx/Drop.mp3", 1, 1);
	Init_Sound(&Pick_Sound, "resources/Sounds/Sfx/Pick.mp3", 1, 1);
	Init_Sound(&press_Sound, "resources/Sounds/Sfx/press.mp3", 1, 1);
	Init_Music(&maiden_Voyage, "resources/Sounds/Music/MaidenVoyage.mp3", 1, 1);
}

void Play_Sound() {
	if (IsKeyPressed(KEY_ONE)) {
		PlaySound(drop_Sound.sound);
	}

	if (IsKeyPressed(KEY_TWO)) {
		PlaySound(Pick_Sound.sound);
	}

	if (IsKeyPressed(KEY_THREE)) {
		PlaySound(press_Sound.sound);
	}
}

void Play_Music(my_Music* music){

	UpdateMusicStream(music->music);

	if ( IsKeyPressed(KEY_KP_ADD) ){
		music->volume += .2f;
		if ( music->volume>1 ) music->volume = 1;
		SetMusicVolume(music->music, music->volume);
	}
	if ( IsKeyPressed(KEY_KP_SUBTRACT) ){
		music->volume -= .2f;
		if ( music->volume<0 ) music->volume = 0;
		SetMusicVolume(music->music, music->volume);
	}
	if ( IsKeyPressed(KEY_KP_MULTIPLY) ){
		music->pitch += .1f;
		if ( music->pitch>2 ) music->pitch = 2;
		SetMusicPitch(music->music, music->pitch);
	}
	if ( IsKeyPressed(KEY_KP_DIVIDE) ){
		music->pitch -= .1f;
		if ( music->pitch<0 ) music->pitch = 0;
		SetMusicPitch(music->music, music->pitch);
	}
}

void Unload_Sound(my_Sound* sound) {
	UnloadSound(sound->sound);
}

void Unload_Music(my_Music* music){
	UnloadMusicStream(music->music);
}

void UnLoad_Audio(){
	Unload_Sound(&drop_Sound);
	Unload_Sound(&Pick_Sound);
	Unload_Sound(&press_Sound);
	Unload_Music(&maiden_Voyage);
}