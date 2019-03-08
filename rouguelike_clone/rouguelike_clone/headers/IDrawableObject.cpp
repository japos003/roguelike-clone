//
//  IDrawableObject.cpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 3/7/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#include <iostream>
#include <cstring>

#ifdef DEBUG
#include <unistd.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "IDrawableObject.hpp"
#include "Exception.hpp"

DrawableObject::DrawableObject(int x, int y, std::string image_src, SDL_Renderer *renderer) :
    DrawableObject(x, y, image_src, renderer, 50, 50) {};

DrawableObject::DrawableObject(int x, int y, std::string image_src,
                               SDL_Renderer *renderer, int width, int height){
    _x = x;
    _y = y;
    _rect = SDL_Rect{x, y, width, height};
    SDL_Surface* surface = IMG_Load(image_src.c_str());
#ifdef DEBUG
    char cCurrentPath[FILENAME_MAX];
    getcwd(cCurrentPath, sizeof(cCurrentPath));
    std::cout << "Current directory: " << cCurrentPath << std::endl;
#endif
    if(surface == NULL){
        auto errorMessage = SDL_GetError();
#ifdef DEBUG
        std::cout << "Error message: " << errorMessage << std::endl;
#endif
        throw GameDetails::GameException(errorMessage);
    }
    _texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
};

DrawableObject::~DrawableObject(){
    SDL_DestroyTexture(_texture);
};
