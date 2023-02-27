
#include "Stack_of_class_for_Game.h"


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
       
           
       for (auto size = 0; size < snake.snake_lenght;size++) {


           deadpool_W_L[snake.snake_positionY[size]][snake.snake_positionX[size]] = '*';
                      
       
       
       }
       
   }
       














   int DeadPool::GetWeight(){
       return pool_weight-1;
   }
  
   
   
   int DeadPool:: GetLenght() {

       return pool_lenght-1;


   }

  


  void DeadPool::Set_apple_position(Apple& apple, DeadPool& pool) {
       
       if (deadpool_W_L[apple.Get_apple_location_Y()][apple.Get_apple_location_X()]==' ') {

           deadpool_W_L[apple.Get_apple_location_Y()][apple.Get_apple_location_X()] = apple.Get_obj_form();

       }
       else {
           bool spawn=true;

           while (spawn) {
               apple.Relocation(pool);
               if (deadpool_W_L[apple.Get_apple_location_Y()][apple.Get_apple_location_X()] == ' ') { 
                   deadpool_W_L[apple.Get_apple_location_Y()][apple.Get_apple_location_X()] = apple.Get_obj_form();
               spawn = false; 
               }
               else {
                   spawn = true;
               }
           }
           
       }
      
   }





   bool DeadPool:: Pool_move(Snake& snake, int& arrow_path, Apple& apple, DeadPool& pool) {

       if (snake.snake_positionY.back() == pool_weight - 1 || snake.snake_positionY.back() == 0 || snake.snake_positionX.back() == pool_lenght - 1 || snake.snake_positionX.back() == 0) {
           deadpool_W_L[snake.snake_positionY.back()][snake.snake_positionX.back()] = '@';
           return false;

       }
       
      

     
               switch (arrow_path)
               {

               case 72:  // Up arrow
                   if (past_path == 80) { 
                       arrow_path = 80; 
                   deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                   for (short size = 0; size < snake.snake_lenght - 1; size++) {
                       snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                       snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                   }
                   snake.snake_positionY. back() = snake.snake_positionY.back()+1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionY.back() = snake.snake_positionY.back() -1;
                       break;
                   }
               case 80:  // Down arrow
                   if (past_path == 72) {
                       arrow_path = 72;
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionY.back() = snake.snake_positionY.back() - 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionY.back() = snake.snake_positionY.back() + 1;
                       break;
                   }
               case 77:  // Right arrow
                   if (past_path == 75) {
                       arrow_path = 75;
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionX.back() = snake.snake_positionX.back() - 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionX.back() = snake.snake_positionX.back() + 1;
                       break;
                   }
               case 75:  // Left arrow
                   if (past_path == 77) { 
                       arrow_path = 77; 
                   deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                   for (short size = 0; size < snake.snake_lenght - 1; size++) {
                       snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                       snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                   }
                   snake.snake_positionX.back() = snake.snake_positionX.back() + 1;
                   break;
                   }
                   else {
                       deadpool_W_L[snake.snake_positionY.front()][snake.snake_positionX.front()] = ' ';
                       for (short size = 0; size < snake.snake_lenght - 1; size++) {
                           snake.snake_positionX[size] = snake.snake_positionX[size + 1];
                           snake.snake_positionY[size] = snake.snake_positionY[size + 1];
                       }
                       snake.snake_positionX.back() = snake.snake_positionX.back() - 1;
                       break;
                   }
               }
       past_path = arrow_path;

      
      

       if (snake.snake_positionX.back() == apple.apple_location_X && snake.snake_positionY.back() == apple.apple_location_Y) {

           
           arrow_path == 75 ? snake.Snake_lenght_resize(75) : arrow_path == 77 ? snake.Snake_lenght_resize(77) : arrow_path == 72 ? snake.Snake_lenght_resize(72) : snake.Snake_lenght_resize(80);
          
          
           apple.Relocation(pool);
           Set_apple_position(apple, pool);

       }

       

       Set_snake(snake);

      
            
       std::this_thread::sleep_for(std::chrono::milliseconds(snake.snake_spead * 400));

       return true;
   }

  

