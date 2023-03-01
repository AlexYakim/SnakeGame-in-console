#pragma once


#include <iostream>
#include<thread>
#include"conio.h"
#include<vector>
#include <random>

class Apple;
class DeadPool;
class Snake;



class DeadPool {

    
public:

   
    
    void Score_result();
  void Set_apple_position (Apple& apple, DeadPool& pool);

    int GetWeight();
    int GetLenght();
    DeadPool(int weight = 10, int lenght = 10); 


    void Pool_print(); 
    ~DeadPool(); 

    void Pool_set();

    bool Pool_move(Snake& snake, int& arrow_path, Apple& apple, DeadPool& pool);

    void Set_snake(Snake& snake);

    DeadPool& operator=(DeadPool&);
private:
  
    static short score;
    int past_path;
    int pool_weight;
    int pool_lenght;

    char** deadpool_W_L = new char* [pool_weight];



    friend Apple;
   
    };
















class Snake {

public:

    int snake_lenght=0;


    int snake_spead;


    std::vector<int> snake_positionX = { 1 };
    std::vector<int> snake_positionY = { 1 };


    Snake& operator= (Snake& snake1);
    void Snake_lenght_resize(int arrow);



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

    void Relocation(DeadPool& pool);
    char Get_obj_form();
    int Get_apple_location_X();
    int Get_apple_location_Y();

    Apple(DeadPool& pool);
    ~Apple();


    friend DeadPool;
};