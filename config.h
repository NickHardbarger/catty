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

static int fg = 0xffffff;
static int bg = 0x000000;
static float opacity = 0.85;

static int col0 = 0x282828;
static int col1 = 0xcc241d;
static int col2 = 0x98971a;
static int col3 = 0xd79921;
static int col4 = 0x458588;
static int col5 = 0xb16286;
static int col6 = 0x689d6a;
static int col7 = 0xa89984;
static int col8 = 0x928374;
static int col9 = 0xfb4934;
static int col10 = 0xb8bb26;
static int col11 = 0xfabd2f;
static int col12 = 0x83a598;
static int col13 = 0xb85e7b;
static int col14 = 0x8ec07c;
static int col15 = 0xebdbb2;
