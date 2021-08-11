#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>



int number_of_players, i,j;
int difficulty;
int gameover=3;
char races[4][10];
char first_player[10];
char turn[10];
char plr, battle;

struct Player{
    char name[10];
    char race[10];
    int life;
    int strength;
    int fights;
};

struct Player Mage;
struct Player Dwarf;
struct Player Barbarian;
struct Player Fighter;

struct Monster{
    int life;
    int strength;
};

struct Monster Level1;
struct Monster Level2;

void setup();
void characters();
void characters_setup();
void order_of_play();
void difficulty_level();
void fight(char);
void print_level_menu();
void print_choose_character_menu();
struct Monster create_monster_lvl1(int);
struct Monster create_monster_lvl2(int);

void main(){

    setup();
    characters();
    characters_setup();
    difficulty_level();
    order_of_play();
    printf("\n\n\t\t\t\t%s start your journey to Firetop Mountain!\n", first_player);
    sleep(2);

    while (gameover !=0) {
        system("clear");
        print_choose_character_menu();
        print_level_menu();
        switch(battle){
            case '1':
                printf("\n\t\t\t\t");
                Level1 = create_monster_lvl1(difficulty);
                break;
            case '2':
                printf("\n\t\t\t\t");
                Level2 = create_monster_lvl2(difficulty);
                break;
            case 'Z':
                printf("\n\t\t\t\t");
                printf("\n\t\t\t\tGet ready to fight Zagor!");
                break;
        }

        fight(battle);

        gameover--;

    }

}

//FUNCTIONS

//FUNCTION TO INPUT THE NUMBER OF PLAYERS

void setup(){
    int menu_h=7, menu_w=40;

    printf("\n\t\t\t\tZagor: How many players would choose to die?");
    printf("\n\n\t\t\t\t--------------------");
    printf("\n\t\t\t\tNumber of Players: ");
    scanf("%d", &number_of_players);

    printf("\n\n\t\t\t\t");
    for (i=0; i<menu_h; i++){
        for (int j=0; j<menu_w; j++){
            if (i == 0 || i == menu_h-1){
                printf("#");
            }

            if (i == 3 && j == 1){
                printf("\tBarbarian ******* Dwarf\n\n \t\t\t\t\t  Fighter ******* Mage");
            }

        }
        printf("\n\t\t\t\t");
    }
}


//FUNCTION TO PRINT MONSTER LEVEL MENU

void print_level_menu(){
    printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t* LEVEL 1 * LEVEL 2 * ZAGOR *");
    printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t");
    printf("\n\t\t\t\tChoose a battle! ");
    scanf(" %c", &battle);

}

//FUNCTION TO PRINT CHARACTER TO FIGHT
void print_choose_character_menu(){
    printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t** F **** B **** D **** M **");
    printf("\n\t\t\t\t****************************");
    printf("\n\t\t\t\t");
    printf("\n\t\t\t\tWho dares to fight my monsters? ");
    scanf(" %c", &plr);

    switch(plr){
        case 'M':
                printf("\n\t\t\t\tMage are you ready to fight?\n");
                Mage.fights++;
                break;
        case 'F':
                printf("\n\t\t\t\tFighter are you ready to fight?\n");
                Fighter.fights++;
                break;
        case 'B':
                printf("\n\t\t\t\tBarbarian are you ready to fight?\n");
                Barbarian.fights++;
                break;
        case 'D':
                printf("\n\t\t\t\tDwarf are you ready to fight?\n");
                Dwarf.fights++;
                break;
        }
}



//FUNCTION TO DETERMINE THE CHARACTERS OF PLAYERS

void characters(){

    for (i=0; i<number_of_players; i++){
        printf("\n\t\t\t\tPlayer %d choose your character! ", i+1);
        scanf("%s", &races[i]);
        int check=strcmp(races[i],races[i-1]);
        while (check == 0){
            printf("\n\t\t\t\tPlayer %d choose again your character! ", i+1);
            scanf("%s", &races[i]);
            check=strcmp(races[i],races[i-1]);
        }

    }

    /*struct Player *plr;
    plr = (struct Player*) malloc(number_of_players * sizeof(struct Player));

    for (j=0; j<number_of_players; j++){

        printf("\n\t\t\t\tEnter your name, life, strength and number of fights: ");
        scanf("%s %d %d %d", &(plr+j)->name, &(plr+j)->life, &(plr+j)->strength, &(plr+j)->fights);
        strcpy((plr+j)->race, races[j]);

    }

    printf("\n\t\t\t\tDisplay Players Information:\n");
    for (j=0; j<number_of_players; j++)
        printf("\n\t\t\t\tName: %s\tRace: %s\tLife: %d\tStrength: %d\tFights: %d\n", (plr+j)->name, (plr+j)->race, (plr+j)->life, (plr+j)->strength, (plr+j)->fights);
    */
}

