//
//  Player.cpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/26/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#ifdef DEBUG
    #include <unistd.h>
#endif
#include "../headers/Player.hpp"
#include "../headers/Exception.hpp"


namespace Player{
    PlayableObject::PlayableObject(int x, int y, std::string image_src, SDL_Renderer *renderer) :
        DrawableObject(x, y, image_src, renderer, 50, 50) {
            _movingSFX = nullptr;
            _harmedSFX = nullptr;
            _attackingSFX = nullptr;
            _collectingSFX = nullptr;
        };
    
    PlayableObject::PlayableObject(int x, int y, std::string image_src, SDL_Renderer *renderer,
                                   int width, int height) :
        DrawableObject(x, y, image_src, renderer, width, height){
            _movingSFX = nullptr;
            _harmedSFX = nullptr;
            _attackingSFX = nullptr;
            _collectingSFX = nullptr;
        };
    
    PlayableObject::~PlayableObject(){
        FreeSFX();
    }
    
    void PlayableObject::Move(int x, int y){
        _x += x;
        _y += y;
        _rect.x = _x;
        _rect.y = _y;
    }
    
    void PlayableObject::Update(SDL_Renderer *renderer){
        SDL_RenderCopy(renderer, _texture, NULL, &_rect);
        //SDL_RenderPresent(renderer);
#ifdef DEBUG
        auto errorMessage = SDL_GetError();
        if(strlen(errorMessage) > 0){
            std::cout << "Error: " << SDL_GetError() << std::endl;
        }
#endif
    }
    
    void PlayableObject::LoadSFX(Player::GameEventStatus gameEventStatus, std::string sfx_src){
        switch(gameEventStatus){
            case MOVING:
                _movingSFX = Mix_LoadWAV(sfx_src.c_str());
                break;
            case ATTACKING:
                _attackingSFX = Mix_LoadWAV(sfx_src.c_str());
                break;
            case HARMED:
                _harmedSFX = Mix_LoadWAV(sfx_src.c_str());
                break;
            case COLLECTING:
                _collectingSFX = Mix_LoadWAV(sfx_src.c_str());
                break;
            default:
                
                break;
        }
    }
    
    void PlayableObject::FreeSFX(){
        if(_movingSFX != NULL){
            Mix_FreeChunk(_movingSFX);
        }
        if(_attackingSFX != NULL){
            Mix_FreeChunk(_attackingSFX);
        }
        if(_harmedSFX != NULL){
            Mix_FreeChunk(_harmedSFX);
        }
        if(_collectingSFX != NULL){
            Mix_FreeChunk(_collectingSFX);
        }
    }
}
