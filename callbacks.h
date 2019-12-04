#include <gtk/gtk.h>


void
on_recherche_clicked                   (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ajouter_vol_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour1_enter                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_RechercheVol_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_res_rech_vol_destroy                (GtkObject       *object,
                                        gpointer         user_data);

void
on_ajoutvol_destroy                    (GtkObject       *object,
                                        gpointer         user_data);

void
on_quit1_destroy                       (GtkObject       *object,
                                        gpointer         user_data);

void
on_quit2_destroy                       (GtkObject       *object,
                                        gpointer         user_data);

gboolean
on_treeview1_select_cursor_row         (GtkTreeView     *treeview,
                                        gboolean         start_editing,
                                        gpointer         user_data);

void
on_delete_vol_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_mod_vol_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_treeview1_popup_menu                (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_retour_mod_vol_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_enr_mod_vol_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_treeview1_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_vol_del_ok_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_enter                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_supp_vol_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_valider_choix_mod_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_entrynom_mod_backspace              (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_entrynom_mod_paste_clipboard        (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_retour_cmv_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_drag_data_get             (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        GtkSelectionData *data,
                                        guint            info,
                                        guint            time,
                                        gpointer         user_data);

void
on_treeview1_selection_received        (GtkWidget       *widget,
                                        GtkSelectionData *data,
                                        guint            time,
                                        gpointer         user_data);

void
on_enr_mod_vol_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_rech_vol_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_combobox1_add                       (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data);
