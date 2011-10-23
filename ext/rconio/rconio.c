/*
 * RConio
 *
 * MS-DOS conio.h wrapper
 *
 */

#include <conio.h>

#include "ruby.h"

VALUE RConio = Qnil;

/*
 * call-seq:
 *      kbhit()     -> number
 *
 * Determines if a keyboard key was pressed.
 */
VALUE method_kbhit(VALUE self)
{
    int ret = _kbhit();
    return INT2NUM(ret);
}

/*
 * call-seq:
 *      getch()     -> number
 *
 * Reads a character directly from the console without buffer, and without echo.
 */
VALUE method_getch(VALUE self)
{
    int ret = _getch();
    return INT2NUM(ret);
}

#if 0
/*
 * Reads a character directly from the console without buffer, but with echo.
 */
VALUE method_getche(VALUE self)
{
}

/*
 * Puts the character c back into the keyboard buffer.
 */
VALUE method_ungetch(VALUE self)
{
}

/*
 * Reads a string directly from the console.
 */
VALUE method_(VALUE self)
{
}

/*
 * Reads formatted values directly from the console.
 */
VALUE method_cscanf(VALUE self)
{
}

/*
 * Writes a character directly to the console.
 */
VALUE method_putch(VALUE self)
{
}

/*
 * Writes a string directly to the console.
 */
VALUE method_cputs(VALUE self)
{
}

/*
 * Formats values and writes them directly to the console.
 */
VALUE method_cprintf(VALUE self)
{
}

#endif

void Init_rconio()
{
    RConio = rb_define_module("RConio");

    rb_define_module_function(RConio, "kbhit", method_kbhit, 0);
    rb_define_module_function(RConio, "getch", method_getch, 0);
}
