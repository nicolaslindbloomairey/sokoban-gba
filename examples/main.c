typedef volatile unsigned short     vu16
typedef unsigned short              u16

#define	REG_VCOUNT		*((vu16 *)(0x4000006))
#define	REG_KEYINPUT		*((vu16 *)(0x4000130))


int main(void)
{
	// Write into the I/O registers, setting video display parameters.
	volatile unsigned char *ioram = (unsigned char *)0x04000000;
	ioram[0] = 0x03; // Use video mode 3 (in BG2, a 16bpp bitmap in VRAM)
	ioram[1] = 0x04; // Enable BG2 (BG0 = 1, BG1 = 2, BG2 = 4, ...)

	// Write pixel colours into VRAM
	volatile unsigned short *vram = (unsigned short *)0x06000000;
        int x = 120;
        int y = 80;
	vram[80*240 + 115] = 0x001F; // X = 115, Y = 80, C = 000000000011111 = R
	vram[y*240 + x] = 0x03E0; // X = 120, Y = 80, C = 000001111100000 = G
	vram[80*240 + 125] = 0x7C00; // X = 125, Y = 80, C = 111110000000000 = B


        u16 keys = 0;

        //main loop
        do {
            while (REG_VCOUNT < 160); // wait for end of frame drawing

            keys = REG_KEYINPUT
              

            if (keys & (1<<6)) {

                vram[y*240 + x] = 0x0;
                y += 1;
                vram[y*240 + x] = 0x03E0; // X = 120, Y = 80, C = 000001111100000 = G
            }

        } while(1);

	return 0;
}
