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
 *      kbhit() -> number
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
 *      getch() -> number
 *
 * Reads a character directly from the console without buffer, and without echo.
 */
VALUE method_getch(VALUE self)
{
    int ret = _getch();
    return INT2NUM(ret);
}

/*
 * call-seq:
 *      getche()    -> number
 *
 * Reads a character directly from the console without buffer, but with echo.
 */
VALUE method_getche(VALUE self)
{
    int ret = _getche();
    return INT2NUM(ret);
}

/*
 * call-seq:
 *      ungetch(character)  -> number
 *
 * Puts the character c back into the keyboard buffer.
 */
VALUE method_ungetch(VALUE self, VALUE int_character)
{
    int character = NUM2INT(int_character);
    int ret = _ungetch(character);
    return INT2NUM(ret);
}

/*
 * call-seq:
 *      cgets(maxlength=256)    -> string
 *
 * Reads a string directly from the console.
 */
VALUE method_cgets(int argc, VALUE* argv, VALUE self)
{
    // get the optional arg `maxlength`
    VALUE int_maxlength;
    rb_scan_args(argc, argv, "01", &int_maxlength);

    // use 254 if `maxlength` isn't set
    int maxlength = NIL_P(int_maxlength) ? 254 : NUM2INT(int_maxlength);

    char* buffer = malloc((maxlength+2) * sizeof(char));
    if(!buffer)
    {
        rb_raise(rb_eNoMemError, "out of memory");
        return Qnil;
    }

    buffer[0] = int_maxlength;
    char* ret = _cgets(buffer);
    VALUE string_ret = rb_str_new(ret, buffer[1]);

    free(buffer);

    return string_ret;
}

/*
 * call-seq:
 *      putch(character)    -> number
 *
 * Writes a character directly to the console.
 */
VALUE method_putch(VALUE self, VALUE int_character)
{
    int character = NUM2INT(int_character);
    int ret = _putch(character);
    return INT2NUM(ret);
}

/*
 * call-seq:
 *      cputs(string)   -> number
 *
 * Writes a string directly to the console.
 */
VALUE method_cputs(VALUE self, VALUE string_string)
{
    const char* title = StringValuePtr(string_string);
    int ret = _cputs(title);
    return INT2NUM(ret);
}

#if 0
/*
 * call-seq:
 *      cscanf(format, ??) -> number
 *
 * Reads formatted values directly from the console.
 */
VALUE method_cscanf(int argc, VALUE* argv, VALUE self)
{
}
#endif

#if 0
/*
 * call-seq:
 *      cprintf(format, arguments...)   -> number
 *
 * Formats values and writes them directly to the console.
 */
VALUE method_cprintf(int argc, VALUE* argv, VALUE self)
{
}
#endif


void Init_rconio()
{
    RConio = rb_define_module("RConio");

    rb_define_module_function(RConio, "kbhit", method_kbhit, 0);
    rb_define_module_function(RConio, "getch", method_getch, 0);
    rb_define_module_function(RConio, "getche", method_getche, 0);
    rb_define_module_function(RConio, "ungetch", method_ungetch, 1);
    rb_define_module_function(RConio, "cgets", method_putch,-1);
    rb_define_module_function(RConio, "putch", method_putch, 1);
    rb_define_module_function(RConio, "cputs", method_cputs, 1);
}
