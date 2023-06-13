/* 
 * Taran's share of his code for 4075CEM.
 * This is for calculations of how long x has elapsed
 * and the players movement based on their keypresses */

#ifndef TARAN_SHARE_H
#define TARAN_SHARE_H
#define author "Taran Nagra"
#define student_id 12169388

// Builtin headerfiles to C++
#include <iostream>
#include <chrono>

/*
 * This header file is for the time
 * and movement based on the user's position
 * in the game. Without this file, 
 * the user will not be able to move or interact.
*/

class TimeAndMovement { // making a class to store private varables and publicly accessible methods
    private:
        struct KeyEvents { // structure to house the different booleans that will be needed soon
            bool is_pressed;
            bool is_released;
            bool is_being_held;
        } all_keys[255], mouse[5];
        
        // defining the float variables for the class
        float player_x;
        float player_y;
        float player_speed;
        float player_location;
        
        // defining the timer and the total time variable for the class
        static time_t time1 = std::chrono::system_clock::now();
        static time_t time2 = std::chrono::system_clock::now();
        std::chrono::duration<float> time_so_far = time2 - time1;
        float elapsed_time = time_so_far.count();

    public:
        void on_user_update(float time_so_far) { // public accessible method to detect user keypress update
            // Moves the user left
            if (all_keys[L'A'].is_being_held) 
                player_location += (player_speed * 0.6) * time_so_far;

            // Moves the user right
            if (all_keys[L'D'].is_being_held) 
                player_location = player_location + (player_speed * 0.6) * elapsed_time;

            // Moves the user forward!
            if (all_keys[L'W'].is_being_held) {
                player_x = player_x + (player_location) * player_speed * elapsed_time;
                player_y = player_y + (player_location) * player_speed * elapsed_time;
            }
            // Moves the user backwards! :(
            if (all_keys[L'S'].is_being_held) {        
                player_x = player_x - (player_location) * player_speed * elapsed_time;
                player_x = player_x - (player_location) * player_speed * elapsed_time;
            }
            // When pressing 1, you can move left and forward at the same time!
            if (all_keys[L'1'].is_being_held) { 
                player_x = player_x + (player_location) * player_speed * elapsed_time;
                player_x = player_x - (player_location) * player_speed * elapsed_time;
            }
            // When pressing 3, you can move right and forward at the same time!
            if (all_keys[L'3'].is_being_held) { 
                player_x = player_x - (player_location) * player_speed * elapsed_time;
                player_x = player_x + (player_location) * player_speed * elapsed_time;
            }

        }
};


#endif // end the ifndef at the top
