#include <stdint.h>
#include "hal.h"

#define VIDEO_MEMORY 0xb8000
#define TIMER_CONTROL_PORT 0x43
#define TIMER_DATA_PORT 0x40

//Global variables
static uint32_t tick_counter = 0;

//Helper functions
static void rotate_pole(int x, int y);

uint32_t get_tick_count()
{
	return tick_counter;
}

void timer_handler(){
	tick_counter ++;
	rotate_pole(79,0);
}

void set_timer(uint16_t count)
{
// FIRST send the command word to the PIT. Sets binary counting,
//	 Mode 3, Read or Load LSB first then MSB, Channel 0
 
	write_port(TIMER_CONTROL_PORT,0x36);
//	mov	al, 110110b
//	out	0x43, al
	write_port(TIMER_DATA_PORT, count & 0xff);
	write_port(TIMER_DATA_PORT, count >> 8);
}

static void rotate_pole(int x, int y)
{
	char* sym = (char*)(VIDEO_MEMORY + 2*(x+80*y));
	switch(*sym){
		case '|':
			*sym = '/';
			break;
		case '/':
			*sym = '-';
			break;
		case '-':
			*sym = '\\';
			break;
		case '\\':
			*sym = '|';
			break;
		default:
			*sym = '|';
	}

}