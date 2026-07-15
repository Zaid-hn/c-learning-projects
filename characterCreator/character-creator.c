#include <stdio.h>
#include <string.h>

struct Character
{
    char name[31];
    char player_class[35];

    int hp;
    int mana;
    int attack;
};

void class_select (int choice_class, char player_class[][31], int player_stats[][3], struct Character *character_p);

int main()
{
    printf("\n========================\n");
    printf("\n   CHARACTER CREATOR   \n");
    printf("\n========================\n");

    struct Character character;
    char player_class[3][31] =
        {
            "Warrior",
            "Archer",
            "Mage"
        };
    
    struct Character *character_p = &character;

    int player_stats[3][3] = 
    {
        {30, 10, 25},
        {20, 15, 10},
        {20, 35, 15}
    };

    printf("\n> Enter name: ");
    scanf("%s", character.name);

    printf("\n1. Warrior\n2. Archer\n3. Mage\n");
    printf("\nChoose Class: ");

    int choice_class;
    scanf("%d", &choice_class);

    class_select(choice_class, player_class, player_stats, character_p);

    printf("\n1. Easy\n2. Medium\n3. Hard\n");
    printf("\nChoose difficulty: ");

    int choice_difficulty;
    scanf("%d", &choice_difficulty);

    char difficulty_setting[16];

    switch (choice_difficulty)
    {
    case 1:
        strcpy(difficulty_setting, "Easy");
        character.hp += 10;
        character.mana += 5;
        character.attack += 5;
        break;

    case 2:
        strcpy(difficulty_setting, "Medium");
        break;

    case 3:
        strcpy(difficulty_setting, "Hard");
        character.hp -= 10;
        character.mana -= 5;
        character.attack += 10;
        break;

    default:
        printf("> Invalid input...");
        break;
    }

    printf("> Player class: %s\n\n", character.player_class);
    printf("====================");
    printf("\n\n  CHARACTER SHEET  \n\n");
    printf("====================");
    printf("\n       <INFO>     \n\n");
    printf("> Name: %s\n\n> Class: %s\n\n", character.name, character.player_class);
    printf("--------------------");
    printf("\n      <STATS>     \n\n");
    printf("> Hp: %d\n\n> Mana: %d\n\n> Attack: %d\n\n", character.hp, character.mana, character.attack);
    printf("====================");
}

void class_select (int choice_class, char player_class[][31], int player_stats[][3], struct Character *character_p)
{
    strcpy(character_p->player_class, player_class[choice_class - 1]);
    character_p->hp = player_stats[choice_class - 1][0];
    character_p->mana = player_stats[choice_class - 1][1];
    character_p->attack = player_stats[choice_class - 1][2];

}