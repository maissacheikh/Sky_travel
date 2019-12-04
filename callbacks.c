#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"


void
on_recherche_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutvol;
GtkWidget *res_rech_vol;
GtkWidget *treeview1;

ajoutvol=lookup_widget(objet,"ajoutvol");


gtk_widget_destroy(ajoutvol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);

treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);

}


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_vol_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
vol v;

GtkWidget *input1, *input2, *input3,*input4,*input5;
GtkWidget *ajoutvol;

ajoutvol=lookup_widget(objet,"ajoutvol");

input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"depart");
input3=lookup_widget(objet,"retour");
input4=lookup_widget(objet,"date_depart");
input5=lookup_widget(objet,"date_retour");

strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.retour,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.date_depart,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(input5)));

ajouter_vol(v);
}


void
on_retourajout_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{

}


void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *RechercheVol, *ajoutvol;

ajoutvol=lookup_widget(objet,"ajoutvol");

gtk_widget_destroy(RechercheVol);
ajoutvol=create_ajoutvol();
gtk_widget_show(ajoutvol);

}
