#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc, &argv); // gtk 를 초기화 하고 일부 표준 옵션을 구문 분석하며, gtk 함수를 사용하기 전에 호출되어야 함.

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // 다른 위젯을 포함할 수 있는 최상위 창을 만드며, 창 유형은 GTK_WINDOW_TOPLEVEL 이다.
    gtk_widget_show(window);    // 생성한 위젯을 보여주는 것 같다.

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);   // 

    gtk_main();

    return 0;

}