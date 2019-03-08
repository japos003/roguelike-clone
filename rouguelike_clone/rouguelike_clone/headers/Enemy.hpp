//
//  Enemy.hpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 3/7/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp
#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "IDrawableObject.hpp"

namespace Enemy{
    class Enemy : DrawableObject{
    public:
        Enemy(int x, int y, std::string image_src, SDL_Renderer *renderer);
        Enemy(int x, int y, std::string image_src, SDL_Renderer *renderer, int width, int height);
        ~Enemy();
        void Move(int x, int y);
        void Update(SDL_Renderer* renderer);
    };
};

#endif /* Enemy_hpp */
