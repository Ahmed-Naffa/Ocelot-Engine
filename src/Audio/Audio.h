#pragma once
#include <Core/Types.h>

void Load_Sound(my_Sound* struc, Sound sound, char* path, float volume, float pitch);
void Load_Music(my_Music* struc, Music music, char* path, float volume, float pitch);
void Init_Sound(void);
void Play_Sound(void);
void Unload_Sound(void);