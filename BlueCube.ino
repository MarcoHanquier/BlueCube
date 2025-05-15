// BlueCube.ino //
#include <Gamebuino-Meta.h>
#include "./assets/avatar.h"
#include "./assets/menus.h"
#include "./assets/assets.h"

extern const uint8_t font3x3[];

// Todo
// Effets pièces
// Ajout mécaniques antichambre
// Objets
// Boutiques
// Assets pour chaque pièce

Image menu(BLUEPRINT_MENU_DATA);
Image paper(PAPER_ICON_DATA);
Image paperSheet(PAPER_SPRITE_DATA);


struct s_room{
  int roomNumber; String roomName; String roomType; 
  bool doorNordExist; bool doorSudExist; bool doorEstExist; bool doorOuestExist;
  bool doorNordIsOpen; bool doorSudIsOpen; bool doorEstIsOpen; bool doorOuestIsOpen;
  s_room* roomNord; s_room* roomSud; s_room* roomEst; s_room* roomOuest;
  bool isRoomInThePool;};

s_room room1;
s_room room2;
s_room room3;
s_room room4;
s_room room5;
s_room room6;
s_room room7;
s_room room8;
s_room room9;
s_room room10;
s_room room11;
s_room room12;
s_room room13;
s_room room14;
s_room room15;
s_room room16;
s_room room17;
s_room room18;
s_room room19;
s_room room20;
s_room room21;
s_room room22;
s_room room23;
s_room room24;
s_room room25;
s_room room26;
s_room room27;
s_room room28;
s_room room29;
s_room room30;
s_room room31;
s_room room32;
s_room room33;
s_room room34;
s_room room35;
s_room room36;
s_room room37;
s_room room38;
s_room room39;
s_room room40;
s_room room41;
s_room room42;
s_room room43;
s_room room44;
s_room room45;
s_room room46;
s_room room47;
s_room room48;
s_room room49;
s_room room50;
s_room room51;
s_room room52;
s_room room53;
s_room room54;
s_room room55;
s_room room56;
s_room room57;
s_room room58;
s_room room59;
s_room room60;
s_room room61;

s_room* roomPool[61] = {&room1, &room2, &room3, &room4, &room5, &room6, &room7, &room8, &room9, &room10,
                        &room11, &room12, &room13, &room14, &room15, &room16, &room17, &room18, &room19, &room20,
                        &room21, &room22, &room23, &room24, &room25, &room26, &room27, &room28, &room29, &room30,
                        &room31, &room32, &room33, &room34, &room35, &room36, &room37, &room38, &room39, &room40,
                        &room41, &room42, &room43, &room44, &room45, &room46, &room47, &room48, &room49, &room50,
                        &room51, &room52, &room53, &room54, &room55, &room56, &room57, &room58, &room59, &room60,
                        &room61};

int numberOfRoomsInThePool = 61;

s_room *currentRoom;

s_room *roomChoiceOne;
s_room *roomChoiceTwo;
s_room *roomChoiceThree;
s_room *newRoomChoice;
s_room *rotatedRoom1;
s_room *rotatedRoom2;
s_room *rotatedRoom3;
s_room *displayedRoom;

s_room *baseRoom1;
s_room *baseRoom2;
s_room *baseRoom3;

// Caractèristiques murs
  const int MUR_LARGEUR = 2;
  const int MUR_HAUTEUR = 2;

// Position pièce
  int roomY = 8;
  int roomX = 2;

  // Caractéristiques joueur
  int joueurX = 40;
  int joueurY = 32;
  const int JOUEUR_TAILLE = 3;
  String direction = "";

  const uint8_t AVATAR_WIDTH  = SPRITE_DATA[0];
  const uint8_t AVATAR_HEIGHT = SPRITE_DATA[1];
  const uint8_t AVATAR_FRAMES = SPRITE_DATA[2];
  const int8_t AVATAR_SPEED =  2;


struct Avatar {

  int16_t x, y;
  uint8_t frame;
  int8_t  orientation;
  Avatar(int16_t x, int16_t y) 
  : x(x)
  , y(y)
  , frame(0)
  , orientation(1)
  {}

  void moveToLeft() {
    joueurX -= 1;
    orientation = -1;
    ++frame %= AVATAR_FRAMES;
  }

  void moveToRight() {
      joueurX += 1;
      orientation = 1;
      ++frame %= AVATAR_FRAMES;
  }

  void moveToUp() {
    joueurY -= 1;
    ++frame %= AVATAR_FRAMES;
  }

  void moveToDown() {
    joueurY += 1;
    ++frame %= AVATAR_FRAMES;
  }

