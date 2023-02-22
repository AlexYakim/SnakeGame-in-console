#pragma once


class Snake {

public:

    int snake_lenght;
    
   
    int snake_spead;
    int snake_positionX = 1;
    int snake_positionY = 1;

    void Snake_lenght_resize(); 



    Snake(double snake_spead); 

    ~Snake();


};