//FUNCTION TO SETUP CHARACTERS DETAILS

void characters_setup(){

     for (i=0; i<number_of_players; i++){
        if (strcmp(races[i], "Mage") == 0){
            Mage.fights = 0;
            strcpy(Mage.race, races[i]);
        }
        if (strcmp(races[i], "Fighter") == 0){
            Fighter.fights = 0;
            strcpy(Fighter.race, races[i]);
        }
        if (strcmp(races[i], "Barbarian") == 0){
            Barbarian.fights = 0;
            strcpy(Barbarian.race, races[i]);
        }
        if (strcmp(races[i], "Dwarf") == 0){
            Dwarf.fights = 0;
            strcpy(Dwarf.race, races[i]);
        }
    }
    //printf("\n\t\t\t\tDisplay Players Information:\n");
    //for (j=0; j<number_of_players; j++)
        //printf("\n\t\t\t\tName: %s\tRace: %s\tLife: %d\tStrength: %d\tFights: %d\n", Players[j].name, Players[j].race, Players[j].life, Players[j].strength, Players[j].fights);
}

//FUNCTION TO DETERMINE ORDER OF PLAY

void order_of_play(){

    char fav_race[10];
    strcpy(fav_race, "Dwarf");
    int check=-1, check2=-1, check3=-1, check4=-1;
    int token, flag=0;

    srand(time(NULL));

    switch (number_of_players){
        case 1:
            printf("\n\t\t\t\tThe first player is: %s", races[0]);
            strcpy(first_player, races[0]);
            break;
        case 2:
            check=strcmp(fav_race, races[0]);
            printf("\n\t\t\t\tTh first check is %d\n", check);
            if (check == 0){
                flag=1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 13 ... 20:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                }
            }
            if (check != 0){
                check2 = strcmp(fav_race, races[1]);
                printf("\n\t\t\t\tThe second check is %d", check2);
            }
            if (check2 == 0){
                flag =1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 13 ... 20:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                }
            }

            if (flag == 0){
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                if (token<11){
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                }
                else{
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                }
            }
            break;
        case 3:
            check=strcmp(fav_race, races[0]);
            printf("\n\t\t\t\tTh first check is %d\n", check);
            if (check == 0){
                flag=1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 13 ... 21:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 22 ... 30:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                }
            }
            if (check != 0){
                check2 = strcmp(fav_race, races[1]);
                printf("\n\t\t\t\tThe second check is %d", check2);
            }
            if (check2 == 0){
                flag = 1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 13 ... 21:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 22 ... 30:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                }
            }
            if (check2 != 0){
                check3 = strcmp(fav_race, races[2]);
                printf("\n\t\t\t\tThe third check is %d", check3);
            }
            if (check3 == 0){
                flag = 1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                    case 13 ... 21:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 22 ... 30:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                }
            }
            if (flag == 0){
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                if (token<11){
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                }
                if (token>10 && token<21){
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                }
                else{
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                }
            }
            break;
        case 4:
            check=strcmp(fav_race, races[0]);
            printf("\n\t\t\t\tTh first check is %d\n", check);
            if (check == 0){
                flag=1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 13 ... 22:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 23 ... 31:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                    case 32 ... 40:
                    printf("\n\t\t\t\tThe first player is: %s", races[3]);
                    strcpy(first_player, races[3]);
                    break;
                }
            }
            if (check != 0){
                check2 = strcmp(fav_race, races[1]);
                printf("\n\t\t\t\tThe second check is %d", check2);
            }
            if (check2 == 0){
                flag =1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 13 ... 22:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 23 ... 31:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                    case 32 ... 40:
                    printf("\n\t\t\t\tThe first player is: %s", races[3]);
                    strcpy(first_player, races[3]);
                    break;
                }
            }
            if (check2 != 0){
                check3 = strcmp(fav_race, races[2]);
                printf("\n\t\t\t\tThe third check is %d", check3);
            }
            if (check3 == 0){
                flag =1;
                token = rand() % (number_of_players*10)+1;
                printf("\n\t\t\t\tThe token for first player is %d\n", token);
                switch (token){
                    case 1 ... 12:
                    printf("\n\t\t\t\tThe first player is: %s", races[2]);
                    strcpy(first_player, races[2]);
                    break;
                    case 13 ... 22:
                    printf("\n\t\t\t\tThe first player is: %s", races[0]);
                    strcpy(first_player, races[0]);
                    break;
                    case 23 ... 31:
                    printf("\n\t\t\t\tThe first player is: %s", races[1]);
                    strcpy(first_player, races[1]);
                    break;
                    case 32 ... 40:
                    printf("\n\t\t\t\tThe first player is: %s", races[3]);
                    strcpy(first_player, races[3]);
                    break;
                }
            }
            if (check3 != 0){
                check4 = strcmp(fav_race, races[3]);
                printf("\n\t\t\t\tThe fourth check is %d", check4);
            }
            if (check4 == 0){
                    flag =1;
                    token = rand() % (number_of_players*10)+1;
                    printf("\n\t\t\t\tThe token for first player is %d\n", token);
                    switch (token){
                        case 1 ... 12:
                        printf("\n\t\t\t\tThe first player is: %s", races[3]);
                        strcpy(first_player, races[3]);
                        break;
                        case 13 ... 22:
                        printf("\n\t\t\t\tThe first player is: %s", races[0]);
                        strcpy(first_player, races[0]);
                        break;
                        case 23 ... 31:
                        printf("\n\t\t\t\tThe first player is: %s", races[1]);
                        strcpy(first_player, races[1]);
                        break;
                        case 32 ... 40:
                        printf("\n\t\t\t\tThe first player is: %s", races[2]);
                        strcpy(first_player, races[2]);
                        break;
                    }
            }

    }

}

