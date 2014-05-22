// \l ex2.c
// q will intercept the k) in the comments bellow and will trigger the compilation and binding for hypot

#include <math.h>
K hypotenuse(K c1,K c2){if(-9!=c1->t||-9!=c2->t)R krr("type");R kf(hypot(c1->f,c2->f));}

/*
// add options for compilation. this should be done before any calls to .c.dl
k).c.cf"-Lm"
k)hypot:.c.dl[`hypotenuse;2]
k)-1"calling hypot[2;3]";
k)hypot[2f;3f]
/ */
