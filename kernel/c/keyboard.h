#ifndef KEYBOARD_H
#define KEYBOARD_H

#include<stdbool.h>

bool kbc_init();
char get_latest_char();
uint8_t get_latest_scan_code();
void wait_for_keyboard();

#endif
