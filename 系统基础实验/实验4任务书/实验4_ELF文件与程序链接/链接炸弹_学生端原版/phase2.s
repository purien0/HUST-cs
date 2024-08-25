
phase2.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <myfunc>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # f <myfunc+0xf>
   f:	e8 00 00 00 00       	call   14 <myfunc+0x14>
  14:	90                   	nop
  15:	5d                   	pop    %rbp
  16:	c3                   	ret    

0000000000000017 <do_phase>:
  17:	f3 0f 1e fa          	endbr64 
  1b:	55                   	push   %rbp
  1c:	48 89 e5             	mov    %rsp,%rbp
  1f:	89 7d fc             	mov    %edi,-0x4(%rbp)
  22:	90                   	nop
  23:	90                   	nop
  24:	90                   	nop
  25:	90                   	nop
  26:	90                   	nop
  27:	90                   	nop
  28:	90                   	nop
  29:	90                   	nop
  2a:	90                   	nop
  2b:	90                   	nop
  2c:	90                   	nop
  2d:	90                   	nop
  2e:	5d                   	pop    %rbp
  2f:	c3                   	ret    
