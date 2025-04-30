// BlueCube.ino //
#include <Gamebuino-Meta.h>


// Caractèristiques murs
  // int raquetteX;
  // const int MUR_Y = 58;
  const int MUR_LARGEUR = 2;
  const int MUR_HAUTEUR = 2;

  // Caractéristiques joueur
  int joueurX = 50;
  int joueurY = 50;
  int joueurVX;
  int joueurVY;
  const int JOUEUR_TAILLE = 3;

  bool doorNordExist = false;
  bool doorSudExist = false;
  bool doorEstExist = false;
  bool doorOuestExist = false;
  
  bool doorNordIsOpen = false;
  bool doorSudIsOpen = false;
  bool doorEstIsOpen = false;
  bool doorOuestIsOpen = false;
  


void setup() {
  gb.begin();
}

void loop() {
  while (!gb.update());
  // INPUTS //
  entrees();

  // LOGIC //
  miseAJour();

  // DRAW //
  affichage();
}


// entrees.ino //
void entrees() {

  if (gb.buttons.pressed(BUTTON_A)) {
    doorNordIsOpen = !doorNordIsOpen;
    doorSudIsOpen = !doorSudIsOpen;
    doorEstIsOpen = !doorEstIsOpen;
    doorOuestIsOpen = !doorOuestIsOpen;
}



  // Mouvement Gauche
  if (gb.buttons.repeat(BUTTON_LEFT, 1) && joueurX <= 0 + MUR_LARGEUR 
  && joueurY > 22 && (joueurY < 43 - JOUEUR_TAILLE) && doorOuestExist && doorOuestIsOpen) {
    joueurX -= 1;
  } else if (gb.buttons.repeat(BUTTON_LEFT, 1) && joueurX > 0 + MUR_LARGEUR) {
    joueurX -= 1;
  }
  
  // Mouvement Droite
  if (gb.buttons.repeat(BUTTON_RIGHT, 1) && joueurX >= gb.display.width() - (MUR_LARGEUR + JOUEUR_TAILLE) 
  && joueurY > 22 && (joueurY < 43 - JOUEUR_TAILLE) && doorEstExist && doorEstIsOpen) {
    joueurX += 1;
  } else if (gb.buttons.repeat(BUTTON_RIGHT, 1) && joueurX < gb.display.width() - (MUR_LARGEUR + JOUEUR_TAILLE)) {
    joueurX += 1;
  }
  
  // Mouvement Haut
  if (gb.buttons.repeat(BUTTON_UP, 1) && joueurY <= 0 + MUR_HAUTEUR && joueurX > 30 && (joueurY < 51 - JOUEUR_TAILLE) 
      && doorNordExist && doorNordIsOpen) {
    joueurY -= 1;
  } else if (gb.buttons.repeat(BUTTON_UP, 1) && joueurY > 0 + MUR_HAUTEUR) {
    joueurY -= 1;
  }
  
  // Mouvement Bas
  if (gb.buttons.repeat(BUTTON_DOWN, 1) && joueurY >= gb.display.height() - (MUR_HAUTEUR + JOUEUR_TAILLE) 
  && joueurX > 22 && (joueurX < 51 - JOUEUR_TAILLE) && doorSudExist && doorSudIsOpen) {
    joueurY += 1;
  } else if (gb.buttons.repeat(BUTTON_DOWN, 1) && joueurY < gb.display.height() - (MUR_HAUTEUR + JOUEUR_TAILLE)) {
    joueurY += 1;
  }



}


