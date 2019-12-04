#include <gtk/gtk.h>

typedef struct
{
char nom[20];
char depart[20];
char retour[20];
char date_depart[20];
char date_retour[20];
}vol;

void ajouter_vol(vol v);
void afficher_vol(GtkWidget *liste);
