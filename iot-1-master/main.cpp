/*
Brendan Baker
Student Number-->17019052
IoT challenge 1 2020
*/

#include "MicroBit.h"

MicroBit uBit;
int score = 0; //stores players score


int pixel_from_g(int value) //movement of accelerometer
{
    int x =0;

    if (value > -750)
    x++;
    if (value > -250)
    x++;
    if (value > 250)
    x++;
    if (value > 750)
    x++;
    return x;
}

/*
Start Menu
*/
void boot(){

    while (!uBit.buttonA.isPressed() || !uBit.buttonB.isPressed()){

        uBit.display.scroll("HOLD AorB");
        uBit.sleep(1000); //time to respond
        
        if(uBit.buttonA.isPressed() ||uBit.buttonB.isPressed()){ 
            uBit.display.scroll("3 2 1"); //Print countdown to game
            break; //break the loop into the main
        }

  }       
}

/*
Main Game function
*/

void level1()
{
    int item_x;
    int item_y;
    int item2_x;
    int item2_y;

    item_x = rand() % 5; //Random position of food on LED
    item_y = rand() % 5;
    item2_x = rand() %5; 
    item2_y = rand() %5;
    unsigned long now = uBit.systemTime();
    unsigned long current; //store time

    while(1)
    {
        
        int x = pixel_from_g(uBit.accelerometer.getX());
        int y = pixel_from_g(uBit.accelerometer.getY());

        uBit.display.image.clear();
        current = uBit.systemTime(); //Stored adter each iteration

        uBit.display.image.setPixelValue(x, y, 255); //Display x and y,brightness
        uBit.sleep(75);
        uBit.display.image.setPixelValue(item2_x, item2_y,25);

        uBit.sleep(100);

        if(current > now + 60000){ //If game has lasted longer than 60 seconds
            break; //break into gameover
        }

        if(current >= now + 30000){ // Equal or more than 30 seconds
            uBit.display.image.setPixelValue(item_x,item_y,25); //Add new item
            uBit.sleep(100); //flash item
            
        }
        
        if(x == item_x && y == item_y ||x == item2_x && y == item2_y){ //If they share the same coordinates
            score++; //Add score
            item_x = rand()%5; //Random psotion each time when collected
            item_y = rand()%5;
            item2_y = rand()%5; //Random psotion each time when collected
            item2_x = rand()%5;
        } 
    }
}

void gameover() //Called when time reaches 60 seconds
{ 
    uBit.display.scroll("GAME OVER SCORE");
    uBit.display.scroll(score); //displays score
    uBit.sleep(200);
    uBit.reset(); //Back to boot menu
    }


int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE); //display mode where you can adjust brightness
    boot(); //Calling the boot menu
    level1(); //call the game
    gameover(); //call game over

 release_fiber();

}