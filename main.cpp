#include "mbed.h"
#include "LM75B.h"
#include "C12832.h"
#include <cstdlib>


DigitalOut myled(LED1);
DigitalIn U(p15);
DigitalIn D(p12);
DigitalIn R(p16);
DigitalIn L(p13);

C12832 lcd(p5, p7, p6, p8, p11);

int ball_x = lcd.width()/2;
int ball_y = lcd.height()/2;

int height = lcd.height() -1;
int width = lcd.width() -1;

int direction_x=0;
int direction_y=0;

int cible_x = lcd.width()/1.5;
int cible_y = lcd.height()/1.5;
int score =0;

int temps_niveau = 60;
int temps_restant = temps_niveau;
float temps_ecoule = 0;
float delai_it =0.05;

int niveau =1;

/*
void temps(){
    for (int i = t ; i>=0 ; i--){
        sleep()
         lcd.locate(0,15);
         lcd.printf("temps: %.2d", i);
        if (i==0){
            win = false;
        }
    }
} 
*/
void mouvement(){
    if(D){
        direction_y = 1;
        direction_x = 0;
    }else if(U){
        direction_y = -1;
        direction_x = 0;
   
    }else if(R){
        direction_x = 1;
        direction_y = 0;
    }else if(L){
        direction_x=-1;
        direction_y = 0;
    }

}
void deplacerBalle() {
    ball_x+= direction_x;
    ball_y+=direction_y;
    if(ball_x<=0){
        direction_x =1;
    }else if(ball_x>=width){
        direction_x =-1;
    }
    if(ball_y<=0){
        direction_y =1;
    }else if(ball_y>=height){
        direction_y =-1;
    }

}



bool toucher(){
    int zone_x_min = cible_x - 5 ;
    int zone_x_max = cible_x + 5 ;
    int zone_y_min = cible_y - 5 ;
    int zone_y_max = cible_y + 5 ;

    if(ball_x>=zone_x_min && ball_x<=zone_x_max && ball_y>=zone_y_min && ball_y<=zone_y_max){
        return true;
    }else{return false;}


}

int main(){
    float temps_depart =0;
    while(true){
        mouvement();
        deplacerBalle();
         temps_ecoule += delai_it;
         float temps_niveau_ecoule = temps_ecoule - temps_depart;
         temps_restant = temps_niveau - (unsigned int)temps_niveau_ecoule;
        if(temps_restant<=0){
            lcd.cls();
            lcd.locate(width/2, height/2);
            lcd.printf("GAME OVER");
            wait(5);
            break;
        }
        if(toucher()){
            score++; 
            lcd.cls();
            direction_x =0;
            direction_y=0;

            niveau++;
            temps_niveau-=10;
            if(temps_niveau< 10){
                temps_niveau=10;
            }
            temps_depart = temps_ecoule;
            temps_restant = temps_niveau;
            cible_x = rand() % width;
            cible_y = rand() % height;

        }
        lcd.cls();
        lcd.locate(0,0);
        lcd.printf("score: %.2d", score);

        lcd.locate(80,0);
        lcd.printf("Temps: %d", temps_restant);
        
        lcd.fillcircle(cible_x, cible_y, 3, 1);
        lcd.fillcircle(ball_x,ball_y,2,1);
        
        wait(0.05);
        
        
    }

}