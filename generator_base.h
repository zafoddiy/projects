/**
 * File:        generator_base.h
 * Author:      Risto Heinsar
 * Created:     12.03.2015
 * Modified     21.10.2019
 *
 * Description: Header file to provide the name pools required for the task.
 *              This should also contain the structure declaration and function
 *              declarations.
 */
#ifndef GENERATOR
#define GENERATOR

#define FIRST_NAME_POOL {"Ants", "Kadri", "Artur", "Urmas", "Mart", "Toomas",\
    "Mihhail", "Yana", "Taavi", "Edgar", "Keit", "Ivari", "Sven", "Hanno",\
    "Kristen", "Anne", "Urve", "Heimar", "Andres", "Juhan", "Rainer", "Ain",\
    "Maris", "Eiki", "Valdo", "Mihkel", "Marika", "Jevgeni", "Mailis", "Rein",\
    "Helir-Valdor", "Heidy"}
#define LAST_NAME_POOL {"Toom", "Padar", "Sulling", "Savisaar", "Helme",\
    "Ratas", "Ligi", "Paet", "Kruuse", "Talvik", "Simson", "Laaneots",\
    "Pentus-Rosimannus", "Mikser", "Pevkur", "Michal", "Stalnuhhin", "Tiidus",\
    "Lenk", "Herkel", "Parts", "Vakra", "Lutsepp", "Lauri", "Nestor",\
    "Randpere", "Raud", "Anvelt", "Tuus-Laul", "Ossinovski", "Reps", "Ratas",\
    "Seeder", "Purga"}
#define CURRICULUM_CODES {"IACB", "MVEB", "EARB"}

#define LIMIT 100

/* add your structure declaration here */

typedef struct
{
	int index;
	char *fName;
	char *lName;
	char *code;
	float admPoints;
} data;

/* function prototypes */
int GetRand(int numMin, int numMax);
float GetFloatRand(int, int);
int GetElem(void);
void Assignment(data*, int, int, int, int, char*[], char*[], char*[]);

#endif
