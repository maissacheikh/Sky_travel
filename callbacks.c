#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"



void on_recherche_clicked (GtkButton *objet,gpointer user_data)
{
GtkWidget *ajoutvol;
GtkWidget *res_rech_vol;
GtkWidget *treeview1;
GtkWidget *RechercheVol;
GtkWidget *combobox1,*combobox2,*jourd,*jourr,*moisd,*moisr,*anneed,*anneer,*sortie;

RechercheVol=lookup_widget(objet,"RechercheVol");
combobox1=lookup_widget(objet,"combobox1");
combobox2=lookup_widget(objet,"combobox2");
jourd=lookup_widget(objet,"j_d_depart");
moisd=lookup_widget(objet,"m_d_depart");
anneed=lookup_widget(objet,"a_d_depart");
jourr=lookup_widget(objet,"j_d_retour");
moisr=lookup_widget(objet,"m_d_retour");
anneer=lookup_widget(objet,"a_d_retour");
sortie=lookup_widget(objet,"mess_rech");
if (gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneed))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneer)))
gtk_label_set_text(GTK_LABEL(sortie),"Date erroné");
else if ((gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisd))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisr)))&&(gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneed))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneer))))
gtk_label_set_text(GTK_LABEL(sortie),"Date erroné");
else if ((gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourd))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr)))&&((gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisd))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisr)))&&(gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneed))>gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneer)))))
gtk_label_set_text(GTK_LABEL(sortie),"Date erroné");
else{
gtk_widget_destroy(RechercheVol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);

treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}
}


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_ajouter_vol_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
vol v;
GtkWidget *input1, *input2, *input3,*Jour,*Mois,*Annee,*jour,*mois,*annee;
GtkWidget *ajoutvol,*res_rech_vol,*treeview1;

ajoutvol=lookup_widget(objet,"ajoutvol");

input1=lookup_widget(objet,"nom");
input2=lookup_widget(objet,"depart");
input3=lookup_widget(objet,"retour");
Jour=lookup_widget(objet,"j_d_depart");
Mois=lookup_widget(objet,"m_d_depart");
Annee=lookup_widget(objet,"a_d_depart");
jour=lookup_widget(objet,"j_d_retour");
mois=lookup_widget(objet,"m_d_retour");
annee=lookup_widget(objet,"a_d_retour");
strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.retour,gtk_entry_get_text(GTK_ENTRY(input3)));
v.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
v.d_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
v.d_depart.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
v.d_retour.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
v.d_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
v.d_retour.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

ajouter_vol(v);
ajoutvol=lookup_widget(objet,"ajoutvol");

gtk_widget_destroy(ajoutvol);

res_rech_vol=create_res_rech_vol();
gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}


void
on_retourajout_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *res_rech_vol, *ajoutvol,*treeview1;

ajoutvol=lookup_widget(objet,"ajoutvol");

gtk_widget_destroy(ajoutvol);

res_rech_vol=create_res_rech_vol();
gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}


void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *res_rech_vol, *ajoutvol;

res_rech_vol=lookup_widget(objet,"res_rech_vol");

gtk_widget_destroy(res_rech_vol);
ajoutvol=create_ajoutvol();
gtk_widget_show(ajoutvol);

}


void
on_retour2_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajoutvol;
GtkWidget *res_rech_vol;
GtkWidget *treeview1;
GtkWidget *RechercheVol;

res_rech_vol=lookup_widget(objet,"res_rech_vol");


gtk_widget_destroy(res_rech_vol);
RechercheVol=lookup_widget(objet,"RechercheVol");
RechercheVol=create_RechercheVol();

gtk_widget_show(RechercheVol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}


void
on_delete_vol_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *res_rech_vol;
GtkWidget *del_vol;

res_rech_vol=lookup_widget(objet,"res_rech_vol");


gtk_widget_destroy(res_rech_vol);
del_vol=lookup_widget(objet,"del_vol");
del_vol=create_del_vol();

