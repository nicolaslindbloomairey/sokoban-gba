
//{{BLOCK(crate1)

//======================================================================
//
//	crate1, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 160 + 2048 = 2720
//
//	Time-stamp: 2023-01-09, 13:11:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CRATE1_H
#define GRIT_CRATE1_H

#define crate1TilesLen 160
extern const unsigned int crate1Tiles[40];

#define crate1MapLen 2048
extern const unsigned short crate1Map[1024];

#define crate1PalLen 512
extern const unsigned short crate1Pal[256];

#endif // GRIT_CRATE1_H

//}}BLOCK(crate1)
