#ifndef _types_h_
#define _types_h_
typedef volatile unsigned char      vu8;
typedef volatile unsigned short     vu16;
typedef volatile unsigned int       vu32;
typedef unsigned char               u8;
typedef unsigned short              u16;
typedef unsigned int                u32;

// single tile 8x8 dots at 4bpp 
typedef struct { u32 data[8]; } TILE, TILE4;
// double tile is 8bpp
typedef struct { u32 data[16]; } TILE8;

//tile block: 32x16 tiles or 16x16 d-tiles
// called a charblock
typedef TILE CHARBLOCK[512];
typedef TILE8 CHARBLOCK8[256];

typedef u16 SCREENBLOCK[1024];
#endif
