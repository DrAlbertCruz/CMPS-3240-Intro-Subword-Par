# CMPS-3240-Intro-Subword-Parallelism
An introduction to Intel's SSE2 instruction set at the assembly level

# Introduction

## Background

### SIMD Operations

```shell
$ for i in {1..3}; do time ./bench_dewvm.out; done;

real    0m0.877s
user    0m0.460s
sys     0m0.416s

real    0m0.823s
user    0m0.452s
sys     0m0.368s

real    0m0.881s
user    0m0.484s
sys     0m0.396s
```

### Addressing in x86

For this lab you will need to know advanced memory addressing in x86 GAS. The following example was taken from this reference.<sup>1</sup>

```x86
mov (%ebx), %eax 	/* Load 4 bytes from the memory address in EBX into EAX. */
mov %ebx, var(,1) 	/* Move the contents of EBX into the 4 bytes at memory address var.
(Note, var is a 32-bit constant). */
mov -4(%esi), %eax 	/* Move 4 bytes at memory address ESI + (-4) into EAX. */
mov %cl, (%esi,%eax,1)    	/* Move the contents of CL into the byte at address ESI+EAX. */
mov (%esi,%ebx,4), %edx      	/* Move the 4 bytes of data at address ESI+4*EBX into EDX. */ 
```

Essentially, `(%ebx)` is shorthand for `0(0,%ebx,1)` and empty elements in this notation are implied 0 or 1. The generalized form is `a(b,c,d)` which evaluates to the memory address at `b + d * c + a`. `b` and `c` are generally registers, whereas `a` and `d` are generally literals. Note that within memory addressing, the numbers do not need a `$` prefix. For this lab we will use the `lea` acdress. 

# References

<sup>1</sup>http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
