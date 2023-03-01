#include"Stack_of_class_for_Game.h"


int getRandomNumber(int min, int max);



Apple::Apple(DeadPool& pool) {


    apple_obj_form = apple_form[getRandomNumber(0,8)];


   apple_location_X = getRandomNumber(2, (pool.GetLenght())-3 );
   apple_location_Y = getRandomNumber(2, (pool.GetWeight())-3 );

    

}
Apple::~Apple(){}



void Apple::Relocation(DeadPool& pool) {

    apple_obj_form = apple_form[getRandomNumber(0, 8)];


    apple_location_X = getRandomNumber(2, (pool.GetLenght()-3));
    apple_location_Y = getRandomNumber(2, (pool.GetWeight()-3));


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
        std::random_device rd;
        std::mt19937 mersene(rd());
        std::uniform_int_distribution<int> dis(min, max);
        return dis(mersene);
   
}