// miseAJour.ino //
void miseAJour() {

  if (joueurX + JOUEUR_TAILLE < 0) {
    joueurX = 50;
  }

  // // Collision avec les murs
  // if (gb.collideRectRect(joueurX, joueurY, JOUEUR_TAILLE, JOUEUR_TAILLE,
  //                       0, 0, gb.display.width(), MUR_HAUTEUR)) {
  //   balleVY = -1;  // Haut
  // }

  

  // // MAJ Balle
  // joueurX += joueurVX;
  // joueurY += joueurVY;

  // // Collisions avec les murs
  // if (balleX < 0 || balleX > gb.display.width() - BALLE_TAILLE) {
  //   balleVX *= -1;
  // }
  // if (balleY < 0) {
  //   balleVY *= -1;
  // }
  // else if (balleY > gb.display.height()) {
  //   reinitialiser();
  // }

  // // Collision avec la raquette
  // if (gb.collideRectRect(balleX, balleY, BALLE_TAILLE, BALLE_TAILLE,
  //                         raquetteX, RAQUETTE_Y, RAQUETTE_LARGEUR, RAQUETTE_HAUTEUR)) {
  //   balleVY = -1;  // Haut
  // }

  //  // Collisions avec les briques
  //  for (int rangee = 0; rangee < GRILLE_TAILLE; rangee += 1) {
  //   for (int colonne = 0; colonne < GRILLE_TAILLE; colonne += 1) {
  //     if (briques[rangee][colonne] == 0) {  // Ignorer les briques nulles
  //       continue;
  //     }

  //     int briqueX = colonne * (BRIQUE_LARGEUR + 2) + 1;
  //     int briqueY = rangee * (BRIQUE_HAUTEUR + 2) + 1;
  //     if (gb.collide.rectRect(balleX, balleY, BALLE_TAILLE, BALLE_TAILLE,
  //                             briqueX, briqueY, BRIQUE_LARGEUR, BRIQUE_HAUTEUR)) {
  //       balleVY *= -1;
  //       briques[rangee][colonne] = 0;  // Détruire la brique

  //       // Verifier qu'il reste encore des briques
  //       bool plusDeBriques = true;  // Si cet entier reste vrai, alors il n'y a plus de briques
  //       for (int x = 0; x < GRILLE_TAILLE; x += 1) {
  //         for (int y = 0; y < GRILLE_TAILLE; y += 1) {
  //           if (briques[y][x] == 0) {  // On a trouvé une brique!
  //             plusDeBriques = false;  // ne pas reinitialiser
  //           }
  //         }
  //       }

  //       if (plusDeBriques) {
  //           reinitialiser();
  //       }
  //     }

  //   }
  // }
}

// affichage.ino //
void affichage() {

  gb.display.clear();

  
  // int x, int y, int largeur, int hauteur

  room01();
  // // Mur nord
  // gb.display.fillRect(0, 0, gb.display.width(), MUR_HAUTEUR);

  // // Mur sud
  // gb.display.fillRect(0, 64 - MUR_HAUTEUR, gb.display.width(), MUR_HAUTEUR);

  // // Mur est
  // gb.display.fillRect(80 - MUR_LARGEUR, 0, MUR_LARGEUR, gb.display.height());

  // // Mur ouest
  // gb.display.fillRect(0, 0, MUR_LARGEUR, gb.display.height());
  
  // Joueur
  gb.display.fillRect(joueurX, joueurY, JOUEUR_TAILLE, JOUEUR_TAILLE);

  gb.display.setCursor(35, 15);
  gb.display.print(joueurX);
  gb.display.setCursor(48, 15);
  gb.display.print(joueurY);
  
      // for (int rangee = 0; rangee < GRILLE_TAILLE; rangee += 1) {
      //   for (int colonne = 0; colonne < GRILLE_TAILLE; colonne += 1) {
      //     if (briques[rangee][colonne] == 0) {
      //       continue;
      //     }
    
      //     int briqueX = colonne * (BRIQUE_LARGEUR + 2) + 1;
      //     int briqueY = rangee * (BRIQUE_HAUTEUR + 2) + 1;
      //     gb.display.fillRect(briqueX, briqueY, BRIQUE_LARGEUR, BRIQUE_HAUTEUR);
      //   }
      // }
    }
  
   
  