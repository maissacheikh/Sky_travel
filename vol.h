#include <gtk/gtk.h>

typedef struct{
int j;
int m;
int a;}DATE;

typedef struct
{
int id;
char nom[20];
char depart[20];
char retour[20];
DATE d_depart;
DATE d_retour;
}vol;


typedef struct{
int h;
int m;}HEURE;

typedef struct{
int id;
char nom[30];
char desc[255];
DATE d_excursion;
HEURE h_depart;
HEURE h_retour;}EXCURSION;

typedef struct{
int id;
char nom[30];
char ville[30];
DATE d_in;
DATE d_out;
int nb_single;
int nb_double;
int nb_triple;}HOTEL;

typedef struct{
int id;
char lieu[20];
DATE d_prise;
DATE d_retour;
HEURE h_prise;
HEURE h_retour;}VOITURE;

void ajouter_vol(vol v);
void afficher_vol(GtkWidget *liste);
void delete_vol(int test,vol v);
int verif(int a,vol v);
void modifier_vol(vol v,int a);
