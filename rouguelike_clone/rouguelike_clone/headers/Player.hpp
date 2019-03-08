//
//  Player.hpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/26/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "IDrawableObject.hpp"

namespace Player{
    enum GameEventStatus{
        STATIONARY,
        MOVING,
        ATTACKING,
        HARMED,
        COLLECTING
    };
    
    class PlayableObject : DrawableObject{
    public:
        PlayableObject(int x, int y, std::string image_src, SDL_Renderer *renderer);
        PlayableObject(int x, int y, std::string image_src, SDL_Renderer *renderer, int width, int height);
        ~PlayableObject();
        void LoadSFX(Player::GameEventStatus gameEventStatus, std::string sfx_src);
        void Move(int x, int y);
        void Update(SDL_Renderer* renderer);
    private:
        /* Sound Effects */
        Mix_Chunk* _attackingSFX;
        Mix_Chunk* _movingSFX;
        Mix_Chunk* _harmedSFX;
        Mix_Chunk* _collectingSFX;
        
        /* Helper Functions */
        void FreeSFX();
    };
}

#endif /* Player_hpp */
