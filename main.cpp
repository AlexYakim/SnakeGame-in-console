#include <iostream>
#include<string>
#include"conio.h"
#include "DeadPool.h"
#include"Snake.h"
#include<chrono>



void Game(DeadPool& pool, Snake& snake);
void Arrow_Path(int& path_status);

   

    int main() {
       
        DeadPool pool(15,20);
        pool.Pool_set();
               
        Snake snake1(1);
        Game(pool, snake1);
       
      
        return 0;
    }


    void Game(DeadPool& pool, Snake& snake) {
        bool integer_for_move = 1;
        int path_status;
        pool.Set_snake(snake);

        pool.Pool_print();
        
        

        while (integer_for_move) {
             Arrow_Path(path_status);
         

            integer_for_move = pool.Pool_move(snake, path_status);
         
           pool.Pool_print();

        }
    }

    void Arrow_Path(int & path_status) {

        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(10)) {
            if (_kbhit()) {
                _getch();
                path_status = _getch();
            }

        }


    }