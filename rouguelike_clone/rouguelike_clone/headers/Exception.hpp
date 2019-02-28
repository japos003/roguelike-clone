//
//  Exception.hpp
//  rouguelike_clone
//
//  Created by Jon Raphael Apostol on 2/26/19.
//  Copyright © 2019 Jon Raphael Apostol. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <stdio.h>
#include <exception>
#include <string>
namespace GameDetails{
    class GameException : public std::exception{
    private:
        std::string _errorMessage;
    public:
        GameException(std::string errorMessage);
        virtual const char* what() const throw();
    };
}

#endif /* Exception_hpp */
