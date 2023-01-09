#include "../include/base.h"
#include "../graphics/crate1.h"

int main(void)
{
        // Set the display control register
        // use video mode three and enable BG2
	REG_DISPCNT = 0x0403; // Use video mode 3 (in BG2, a 16bpp bitmap in VRAM)
        //REG_DISPCNT = BG0_ENABLE | MODE0
        //REG_BG0CNT = SCREENSIZE00 | 

        //green pixel location so it can be moved
        u32 x = 120;
        u32 y = 80;
	// Write pixel colours into VRAM
	//VRAM[80*240 + 115] = 0x001F; //red
        m3_plot(115, 80, RGB15(31, 0, 0));
	VRAM[y*240 + x] = 0x03E0; //green
	VRAM[80*240 + 125] = 0x7C00; //blue

        u16 key_curr = 0;
        u16 key_prev = 0; //stores the value of the key register

        //main loop
        while(1) {
            while (REG_VCOUNT >= 160); // only do this once per v-blank
            while (REG_VCOUNT < 160); // wait for end of frame drawing

            // update key variables
            key_prev = key_curr;
            key_curr = ~REG_KEYINPUT & KEY_MASK;
              
            //up
            if (key_curr & KEY_UP && y>0) {
                VRAM[y*240 + x] = 0x0;
                y -= 1;
                VRAM[y*240 + x] = 0x03E0;
            }
            //down
            if (key_curr & KEY_DWN && y<159) {

                VRAM[y*240 + x] = 0x0;
                y += 1;
                VRAM[y*240 + x] = 0x03E0; 
            }
            if (key_curr & KEY_LFT && x>0) {

                VRAM[y*240 + x] = 0x0;
                x -= 1;
                VRAM[y*240 + x] = 0x03E0;
            }
            if (key_curr & KEY_RT && x<239) {

                VRAM[y*240 + x] = 0x0;
                x += 1;
                VRAM[y*240 + x] = 0x03E0;
            }
        }

	return 0;
}
