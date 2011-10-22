/*
 * RConio
 *
 * MS-DOS conio.h wrapper
 *
 */

#include <conio.h>

#include "ruby.h"

VALUE RConio = Qnil;

#if 0
/*
 * Determines if a keyboard key was pressed.
 */
VALUE method_kbhit(VALUE self)
{
}
/*
 * Reads a character directly from the console without buffer, and without echo.
 */
VALUE method_getch(VALUE self)
{
}
/*
 * Reads a character directly from the console without buffer, but with echo.
 */
VALUE method_getche(VALUE self)
{
}
/*
 * Puts the character c back into the keyboard buffer.
 */
VALUE method_ungetch(VALUE self);
/*
 * Reads a string directly from the console.
 */
VALUE method_(VALUE self);
/*
 * Reads formatted values directly from the console.
 */
VALUE method_cscanf(VALUE self);
/*
 * Writes a character directly to the console.
 */
VALUE method_putch(VALUE self);
/*
 * Writes a string directly to the console.
 */
VALUE method_cputs(VALUE self);
/*
 * Formats values and writes them directly to the console.
 */
VALUE method_cprintf(VALUE self);
#endif

void Init_rconio()
{
    RConio = rb_define_module("RConio");
}
