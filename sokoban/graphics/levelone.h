
//{{BLOCK(levelone)

//======================================================================
//
//	levelone, 256x256@4, 
//	+ palette 24 entries, not compressed
//	+ 19 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 48 + 608 + 2048 = 2704
//
//	Time-stamp: 2023-01-09, 15:14:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVELONE_H
#define GRIT_LEVELONE_H

#define leveloneTilesLen 608
extern const unsigned short leveloneTiles[304];

#define leveloneMapLen 2048
extern const unsigned short leveloneMap[1024];

#define levelonePalLen 48
extern const unsigned short levelonePal[24];

#endif // GRIT_LEVELONE_H

//}}BLOCK(levelone)
