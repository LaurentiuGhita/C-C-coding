	.file	"main.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	main
	.type	main, @function
main:
.LFB1031:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1031
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-96(%rbp), %rax
	movl	$10, %edx
	movl	$10, %esi
	movq	%rax, %rdi
.LEHB0:
	call	_ZN4GridIiEC1Eii
.LEHE0:
	leaq	-80(%rbp), %rax
	movl	$11, %edx
	movl	$11, %esi
	movq	%rax, %rdi
.LEHB1:
	call	_ZN4GridIdEC1Eii
.LEHE1:
	movl	$10, -48(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rcx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN4GridIiE12SetElementAtEiiRKi
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB2:
	call	_ZN4GridIiEC1ERKS0_
.LEHE2:
	leaq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB3:
	call	_ZN4GridIiEC1ERKS0_
.LEHE3:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIiED1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIiED1Ev
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIdED1Ev
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIiED1Ev
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L6
	jmp	.L10
.L9:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIiED1Ev
	jmp	.L4
.L8:
	movq	%rax, %rbx
.L4:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIdED1Ev
	jmp	.L5
.L7:
	movq	%rax, %rbx
.L5:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4GridIiED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
.L10:
	call	__stack_chk_fail
.L6:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1031:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1031:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1031-.LLSDACSB1031
.LLSDACSB1031:
	.uleb128 .LEHB0-.LFB1031
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1031
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L7-.LFB1031
	.uleb128 0
	.uleb128 .LEHB2-.LFB1031
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L8-.LFB1031
	.uleb128 0
	.uleb128 .LEHB3-.LFB1031
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L9-.LFB1031
	.uleb128 0
	.uleb128 .LEHB4-.LFB1031
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE1031:
	.text
	.size	main, .-main
	.section	.text._ZN4GridIiEC2Eii,"axG",@progbits,_ZN4GridIiEC5Eii,comdat
	.align 2
	.weak	_ZN4GridIiEC2Eii
	.type	_ZN4GridIiEC2Eii, @function
_ZN4GridIiEC2Eii:
.LFB1033:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movq	-40(%rbp), %rax
	movl	-44(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-40(%rbp), %rax
	movl	-48(%rbp), %edx
	movl	%edx, 12(%rax)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cltq
	movabsq	$1143914305352105984, %rdx
	cmpq	%rdx, %rax
	ja	.L12
	salq	$3, %rax
	jmp	.L13
.L12:
	movq	$-1, %rax
.L13:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -20(%rbp)
.L17:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-20(%rbp), %eax
	jle	.L18
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	leaq	(%rax,%rdx), %rbx
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	movabsq	$2287828610704211968, %rdx
	cmpq	%rdx, %rax
	ja	.L15
	salq	$2, %rax
	jmp	.L16
.L15:
	movq	$-1, %rax
.L16:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, (%rbx)
	addl	$1, -20(%rbp)
	jmp	.L17
.L18:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1033:
	.size	_ZN4GridIiEC2Eii, .-_ZN4GridIiEC2Eii
	.weak	_ZN4GridIiEC1Eii
	.set	_ZN4GridIiEC1Eii,_ZN4GridIiEC2Eii
	.section	.text._ZN4GridIiED2Ev,"axG",@progbits,_ZN4GridIiED5Ev,comdat
	.align 2
	.weak	_ZN4GridIiED2Ev
	.type	_ZN4GridIiED2Ev, @function
_ZN4GridIiED2Ev:
.LFB1036:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
.L22:
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-4(%rbp), %eax
	jle	.L20
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L21
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L21:
	addl	$1, -4(%rbp)
	jmp	.L22
.L20:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L23
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L23:
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1036:
	.size	_ZN4GridIiED2Ev, .-_ZN4GridIiED2Ev
	.weak	_ZN4GridIiED1Ev
	.set	_ZN4GridIiED1Ev,_ZN4GridIiED2Ev
	.section	.text._ZN4GridIdEC2Eii,"axG",@progbits,_ZN4GridIdEC5Eii,comdat
	.align 2
	.weak	_ZN4GridIdEC2Eii
	.type	_ZN4GridIdEC2Eii, @function
_ZN4GridIdEC2Eii:
.LFB1039:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movq	-40(%rbp), %rax
	movl	-44(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-40(%rbp), %rax
	movl	-48(%rbp), %edx
	movl	%edx, 12(%rax)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cltq
	movabsq	$1143914305352105984, %rdx
	cmpq	%rdx, %rax
	ja	.L25
	salq	$3, %rax
	jmp	.L26
.L25:
	movq	$-1, %rax
.L26:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -20(%rbp)
.L30:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-20(%rbp), %eax
	jle	.L31
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	leaq	(%rax,%rdx), %rbx
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	movabsq	$1143914305352105984, %rdx
	cmpq	%rdx, %rax
	ja	.L28
	salq	$3, %rax
	jmp	.L29
.L28:
	movq	$-1, %rax
.L29:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, (%rbx)
	addl	$1, -20(%rbp)
	jmp	.L30
.L31:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1039:
	.size	_ZN4GridIdEC2Eii, .-_ZN4GridIdEC2Eii
	.weak	_ZN4GridIdEC1Eii
	.set	_ZN4GridIdEC1Eii,_ZN4GridIdEC2Eii
	.section	.text._ZN4GridIdED2Ev,"axG",@progbits,_ZN4GridIdED5Ev,comdat
	.align 2
	.weak	_ZN4GridIdED2Ev
	.type	_ZN4GridIdED2Ev, @function
_ZN4GridIdED2Ev:
.LFB1042:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
.L35:
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-4(%rbp), %eax
	jle	.L33
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L34
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L34:
	addl	$1, -4(%rbp)
	jmp	.L35
.L33:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L36
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L36:
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1042:
	.size	_ZN4GridIdED2Ev, .-_ZN4GridIdED2Ev
	.weak	_ZN4GridIdED1Ev
	.set	_ZN4GridIdED1Ev,_ZN4GridIdED2Ev
	.section	.text._ZN4GridIiE12SetElementAtEiiRKi,"axG",@progbits,_ZN4GridIiE12SetElementAtEiiRKi,comdat
	.align 2
	.weak	_ZN4GridIiE12SetElementAtEiiRKi
	.type	_ZN4GridIiE12SetElementAtEiiRKi, @function
_ZN4GridIiE12SetElementAtEiiRKi:
.LFB1044:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1044:
	.size	_ZN4GridIiE12SetElementAtEiiRKi, .-_ZN4GridIiE12SetElementAtEiiRKi
	.section	.rodata
.LC0:
	.string	"Copy ctor\n"
	.section	.text._ZN4GridIiEC2ERKS0_,"axG",@progbits,_ZN4GridIiEC5ERKS0_,comdat
	.align 2
	.weak	_ZN4GridIiEC2ERKS0_
	.type	_ZN4GridIiEC2ERKS0_, @function
_ZN4GridIiEC2ERKS0_:
.LFB1046:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4GridIiE8CopyFromERKS0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1046:
	.size	_ZN4GridIiEC2ERKS0_, .-_ZN4GridIiEC2ERKS0_
	.weak	_ZN4GridIiEC1ERKS0_
	.set	_ZN4GridIiEC1ERKS0_,_ZN4GridIiEC2ERKS0_
	.section	.text._ZN4GridIiE8CopyFromERKS0_,"axG",@progbits,_ZN4GridIiE8CopyFromERKS0_,comdat
	.align 2
	.weak	_ZN4GridIiE8CopyFromERKS0_
	.type	_ZN4GridIiE8CopyFromERKS0_, @function
_ZN4GridIiE8CopyFromERKS0_:
.LFB1049:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movl	8(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 8(%rax)
	movq	-48(%rbp), %rax
	movl	12(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 12(%rax)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cltq
	movabsq	$1143914305352105984, %rdx
	cmpq	%rdx, %rax
	ja	.L40
	salq	$3, %rax
	jmp	.L41
.L40:
	movq	$-1, %rax
.L41:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -28(%rbp)
.L45:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-28(%rbp), %eax
	jle	.L42
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	leaq	(%rax,%rdx), %rbx
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	movabsq	$2287828610704211968, %rdx
	cmpq	%rdx, %rax
	ja	.L43
	salq	$2, %rax
	jmp	.L44
.L43:
	movq	$-1, %rax
.L44:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, (%rbx)
	addl	$1, -28(%rbp)
	jmp	.L45
.L42:
	movl	$0, -24(%rbp)
.L49:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-24(%rbp), %eax
	jle	.L50
	movl	$0, -20(%rbp)
.L48:
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	-20(%rbp), %eax
	jle	.L47
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movl	-24(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -20(%rbp)
	jmp	.L48
.L47:
	addl	$1, -24(%rbp)
	jmp	.L49
.L50:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1049:
	.size	_ZN4GridIiE8CopyFromERKS0_, .-_ZN4GridIiE8CopyFromERKS0_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1052:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L53
	cmpl	$65535, -8(%rbp)
	jne	.L53
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L53:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1052:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1053:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1053:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
