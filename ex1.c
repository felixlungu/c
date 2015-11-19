// \l ex1.c
// q will intercept the k) in comment bellow and will trigger the compilation and binding for add and sub

K add(K x,K y){R k(0,"{x+y}",r1(x),r1(y),(K)0);}
K sub(K x,K y){R k(0,"{x-y}",r1(x),r1(y),(K)0);}


/*see the last line for the trick to trick the q interpreter and still have a valid c comment. this line is considered a comment by q and it is not passed to .c.e 
k)add:.c.dl[`add;2]
k)sub:.c.dl[`sub;2]
k)-1"calling add[2;3]";
k)add[2;3]
k)-1"calling sub[2;3]";
k)sub[2;3]
/ */

