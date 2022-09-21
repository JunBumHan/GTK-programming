#include <gtk/gtk.h>

static void clicked(GtkButton* button, gpointer user_data) 
{
    gtk_button_set_label(button, "Clicked");
}

static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget* window;
    GtkWidget* button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window),1000, 700);
    
    button = gtk_button_new_with_label("Hello, world");
    /*
     * GtkButton :  클릭 가능한 위젯을 생성
     * gtk_button_new_with_label = gtk_button_new + gtk_button_set_label
     */

    g_signal_connect(button, "clicked", G_CALLBACK(clicked), NULL);
    gtk_window_set_child(GTK_WINDOW(window), button);
    gtk_widget_show(window);
}

int main(int argc, char * argv[])
{
    GtkApplication * app;
    int status;

    app = gtk_application_new("jb.jb", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}