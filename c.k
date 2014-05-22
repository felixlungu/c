\d .c

TS:TS1:"#define KXVER ",($.z.K),"\n#include \"",$[#f:getenv`QHOME;f;getenv[`HOME],"/q"],"/c/k.h\""
CF:CF1:"-w"

/ alocate compile context, compile and relocate.don't call direnctly. use dl[] to triger the compilation of code accumulated in TS
/ .c.c["int main(...."]
c:`c 2:(`c;2);
/ bind a function from the current compile context to a k object
b:`c 2:(`b;2)
/ eval function called by q. just append to TS
e:{TS,::"\n",x;}
/ add compile flags for tcc
cf:{CF,::" ",x}
/ dynamic link functions from compiled code
dl:{[f;n] if[~TS~TS1;c[CF,"\000";TS,"\000"];CF::CF1;TS::TS1];b[f;n]}

\

.c.e is called by q when \l file.c or c)...  it just appends to TS

ex:

c)K add(K x,K y){R ki(x->i+x->i);}
add:.c.dl[`add;2]
