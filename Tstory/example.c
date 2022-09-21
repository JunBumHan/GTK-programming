#include <gtk/gtk.h>

static void activate(GtkApplication * app, gpointer user_data)
{
    GtkWidget *window;

    window = gtk_application_window_new(app);   
    // GtkApplication 객체에 기본 윈도우에 생성 및 등록한다.


    
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    /*
     *  윈도우 제목 설정
     *  window는 GtkWidget 객체로 선언했기 때문에 GEK_WINDOW()를 이용해 매크로 형변환을 해주어야 한다.   
     */  

    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 1000);   
    // 윈도우의 기본 크기를 설정한다.

    gtk_widget_show(window);
    // 윈도우 위젯을 드로잉함

}

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("jb.jb", G_APPLICATION_FLAGS_NONE);
    // 어플리케이션 이름은 도메인 주소와 유사한 형식을 사용함.

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    /*
     * g_application_run() api 호출 시, activate 시그널이 발생함.
     * 따라서 activate 시그널이 발생할 때, 등록한 콜백 함수를 호출함.
     */
    
    status = g_application_run(G_APPLICATION(app), argc, argv);
    /*
     * 실제 어플리케이션 동작하는 메인 루프 이며, 어플리케이션이 종료되기 전까지는 다음으로 넘어가지 않는다.
     */
    g_object_unref(app);
    return status;
}