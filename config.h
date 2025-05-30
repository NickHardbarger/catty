#define FONT "JetBrainsMonoNF"
#define FONT_SIZE 12

#define CLR_R(x) (((x) & 0xff0000) >> 16)
#define CLR_G(x) (((x) & 0x00ff00) >> 8)
#define CLR_B(x) (((x) & 0x0000ff) >> 0)
#define CLR_16(x) ((double)(x) / 0xff)
#define CLR_GDK(x, y)                                                          \
  (const GdkRGBA) {                                                            \
    .red = CLR_16(CLR_R(x)), .green = CLR_16(CLR_G(x)),                        \
    .blue = CLR_16(CLR_B(x)), .alpha = y                                       \
  }
vte_terminal_set_colors(
    VTE_TERMINAL(terminal), &CLR_GDK(0xffffff, 1), &(GdkRGBA){.alpha = 0.85},
    (const GdkRGBA[]){
        CLR_GDK(0x282828, 1), CLR_GDK(0xcc241d, 1), CLR_GDK(0x98971a, 1),
        CLR_GDK(0xd79921, 1), CLR_GDK(0x458588, 1), CLR_GDK(0xb16286, 1),
        CLR_GDK(0x689d6a, 1), CLR_GDK(0xa89984, 1), CLR_GDK(0x928374, 1),
        CLR_GDK(0xfb4934, 1), CLR_GDK(0xb8bb26, 1), CLR_GDK(0xfabd2f, 1),
        CLR_GDK(0x83a598, 1), CLR_GDK(0xb85e7b, 1), CLR_GDK(0x8ec07c, 1),
        CLR_GDK(0xebdbb2, 1)},
    16);
gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL,
                                     &CLR_GDK(0x000000, 0.85));
