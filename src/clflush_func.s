.global clflush_func

.section .text

# void clflush_func(void *p1, void *p2)
# p1 is in %rcx
# p2 is in %rdx

clflush_func:
    mov (%rcx), %rax
    mov (%rcx), %rax
    mov (%rcx), %rax

    mov %rax, (%rdx)
    mov %rax, (%rdx)
    mov %rax, (%rdx)

    mov (%rdx), %rax
    mov (%rdx), %rax
    mov (%rdx), %rax

    mov %rax, (%rcx)
    mov %rax, (%rcx)
    mov %rax, (%rcx)

    clflush (%rcx)
    clflush (%rdx)

    ret
