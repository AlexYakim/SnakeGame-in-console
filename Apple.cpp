#include"Stack_of_class_for_Game.h"


int getRandomNumber(int min, int max);



Apple::Apple(DeadPool& pool) {


    apple_obj_form = apple_form[getRandomNumber(0,8)];


   apple_location_X = getRandomNumber(1, pool.GetLenght());
   apple_location_Y = getRandomNumber(1, pool.GetWeight());

    

}
Apple::~Apple(){}



void Apple::Relocation(DeadPool& pool) {

    apple_obj_form = apple_form[getRandomNumber(0, 8)];


    apple_location_X = getRandomNumber(1, pool.GetLenght());
    apple_location_Y = getRandomNumber(1, pool.GetWeight());


}




int Apple::Get_apple_location_X() {

    return apple_location_X;
}
int Apple::Get_apple_location_Y() {

    return apple_location_Y;

}

char Apple:: Get_obj_form() {

    return apple_obj_form;


}


int getRandomNumber(int min, int max)
{
    rand();
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}