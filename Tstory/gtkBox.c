#include <gtk/gtk.h>

static void clicked(GtkButton* button, gpointer user_data)
{
    gtk_button_set_label(button, "Clicked");
}

static void activate(GtkApplication* app, gpointer user_data)
{
    gtkWidget* window;
    gtkWidget* box;
    gtkWidget* label;
    gtkWidget* button;

    
}