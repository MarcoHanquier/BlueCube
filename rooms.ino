#include <Gamebuino-Meta.h>
#include "assets/rooms.h"
#include "assets/menus.h"

Image antichambre(ANTICHAMBRE_DATA);
Image carrelage1(CARRELAGE1_DATA);
Image carrelage2(CARRELAGE2_DATA);
Image carrelage3(CARRELAGE3_DATA);
Image chambre(BEDROOM_DATA);
Image redRoom(REDROOM_DATA);
Image plancher(PLANCHER_DATA);
Image jardin(GARDEN_DATA);

Image roomSelection(BLUEPRINT_ROOM_SELECTION_DATA);

bool base1Nord; 
bool base1Est;
bool base1Sud;
bool base1Ouest;
bool base2Nord;
bool base2Est;
bool base2Sud;
bool base2Ouest;
bool base3Nord;
bool base3Est;
bool base3Sud;
bool base3Ouest;

// Nord Sud Est Ouest
void initialiseRooms(){
room1 = {1,"Hall d'Entree","Basique", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, false};
room2 = {2,"Placard","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room3 = {3,"Grand Placard","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room4 = {4,"Grenier","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room5 = {5,"Billard","Basique", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room6 = {6,"Parloir","Basique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room7 = {7,"Entrepot","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room8 = {8,"Recoin","Basique", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room9 = {9,"Garage","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room10 = {10,"Chambre froide","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room11 = {11,"Salle a manger","Basique", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room12 = {12,"Bureau","Basique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room13 = {13,"Coffres","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room14 = {14,"Salle de bal","Basique", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room15 = {15,"Salle musicale","Basique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room16 = {16,"Garde-manger","Basique", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room17 = {17,"Sauna","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room18 = {18,"Galerie","Basique", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room19 = {19,"Piscine","Basique", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room20 = {20,"Salon","Basique", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room21 = {21,"Vestiaire","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room22 = {22,"Laboratoire","Basique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room23 = {23,"Securite","Basique", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room24 = {24,"Fondation","Basique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room25 = {25,"Croisement","Couloir", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room26 = {26,"Aile Droite","Couloir", true, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room27 = {27,"Aile Gauche","Couloir", true, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room28 = {28,"Corridor","Couloir", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room29 = {29,"Hall","Couloir", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room30 = {30,"Foyer","Couloir", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room31 = {31,"Aquarium","Basique", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room32 = {32,"Serre","Jardin", true, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room33 = {33,"Terrasse","Jardin", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room34 = {34,"Patio","Jardin", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room35 = {35,"Cour","Jardin", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room36 = {36,"Cloitre","Jardin", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room37 = {37,"Veranda","Jardin", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room38 = {38,"Jardin Secret","Jardin", true, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room39 = {39,"Suite","Chambre", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room40 = {40,"Chambre double","Chambre", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room41 = {41,"Chambre","Chambre", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room42 = {42,"Boudoir","Chambre", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room43 = {43,"Chambre d'amis","Chambre", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room44 = {44,"Nurserie","Chambre", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room45 = {45,"Sous l'escalier","Chambre", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room46 = {46,"Laverie","Boutique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room47 = {47,"Souvenir","Boutique", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room48 = {48,"Cuisine","Boutique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room49 = {49,"Armurerie","Boutique", false, true, true, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room50 = {50,"Cordonnier","Boutique", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room51 = {51,"Bijouterie","Boutique", true, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room52 = {52,"Librairie","Boutique", false, true, false, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room53 = {53,"Salle de muscu","Rouge", true, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room54 = {54,"Chaudiere","Rouge", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room55 = {55,"Chapelle","Rouge", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room56 = {56,"Chambre Noire","Rouge", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room57 = {57,"Gymnase","Rouge", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room58 = {58,"Archives","Rouge", false, true, true, true, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room59 = {59,"Salle de bain","Rouge", false, true, false, false, false, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, true};
room60 = {60,"Antichambre","Basique", true, true, true, true, true, false, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, false};
room61 = {61,"Piece ???","Basique", false, true, false, false, false, true, false,  false, false, false, false, false, nullptr, nullptr, nullptr, nullptr, false};
}

void changeDisplayColorOfRoomType(){
    if(currentRoom->roomType == "Basique"){
        gb.display.setColor(LIGHTBLUE);
        gb.lights.fill(LIGHTBLUE);
    } else if(currentRoom->roomType == "Couloir"){
        gb.display.setColor(ORANGE);
        gb.lights.fill(ORANGE);
    } else if(currentRoom->roomType == "Chambre"){
        gb.display.setColor(PURPLE);
        gb.lights.fill(PURPLE);
    } else if(currentRoom->roomType == "Jardin"){
        gb.display.setColor(LIGHTGREEN);
        gb.lights.fill(LIGHTGREEN);
    } else if(currentRoom->roomType == "Boutique"){
        gb.display.setColor(YELLOW);
        gb.lights.fill(YELLOW);
    } else if(currentRoom->roomType == "Rouge"){
        gb.display.setColor(RED);
        gb.lights.fill(RED);
    } 
}

void changeDisplayColorOfMiniRoomType(){
    if(displayedRoom->roomType == "Basique"){
        gb.display.setColor(LIGHTBLUE);
    } else if(displayedRoom->roomType == "Couloir"){
        gb.display.setColor(ORANGE);
    } else if(displayedRoom->roomType == "Chambre"){
        gb.display.setColor(PURPLE);
    } else if(displayedRoom->roomType == "Jardin"){
        gb.display.setColor(LIGHTGREEN);
    } else if(displayedRoom->roomType == "Boutique"){
        gb.display.setColor(YELLOW);
    } else if(displayedRoom->roomType == "Rouge"){
        gb.display.setColor(RED);
    } 
}

void changeAssetOfRoomType(){
    if(currentRoom->roomName == "Antichambre"){
        gb.display.drawImage(0, 0, antichambre);
    } else if(currentRoom->roomType == "Basique"){
        gb.display.drawImage(0, 0, carrelage3);
    } else if(currentRoom->roomType == "Couloir"){
        gb.display.drawImage(0, 0, carrelage2);
    } else if(currentRoom->roomType == "Chambre"){
        gb.display.drawImage(0, 0, chambre);
    } else if(currentRoom->roomType == "Jardin"){
        gb.display.drawImage(0, 0, jardin);
    } else if(currentRoom->roomType == "Boutique"){
        gb.display.drawImage(0, 0, plancher);
    } else if(currentRoom->roomType == "Rouge"){
        gb.display.drawImage(0, 0, redRoom);
    } 
}

void displayMiniMap(){
    gb.display.setColor(WHITE);
    int rX = 4;
    int rY = 3;

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 5; x++) {

            if (houseMap[y][x] == currentRoom->roomNumber){ // salle actuelle
                gb.display.setColor(RED);
                gb.display.fillRect(rX+1, rY+1, 3, 3);
                gb.display.setColor(WHITE);
            }
            if (houseMap[y][x] == 60){ // Antichambre
                gb.display.setColor(BLUE);
                gb.display.fillRect(rX+1, rY+1, 3, 3);
                gb.display.setColor(WHITE);
            }
            if (houseMap[y][x] != 0){
                gb.display.fillRect(rX, rY, 5, 1); // Haut
                gb.display.fillRect(rX, rY, 1, 5); // Gauche
                gb.display.fillRect(rX+4, rY, 1, 5); // Droite
                gb.display.fillRect(rX, rY+4, 5, 1); // Bas
                gb.display.setColor(BLACK);

            // Porte sud
            if (roomPool[houseMap[y][x]-1]->doorSudExist) {
                gb.display.fillRect(rX+2, rY+4, 1, 1);
            }

            // Porte nord
            if (roomPool[houseMap[y][x]-1]->doorNordExist == true) {
                gb.display.fillRect(rX+2, rY, 1, 1);
            }

            // Porte ouest
            if (roomPool[houseMap[y][x]-1]->doorOuestExist) {
                gb.display.fillRect(rX, rY+2, 1, 1);
            }

            // Porte Est
            if (roomPool[houseMap[y][x]-1]->doorEstExist) {
                gb.display.fillRect(rX+4, rY+2, 1, 1);
            }

            gb.display.setColor(WHITE);
            }

        rX += 4;
        }
        rX = 4;
        rY += 4;
      }
}


void generateCurrentRoom(){

    changeDisplayColorOfRoomType();

    changeAssetOfRoomType();

    // Mur nord
    gb.display.fillRect(0, 0, gb.display.width(), MUR_HAUTEUR);
  
    // Mur sud
    gb.display.fillRect(0, 64 - MUR_HAUTEUR, gb.display.width(), MUR_HAUTEUR);
  
    // Mur est
    gb.display.fillRect(80 - MUR_LARGEUR, 0, MUR_LARGEUR, gb.display.height());
  
    // Mur ouest
    gb.display.fillRect(0, 0, MUR_LARGEUR, gb.display.height());

    // check les 4 salles autour
    if(houseMap[roomY-1][roomX] != 0) { // Pièce Nord
        currentRoom->roomNord = roomPool[(houseMap[roomY-1][roomX])-1];
        currentRoom->doorNordIsOpen = true;
    }
    if(houseMap[roomY][roomX-1] != 0) { // Pièce Ouest 
        currentRoom->roomOuest = roomPool[(houseMap[roomY][roomX-1])-1];
        currentRoom->doorOuestIsOpen = true;
    }
    if(houseMap[roomY+1][roomX] != 0) { // Pièce Sud 
        currentRoom->roomSud = roomPool[(houseMap[roomY+1][roomX])-1];
        currentRoom->doorSudIsOpen = true;
    }
    if(houseMap[roomY][roomX+1] != 0) { // Pièce Est 
        currentRoom->roomEst = roomPool[(houseMap[roomY][roomX+1])-1];
        currentRoom->doorEstIsOpen = true;
    }

    // N'affiche pas de porte si les portes des deux salles ne sont pas connectées
    if (!currentRoom->roomNord->doorSudExist) {
        currentRoom->doorNordExist = false;
      }

    if (!currentRoom->roomSud->doorNordExist) {
      currentRoom->doorSudExist = false;
    }

    if (!currentRoom->roomEst->doorOuestExist) {
      currentRoom->doorEstExist = false;
    }

    if (!currentRoom->roomOuest->doorEstExist) {
      currentRoom->doorOuestExist = false;
    }

    // Affiche la porte si elle est présente

    // Porte ouest
    if (currentRoom->doorOuestExist) {
        if (currentRoom->doorOuestIsOpen == false) {
            gb.display.setColor(GRAY);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(0, 22, MUR_LARGEUR, 20);
    }

    // Porte nord
    if (currentRoom->doorNordExist) {
        if (currentRoom->doorNordIsOpen == false) {
            gb.display.setColor(GRAY);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(30, 0, 20, MUR_HAUTEUR);
    }

    // Porte est
    if (currentRoom->doorEstExist) {
        if (currentRoom->doorEstIsOpen == false) {
            gb.display.setColor(GRAY);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(gb.display.width() - MUR_LARGEUR, 22, MUR_LARGEUR, 20);
    }

    // Porte sud
    if (currentRoom->doorSudExist) {
        if (currentRoom->doorSudIsOpen == false) {
            gb.display.setColor(GRAY);
        } else gb.display.setColor(BLACK);
        gb.display.fillRect(30, gb.display.height() - MUR_HAUTEUR, 20, MUR_HAUTEUR);
    }

        if (roomY == 8) { // Mur maison bas
            currentRoom->doorSudExist = false;
        } 
        if (roomY == 0) { // Mur maison haut
            currentRoom->doorNordExist = false;
        }
        if (roomX == 4) { // Mur maison droite
            currentRoom->doorEstExist = false;
        }
        if (roomX == 0) { // Mur maison gauche
            currentRoom->doorOuestExist = false;
        }
        if (currentRoom->roomName == "Antichambre"){
            currentRoom->doorNordExist = true;
        }

    gb.display.setColor(WHITE);
}


void generateNewRoom(){

    // Choisis aléatoirement 3 pièces et effectue une rotation selon la direction du joueur avant de les afficher
    rollRandomRoomOne();
    rollRandomRoomTwo();
    rollRandomRoomThree();
    rotateRoom();

    int cursorPosition = 10;
    int selection = 1;

    while(1) {
		while(!gb.update());

        gb.display.clear();

        gb.display.drawImage(0, 0, roomSelection);
        drawMiniRoom();

        if(gb.buttons.pressed(BUTTON_UP) && selection > 1){
			selection--;
			gb.sound.playTick();
		}

		if(gb.buttons.pressed(BUTTON_DOWN) && selection < 3){
			selection++;
			gb.sound.playTick();
		}

        // Le joueur choisit une pièce qui sera placée en jeu et retirée des pièces disponibles au tirage, les autres sont réinitialisées
        if(gb.buttons.pressed(BUTTON_A)){
			switch(selection){
				case 1:
                    gb.sound.playOK();
                    newRoomChoice = rotatedRoom1;
                    revertRotationRoom2();
                    revertRotationRoom3();
                    createNewRoom();
                    return;
					break;
				case 2:
                    gb.sound.playOK();
					newRoomChoice = rotatedRoom2;
                    revertRotationRoom1();
                    revertRotationRoom3();
                    createNewRoom();
                    return;
					break;
				case 3:
					gb.sound.playOK();
					newRoomChoice = rotatedRoom3;
                    revertRotationRoom1();
                    revertRotationRoom2();
                    createNewRoom();
                    return;
					break;
			}
		}

        switch (selection){
			case 1:
				cursorPosition = 10;
				break;
			case 2:
                cursorPosition = 30;
				break;
			case 3:
                cursorPosition = 50;
				break;
		}

        gb.display.setCursor(3, cursorPosition);
        gb.display.print("-");

        gb.display.setCursor(7, 10);
        gb.display.print(roomChoiceOne->roomName);
    
        gb.display.setCursor(7, 30);
        gb.display.print(roomChoiceTwo->roomName);
    
        gb.display.setCursor(7, 50);
        gb.display.print(roomChoiceThree->roomName);
	}
}

void createNewRoom() {
    // Place la pièce en jeu et fait la liaison entre la pièce actuelle et la nouvelle
    newRoomChoice->isRoomInThePool = false;
    
    if(direction == "Nord") {
        roomY--;
        newRoomChoice->doorNordIsLocked = rollNewRoomLockedDoors();
        roomY++;
        currentRoom->roomNord = newRoomChoice;
        currentRoom->roomNord->roomSud = currentRoom;
        currentRoom->roomNord->doorSudIsOpen = true;
        houseMap[roomY-1][roomX] = currentRoom->roomNord->roomNumber;
    }
    if(direction == "Ouest") {
        newRoomChoice->doorOuestIsLocked = rollNewRoomLockedDoors();
        currentRoom->roomOuest = newRoomChoice;
        currentRoom->roomOuest->roomEst = currentRoom;
        currentRoom->roomOuest->doorEstIsOpen = true;
        houseMap[roomY][roomX-1] = currentRoom->roomOuest->roomNumber;
    }
    if(direction == "Est") {
        newRoomChoice->doorEstIsLocked = rollNewRoomLockedDoors();
        currentRoom->roomEst = newRoomChoice;
        currentRoom->roomEst->roomOuest = currentRoom;
        currentRoom->roomEst->doorOuestIsOpen = true;
        houseMap[roomY][roomX+1] = currentRoom->roomEst->roomNumber;
    }
    if(direction == "Sud") {
        roomY++;
        newRoomChoice->doorSudIsLocked = rollNewRoomLockedDoors();
        roomY--;
        currentRoom->roomSud = newRoomChoice;
        currentRoom->roomSud->roomNord = currentRoom;
        currentRoom->roomSud->doorNordIsOpen = true;
        houseMap[roomY+1][roomX] = currentRoom->roomSud->roomNumber;
    }

}


bool rollNewRoomLockedDoors() {

    int lockedProbability = 0;

    switch(roomY){
        case 0:
            lockedProbability = 70;
            break;
        case 1:
            lockedProbability = 60;
            break;
        case 2:
            lockedProbability = 50;
            break;
        case 3:
            lockedProbability = 40;
            break;
        case 4:
            lockedProbability = 30;
            break;
        case 5:
            lockedProbability = 20;
            break;
        case 6:
            lockedProbability = 10;
            break;
        default:    
            lockedProbability = 0;
            break;

    }
  
    int rollLockedDoor = random(100);

    gb.display.setCursor(40, 20);
    gb.display.print(rollLockedDoor);

    gb.display.setCursor(40, 25);
    gb.display.print(lockedProbability);
  
    if (rollLockedDoor < lockedProbability) {
        return true;
    } else return false;

}

void rollRandomRoomOne(){
    int randomRoomOne = random(numberOfRoomsInThePool);

    if (roomPool[randomRoomOne]->isRoomInThePool == true) {
        roomChoiceOne = roomPool[randomRoomOne];
    } else {
        rollRandomRoomOne();
    }
}

void rollRandomRoomTwo(){
    int randomRoomTwo = random(numberOfRoomsInThePool);

    if (roomPool[randomRoomTwo]->isRoomInThePool == true && roomPool[randomRoomTwo] != roomChoiceOne) {
        roomChoiceTwo = roomPool[randomRoomTwo];
    } else {
        rollRandomRoomTwo();
    }
}

void rollRandomRoomThree(){
    int randomRoomThree = random(numberOfRoomsInThePool);

    if (roomPool[randomRoomThree]->isRoomInThePool == true && roomPool[randomRoomThree] != roomChoiceOne && roomPool[randomRoomThree] != roomChoiceTwo) {
        roomChoiceThree = roomPool[randomRoomThree];
    } else {
        rollRandomRoomThree();
    }
}

void revertRotationRoom1(){
    roomChoiceOne->doorNordExist = base1Nord; 
    roomChoiceOne->doorEstExist = base1Est;
    roomChoiceOne->doorSudExist = base1Sud;
    roomChoiceOne->doorOuestExist = base1Ouest;
}

void revertRotationRoom2(){
    roomChoiceTwo->doorNordExist = base2Nord; 
    roomChoiceTwo->doorEstExist = base2Est;
    roomChoiceTwo->doorSudExist = base2Sud;
    roomChoiceTwo->doorOuestExist = base2Ouest;
}

void revertRotationRoom3(){
    roomChoiceThree->doorNordExist = base3Nord; 
    roomChoiceThree->doorEstExist = base3Est;
    roomChoiceThree->doorSudExist = base3Sud;
    roomChoiceThree->doorOuestExist = base3Ouest;
}

void rotateRoom90Degrees(s_room* room) {
    bool tempNord = room->doorNordExist;
    bool tempEst = room->doorEstExist;
    bool tempSud = room->doorSudExist;
    bool tempOuest = room->doorOuestExist;
  
    room->doorNordExist = tempOuest;
    room->doorEstExist  = tempNord;
    room->doorSudExist  = tempEst;
    room->doorOuestExist = tempSud;
}

void rotateRoom() {
    // Effectue une rotation pour assurer que la porte Sud de la nouvelle pièce est toujours placée en face du joueur au moment de la création
    rotatedRoom1 = roomChoiceOne;
    rotatedRoom2 = roomChoiceTwo;
    rotatedRoom3 = roomChoiceThree;

    base1Nord = roomChoiceOne->doorNordExist;
    base1Est = roomChoiceOne->doorEstExist;
    base1Sud = roomChoiceOne->doorSudExist;
    base1Ouest = roomChoiceOne->doorOuestExist;

    base2Nord = roomChoiceTwo->doorNordExist;
    base2Est = roomChoiceTwo->doorEstExist;
    base2Sud = roomChoiceTwo->doorSudExist;
    base2Ouest = roomChoiceTwo->doorOuestExist;

    base3Nord = roomChoiceThree->doorNordExist;
    base3Est = roomChoiceThree->doorEstExist;
    base3Sud = roomChoiceThree->doorSudExist;
    base3Ouest = roomChoiceThree->doorOuestExist;
  
    int rotations = 0;
  
    if (direction == "Nord") rotations = 0;
    if (direction == "Est") rotations = 1;
    if (direction == "Sud") rotations = 2;
    if (direction == "Ouest") rotations = 3;
  
    for (int i = 0; i < rotations; i++) {
      rotateRoom90Degrees(rotatedRoom1);
      rotateRoom90Degrees(rotatedRoom2);
      rotateRoom90Degrees(rotatedRoom3);
    }

}


void drawMiniRoom(){
    // Affiche une version miniature de la pièce en prévisualisation lors du choi

    // Pièce 1
    displayedRoom = rotatedRoom1;
    changeDisplayColorOfMiniRoomType();
    gb.display.fillRect(65, 8, 7, 1); // Mur nord
    gb.display.fillRect(65, 17, 10, 1); // Mur sud
    gb.display.fillRect(74, 9, 1, 9); // Mur est
    gb.display.fillRect(65, 8, 1, 10);  // Mur ouest

    gb.display.setColor(BLACK);
    // Porte nord
    if (rotatedRoom1->doorNordExist) {
        gb.display.fillRect(69, 8, 2, 1);
    }
    // Porte sud
    if (rotatedRoom1->doorSudExist) {
        gb.display.fillRect(69, 17, 2, 1);
    }
    // Porte est
    if (rotatedRoom1->doorEstExist) {
        gb.display.fillRect(74, 12, 1, 2);
    }
    // Porte ouest
    if (rotatedRoom1->doorOuestExist) {
        gb.display.fillRect(65, 12, 1, 2);
    }
    gb.display.setColor(WHITE);

    // Pièce 2
    displayedRoom = rotatedRoom2;
    changeDisplayColorOfMiniRoomType();
    gb.display.fillRect(65, 28, 10, 1); // Mur nord
    gb.display.fillRect(65, 37, 10, 1); // Mur sud
    gb.display.fillRect(74, 28, 1, 10); // Mur est
    gb.display.fillRect(65, 28, 1, 10);  // Mur ouest

    gb.display.setColor(BLACK);
    // Porte nord
    if (rotatedRoom2->doorNordExist) {
        gb.display.fillRect(69, 28, 2, 1);
    }
    // Porte sud
    if (rotatedRoom2->doorSudExist) {
        gb.display.fillRect(69, 37, 2, 1);
    }
    // Porte est
    if (rotatedRoom2->doorEstExist) {
        gb.display.fillRect(74, 32, 1, 2);
    }
    // Porte ouest
    if (rotatedRoom2->doorOuestExist) {
        gb.display.fillRect(65, 32, 1, 2);
    }
    gb.display.setColor(WHITE);

    // Pièce 3
    displayedRoom = rotatedRoom3;
    changeDisplayColorOfMiniRoomType();
    gb.display.fillRect(65, 48, 10, 1); // Mur nord
    gb.display.fillRect(65, 57, 10, 1); // Mur sud
    gb.display.fillRect(74, 48, 1, 10); // Mur est
    gb.display.fillRect(65, 48, 1, 10);  // Mur ouest

    gb.display.setColor(BLACK);
    // Porte nord
    if (rotatedRoom3->doorNordExist) {
        gb.display.fillRect(69, 48, 2, 1);
    }
    // Porte sud
    if (rotatedRoom3->doorSudExist) {
        gb.display.fillRect(69, 57, 2, 1);
    }
    // Porte est
    if (rotatedRoom3->doorEstExist) {
        gb.display.fillRect(74, 52, 1, 2);
    }
    // Porte ouest
    if (rotatedRoom3->doorOuestExist) {
        gb.display.fillRect(65, 52, 1, 2);
    }
    gb.display.setColor(WHITE);

}