  void draw() {
    Image sprite(SPRITE_DATA);
    sprite.setFrame(frame);
    gb.display.drawImage(joueurX, joueurY, sprite, orientation * AVATAR_WIDTH, AVATAR_HEIGHT);
  }
};

  Avatar avatar(joueurX, joueurY);

  // Stats joueur

  int day = 1;
  int steps = 50;
  int keys = 0;
  int gems = 0;
  int dice = 0;
  int gold = 0;

  int numberOfRooms = 2;
  int numberOfBedrooms = 0;
  int numberOfGardens = 0;
  int numberOfHallways = 0;
  int numberOfRedRooms = 0;
  int numberOfShops = 0;
  
  String roomName = "";
  String roomType = "";

  int houseMap[9][5] = { 
    {0, 0, 60, 0, 0},
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 1, 0, 0}
  };

void callItADay(){
  // Reset stats
  steps = 50;
  keys = 0;
  gems = 0;
  dice = 0;
  gold = 0;
  day++;

  joueurX = 40;
  joueurY = 32;

  roomY = 8;
  roomX = 2;

  int numberOfRooms = 2;
  int numberOfBedrooms = 0;
  int numberOfGardens = 0;
  int numberOfHallways = 0;
  int numberOfRedRooms = 0;
  int numberOfShops = 0;

  // Reset tableau pièces
  int resetMap[9][5] = {
    {0, 0, 60, 0, 0},
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 1, 0, 0}
  };

  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 5; x++) {
      houseMap[y][x] = resetMap[y][x];
    }
  }

  // Reset pièces
  initialiseRooms();
  startRoom();
}


void setup() {
  gb.display.setFont( font3x3 );
 
  initialiseRooms();
  startRoom();

  gb.begin();
}

void startRoom() {
  currentRoom = &room1;
  room60.roomNord = &room61;
  room61.roomSud = &room60;
  roomName = currentRoom->roomName;
  gb.display.clear();
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
    doorOpening();
  }

  // Mouvement Gauche
  if (gb.buttons.repeat(BUTTON_LEFT, 1) && joueurX <= 0 + MUR_LARGEUR 
  && joueurY >= 22 && (joueurY < 43 - JOUEUR_TAILLE) && currentRoom->doorOuestExist && currentRoom->doorOuestIsOpen) { 
    avatar.moveToLeft();

  } else if (gb.buttons.repeat(BUTTON_LEFT, 1) && joueurX > 0 + MUR_LARGEUR) { 
    avatar.moveToLeft();

  }
  
  // Mouvement Droite
  if (gb.buttons.repeat(BUTTON_RIGHT, 1) && joueurX >= gb.display.width() - (MUR_LARGEUR + AVATAR_WIDTH) 
  && joueurY >= 22 && (joueurY < 43 - AVATAR_HEIGHT) && currentRoom->doorEstExist && currentRoom->doorEstIsOpen) {
    avatar.moveToRight();

  } else if (gb.buttons.repeat(BUTTON_RIGHT, 1) && joueurX < gb.display.width() - (MUR_LARGEUR + AVATAR_WIDTH)) {
    avatar.moveToRight();

  }
  

  // Mouvement Haut
  if (gb.buttons.repeat(BUTTON_UP, 1) && joueurY <= 0 + MUR_HAUTEUR 
  && joueurX >= 30 && (joueurX < 51 - AVATAR_WIDTH) && currentRoom->doorNordExist && currentRoom->doorNordIsOpen) {
    avatar.moveToUp();

  } else if (gb.buttons.repeat(BUTTON_UP, 1) && joueurY > 0 + MUR_HAUTEUR) {
    avatar.moveToUp();

  }
  
  // Mouvement Bas
  if (gb.buttons.repeat(BUTTON_DOWN, 1) && joueurY >= gb.display.height() - (MUR_HAUTEUR + AVATAR_HEIGHT) 
  && joueurX >= 30 && (joueurX < 51 - AVATAR_WIDTH) && currentRoom->doorSudExist && currentRoom->doorSudIsOpen) {
    avatar.moveToDown();

  } else if (gb.buttons.repeat(BUTTON_DOWN, 1) && joueurY < gb.display.height() - (MUR_HAUTEUR + AVATAR_HEIGHT)) {
    avatar.moveToDown();

  }

  // Menu
  if (gb.buttons.pressed(BUTTON_MENU)) {
    displayMenu();
  } 
}

// miseAJour.ino //
void miseAJour() {

  // Sortie Salle gauche
  if (joueurX < 0) {
    if (houseMap[roomY][roomX -1] != 0)
    roomX -= 1;
    steps -= 1;
    joueurX = 75;
    currentRoom = currentRoom->roomOuest;
  }

  // Sortie Salle droite
  if (joueurX > gb.display.width() - JOUEUR_TAILLE) {
    if (houseMap[roomY][roomX +1] != 0)
    roomX += 1;
    steps -= 1;
    joueurX = 2;
    currentRoom = currentRoom->roomEst;
  }

  // Sortie Salle haut
  if (joueurY < 0 ) {
    if (houseMap[roomY-1][roomX] != 0)
    roomY -= 1;
    steps -= 1;
    joueurY = 59;
    currentRoom = currentRoom->roomNord;
  } 

  // Sortie Salle bas
  if (joueurY + JOUEUR_TAILLE > gb.display.height()) {
    if (houseMap[roomY+1][roomX] != 0)
    roomY += 1;
    steps -= 1;
    joueurY = 2;
    currentRoom = currentRoom->roomSud;
  }
  roomName = currentRoom->roomName;

}

