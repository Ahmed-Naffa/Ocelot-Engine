#pragma once
#include <Core/Types.h>

void Init_Sound(my_Sound* sound,const char* path, float volume, float pitch);
void Play_Sound();
void Unload_Sound(my_Sound* sound);

void Init_Music(my_Music* music, const char* path, float volume, float pitch);
void Play_Music(my_Music* music);
void Unload_Music(my_Music* music);

void Load_Audio();
void UnLoad_Audio();