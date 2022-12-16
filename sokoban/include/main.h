typedef volatile unsigned short     vu16;
typedef unsigned short              u16;
typedef unsigned int                u32;
typedef volatile unsigned char      vu8;

// VERITICAL SCANLINE COUNT REGISTER
#define	REG_VCOUNT		*((vu16 *)(0x04000006))

// DISPLAY CONTROL REGISTER
#define	REG_DISPCNT		*((vu16 *)(0x04000000))

// KEY INPUT REGISTER
#define	REG_KEYINPUT		*((vu16 *)(0x04000130))
// Key bit masks for REG_KEYINPUT
#define KEY_L                   (1<<9)
#define KEY_R                   (1<<8)
#define KEY_DWN                 (1<<7)
#define KEY_UP                  (1<<6)
#define KEY_LFT                 (1<<5)
#define KEY_RT                  (1<<4)
#define KEY_ST                  (1<<3)
#define KEY_SL                  (1<<2)
#define KEY_B                   (1<<1)
#define KEY_A                   (1)

// Background control registers
#define REG_BG0CNT              *((vu16 *)(0x04000008))
#define REG_BG1CNT              *((vu16 *)(0x0400000A))
#define REG_BG2CNT              *((vu16 *)(0x0400000C))
#define REG_BG3CNT              *((vu16 *)(0x0400000E))

// Sections of RAM
#define EWRAM                   ((vu16 *)0x02000000)
#define IWRAM                   ((vu16 *)0x03000000) //should be 32 bit?
#define IORAM                   ((vu16 *)0x04000000)
#define PALETTE_RAM             ((vu16 *)0x05000000)
#define VRAM                    ((vu16 *)0x06000000)
#define OAM                     ((vu16 *)0x07000000) //should be 32 bit?


#define SCREEN_WIDTH            240
#define SCREEN_HEIGHT           160

#define COLOR_0                 0x0000

// static inline functions

// mode 3 plot a color to a (x,y) coordinate
static inline void m3_plot(int x, int y, u16 color)
{   VRAM[y*SCREEN_WIDTH+x] = color;  }

// create color format from rgb values between 0 and 31
static inline u16 RGB15(u16 red, u16 green, u16 blue)
{   return red | (green<<5) | (blue<<10);   }
