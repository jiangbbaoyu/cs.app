//
// Created by root on 23-8-27.
//


union ele {
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union ele *next;
    } e2;
};

void proc(union ele *up) {
    up->e2.x = *((up->e2.next)->e1.p ) - (up->e2.next)->e1.y;
//    up->e2.x = *((*(up->e2.next)).e1.p ) - (*(up->e2.next)).e1.y;
//    up->e2.x = *((*((*up).e2.next)).e1.p ) - (*((*up).e2.next)).e1.y;
    /**
     * for *((*((*up).e2.next)).e1.p)
     *     (*up) refer to the ele struct itself
     *     ((*up).e2.next) refer to e2.next value (a pointer point to another ele struct)  movq 8(%rdi), %rax
     *     (*((*up).e2.next)) refer to the next struct itself
     *     ((*((*up).e2.next)).e1.p )  refer to  struct.e1.p value (a pointer  point to a long )  movq (%rax), %rdx
     *     *((*((*up).e2.next)).e1.p )  refer to the long value                                   movq (%rdx), %rdx
     *
     * for    *((*(up->e2.next)).e1.p )
     *     (up->e2.next)              //    movq 8(%rdi), %rax
     *     (*(up->e2.next)).e1.p      //    movq (%rax),  %rdx
     *     *((*(up->e2.next)).e1.p )  //    movq (%rdx),  %rdx
     *
     *
     */


}