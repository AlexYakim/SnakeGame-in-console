#pragma once
#include"Snake.h"

class DeadPool {

    
public:
     
    
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

    };


