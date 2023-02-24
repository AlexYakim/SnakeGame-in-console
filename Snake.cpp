#include"Stack_of_class_for_Game.h"




void Snake::Snake_lenght_resize() {

    snake_lenght.resize(snake_lenght.size() + 1);
    
    snake_positionX.resize(snake_positionX.size() + 1);
    snake_positionY.resize(snake_positionY.size() + 1);
    snake_positionX.at(snake_positionX.front())= snake_positionX.back() - 1;
    snake_positionY.at(snake_positionY.front() - 1)= snake_positionY.back() - 1;;
}



   Snake:: Snake(int snake_spead) :snake_spead(snake_spead) { snake_lenght.resize(1); }

   Snake:: ~Snake() {}

