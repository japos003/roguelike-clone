//
//  Exception.cpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/26/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//
#include <stdio.h>
#include <exception>
#include <string>

#include "../headers/Exception.hpp"

namespace GameDetails{
    GameException::GameException(std::string errorMsg){
        _errorMessage = errorMsg;
    }
    const char* GameException::what() const throw(){
        std::string message = "GAMEOBJECT ERROR: ";
        message.append(_errorMessage.c_str());
        
        return message.c_str();
    }
}