// affichage.ino //
void affichage() {

  gb.display.clear();

  generateCurrentRoom();

  gb.display.setColor(WHITE);

  gb.display.setCursor(4, 55);
  
  if(currentRoom->roomName == "Antichambre"){
    gb.display.setColor(BLACK);
  }
  gb.display.print(currentRoom->roomName);
  gb.display.setColor(WHITE);

  if(currentRoom->roomName == "Piece ???"){
    finalRoom();
  }

  avatar.draw();

}


void displayMenu(){
    
  int cursorPosition = 35;
  int selection = 1;
  int rightMenuX = 30;

  while(1) {
  while(!gb.update());
    gb.display.clear();
    gb.display.drawImage(0, 0, menu);
    displayMiniMap();
    if (gb.buttons.pressed(BUTTON_MENU) || gb.buttons.pressed(BUTTON_B) ) {
      return;
    } 
  
    if(gb.buttons.pressed(BUTTON_A)){
      callItADay();
    return;
    }
    gb.display.setCursor(rightMenuX, 5);
    gb.display.print("Jour");
    
    gb.display.setCursor(rightMenuX +18, 5);
    gb.display.print(day);
    
    gb.display.setCursor(rightMenuX, 12);
    gb.display.print("Pas :");
    
    gb.display.setCursor(rightMenuX+20, 12);
    gb.display.print(steps);
    
    gb.display.setCursor(rightMenuX, 19);
    gb.display.print("Cles :");
    
    gb.display.setCursor(rightMenuX+32, 19);
    gb.display.print(keys);
    
    gb.display.setCursor(rightMenuX, 26);
    gb.display.print("Argent :");
    
    gb.display.setCursor(rightMenuX+32, 26);
    gb.display.print(gold);
    
    gb.display.setCursor(rightMenuX, 34);
    gb.display.print("A:Dormir");
  }
}

void doorOpening(){
  if (joueurY == gb.display.height() - (MUR_HAUTEUR + AVATAR_HEIGHT) && joueurX >= 30 && (joueurX < 51 - AVATAR_WIDTH) 
  && currentRoom->doorSudExist && !currentRoom->doorSudIsOpen) { // Porte bas
    direction = "Sud";
    generateNewRoom();
    currentRoom->doorSudIsOpen = true;
  } 
  if (joueurY == 0 + MUR_HAUTEUR && joueurX >= 30 && (joueurX < 51 - AVATAR_WIDTH) 
  && currentRoom->doorNordExist && !currentRoom->doorNordIsOpen) { // Porte haut
    direction = "Nord";
    generateNewRoom();
    currentRoom->doorNordIsOpen = true;
  }
  if (joueurX == gb.display.width() - (MUR_LARGEUR + AVATAR_WIDTH) && joueurY >= 22 && (joueurY < 43 - AVATAR_HEIGHT) 
  && currentRoom->doorEstExist && !currentRoom->doorEstIsOpen) { // Porte droite
    direction = "Est";
    generateNewRoom();
    currentRoom->doorEstIsOpen = true;
  }
  if (joueurX == 0 + MUR_LARGEUR && joueurY >= 22 && (joueurY < 43 - AVATAR_HEIGHT) 
    && currentRoom->doorOuestExist && !currentRoom->doorOuestIsOpen) { // Porte gauche
    direction = "Ouest";
    generateNewRoom();
    currentRoom->doorOuestIsOpen = true;
  }

}


void finalRoom() {

  gb.display.drawImage(40, 32, paper);
  const uint8_t PAPER_WIDTH  = PAPER_ICON_DATA[0];
  const uint8_t PAPER_HEIGHT = PAPER_ICON_DATA[1];

  if (gb.buttons.pressed(BUTTON_A) && joueurX > 40 && joueurX < 40 + PAPER_WIDTH && joueurY > 32 && joueurY < 32 + PAPER_HEIGHT) {
    readPaper();
  }

}


void readPaper() {

  while(1) {
  while(!gb.update());

    gb.display.drawImage(20, 3, paperSheet);
    // gb.display.clear();

    if (gb.buttons.pressed(BUTTON_B) ) {
      return;
    } 
  
    gb.display.setColor(GRAY);

    gb.display.setCursor(30, 10);
    gb.display.print("Bravo!");

    gb.display.setCursor(25, 18);
    gb.display.print("Tu as");

    gb.display.setCursor(25, 26);
    gb.display.print("fini");

    gb.display.setCursor(25, 34);
    gb.display.print("le jeu!");
    
    gb.display.setColor(WHITE);

  }
}

  
