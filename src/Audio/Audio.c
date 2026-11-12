#include "Audio.h"
#include <raylib.h>

my_Sound drop_Sound;
my_Sound Pick_Sound;
my_Sound press_Sound;
my_Music maiden_Voyage;

void Load_Sound(my_Sound* struc, Sound sound, char* path, float volume, float pitch) {

	struc->sound = LoadSound(path);
	struc->path = path;
	struc->volume = volume;
	struc->pitch = pitch;
}

void Load_Music(my_Music* struc, Music music, char* path, float volume, float pitch) {

	struc->music = LoadMusicStream(path);
	struc->path = path;
	struc->volume = volume;
	struc->pitch = pitch;
}

void Init_Sound() {

	maiden_Voyage.volume = 1;
	maiden_Voyage.pitch = 1;
	drop_Sound.volume = 1;
	drop_Sound.pitch = 1;
	Pick_Sound.volume = 1;
	Pick_Sound.pitch = 1;
	press_Sound.volume = 1;
	press_Sound.pitch = 1;

	Load_Sound(&drop_Sound, drop_Sound.sound, "resources/Sounds/Sfx/Drop.mp3", drop_Sound.volume, drop_Sound.pitch);
	Load_Sound(&Pick_Sound, Pick_Sound.sound, "resources/Sounds/Sfx/Pick.mp3", Pick_Sound.volume, Pick_Sound.pitch);
	Load_Sound(&press_Sound, press_Sound.sound, "resources/Sounds/Sfx/press.mp3", press_Sound.volume, press_Sound.pitch);

	Load_Music(&maiden_Voyage, maiden_Voyage.music, "resources/Sounds/Music/MaidenVoyage.mp3", maiden_Voyage.volume, maiden_Voyage.pitch);
	PlayMusicStream(maiden_Voyage.music);

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

	UpdateMusicStream(maiden_Voyage.music);

	if (IsKeyPressed(KEY_KP_ADD)) {
		maiden_Voyage.volume += .2f;
		if (maiden_Voyage.volume > 1) maiden_Voyage.volume = 1;
		SetMusicVolume(maiden_Voyage.music, maiden_Voyage.volume);
	}
	if (IsKeyPressed(KEY_KP_SUBTRACT)) {
		maiden_Voyage.volume -= .2f;
		if (maiden_Voyage.volume < 0) maiden_Voyage.volume = 0;
		SetMusicVolume(maiden_Voyage.music, maiden_Voyage.volume);
	}
	if (IsKeyPressed(KEY_KP_MULTIPLY)) {
		maiden_Voyage.pitch += .1f;
		if (maiden_Voyage.pitch > 2) maiden_Voyage.pitch = 2;
		SetMusicPitch(maiden_Voyage.music, maiden_Voyage.pitch);
	}
	if (IsKeyPressed(KEY_KP_DIVIDE)) {
		maiden_Voyage.pitch -= .1f;
		if (maiden_Voyage.pitch < 0) maiden_Voyage.pitch = 0;
		SetMusicPitch(maiden_Voyage.music, maiden_Voyage.pitch);
	}
}

void Unload_Sound() {
	UnloadSound(drop_Sound.sound);
	UnloadSound(press_Sound.sound);
	UnloadSound(Pick_Sound.sound);
	UnloadMusicStream(maiden_Voyage.music);
}