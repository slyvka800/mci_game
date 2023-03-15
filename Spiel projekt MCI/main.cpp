#include "mcigraph.hpp"
#include <stdlib.h>

bool can_move (int new_x, int new_y, int second_person_x, int second_person_y) {
    if (new_x < 0 || new_x > 1012)
        return false;
    if (new_y < -4 || new_y > 755)
        return false;
    if (new_x >= second_person_x-12 && new_x <= second_person_x+12 && new_y >= second_person_y-8 && new_y <= second_person_y+8)
        return false;
    
    return true;
}

int main(int argc, char *argv[]) {
    
    int first_person_x = 300;
    int first_person_y = 200;
    int second_person_x = 800;
    int second_person_y = 400;
    const int step = 8;
    
    while (running()) {
        for (int x = 0; x < 1024; x+=16)
            for (int y = 0; y < 768; y+=16)
                draw_image("tiles/5_0.bmp", x, y);
        
        if (is_pressed(KEY_W) && can_move(first_person_x, first_person_y-step, second_person_x, second_person_y))
            first_person_y -= step;
        if (is_pressed(KEY_S) && can_move(first_person_x, first_person_y+step, second_person_x, second_person_y))
            first_person_y += step;
        if (is_pressed(KEY_A) && can_move(first_person_x-step, first_person_y, second_person_x, second_person_y))
            first_person_x -= step;
        if (is_pressed(KEY_D) && can_move(first_person_x+step, first_person_y, second_person_x, second_person_y))
            first_person_x += step;
        
        if (is_pressed(KEY_UP) && can_move(second_person_x, second_person_y-step, first_person_x, first_person_y))
            second_person_y -= step;
        if (is_pressed(KEY_DOWN) && can_move(second_person_x, second_person_y+step, first_person_x, first_person_y))
            second_person_y += step;
        if (is_pressed(KEY_LEFT) && can_move(second_person_x-step, second_person_y, first_person_x, first_person_y))
            second_person_x -= step;
        if (is_pressed(KEY_RIGHT) && can_move(second_person_x+step, second_person_y, first_person_x, first_person_y))
            second_person_x += step;
        
        draw_image("tiles/char4.bmp", first_person_x, first_person_y);
        draw_image("tiles/char3.bmp", second_person_x, second_person_y);
        present();
    }
    return 0;
}
