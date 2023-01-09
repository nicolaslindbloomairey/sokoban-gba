#include <string.h>
#include "../include/base.h"
#include "../graphics/crate1.h"

int main(void)
{
        REG_DISPCNT = BG0_ENABLE | MODE0;
        REG_BG0CNT = (30 << 8);

        memcpy(PALETTE_RAM, crate1Pal, crate1PalLen);
        memcpy(&TILE_MEM[0][0], crate1Tiles, crate1TilesLen);
        memcpy(&SE_MEM[30][0], crate1Map, crate1MapLen);

        u16 key_curr = 0;
        u16 key_prev = 0; //stores the value of the key register

        //main loop
        u32 x=0,y=0;
        while(1) {
            while (REG_VCOUNT >= 160); // only do this once per v-blank
            while (REG_VCOUNT < 160); // wait for end of frame drawing

            // update key variables
            key_prev = key_curr;
            key_curr = ~REG_KEYINPUT & KEY_MASK;
              
            //up
            if (key_curr & KEY_UP) {
                y += 1;
            }
            //down
            if (key_curr & KEY_DWN) {

                y -= 1;
            }
            if (key_curr & KEY_LFT) {

                x += 1;
            }
            if (key_curr & KEY_RT) {

                x -= 1;
            }

            REG_BG0HOFS = x;
            REG_BG0VOFS = y;
        }

	return 0;
}
