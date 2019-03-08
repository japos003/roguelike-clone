//
//  Enemy.cpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 3/7/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Enemy.hpp"

Enemy::Enemy::Enemy(int x, int y, std::string image_src, SDL_Renderer *renderer) :
DrawableObject(x, y, image_src, renderer){};

Enemy::Enemy::Enemy(int x, int y, std::string image_src, SDL_Renderer *renderer, int width, int height)
    : DrawableObject(x, y, image_src, renderer, width, height){}

Enemy::Enemy::~Enemy(){
    
};
void Enemy::Enemy::Move(int x, int y){
    
};

void Enemy::Enemy::Update(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, _texture, NULL, &_rect);
    //SDL_RenderPresent(renderer);
#ifdef DEBUG
    auto errorMessage = SDL_GetError();
    if(strlen(errorMessage) > 0){
        std::cout << "Error: " << SDL_GetError() << std::endl;
    }
#endif
}
