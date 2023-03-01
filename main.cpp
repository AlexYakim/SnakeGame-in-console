#include<string>
#include "Stack_of_class_for_Game.h"
#include<chrono>
#include<array>


void Game(DeadPool& pool, Snake& snake, Apple apple);
void Arrow_Path(int& path_status);

   


void Select_menu_function(short& pool_weight_set, short& pool_lenght_set);
void Select_menu_function(short& snake_spead_set);
void Print_Game_Logo();
void Print_Game_Logo(const int delay); 


    int main() {

        
       
        short pool_weight_set,pool_lenght_set, snake_spead_set;
        Print_Game_Logo(750);
        Select_menu_function(pool_weight_set, pool_lenght_set);
        Select_menu_function(snake_spead_set);
        
        

        
        DeadPool pool(pool_weight_set, pool_lenght_set);
        Apple apple(pool);
        Snake snake1(snake_spead_set);
        Game(pool, snake1, apple);
       
      
        return 0;
    }




















    void Game(DeadPool& pool, Snake& snake, Apple apple) {
        bool integer_for_move = 1;
        int path_status;
        

        pool.Pool_set();
        pool.Set_snake(snake);
        pool.Set_apple_position(apple, pool);

        pool.Pool_print();
       
        

        while (integer_for_move) {
             Arrow_Path(path_status);
         

            integer_for_move = pool.Pool_move(snake, path_status,apple,pool);
         
           pool.Pool_print();
           std::cout << "\nChoose directions using the arrows to start moving" << std::endl;

           if (integer_for_move == false) {
               
               std::cout << "\n Do you want to try again? (y/n) ";
               char answer;
               std::cin >> answer;
               if (answer =='y'|| answer=='Y') { 
                   integer_for_move = true;
                   path_status = 0;
                   Snake snake1(snake.snake_spead);
                   snake = snake1;
                   DeadPool pool1(pool.GetWeight(),pool.GetLenght());
                   pool = pool1;
                   pool.Pool_set();
                   pool.Set_apple_position(apple,pool);
                   system("cls");
               }
               else if(answer == 'n' || answer == 'N'){ 
                   integer_for_move = false;
                   
                   system("cls");
               }
              
           }

        }
        std::cout << "\n\t I hope to see you again\n";
    }
















    void Arrow_Path(int & path_status) {

        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start_time < std::chrono::milliseconds(100)) {
            if (_kbhit()) {
                path_status = _getch();
                if (path_status == 224) {
                    path_status = _getch();
                }
            }

        }
       

    }

    void Select_menu_function(short& pool_weight_set, short& pool_lenght_set) {
        

        std::array<std::string, 3> size_of_pool{ "->","  ","  " };

        bool select_menu_logic = true;
        system("cls");
        int arrow = 0;
        do {
            Print_Game_Logo();
            std::cout << "\n\tWelcome to the Snake game created by Yakim Software\n" << std::endl << "\tSelect pool size:\n" << std::endl;

            std::cout << "\t" << size_of_pool.at(0) << " 10:15" << "\t" << size_of_pool.at(1) << " 15:20" << "\t" << size_of_pool.at(2) << " 25:25\n";

            Arrow_Path(arrow);
            if (arrow == 77) {
                std::swap(size_of_pool.at(1), size_of_pool.at(2));
                std::swap(size_of_pool.at(0), size_of_pool.at(1));
                arrow = 0;
            }
            else if (arrow == 75) {
                std::swap(size_of_pool.at(0), size_of_pool.at(1));
                std::swap(size_of_pool.at(1), size_of_pool.at(2));
                arrow = 0;
            }

            if (arrow == 13 && size_of_pool.at(0) == "->") {

                pool_weight_set = 10;
                pool_lenght_set = 15;
                select_menu_logic = false;
            }
            else if (arrow == 13 && size_of_pool.at(1) == "->") {
                pool_weight_set = 15;
                pool_lenght_set = 20;
                select_menu_logic = false;
            }
            else if (arrow == 13 && size_of_pool.at(2) == "->") {
                pool_weight_set = 25;
                pool_lenght_set = 25;
                select_menu_logic = false;
            }




            system("cls");
        } while (select_menu_logic);





    }

    void Select_menu_function(short& snake_spead_set) {


        std::array<std::string, 3> size_of_pool{ "->","  ","  " };

        bool select_menu_logic = true;
        int arrow = 0;
        system("cls");
        do {
            Print_Game_Logo();
            std::cout << "\n\tWelcome to the Snake game created by Yakim Software\n" << std::endl << "\tSelect snake speed:\n" << std::endl;

            std::cout << "\t" << size_of_pool.at(0) << " first speed" << "\t" << size_of_pool.at(1) << " second speed" << "\t" << size_of_pool.at(2) << " third speed\n";

            Arrow_Path(arrow);
            if (arrow == 77) {
                std::swap(size_of_pool.at(1), size_of_pool.at(2));
                std::swap(size_of_pool.at(0), size_of_pool.at(1));
                arrow = 0;
            }
            else if (arrow == 75) {
                std::swap(size_of_pool.at(0), size_of_pool.at(1));
                std::swap(size_of_pool.at(1), size_of_pool.at(2));
                arrow = 0;
            }

            if (arrow == 13 && size_of_pool.at(0) == "->") {

                snake_spead_set = 3;
                select_menu_logic = false;
            }
            else if (arrow == 13 && size_of_pool.at(1) == "->") {
                snake_spead_set = 2;
                select_menu_logic = false;
            }
            else if (arrow == 13 && size_of_pool.at(2) == "->") {
                snake_spead_set = 1;
                select_menu_logic = false;
            }




            system("cls");
        } while (select_menu_logic);





    }

    void Print_Game_Logo(const int delay) {

        std::string snakeGame_logo[6] = { "\t   _____             _         _____                       ",
                                              "\t  / ____|           | |       / ____|                      ",
                                              "\t | (___  _ __   __ _| | _____| |  __  __ _ _ __ ___   ___  ",
                                              "\t  \\___ \\| '_ \\ / _` | |/ / _ \\ | |_ |/ _` | '_ ` _ \\ / _ \\ ",
                                              "\t  ____) | | | | (_| |   <  __/ |__| | (_| | | | | | |  __/ ",
                                              "\t |_____/|_| |_|\\__,_|_|\\_\\___|\\_____|\\__,_|_| |_| |_|\\___| " };

        for (short logo_size = 0; logo_size < sizeof(snakeGame_logo) / sizeof(snakeGame_logo[0]); logo_size++) {

            std::cout << snakeGame_logo[logo_size] << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }

    }

    void Print_Game_Logo() {

        std::string snakeGame_logo[6] = { "\t   _____             _         _____                       ",
                                              "\t  / ____|           | |       / ____|                      ",
                                              "\t | (___  _ __   __ _| | _____| |  __  __ _ _ __ ___   ___  ",
                                              "\t  \\___ \\| '_ \\ / _` | |/ / _ \\ | |_ |/ _` | '_ ` _ \\ / _ \\ ",
                                              "\t  ____) | | | | (_| |   <  __/ |__| | (_| | | | | | |  __/ ",
                                              "\t |_____/|_| |_|\\__,_|_|\\_\\___|\\_____|\\__,_|_| |_| |_|\\___| " };

        for (short logo_size = 0; logo_size < sizeof(snakeGame_logo) / sizeof(snakeGame_logo[0]); logo_size++) {

            std::cout << snakeGame_logo[logo_size] << std::endl;
            
        }

    }
