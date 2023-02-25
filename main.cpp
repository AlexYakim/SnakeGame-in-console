#include<string>
#include "Stack_of_class_for_Game.h"
#include<chrono>



void Game(DeadPool& pool, Snake& snake,Apple& apple);
void Arrow_Path(int& path_status);

   









    int main() {
       
        DeadPool pool(15,20);
        pool.Pool_set();
        Apple apple(pool);
        Snake snake1(1);
        Game(pool, snake1, apple);
       
      
        return 0;
    }




















    void Game(DeadPool& pool, Snake& snake, Apple& apple) {
        bool integer_for_move = 1;
        int path_status;

        pool.Set_snake(snake);

        pool.Pool_print();
        pool.Set_apple_position(apple,pool);
        

        while (integer_for_move) {
             Arrow_Path(path_status);
         

            integer_for_move = pool.Pool_move(snake, path_status,apple);
         
           pool.Pool_print();

        }
    }
















    void Arrow_Path(int & path_status) {

        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(100)) {
            if (_kbhit()) {
                _getch();
                path_status = _getch();
            }

        }
       

    }