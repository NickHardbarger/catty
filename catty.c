#include <vte/vte.h>

#include "config.h"

static void child_ready(VteTerminal *terminal, GPid pid, GError *error,
                        gpointer user_data) {
  if (!terminal)
    return;
  if (pid == -1)
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
  GtkWidget *window, *terminal;

  gtk_init(&argc, &argv);
  terminal = vte_terminal_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "catty");

  vte_terminal_set_colors(
      VTE_TERMINAL(terminal), &CLR_GDK(fg, 1), &CLR_GDK(bg, opacity),
      (const GdkRGBA[]){CLR_GDK(col0, 1), CLR_GDK(col1, 1), CLR_GDK(col2, 1),
                        CLR_GDK(col3, 1), CLR_GDK(col4, 1), CLR_GDK(col5, 1),
                        CLR_GDK(col6, 1), CLR_GDK(col7, 1), CLR_GDK(col8, 1),
                        CLR_GDK(col9, 1), CLR_GDK(col10, 1), CLR_GDK(col11, 1),
                        CLR_GDK(col12, 1), CLR_GDK(col13, 1), CLR_GDK(col14, 1),
                        CLR_GDK(col15, 1)},
      16);
  /* WARNING: this function is deprecated! */
  gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL,
                                       &CLR_GDK(bg, opacity));

  PangoFontDescription *pfd = pango_font_description_new();
  pango_font_description_set_size(pfd, FONT_SIZE * PANGO_SCALE);
  pango_font_description_set_family(pfd, FONT);
  vte_terminal_set_font(VTE_TERMINAL(terminal), pfd);

  gchar **envp = g_get_environ();
  gchar **command =
      (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL};
  g_strfreev(envp);
  vte_terminal_spawn_async(VTE_TERMINAL(terminal), VTE_PTY_DEFAULT,
                           NULL,        /* working directory  */
                           command,     /* command */
                           NULL,        /* environment */
                           0,           /* spawn flags */
                           NULL, NULL,  /* child setup */
                           NULL,        /* child pid */
                           -1,          /* timeout */
                           NULL,        /* cancellable */
                           child_ready, /* callback */
                           NULL);       /* user_data */

  g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
  g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);

  gtk_container_add(GTK_CONTAINER(window), terminal);
  gtk_widget_show_all(window);
  gtk_main();
}