gtk_widget_show(del_vol);
}


void
on_mod_vol_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{ 
GtkWidget *mod_vol_choix;
GtkWidget *res_rech_vol;

res_rech_vol=lookup_widget(objet,"res_rech_vol");


gtk_widget_destroy(res_rech_vol);
mod_vol_choix=lookup_widget(objet,"mod_vol_choix");
mod_vol_choix=create_mod_vol_choix();

gtk_widget_show(mod_vol_choix);
}


void
on_retour_mod_vol_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_vol;
GtkWidget *res_rech_vol,*treeview1;

mod_vol=lookup_widget(objet,"mod_vol");


gtk_widget_destroy(mod_vol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}






void
on_vol_del_ok_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *del_vol;
GtkWidget *res_rech_vol,*treeview1;
vol v;
int test;
input=lookup_widget(objet,"vol_del");
test=atof(gtk_entry_get_text(GTK_ENTRY(input)));
delete_vol(test,v);
del_vol=lookup_widget(objet,"del_vol");


gtk_widget_destroy(del_vol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}


void
on_retour_supp_vol_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *del_vol;
GtkWidget *res_rech_vol,*treeview1;

del_vol=lookup_widget(objet,"del_vol");


gtk_widget_destroy(del_vol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}




void
on_valider_choix_mod_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *mod_vol_choix;
GtkWidget *mod_vol,*nom,*depart,*retour,*dj,*dm,*da,*rj,*rm,*ra,*ID;
vol v;
int x;
FILE *f;
char id[5];

input=lookup_widget(objet,"entry_choix_mod_vol");
x=atof(gtk_entry_get_text(GTK_ENTRY(input)));
if ((verif(x,v)))
{mod_vol_choix=lookup_widget(objet,"mod_vol_choix");
gtk_widget_destroy(mod_vol_choix);
mod_vol=lookup_widget(objet,"mod_vol");
mod_vol=create_mod_vol();
gtk_widget_show(mod_vol);
f=fopen("vol.txt","r");
ID=lookup_widget(mod_vol,"ID_fix");
nom=lookup_widget(mod_vol,"entrynom_mod");
depart=lookup_widget(mod_vol,"entrydepart_mod");
retour=lookup_widget(mod_vol,"entryretour_mod");
dj=lookup_widget(mod_vol,"j_d_depart");
dm=lookup_widget(mod_vol,"m_d_depart");
da=lookup_widget(mod_vol,"a_d_depart");
rj=lookup_widget(mod_vol,"j_d_retour");
rm=lookup_widget(mod_vol,"m_d_retour");
ra=lookup_widget(mod_vol,"a_d_retour");

if(f!=NULL)
{while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
{if(x==v.id)
{sprintf(id,"%d",v.id);
gtk_entry_set_text(GTK_ENTRY(ID),id);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(ID),v.id);
gtk_entry_set_text(GTK_ENTRY(nom),v.nom);
gtk_entry_set_text(GTK_ENTRY(depart),v.depart);
gtk_entry_set_text(GTK_ENTRY(retour),v.retour);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(dj),v.d_depart.j);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(dm),v.d_depart.m);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(da),v.d_depart.a);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(rj),v.d_retour.j);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(rm),v.d_retour.m);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(ra),v.d_retour.a);
}}}}fclose(f);
}

void
on_retour_cmv_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_vol_choix;
GtkWidget *res_rech_vol,*treeview1;

mod_vol_choix=lookup_widget(objet,"mod_vol_choix");


gtk_widget_destroy(mod_vol_choix);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();

gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");

afficher_vol(treeview1);
}