//FUNCTION FOR GAME DIFFICULTY

void difficulty_level(){

    srand(time(NULL));

    int token = rand() % 100 +1;
    printf("\n\t\t\t\tThe token for difficulty is %d\n", token);

    switch (token) {
        case 1 ... 7:
            difficulty = 1;
            printf("\n\t\t\t\tThe game is very easy!");
            break;
        case 8 ... 20:
            difficulty = 2;
            printf("\n\t\t\t\tThe game is easy!");
            break;
        case 21 ... 30:
            difficulty = 4;
            printf("\n\t\t\t\tThe game is hard!");
            break;
        case 31 ... 36:
            difficulty = 5;
            printf("\n\t\t\t\tThe game is very hard!");
            break;
        case 37 ... 100:
            difficulty = 3;
            printf("\n\t\t\t\tThe game is normal!");
            break;

    }
}

//FUNCTION TO CREATE A LEVEL 1 MONSTER

struct Monster create_monster_lvl1(int difficulty){

    struct Monster Random_Monster;
    int token_life,token_strength;
    srand(time(NULL));
    switch(difficulty){
        case 1:
             token_life = rand() % 100+1;
             printf("\n\t\t\t\tToken for Life is: %d", token_life);
             token_strength = rand() % 100+1;
             printf("\n\t\t\t\tToken for Strength is: %d", token_strength);

             switch(token_life){
                case 1 ... 60:
                Random_Monster.life = 1;
                break;
                case 61 ... 94:
                Random_Monster.life = 2;
                break;
                case 95 ... 98:
                Random_Monster.life = 3;
                break;
                case 99 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                 case 1 ... 40:
                 Random_Monster.strength = 1;
                 break;
                 case 41 ... 90:
                 Random_Monster.strength = 2;
                 break;
                 case 91 ... 97:
                 Random_Monster.strength = 3;
                 break;
                 case 98 ... 100:
                 Random_Monster.strength = 4;
                 break;
             }
             break;
        case 2:
            token_life= rand() % 100+1;
            printf("\n\t\t\t\tToken for Life_ is: %d", token_life);
            token_strength = rand() % 100+1;
            printf("\n\t\t\t\tToken for Strength_ is: %d", token_strength);

            switch(token_life){
                case 1 ... 50:
                Random_Monster.life = 1;
                break;
                case 51 ... 89:
                Random_Monster.life = 2;
                break;
                case 90 ... 96:
                Random_Monster.life = 3;
                break;
                case 97 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 40:
                Random_Monster.strength = 1;
                break;
                case 41 ... 85:
                Random_Monster.strength = 2;
                break;
                case 86 ... 96:
                Random_Monster.strength = 3;
                break;
                case 97 ... 100:
                Random_Monster.strength = 4;
                break;
             }
            break;
        case 3:
            token_life= rand() % 100+1;
            printf("\n\t\t\t\tToken for Life* is: %d", token_life);
            token_strength = rand() % 100+1;
            printf("\n\t\t\t\tToken for Strength* is: %d", token_strength);

            switch(token_life){
                case 1 ... 45:
                Random_Monster.life = 1;
                break;
                case 46 ... 85:
                Random_Monster.life = 2;
                break;
                case 86 ... 95:
                Random_Monster.life = 3;
                break;
                case 96 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 35:
                Random_Monster.strength = 1;
                break;
                case 36 ... 82:
                Random_Monster.strength = 2;
                break;
                case 83 ... 95:
                Random_Monster.strength = 3;
                break;
                case 96 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;
        case 4:
            token_life= rand() % 100+1;
            printf("\n\t\t\t\tToken for Life^ is: %d", token_life);
            token_strength = rand() % 100+1;
            printf("\n\t\t\t\tToken for Strength^ is: %d", token_strength);

            switch(token_life){
                case 1 ... 35:
                Random_Monster.life = 1;
                break;
                case 36 ... 79:
                Random_Monster.life = 2;
                break;
                case 80 ... 94:
                Random_Monster.life = 3;
                break;
                case 95 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 30:
                Random_Monster.strength = 1;
                break;
                case 31 ... 80:
                Random_Monster.strength = 2;
                break;
                case 81 ... 94:
                Random_Monster.strength = 3;
                break;
                case 95 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;
        case 5:
            token_life= rand() % 100+1;
            printf("\n\t\t\t\tToken for Life- is: %d", token_life);
            token_strength = rand() % 100+1;
            printf("\n\t\t\t\tToken for Strength- is: %d", token_strength);

            switch(token_life){
                case 1 ... 30:
                Random_Monster.life = 1;
                break;
                case 31 ... 75:
                Random_Monster.life = 2;
                break;
                case 76 ... 93:
                Random_Monster.life = 3;
                break;
                case 94 ... 100:
                Random_Monster.life = 4;
                break;
             }

             switch(token_strength){
                case 1 ... 25:
                Random_Monster.strength = 1;
                break;
                case 26 ... 78:
                Random_Monster.strength = 2;
                break;
                case 79 ... 93:
                Random_Monster.strength = 3;
                break;
                case 94 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;

    }
    printf("\n\t\t\t\tAn evil monster approches!\n\t\t\t\tStrength: %d \tLife:  %d", Random_Monster.strength, Random_Monster.life);
    return Random_Monster;

}

//FUNCTION TO CREATE A LEVEL 2 MONSTER

struct Monster create_monster_lvl2(int difficulty){

    struct Monster Random_Monster;
    int token_life,token_strength;
    srand(time(NULL));
    token_life = rand() % 100+1;
    token_strength = rand() % 100+1;
    switch(difficulty){
        case 1:
             printf("\n\t\t\t\tToken for Life is: %d", token_life);
             printf("\n\t\t\t\tToken for Strength is: %d", token_strength);

             switch(token_life){
                case 1 ... 15:
                Random_Monster.life = 1;
                break;
                case 16 ... 84:
                Random_Monster.life = 2;
                break;
                case 85 ... 98:
                Random_Monster.life = 3;
                break;
                case 99 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                 case 1 ... 10:
                 Random_Monster.strength = 1;
                 break;
                 case 11 ... 75:
                 Random_Monster.strength = 2;
                 break;
                 case 76 ... 97:
                 Random_Monster.strength = 3;
                 break;
                 case 98 ... 100:
                 Random_Monster.strength = 4;
                 break;
             }
             break;
        case 2:
            printf("\n\t\t\t\tToken for Life_ is: %d", token_life);
            printf("\n\t\t\t\tToken for Strength_ is: %d", token_strength);

            switch(token_life){
                case 1 ... 10:
                Random_Monster.life = 1;
                break;
                case 11 ... 81:
                Random_Monster.life = 2;
                break;
                case 82 ... 95:
                Random_Monster.life = 3;
                break;
                case 96 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 10:
                Random_Monster.strength = 1;
                break;
                case 11 ... 70:
                Random_Monster.strength = 2;
                break;
                case 71 ... 96:
                Random_Monster.strength = 3;
                break;
                case 97 ... 100:
                Random_Monster.strength = 4;
                break;
             }
            break;
        case 3:
            printf("\n\t\t\t\tToken for Life* is: %d", token_life);
            printf("\n\t\t\t\tToken for Strength* is: %d", token_strength);

            switch(token_life){
                case 1 ... 10:
                Random_Monster.life = 1;
                break;
                case 11 ... 70:
                Random_Monster.life = 2;
                break;
                case 71 ... 94:
                Random_Monster.life = 3;
                break;
                case 95 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 10:
                Random_Monster.strength = 1;
                break;
                case 11 ... 51:
                Random_Monster.strength = 2;
                break;
                case 52 ... 91:
                Random_Monster.strength = 3;
                break;
                case 92 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;
        case 4:
            printf("\n\t\t\t\tToken for Life^ is: %d", token_life);
            printf("\n\t\t\t\tToken for Strength^ is: %d", token_strength);

            switch(token_life){
                case 1 ... 8:
                Random_Monster.life = 1;
                break;
                case 9 ... 65:
                Random_Monster.life = 2;
                break;
                case 66 ... 92:
                Random_Monster.life = 3;
                break;
                case 93 ... 100:
                Random_Monster.life = 4;
                break;
             }
             switch(token_strength){
                case 1 ... 7:
                Random_Monster.strength = 1;
                break;
                case 8 ... 50:
                Random_Monster.strength = 2;
                break;
                case 51 ... 90:
                Random_Monster.strength = 3;
                break;
                case 91 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;
        case 5:
            printf("\n\t\t\t\tToken for Life- is: %d", token_life);
            printf("\n\t\t\t\tToken for Strength- is: %d", token_strength);

            switch(token_life){
                case 1 ... 7:
                Random_Monster.life = 1;
                break;
                case 8 ... 43:
                Random_Monster.life = 2;
                break;
                case 44 ... 88:
                Random_Monster.life = 3;
                break;
                case 89 ... 100:
                Random_Monster.life = 4;
                break;
             }

             switch(token_strength){
                case 1 ... 5:
                Random_Monster.strength = 1;
                break;
                case 6 ... 36:
                Random_Monster.strength = 2;
                break;
                case 37 ... 84:
                Random_Monster.strength = 3;
                break;
                case 85 ... 100:
                Random_Monster.strength = 4;
                break;
             }
             break;

    }
    printf("\n\t\t\t\tAn evil monster approches!\n\t\t\t\tStrength: %d \tLife:  %d", Random_Monster.strength, Random_Monster.life);
    return Random_Monster;
}

//FUNCTION FOR FIGHT ACTION

void fight(char battle_type){
    srand(time(NULL));
    char end;
    int end_fight=-1;
    int random_value, monster_die;

    while (end_fight !=0){

        random_value = rand() % 100+1;

        switch(battle_type){
            case '1':
                switch(random_value){
                    case 1 ... 15:
                        monster_die = 1;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 16 ... 30:
                        monster_die = 2;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 31 ... 50:
                        monster_die = 3;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 51 ... 70:
                        monster_die = 4;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 71 ... 80:
                        monster_die = 5;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 81 ... 87:
                        monster_die = 6;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        sleep(5);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 88 ... 93:
                        monster_die = 7;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 94 ... 96:
                        monster_die = 8;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 97 ... 99:
                        monster_die = 9;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 100:
                        monster_die = 10;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                }
                break;
            case '2':
                    switch(random_value){
                    case 1 ... 5:
                        monster_die = 1;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 6 ... 11:
                        monster_die = 2;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 12 ... 21:
                        monster_die = 3;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 22 ... 36:
                        monster_die = 4;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 37 ... 56:
                        monster_die = 5;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 57 ... 76:
                        monster_die = 6;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 77 ... 86:
                        monster_die = 7;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 87 ... 94:
                        monster_die = 8;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 95 ... 98:
                        monster_die = 9;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 99 ... 100:
                        monster_die = 10;
                        printf("\n\t\t\t\tThe monster throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                }
                break;
            case 'Z':
                    switch(random_value){
                    case 1 ... 4:
                        monster_die = 1;
                        printf("\n\t\t\t\tZagors throw a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 5 ... 9:
                        monster_die = 2;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 10 ... 15:
                        monster_die = 3;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 16 ... 25:
                        printf("\n\t\t\t\tZagor throws a Doom Spell");
                        printf("\n\t\t\t\tLose 2 points of life!");
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 26 ... 35:
                        monster_die = 4;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 36 ... 42:
                        monster_die = 5;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 43 ... 52:
                        printf("\n\t\t\t\tZagor throws a Lighting Spell");
                        printf("\n\t\t\t\tLose 1 point of life!");
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 53 ... 65:
                        monster_die = 6;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 66 ... 75:
                        monster_die = 7;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 76 ... 85:
                        printf("\n\t\t\t\tZagor throws a Thunder Spell");
                        printf("\n\t\t\t\tLose one piece of your armor!");
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 86 ... 91:
                        monster_die = 8;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 92 ... 95:
                        monster_die = 9;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                    case 96 ... 100:
                        monster_die = 7;
                        printf("\n\t\t\t\tZagor throws a %d ", monster_die);
                        end = getchar();
                        if (end == plr)
                            end_fight = 0;
                        break;
                }
                break;

        }
    sleep(2);
    }
}
