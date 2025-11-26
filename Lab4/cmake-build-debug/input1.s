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
 movq %rax, %rcx //rcx = 100 = y
 movq $100, %rax //100 -> rax
cmpq %rax, %rcx // 100 - 100 != 0
jne endcase_1
 movq $1, %rax
 movq %rax, -8(%rbp)
endcase_1:
 movq $200, %rax
cmpq %rax, %rcx
jne endcase_2
 movq $2, %rax
 movq %rax, -8(%rbp)
endcase_2:
 jmp endswitch_0
endswitch_0:
 movq -8(%rbp), %rax
 movq %rax, %rsi
 leaq print_fmt(%rip), %rdi
 movl $0, %eax
 call printf@PLT
 movq $0, %rax
 jmp .end_main
.end_main:
leave
ret
.section .note.GNU-stack,"",@progbits
