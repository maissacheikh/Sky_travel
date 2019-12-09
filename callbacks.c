#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include <string.h>
#include "support.h"
#include "authentification.h"
#include "adherent.h"
#include <stdlib.h>


void
on_buttonsignin_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*output;
GtkWidget *nomcompte;
GtkWidget *fenetreadherent;GtkWidget *authentification,*fenetreadmin,*fenetreagent;
Adherent ad;
char use[20];char pwd[20];int x;
input1=lookup_widget(objet_graphique,"entryusername");
input2=lookup_widget(objet_graphique,"entrypassword");
strcpy(use,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(pwd,gtk_entry_get_text(GTK_ENTRY(input2)));
x=verifier(use,pwd);

switch (x)
{
case (1):{
	authentification=lookup_widget(objet_graphique,"authentification");
	gtk_widget_destroy(authentification);
	fenetreadmin=lookup_widget(objet_graphique,"fenetreadmin");
	fenetreadmin=create_fenetreadmin();
	gtk_widget_show(fenetreadmin);
	break;}

case (2):{
	authentification=lookup_widget(objet_graphique,"authentification");
	gtk_widget_destroy(authentification);
	fenetreagent=lookup_widget(objet_graphique,"fenetreagent");
	fenetreagent=create_fenetreadmin();
	gtk_widget_show(fenetreagent);
	break ;}

case (3):{		
	authentification=lookup_widget(objet_graphique,"authentification");
	gtk_widget_destroy(authentification);
	fenetreadherent=lookup_widget(objet_graphique,"fenetreadherent");
	fenetreadherent=create_fenetreadherent();
	gtk_widget_show(fenetreadherent);
	enregistrerusername(use);
	nomcompte=lookup_widget(fenetreadherent,"label15");
	gtk_entry_set_text(GTK_ENTRY(nomcompte),use);
	break;}

}
}


void
on_buttoncontinuervisiteur_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_buttoncreercompte_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *authentification,*creeruncompte;
authentification=lookup_widget(button,"authentification");
	gtk_widget_destroy(authentification);
	creeruncompte=lookup_widget(button,"creeruncompte");
	creeruncompte=create_creeruncompte();
	gtk_widget_show(creeruncompte);
}



void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data)

{Adherent ad;
int jour,mois,annee,t;char login[20];
GtkWidget *msg,*input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11,*creeruncompte,*authentification;
creeruncompte=lookup_widget(button,"creeruncompte");
input1=lookup_widget(button,"entrynom");
input2=lookup_widget(button,"entryprenom");
input3=lookup_widget(button,"entrycin");
input4=lookup_widget(button,"entrymail");
input5=lookup_widget(button,"entryadresse");
input6=lookup_widget(button,"entrynum");
input7=lookup_widget(button,"spinbuttonjour");
input8=lookup_widget(button,"spinbuttonmois");
input9=lookup_widget(button,"spinbuttonannee");
input10=lookup_widget(button,"entryuse");
input11=lookup_widget(button,"entrypwd");
if(verifier_adherent(gtk_entry_get_text(GTK_ENTRY(input10)))==0)
{strcpy(ad.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ad.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
ad.cin=atof(gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ad.adressemail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ad.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
strcpy(ad.Username,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(ad.password,gtk_entry_get_text(GTK_ENTRY(input11)));
ad.telephone=atof(gtk_entry_get_text(GTK_ENTRY(input6)));
ad.datenaissance.j=jour;
ad.datenaissance.m=mois;
ad.datenaissance.a=annee;
ajouter_adherent(ad);
gtk_widget_destroy(creeruncompte);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);}else
{msg=lookup_widget(button,"msg_err");
gtk_label_set_text(GTK_LABEL(msg),"Username non disponible");}

}



void
on_buttondeconnecter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *authentification, *fenetreadmin;
fenetreadmin=lookup_widget(button,"fenetreadmin");
gtk_widget_destroy(fenetreadmin);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);

}


void
on_buttondeconnecteradherent_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *authentification, *fenetreadherent;
fenetreadherent=lookup_widget(button,"fenetreadherent");
gtk_widget_destroy(fenetreadherent);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);

}


void
on_buttondeconnecteradmin_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *authentification, *fenetreadmin;
fenetreadmin=lookup_widget(button,"fenetreadmin");
gtk_widget_destroy(fenetreadmin);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);

}


void
on_buttonretour_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *authentification, *creeruncompte;
creeruncompte=lookup_widget(button,"creeruncompte");
gtk_widget_destroy(creeruncompte);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);

}


void
on_buttoncompteagent_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fenetreagent,*parametrescompte;
fenetreagent=lookup_widget(button,"fenetreagent");
	gtk_widget_destroy(fenetreagent);
	parametrescompte=lookup_widget(button,"parametrescompte");
	parametrescompte=create_parametrescompte();
	gtk_widget_show(parametrescompte);

}


