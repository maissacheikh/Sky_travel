#include <stdio.h>
#include <string.h>
#include "vol.h"
#include <gtk/gtk.h>
#include <stdlib.h>

enum{
NOM,
DEPART,
RETOUR,
DATE_DEPART,
DATE_RETOUR,
COLUMNS};

void ajouter_vol(vol v)
{FILE *f;
f=fopen("vol.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",v.nom,v.depart,v.retour,v.date_depart,v.date_retour);
fclose(f);}}

void afficher_vol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char depart[20];
char retour[20];
char date_depart[20];
char date_retour[20];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" retour", renderer, "text",RETOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_depart", renderer, "text",DATE_DEPART, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_retour", renderer, "text",DATE_RETOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("vol.txt","r");

if(f==NULL)
{
return;
}
else
{f=fopen("vol.txt","a+");
while(fscanf(f,"%s %s %s %s %s\n",nom,depart,retour,date_depart,date_retour)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, NOM, nom, DEPART, depart, RETOUR, retour,DATE_DEPART,date_depart,DATE_RETOUR,date_retour, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}}
}
