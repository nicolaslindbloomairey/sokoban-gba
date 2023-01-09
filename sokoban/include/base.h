#ifndef _base_h_
#define _base_h_

#include "types.h"
#include "input.h"

// Sections of RAM
#define EWRAM                   ((vu16 *)0x02000000)
#define IWRAM                   ((vu16 *)0x03000000) //should be 32 bit?
#define IORAM                   ((vu16 *)0x04000000)
#define PALETTE_RAM             ((u16 *)0x05000000)

// we can treat VRAM as an array of halfwords (vu16) or an array of tile blocks
#define VRAM                    0x06000000
#define TILE_MEM                ((CHARBLOCK *) VRAM)
#define TILE8_MEM               ((CHARBLOCK8 *) VRAM)
#define SE_MEM                  ((SCREENBLOCK*) VRAM)


#define OAM                     ((vu16 *)0x07000000) //should be 32 bit?
                                                     //
// INTERRUPTS
// interrupt master enable register
#define REG_IME                 *((vu16 *)(0x04000208))
// interrupt enable register
#define REG_IE                  *((vu16 *)(0x04000200))
// interrupt request register
#define REG_IF                  *((vu16 *)(0x04000202))
#define VBLANK_IRR              1

// VERITICAL SCANLINE COUNT REGISTER
#define	REG_VCOUNT		*((vu16 *)(0x04000006))

// DISPLAY CONTROL REGISTER
#define	REG_DISPCNT		*((vu16 *)(0x04000000))
#define MODE0                   0x00 //tile modes
#define MODE1                   0x01
#define MODE2                   0x02
#define MODE3                   0x03 //bit map modes
#define MODE4                   0x04
#define MODE5                   0x05
//enable bits
#define BG0_ENABLE              0x0100
#define BG1_ENABLE              0x0200
#define BG2_ENABLE              0x0400
#define BG3_ENABLE              0x0800
#define OBJ_ENABLE              0x1000

//DISPLAY

// Background control registers
#define REG_BG0CNT              *((vu16 *)(0x04000008))
#define REG_BG1CNT              *((vu16 *)(0x0400000A))
#define REG_BG2CNT              *((vu16 *)(0x0400000C))
#define REG_BG3CNT              *((vu16 *)(0x0400000E))

// bit fields of bg control registers
#define SCREENSIZE00            0x0000 
#define SCREENSIZE01            d14
#define SCREENSIZE10            d15
#define SCREENSIZE11            d14 | d15

#define TRANSPARENT_DIS         d13
#define WRAPAROUND_DIS          0x0000
#define COLORMODE0              0x0000
#define COLORMODE1              d7
#define MOSAIC_ENABLE           d6

// BG SCROLLING OFFSET REGISTERS
#define REG_BG0HOFS             *((vu16 *)(0x04000010))
#define REG_BG1HOFS             *((vu16 *)(0x04000014))
#define REG_BG2HOFS             *((vu16 *)(0x04000018))
#define REG_BG3HOFS             *((vu16 *)(0x0400001C))

#define REG_BG0VOFS             *((vu16 *)(0x04000012))
#define REG_BG1VOFS             *((vu16 *)(0x04000016))
#define REG_BG2VOFS             *((vu16 *)(0x0400001A))
#define REG_BG3VOFS             *((vu16 *)(0x0400001E))


#define SCREEN_WIDTH            240
#define SCREEN_HEIGHT           160

#define COLOR_0                 0x0000

#define d0                      0x0001
#define d1                      0x0002
#define d2                      0x0004
#define d3                      0x0008
#define d4                      0x0010
#define d5                      0x0020
#define d6                      0x0040
#define d7                      0x0080
#define d8                      0x0100
#define d9                      0x0200
#define d10                     0x0400
#define d11                     0x0800
#define d12                     0x1000
#define d13                     0x2000
#define d14                     0x4000
#define d15                     0x8000

// KEY INPUT REGISTER
#define	REG_KEYINPUT		*((vu16 *)(0x04000130))
// Key bit masks for REG_KEYINPUT
#define KEY_L                   0x0200
#define KEY_R                   0x0100
#define KEY_DWN                 0x0080
#define KEY_UP                  0x0040
#define KEY_LFT                 0x0020
#define KEY_RT                  0x0010
#define KEY_ST                  0x0008
#define KEY_SL                  0x0004
#define KEY_B                   0x0002
#define KEY_A                   0x0001
#define KEY_MASK                0x03FF

// static inline functions

#define INLINE static inline
// mode 3 plot a color to a (x,y) coordinate
INLINE void m3_plot(int x, int y, u16 color)
{   ((u16 *)VRAM)[y*SCREEN_WIDTH+x] = color;  }

// create color format from rgb values between 0 and 31
INLINE u16 RGB15(u16 red, u16 green, u16 blue)
{   return red | (green<<5) | (blue<<10);   }

#endif
