#include"Stack_of_class_for_Game.h"




void Snake::Snake_lenght_resize(int arrow) {

    snake_lenght += 1;
    
    if (arrow == 72) {
        snake_positionY.resize(snake_positionY.size() + 1, (snake_positionY.back() - 1));
        snake_positionX.resize(snake_positionX.size() + 1, (snake_positionX.back()));
    }
    else if (arrow == 80) {
        snake_positionY.resize(snake_positionY.size() + 1, (snake_positionY.back() + 1));
        snake_positionX.resize(snake_positionX.size() + 1, (snake_positionX.back()));
    }
    else if (arrow == 77) {
        snake_positionX.resize(snake_positionX.size() + 1, (snake_positionX.back() + 1));
        snake_positionY.resize(snake_positionY.size() + 1, (snake_positionY.back()));
    }
    else {
        snake_positionX.resize(snake_positionX.size() + 1, (snake_positionX.back() - 1));
        snake_positionY.resize(snake_positionY.size() + 1, (snake_positionY.back()));
    }
   
    
  
}

Snake& Snake:: operator= (Snake& snake1) {

    snake_lenght = snake1.snake_lenght;
    snake_spead = snake1.snake_spead;
    snake_positionX.clear();
    snake_positionX = snake1.snake_positionX;
    snake_positionY.clear();
    snake_positionY = snake1.snake_positionY;
    return snake1;
}

   Snake:: Snake(int snake_spead) :snake_spead(snake_spead) { snake_lenght+=1; }

   Snake:: ~Snake() {}

