.Ltext0:
.LC0:
        .string "Hello, World!"
main:
.LFB0:
        pushq   %rbp
        movq    %rsp, %rbp
        movl    $.LC0, %edi
        movl    $0, %eax
        call    printf
        movl    $0, %eax
        popq    %rbp
        ret
