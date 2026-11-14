#include "Renderer.h"
#include <stdio.h>
#include <raylib.h>

Color space_Color;
my_Texture art_Clouds;
my_Texture playertext;
my_Font fontTTF;
my_Camera camera;
Rectangle HBounds;
Rectangle EBounds;

const int viewport_Width = 320;
const int viewport_Height = 180;
RenderTexture2D viewport;

void Load_Fonts(my_Font* struc, const char* path, const char* msg, Vector2 pos, float size, float spacing, Color tint) {

    struc->font = LoadFontEx(path, (float)size, NULL, 0);
    struc->path = path;
    struc->msg = msg;
    struc->size = size;
    struc->pos = pos;
    struc->size = size;
    struc->spacing = spacing;
    struc->tint = tint;

    if (!IsFontValid(struc->font)) {
        printf("Error: font is not valid");
    }
}

void Load_Texture(my_Texture* struc, const char* path, Vector2 pos, Rectangle rect, Color color) {

    struc->text = LoadTexture(path);
    struc->pos = pos;
    struc->rect = rect;
    struc->color = color;
}

void Init_Color_Values() {

    space_Color.r = 54;
    space_Color.g = 69;
    space_Color.b = 79;
    space_Color.a = 100;
}

void Init_Render() {

    Load_Texture(&art_Clouds, "resources/Textures/Clouds.png", (Vector2)VZERO, (Rectangle) { 0, 0, 320, 180 }, WHITE);
    SetTextureFilter(art_Clouds.text, TEXTURE_FILTER_POINT);

    Load_Texture(&Hero.playertext, "resources/Textures/Player.png", (Vector2) { 10, 40 }, (Rectangle) { 0, 0, 32, 32 }, WHITE);
    SetTextureFilter(Hero.playertext.text, TEXTURE_FILTER_POINT);
    
    Load_Texture(&Man.enemytext, "resources/Textures/Enemy.png", (Vector2) { 70, 50 }, (Rectangle) { 0, 0, 32, 32 }, WHITE);
    SetTextureFilter(Man.enemytext.text, TEXTURE_FILTER_POINT);

    Load_Fonts(&fontTTF, "resources/Fonts/propaganda.ttf", "Using Ocelot-Engine\nGame Engine By Ahmed Naffa", (Vector2) { 5, 0 }, 15, 2, GOLD);
    SetTextureFilter(fontTTF.font.texture, TEXTURE_FILTER_POINT);

    Init_Color_Values();
    camera.cam.target = (Vector2)VZERO;
    camera.cam.offset = (Vector2)VZERO;
    camera.cam.rotation = 0;
    camera.cam.zoom = 1;
    camera.speed = 10;
}

void Draw() {
    BeginTextureMode(viewport);
    ClearBackground(space_Color);

    BeginMode2D(camera.cam);
    DrawTextureRec(art_Clouds.text, art_Clouds.rect, art_Clouds.pos, art_Clouds.color);

    DrawTextureRec(Hero.playertext.text, Hero.playertext.rect, Hero.playertext.pos, Hero.playertext.color);
     HBounds = (Rectangle){Hero.playertext.pos.x,Hero.playertext.pos.y,Hero.playertext.rect.width,Hero.playertext.rect.height}; //DEBUG TO SHOW Player COLLISON BOUNDS
    DrawRectangleLinesEx(HBounds, 1, space_Color);//DEBUG TO SHOW Player COLLISON BOUNDS

    DrawTextureRec(Man.enemytext.text, Man.enemytext.rect, Man.enemytext.pos, Man.enemytext.color);
     EBounds = (Rectangle){Man.enemytext.pos.x,Man.enemytext.pos.y,Man.enemytext.rect.width,Man.enemytext.rect.height};//DEBUG TO SHOW Enemy COLLISON BOUNDS
    DrawRectangleLinesEx(EBounds, 1, space_Color);//DEBUG TO SHOW Enemy COLLISON BOUNDS

    DrawTextEx(fontTTF.font, fontTTF.msg, fontTTF.pos, fontTTF.size, fontTTF.spacing, fontTTF.tint);
    
    EndMode2D();
    EndTextureMode();

    float scaleX = (float)GetScreenWidth()/viewport_Width;
    float scaleY = (float)GetScreenHeight()/viewport_Height;
    float scale = (scaleX<scaleY) ? scaleX : scaleY;

    Rectangle source = {0.0f, 0.0f, (float)viewport.texture.width, -(float)viewport.texture.height};
    Rectangle dest = {(GetScreenWidth()-(viewport_Width*scale))*0.5f, (GetScreenHeight()-(viewport_Height*scale))*0.5f, viewport_Width*scale, viewport_Height*scale};

    BeginDrawing();
    ClearBackground(space_Color);
    DrawTexturePro(viewport.texture, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE);

    DrawRectangle(0, 0, 90, 25, space_Color);
    DrawFPS(2, 2);
    EndDrawing();
}

void Unload_Textures() {
    UnloadTexture(art_Clouds.text);
}

void Unload_Fonts() {
    UnloadFont(fontTTF.font);
}