void
on_buttoncompteadherent_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetreadherent,*parametrescompte,*input1,*user,*nom,*prenom,*cin,*mail,*adresse,*num,*jour,*mois,*annee,*use,*pwd;
FILE *f,*h;
Adherent ad;
char cinaux[20];
char telaux[20];
char username[20];

	fenetreadherent=lookup_widget(objet,"fenetreadherent");
	gtk_widget_destroy(fenetreadherent);
	parametrescompte=lookup_widget(objet,"parametrescompte");
	parametrescompte=create_parametrescompte();
	gtk_widget_show(parametrescompte);

f=fopen("adherent.txt","r");
h=fopen("username.txt","r");	
nom=lookup_widget(parametrescompte,"entrynommodif");
prenom=lookup_widget(parametrescompte,"entryprenommodif");
cin=lookup_widget(parametrescompte,"entrycinmodif");
mail=lookup_widget(parametrescompte,"entrymailmodif");
adresse=lookup_widget(parametrescompte,"entryadressemodif");
num=lookup_widget(parametrescompte,"entrynummodif");
jour=lookup_widget(parametrescompte,"spinbuttonjourmodif");
mois=lookup_widget(parametrescompte,"spinbuttonmoismodif");
annee=lookup_widget(parametrescompte,"spinbuttonanneemodif");
use=lookup_widget(parametrescompte,"entryusermodif");
pwd=lookup_widget(parametrescompte,"entrypassmodif");
while (fscanf(h,"%s",username)!=EOF)
{while (fscanf(f,"%d %s %s %d %s %s %d %d/%d/%d %s %s\n",&ad.id,ad.nom,ad.prenom,&ad.cin,ad.adressemail,ad.adresse,&ad.telephone,&ad.datenaissance.j,&ad.datenaissance.m,&ad.datenaissance.a,ad.Username,ad.password)!=EOF) 
if (strcmp(ad.Username,username)==0)
{
gtk_entry_set_text(GTK_ENTRY(nom),ad.nom);
gtk_entry_set_text(GTK_ENTRY(prenom),ad.prenom);
sprintf(cinaux,"%d",ad.cin);
gtk_entry_set_text(GTK_ENTRY(cin),cinaux);
gtk_entry_set_text(GTK_ENTRY(mail),ad.adressemail);
gtk_entry_set_text(GTK_ENTRY(adresse),ad.adresse);
sprintf(telaux,"%d",ad.telephone);
gtk_entry_set_text(GTK_ENTRY(num),telaux);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),ad.datenaissance.j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),ad.datenaissance.m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),ad.datenaissance.a);
gtk_entry_set_text(GTK_ENTRY(use),ad.Username);
gtk_entry_set_text(GTK_ENTRY(pwd),ad.password);


fclose(f);
fclose(h);}
}}

void
on_buttoncompteadmin_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fenetreadmin,*parametrescompte;
fenetreadmin=lookup_widget(button,"fenetreadmin");
	gtk_widget_destroy(fenetreadmin);
	parametrescompte=lookup_widget(button,"parametrescompte");
	parametrescompte=create_parametrescompte();
	gtk_widget_show(parametrescompte);


}


void
on_buttonconfirmermodif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *fenetreadherent,*parametrescompte,*use,*nomcompte,*input1;
Adherent ad;
char username[20];
FILE *f=fopen("username.txt","r");

parametrescompte=lookup_widget(button,"parametrescompte");
	gtk_widget_destroy(parametrescompte);
	fenetreadherent=lookup_widget(button,"fenetreadherent");
	fenetreadherent=create_fenetreadherent();
	gtk_widget_show(fenetreadherent);

while(fscanf(f,"%s",username)!=EOF)
{input1=lookup_widget(fenetreadherent,"label15");
gtk_entry_set_text(GTK_ENTRY(input1),username);}
}


void
on_buttonretourfenetreadherent_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetreadherent, *parametrescompte,*input1;
Adherent ad;
FILE *f=fopen("username.txt","r");
char username[20];
parametrescompte=lookup_widget(button,"parametrescompte");
gtk_widget_destroy(parametrescompte);
fenetreadherent=lookup_widget(button,"fenetreadherent");
fenetreadherent=create_fenetreadherent();
gtk_widget_show(fenetreadherent);
while(fscanf(f,"%s",username)!=EOF)
{input1=lookup_widget(fenetreadherent,"label15");
gtk_entry_set_text(GTK_ENTRY(input1),username);}
fclose(f);
}


void
on_buttonsupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *parametrescompte,*authentification;
GtkWidget *input;
Adherent ad;
char username[20];
FILE *f=fopen("username.txt","r");
while(fscanf(f,"%s",username)!=EOF)
supp_adherent(username,ad);

parametrescompte=lookup_widget(button,"parametrescompte");
gtk_widget_destroy(parametrescompte);
authentification=lookup_widget(button,"authentification");
authentification=create_authentification();
gtk_widget_show(authentification);
}


