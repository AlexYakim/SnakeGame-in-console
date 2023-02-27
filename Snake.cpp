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



   Snake:: Snake(int snake_spead) :snake_spead(snake_spead) { snake_lenght+=1; }

   Snake:: ~Snake() {}

