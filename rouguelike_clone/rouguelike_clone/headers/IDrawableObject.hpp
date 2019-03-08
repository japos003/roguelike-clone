//
//  IDrawableObject.hpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/27/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#ifndef IDrawableObject_hpp
#define IDrawableObject_hpp

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class DrawableObject{
public:
    DrawableObject(int x, int y, std::string image_src, SDL_Renderer *renderer);
    DrawableObject(int x, int y, std::string image_src, SDL_Renderer *renderer, int width, int height);
    ~DrawableObject();
    virtual void Move(int x, int y) = 0;
    virtual void Update(SDL_Renderer* renderer) = 0;
    
protected:
    int _x;
    int _y;
    int _width;
    int _height;
    SDL_Rect _rect;
    SDL_Texture* _texture;
};

#endif /* IDrawableObject_hpp */
