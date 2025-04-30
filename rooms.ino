#include <Gamebuino-Meta.h>



void room01(){
    gb.display.clear();
  
    doorNordExist = true;
    doorSudExist = true;
    doorEstExist = true;
    doorOuestExist = true;

    // doorNordIsOpen = false;
    // doorSudIsOpen = false;
    // doorEstIsOpen = false;
    // doorOuestIsOpen = false;

    // int x, int y, int largeur, int hauteur
  
    // Mur nord
    gb.display.fillRect(0, 0, gb.display.width(), MUR_HAUTEUR);
  
    // Mur sud
    gb.display.fillRect(0, 64 - MUR_HAUTEUR, gb.display.width(), MUR_HAUTEUR);
  
    // Mur est
    gb.display.fillRect(80 - MUR_LARGEUR, 0, MUR_LARGEUR, gb.display.height());
  
    // Mur ouest
    gb.display.fillRect(0, 0, MUR_LARGEUR, gb.display.height());

    // Porte ouest
    if (doorOuestExist) {
        if (doorOuestIsOpen == false) {
            gb.display.setColor(BROWN);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(0, 22, MUR_LARGEUR, 20);
    }

    // Porte nord
    if (doorNordExist) {
        if (doorNordIsOpen == false) {
            gb.display.setColor(BROWN);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(30, 0, 20, MUR_HAUTEUR);
    }

    // Porte est
    if (doorEstExist) {
        if (doorEstIsOpen == false) {
            gb.display.setColor(BROWN);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(gb.display.width() - MUR_LARGEUR, 22, MUR_LARGEUR, 20);
    }

    // Porte sud
    if (doorSudExist) {
        if (doorSudIsOpen == false) {
            gb.display.setColor(BROWN);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(30, gb.display.height() - MUR_HAUTEUR, 20, MUR_HAUTEUR);
    }

    gb.display.setColor(WHITE);
  }