#ifndef _PRINT_SC_H_
#define _PRINT_SC_H_

#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include "input_sc.h"

int draw(unsigned int colour, int pixel);
int draw_circle(unsigned int colour, int pixel, int x, int y, int r);
int draw_line(unsigned int colour, int pixel);

#endif