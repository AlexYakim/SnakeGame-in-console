#pragma once


#include <iostream>
#include<thread>
#include"conio.h"

class Apple;
class DeadPool;
class Snake;

class DeadPool {

    
public:


   Apple& Set_apple_position (Apple& apple);

    int GetWeight();
    int GetLenght();
    DeadPool(int weight = 10, int lenght = 10); 


    void Pool_print(); 
    ~DeadPool(); 

    void Pool_set();

    bool Pool_move(Snake& snake, int& arrow_path); 

    void Set_snake(Snake& snake); 
private:
  
    int past_path;
    int pool_weight;
    int pool_lenght;

    char** deadpool_W_L = new char* [pool_weight];

    friend Apple;
   
    };


class Snake {

public:

    int snake_lenght;


    int snake_spead;
    int snake_positionX = 1;
    int snake_positionY = 1;

    void Snake_lenght_resize();



    Snake(int snake_spead);

    ~Snake();
    friend DeadPool;

};


class Apple {

private:
    int apple_location_X;
    int apple_location_Y;
    char apple_form[9] = { '1','(',')','0','%','$','!','=','+' };
    char apple_obj_form;
public:

    char Get_obj_form();
    int Get_apple_location_X();
    int Get_apple_location_Y();

    Apple(DeadPool& pool);
    ~Apple();


    friend DeadPool;
};