void
on_enr_mod_vol_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *mod_vol_choix;
GtkWidget *mod_vol,*nom,*depart,*retour,*dj,*dm,*da,*rj,*rm,*ra,*ID;
GtkWidget *res_rech_vol,*treeview1;
vol v;
char id[5];
FILE *f;
ID=lookup_widget(objet,"ID_fix");
nom=lookup_widget(objet,"entrynom_mod");
depart=lookup_widget(objet,"entrydepart_mod");
retour=lookup_widget(objet,"entryretour_mod");
dj=lookup_widget(objet,"j_d_depart");
dm=lookup_widget(objet,"m_d_depart");
da=lookup_widget(objet,"a_d_depart");
rj=lookup_widget(objet,"j_d_retour");
rm=lookup_widget(objet,"m_d_retour");
ra=lookup_widget(objet,"a_d_retour");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(ID)));
v.id=atof(id);
strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(depart)));
strcpy(v.retour,gtk_entry_get_text(GTK_ENTRY(retour)));
v.d_depart.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dj));
v.d_depart.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dm));
v.d_depart.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(da));
v.d_retour.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rj));
v.d_retour.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rm));
v.d_retour.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ra));
delete_vol(atof(id),v);
f=fopen("vol.txt","a+");
fprintf(f,"%d %s %s %s %d/%d/%d %d/%d/%d",v.id,v.nom,v.depart,v.retour,v.d_depart.j,v.d_depart.m,v.d_depart.a,v.d_retour.j,v.d_retour.m,v.d_retour.a);
fclose(f);
mod_vol=lookup_widget(objet,"mod_vol");
gtk_widget_destroy(mod_vol);
res_rech_vol=lookup_widget(objet,"res_rech_vol");
res_rech_vol=create_res_rech_vol();
gtk_widget_show(res_rech_vol);
treeview1=lookup_widget(res_rech_vol,"treeview1");
afficher_vol(treeview1);
}


void
on_rech_vol_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *menu_X,*RechercheVol;
GtkWidget *combobox1,*combobox2;
FILE *f=fopen("vol.txt","r"),*d=fopen("depart.txt","w+"),*r=fopen("retour.txt","w+");
vol v;
int i,j,k,nbr,n=0,x;
char villed[50][10];
char viller[50][10];
menu_X=lookup_widget(objet,"menu_X");
gtk_widget_destroy(menu_X);
RechercheVol=lookup_widget(objet,"RechercheVol");
RechercheVol=create_RechercheVol();
gtk_widget_show(RechercheVol);
combobox1=lookup_widget(RechercheVol,"combobox1");
combobox2=lookup_widget(RechercheVol,"combobox2");
if (f!=NULL)
while (fscanf(f,"%d %s %s %s %d/%d/%d %d/%d/%d\n",&v.id,v.nom,v.depart,v.retour,&v.d_depart.j,&
v.d_depart.m,&v.d_depart.a,&v.d_retour.j,&v.d_retour.m,&v.d_retour.a)!=EOF)
{
strcpy(villed[n],v.depart);
fprintf(d,"%s\n",villed[n]);
strcpy(viller[n],v.retour);
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1),_(villed[n]));
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),_(viller[n]));
fprintf(r,"%s\n",viller[n]);
n++;}
nbr=n;
d=fopen("depart.txt","w+");
r=fopen("retour.txt","w+");


fclose(d);
fclose(r);
fclose(f);
}
/*while(fscanf(d,"%s\n",villed[i])!=EOF)
{for (i=0;i<n;i++){+q+d
for (j=i+1;j<n;j++){
if (strcmp(villed[j],villed[i])==0){
for(k=j;k<n;k++){
strcpy(villed[k],villed[k+1]);
fprintf(d,"%s\n",villed[k]);}
n--;}else j++;}}}
for(i=0;i<n;i++)
while(fscanf(r,"%s\n",viller[i])!=EOF)
{for (i=0;i<nbr;i++){
for (j=i+1;j<nbr;j++){
if (strcmp(villed[j],villed[i])==0){
for(k=j;k<nbr;k++){
strcpy(villed[k],villed[k+1]);}
nbr--;}else j++;}*/

