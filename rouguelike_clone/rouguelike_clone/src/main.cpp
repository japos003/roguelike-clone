//
//  main.cpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/26/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <SDL2_Mixer/SDL_mixer.h>

#include "../headers/Player.hpp"

void handleMovement(SDL_Event event, Player::PlayableObject *playableObject){
    if(event.key.keysym.scancode == SDL_SCANCODE_LEFT){
        playableObject->Move(-50, 0);
    }
    else if(event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
        playableObject->Move(50, 0);
    }
    if(event.key.keysym.scancode == SDL_SCANCODE_UP){
        playableObject->Move(0, -50);
    }
    else if(event.key.keysym.scancode == SDL_SCANCODE_DOWN){
        playableObject->Move(0, 50);
    }
};

int main(int argc, char** args)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    //For loading PNG images
    IMG_Init(IMG_INIT_PNG);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return -1;
    };
    
    SDL_Window* window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    Mix_Music *music = Mix_LoadMUS("resources/music/passion_pit_music_test.wav");
    if(music == NULL){
#ifdef DEBUG
        std::cout << "Error: " << SDL_GetError() << std::endl;
#endif
    }
    SDL_Event input;
    bool quit = false;

    Player::PlayableObject *player = new Player::PlayableObject(0, 300, "resources/img/awesome_face.png", renderer);
    Mix_PlayMusic(music, -1);
    
    while (!quit)
    {
        while (SDL_PollEvent(&input) > 0)
        {
            if (input.type == SDL_QUIT) quit = true;
            if(input.type == SDL_KEYDOWN){
                handleMovement(input, player);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        player->Update(renderer);

        //SDL_RenderPresent(renderer);
    }
    delete player;
    Mix_FreeMusic(music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //For quitting IMG systems
    IMG_Quit();

    SDL_Quit();

    return 0;
}


//int main(int argc, char** args)
//{
//    SDL_Init(SDL_INIT_EVERYTHING);
//    //For loading PNG images
//    IMG_Init(IMG_INIT_PNG);
//    SDL_Window* window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
//                                          SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
//    SDL_Event input;
//    bool quit = false;
//
//    SDL_Texture* texture = NULL;
//    SDL_Surface* temp = IMG_Load("resources/img/awesome_face.png");
//
//    //Filling texture with the image using a surface
//    texture = SDL_CreateTextureFromSurface(renderer, temp);
//
//    //Deleting the temporary surface
//    SDL_FreeSurface(temp);
//
//    SDL_Rect rect;
//    rect.x = 0; //Extreme left of the window
//    rect.y = 500; //Very bottom of the window
//    rect.w = 100; //100 pixels width
//    rect.h = 100; //100 pixels height
//    //'rect' defines the dimensions for the bottom-left of the window
//
//    while (!quit)
//    {
//        while (SDL_PollEvent(&input) > 0)
//        {
//            if (input.type == SDL_QUIT) quit = true;
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//
//        //Copying the texture on to the window using renderer and rectangle
//        SDL_RenderCopy(renderer, texture, NULL, &rect);
//
//        SDL_RenderPresent(renderer);
//    }
//
//    //Deleting the texture
//    SDL_DestroyTexture(texture);
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//
//    //For quitting IMG systems
//    IMG_Quit();
//
//    SDL_Quit();
//
//    return 0;
//}
