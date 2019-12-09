#include <stdio.h>
#include <string.h>
#include "adherent.h"
#include <gtk/gtk.h>
#include <stdlib.h>
void ajouter_adherent(Adherent ad)
{FILE *f;
FILE *H;
int a=0;
Adherent h;
f=fopen("adherent.txt","r");

strcpy(h.nom,ad.nom);
strcpy(h.prenom,ad.prenom);
h.cin=ad.cin;
strcpy(h.adressemail,ad.adressemail);
strcpy(h.adresse,ad.adresse);
h.telephone=ad.telephone;
h.datenaissance.j=ad.datenaissance.j;
h.datenaissance.m=ad.datenaissance.m;
h.datenaissance.a=ad.datenaissance.a;
strcpy(h.Username,ad.Username);
strcpy(h.password,ad.password);

while(fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.adressemail,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.Username,ad.password)!=EOF){if (a<=ad.id)
a=ad.id;}
fclose(f);
H=fopen("users.txt","a+");
f=fopen("adherent.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",a+1,h.nom,h.prenom,h.cin,h.adressemail,h.adresse,h.telephone,h.datenaissance.j,h.datenaissance.m,h.datenaissance.a,h.Username,h.password);

fprintf(H,"%s %s %d\n",ad.Username,ad.password,3);
fclose(H);

fclose(f);
}

int verifier_adherent(char username[20])
{
FILE *H;
char login[20], password[20];
int role,t=0;

H=fopen("users.txt","r");
if(H!=NULL)
while(fscanf(H,"%s %s %d\n",login,password,&role)!=EOF)
if ((strcmp(login,username))==0)
t=1;
fclose(H);
return (t);}

void supp_adherent(char username[20],Adherent ad)
{
FILE *f,*h;

f=fopen("adherent.txt","r");
h=fopen("testadherent.txt","w+");

if(f!=NULL)
while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.adressemail,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.Username,ad.password)!=EOF)
{if (strcmp(username,ad.Username)!=0)
fprintf(h,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",ad.id,ad.nom,ad.prenom,ad.cin,ad.adressemail,ad.adresse,ad.telephone,ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a,ad.Username,ad.password);
}

fclose(f);
fclose(h);
f=fopen("adherent.txt","w+");
h=fopen("testadherent.txt","r");

while(fscanf(h,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.adressemail,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.Username,ad.password)!=EOF)
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",ad.id,ad.nom,ad.prenom,ad.cin,ad.adressemail,ad.adresse,ad.telephone,ad.datenaissance.j,ad.datenaissance.m,ad.datenaissance.a,ad.Username,ad.password);
fclose(f);
fclose(h);
}

void enregistrerusername(char usetest[20])
{
FILE *f ,*h;
Adherent ad;
f=fopen("adherent.txt","r");
if(f!=NULL)
{
while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.adressemail,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.Username,ad.password)!=EOF)
if(strcmp(ad.Username,usetest)==0)
h=fopen("username.txt","w+");
fprintf(h,"%s",usetest);
fclose(f);
fclose(h);
}}



void  modifierad (Adherent v,int a)
{ FILE *f;Adherent av ;

f=fopen ( "adherent.txt " , "r" );
if (f!=NULL )
{ while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&v.id,v.nom,v.prenom,&v.cin,v.adressemail,v.adresse,&v.telephone,&v.datenaissance.j,&v.datenaissance.m,&v.datenaissance.a,v.Username,v.password)!=EOF)
if(v.id==a) 
av.id=v.id;
supp_adherent(v.nom,v);
fclose(f);
}

f=fopen("adherent.txt","a+");
fprintf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",av.id,av.nom,av.prenom,av.cin,av.adressemail,av.adresse,av.telephone,av.datenaissance.j,av.datenaissance.m,av.datenaissance.a,av.Username,av.password);
fclose (f);
}
















