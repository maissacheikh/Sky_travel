#include <stdio.h>
#include <string.h>
#include "vol.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <wctype.h>

enum{
ID,
NOM,
DEPART,
RETOUR,
DATEDEPART,
DATERETOUR,
COLUMNS};

void ajouter_vol(vol v)
{FILE *f;
vol h;
int i=0;
f=fopen("vol.txt","r");
strcpy(h.nom,v.nom);
strcpy(h.depart,v.depart);
strcpy(h.retour,v.retour);
h.d_depart.j=v.d_depart.j;
h.d_depart.m=v.d_depart.m;
h.d_depart.a=v.d_depart.a;
h.d_retour.j=v.d_retour.j;
h.d_retour.m=v.d_retour.m;
h.d_retour.a=v.d_retour.a;
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
{i=v.id;}
fclose(f);
f=fopen("vol.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",i+1,h.nom,h.depart,h.retour,h.d_depart.j,
h.d_depart.m,h.d_depart.a,h.d_retour.j,h.d_retour.m,h.d_retour.a);
fclose(f);}

void afficher_vol(GtkWidget *liste)
{
GtkWidget *treeview1;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
vol v;
int id;
char nom[20];
char depart[20];
char retour[20];
DATE d_depart;
DATE d_retour;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);

char date_depart[20];
char date_retour[20];



if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer, "text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer, "text",NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" retour", renderer, "text",RETOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_depart", renderer, "text",DATEDEPART, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_retour", renderer, "text",DATERETOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("vol.txt","r");

if(f==NULL)
{
return;
}
else
{f=fopen("vol.txt","a+");
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
{
sprintf(date_depart,"%d/%d/%d",v.d_depart.j,v.d_depart.m,v.d_depart.a);
sprintf(date_retour,"%d/%d/%d",v.d_retour.j,v.d_retour.m,v.d_retour.a);
gtk_list_store_append(store, &iter);
gtk_list_store_set (store, &iter, ID, v.id, NOM, v.nom, DEPART, v.depart, RETOUR, v.retour,DATEDEPART,date_depart,DATERETOUR,date_retour, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}}
}

void delete_vol(int test,vol v)
{FILE *f,*h;
f=fopen("vol.txt","r");
if(f!=NULL)
{h=fopen("voltest.txt","w+");
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
if(v.id!=test)
fprintf(h,"%d %s %s %s %d/%d/%d %d/%d/%d\n",v.id,v.nom,v.depart,v.retour,v.d_depart.j,
v.d_depart.m,v.d_depart.a,v.d_retour.j,v.d_retour.m,v.d_retour.a);
}else printf("File Not opened");
fclose(f);
fclose(h);
f=fopen("vol.txt","w+");
h=fopen("voltest.txt","r");
while (fscanf(h,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",v.id,v.nom,v.depart,v.retour,v.d_depart.j,
v.d_depart.m,v.d_depart.a,v.d_retour.j,v.d_retour.m,v.d_retour.a);
fclose(f);fclose(h);}


void modifier_vol(vol v,int a)
{FILE *f;vol h;
strcpy(h.nom,v.nom);
strcpy(h.depart,v.depart);
strcpy(h.retour,v.retour);
h.d_depart.j=v.d_depart.j;
h.d_depart.m=v.d_depart.m;
h.d_depart.a=v.d_depart.a;
h.d_retour.j=v.d_retour.j;
h.d_retour.m=v.d_retour.m;
h.d_retour.a=v.d_retour.a;
f=fopen("vol.txt","r");
if(f!=NULL)
{while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
if(v.id==a)
{delete_vol(a,v);
close(f);
}
}
f=fopen("vol.txt","a+");
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",a,h.nom,h.depart,h.retour,h.d_depart.j,
h.d_depart.m,h.d_depart.a,h.d_retour.j,h.d_retour.m,h.d_retour.a);
fclose(f);
}

int verif(int a,vol v)
{
FILE *f;
int e=0;
f=fopen("vol.txt","r");
if(f!=NULL)
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
{if (a==v.id)
e=1;}
fclose(f);
return e;
}


