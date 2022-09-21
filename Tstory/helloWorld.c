#include <gtk/gtk.h>

static void activate(GtkApplication * app, gpointer user_data) 
{
    GtkWidget * window;
    GtkWidget * label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    label = gtk_label_new("Hello, world");
    //GtkLabel : 간단한 텍스트를 보여주는 위젯이다.

    gtk_window_set_child(GTK_WINDOW(window), label);
    /*
     * gtk_window_set_child을 통해서 window 위젯에 label 위젯을 자식으로 추가함.
     * 자식으로 추가해야 해야지만 gtk_widget_show(window) 함수 실행 할 때 출력이 됨.
     */
    gtk_widget_show(window);
}

int main(int argc, char ** argv)
{
    GtkApplication * app;
    int status;

    app = gtk_application_new("jb.jb", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}