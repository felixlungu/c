/* c scripting for kdb+ */
/* get tcc from http://download.savannah.gnu.org/releases/tinycc/ */
/* uncompress, prepare Makefile and compile:
    cd <tcc dir>
    ./configure --cpu=x86
or
    ./configure --cpu=x86-64
add this line to the generated config.h:
    #define WITHOUT_LIBTCC
    make

compile c.so this as (for 64bit use -m64):
mac osx:
    gcc -dynamiclib -undefined dynamic_lookup -m32 -I <tcc dir> -o c.so c.c <tcc dir>/libtcc.a
linux:
    gcc -shared -m32 -I <tcc dir> -o c.so c.c <tcc dir>/libtcc.a

install the c.so in right binary dir (for l32 in $QHOME/m32, k.h in $QHOME/c and c.k in $QHOME

*/

#include <stdlib.h>
#include <stdio.h>

#define KXVER 3
#include "libtcc.h"
#include "k.h"

static TCCState* TS=NULL;

// compile a string. cf: compile flags, p: C code. both args should be '\0' treminated.
K c(K cf,K p){if(10!=cf->t||10!=p->t)R krr("type");
 if(TS){tcc_delete(TS);TS=tcc_new();};if(!TS)R krr("context");tcc_set_output_type(TS,TCC_OUTPUT_MEMORY);tcc_set_options(TS,(S)kG(cf));
 if(-1==tcc_compile_string(TS,(S)kG(p)))R krr("compile");if(-1==tcc_relocate(TS,TCC_RELOCATE_AUTO))R krr("relocate");R kb(1);}

// bind a function symbol to code (type 112)
K b(K s,K n){V* f;I i;if(-11!=s->t||!(-6==n->t||-7==n->t))R krr("type");
 i=n->t==-6?n->i:(I)n->j;f=tcc_get_symbol(TS,s->s);R !f?krr(s->s):dl(f,n->i);}

