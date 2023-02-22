#include <iostream>
#include "DeadPool.h"
#include<thread>
#include"conio.h"


    DeadPool::DeadPool(int weight , int lenght ) :pool_weight(weight), pool_lenght(lenght)
    {
        past_path = 0;
        for (short i = 0; i < pool_weight; i++) {
            deadpool_W_L[i] = new char[pool_lenght];
        }

    }


    void DeadPool::Pool_set() {

        for (int i = 0; i < pool_weight;i++) {

            
            for (int j = 0; j < pool_lenght; j++) {

                if (j==0 || j == (pool_lenght - 1)) {

                    deadpool_W_L[i][j]='#';
                }
                else if (i == 0 || i == (pool_weight - 1)) {

                    deadpool_W_L[i][j] = '#';
                }
                else {

                    deadpool_W_L[i][j] = ' ';
                }


            }
            

        }



    }

    void DeadPool:: Pool_print() {

        system("cls");
        for (int n = 0; n < pool_weight; n++) {


            for (int i = 0; i < (pool_lenght); i++) {

                std::cout << deadpool_W_L[n][i];

            }
            std::cout << std::endl;

        }


    }
   DeadPool:: ~DeadPool() {

        for (int i = 0; i < pool_weight; i++) {
            delete[] deadpool_W_L[i];

        }
    }


   void DeadPool:: Set_snake(Snake& snake) {

       deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = '*';

   }











   bool DeadPool:: Pool_move(Snake& snake, int& arrow_path) {

       if (snake.snake_positionY == pool_weight - 1 ||snake.snake_positionY == 0 ||snake.snake_positionX == pool_lenght - 1|| snake.snake_positionX == 0) {
           deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = '@';
           return false;

       }

      
     
               switch (arrow_path)
               {
               case 72:  // Up arrow
                   if (past_path == 80) { 
                       arrow_path = 80; 
                   deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                   snake.snake_positionY += 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                       snake.snake_positionY -= 1;

                       break;
                   }
               case 80:  // Down arrow
                   if (past_path == 72) { 
                       arrow_path = 72;
                   deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                   snake.snake_positionY -= 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                       snake.snake_positionY += 1;

                       break;
                   }
               case 77:  // Right arrow
                   if (past_path == 75) { 
                       arrow_path = 75; 
                   deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                   snake.snake_positionX -= 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                       snake.snake_positionX += 1;

                       break;
                   }
               case 75:  // Left arrow
                   if (past_path == 77) { 
                       arrow_path = 77; 
                   deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                   snake.snake_positionX += 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY][snake.snake_positionX] = ' ';
                       snake.snake_positionX -= 1;

                       break;
                   }
               }
         
               past_path = arrow_path;
       Set_snake(snake);

       std::this_thread::sleep_for(std::chrono::milliseconds(snake.snake_spead*500));
     
            
      
       return true;
   }

  

