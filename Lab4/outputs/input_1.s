.data
print_fmt: .string "%ld \n"
.text
.globl main
main:
 pushq %rbp
 movq %rsp, %rbp
 subq $16, %rsp
 movq $100, %rax
 movq %rax, -16(%rbp)
 movq -16(%rbp), %rax
 movq %rax, %rcx
 jmp endswitch_0
endswitch_0:
.end_main:
leave
ret
.section .note.GNU-stack,"",@progbits
