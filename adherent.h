#include<gtk/gtk.h>
#include <string.h>
typedef struct {
int j;
int m;
int a;
}DATE;

typedef struct
{
int id;
char nom[50];
char prenom[50];
int cin;
char adressemail[50];
char adresse[30];
int telephone;
DATE datenaissance;
char Username[20];
char password[20];
}Adherent;
void ajouter_adherent(Adherent ad);
int verifier_adherent(char username[20]);
void supp_adherent(char username[20],Adherent ad);
void enregistrerusername(char usetest[20]);
void  modifierad(Adherent v,int a);
