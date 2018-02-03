#include <string>

/**
 * author: seanlee
 * mail: xmlee97@gmail.com
 **/

using namespace std;

enum tok_num {
    undef           =   0,  // placeholder;
    tok_eof         =   1,  // end of file
    ident           =   2,  // letter ( letter | '_' | digit )*
        rw_var      =   3,  // "var"
        rw_begin    =   4,  // "begin"
        rw_end      =   5,  // "end"
        rw_if       =   6,  // "if"
        rw_integer  =   7,  // "integer"
        rw_read     =   8,  // "read"
        rw_real     =   9,  // "real"
        rw_then     =  10,  // "then"
        rw_write    =  11,  // "write"
    lit_int         =  12,  // digit+
    lit_real        =  13,  // digit+ '.' digit+

    op_add          =  14,  // "+"
    op_sub          =  15,  // "-"
    op_mul          =  16,  // "*"
    op_div          =  17,  // "/"
    lparen          =  18,  // "("
    rparen          =  19,  // ")"
    lbrac           =  20,  // "["
    rbrac           =  21,  // "]"
    comma           =  22,  // ","
    semic           =  23,  // ";"
    colon           =  24,  // ":"
    op_lt           =  25,  // "<"
    op_gt           =  26,  // ">"
    op_le           =  27,  // "<="
    op_ge           =  28,  // ">="
    op_eq           =  29,  // "=="
    op_ne           =  30,  // "!="
    becomes         =  31,  // ":="
    tok_error       =  32   // invalid token
};

static const tok_num first_rw = rw_var;
static const tok_num last_rw  = rw_write;

struct token {
    tok_num num;
    const char* name;   
    string  image;      
    int     line;       
    int     column;     
};

extern token scan();
