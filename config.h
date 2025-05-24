#define CLR_R(x) (((x) & 0xff0000) >> 16)
#define CLR_G(x) (((x) & 0x00ff00) >> 8)
#define CLR_B(x) (((x) & 0x0000ff) >> 0)
#define CLR_16(x) ((double)(x) / 0xff)
#define CLR_GDK(x)                                                             \
  (const GdkRGBA){.red = CLR_16(CLR_R(x)),                                     \
                  .green = CLR_16(CLR_G(x)),                                   \
                  .blue = CLR_16(CLR_B(x)),                                    \
                  .alpha = 0}
vte_terminal_set_colors(
    VTE_TERMINAL(terminal), &CLR_GDK(0xffffff), &(GdkRGBA){.alpha = 0.85},
    (const GdkRGBA[]){CLR_GDK(0x282828), CLR_GDK(0xcc241d), CLR_GDK(0x98971a),
                      CLR_GDK(0xd79921), CLR_GDK(0x458588), CLR_GDK(0xb16286),
                      CLR_GDK(0x689d6a), CLR_GDK(0xa89984), CLR_GDK(0x928374),
                      CLR_GDK(0xfb4934), CLR_GDK(0xb8bb26), CLR_GDK(0xfabd2f),
                      CLR_GDK(0x83a598), CLR_GDK(0xb85e7b), CLR_GDK(0x8ec07c),
                      CLR_GDK(0xebdbb2)},
    16);
