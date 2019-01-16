# CMPS-3240-Intro-Subword-Parallelism
An introduction to Intel's SSE2 instruction set at the assembly level

# Introduction

## Background

### SSE2 instruction set

The topic of today's lab is an element-wise vector multiplication. It takes two vectors of identical size and steps through the arrays, multiplying it element by element and storing the result in a third array:

```c
.
int dewvm( int N, double *x, double *y, double *result ) {
    for( int i = 0; i < N; i++ )
        result[i] = x[i] * y[i];

    return 0;
}
```

which seems simple enough. Note that these are double precision, which is 64 bits large. If you run benchmark this operation three times on `odin.cs.csubak.edu` you get the following results:

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

Recall from lecture that there are a type of instruction called SIMD, which stands for single instruction multiple datapath (SIMD). The SIMD instruction set we will be using today is called SSE2, and it was introduced with the Pentium 4. Essentially, when iterating an arithmetic operation over an array, rather than carry it out one index at a time, we can:

1. Grab N values from the arrays and place them into a single, large register that can fit them all. The oversized registers in x86 are called *multimedia registers* (MM), so called because they were originally introduced to give better performance and fidelity for--as you might have guessed, multimedia programs. The process of stuffing the MM registers with many variables is called *packing*. An MM register is *packed* if it contains many smaller values inside of it.
1. Carry out a single arithmetic operation, that will be carried out on all the values in the oversized register. So, rather than carry out N arithmetic operations, we carry out only 1. 
1. *Unpack* the MM register by placing the items back in order into memory.

This introduces the constraint that the array size must be a multiple of N, but potentially improves execution time by a factor of 1/N. Though, not quite, as there is some overhead introduced by packing and unpacking the arrays. I get the following result on `odin.cs.csubak.edu` when I alter the code to make use of SSE2 SIMD instructions:

```shell
$ for i in {1..3}; do time ./bench_dewvm.out; done;

real    0m0.716s
user    0m0.284s
sys     0m0.428s

real    0m0.657s
user    0m0.324s
sys     0m0.332s

real    0m0.661s
user    0m0.280s
sys     0m0.384s
```

SSE2 instructions use a 128-bit MM registers. So, we can pack 2 doubles into a single MM register, and we will need to carry out half as many multiplications. In practice, the improved code benches at an average of 296ms from 465ms (remember that you care about user time, not system time). It is faster by a factor of 0.636, so, not exactly 1/2 but pretty close.

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

Essentially, `(%ebx)` is shorthand for `0(0,%ebx,1)` and empty elements in this notation are implied 0 or 1. The generalized form is `a(b,c,d)` which evaluates to the memory address at `b + d * c + a`. `b` and `c` are generally registers, whereas `a` and `d` are generally literals. Note that within memory addressing, the numbers do not need a `$` prefix. For this lab we will use the `lea` acdress. The scale factor, `d`, must be 1, 2, 4 or 8.

# References

<sup>1</sup>http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
