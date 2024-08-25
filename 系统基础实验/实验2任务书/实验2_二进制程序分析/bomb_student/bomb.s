
./bomb：     文件格式 elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)  
 319:	6c                   	insb   (%dx),%es:(%rdi)
 31a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 321:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 326:	78 2d                	js     355 <__abi_tag-0x37>
 328:	78 38                	js     362 <__abi_tag-0x2a>
 32a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 330:	6f                   	outsl  %ds:(%rsi),(%dx)
 331:	2e 32 00             	cs xor (%rax),%al

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    $0x0,%al
 33a:	00 00                	add    %al,(%rax)
 33c:	20 00                	and    %al,(%rax)
 33e:	00 00                	add    %al,(%rax)
 340:	05 00 00 00 47       	add    $0x47000000,%eax
 345:	4e 55                	rex.WRX push %rbp
 347:	00 02                	add    %al,(%rdx)
 349:	00 00                	add    %al,(%rax)
 34b:	c0 04 00 00          	rolb   $0x0,(%rax,%rax,1)
 34f:	00 03                	add    %al,(%rbx)
 351:	00 00                	add    %al,(%rax)
 353:	00 00                	add    %al,(%rax)
 355:	00 00                	add    %al,(%rax)
 357:	00 02                	add    %al,(%rdx)
 359:	80 00 c0             	addb   $0xc0,(%rax)
 35c:	04 00                	add    $0x0,%al
 35e:	00 00                	add    %al,(%rax)
 360:	01 00                	add    %eax,(%rax)
 362:	00 00                	add    %al,(%rax)
 364:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000000368 <.note.gnu.build-id>:
 368:	04 00                	add    $0x0,%al
 36a:	00 00                	add    %al,(%rax)
 36c:	14 00                	adc    $0x0,%al
 36e:	00 00                	add    %al,(%rax)
 370:	03 00                	add    (%rax),%eax
 372:	00 00                	add    %al,(%rax)
 374:	47                   	rex.RXB
 375:	4e 55                	rex.WRX push %rbp
 377:	00 9b 4e a1 ff d4    	add    %bl,-0x2b005eb2(%rbx)
 37d:	19 52 da             	sbb    %edx,-0x26(%rdx)
 380:	6f                   	outsl  %ds:(%rsi),(%dx)
 381:	c0 11 17             	rclb   $0x17,(%rcx)
 384:	eb ce                	jmp    354 <__abi_tag-0x38>
 386:	ad                   	lods   %ds:(%rsi),%eax
 387:	c2 ba 07             	ret    $0x7ba
 38a:	47                   	rex.RXB
 38b:	b6                   	.byte 0xb6

Disassembly of section .note.ABI-tag:

000000000000038c <__abi_tag>:
 38c:	04 00                	add    $0x0,%al
 38e:	00 00                	add    %al,(%rax)
 390:	10 00                	adc    %al,(%rax)
 392:	00 00                	add    %al,(%rax)
 394:	01 00                	add    %eax,(%rax)
 396:	00 00                	add    %al,(%rax)
 398:	47                   	rex.RXB
 399:	4e 55                	rex.WRX push %rbp
 39b:	00 00                	add    %al,(%rax)
 39d:	00 00                	add    %al,(%rax)
 39f:	00 03                	add    %al,(%rbx)
 3a1:	00 00                	add    %al,(%rax)
 3a3:	00 02                	add    %al,(%rdx)
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 00                	add    %al,(%rax)
 3a9:	00 00                	add    %al,(%rax)
	...

Disassembly of section .gnu.hash:

00000000000003b0 <.gnu.hash>:
 3b0:	03 00                	add    (%rax),%eax
 3b2:	00 00                	add    %al,(%rax)
 3b4:	13 00                	adc    (%rax),%eax
 3b6:	00 00                	add    %al,(%rax)
 3b8:	01 00                	add    %eax,(%rax)
 3ba:	00 00                	add    %al,(%rax)
 3bc:	06                   	(bad)  
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 00                	add    %al,(%rax)
 3c1:	00 a1 00 80 01 10    	add    %ah,0x10018000(%rcx)
 3c7:	00 13                	add    %dl,(%rbx)
 3c9:	00 00                	add    %al,(%rax)
 3cb:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 3d1 <__abi_tag+0x45>
 3d1:	00 00                	add    %al,(%rax)
 3d3:	00 28                	add    %ch,(%rax)
 3d5:	1d 8c 1c d1 65       	sbb    $0x65d11c8c,%eax
 3da:	ce                   	(bad)  
 3db:	6d                   	insl   (%dx),%es:(%rdi)
 3dc:	67 55                	addr32 push %rbp
 3de:	61                   	(bad)  
 3df:	10                   	.byte 0x10

Disassembly of section .dynsym:

00000000000003e0 <.dynsym>:
	...
 3f8:	68 00 00 00 12       	push   $0x12000000
	...
 40d:	00 00                	add    %al,(%rax)
 40f:	00 16                	add    %dl,(%rsi)
 411:	00 00                	add    %al,(%rax)
 413:	00 12                	add    %dl,(%rdx)
	...
 425:	00 00                	add    %al,(%rax)
 427:	00 e1                	add    %ah,%cl
 429:	00 00                	add    %al,(%rax)
 42b:	00 20                	add    %ah,(%rax)
	...
 43d:	00 00                	add    %al,(%rax)
 43f:	00 4f 00             	add    %cl,0x0(%rdi)
 442:	00 00                	add    %al,(%rax)
 444:	12 00                	adc    (%rax),%al
	...
 456:	00 00                	add    %al,(%rax)
 458:	5b                   	pop    %rbx
 459:	00 00                	add    %al,(%rax)
 45b:	00 12                	add    %dl,(%rdx)
	...
 46d:	00 00                	add    %al,(%rax)
 46f:	00 8a 00 00 00 12    	add    %cl,0x12000000(%rdx)
	...
 485:	00 00                	add    %al,(%rax)
 487:	00 9b 00 00 00 12    	add    %bl,0x12000000(%rbx)
	...
 49d:	00 00                	add    %al,(%rax)
 49f:	00 10                	add    %dl,(%rax)
 4a1:	00 00                	add    %al,(%rax)
 4a3:	00 12                	add    %dl,(%rdx)
	...
 4b5:	00 00                	add    %al,(%rax)
 4b7:	00 28                	add    %ch,(%rax)
 4b9:	00 00                	add    %al,(%rax)
 4bb:	00 12                	add    %dl,(%rdx)
	...
 4cd:	00 00                	add    %al,(%rax)
 4cf:	00 fd                	add    %bh,%ch
 4d1:	00 00                	add    %al,(%rax)
 4d3:	00 20                	add    %ah,(%rax)
	...
 4e5:	00 00                	add    %al,(%rax)
 4e7:	00 54 00 00          	add    %dl,0x0(%rax,%rax,1)
 4eb:	00 12                	add    %dl,(%rdx)
	...
 4fd:	00 00                	add    %al,(%rax)
 4ff:	00 7a 00             	add    %bh,0x0(%rdx)
 502:	00 00                	add    %al,(%rax)
 504:	12 00                	adc    (%rax),%al
	...
 516:	00 00                	add    %al,(%rax)
 518:	34 00                	xor    $0x0,%al
 51a:	00 00                	add    %al,(%rax)
 51c:	12 00                	adc    (%rax),%al
	...
 52e:	00 00                	add    %al,(%rax)
 530:	2f                   	(bad)  
 531:	00 00                	add    %al,(%rax)
 533:	00 12                	add    %dl,(%rdx)
	...
 545:	00 00                	add    %al,(%rax)
 547:	00 75 00             	add    %dh,0x0(%rbp)
 54a:	00 00                	add    %al,(%rax)
 54c:	12 00                	adc    (%rax),%al
	...
 55e:	00 00                	add    %al,(%rax)
 560:	0c 01                	or     $0x1,%al
 562:	00 00                	add    %al,(%rax)
 564:	20 00                	and    %al,(%rax)
	...
 576:	00 00                	add    %al,(%rax)
 578:	62                   	(bad)  
 579:	00 00                	add    %al,(%rax)
 57b:	00 12                	add    %dl,(%rdx)
	...
 58d:	00 00                	add    %al,(%rax)
 58f:	00 3a                	add    %bh,(%rdx)
 591:	00 00                	add    %al,(%rax)
 593:	00 12                	add    %dl,(%rdx)
	...
 5a5:	00 00                	add    %al,(%rax)
 5a7:	00 48 00             	add    %cl,0x0(%rax)
 5aa:	00 00                	add    %al,(%rax)
 5ac:	11 00                	adc    %eax,(%rax)
 5ae:	1a 00                	sbb    (%rax),%al
 5b0:	80 56 00 00          	adcb   $0x0,0x0(%rsi)
 5b4:	00 00                	add    %al,(%rax)
 5b6:	00 00                	add    %al,(%rax)
 5b8:	08 00                	or     %al,(%rax)
 5ba:	00 00                	add    %al,(%rax)
 5bc:	00 00                	add    %al,(%rax)
 5be:	00 00                	add    %al,(%rax)
 5c0:	01 00                	add    %eax,(%rax)
 5c2:	00 00                	add    %al,(%rax)
 5c4:	22 00                	and    (%rax),%al
	...
 5d6:	00 00                	add    %al,(%rax)
 5d8:	6f                   	outsl  %ds:(%rsi),(%dx)
 5d9:	00 00                	add    %al,(%rax)
 5db:	00 11                	add    %dl,(%rcx)
 5dd:	00 1a                	add    %bl,(%rdx)
 5df:	00 90 56 00 00 00    	add    %dl,0x56(%rax)
 5e5:	00 00                	add    %al,(%rax)
 5e7:	00 08                	add    %cl,(%rax)
 5e9:	00 00                	add    %al,(%rax)
 5eb:	00 00                	add    %al,(%rax)
 5ed:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynstr:

00000000000005f0 <.dynstr>:
 5f0:	00 5f 5f             	add    %bl,0x5f(%rdi)
 5f3:	63 78 61             	movsxd 0x61(%rax),%edi
 5f6:	5f                   	pop    %rdi
 5f7:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 5fd:	7a 65                	jp     664 <__abi_tag+0x2d8>
 5ff:	00 66 67             	add    %ah,0x67(%rsi)
 602:	65 74 73             	gs je  678 <__abi_tag+0x2ec>
 605:	00 5f 5f             	add    %bl,0x5f(%rdi)
 608:	6c                   	insb   (%dx),%es:(%rdi)
 609:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 610:	72 74                	jb     686 <__abi_tag+0x2fa>
 612:	5f                   	pop    %rdi
 613:	6d                   	insl   (%dx),%es:(%rdi)
 614:	61                   	(bad)  
 615:	69 6e 00 73 69 67 6e 	imul   $0x6e676973,0x0(%rsi),%ebp
 61c:	61                   	(bad)  
 61d:	6c                   	insb   (%dx),%es:(%rdi)
 61e:	00 61 74             	add    %ah,0x74(%rcx)
 621:	6f                   	outsl  %ds:(%rsi),(%dx)
 622:	69 00 66 6f 70 65    	imul   $0x65706f66,(%rax),%eax
 628:	6e                   	outsb  %ds:(%rsi),(%dx)
 629:	00 5f 5f             	add    %bl,0x5f(%rdi)
 62c:	63 74 79 70          	movsxd 0x70(%rcx,%rdi,2),%esi
 630:	65 5f                	gs pop %rdi
 632:	62                   	(bad)  
 633:	5f                   	pop    %rdi
 634:	6c                   	insb   (%dx),%es:(%rdi)
 635:	6f                   	outsl  %ds:(%rsi),(%dx)
 636:	63 00                	movsxd (%rax),%eax
 638:	73 74                	jae    6ae <__abi_tag+0x322>
 63a:	64 6f                	outsl  %fs:(%rsi),(%dx)
 63c:	75 74                	jne    6b2 <__abi_tag+0x326>
 63e:	00 70 75             	add    %dh,0x75(%rax)
 641:	74 73                	je     6b6 <__abi_tag+0x32a>
 643:	00 66 66             	add    %ah,0x66(%rsi)
 646:	6c                   	insb   (%dx),%es:(%rdi)
 647:	75 73                	jne    6bc <__abi_tag+0x330>
 649:	68 00 73 74 72       	push   $0x72747300
 64e:	6c                   	insb   (%dx),%es:(%rdi)
 64f:	65 6e                	outsb  %gs:(%rsi),(%dx)
 651:	00 73 6c             	add    %dh,0x6c(%rbx)
 654:	65 65 70 00          	gs gs jo 658 <__abi_tag+0x2cc>
 658:	67 65 74 65          	addr32 gs je 6c1 <__abi_tag+0x335>
 65c:	6e                   	outsb  %ds:(%rsi),(%dx)
 65d:	76 00                	jbe    65f <__abi_tag+0x2d3>
 65f:	73 74                	jae    6d5 <__abi_tag+0x349>
 661:	64 69 6e 00 65 78 69 	imul   $0x74697865,%fs:0x0(%rsi),%ebp
 668:	74 
 669:	00 5f 5f             	add    %bl,0x5f(%rdi)
 66c:	69 73 6f 63 39 39 5f 	imul   $0x5f393963,0x6f(%rbx),%esi
 673:	73 73                	jae    6e8 <__abi_tag+0x35c>
 675:	63 61 6e             	movsxd 0x6e(%rcx),%esp
 678:	66 00 5f 5f          	data16 add %bl,0x5f(%rdi)
 67c:	73 74                	jae    6f2 <__abi_tag+0x366>
 67e:	61                   	(bad)  
 67f:	63 6b 5f             	movsxd 0x5f(%rbx),%ebp
 682:	63 68 6b             	movsxd 0x6b(%rax),%ebp
 685:	5f                   	pop    %rdi
 686:	66 61                	data16 (bad) 
 688:	69 6c 00 70 72 69 6e 	imul   $0x746e6972,0x70(%rax,%rax,1),%ebp
 68f:	74 
 690:	66 00 6c 69 62       	data16 add %ch,0x62(%rcx,%rbp,2)
 695:	63 2e                	movsxd (%rsi),%ebp
 697:	73 6f                	jae    708 <__abi_tag+0x37c>
 699:	2e 36 00 47 4c       	cs ss add %al,0x4c(%rdi)
 69e:	49                   	rex.WB
 69f:	42                   	rex.X
 6a0:	43 5f                	rex.XB pop %r15
 6a2:	32 2e                	xor    (%rsi),%ch
 6a4:	33 00                	xor    (%rax),%eax
 6a6:	47                   	rex.RXB
 6a7:	4c                   	rex.WR
 6a8:	49                   	rex.WB
 6a9:	42                   	rex.X
 6aa:	43 5f                	rex.XB pop %r15
 6ac:	32 2e                	xor    (%rsi),%ch
 6ae:	37                   	(bad)  
 6af:	00 47 4c             	add    %al,0x4c(%rdi)
 6b2:	49                   	rex.WB
 6b3:	42                   	rex.X
 6b4:	43 5f                	rex.XB pop %r15
 6b6:	32 2e                	xor    (%rsi),%ch
 6b8:	34 00                	xor    $0x0,%al
 6ba:	47                   	rex.RXB
 6bb:	4c                   	rex.WR
 6bc:	49                   	rex.WB
 6bd:	42                   	rex.X
 6be:	43 5f                	rex.XB pop %r15
 6c0:	32 2e                	xor    (%rsi),%ch
 6c2:	33 34 00             	xor    (%rax,%rax,1),%esi
 6c5:	47                   	rex.RXB
 6c6:	4c                   	rex.WR
 6c7:	49                   	rex.WB
 6c8:	42                   	rex.X
 6c9:	43 5f                	rex.XB pop %r15
 6cb:	32 2e                	xor    (%rsi),%ch
 6cd:	32 2e                	xor    (%rsi),%ch
 6cf:	35 00 5f 49 54       	xor    $0x54495f00,%eax
 6d4:	4d 5f                	rex.WRB pop %r15
 6d6:	64 65 72 65          	fs gs jb 73f <__abi_tag+0x3b3>
 6da:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 6e1:	4d 
 6e2:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 6e4:	6f                   	outsl  %ds:(%rsi),(%dx)
 6e5:	6e                   	outsb  %ds:(%rsi),(%dx)
 6e6:	65 54                	gs push %rsp
 6e8:	61                   	(bad)  
 6e9:	62                   	(bad)  
 6ea:	6c                   	insb   (%dx),%es:(%rdi)
 6eb:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 6ef:	67 6d                	insl   (%dx),%es:(%edi)
 6f1:	6f                   	outsl  %ds:(%rsi),(%dx)
 6f2:	6e                   	outsb  %ds:(%rsi),(%dx)
 6f3:	5f                   	pop    %rdi
 6f4:	73 74                	jae    76a <__abi_tag+0x3de>
 6f6:	61                   	(bad)  
 6f7:	72 74                	jb     76d <__abi_tag+0x3e1>
 6f9:	5f                   	pop    %rdi
 6fa:	5f                   	pop    %rdi
 6fb:	00 5f 49             	add    %bl,0x49(%rdi)
 6fe:	54                   	push   %rsp
 6ff:	4d 5f                	rex.WRB pop %r15
 701:	72 65                	jb     768 <__abi_tag+0x3dc>
 703:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 70a:	4d 
 70b:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 70d:	6f                   	outsl  %ds:(%rsi),(%dx)
 70e:	6e                   	outsb  %ds:(%rsi),(%dx)
 70f:	65 54                	gs push %rsp
 711:	61                   	(bad)  
 712:	62                   	.byte 0x62
 713:	6c                   	insb   (%dx),%es:(%rdi)
 714:	65                   	gs
	...

Disassembly of section .gnu.version:

0000000000000716 <.gnu.version>:
 716:	00 00                	add    %al,(%rax)
 718:	02 00                	add    (%rax),%al
 71a:	03 00                	add    (%rax),%eax
 71c:	01 00                	add    %eax,(%rax)
 71e:	02 00                	add    (%rax),%al
 720:	02 00                	add    (%rax),%al
 722:	04 00                	add    $0x0,%al
 724:	02 00                	add    (%rax),%al
 726:	02 00                	add    (%rax),%al
 728:	02 00                	add    (%rax),%al
 72a:	01 00                	add    %eax,(%rax)
 72c:	02 00                	add    (%rax),%al
 72e:	05 00 02 00 02       	add    $0x2000200,%eax
 733:	00 02                	add    %al,(%rdx)
 735:	00 01                	add    %al,(%rcx)
 737:	00 02                	add    %al,(%rdx)
 739:	00 06                	add    %al,(%rsi)
 73b:	00 02                	add    %al,(%rdx)
 73d:	00 02                	add    %al,(%rdx)
 73f:	00 02                	add    %al,(%rdx)
	...

Disassembly of section .gnu.version_r:

0000000000000748 <.gnu.version_r>:
 748:	01 00                	add    %eax,(%rax)
 74a:	05 00 a2 00 00       	add    $0xa200,%eax
 74f:	00 10                	add    %dl,(%rax)
 751:	00 00                	add    %al,(%rax)
 753:	00 00                	add    %al,(%rax)
 755:	00 00                	add    %al,(%rax)
 757:	00 13                	add    %dl,(%rbx)
 759:	69 69 0d 00 00 06 00 	imul   $0x60000,0xd(%rcx),%ebp
 760:	ac                   	lods   %ds:(%rsi),%al
 761:	00 00                	add    %al,(%rax)
 763:	00 10                	add    %dl,(%rax)
 765:	00 00                	add    %al,(%rax)
 767:	00 17                	add    %dl,(%rdi)
 769:	69 69 0d 00 00 05 00 	imul   $0x50000,0xd(%rcx),%ebp
 770:	b6 00                	mov    $0x0,%dh
 772:	00 00                	add    %al,(%rax)
 774:	10 00                	adc    %al,(%rax)
 776:	00 00                	add    %al,(%rax)
 778:	14 69                	adc    $0x69,%al
 77a:	69 0d 00 00 04 00 c0 	imul   $0xc0,0x40000(%rip),%ecx        # 40784 <_end+0x3aa14>
 781:	00 00 00 
 784:	10 00                	adc    %al,(%rax)
 786:	00 00                	add    %al,(%rax)
 788:	b4 91                	mov    $0x91,%ah
 78a:	96                   	xchg   %eax,%esi
 78b:	06                   	(bad)  
 78c:	00 00                	add    %al,(%rax)
 78e:	03 00                	add    (%rax),%eax
 790:	ca 00 00             	lret   $0x0
 793:	00 10                	add    %dl,(%rax)
 795:	00 00                	add    %al,(%rax)
 797:	00 75 1a             	add    %dh,0x1a(%rbp)
 79a:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
 7a0:	d5                   	(bad)  
 7a1:	00 00                	add    %al,(%rax)
 7a3:	00 00                	add    %al,(%rax)
 7a5:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

00000000000007a8 <.rela.dyn>:
 7a8:	50                   	push   %rax
 7a9:	4d 00 00             	rex.WRB add %r8b,(%r8)
 7ac:	00 00                	add    %al,(%rax)
 7ae:	00 00                	add    %al,(%rax)
 7b0:	08 00                	or     %al,(%rax)
 7b2:	00 00                	add    %al,(%rax)
 7b4:	00 00                	add    %al,(%rax)
 7b6:	00 00                	add    %al,(%rax)
 7b8:	e0 12                	loopne 7cc <__abi_tag+0x440>
 7ba:	00 00                	add    %al,(%rax)
 7bc:	00 00                	add    %al,(%rax)
 7be:	00 00                	add    %al,(%rax)
 7c0:	58                   	pop    %rax
 7c1:	4d 00 00             	rex.WRB add %r8b,(%r8)
 7c4:	00 00                	add    %al,(%rax)
 7c6:	00 00                	add    %al,(%rax)
 7c8:	08 00                	or     %al,(%rax)
 7ca:	00 00                	add    %al,(%rax)
 7cc:	00 00                	add    %al,(%rax)
 7ce:	00 00                	add    %al,(%rax)
 7d0:	a0 12 00 00 00 00 00 	movabs 0x800000000000012,%al
 7d7:	00 08 
 7d9:	50                   	push   %rax
 7da:	00 00                	add    %al,(%rax)
 7dc:	00 00                	add    %al,(%rax)
 7de:	00 00                	add    %al,(%rax)
 7e0:	08 00                	or     %al,(%rax)
 7e2:	00 00                	add    %al,(%rax)
 7e4:	00 00                	add    %al,(%rax)
 7e6:	00 00                	add    %al,(%rax)
 7e8:	08 50 00             	or     %dl,0x0(%rax)
 7eb:	00 00                	add    %al,(%rax)
 7ed:	00 00                	add    %al,(%rax)
 7ef:	00 20                	add    %ah,(%rax)
 7f1:	50                   	push   %rax
 7f2:	00 00                	add    %al,(%rax)
 7f4:	00 00                	add    %al,(%rax)
 7f6:	00 00                	add    %al,(%rax)
 7f8:	08 00                	or     %al,(%rax)
 7fa:	00 00                	add    %al,(%rax)
 7fc:	00 00                	add    %al,(%rax)
 7fe:	00 00                	add    %al,(%rax)
 800:	58                   	pop    %rax
 801:	31 00                	xor    %eax,(%rax)
 803:	00 00                	add    %al,(%rax)
 805:	00 00                	add    %al,(%rax)
 807:	00 28                	add    %ch,(%rax)
 809:	50                   	push   %rax
 80a:	00 00                	add    %al,(%rax)
 80c:	00 00                	add    %al,(%rax)
 80e:	00 00                	add    %al,(%rax)
 810:	08 00                	or     %al,(%rax)
 812:	00 00                	add    %al,(%rax)
 814:	00 00                	add    %al,(%rax)
 816:	00 00                	add    %al,(%rax)
 818:	72 31                	jb     84b <__abi_tag+0x4bf>
 81a:	00 00                	add    %al,(%rax)
 81c:	00 00                	add    %al,(%rax)
 81e:	00 00                	add    %al,(%rax)
 820:	30 50 00             	xor    %dl,0x0(%rax)
 823:	00 00                	add    %al,(%rax)
 825:	00 00                	add    %al,(%rax)
 827:	00 08                	add    %cl,(%rax)
 829:	00 00                	add    %al,(%rax)
 82b:	00 00                	add    %al,(%rax)
 82d:	00 00                	add    %al,(%rax)
 82f:	00 8c 31 00 00 00 00 	add    %cl,0x0(%rcx,%rsi,1)
 836:	00 00                	add    %al,(%rax)
 838:	58                   	pop    %rax
 839:	55                   	push   %rbp
 83a:	00 00                	add    %al,(%rax)
 83c:	00 00                	add    %al,(%rax)
 83e:	00 00                	add    %al,(%rax)
 840:	08 00                	or     %al,(%rax)
 842:	00 00                	add    %al,(%rax)
 844:	00 00                	add    %al,(%rax)
 846:	00 00                	add    %al,(%rax)
 848:	30 54 00 00          	xor    %dl,0x0(%rax,%rax,1)
 84c:	00 00                	add    %al,(%rax)
 84e:	00 00                	add    %al,(%rax)
 850:	68 55 00 00 00       	push   $0x55
 855:	00 00                	add    %al,(%rax)
 857:	00 08                	add    %cl,(%rax)
 859:	00 00                	add    %al,(%rax)
 85b:	00 00                	add    %al,(%rax)
 85d:	00 00                	add    %al,(%rax)
 85f:	00 50 55             	add    %dl,0x55(%rax)
 862:	00 00                	add    %al,(%rax)
 864:	00 00                	add    %al,(%rax)
 866:	00 00                	add    %al,(%rax)
 868:	78 55                	js     8bf <__abi_tag+0x533>
 86a:	00 00                	add    %al,(%rax)
 86c:	00 00                	add    %al,(%rax)
 86e:	00 00                	add    %al,(%rax)
 870:	08 00                	or     %al,(%rax)
 872:	00 00                	add    %al,(%rax)
 874:	00 00                	add    %al,(%rax)
 876:	00 00                	add    %al,(%rax)
 878:	60                   	(bad)  
 879:	55                   	push   %rbp
 87a:	00 00                	add    %al,(%rax)
 87c:	00 00                	add    %al,(%rax)
 87e:	00 00                	add    %al,(%rax)
 880:	88 55 00             	mov    %dl,0x0(%rbp)
 883:	00 00                	add    %al,(%rax)
 885:	00 00                	add    %al,(%rax)
 887:	00 08                	add    %cl,(%rax)
 889:	00 00                	add    %al,(%rax)
 88b:	00 00                	add    %al,(%rax)
 88d:	00 00                	add    %al,(%rax)
 88f:	00 70 55             	add    %dh,0x55(%rax)
 892:	00 00                	add    %al,(%rax)
 894:	00 00                	add    %al,(%rax)
 896:	00 00                	add    %al,(%rax)
 898:	98                   	cwtl   
 899:	55                   	push   %rbp
 89a:	00 00                	add    %al,(%rax)
 89c:	00 00                	add    %al,(%rax)
 89e:	00 00                	add    %al,(%rax)
 8a0:	08 00                	or     %al,(%rax)
 8a2:	00 00                	add    %al,(%rax)
 8a4:	00 00                	add    %al,(%rax)
 8a6:	00 00                	add    %al,(%rax)
 8a8:	80 55 00 00          	adcb   $0x0,0x0(%rbp)
 8ac:	00 00                	add    %al,(%rax)
 8ae:	00 00                	add    %al,(%rax)
 8b0:	a8 55                	test   $0x55,%al
 8b2:	00 00                	add    %al,(%rax)
 8b4:	00 00                	add    %al,(%rax)
 8b6:	00 00                	add    %al,(%rax)
 8b8:	08 00                	or     %al,(%rax)
 8ba:	00 00                	add    %al,(%rax)
 8bc:	00 00                	add    %al,(%rax)
 8be:	00 00                	add    %al,(%rax)
 8c0:	e0 54                	loopne 916 <__abi_tag+0x58a>
 8c2:	00 00                	add    %al,(%rax)
 8c4:	00 00                	add    %al,(%rax)
 8c6:	00 00                	add    %al,(%rax)
 8c8:	b0 55                	mov    $0x55,%al
 8ca:	00 00                	add    %al,(%rax)
 8cc:	00 00                	add    %al,(%rax)
 8ce:	00 00                	add    %al,(%rax)
 8d0:	08 00                	or     %al,(%rax)
 8d2:	00 00                	add    %al,(%rax)
 8d4:	00 00                	add    %al,(%rax)
 8d6:	00 00                	add    %al,(%rax)
 8d8:	40 54                	rex push %rsp
 8da:	00 00                	add    %al,(%rax)
 8dc:	00 00                	add    %al,(%rax)
 8de:	00 00                	add    %al,(%rax)
 8e0:	c8 55 00 00          	enter  $0x55,$0x0
 8e4:	00 00                	add    %al,(%rax)
 8e6:	00 00                	add    %al,(%rax)
 8e8:	08 00                	or     %al,(%rax)
 8ea:	00 00                	add    %al,(%rax)
 8ec:	00 00                	add    %al,(%rax)
 8ee:	00 00                	add    %al,(%rax)
 8f0:	00 55 00             	add    %dl,0x0(%rbp)
 8f3:	00 00                	add    %al,(%rax)
 8f5:	00 00                	add    %al,(%rax)
 8f7:	00 d0                	add    %dl,%al
 8f9:	55                   	push   %rbp
 8fa:	00 00                	add    %al,(%rax)
 8fc:	00 00                	add    %al,(%rax)
 8fe:	00 00                	add    %al,(%rax)
 900:	08 00                	or     %al,(%rax)
 902:	00 00                	add    %al,(%rax)
 904:	00 00                	add    %al,(%rax)
 906:	00 00                	add    %al,(%rax)
 908:	a0 54 00 00 00 00 00 	movabs 0xe800000000000054,%al
 90f:	00 e8 
 911:	55                   	push   %rbp
 912:	00 00                	add    %al,(%rax)
 914:	00 00                	add    %al,(%rax)
 916:	00 00                	add    %al,(%rax)
 918:	08 00                	or     %al,(%rax)
 91a:	00 00                	add    %al,(%rax)
 91c:	00 00                	add    %al,(%rax)
 91e:	00 00                	add    %al,(%rax)
 920:	20 55 00             	and    %dl,0x0(%rbp)
 923:	00 00                	add    %al,(%rax)
 925:	00 00                	add    %al,(%rax)
 927:	00 f0                	add    %dh,%al
 929:	55                   	push   %rbp
 92a:	00 00                	add    %al,(%rax)
 92c:	00 00                	add    %al,(%rax)
 92e:	00 00                	add    %al,(%rax)
 930:	08 00                	or     %al,(%rax)
 932:	00 00                	add    %al,(%rax)
 934:	00 00                	add    %al,(%rax)
 936:	00 00                	add    %al,(%rax)
 938:	60                   	(bad)  
 939:	54                   	push   %rsp
 93a:	00 00                	add    %al,(%rax)
 93c:	00 00                	add    %al,(%rax)
 93e:	00 00                	add    %al,(%rax)
 940:	08 56 00             	or     %dl,0x0(%rsi)
 943:	00 00                	add    %al,(%rax)
 945:	00 00                	add    %al,(%rax)
 947:	00 08                	add    %cl,(%rax)
 949:	00 00                	add    %al,(%rax)
 94b:	00 00                	add    %al,(%rax)
 94d:	00 00                	add    %al,(%rax)
 94f:	00 80 54 00 00 00    	add    %al,0x54(%rax)
 955:	00 00                	add    %al,(%rax)
 957:	00 10                	add    %dl,(%rax)
 959:	56                   	push   %rsi
 95a:	00 00                	add    %al,(%rax)
 95c:	00 00                	add    %al,(%rax)
 95e:	00 00                	add    %al,(%rax)
 960:	08 00                	or     %al,(%rax)
 962:	00 00                	add    %al,(%rax)
 964:	00 00                	add    %al,(%rax)
 966:	00 00                	add    %al,(%rax)
 968:	c0 54 00 00 00       	rclb   $0x0,0x0(%rax,%rax,1)
 96d:	00 00                	add    %al,(%rax)
 96f:	00 28                	add    %ch,(%rax)
 971:	56                   	push   %rsi
 972:	00 00                	add    %al,(%rax)
 974:	00 00                	add    %al,(%rax)
 976:	00 00                	add    %al,(%rax)
 978:	08 00                	or     %al,(%rax)
 97a:	00 00                	add    %al,(%rax)
 97c:	00 00                	add    %al,(%rax)
 97e:	00 00                	add    %al,(%rax)
 980:	e0 55                	loopne 9d7 <__abi_tag+0x64b>
 982:	00 00                	add    %al,(%rax)
 984:	00 00                	add    %al,(%rax)
 986:	00 00                	add    %al,(%rax)
 988:	30 56 00             	xor    %dl,0x0(%rsi)
 98b:	00 00                	add    %al,(%rax)
 98d:	00 00                	add    %al,(%rax)
 98f:	00 08                	add    %cl,(%rax)
 991:	00 00                	add    %al,(%rax)
 993:	00 00                	add    %al,(%rax)
 995:	00 00                	add    %al,(%rax)
 997:	00 a0 55 00 00 00    	add    %ah,0x55(%rax)
 99d:	00 00                	add    %al,(%rax)
 99f:	00 48 56             	add    %cl,0x56(%rax)
 9a2:	00 00                	add    %al,(%rax)
 9a4:	00 00                	add    %al,(%rax)
 9a6:	00 00                	add    %al,(%rax)
 9a8:	08 00                	or     %al,(%rax)
 9aa:	00 00                	add    %al,(%rax)
 9ac:	00 00                	add    %al,(%rax)
 9ae:	00 00                	add    %al,(%rax)
 9b0:	c0 55 00 00          	rclb   $0x0,0x0(%rbp)
 9b4:	00 00                	add    %al,(%rax)
 9b6:	00 00                	add    %al,(%rax)
 9b8:	50                   	push   %rax
 9b9:	56                   	push   %rsi
 9ba:	00 00                	add    %al,(%rax)
 9bc:	00 00                	add    %al,(%rax)
 9be:	00 00                	add    %al,(%rax)
 9c0:	08 00                	or     %al,(%rax)
 9c2:	00 00                	add    %al,(%rax)
 9c4:	00 00                	add    %al,(%rax)
 9c6:	00 00                	add    %al,(%rax)
 9c8:	00 56 00             	add    %dl,0x0(%rsi)
 9cb:	00 00                	add    %al,(%rax)
 9cd:	00 00                	add    %al,(%rax)
 9cf:	00 68 56             	add    %ch,0x56(%rax)
 9d2:	00 00                	add    %al,(%rax)
 9d4:	00 00                	add    %al,(%rax)
 9d6:	00 00                	add    %al,(%rax)
 9d8:	08 00                	or     %al,(%rax)
 9da:	00 00                	add    %al,(%rax)
 9dc:	00 00                	add    %al,(%rax)
 9de:	00 00                	add    %al,(%rax)
 9e0:	40 56                	rex push %rsi
 9e2:	00 00                	add    %al,(%rax)
 9e4:	00 00                	add    %al,(%rax)
 9e6:	00 00                	add    %al,(%rax)
 9e8:	70 56                	jo     a40 <__abi_tag+0x6b4>
 9ea:	00 00                	add    %al,(%rax)
 9ec:	00 00                	add    %al,(%rax)
 9ee:	00 00                	add    %al,(%rax)
 9f0:	08 00                	or     %al,(%rax)
 9f2:	00 00                	add    %al,(%rax)
 9f4:	00 00                	add    %al,(%rax)
 9f6:	00 00                	add    %al,(%rax)
 9f8:	20 56 00             	and    %dl,0x0(%rsi)
 9fb:	00 00                	add    %al,(%rax)
 9fd:	00 00                	add    %al,(%rax)
 9ff:	00 d8                	add    %bl,%al
 a01:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 a04:	00 00                	add    %al,(%rax)
 a06:	00 00                	add    %al,(%rax)
 a08:	06                   	(bad)  
 a09:	00 00                	add    %al,(%rax)
 a0b:	00 02                	add    %al,(%rdx)
	...
 a15:	00 00                	add    %al,(%rax)
 a17:	00 e0                	add    %ah,%al
 a19:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 a1c:	00 00                	add    %al,(%rax)
 a1e:	00 00                	add    %al,(%rax)
 a20:	06                   	(bad)  
 a21:	00 00                	add    %al,(%rax)
 a23:	00 03                	add    %al,(%rbx)
	...
 a2d:	00 00                	add    %al,(%rax)
 a2f:	00 e8                	add    %ch,%al
 a31:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 a34:	00 00                	add    %al,(%rax)
 a36:	00 00                	add    %al,(%rax)
 a38:	06                   	(bad)  
 a39:	00 00                	add    %al,(%rax)
 a3b:	00 0a                	add    %cl,(%rdx)
	...
 a45:	00 00                	add    %al,(%rax)
 a47:	00 f0                	add    %dh,%al
 a49:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 a4c:	00 00                	add    %al,(%rax)
 a4e:	00 00                	add    %al,(%rax)
 a50:	06                   	(bad)  
 a51:	00 00                	add    %al,(%rax)
 a53:	00 10                	add    %dl,(%rax)
	...
 a5d:	00 00                	add    %al,(%rax)
 a5f:	00 f8                	add    %bh,%al
 a61:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 a64:	00 00                	add    %al,(%rax)
 a66:	00 00                	add    %al,(%rax)
 a68:	06                   	(bad)  
 a69:	00 00                	add    %al,(%rax)
 a6b:	00 14 00             	add    %dl,(%rax,%rax,1)
	...
 a76:	00 00                	add    %al,(%rax)
 a78:	80 56 00 00          	adcb   $0x0,0x0(%rsi)
 a7c:	00 00                	add    %al,(%rax)
 a7e:	00 00                	add    %al,(%rax)
 a80:	05 00 00 00 13       	add    $0x13000000,%eax
	...
 a8d:	00 00                	add    %al,(%rax)
 a8f:	00 90 56 00 00 00    	add    %dl,0x56(%rax)
 a95:	00 00                	add    %al,(%rax)
 a97:	00 05 00 00 00 15    	add    %al,0x15000000(%rip)        # 15000a9d <_end+0x14ffad2d>
	...

Disassembly of section .rela.plt:

0000000000000aa8 <.rela.plt>:
 aa8:	68 4f 00 00 00       	push   $0x4f
 aad:	00 00                	add    %al,(%rax)
 aaf:	00 07                	add    %al,(%rdi)
 ab1:	00 00                	add    %al,(%rax)
 ab3:	00 01                	add    %al,(%rcx)
	...
 abd:	00 00                	add    %al,(%rax)
 abf:	00 70 4f             	add    %dh,0x4f(%rax)
 ac2:	00 00                	add    %al,(%rax)
 ac4:	00 00                	add    %al,(%rax)
 ac6:	00 00                	add    %al,(%rax)
 ac8:	07                   	(bad)  
 ac9:	00 00                	add    %al,(%rax)
 acb:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 ad6:	00 00                	add    %al,(%rax)
 ad8:	78 4f                	js     b29 <__abi_tag+0x79d>
 ada:	00 00                	add    %al,(%rax)
 adc:	00 00                	add    %al,(%rax)
 ade:	00 00                	add    %al,(%rax)
 ae0:	07                   	(bad)  
 ae1:	00 00                	add    %al,(%rax)
 ae3:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # ae9 <__abi_tag+0x75d>
 ae9:	00 00                	add    %al,(%rax)
 aeb:	00 00                	add    %al,(%rax)
 aed:	00 00                	add    %al,(%rax)
 aef:	00 80 4f 00 00 00    	add    %al,0x4f(%rax)
 af5:	00 00                	add    %al,(%rax)
 af7:	00 07                	add    %al,(%rdi)
 af9:	00 00                	add    %al,(%rax)
 afb:	00 06                	add    %al,(%rsi)
	...
 b05:	00 00                	add    %al,(%rax)
 b07:	00 88 4f 00 00 00    	add    %cl,0x4f(%rax)
 b0d:	00 00                	add    %al,(%rax)
 b0f:	00 07                	add    %al,(%rdi)
 b11:	00 00                	add    %al,(%rax)
 b13:	00 07                	add    %al,(%rdi)
	...
 b1d:	00 00                	add    %al,(%rax)
 b1f:	00 90 4f 00 00 00    	add    %dl,0x4f(%rax)
 b25:	00 00                	add    %al,(%rax)
 b27:	00 07                	add    %al,(%rdi)
 b29:	00 00                	add    %al,(%rax)
 b2b:	00 08                	add    %cl,(%rax)
	...
 b35:	00 00                	add    %al,(%rax)
 b37:	00 98 4f 00 00 00    	add    %bl,0x4f(%rax)
 b3d:	00 00                	add    %al,(%rax)
 b3f:	00 07                	add    %al,(%rdi)
 b41:	00 00                	add    %al,(%rax)
 b43:	00 09                	add    %cl,(%rcx)
	...
 b4d:	00 00                	add    %al,(%rax)
 b4f:	00 a0 4f 00 00 00    	add    %ah,0x4f(%rax)
 b55:	00 00                	add    %al,(%rax)
 b57:	00 07                	add    %al,(%rdi)
 b59:	00 00                	add    %al,(%rax)
 b5b:	00 0b                	add    %cl,(%rbx)
	...
 b65:	00 00                	add    %al,(%rax)
 b67:	00 a8 4f 00 00 00    	add    %ch,0x4f(%rax)
 b6d:	00 00                	add    %al,(%rax)
 b6f:	00 07                	add    %al,(%rdi)
 b71:	00 00                	add    %al,(%rax)
 b73:	00 0c 00             	add    %cl,(%rax,%rax,1)
	...
 b7e:	00 00                	add    %al,(%rax)
 b80:	b0 4f                	mov    $0x4f,%al
 b82:	00 00                	add    %al,(%rax)
 b84:	00 00                	add    %al,(%rax)
 b86:	00 00                	add    %al,(%rax)
 b88:	07                   	(bad)  
 b89:	00 00                	add    %al,(%rax)
 b8b:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # b91 <__abi_tag+0x805>
 b91:	00 00                	add    %al,(%rax)
 b93:	00 00                	add    %al,(%rax)
 b95:	00 00                	add    %al,(%rax)
 b97:	00 b8 4f 00 00 00    	add    %bh,0x4f(%rax)
 b9d:	00 00                	add    %al,(%rax)
 b9f:	00 07                	add    %al,(%rdi)
 ba1:	00 00                	add    %al,(%rax)
 ba3:	00 0e                	add    %cl,(%rsi)
	...
 bad:	00 00                	add    %al,(%rax)
 baf:	00 c0                	add    %al,%al
 bb1:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 bb4:	00 00                	add    %al,(%rax)
 bb6:	00 00                	add    %al,(%rax)
 bb8:	07                   	(bad)  
 bb9:	00 00                	add    %al,(%rax)
 bbb:	00 0f                	add    %cl,(%rdi)
	...
 bc5:	00 00                	add    %al,(%rax)
 bc7:	00 c8                	add    %cl,%al
 bc9:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 bcc:	00 00                	add    %al,(%rax)
 bce:	00 00                	add    %al,(%rax)
 bd0:	07                   	(bad)  
 bd1:	00 00                	add    %al,(%rax)
 bd3:	00 11                	add    %dl,(%rcx)
	...
 bdd:	00 00                	add    %al,(%rax)
 bdf:	00 d0                	add    %dl,%al
 be1:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 be4:	00 00                	add    %al,(%rax)
 be6:	00 00                	add    %al,(%rax)
 be8:	07                   	(bad)  
 be9:	00 00                	add    %al,(%rax)
 beb:	00 12                	add    %dl,(%rdx)
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 3f 00 00 	mov    0x3fd9(%rip),%rax        # 4fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 32 3f 00 00    	push   0x3f32(%rip)        # 4f58 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 33 3f 00 00 	bnd jmp *0x3f33(%rip)        # 4f60 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	push   $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmp 1020 <_init+0x20>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	push   $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmp 1020 <_init+0x20>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	push   $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	push   $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	push   $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	push   $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	push   $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	push   $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmp 1020 <_init+0x20>
    10ff:	90                   	nop
    1100:	f3 0f 1e fa          	endbr64 
    1104:	68 0d 00 00 00       	push   $0xd
    1109:	f2 e9 11 ff ff ff    	bnd jmp 1020 <_init+0x20>
    110f:	90                   	nop

Disassembly of section .plt.got:

0000000000001110 <__cxa_finalize@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 dd 3e 00 00 	bnd jmp *0x3edd(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001120 <getenv@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 3d 3e 00 00 	bnd jmp *0x3e3d(%rip)        # 4f68 <getenv@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <puts@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 35 3e 00 00 	bnd jmp *0x3e35(%rip)        # 4f70 <puts@GLIBC_2.2.5>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <strlen@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 2d 3e 00 00 	bnd jmp *0x3e2d(%rip)        # 4f78 <strlen@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <__stack_chk_fail@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 25 3e 00 00 	bnd jmp *0x3e25(%rip)        # 4f80 <__stack_chk_fail@GLIBC_2.4>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <printf@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 1d 3e 00 00 	bnd jmp *0x3e1d(%rip)        # 4f88 <printf@GLIBC_2.2.5>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <fgets@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 15 3e 00 00 	bnd jmp *0x3e15(%rip)        # 4f90 <fgets@GLIBC_2.2.5>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001180 <signal@plt>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	f2 ff 25 0d 3e 00 00 	bnd jmp *0x3e0d(%rip)        # 4f98 <signal@GLIBC_2.2.5>
    118b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001190 <fflush@plt>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	f2 ff 25 05 3e 00 00 	bnd jmp *0x3e05(%rip)        # 4fa0 <fflush@GLIBC_2.2.5>
    119b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011a0 <__isoc99_sscanf@plt>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	f2 ff 25 fd 3d 00 00 	bnd jmp *0x3dfd(%rip)        # 4fa8 <__isoc99_sscanf@GLIBC_2.7>
    11ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011b0 <fopen@plt>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	f2 ff 25 f5 3d 00 00 	bnd jmp *0x3df5(%rip)        # 4fb0 <fopen@GLIBC_2.2.5>
    11bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011c0 <atoi@plt>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	f2 ff 25 ed 3d 00 00 	bnd jmp *0x3ded(%rip)        # 4fb8 <atoi@GLIBC_2.2.5>
    11cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011d0 <exit@plt>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	f2 ff 25 e5 3d 00 00 	bnd jmp *0x3de5(%rip)        # 4fc0 <exit@GLIBC_2.2.5>
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011e0 <sleep@plt>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	f2 ff 25 dd 3d 00 00 	bnd jmp *0x3ddd(%rip)        # 4fc8 <sleep@GLIBC_2.2.5>
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011f0 <__ctype_b_loc@plt>:
    11f0:	f3 0f 1e fa          	endbr64 
    11f4:	f2 ff 25 d5 3d 00 00 	bnd jmp *0x3dd5(%rip)        # 4fd0 <__ctype_b_loc@GLIBC_2.3>
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001200 <_start>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	31 ed                	xor    %ebp,%ebp
    1206:	49 89 d1             	mov    %rdx,%r9
    1209:	5e                   	pop    %rsi
    120a:	48 89 e2             	mov    %rsp,%rdx
    120d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1211:	50                   	push   %rax
    1212:	54                   	push   %rsp
    1213:	45 31 c0             	xor    %r8d,%r8d
    1216:	31 c9                	xor    %ecx,%ecx
    1218:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 12e9 <main>
    121f:	ff 15 b3 3d 00 00    	call   *0x3db3(%rip)        # 4fd8 <__libc_start_main@GLIBC_2.34>
    1225:	f4                   	hlt    
    1226:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    122d:	00 00 00 

0000000000001230 <deregister_tm_clones>:
    1230:	48 8d 3d 41 44 00 00 	lea    0x4441(%rip),%rdi        # 5678 <__TMC_END__>
    1237:	48 8d 05 3a 44 00 00 	lea    0x443a(%rip),%rax        # 5678 <__TMC_END__>
    123e:	48 39 f8             	cmp    %rdi,%rax
    1241:	74 15                	je     1258 <deregister_tm_clones+0x28>
    1243:	48 8b 05 96 3d 00 00 	mov    0x3d96(%rip),%rax        # 4fe0 <_ITM_deregisterTMCloneTable@Base>
    124a:	48 85 c0             	test   %rax,%rax
    124d:	74 09                	je     1258 <deregister_tm_clones+0x28>
    124f:	ff e0                	jmp    *%rax
    1251:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1258:	c3                   	ret    
    1259:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001260 <register_tm_clones>:
    1260:	48 8d 3d 11 44 00 00 	lea    0x4411(%rip),%rdi        # 5678 <__TMC_END__>
    1267:	48 8d 35 0a 44 00 00 	lea    0x440a(%rip),%rsi        # 5678 <__TMC_END__>
    126e:	48 29 fe             	sub    %rdi,%rsi
    1271:	48 89 f0             	mov    %rsi,%rax
    1274:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1278:	48 c1 f8 03          	sar    $0x3,%rax
    127c:	48 01 c6             	add    %rax,%rsi
    127f:	48 d1 fe             	sar    %rsi
    1282:	74 14                	je     1298 <register_tm_clones+0x38>
    1284:	48 8b 05 65 3d 00 00 	mov    0x3d65(%rip),%rax        # 4ff0 <_ITM_registerTMCloneTable@Base>
    128b:	48 85 c0             	test   %rax,%rax
    128e:	74 08                	je     1298 <register_tm_clones+0x38>
    1290:	ff e0                	jmp    *%rax
    1292:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1298:	c3                   	ret    
    1299:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012a0 <__do_global_dtors_aux>:
    12a0:	f3 0f 1e fa          	endbr64 
    12a4:	80 3d ed 43 00 00 00 	cmpb   $0x0,0x43ed(%rip)        # 5698 <completed.0>
    12ab:	75 2b                	jne    12d8 <__do_global_dtors_aux+0x38>
    12ad:	55                   	push   %rbp
    12ae:	48 83 3d 42 3d 00 00 	cmpq   $0x0,0x3d42(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    12b5:	00 
    12b6:	48 89 e5             	mov    %rsp,%rbp
    12b9:	74 0c                	je     12c7 <__do_global_dtors_aux+0x27>
    12bb:	48 8b 3d 46 3d 00 00 	mov    0x3d46(%rip),%rdi        # 5008 <__dso_handle>
    12c2:	e8 49 fe ff ff       	call   1110 <__cxa_finalize@plt>
    12c7:	e8 64 ff ff ff       	call   1230 <deregister_tm_clones>
    12cc:	c6 05 c5 43 00 00 01 	movb   $0x1,0x43c5(%rip)        # 5698 <completed.0>
    12d3:	5d                   	pop    %rbp
    12d4:	c3                   	ret    
    12d5:	0f 1f 00             	nopl   (%rax)
    12d8:	c3                   	ret    
    12d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012e0 <frame_dummy>:
    12e0:	f3 0f 1e fa          	endbr64 
    12e4:	e9 77 ff ff ff       	jmp    1260 <register_tm_clones>

00000000000012e9 <main>:
    12e9:	f3 0f 1e fa          	endbr64 
    12ed:	55                   	push   %rbp
    12ee:	48 89 e5             	mov    %rsp,%rbp
    12f1:	48 83 ec 20          	sub    $0x20,%rsp
    12f5:	89 7d ec             	mov    %edi,-0x14(%rbp)
    12f8:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    12fc:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
    1300:	75 13                	jne    1315 <main+0x2c>
    1302:	48 8b 05 87 43 00 00 	mov    0x4387(%rip),%rax        # 5690 <stdin@GLIBC_2.2.5>
    1309:	48 89 05 90 43 00 00 	mov    %rax,0x4390(%rip)        # 56a0 <infile>
    1310:	e9 91 00 00 00       	jmp    13a6 <main+0xbd>
    1315:	83 7d ec 02          	cmpl   $0x2,-0x14(%rbp)
    1319:	75 63                	jne    137e <main+0x95>
    131b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    131f:	48 83 c0 08          	add    $0x8,%rax
    1323:	48 8b 00             	mov    (%rax),%rax
    1326:	48 8d 15 db 1c 00 00 	lea    0x1cdb(%rip),%rdx        # 3008 <_IO_stdin_used+0x8>
    132d:	48 89 d6             	mov    %rdx,%rsi
    1330:	48 89 c7             	mov    %rax,%rdi
    1333:	e8 78 fe ff ff       	call   11b0 <fopen@plt>
    1338:	48 89 05 61 43 00 00 	mov    %rax,0x4361(%rip)        # 56a0 <infile>
    133f:	48 8b 05 5a 43 00 00 	mov    0x435a(%rip),%rax        # 56a0 <infile>
    1346:	48 85 c0             	test   %rax,%rax
    1349:	75 5b                	jne    13a6 <main+0xbd>
    134b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    134f:	48 83 c0 08          	add    $0x8,%rax
    1353:	48 8b 10             	mov    (%rax),%rdx
    1356:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    135a:	48 8b 00             	mov    (%rax),%rax
    135d:	48 89 c6             	mov    %rax,%rsi
    1360:	48 8d 05 a3 1c 00 00 	lea    0x1ca3(%rip),%rax        # 300a <_IO_stdin_used+0xa>
    1367:	48 89 c7             	mov    %rax,%rdi
    136a:	b8 00 00 00 00       	mov    $0x0,%eax
    136f:	e8 ec fd ff ff       	call   1160 <printf@plt>
    1374:	bf 08 00 00 00       	mov    $0x8,%edi
    1379:	e8 52 fe ff ff       	call   11d0 <exit@plt>
    137e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1382:	48 8b 00             	mov    (%rax),%rax
    1385:	48 89 c6             	mov    %rax,%rsi
    1388:	48 8d 05 98 1c 00 00 	lea    0x1c98(%rip),%rax        # 3027 <_IO_stdin_used+0x27>
    138f:	48 89 c7             	mov    %rax,%rdi
    1392:	b8 00 00 00 00       	mov    $0x0,%eax
    1397:	e8 c4 fd ff ff       	call   1160 <printf@plt>
    139c:	bf 08 00 00 00       	mov    $0x8,%edi
    13a1:	e8 2a fe ff ff       	call   11d0 <exit@plt>
    13a6:	e8 d9 02 00 00       	call   1684 <initialize_bomb>
    13ab:	48 8d 05 96 1c 00 00 	lea    0x1c96(%rip),%rax        # 3048 <_IO_stdin_used+0x48>
    13b2:	48 89 c7             	mov    %rax,%rdi
    13b5:	e8 76 fd ff ff       	call   1130 <puts@plt>
    13ba:	48 8d 05 c7 1c 00 00 	lea    0x1cc7(%rip),%rax        # 3088 <_IO_stdin_used+0x88>
    13c1:	48 89 c7             	mov    %rax,%rdi
    13c4:	e8 67 fd ff ff       	call   1130 <puts@plt>
    13c9:	e8 9d 03 00 00       	call   176b <read_line>
    13ce:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    13d2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13d6:	48 89 c7             	mov    %rax,%rdi
    13d9:	e8 1e 06 00 00       	call   19fc <phase_1>
    13de:	e8 4b 05 00 00       	call   192e <phase_defused>
    13e3:	48 8d 05 ce 1c 00 00 	lea    0x1cce(%rip),%rax        # 30b8 <_IO_stdin_used+0xb8>
    13ea:	48 89 c7             	mov    %rax,%rdi
    13ed:	e8 3e fd ff ff       	call   1130 <puts@plt>
    13f2:	e8 74 03 00 00       	call   176b <read_line>
    13f7:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    13fb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13ff:	48 89 c7             	mov    %rax,%rdi
    1402:	e8 24 06 00 00       	call   1a2b <phase_2>
    1407:	e8 22 05 00 00       	call   192e <phase_defused>
    140c:	48 8d 05 ce 1c 00 00 	lea    0x1cce(%rip),%rax        # 30e1 <_IO_stdin_used+0xe1>
    1413:	48 89 c7             	mov    %rax,%rdi
    1416:	e8 15 fd ff ff       	call   1130 <puts@plt>
    141b:	e8 4b 03 00 00       	call   176b <read_line>
    1420:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1424:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1428:	48 89 c7             	mov    %rax,%rdi
    142b:	e8 86 06 00 00       	call   1ab6 <phase_3>
    1430:	e8 f9 04 00 00       	call   192e <phase_defused>
    1435:	48 8d 05 c3 1c 00 00 	lea    0x1cc3(%rip),%rax        # 30ff <_IO_stdin_used+0xff>
    143c:	48 89 c7             	mov    %rax,%rdi
    143f:	e8 ec fc ff ff       	call   1130 <puts@plt>
    1444:	e8 22 03 00 00       	call   176b <read_line>
    1449:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    144d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1451:	48 89 c7             	mov    %rax,%rdi
    1454:	e8 ce 07 00 00       	call   1c27 <phase_4>
    1459:	e8 d0 04 00 00       	call   192e <phase_defused>
    145e:	48 8d 05 ab 1c 00 00 	lea    0x1cab(%rip),%rax        # 3110 <_IO_stdin_used+0x110>
    1465:	48 89 c7             	mov    %rax,%rdi
    1468:	e8 c3 fc ff ff       	call   1130 <puts@plt>
    146d:	e8 f9 02 00 00       	call   176b <read_line>
    1472:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1476:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    147a:	48 89 c7             	mov    %rax,%rdi
    147d:	e8 4b 08 00 00       	call   1ccd <phase_5>
    1482:	e8 a7 04 00 00       	call   192e <phase_defused>
    1487:	48 8d 05 a6 1c 00 00 	lea    0x1ca6(%rip),%rax        # 3134 <_IO_stdin_used+0x134>
    148e:	48 89 c7             	mov    %rax,%rdi
    1491:	e8 9a fc ff ff       	call   1130 <puts@plt>
    1496:	e8 d0 02 00 00       	call   176b <read_line>
    149b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    149f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    14a3:	48 89 c7             	mov    %rax,%rdi
    14a6:	e8 d1 08 00 00       	call   1d7c <phase_6>
    14ab:	e8 7e 04 00 00       	call   192e <phase_defused>
    14b0:	b8 00 00 00 00       	mov    $0x0,%eax
    14b5:	c9                   	leave  
    14b6:	c3                   	ret    

00000000000014b7 <sig_handler>:
    14b7:	f3 0f 1e fa          	endbr64 
    14bb:	55                   	push   %rbp
    14bc:	48 89 e5             	mov    %rsp,%rbp
    14bf:	48 83 ec 10          	sub    $0x10,%rsp
    14c3:	89 7d fc             	mov    %edi,-0x4(%rbp)
    14c6:	48 8d 05 db 1c 00 00 	lea    0x1cdb(%rip),%rax        # 31a8 <_IO_stdin_used+0x1a8>
    14cd:	48 89 c7             	mov    %rax,%rdi
    14d0:	e8 5b fc ff ff       	call   1130 <puts@plt>
    14d5:	bf 03 00 00 00       	mov    $0x3,%edi
    14da:	e8 01 fd ff ff       	call   11e0 <sleep@plt>
    14df:	48 8d 05 fa 1c 00 00 	lea    0x1cfa(%rip),%rax        # 31e0 <_IO_stdin_used+0x1e0>
    14e6:	48 89 c7             	mov    %rax,%rdi
    14e9:	b8 00 00 00 00       	mov    $0x0,%eax
    14ee:	e8 6d fc ff ff       	call   1160 <printf@plt>
    14f3:	48 8b 05 86 41 00 00 	mov    0x4186(%rip),%rax        # 5680 <stdout@GLIBC_2.2.5>
    14fa:	48 89 c7             	mov    %rax,%rdi
    14fd:	e8 8e fc ff ff       	call   1190 <fflush@plt>
    1502:	bf 01 00 00 00       	mov    $0x1,%edi
    1507:	e8 d4 fc ff ff       	call   11e0 <sleep@plt>
    150c:	48 8d 05 d5 1c 00 00 	lea    0x1cd5(%rip),%rax        # 31e8 <_IO_stdin_used+0x1e8>
    1513:	48 89 c7             	mov    %rax,%rdi
    1516:	e8 15 fc ff ff       	call   1130 <puts@plt>
    151b:	bf 10 00 00 00       	mov    $0x10,%edi
    1520:	e8 ab fc ff ff       	call   11d0 <exit@plt>

0000000000001525 <invalid_phase>:
    1525:	f3 0f 1e fa          	endbr64 
    1529:	55                   	push   %rbp
    152a:	48 89 e5             	mov    %rsp,%rbp
    152d:	48 83 ec 10          	sub    $0x10,%rsp
    1531:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1535:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1539:	48 89 c6             	mov    %rax,%rsi
    153c:	48 8d 05 ad 1c 00 00 	lea    0x1cad(%rip),%rax        # 31f0 <_IO_stdin_used+0x1f0>
    1543:	48 89 c7             	mov    %rax,%rdi
    1546:	b8 00 00 00 00       	mov    $0x0,%eax
    154b:	e8 10 fc ff ff       	call   1160 <printf@plt>
    1550:	bf 08 00 00 00       	mov    $0x8,%edi
    1555:	e8 76 fc ff ff       	call   11d0 <exit@plt>

000000000000155a <read_six_numbers>:
    155a:	f3 0f 1e fa          	endbr64 
    155e:	55                   	push   %rbp
    155f:	48 89 e5             	mov    %rsp,%rbp
    1562:	48 83 ec 20          	sub    $0x20,%rsp
    1566:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    156a:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    156e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1572:	48 8d 78 14          	lea    0x14(%rax),%rdi
    1576:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    157a:	48 8d 70 10          	lea    0x10(%rax),%rsi
    157e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1582:	4c 8d 48 0c          	lea    0xc(%rax),%r9
    1586:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    158a:	4c 8d 40 08          	lea    0x8(%rax),%r8
    158e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1592:	48 8d 48 04          	lea    0x4(%rax),%rcx
    1596:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    159a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    159e:	57                   	push   %rdi
    159f:	56                   	push   %rsi
    15a0:	48 8d 35 5a 1c 00 00 	lea    0x1c5a(%rip),%rsi        # 3201 <_IO_stdin_used+0x201>
    15a7:	48 89 c7             	mov    %rax,%rdi
    15aa:	b8 00 00 00 00       	mov    $0x0,%eax
    15af:	e8 ec fb ff ff       	call   11a0 <__isoc99_sscanf@plt>
    15b4:	48 83 c4 10          	add    $0x10,%rsp
    15b8:	89 45 fc             	mov    %eax,-0x4(%rbp)
    15bb:	83 7d fc 05          	cmpl   $0x5,-0x4(%rbp)
    15bf:	7f 05                	jg     15c6 <read_six_numbers+0x6c>
    15c1:	e8 38 03 00 00       	call   18fe <explode_bomb>
    15c6:	90                   	nop
    15c7:	c9                   	leave  
    15c8:	c3                   	ret    

00000000000015c9 <string_length>:
    15c9:	f3 0f 1e fa          	endbr64 
    15cd:	55                   	push   %rbp
    15ce:	48 89 e5             	mov    %rsp,%rbp
    15d1:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    15d5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    15d9:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    15dd:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    15e4:	eb 09                	jmp    15ef <string_length+0x26>
    15e6:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    15eb:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    15ef:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15f3:	0f b6 00             	movzbl (%rax),%eax
    15f6:	84 c0                	test   %al,%al
    15f8:	75 ec                	jne    15e6 <string_length+0x1d>
    15fa:	8b 45 f4             	mov    -0xc(%rbp),%eax
    15fd:	5d                   	pop    %rbp
    15fe:	c3                   	ret    

00000000000015ff <strings_not_equal>:
    15ff:	f3 0f 1e fa          	endbr64 
    1603:	55                   	push   %rbp
    1604:	48 89 e5             	mov    %rsp,%rbp
    1607:	53                   	push   %rbx
    1608:	48 83 ec 20          	sub    $0x20,%rsp
    160c:	48 89 7d e0          	mov    %rdi,-0x20(%rbp)
    1610:	48 89 75 d8          	mov    %rsi,-0x28(%rbp)
    1614:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1618:	48 89 c7             	mov    %rax,%rdi
    161b:	e8 a9 ff ff ff       	call   15c9 <string_length>
    1620:	89 c3                	mov    %eax,%ebx
    1622:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1626:	48 89 c7             	mov    %rax,%rdi
    1629:	e8 9b ff ff ff       	call   15c9 <string_length>
    162e:	39 c3                	cmp    %eax,%ebx
    1630:	74 07                	je     1639 <strings_not_equal+0x3a>
    1632:	b8 01 00 00 00       	mov    $0x1,%eax
    1637:	eb 45                	jmp    167e <strings_not_equal+0x7f>
    1639:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    163d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1641:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1645:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1649:	eb 23                	jmp    166e <strings_not_equal+0x6f>
    164b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    164f:	0f b6 10             	movzbl (%rax),%edx
    1652:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1656:	0f b6 00             	movzbl (%rax),%eax
    1659:	38 c2                	cmp    %al,%dl
    165b:	74 07                	je     1664 <strings_not_equal+0x65>
    165d:	b8 01 00 00 00       	mov    $0x1,%eax
    1662:	eb 1a                	jmp    167e <strings_not_equal+0x7f>
    1664:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
    1669:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    166e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1672:	0f b6 00             	movzbl (%rax),%eax
    1675:	84 c0                	test   %al,%al
    1677:	75 d2                	jne    164b <strings_not_equal+0x4c>
    1679:	b8 00 00 00 00       	mov    $0x0,%eax
    167e:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    1682:	c9                   	leave  
    1683:	c3                   	ret    

0000000000001684 <initialize_bomb>:
    1684:	f3 0f 1e fa          	endbr64 
    1688:	55                   	push   %rbp
    1689:	48 89 e5             	mov    %rsp,%rbp
    168c:	48 8d 05 24 fe ff ff 	lea    -0x1dc(%rip),%rax        # 14b7 <sig_handler>
    1693:	48 89 c6             	mov    %rax,%rsi
    1696:	bf 02 00 00 00       	mov    $0x2,%edi
    169b:	e8 e0 fa ff ff       	call   1180 <signal@plt>
    16a0:	90                   	nop
    16a1:	5d                   	pop    %rbp
    16a2:	c3                   	ret    

00000000000016a3 <initialize_bomb_solve>:
    16a3:	f3 0f 1e fa          	endbr64 
    16a7:	55                   	push   %rbp
    16a8:	48 89 e5             	mov    %rsp,%rbp
    16ab:	90                   	nop
    16ac:	5d                   	pop    %rbp
    16ad:	c3                   	ret    

00000000000016ae <blank_line>:
    16ae:	f3 0f 1e fa          	endbr64 
    16b2:	55                   	push   %rbp
    16b3:	48 89 e5             	mov    %rsp,%rbp
    16b6:	48 83 ec 10          	sub    $0x10,%rsp
    16ba:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    16be:	eb 37                	jmp    16f7 <blank_line+0x49>
    16c0:	e8 2b fb ff ff       	call   11f0 <__ctype_b_loc@plt>
    16c5:	48 8b 08             	mov    (%rax),%rcx
    16c8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    16cc:	48 8d 50 01          	lea    0x1(%rax),%rdx
    16d0:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
    16d4:	0f b6 00             	movzbl (%rax),%eax
    16d7:	48 0f be c0          	movsbq %al,%rax
    16db:	48 01 c0             	add    %rax,%rax
    16de:	48 01 c8             	add    %rcx,%rax
    16e1:	0f b7 00             	movzwl (%rax),%eax
    16e4:	0f b7 c0             	movzwl %ax,%eax
    16e7:	25 00 20 00 00       	and    $0x2000,%eax
    16ec:	85 c0                	test   %eax,%eax
    16ee:	75 07                	jne    16f7 <blank_line+0x49>
    16f0:	b8 00 00 00 00       	mov    $0x0,%eax
    16f5:	eb 10                	jmp    1707 <blank_line+0x59>
    16f7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    16fb:	0f b6 00             	movzbl (%rax),%eax
    16fe:	84 c0                	test   %al,%al
    1700:	75 be                	jne    16c0 <blank_line+0x12>
    1702:	b8 01 00 00 00       	mov    $0x1,%eax
    1707:	c9                   	leave  
    1708:	c3                   	ret    

0000000000001709 <skip>:
    1709:	f3 0f 1e fa          	endbr64 
    170d:	55                   	push   %rbp
    170e:	48 89 e5             	mov    %rsp,%rbp
    1711:	48 83 ec 10          	sub    $0x10,%rsp
    1715:	48 8b 15 84 3f 00 00 	mov    0x3f84(%rip),%rdx        # 56a0 <infile>
    171c:	8b 05 de 45 00 00    	mov    0x45de(%rip),%eax        # 5d00 <num_input_strings>
    1722:	48 63 c8             	movslq %eax,%rcx
    1725:	48 89 c8             	mov    %rcx,%rax
    1728:	48 c1 e0 02          	shl    $0x2,%rax
    172c:	48 01 c8             	add    %rcx,%rax
    172f:	48 c1 e0 04          	shl    $0x4,%rax
    1733:	48 8d 0d 86 3f 00 00 	lea    0x3f86(%rip),%rcx        # 56c0 <input_strings>
    173a:	48 01 c8             	add    %rcx,%rax
    173d:	be 50 00 00 00       	mov    $0x50,%esi
    1742:	48 89 c7             	mov    %rax,%rdi
    1745:	e8 26 fa ff ff       	call   1170 <fgets@plt>
    174a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    174e:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1753:	74 10                	je     1765 <skip+0x5c>
    1755:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1759:	48 89 c7             	mov    %rax,%rdi
    175c:	e8 4d ff ff ff       	call   16ae <blank_line>
    1761:	85 c0                	test   %eax,%eax
    1763:	75 b0                	jne    1715 <skip+0xc>
    1765:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1769:	c9                   	leave  
    176a:	c3                   	ret    

000000000000176b <read_line>:
    176b:	f3 0f 1e fa          	endbr64 
    176f:	55                   	push   %rbp
    1770:	48 89 e5             	mov    %rsp,%rbp
    1773:	48 83 ec 10          	sub    $0x10,%rsp
    1777:	b8 00 00 00 00       	mov    $0x0,%eax
    177c:	e8 88 ff ff ff       	call   1709 <skip>
    1781:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1785:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    178a:	0f 85 86 00 00 00    	jne    1816 <read_line+0xab>
    1790:	48 8b 15 09 3f 00 00 	mov    0x3f09(%rip),%rdx        # 56a0 <infile>
    1797:	48 8b 05 f2 3e 00 00 	mov    0x3ef2(%rip),%rax        # 5690 <stdin@GLIBC_2.2.5>
    179e:	48 39 c2             	cmp    %rax,%rdx
    17a1:	75 19                	jne    17bc <read_line+0x51>
    17a3:	48 8d 05 69 1a 00 00 	lea    0x1a69(%rip),%rax        # 3213 <_IO_stdin_used+0x213>
    17aa:	48 89 c7             	mov    %rax,%rdi
    17ad:	e8 7e f9 ff ff       	call   1130 <puts@plt>
    17b2:	bf 08 00 00 00       	mov    $0x8,%edi
    17b7:	e8 14 fa ff ff       	call   11d0 <exit@plt>
    17bc:	48 8d 05 6e 1a 00 00 	lea    0x1a6e(%rip),%rax        # 3231 <_IO_stdin_used+0x231>
    17c3:	48 89 c7             	mov    %rax,%rdi
    17c6:	e8 55 f9 ff ff       	call   1120 <getenv@plt>
    17cb:	48 85 c0             	test   %rax,%rax
    17ce:	74 0a                	je     17da <read_line+0x6f>
    17d0:	bf 00 00 00 00       	mov    $0x0,%edi
    17d5:	e8 f6 f9 ff ff       	call   11d0 <exit@plt>
    17da:	48 8b 05 af 3e 00 00 	mov    0x3eaf(%rip),%rax        # 5690 <stdin@GLIBC_2.2.5>
    17e1:	48 89 05 b8 3e 00 00 	mov    %rax,0x3eb8(%rip)        # 56a0 <infile>
    17e8:	b8 00 00 00 00       	mov    $0x0,%eax
    17ed:	e8 17 ff ff ff       	call   1709 <skip>
    17f2:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    17f6:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    17fb:	75 19                	jne    1816 <read_line+0xab>
    17fd:	48 8d 05 0f 1a 00 00 	lea    0x1a0f(%rip),%rax        # 3213 <_IO_stdin_used+0x213>
    1804:	48 89 c7             	mov    %rax,%rdi
    1807:	e8 24 f9 ff ff       	call   1130 <puts@plt>
    180c:	bf 00 00 00 00       	mov    $0x0,%edi
    1811:	e8 ba f9 ff ff       	call   11d0 <exit@plt>
    1816:	8b 05 e4 44 00 00    	mov    0x44e4(%rip),%eax        # 5d00 <num_input_strings>
    181c:	48 63 d0             	movslq %eax,%rdx
    181f:	48 89 d0             	mov    %rdx,%rax
    1822:	48 c1 e0 02          	shl    $0x2,%rax
    1826:	48 01 d0             	add    %rdx,%rax
    1829:	48 c1 e0 04          	shl    $0x4,%rax
    182d:	48 8d 15 8c 3e 00 00 	lea    0x3e8c(%rip),%rdx        # 56c0 <input_strings>
    1834:	48 01 d0             	add    %rdx,%rax
    1837:	48 89 c7             	mov    %rax,%rdi
    183a:	e8 01 f9 ff ff       	call   1140 <strlen@plt>
    183f:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1842:	83 7d f4 4e          	cmpl   $0x4e,-0xc(%rbp)
    1846:	7e 59                	jle    18a1 <read_line+0x136>
    1848:	48 8d 05 ed 19 00 00 	lea    0x19ed(%rip),%rax        # 323c <_IO_stdin_used+0x23c>
    184f:	48 89 c7             	mov    %rax,%rdi
    1852:	e8 d9 f8 ff ff       	call   1130 <puts@plt>
    1857:	8b 05 a3 44 00 00    	mov    0x44a3(%rip),%eax        # 5d00 <num_input_strings>
    185d:	8d 50 01             	lea    0x1(%rax),%edx
    1860:	89 15 9a 44 00 00    	mov    %edx,0x449a(%rip)        # 5d00 <num_input_strings>
    1866:	48 63 d0             	movslq %eax,%rdx
    1869:	48 89 d0             	mov    %rdx,%rax
    186c:	48 c1 e0 02          	shl    $0x2,%rax
    1870:	48 01 d0             	add    %rdx,%rax
    1873:	48 c1 e0 04          	shl    $0x4,%rax
    1877:	48 8d 15 42 3e 00 00 	lea    0x3e42(%rip),%rdx        # 56c0 <input_strings>
    187e:	48 01 d0             	add    %rdx,%rax
    1881:	48 be 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rsi
    1888:	75 6e 63 
    188b:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
    1892:	2a 2a 00 
    1895:	48 89 30             	mov    %rsi,(%rax)
    1898:	48 89 78 08          	mov    %rdi,0x8(%rax)
    189c:	e8 5d 00 00 00       	call   18fe <explode_bomb>
    18a1:	8b 05 59 44 00 00    	mov    0x4459(%rip),%eax        # 5d00 <num_input_strings>
    18a7:	8b 55 f4             	mov    -0xc(%rbp),%edx
    18aa:	83 ea 01             	sub    $0x1,%edx
    18ad:	48 63 ca             	movslq %edx,%rcx
    18b0:	48 63 d0             	movslq %eax,%rdx
    18b3:	48 89 d0             	mov    %rdx,%rax
    18b6:	48 c1 e0 02          	shl    $0x2,%rax
    18ba:	48 01 d0             	add    %rdx,%rax
    18bd:	48 c1 e0 04          	shl    $0x4,%rax
    18c1:	48 8d 14 08          	lea    (%rax,%rcx,1),%rdx
    18c5:	48 8d 05 f4 3d 00 00 	lea    0x3df4(%rip),%rax        # 56c0 <input_strings>
    18cc:	48 01 d0             	add    %rdx,%rax
    18cf:	c6 00 00             	movb   $0x0,(%rax)
    18d2:	8b 05 28 44 00 00    	mov    0x4428(%rip),%eax        # 5d00 <num_input_strings>
    18d8:	8d 50 01             	lea    0x1(%rax),%edx
    18db:	89 15 1f 44 00 00    	mov    %edx,0x441f(%rip)        # 5d00 <num_input_strings>
    18e1:	48 63 d0             	movslq %eax,%rdx
    18e4:	48 89 d0             	mov    %rdx,%rax
    18e7:	48 c1 e0 02          	shl    $0x2,%rax
    18eb:	48 01 d0             	add    %rdx,%rax
    18ee:	48 c1 e0 04          	shl    $0x4,%rax
    18f2:	48 8d 15 c7 3d 00 00 	lea    0x3dc7(%rip),%rdx        # 56c0 <input_strings>
    18f9:	48 01 d0             	add    %rdx,%rax
    18fc:	c9                   	leave  
    18fd:	c3                   	ret    

00000000000018fe <explode_bomb>:
    18fe:	f3 0f 1e fa          	endbr64 
    1902:	55                   	push   %rbp
    1903:	48 89 e5             	mov    %rsp,%rbp
    1906:	48 8d 05 4a 19 00 00 	lea    0x194a(%rip),%rax        # 3257 <_IO_stdin_used+0x257>
    190d:	48 89 c7             	mov    %rax,%rdi
    1910:	e8 1b f8 ff ff       	call   1130 <puts@plt>
    1915:	48 8d 05 44 19 00 00 	lea    0x1944(%rip),%rax        # 3260 <_IO_stdin_used+0x260>
    191c:	48 89 c7             	mov    %rax,%rdi
    191f:	e8 0c f8 ff ff       	call   1130 <puts@plt>
    1924:	bf 08 00 00 00       	mov    $0x8,%edi
    1929:	e8 a2 f8 ff ff       	call   11d0 <exit@plt>

000000000000192e <phase_defused>:
    192e:	f3 0f 1e fa          	endbr64 
    1932:	55                   	push   %rbp
    1933:	48 89 e5             	mov    %rsp,%rbp
    1936:	48 83 ec 70          	sub    $0x70,%rsp
    193a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1941:	00 00 
    1943:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1947:	31 c0                	xor    %eax,%eax
    1949:	8b 05 b1 43 00 00    	mov    0x43b1(%rip),%eax        # 5d00 <num_input_strings>
    194f:	83 f8 06             	cmp    $0x6,%eax
    1952:	0f 85 8d 00 00 00    	jne    19e5 <phase_defused+0xb7>
    1958:	48 8d 4d a0          	lea    -0x60(%rbp),%rcx
    195c:	48 8d 55 98          	lea    -0x68(%rbp),%rdx
    1960:	48 8d 45 94          	lea    -0x6c(%rbp),%rax
    1964:	49 89 c8             	mov    %rcx,%r8
    1967:	48 89 d1             	mov    %rdx,%rcx
    196a:	48 89 c2             	mov    %rax,%rdx
    196d:	48 8d 05 03 19 00 00 	lea    0x1903(%rip),%rax        # 3277 <_IO_stdin_used+0x277>
    1974:	48 89 c6             	mov    %rax,%rsi
    1977:	48 8d 05 32 3e 00 00 	lea    0x3e32(%rip),%rax        # 57b0 <input_strings+0xf0>
    197e:	48 89 c7             	mov    %rax,%rdi
    1981:	b8 00 00 00 00       	mov    $0x0,%eax
    1986:	e8 15 f8 ff ff       	call   11a0 <__isoc99_sscanf@plt>
    198b:	89 45 9c             	mov    %eax,-0x64(%rbp)
    198e:	83 7d 9c 03          	cmpl   $0x3,-0x64(%rbp)
    1992:	75 42                	jne    19d6 <phase_defused+0xa8>
    1994:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1998:	48 8d 15 e1 18 00 00 	lea    0x18e1(%rip),%rdx        # 3280 <_IO_stdin_used+0x280>
    199f:	48 89 d6             	mov    %rdx,%rsi
    19a2:	48 89 c7             	mov    %rax,%rdi
    19a5:	e8 55 fc ff ff       	call   15ff <strings_not_equal>
    19aa:	85 c0                	test   %eax,%eax
    19ac:	75 28                	jne    19d6 <phase_defused+0xa8>
    19ae:	48 8d 05 d3 18 00 00 	lea    0x18d3(%rip),%rax        # 3288 <_IO_stdin_used+0x288>
    19b5:	48 89 c7             	mov    %rax,%rdi
    19b8:	e8 73 f7 ff ff       	call   1130 <puts@plt>
    19bd:	48 8d 05 ec 18 00 00 	lea    0x18ec(%rip),%rax        # 32b0 <_IO_stdin_used+0x2b0>
    19c4:	48 89 c7             	mov    %rax,%rdi
    19c7:	e8 64 f7 ff ff       	call   1130 <puts@plt>
    19cc:	b8 00 00 00 00       	mov    $0x0,%eax
    19d1:	e8 b6 05 00 00       	call   1f8c <secret_phase>
    19d6:	48 8d 05 0b 19 00 00 	lea    0x190b(%rip),%rax        # 32e8 <_IO_stdin_used+0x2e8>
    19dd:	48 89 c7             	mov    %rax,%rdi
    19e0:	e8 4b f7 ff ff       	call   1130 <puts@plt>
    19e5:	90                   	nop
    19e6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19ea:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    19f1:	00 00 
    19f3:	74 05                	je     19fa <phase_defused+0xcc>
    19f5:	e8 56 f7 ff ff       	call   1150 <__stack_chk_fail@plt>
    19fa:	c9                   	leave  
    19fb:	c3                   	ret    

00000000000019fc <phase_1>:
    19fc:	f3 0f 1e fa          	endbr64 
    1a00:	55                   	push   %rbp
    1a01:	48 89 e5             	mov    %rsp,%rbp
    1a04:	48 83 ec 10          	sub    $0x10,%rsp
    1a08:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1a0c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a10:	48 8d 35 01 19 00 00 	lea    0x1901(%rip),%rsi        # 3318 <_IO_stdin_used+0x318>
    1a17:	48 89 c7             	mov    %rax,%rdi
    1a1a:	e8 e0 fb ff ff       	call   15ff <strings_not_equal>
    1a1f:	85 c0                	test   %eax,%eax
    1a21:	74 05                	je     1a28 <phase_1+0x2c>
    1a23:	e8 d6 fe ff ff       	call   18fe <explode_bomb>
    1a28:	90                   	nop
    1a29:	c9                   	leave  
    1a2a:	c3                   	ret    

0000000000001a2b <phase_2>:
    1a2b:	f3 0f 1e fa          	endbr64 
    1a2f:	55                   	push   %rbp
    1a30:	48 89 e5             	mov    %rsp,%rbp
    1a33:	48 83 ec 40          	sub    $0x40,%rsp
    1a37:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    1a3b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1a42:	00 00 
    1a44:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1a48:	31 c0                	xor    %eax,%eax
    1a4a:	48 8d 55 e0          	lea    -0x20(%rbp),%rdx
    1a4e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1a52:	48 89 d6             	mov    %rdx,%rsi
    1a55:	48 89 c7             	mov    %rax,%rdi
    1a58:	e8 fd fa ff ff       	call   155a <read_six_numbers>
    1a5d:	8b 45 e0             	mov    -0x20(%rbp),%eax
    1a60:	85 c0                	test   %eax,%eax
    1a62:	79 05                	jns    1a69 <phase_2+0x3e>
    1a64:	e8 95 fe ff ff       	call   18fe <explode_bomb>
    1a69:	c7 45 dc 01 00 00 00 	movl   $0x1,-0x24(%rbp)
    1a70:	eb 27                	jmp    1a99 <phase_2+0x6e>
    1a72:	8b 45 dc             	mov    -0x24(%rbp),%eax
    1a75:	48 98                	cltq   
    1a77:	8b 54 85 e0          	mov    -0x20(%rbp,%rax,4),%edx
    1a7b:	8b 45 dc             	mov    -0x24(%rbp),%eax
    1a7e:	83 e8 01             	sub    $0x1,%eax
    1a81:	48 98                	cltq   
    1a83:	8b 4c 85 e0          	mov    -0x20(%rbp,%rax,4),%ecx
    1a87:	8b 45 dc             	mov    -0x24(%rbp),%eax
    1a8a:	01 c8                	add    %ecx,%eax
    1a8c:	39 c2                	cmp    %eax,%edx
    1a8e:	74 05                	je     1a95 <phase_2+0x6a>
    1a90:	e8 69 fe ff ff       	call   18fe <explode_bomb>
    1a95:	83 45 dc 01          	addl   $0x1,-0x24(%rbp)
    1a99:	83 7d dc 05          	cmpl   $0x5,-0x24(%rbp)
    1a9d:	7e d3                	jle    1a72 <phase_2+0x47>
    1a9f:	90                   	nop
    1aa0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1aa4:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1aab:	00 00 
    1aad:	74 05                	je     1ab4 <phase_2+0x89>
    1aaf:	e8 9c f6 ff ff       	call   1150 <__stack_chk_fail@plt>
    1ab4:	c9                   	leave  
    1ab5:	c3                   	ret    

0000000000001ab6 <phase_3>:
    1ab6:	f3 0f 1e fa          	endbr64 
    1aba:	55                   	push   %rbp
    1abb:	48 89 e5             	mov    %rsp,%rbp
    1abe:	48 83 ec 30          	sub    $0x30,%rsp
    1ac2:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1ac6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1acd:	00 00 
    1acf:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1ad3:	31 c0                	xor    %eax,%eax
    1ad5:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
    1adc:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1ae3:	48 8d 4d ec          	lea    -0x14(%rbp),%rcx
    1ae7:	48 8d 55 e8          	lea    -0x18(%rbp),%rdx
    1aeb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1aef:	48 8d 35 46 18 00 00 	lea    0x1846(%rip),%rsi        # 333c <_IO_stdin_used+0x33c>
    1af6:	48 89 c7             	mov    %rax,%rdi
    1af9:	b8 00 00 00 00       	mov    $0x0,%eax
    1afe:	e8 9d f6 ff ff       	call   11a0 <__isoc99_sscanf@plt>
    1b03:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1b06:	83 7d f4 01          	cmpl   $0x1,-0xc(%rbp)
    1b0a:	7f 05                	jg     1b11 <phase_3+0x5b>
    1b0c:	e8 ed fd ff ff       	call   18fe <explode_bomb>
    1b11:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1b14:	83 f8 07             	cmp    $0x7,%eax
    1b17:	77 6b                	ja     1b84 <phase_3+0xce>
    1b19:	89 c0                	mov    %eax,%eax
    1b1b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1b22:	00 
    1b23:	48 8d 05 1a 18 00 00 	lea    0x181a(%rip),%rax        # 3344 <_IO_stdin_used+0x344>
    1b2a:	8b 04 02             	mov    (%rdx,%rax,1),%eax
    1b2d:	48 98                	cltq   
    1b2f:	48 8d 15 0e 18 00 00 	lea    0x180e(%rip),%rdx        # 3344 <_IO_stdin_used+0x344>
    1b36:	48 01 d0             	add    %rdx,%rax
    1b39:	3e ff e0             	notrack jmp *%rax
    1b3c:	c7 45 f0 2f 03 00 00 	movl   $0x32f,-0x10(%rbp)
    1b43:	eb 44                	jmp    1b89 <phase_3+0xd3>
    1b45:	c7 45 f0 30 01 00 00 	movl   $0x130,-0x10(%rbp)
    1b4c:	eb 3b                	jmp    1b89 <phase_3+0xd3>
    1b4e:	c7 45 f0 84 01 00 00 	movl   $0x184,-0x10(%rbp)
    1b55:	eb 32                	jmp    1b89 <phase_3+0xd3>
    1b57:	c7 45 f0 8e 02 00 00 	movl   $0x28e,-0x10(%rbp)
    1b5e:	eb 29                	jmp    1b89 <phase_3+0xd3>
    1b60:	c7 45 f0 1c 01 00 00 	movl   $0x11c,-0x10(%rbp)
    1b67:	eb 20                	jmp    1b89 <phase_3+0xd3>
    1b69:	c7 45 f0 01 02 00 00 	movl   $0x201,-0x10(%rbp)
    1b70:	eb 17                	jmp    1b89 <phase_3+0xd3>
    1b72:	c7 45 f0 a9 01 00 00 	movl   $0x1a9,-0x10(%rbp)
    1b79:	eb 0e                	jmp    1b89 <phase_3+0xd3>
    1b7b:	c7 45 f0 74 03 00 00 	movl   $0x374,-0x10(%rbp)
    1b82:	eb 05                	jmp    1b89 <phase_3+0xd3>
    1b84:	e8 75 fd ff ff       	call   18fe <explode_bomb>
    1b89:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1b8c:	39 45 f0             	cmp    %eax,-0x10(%rbp)
    1b8f:	74 05                	je     1b96 <phase_3+0xe0>
    1b91:	e8 68 fd ff ff       	call   18fe <explode_bomb>
    1b96:	90                   	nop
    1b97:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1b9b:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1ba2:	00 00 
    1ba4:	74 05                	je     1bab <phase_3+0xf5>
    1ba6:	e8 a5 f5 ff ff       	call   1150 <__stack_chk_fail@plt>
    1bab:	c9                   	leave  
    1bac:	c3                   	ret    

0000000000001bad <func4>:
    1bad:	f3 0f 1e fa          	endbr64 
    1bb1:	55                   	push   %rbp
    1bb2:	48 89 e5             	mov    %rsp,%rbp
    1bb5:	48 83 ec 20          	sub    $0x20,%rsp
    1bb9:	89 7d ec             	mov    %edi,-0x14(%rbp)
    1bbc:	89 75 e8             	mov    %esi,-0x18(%rbp)
    1bbf:	89 55 e4             	mov    %edx,-0x1c(%rbp)
    1bc2:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1bc5:	2b 45 e8             	sub    -0x18(%rbp),%eax
    1bc8:	89 c2                	mov    %eax,%edx
    1bca:	c1 ea 1f             	shr    $0x1f,%edx
    1bcd:	01 d0                	add    %edx,%eax
    1bcf:	d1 f8                	sar    %eax
    1bd1:	89 c2                	mov    %eax,%edx
    1bd3:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1bd6:	01 d0                	add    %edx,%eax
    1bd8:	89 45 fc             	mov    %eax,-0x4(%rbp)
    1bdb:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1bde:	3b 45 ec             	cmp    -0x14(%rbp),%eax
    1be1:	7e 19                	jle    1bfc <func4+0x4f>
    1be3:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1be6:	8d 50 ff             	lea    -0x1(%rax),%edx
    1be9:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    1bec:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1bef:	89 ce                	mov    %ecx,%esi
    1bf1:	89 c7                	mov    %eax,%edi
    1bf3:	e8 b5 ff ff ff       	call   1bad <func4>
    1bf8:	01 c0                	add    %eax,%eax
    1bfa:	eb 29                	jmp    1c25 <func4+0x78>
    1bfc:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1bff:	3b 45 ec             	cmp    -0x14(%rbp),%eax
    1c02:	7d 1c                	jge    1c20 <func4+0x73>
    1c04:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1c07:	8d 48 01             	lea    0x1(%rax),%ecx
    1c0a:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    1c0d:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1c10:	89 ce                	mov    %ecx,%esi
    1c12:	89 c7                	mov    %eax,%edi
    1c14:	e8 94 ff ff ff       	call   1bad <func4>
    1c19:	01 c0                	add    %eax,%eax
    1c1b:	83 c0 01             	add    $0x1,%eax
    1c1e:	eb 05                	jmp    1c25 <func4+0x78>
    1c20:	b8 00 00 00 00       	mov    $0x0,%eax
    1c25:	c9                   	leave  
    1c26:	c3                   	ret    

0000000000001c27 <phase_4>:
    1c27:	f3 0f 1e fa          	endbr64 
    1c2b:	55                   	push   %rbp
    1c2c:	48 89 e5             	mov    %rsp,%rbp
    1c2f:	48 83 ec 30          	sub    $0x30,%rsp
    1c33:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1c37:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1c3e:	00 00 
    1c40:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1c44:	31 c0                	xor    %eax,%eax
    1c46:	48 8d 4d e8          	lea    -0x18(%rbp),%rcx
    1c4a:	48 8d 55 e4          	lea    -0x1c(%rbp),%rdx
    1c4e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1c52:	48 8d 35 e3 16 00 00 	lea    0x16e3(%rip),%rsi        # 333c <_IO_stdin_used+0x33c>
    1c59:	48 89 c7             	mov    %rax,%rdi
    1c5c:	b8 00 00 00 00       	mov    $0x0,%eax
    1c61:	e8 3a f5 ff ff       	call   11a0 <__isoc99_sscanf@plt>
    1c66:	89 45 ec             	mov    %eax,-0x14(%rbp)
    1c69:	83 7d ec 02          	cmpl   $0x2,-0x14(%rbp)
    1c6d:	75 0f                	jne    1c7e <phase_4+0x57>
    1c6f:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1c72:	85 c0                	test   %eax,%eax
    1c74:	78 08                	js     1c7e <phase_4+0x57>
    1c76:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1c79:	83 f8 0e             	cmp    $0xe,%eax
    1c7c:	7e 05                	jle    1c83 <phase_4+0x5c>
    1c7e:	e8 7b fc ff ff       	call   18fe <explode_bomb>
    1c83:	c7 45 f0 07 00 00 00 	movl   $0x7,-0x10(%rbp)
    1c8a:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1c8d:	ba 0e 00 00 00       	mov    $0xe,%edx
    1c92:	be 00 00 00 00       	mov    $0x0,%esi
    1c97:	89 c7                	mov    %eax,%edi
    1c99:	e8 0f ff ff ff       	call   1bad <func4>
    1c9e:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1ca1:	8b 45 f4             	mov    -0xc(%rbp),%eax
    1ca4:	3b 45 f0             	cmp    -0x10(%rbp),%eax
    1ca7:	75 08                	jne    1cb1 <phase_4+0x8a>
    1ca9:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1cac:	39 45 f0             	cmp    %eax,-0x10(%rbp)
    1caf:	74 05                	je     1cb6 <phase_4+0x8f>
    1cb1:	e8 48 fc ff ff       	call   18fe <explode_bomb>
    1cb6:	90                   	nop
    1cb7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1cbb:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1cc2:	00 00 
    1cc4:	74 05                	je     1ccb <phase_4+0xa4>
    1cc6:	e8 85 f4 ff ff       	call   1150 <__stack_chk_fail@plt>
    1ccb:	c9                   	leave  
    1ccc:	c3                   	ret    

0000000000001ccd <phase_5>:
    1ccd:	f3 0f 1e fa          	endbr64 
    1cd1:	55                   	push   %rbp
    1cd2:	48 89 e5             	mov    %rsp,%rbp
    1cd5:	48 83 ec 30          	sub    $0x30,%rsp
    1cd9:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1cdd:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1ce4:	00 00 
    1ce6:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1cea:	31 c0                	xor    %eax,%eax
    1cec:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1cf0:	48 89 c7             	mov    %rax,%rdi
    1cf3:	e8 d1 f8 ff ff       	call   15c9 <string_length>
    1cf8:	89 45 ec             	mov    %eax,-0x14(%rbp)
    1cfb:	83 7d ec 06          	cmpl   $0x6,-0x14(%rbp)
    1cff:	74 05                	je     1d06 <phase_5+0x39>
    1d01:	e8 f8 fb ff ff       	call   18fe <explode_bomb>
    1d06:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    1d0d:	eb 30                	jmp    1d3f <phase_5+0x72>
    1d0f:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1d12:	48 63 d0             	movslq %eax,%rdx
    1d15:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1d19:	48 01 d0             	add    %rdx,%rax
    1d1c:	0f b6 00             	movzbl (%rax),%eax
    1d1f:	0f be c0             	movsbl %al,%eax
    1d22:	83 e0 0f             	and    $0xf,%eax
    1d25:	48 98                	cltq   
    1d27:	48 8d 15 12 38 00 00 	lea    0x3812(%rip),%rdx        # 5540 <array.3096>
    1d2e:	0f b6 14 10          	movzbl (%rax,%rdx,1),%edx
    1d32:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1d35:	48 98                	cltq   
    1d37:	88 54 05 f1          	mov    %dl,-0xf(%rbp,%rax,1)
    1d3b:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    1d3f:	83 7d e8 05          	cmpl   $0x5,-0x18(%rbp)
    1d43:	7e ca                	jle    1d0f <phase_5+0x42>
    1d45:	c6 45 f7 00          	movb   $0x0,-0x9(%rbp)
    1d49:	48 8d 45 f1          	lea    -0xf(%rbp),%rax
    1d4d:	48 8d 35 10 16 00 00 	lea    0x1610(%rip),%rsi        # 3364 <_IO_stdin_used+0x364>
    1d54:	48 89 c7             	mov    %rax,%rdi
    1d57:	e8 a3 f8 ff ff       	call   15ff <strings_not_equal>
    1d5c:	85 c0                	test   %eax,%eax
    1d5e:	74 05                	je     1d65 <phase_5+0x98>
    1d60:	e8 99 fb ff ff       	call   18fe <explode_bomb>
    1d65:	90                   	nop
    1d66:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1d6a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1d71:	00 00 
    1d73:	74 05                	je     1d7a <phase_5+0xad>
    1d75:	e8 d6 f3 ff ff       	call   1150 <__stack_chk_fail@plt>
    1d7a:	c9                   	leave  
    1d7b:	c3                   	ret    

0000000000001d7c <phase_6>:
    1d7c:	f3 0f 1e fa          	endbr64 
    1d80:	55                   	push   %rbp
    1d81:	48 89 e5             	mov    %rsp,%rbp
    1d84:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
    1d8b:	48 89 bd 78 ff ff ff 	mov    %rdi,-0x88(%rbp)
    1d92:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1d99:	00 00 
    1d9b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1d9f:	31 c0                	xor    %eax,%eax
    1da1:	48 8d 05 e8 37 00 00 	lea    0x37e8(%rip),%rax        # 5590 <node1>
    1da8:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    1dac:	48 8d 55 a0          	lea    -0x60(%rbp),%rdx
    1db0:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    1db7:	48 89 d6             	mov    %rdx,%rsi
    1dba:	48 89 c7             	mov    %rax,%rdi
    1dbd:	e8 98 f7 ff ff       	call   155a <read_six_numbers>
    1dc2:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    1dc9:	eb 54                	jmp    1e1f <phase_6+0xa3>
    1dcb:	8b 45 88             	mov    -0x78(%rbp),%eax
    1dce:	48 98                	cltq   
    1dd0:	8b 44 85 a0          	mov    -0x60(%rbp,%rax,4),%eax
    1dd4:	85 c0                	test   %eax,%eax
    1dd6:	7e 0e                	jle    1de6 <phase_6+0x6a>
    1dd8:	8b 45 88             	mov    -0x78(%rbp),%eax
    1ddb:	48 98                	cltq   
    1ddd:	8b 44 85 a0          	mov    -0x60(%rbp,%rax,4),%eax
    1de1:	83 f8 06             	cmp    $0x6,%eax
    1de4:	7e 05                	jle    1deb <phase_6+0x6f>
    1de6:	e8 13 fb ff ff       	call   18fe <explode_bomb>
    1deb:	8b 45 88             	mov    -0x78(%rbp),%eax
    1dee:	83 c0 01             	add    $0x1,%eax
    1df1:	89 45 8c             	mov    %eax,-0x74(%rbp)
    1df4:	eb 1f                	jmp    1e15 <phase_6+0x99>
    1df6:	8b 45 88             	mov    -0x78(%rbp),%eax
    1df9:	48 98                	cltq   
    1dfb:	8b 54 85 a0          	mov    -0x60(%rbp,%rax,4),%edx
    1dff:	8b 45 8c             	mov    -0x74(%rbp),%eax
    1e02:	48 98                	cltq   
    1e04:	8b 44 85 a0          	mov    -0x60(%rbp,%rax,4),%eax
    1e08:	39 c2                	cmp    %eax,%edx
    1e0a:	75 05                	jne    1e11 <phase_6+0x95>
    1e0c:	e8 ed fa ff ff       	call   18fe <explode_bomb>
    1e11:	83 45 8c 01          	addl   $0x1,-0x74(%rbp)
    1e15:	83 7d 8c 05          	cmpl   $0x5,-0x74(%rbp)
    1e19:	7e db                	jle    1df6 <phase_6+0x7a>
    1e1b:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    1e1f:	83 7d 88 05          	cmpl   $0x5,-0x78(%rbp)
    1e23:	7e a6                	jle    1dcb <phase_6+0x4f>
    1e25:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    1e2c:	eb 41                	jmp    1e6f <phase_6+0xf3>
    1e2e:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    1e32:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1e36:	c7 45 8c 01 00 00 00 	movl   $0x1,-0x74(%rbp)
    1e3d:	eb 10                	jmp    1e4f <phase_6+0xd3>
    1e3f:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1e43:	48 8b 40 08          	mov    0x8(%rax),%rax
    1e47:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1e4b:	83 45 8c 01          	addl   $0x1,-0x74(%rbp)
    1e4f:	8b 45 88             	mov    -0x78(%rbp),%eax
    1e52:	48 98                	cltq   
    1e54:	8b 44 85 a0          	mov    -0x60(%rbp,%rax,4),%eax
    1e58:	39 45 8c             	cmp    %eax,-0x74(%rbp)
    1e5b:	7c e2                	jl     1e3f <phase_6+0xc3>
    1e5d:	8b 45 88             	mov    -0x78(%rbp),%eax
    1e60:	48 98                	cltq   
    1e62:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    1e66:	48 89 54 c5 c0       	mov    %rdx,-0x40(%rbp,%rax,8)
    1e6b:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    1e6f:	83 7d 88 05          	cmpl   $0x5,-0x78(%rbp)
    1e73:	7e b9                	jle    1e2e <phase_6+0xb2>
    1e75:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    1e79:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    1e7d:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    1e81:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1e85:	c7 45 88 01 00 00 00 	movl   $0x1,-0x78(%rbp)
    1e8c:	eb 22                	jmp    1eb0 <phase_6+0x134>
    1e8e:	8b 45 88             	mov    -0x78(%rbp),%eax
    1e91:	48 98                	cltq   
    1e93:	48 8b 54 c5 c0       	mov    -0x40(%rbp,%rax,8),%rdx
    1e98:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1e9c:	48 89 50 08          	mov    %rdx,0x8(%rax)
    1ea0:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1ea4:	48 8b 40 08          	mov    0x8(%rax),%rax
    1ea8:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1eac:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    1eb0:	83 7d 88 05          	cmpl   $0x5,-0x78(%rbp)
    1eb4:	7e d8                	jle    1e8e <phase_6+0x112>
    1eb6:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1eba:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    1ec1:	00 
    1ec2:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    1ec6:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1eca:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    1ed1:	eb 29                	jmp    1efc <phase_6+0x180>
    1ed3:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1ed7:	8b 10                	mov    (%rax),%edx
    1ed9:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1edd:	48 8b 40 08          	mov    0x8(%rax),%rax
    1ee1:	8b 00                	mov    (%rax),%eax
    1ee3:	39 c2                	cmp    %eax,%edx
    1ee5:	7d 05                	jge    1eec <phase_6+0x170>
    1ee7:	e8 12 fa ff ff       	call   18fe <explode_bomb>
    1eec:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1ef0:	48 8b 40 08          	mov    0x8(%rax),%rax
    1ef4:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1ef8:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    1efc:	83 7d 88 04          	cmpl   $0x4,-0x78(%rbp)
    1f00:	7e d1                	jle    1ed3 <phase_6+0x157>
    1f02:	90                   	nop
    1f03:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f07:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1f0e:	00 00 
    1f10:	74 05                	je     1f17 <phase_6+0x19b>
    1f12:	e8 39 f2 ff ff       	call   1150 <__stack_chk_fail@plt>
    1f17:	c9                   	leave  
    1f18:	c3                   	ret    

0000000000001f19 <fun7>:
    1f19:	f3 0f 1e fa          	endbr64 
    1f1d:	55                   	push   %rbp
    1f1e:	48 89 e5             	mov    %rsp,%rbp
    1f21:	48 83 ec 10          	sub    $0x10,%rsp
    1f25:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1f29:	89 75 f4             	mov    %esi,-0xc(%rbp)
    1f2c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1f31:	75 07                	jne    1f3a <fun7+0x21>
    1f33:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1f38:	eb 50                	jmp    1f8a <fun7+0x71>
    1f3a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f3e:	8b 00                	mov    (%rax),%eax
    1f40:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    1f43:	7d 19                	jge    1f5e <fun7+0x45>
    1f45:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f49:	48 8b 40 08          	mov    0x8(%rax),%rax
    1f4d:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1f50:	89 d6                	mov    %edx,%esi
    1f52:	48 89 c7             	mov    %rax,%rdi
    1f55:	e8 bf ff ff ff       	call   1f19 <fun7>
    1f5a:	01 c0                	add    %eax,%eax
    1f5c:	eb 2c                	jmp    1f8a <fun7+0x71>
    1f5e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f62:	8b 00                	mov    (%rax),%eax
    1f64:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    1f67:	75 07                	jne    1f70 <fun7+0x57>
    1f69:	b8 00 00 00 00       	mov    $0x0,%eax
    1f6e:	eb 1a                	jmp    1f8a <fun7+0x71>
    1f70:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f74:	48 8b 40 10          	mov    0x10(%rax),%rax
    1f78:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1f7b:	89 d6                	mov    %edx,%esi
    1f7d:	48 89 c7             	mov    %rax,%rdi
    1f80:	e8 94 ff ff ff       	call   1f19 <fun7>
    1f85:	01 c0                	add    %eax,%eax
    1f87:	83 c0 01             	add    $0x1,%eax
    1f8a:	c9                   	leave  
    1f8b:	c3                   	ret    

0000000000001f8c <secret_phase>:
    1f8c:	f3 0f 1e fa          	endbr64 
    1f90:	55                   	push   %rbp
    1f91:	48 89 e5             	mov    %rsp,%rbp
    1f94:	48 83 ec 10          	sub    $0x10,%rsp
    1f98:	e8 ce f7 ff ff       	call   176b <read_line>
    1f9d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1fa1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1fa5:	48 89 c7             	mov    %rax,%rdi
    1fa8:	e8 13 f2 ff ff       	call   11c0 <atoi@plt>
    1fad:	89 45 f0             	mov    %eax,-0x10(%rbp)
    1fb0:	83 7d f0 00          	cmpl   $0x0,-0x10(%rbp)
    1fb4:	7e 09                	jle    1fbf <secret_phase+0x33>
    1fb6:	81 7d f0 e9 03 00 00 	cmpl   $0x3e9,-0x10(%rbp)
    1fbd:	7e 05                	jle    1fc4 <secret_phase+0x38>
    1fbf:	e8 3a f9 ff ff       	call   18fe <explode_bomb>
    1fc4:	8b 45 f0             	mov    -0x10(%rbp),%eax
    1fc7:	89 c6                	mov    %eax,%esi
    1fc9:	48 8d 3d 90 36 00 00 	lea    0x3690(%rip),%rdi        # 5660 <n1>
    1fd0:	e8 44 ff ff ff       	call   1f19 <fun7>
    1fd5:	89 45 f4             	mov    %eax,-0xc(%rbp)
    1fd8:	83 7d f4 01          	cmpl   $0x1,-0xc(%rbp)
    1fdc:	74 05                	je     1fe3 <secret_phase+0x57>
    1fde:	e8 1b f9 ff ff       	call   18fe <explode_bomb>
    1fe3:	48 8d 3d 86 13 00 00 	lea    0x1386(%rip),%rdi        # 3370 <_IO_stdin_used+0x370>
    1fea:	e8 41 f1 ff ff       	call   1130 <puts@plt>
    1fef:	e8 3a f9 ff ff       	call   192e <phase_defused>
    1ff4:	90                   	nop
    1ff5:	c9                   	leave  
    1ff6:	c3                   	ret    

Disassembly of section .fini:

0000000000001ff8 <_fini>:
    1ff8:	f3 0f 1e fa          	endbr64 
    1ffc:	48 83 ec 08          	sub    $0x8,%rsp
    2000:	48 83 c4 08          	add    $0x8,%rsp
    2004:	c3                   	ret    

Disassembly of section .rodata:

0000000000003000 <_IO_stdin_used>:
    3000:	01 00                	add    %eax,(%rax)
    3002:	02 00                	add    (%rax),%al
    3004:	00 00                	add    %al,(%rax)
    3006:	00 00                	add    %al,(%rax)
    3008:	72 00                	jb     300a <_IO_stdin_used+0xa>
    300a:	25 73 3a 20 45       	and    $0x45203a73,%eax
    300f:	72 72                	jb     3083 <_IO_stdin_used+0x83>
    3011:	6f                   	outsl  %ds:(%rsi),(%dx)
    3012:	72 3a                	jb     304e <_IO_stdin_used+0x4e>
    3014:	20 43 6f             	and    %al,0x6f(%rbx)
    3017:	75 6c                	jne    3085 <_IO_stdin_used+0x85>
    3019:	64 6e                	outsb  %fs:(%rsi),(%dx)
    301b:	27                   	(bad)  
    301c:	74 20                	je     303e <_IO_stdin_used+0x3e>
    301e:	6f                   	outsl  %ds:(%rsi),(%dx)
    301f:	70 65                	jo     3086 <_IO_stdin_used+0x86>
    3021:	6e                   	outsb  %ds:(%rsi),(%dx)
    3022:	20 25 73 0a 00 55    	and    %ah,0x55000a73(%rip)        # 55003a9b <_end+0x54ffdd2b>
    3028:	73 61                	jae    308b <_IO_stdin_used+0x8b>
    302a:	67 65 3a 20          	cmp    %gs:(%eax),%ah
    302e:	25 73 20 5b 3c       	and    $0x3c5b2073,%eax
    3033:	69 6e 70 75 74 5f 66 	imul   $0x665f7475,0x70(%rsi),%ebp
    303a:	69 6c 65 3e 5d 0a 00 	imul   $0xa5d,0x3e(%rbp,%riz,2),%ebp
    3041:	00 
    3042:	00 00                	add    %al,(%rax)
    3044:	00 00                	add    %al,(%rax)
    3046:	00 00                	add    %al,(%rax)
    3048:	57                   	push   %rdi
    3049:	65 6c                	gs insb (%dx),%es:(%rdi)
    304b:	63 6f 6d             	movsxd 0x6d(%rdi),%ebp
    304e:	65 20 74 6f 20       	and    %dh,%gs:0x20(%rdi,%rbp,2)
    3053:	6d                   	insl   (%dx),%es:(%rdi)
    3054:	79 20                	jns    3076 <_IO_stdin_used+0x76>
    3056:	66 69 65 6e 64 69    	imul   $0x6964,0x6e(%rbp),%sp
    305c:	73 68                	jae    30c6 <_IO_stdin_used+0xc6>
    305e:	20 6c 69 74          	and    %ch,0x74(%rcx,%rbp,2)
    3062:	74 6c                	je     30d0 <_IO_stdin_used+0xd0>
    3064:	65 20 62 6f          	and    %ah,%gs:0x6f(%rdx)
    3068:	6d                   	insl   (%dx),%es:(%rdi)
    3069:	62                   	(bad)  
    306a:	2e 20 59 6f          	cs and %bl,0x6f(%rcx)
    306e:	75 20                	jne    3090 <_IO_stdin_used+0x90>
    3070:	68 61 76 65 20       	push   $0x20657661
    3075:	36 20 70 68          	ss and %dh,0x68(%rax)
    3079:	61                   	(bad)  
    307a:	73 65                	jae    30e1 <_IO_stdin_used+0xe1>
    307c:	73 20                	jae    309e <_IO_stdin_used+0x9e>
    307e:	77 69                	ja     30e9 <_IO_stdin_used+0xe9>
    3080:	74 68                	je     30ea <_IO_stdin_used+0xea>
    3082:	00 00                	add    %al,(%rax)
    3084:	00 00                	add    %al,(%rax)
    3086:	00 00                	add    %al,(%rax)
    3088:	77 68                	ja     30f2 <_IO_stdin_used+0xf2>
    308a:	69 63 68 20 74 6f 20 	imul   $0x206f7420,0x68(%rbx),%esp
    3091:	62                   	(bad)  
    3092:	6c                   	insb   (%dx),%es:(%rdi)
    3093:	6f                   	outsl  %ds:(%rsi),(%dx)
    3094:	77 20                	ja     30b6 <_IO_stdin_used+0xb6>
    3096:	79 6f                	jns    3107 <_IO_stdin_used+0x107>
    3098:	75 72                	jne    310c <_IO_stdin_used+0x10c>
    309a:	73 65                	jae    3101 <_IO_stdin_used+0x101>
    309c:	6c                   	insb   (%dx),%es:(%rdi)
    309d:	66 20 75 70          	data16 and %dh,0x70(%rbp)
    30a1:	2e 20 48 61          	cs and %cl,0x61(%rax)
    30a5:	76 65                	jbe    310c <_IO_stdin_used+0x10c>
    30a7:	20 61 20             	and    %ah,0x20(%rcx)
    30aa:	6e                   	outsb  %ds:(%rsi),(%dx)
    30ab:	69 63 65 20 64 61 79 	imul   $0x79616420,0x65(%rbx),%esp
    30b2:	21 00                	and    %eax,(%rax)
    30b4:	00 00                	add    %al,(%rax)
    30b6:	00 00                	add    %al,(%rax)
    30b8:	50                   	push   %rax
    30b9:	68 61 73 65 20       	push   $0x20657361
    30be:	31 20                	xor    %esp,(%rax)
    30c0:	64 65 66 75 73       	fs gs data16 jne 3138 <_IO_stdin_used+0x138>
    30c5:	65 64 2e 20 48 6f    	gs fs and %cl,%fs:0x6f(%rax)
    30cb:	77 20                	ja     30ed <_IO_stdin_used+0xed>
    30cd:	61                   	(bad)  
    30ce:	62                   	(bad)  
    30cf:	6f                   	outsl  %ds:(%rsi),(%dx)
    30d0:	75 74                	jne    3146 <_IO_stdin_used+0x146>
    30d2:	20 74 68 65          	and    %dh,0x65(%rax,%rbp,2)
    30d6:	20 6e 65             	and    %ch,0x65(%rsi)
    30d9:	78 74                	js     314f <_IO_stdin_used+0x14f>
    30db:	20 6f 6e             	and    %ch,0x6e(%rdi)
    30de:	65 3f                	gs (bad) 
    30e0:	00 54 68 61          	add    %dl,0x61(%rax,%rbp,2)
    30e4:	74 27                	je     310d <_IO_stdin_used+0x10d>
    30e6:	73 20                	jae    3108 <_IO_stdin_used+0x108>
    30e8:	6e                   	outsb  %ds:(%rsi),(%dx)
    30e9:	75 6d                	jne    3158 <_IO_stdin_used+0x158>
    30eb:	62 65                	(bad)  
    30ed:	72 20                	jb     310f <_IO_stdin_used+0x10f>
    30ef:	32 2e                	xor    (%rsi),%ch
    30f1:	20 20                	and    %ah,(%rax)
    30f3:	4b                   	rex.WXB
    30f4:	65 65 70 20          	gs gs jo 3118 <_IO_stdin_used+0x118>
    30f8:	67 6f                	outsl  %ds:(%esi),(%dx)
    30fa:	69 6e 67 21 00 48 61 	imul   $0x61480021,0x67(%rsi),%ebp
    3101:	6c                   	insb   (%dx),%es:(%rdi)
    3102:	66 77 61             	data16 ja 3166 <_IO_stdin_used+0x166>
    3105:	79 20                	jns    3127 <_IO_stdin_used+0x127>
    3107:	74 68                	je     3171 <_IO_stdin_used+0x171>
    3109:	65 72 65             	gs jb  3171 <_IO_stdin_used+0x171>
    310c:	21 00                	and    %eax,(%rax)
    310e:	00 00                	add    %al,(%rax)
    3110:	53                   	push   %rbx
    3111:	6f                   	outsl  %ds:(%rsi),(%dx)
    3112:	20 79 6f             	and    %bh,0x6f(%rcx)
    3115:	75 20                	jne    3137 <_IO_stdin_used+0x137>
    3117:	67 6f                	outsl  %ds:(%esi),(%dx)
    3119:	74 20                	je     313b <_IO_stdin_used+0x13b>
    311b:	74 68                	je     3185 <_IO_stdin_used+0x185>
    311d:	61                   	(bad)  
    311e:	74 20                	je     3140 <_IO_stdin_used+0x140>
    3120:	6f                   	outsl  %ds:(%rsi),(%dx)
    3121:	6e                   	outsb  %ds:(%rsi),(%dx)
    3122:	65 2e 20 20          	gs and %ah,%gs:(%rax)
    3126:	54                   	push   %rsp
    3127:	72 79                	jb     31a2 <_IO_stdin_used+0x1a2>
    3129:	20 74 68 69          	and    %dh,0x69(%rax,%rbp,2)
    312d:	73 20                	jae    314f <_IO_stdin_used+0x14f>
    312f:	6f                   	outsl  %ds:(%rsi),(%dx)
    3130:	6e                   	outsb  %ds:(%rsi),(%dx)
    3131:	65 2e 00 47 6f       	gs add %al,%gs:0x6f(%rdi)
    3136:	6f                   	outsl  %ds:(%rsi),(%dx)
    3137:	64 20 77 6f          	and    %dh,%fs:0x6f(%rdi)
    313b:	72 6b                	jb     31a8 <_IO_stdin_used+0x1a8>
    313d:	21 20                	and    %esp,(%rax)
    313f:	20 4f 6e             	and    %cl,0x6e(%rdi)
    3142:	20 74 6f 20          	and    %dh,0x20(%rdi,%rbp,2)
    3146:	74 68                	je     31b0 <_IO_stdin_used+0x1b0>
    3148:	65 20 6e 65          	and    %ch,%gs:0x65(%rsi)
    314c:	78 74                	js     31c2 <_IO_stdin_used+0x1c2>
    314e:	2e 2e 2e 00 00       	cs cs cs add %al,(%rax)
    3153:	00 00                	add    %al,(%rax)
    3155:	00 00                	add    %al,(%rax)
    3157:	00 67 72             	add    %ah,0x72(%rdi)
    315a:	65 61                	gs (bad) 
    315c:	74 77                	je     31d5 <_IO_stdin_used+0x1d5>
    315e:	68 69 74 65 2e       	push   $0x2e657469
    3163:	69 63 73 2e 63 73 2e 	imul   $0x2e73632e,0x73(%rbx),%esp
    316a:	63 6d 75             	movsxd 0x75(%rbp),%ebp
    316d:	2e 65 64 75 00       	cs gs jne,pn 3172 <_IO_stdin_used+0x172>
    3172:	61                   	(bad)  
    3173:	6e                   	outsb  %ds:(%rsi),(%dx)
    3174:	67 65 6c             	gs insb (%dx),%es:(%edi)
    3177:	73 68                	jae    31e1 <_IO_stdin_used+0x1e1>
    3179:	61                   	(bad)  
    317a:	72 6b                	jb     31e7 <_IO_stdin_used+0x1e7>
    317c:	2e 69 63 73 2e 63 73 	cs imul $0x2e73632e,0x73(%rbx),%esp
    3183:	2e 
    3184:	63 6d 75             	movsxd 0x75(%rbp),%ebp
    3187:	2e 65 64 75 00       	cs gs jne,pn 318c <_IO_stdin_used+0x18c>
    318c:	6d                   	insl   (%dx),%es:(%rdi)
    318d:	61                   	(bad)  
    318e:	6b 6f 73 68          	imul   $0x68,0x73(%rdi),%ebp
    3192:	61                   	(bad)  
    3193:	72 6b                	jb     3200 <_IO_stdin_used+0x200>
    3195:	2e 69 63 73 2e 63 73 	cs imul $0x2e73632e,0x73(%rbx),%esp
    319c:	2e 
    319d:	63 6d 75             	movsxd 0x75(%rbp),%ebp
    31a0:	2e 65 64 75 00       	cs gs jne,pn 31a5 <_IO_stdin_used+0x1a5>
    31a5:	00 00                	add    %al,(%rax)
    31a7:	00 53 6f             	add    %dl,0x6f(%rbx)
    31aa:	20 79 6f             	and    %bh,0x6f(%rcx)
    31ad:	75 20                	jne    31cf <_IO_stdin_used+0x1cf>
    31af:	74 68                	je     3219 <_IO_stdin_used+0x219>
    31b1:	69 6e 6b 20 79 6f 75 	imul   $0x756f7920,0x6b(%rsi),%ebp
    31b8:	20 63 61             	and    %ah,0x61(%rbx)
    31bb:	6e                   	outsb  %ds:(%rsi),(%dx)
    31bc:	20 73 74             	and    %dh,0x74(%rbx)
    31bf:	6f                   	outsl  %ds:(%rsi),(%dx)
    31c0:	70 20                	jo     31e2 <_IO_stdin_used+0x1e2>
    31c2:	74 68                	je     322c <_IO_stdin_used+0x22c>
    31c4:	65 20 62 6f          	and    %ah,%gs:0x6f(%rdx)
    31c8:	6d                   	insl   (%dx),%es:(%rdi)
    31c9:	62                   	(bad)  
    31ca:	20 77 69             	and    %dh,0x69(%rdi)
    31cd:	74 68                	je     3237 <_IO_stdin_used+0x237>
    31cf:	20 63 74             	and    %ah,0x74(%rbx)
    31d2:	72 6c                	jb     3240 <_IO_stdin_used+0x240>
    31d4:	2d 63 2c 20 64       	sub    $0x64202c63,%eax
    31d9:	6f                   	outsl  %ds:(%rsi),(%dx)
    31da:	20 79 6f             	and    %bh,0x6f(%rcx)
    31dd:	75 3f                	jne    321e <_IO_stdin_used+0x21e>
    31df:	00 57 65             	add    %dl,0x65(%rdi)
    31e2:	6c                   	insb   (%dx),%es:(%rdi)
    31e3:	6c                   	insb   (%dx),%es:(%rdi)
    31e4:	2e 2e 2e 00 4f 4b    	cs cs cs add %cl,0x4b(%rdi)
    31ea:	2e 20 3a             	cs and %bh,(%rdx)
    31ed:	2d 29 00 49 6e       	sub    $0x6e490029,%eax
    31f2:	76 61                	jbe    3255 <_IO_stdin_used+0x255>
    31f4:	6c                   	insb   (%dx),%es:(%rdi)
    31f5:	69 64 20 70 68 61 73 	imul   $0x65736168,0x70(%rax,%riz,1),%esp
    31fc:	65 
    31fd:	25 73 0a 00 25       	and    $0x25000a73,%eax
    3202:	64 20 25 64 20 25 64 	and    %ah,%fs:0x64252064(%rip)        # 6425526d <_end+0x6424f4fd>
    3209:	20 25 64 20 25 64    	and    %ah,0x64252064(%rip)        # 64255273 <_end+0x6424f503>
    320f:	20 25 64 00 45 72    	and    %ah,0x72450064(%rip)        # 72453279 <_end+0x7244d509>
    3215:	72 6f                	jb     3286 <_IO_stdin_used+0x286>
    3217:	72 3a                	jb     3253 <_IO_stdin_used+0x253>
    3219:	20 50 72             	and    %dl,0x72(%rax)
    321c:	65 6d                	gs insl (%dx),%es:(%rdi)
    321e:	61                   	(bad)  
    321f:	74 75                	je     3296 <_IO_stdin_used+0x296>
    3221:	72 65                	jb     3288 <_IO_stdin_used+0x288>
    3223:	20 45 4f             	and    %al,0x4f(%rbp)
    3226:	46 20 6f 6e          	rex.RX and %r13b,0x6e(%rdi)
    322a:	20 73 74             	and    %dh,0x74(%rbx)
    322d:	64 69 6e 00 47 52 41 	imul   $0x44415247,%fs:0x0(%rsi),%ebp
    3234:	44 
    3235:	45 5f                	rex.RB pop %r15
    3237:	42                   	rex.X
    3238:	4f                   	rex.WRXB
    3239:	4d                   	rex.WRB
    323a:	42 00 45 72          	rex.X add %al,0x72(%rbp)
    323e:	72 6f                	jb     32af <_IO_stdin_used+0x2af>
    3240:	72 3a                	jb     327c <_IO_stdin_used+0x27c>
    3242:	20 49 6e             	and    %cl,0x6e(%rcx)
    3245:	70 75                	jo     32bc <_IO_stdin_used+0x2bc>
    3247:	74 20                	je     3269 <_IO_stdin_used+0x269>
    3249:	6c                   	insb   (%dx),%es:(%rdi)
    324a:	69 6e 65 20 74 6f 6f 	imul   $0x6f6f7420,0x65(%rsi),%ebp
    3251:	20 6c 6f 6e          	and    %ch,0x6e(%rdi,%rbp,2)
    3255:	67 00 0a             	add    %cl,(%edx)
    3258:	42                   	rex.X
    3259:	4f                   	rex.WRXB
    325a:	4f                   	rex.WRXB
    325b:	4d 21 21             	and    %r12,(%r9)
    325e:	21 00                	and    %eax,(%rax)
    3260:	54                   	push   %rsp
    3261:	68 65 20 62 6f       	push   $0x6f622065
    3266:	6d                   	insl   (%dx),%es:(%rdi)
    3267:	62                   	(bad)  
    3268:	20 68 61             	and    %ch,0x61(%rax)
    326b:	73 20                	jae    328d <_IO_stdin_used+0x28d>
    326d:	62                   	(bad)  
    326e:	6c                   	insb   (%dx),%es:(%rdi)
    326f:	6f                   	outsl  %ds:(%rsi),(%dx)
    3270:	77 6e                	ja     32e0 <_IO_stdin_used+0x2e0>
    3272:	20 75 70             	and    %dh,0x70(%rbp)
    3275:	2e 00 25 64 20 25 64 	cs add %ah,0x64252064(%rip)        # 642552e0 <_end+0x6424f570>
    327c:	20 25 73 00 44 72    	and    %ah,0x72440073(%rip)        # 724432f5 <_end+0x7243d585>
    3282:	45 76 69             	rex.RB jbe 32ee <_IO_stdin_used+0x2ee>
    3285:	6c                   	insb   (%dx),%es:(%rdi)
    3286:	00 00                	add    %al,(%rax)
    3288:	43 75 72             	rex.XB jne 32fd <_IO_stdin_used+0x2fd>
    328b:	73 65                	jae    32f2 <_IO_stdin_used+0x2f2>
    328d:	73 2c                	jae    32bb <_IO_stdin_used+0x2bb>
    328f:	20 79 6f             	and    %bh,0x6f(%rcx)
    3292:	75 27                	jne    32bb <_IO_stdin_used+0x2bb>
    3294:	76 65                	jbe    32fb <_IO_stdin_used+0x2fb>
    3296:	20 66 6f             	and    %ah,0x6f(%rsi)
    3299:	75 6e                	jne    3309 <_IO_stdin_used+0x309>
    329b:	64 20 74 68 65       	and    %dh,%fs:0x65(%rax,%rbp,2)
    32a0:	20 73 65             	and    %dh,0x65(%rbx)
    32a3:	63 72 65             	movsxd 0x65(%rdx),%esi
    32a6:	74 20                	je     32c8 <_IO_stdin_used+0x2c8>
    32a8:	70 68                	jo     3312 <_IO_stdin_used+0x312>
    32aa:	61                   	(bad)  
    32ab:	73 65                	jae    3312 <_IO_stdin_used+0x312>
    32ad:	21 00                	and    %eax,(%rax)
    32af:	00 42 75             	add    %al,0x75(%rdx)
    32b2:	74 20                	je     32d4 <_IO_stdin_used+0x2d4>
    32b4:	66 69 6e 64 69 6e    	imul   $0x6e69,0x64(%rsi),%bp
    32ba:	67 20 69 74          	and    %ch,0x74(%ecx)
    32be:	20 61 6e             	and    %ah,0x6e(%rcx)
    32c1:	64 20 73 6f          	and    %dh,%fs:0x6f(%rbx)
    32c5:	6c                   	insb   (%dx),%es:(%rdi)
    32c6:	76 69                	jbe    3331 <_IO_stdin_used+0x331>
    32c8:	6e                   	outsb  %ds:(%rsi),(%dx)
    32c9:	67 20 69 74          	and    %ch,0x74(%ecx)
    32cd:	20 61 72             	and    %ah,0x72(%rcx)
    32d0:	65 20 71 75          	and    %dh,%gs:0x75(%rcx)
    32d4:	69 74 65 20 64 69 66 	imul   $0x66666964,0x20(%rbp,%riz,2),%esi
    32db:	66 
    32dc:	65 72 65             	gs jb  3344 <_IO_stdin_used+0x344>
    32df:	6e                   	outsb  %ds:(%rsi),(%dx)
    32e0:	74 2e                	je     3310 <_IO_stdin_used+0x310>
    32e2:	2e 2e 00 00          	cs cs add %al,(%rax)
    32e6:	00 00                	add    %al,(%rax)
    32e8:	43 6f                	rex.XB outsl %ds:(%rsi),(%dx)
    32ea:	6e                   	outsb  %ds:(%rsi),(%dx)
    32eb:	67 72 61             	addr32 jb 334f <_IO_stdin_used+0x34f>
    32ee:	74 75                	je     3365 <_IO_stdin_used+0x365>
    32f0:	6c                   	insb   (%dx),%es:(%rdi)
    32f1:	61                   	(bad)  
    32f2:	74 69                	je     335d <_IO_stdin_used+0x35d>
    32f4:	6f                   	outsl  %ds:(%rsi),(%dx)
    32f5:	6e                   	outsb  %ds:(%rsi),(%dx)
    32f6:	73 21                	jae    3319 <_IO_stdin_used+0x319>
    32f8:	20 59 6f             	and    %bl,0x6f(%rcx)
    32fb:	75 27                	jne    3324 <_IO_stdin_used+0x324>
    32fd:	76 65                	jbe    3364 <_IO_stdin_used+0x364>
    32ff:	20 64 65 66          	and    %ah,0x66(%rbp,%riz,2)
    3303:	75 73                	jne    3378 <_IO_stdin_used+0x378>
    3305:	65 64 20 74 68 65    	gs and %dh,%fs:0x65(%rax,%rbp,2)
    330b:	20 62 6f             	and    %ah,0x6f(%rdx)
    330e:	6d                   	insl   (%dx),%es:(%rdi)
    330f:	62 21                	(bad)  
    3311:	00 00                	add    %al,(%rax)
    3313:	00 00                	add    %al,(%rax)
    3315:	00 00                	add    %al,(%rax)
    3317:	00 54 68 65          	add    %dl,0x65(%rax,%rbp,2)
    331b:	20 66 75             	and    %ah,0x75(%rsi)
    331e:	74 75                	je     3395 <_IO_stdin_used+0x395>
    3320:	72 65                	jb     3387 <_IO_stdin_used+0x387>
    3322:	20 77 69             	and    %dh,0x69(%rdi)
    3325:	6c                   	insb   (%dx),%es:(%rdi)
    3326:	6c                   	insb   (%dx),%es:(%rdi)
    3327:	20 62 65             	and    %ah,0x65(%rdx)
    332a:	20 62 65             	and    %ah,0x65(%rdx)
    332d:	74 74                	je     33a3 <__GNU_EH_FRAME_HDR+0xb>
    332f:	65 72 20             	gs jb  3352 <_IO_stdin_used+0x352>
    3332:	74 6f                	je     33a3 <__GNU_EH_FRAME_HDR+0xb>
    3334:	6d                   	insl   (%dx),%es:(%rdi)
    3335:	6f                   	outsl  %ds:(%rsi),(%dx)
    3336:	72 72                	jb     33aa <__GNU_EH_FRAME_HDR+0x12>
    3338:	6f                   	outsl  %ds:(%rsi),(%dx)
    3339:	77 2e                	ja     3369 <_IO_stdin_used+0x369>
    333b:	00 25 64 20 25 64    	add    %ah,0x64252064(%rip)        # 642553a5 <_end+0x6424f635>
    3341:	00 00                	add    %al,(%rax)
    3343:	00 f8                	add    %bh,%al
    3345:	e7 ff                	out    %eax,$0xff
    3347:	ff 01                	incl   (%rcx)
    3349:	e8 ff ff 0a e8       	call   ffffffffe80b334d <_end+0xffffffffe80ad5dd>
    334e:	ff                   	(bad)  
    334f:	ff 13                	call   *(%rbx)
    3351:	e8 ff ff 1c e8       	call   ffffffffe81d3355 <_end+0xffffffffe81cd5e5>
    3356:	ff                   	(bad)  
    3357:	ff 25 e8 ff ff 2e    	jmp    *0x2effffe8(%rip)        # 2f003345 <_end+0x2effd5d5>
    335d:	e8 ff ff 37 e8       	call   ffffffffe8383361 <_end+0xffffffffe837d5f1>
    3362:	ff                   	(bad)  
    3363:	ff 62 72             	jmp    *0x72(%rdx)
    3366:	75 69                	jne    33d1 <__GNU_EH_FRAME_HDR+0x39>
    3368:	6e                   	outsb  %ds:(%rsi),(%dx)
    3369:	73 00                	jae    336b <_IO_stdin_used+0x36b>
    336b:	00 00                	add    %al,(%rax)
    336d:	00 00                	add    %al,(%rax)
    336f:	00 57 6f             	add    %dl,0x6f(%rdi)
    3372:	77 21                	ja     3395 <_IO_stdin_used+0x395>
    3374:	20 59 6f             	and    %bl,0x6f(%rcx)
    3377:	75 27                	jne    33a0 <__GNU_EH_FRAME_HDR+0x8>
    3379:	76 65                	jbe    33e0 <__GNU_EH_FRAME_HDR+0x48>
    337b:	20 64 65 66          	and    %ah,0x66(%rbp,%riz,2)
    337f:	75 73                	jne    33f4 <__GNU_EH_FRAME_HDR+0x5c>
    3381:	65 64 20 74 68 65    	gs and %dh,%fs:0x65(%rax,%rbp,2)
    3387:	20 73 65             	and    %dh,0x65(%rbx)
    338a:	63 72 65             	movsxd 0x65(%rdx),%esi
    338d:	74 20                	je     33af <__GNU_EH_FRAME_HDR+0x17>
    338f:	73 74                	jae    3405 <__GNU_EH_FRAME_HDR+0x6d>
    3391:	61                   	(bad)  
    3392:	67 65 21 00          	and    %eax,%gs:(%eax)

Disassembly of section .eh_frame_hdr:

0000000000003398 <__GNU_EH_FRAME_HDR>:
    3398:	01 1b                	add    %ebx,(%rbx)
    339a:	03 3b                	add    (%rbx),%edi
    339c:	dc 00                	faddl  (%rax)
    339e:	00 00                	add    %al,(%rax)
    33a0:	1a 00                	sbb    (%rax),%al
    33a2:	00 00                	add    %al,(%rax)
    33a4:	88 dc                	mov    %bl,%ah
    33a6:	ff                   	(bad)  
    33a7:	ff 10                	call   *(%rax)
    33a9:	01 00                	add    %eax,(%rax)
    33ab:	00 78 dd             	add    %bh,-0x23(%rax)
    33ae:	ff                   	(bad)  
    33af:	ff                   	(bad)  
    33b0:	38 01                	cmp    %al,(%rcx)
    33b2:	00 00                	add    %al,(%rax)
    33b4:	88 dd                	mov    %bl,%ch
    33b6:	ff                   	(bad)  
    33b7:	ff 50 01             	call   *0x1(%rax)
    33ba:	00 00                	add    %al,(%rax)
    33bc:	68 de ff ff f8       	push   $0xfffffffff8ffffde
    33c1:	00 00                	add    %al,(%rax)
    33c3:	00 51 df             	add    %dl,-0x21(%rcx)
    33c6:	ff                   	(bad)  
    33c7:	ff 68 01             	ljmp   *0x1(%rax)
    33ca:	00 00                	add    %al,(%rax)
    33cc:	1f                   	(bad)  
    33cd:	e1 ff                	loope  33ce <__GNU_EH_FRAME_HDR+0x36>
    33cf:	ff 88 01 00 00 8d    	decl   -0x72ffffff(%rax)
    33d5:	e1 ff                	loope  33d6 <__GNU_EH_FRAME_HDR+0x3e>
    33d7:	ff a4 01 00 00 c2 e1 	jmp    *-0x1e3e0000(%rcx,%rax,1)
    33de:	ff                   	(bad)  
    33df:	ff c0                	inc    %eax
    33e1:	01 00                	add    %eax,(%rax)
    33e3:	00 31                	add    %dh,(%rcx)
    33e5:	e2 ff                	loop   33e6 <__GNU_EH_FRAME_HDR+0x4e>
    33e7:	ff e0                	jmp    *%rax
    33e9:	01 00                	add    %eax,(%rax)
    33eb:	00 67 e2             	add    %ah,-0x1e(%rdi)
    33ee:	ff                   	(bad)  
    33ef:	ff 00                	incl   (%rax)
    33f1:	02 00                	add    (%rax),%al
    33f3:	00 ec                	add    %ch,%ah
    33f5:	e2 ff                	loop   33f6 <__GNU_EH_FRAME_HDR+0x5e>
    33f7:	ff 24 02             	jmp    *(%rdx,%rax,1)
    33fa:	00 00                	add    %al,(%rax)
    33fc:	0b e3                	or     %ebx,%esp
    33fe:	ff                   	(bad)  
    33ff:	ff 44 02 00          	incl   0x0(%rdx,%rax,1)
    3403:	00 16                	add    %dl,(%rsi)
    3405:	e3 ff                	jrcxz  3406 <__GNU_EH_FRAME_HDR+0x6e>
    3407:	ff 64 02 00          	jmp    *0x0(%rdx,%rax,1)
    340b:	00 71 e3             	add    %dh,-0x1d(%rcx)
    340e:	ff                   	(bad)  
    340f:	ff 84 02 00 00 d3 e3 	incl   -0x1c2d0000(%rdx,%rax,1)
    3416:	ff                   	(bad)  
    3417:	ff a4 02 00 00 66 e5 	jmp    *-0x1a9a0000(%rdx,%rax,1)
    341e:	ff                   	(bad)  
    341f:	ff c4                	inc    %esp
    3421:	02 00                	add    (%rax),%al
    3423:	00 96 e5 ff ff e0    	add    %dl,-0x1f00001b(%rsi)
    3429:	02 00                	add    (%rax),%al
    342b:	00 64 e6 ff          	add    %ah,-0x1(%rsi,%riz,8)
    342f:	ff 00                	incl   (%rax)
    3431:	03 00                	add    (%rax),%eax
    3433:	00 93 e6 ff ff 20    	add    %dl,0x20ffffe6(%rbx)
    3439:	03 00                	add    (%rax),%eax
    343b:	00 1e                	add    %bl,(%rsi)
    343d:	e7 ff                	out    %eax,$0xff
    343f:	ff 40 03             	incl   0x3(%rax)
    3442:	00 00                	add    %al,(%rax)
    3444:	15 e8 ff ff 60       	adc    $0x60ffffe8,%eax
    3449:	03 00                	add    (%rax),%eax
    344b:	00 8f e8 ff ff 80    	add    %cl,-0x7f000018(%rdi)
    3451:	03 00                	add    (%rax),%eax
    3453:	00 35 e9 ff ff a0    	add    %dh,-0x5f000017(%rip)        # ffffffffa1003442 <_end+0xffffffffa0ffd6d2>
    3459:	03 00                	add    (%rax),%eax
    345b:	00 e4                	add    %ah,%ah
    345d:	e9 ff ff c0 03       	jmp    3c13461 <_end+0x3c0d6f1>
    3462:	00 00                	add    %al,(%rax)
    3464:	81 eb ff ff e0 03    	sub    $0x3e0ffff,%ebx
    346a:	00 00                	add    %al,(%rax)
    346c:	f4                   	hlt    
    346d:	eb ff                	jmp    346e <__GNU_EH_FRAME_HDR+0xd6>
    346f:	ff 00                	incl   (%rax)
    3471:	04 00                	add    $0x0,%al
	...

Disassembly of section .eh_frame:

0000000000003478 <__FRAME_END__-0x340>:
    3478:	14 00                	adc    $0x0,%al
    347a:	00 00                	add    %al,(%rax)
    347c:	00 00                	add    %al,(%rax)
    347e:	00 00                	add    %al,(%rax)
    3480:	01 7a 52             	add    %edi,0x52(%rdx)
    3483:	00 01                	add    %al,(%rcx)
    3485:	78 10                	js     3497 <__GNU_EH_FRAME_HDR+0xff>
    3487:	01 1b                	add    %ebx,(%rbx)
    3489:	0c 07                	or     $0x7,%al
    348b:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
    3491:	00 00                	add    %al,(%rax)
    3493:	00 1c 00             	add    %bl,(%rax,%rax,1)
    3496:	00 00                	add    %al,(%rax)
    3498:	68 dd ff ff 26       	push   $0x26ffffdd
    349d:	00 00                	add    %al,(%rax)
    349f:	00 00                	add    %al,(%rax)
    34a1:	44 07                	rex.R (bad) 
    34a3:	10 00                	adc    %al,(%rax)
    34a5:	00 00                	add    %al,(%rax)
    34a7:	00 24 00             	add    %ah,(%rax,%rax,1)
    34aa:	00 00                	add    %al,(%rax)
    34ac:	34 00                	xor    $0x0,%al
    34ae:	00 00                	add    %al,(%rax)
    34b0:	70 db                	jo     348d <__GNU_EH_FRAME_HDR+0xf5>
    34b2:	ff                   	(bad)  
    34b3:	ff f0                	push   %rax
    34b5:	00 00                	add    %al,(%rax)
    34b7:	00 00                	add    %al,(%rax)
    34b9:	0e                   	(bad)  
    34ba:	10 46 0e             	adc    %al,0xe(%rsi)
    34bd:	18 4a 0f             	sbb    %cl,0xf(%rdx)
    34c0:	0b 77 08             	or     0x8(%rdi),%esi
    34c3:	80 00 3f             	addb   $0x3f,(%rax)
    34c6:	1a 3a                	sbb    (%rdx),%bh
    34c8:	2a 33                	sub    (%rbx),%dh
    34ca:	24 22                	and    $0x22,%al
    34cc:	00 00                	add    %al,(%rax)
    34ce:	00 00                	add    %al,(%rax)
    34d0:	14 00                	adc    $0x0,%al
    34d2:	00 00                	add    %al,(%rax)
    34d4:	5c                   	pop    %rsp
    34d5:	00 00                	add    %al,(%rax)
    34d7:	00 38                	add    %bh,(%rax)
    34d9:	dc ff                	fdivr  %st,%st(7)
    34db:	ff 10                	call   *(%rax)
	...
    34e5:	00 00                	add    %al,(%rax)
    34e7:	00 14 00             	add    %dl,(%rax,%rax,1)
    34ea:	00 00                	add    %al,(%rax)
    34ec:	74 00                	je     34ee <__GNU_EH_FRAME_HDR+0x156>
    34ee:	00 00                	add    %al,(%rax)
    34f0:	30 dc                	xor    %bl,%ah
    34f2:	ff                   	(bad)  
    34f3:	ff e0                	jmp    *%rax
	...
    34fd:	00 00                	add    %al,(%rax)
    34ff:	00 1c 00             	add    %bl,(%rax,%rax,1)
    3502:	00 00                	add    %al,(%rax)
    3504:	8c 00                	mov    %es,(%rax)
    3506:	00 00                	add    %al,(%rax)
    3508:	e1 dd                	loope  34e7 <__GNU_EH_FRAME_HDR+0x14f>
    350a:	ff                   	(bad)  
    350b:	ff ce                	dec    %esi
    350d:	01 00                	add    %eax,(%rax)
    350f:	00 00                	add    %al,(%rax)
    3511:	45 0e                	rex.RB (bad) 
    3513:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3519:	03 c5                	add    %ebp,%eax
    351b:	01 0c 07             	add    %ecx,(%rdi,%rax,1)
    351e:	08 00                	or     %al,(%rax)
    3520:	18 00                	sbb    %al,(%rax)
    3522:	00 00                	add    %al,(%rax)
    3524:	ac                   	lods   %ds:(%rsi),%al
    3525:	00 00                	add    %al,(%rax)
    3527:	00 8f df ff ff 6e    	add    %cl,0x6effffdf(%rdi)
    352d:	00 00                	add    %al,(%rax)
    352f:	00 00                	add    %al,(%rax)
    3531:	45 0e                	rex.RB (bad) 
    3533:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3539:	00 00                	add    %al,(%rax)
    353b:	00 18                	add    %bl,(%rax)
    353d:	00 00                	add    %al,(%rax)
    353f:	00 c8                	add    %cl,%al
    3541:	00 00                	add    %al,(%rax)
    3543:	00 e1                	add    %ah,%cl
    3545:	df ff                	(bad)  
    3547:	ff 35 00 00 00 00    	push   0x0(%rip)        # 354d <__GNU_EH_FRAME_HDR+0x1b5>
    354d:	45 0e                	rex.RB (bad) 
    354f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3555:	00 00                	add    %al,(%rax)
    3557:	00 1c 00             	add    %bl,(%rax,%rax,1)
    355a:	00 00                	add    %al,(%rax)
    355c:	e4 00                	in     $0x0,%al
    355e:	00 00                	add    %al,(%rax)
    3560:	fa                   	cli    
    3561:	df ff                	(bad)  
    3563:	ff 6f 00             	ljmp   *0x0(%rdi)
    3566:	00 00                	add    %al,(%rax)
    3568:	00 45 0e             	add    %al,0xe(%rbp)
    356b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3571:	02 66 0c             	add    0xc(%rsi),%ah
    3574:	07                   	(bad)  
    3575:	08 00                	or     %al,(%rax)
    3577:	00 1c 00             	add    %bl,(%rax,%rax,1)
    357a:	00 00                	add    %al,(%rax)
    357c:	04 01                	add    $0x1,%al
    357e:	00 00                	add    %al,(%rax)
    3580:	49 e0 ff             	rex.WB loopne 3582 <__GNU_EH_FRAME_HDR+0x1ea>
    3583:	ff 36                	push   (%rsi)
    3585:	00 00                	add    %al,(%rax)
    3587:	00 00                	add    %al,(%rax)
    3589:	45 0e                	rex.RB (bad) 
    358b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3591:	6d                   	insl   (%dx),%es:(%rdi)
    3592:	0c 07                	or     $0x7,%al
    3594:	08 00                	or     %al,(%rax)
    3596:	00 00                	add    %al,(%rax)
    3598:	20 00                	and    %al,(%rax)
    359a:	00 00                	add    %al,(%rax)
    359c:	24 01                	and    $0x1,%al
    359e:	00 00                	add    %al,(%rax)
    35a0:	5f                   	pop    %rdi
    35a1:	e0 ff                	loopne 35a2 <__GNU_EH_FRAME_HDR+0x20a>
    35a3:	ff 85 00 00 00 00    	incl   0x0(%rbp)
    35a9:	45 0e                	rex.RB (bad) 
    35ab:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    35b1:	45 83 03 02          	rex.RB addl $0x2,(%r11)
    35b5:	77 0c                	ja     35c3 <__GNU_EH_FRAME_HDR+0x22b>
    35b7:	07                   	(bad)  
    35b8:	08 00                	or     %al,(%rax)
    35ba:	00 00                	add    %al,(%rax)
    35bc:	1c 00                	sbb    $0x0,%al
    35be:	00 00                	add    %al,(%rax)
    35c0:	48 01 00             	add    %rax,(%rax)
    35c3:	00 c0                	add    %al,%al
    35c5:	e0 ff                	loopne 35c6 <__GNU_EH_FRAME_HDR+0x22e>
    35c7:	ff 1f                	lcall  *(%rdi)
    35c9:	00 00                	add    %al,(%rax)
    35cb:	00 00                	add    %al,(%rax)
    35cd:	45 0e                	rex.RB (bad) 
    35cf:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    35d5:	56                   	push   %rsi
    35d6:	0c 07                	or     $0x7,%al
    35d8:	08 00                	or     %al,(%rax)
    35da:	00 00                	add    %al,(%rax)
    35dc:	1c 00                	sbb    $0x0,%al
    35de:	00 00                	add    %al,(%rax)
    35e0:	68 01 00 00 bf       	push   $0xffffffffbf000001
    35e5:	e0 ff                	loopne 35e6 <__GNU_EH_FRAME_HDR+0x24e>
    35e7:	ff 0b                	decl   (%rbx)
    35e9:	00 00                	add    %al,(%rax)
    35eb:	00 00                	add    %al,(%rax)
    35ed:	45 0e                	rex.RB (bad) 
    35ef:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    35f5:	42 0c 07             	rex.X or $0x7,%al
    35f8:	08 00                	or     %al,(%rax)
    35fa:	00 00                	add    %al,(%rax)
    35fc:	1c 00                	sbb    $0x0,%al
    35fe:	00 00                	add    %al,(%rax)
    3600:	88 01                	mov    %al,(%rcx)
    3602:	00 00                	add    %al,(%rax)
    3604:	aa                   	stos   %al,%es:(%rdi)
    3605:	e0 ff                	loopne 3606 <__GNU_EH_FRAME_HDR+0x26e>
    3607:	ff 5b 00             	lcall  *0x0(%rbx)
    360a:	00 00                	add    %al,(%rax)
    360c:	00 45 0e             	add    %al,0xe(%rbp)
    360f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3615:	02 52 0c             	add    0xc(%rdx),%dl
    3618:	07                   	(bad)  
    3619:	08 00                	or     %al,(%rax)
    361b:	00 1c 00             	add    %bl,(%rax,%rax,1)
    361e:	00 00                	add    %al,(%rax)
    3620:	a8 01                	test   $0x1,%al
    3622:	00 00                	add    %al,(%rax)
    3624:	e5 e0                	in     $0xe0,%eax
    3626:	ff                   	(bad)  
    3627:	ff 62 00             	jmp    *0x0(%rdx)
    362a:	00 00                	add    %al,(%rax)
    362c:	00 45 0e             	add    %al,0xe(%rbp)
    362f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3635:	02 59 0c             	add    0xc(%rcx),%bl
    3638:	07                   	(bad)  
    3639:	08 00                	or     %al,(%rax)
    363b:	00 1c 00             	add    %bl,(%rax,%rax,1)
    363e:	00 00                	add    %al,(%rax)
    3640:	c8 01 00 00          	enter  $0x1,$0x0
    3644:	27                   	(bad)  
    3645:	e1 ff                	loope  3646 <__GNU_EH_FRAME_HDR+0x2ae>
    3647:	ff 93 01 00 00 00    	call   *0x1(%rbx)
    364d:	45 0e                	rex.RB (bad) 
    364f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3655:	03 8a 01 0c 07 08    	add    0x8070c01(%rdx),%ecx
    365b:	00 18                	add    %bl,(%rax)
    365d:	00 00                	add    %al,(%rax)
    365f:	00 e8                	add    %ch,%al
    3661:	01 00                	add    %eax,(%rax)
    3663:	00 9a e2 ff ff 30    	add    %bl,0x30ffffe2(%rdx)
    3669:	00 00                	add    %al,(%rax)
    366b:	00 00                	add    %al,(%rax)
    366d:	45 0e                	rex.RB (bad) 
    366f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3675:	00 00                	add    %al,(%rax)
    3677:	00 1c 00             	add    %bl,(%rax,%rax,1)
    367a:	00 00                	add    %al,(%rax)
    367c:	04 02                	add    $0x2,%al
    367e:	00 00                	add    %al,(%rax)
    3680:	ae                   	scas   %es:(%rdi),%al
    3681:	e2 ff                	loop   3682 <__GNU_EH_FRAME_HDR+0x2ea>
    3683:	ff ce                	dec    %esi
    3685:	00 00                	add    %al,(%rax)
    3687:	00 00                	add    %al,(%rax)
    3689:	45 0e                	rex.RB (bad) 
    368b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3691:	02 c5                	add    %ch,%al
    3693:	0c 07                	or     $0x7,%al
    3695:	08 00                	or     %al,(%rax)
    3697:	00 1c 00             	add    %bl,(%rax,%rax,1)
    369a:	00 00                	add    %al,(%rax)
    369c:	24 02                	and    $0x2,%al
    369e:	00 00                	add    %al,(%rax)
    36a0:	5c                   	pop    %rsp
    36a1:	e3 ff                	jrcxz  36a2 <__GNU_EH_FRAME_HDR+0x30a>
    36a3:	ff 2f                	ljmp   *(%rdi)
    36a5:	00 00                	add    %al,(%rax)
    36a7:	00 00                	add    %al,(%rax)
    36a9:	45 0e                	rex.RB (bad) 
    36ab:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    36b1:	66 0c 07             	data16 or $0x7,%al
    36b4:	08 00                	or     %al,(%rax)
    36b6:	00 00                	add    %al,(%rax)
    36b8:	1c 00                	sbb    $0x0,%al
    36ba:	00 00                	add    %al,(%rax)
    36bc:	44 02 00             	add    (%rax),%r8b
    36bf:	00 6b e3             	add    %ch,-0x1d(%rbx)
    36c2:	ff                   	(bad)  
    36c3:	ff 8b 00 00 00 00    	decl   0x0(%rbx)
    36c9:	45 0e                	rex.RB (bad) 
    36cb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    36d1:	02 82 0c 07 08 00    	add    0x8070c(%rdx),%al
    36d7:	00 1c 00             	add    %bl,(%rax,%rax,1)
    36da:	00 00                	add    %al,(%rax)
    36dc:	64 02 00             	add    %fs:(%rax),%al
    36df:	00 d6                	add    %dl,%dh
    36e1:	e3 ff                	jrcxz  36e2 <__GNU_EH_FRAME_HDR+0x34a>
    36e3:	ff f7                	push   %rdi
    36e5:	00 00                	add    %al,(%rax)
    36e7:	00 00                	add    %al,(%rax)
    36e9:	45 0e                	rex.RB (bad) 
    36eb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    36f1:	02 ee                	add    %dh,%ch
    36f3:	0c 07                	or     $0x7,%al
    36f5:	08 00                	or     %al,(%rax)
    36f7:	00 1c 00             	add    %bl,(%rax,%rax,1)
    36fa:	00 00                	add    %al,(%rax)
    36fc:	84 02                	test   %al,(%rdx)
    36fe:	00 00                	add    %al,(%rax)
    3700:	ad                   	lods   %ds:(%rsi),%eax
    3701:	e4 ff                	in     $0xff,%al
    3703:	ff                   	(bad)  
    3704:	7a 00                	jp     3706 <__GNU_EH_FRAME_HDR+0x36e>
    3706:	00 00                	add    %al,(%rax)
    3708:	00 45 0e             	add    %al,0xe(%rbp)
    370b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3711:	02 71 0c             	add    0xc(%rcx),%dh
    3714:	07                   	(bad)  
    3715:	08 00                	or     %al,(%rax)
    3717:	00 1c 00             	add    %bl,(%rax,%rax,1)
    371a:	00 00                	add    %al,(%rax)
    371c:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
    371d:	02 00                	add    (%rax),%al
    371f:	00 07                	add    %al,(%rdi)
    3721:	e5 ff                	in     $0xff,%eax
    3723:	ff a6 00 00 00 00    	jmp    *0x0(%rsi)
    3729:	45 0e                	rex.RB (bad) 
    372b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3731:	02 9d 0c 07 08 00    	add    0x8070c(%rbp),%bl
    3737:	00 1c 00             	add    %bl,(%rax,%rax,1)
    373a:	00 00                	add    %al,(%rax)
    373c:	c4 02 00 00          	(bad)
    3740:	8d                   	(bad)  
    3741:	e5 ff                	in     $0xff,%eax
    3743:	ff af 00 00 00 00    	ljmp   *0x0(%rdi)
    3749:	45 0e                	rex.RB (bad) 
    374b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3751:	02 a6 0c 07 08 00    	add    0x8070c(%rsi),%ah
    3757:	00 1c 00             	add    %bl,(%rax,%rax,1)
    375a:	00 00                	add    %al,(%rax)
    375c:	e4 02                	in     $0x2,%al
    375e:	00 00                	add    %al,(%rax)
    3760:	1c e6                	sbb    $0xe6,%al
    3762:	ff                   	(bad)  
    3763:	ff 9d 01 00 00 00    	lcall  *0x1(%rbp)
    3769:	45 0e                	rex.RB (bad) 
    376b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3771:	03 94 01 0c 07 08 00 	add    0x8070c(%rcx,%rax,1),%edx
    3778:	1c 00                	sbb    $0x0,%al
    377a:	00 00                	add    %al,(%rax)
    377c:	04 03                	add    $0x3,%al
    377e:	00 00                	add    %al,(%rax)
    3780:	99                   	cltd   
    3781:	e7 ff                	out    %eax,$0xff
    3783:	ff 73 00             	push   0x0(%rbx)
    3786:	00 00                	add    %al,(%rax)
    3788:	00 45 0e             	add    %al,0xe(%rbp)
    378b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    3791:	02 6a 0c             	add    0xc(%rdx),%ch
    3794:	07                   	(bad)  
    3795:	08 00                	or     %al,(%rax)
    3797:	00 1c 00             	add    %bl,(%rax,%rax,1)
    379a:	00 00                	add    %al,(%rax)
    379c:	24 03                	and    $0x3,%al
    379e:	00 00                	add    %al,(%rax)
    37a0:	ec                   	in     (%dx),%al
    37a1:	e7 ff                	out    %eax,$0xff
    37a3:	ff 6b 00             	ljmp   *0x0(%rbx)
    37a6:	00 00                	add    %al,(%rax)
    37a8:	00 45 0e             	add    %al,0xe(%rbp)
    37ab:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    37b1:	02 62 0c             	add    0xc(%rdx),%ah
    37b4:	07                   	(bad)  
    37b5:	08 00                	or     %al,(%rax)
	...

00000000000037b8 <__FRAME_END__>:
    37b8:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000004d50 <__frame_dummy_init_array_entry>:
    4d50:	e0 12                	loopne 4d64 <_DYNAMIC+0x4>
    4d52:	00 00                	add    %al,(%rax)
    4d54:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000004d58 <__do_global_dtors_aux_fini_array_entry>:
    4d58:	a0                   	.byte 0xa0
    4d59:	12 00                	adc    (%rax),%al
    4d5b:	00 00                	add    %al,(%rax)
    4d5d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000004d60 <_DYNAMIC>:
    4d60:	01 00                	add    %eax,(%rax)
    4d62:	00 00                	add    %al,(%rax)
    4d64:	00 00                	add    %al,(%rax)
    4d66:	00 00                	add    %al,(%rax)
    4d68:	a2 00 00 00 00 00 00 	movabs %al,0xc00000000000000
    4d6f:	00 0c 
	...
    4d79:	10 00                	adc    %al,(%rax)
    4d7b:	00 00                	add    %al,(%rax)
    4d7d:	00 00                	add    %al,(%rax)
    4d7f:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 4d85 <_DYNAMIC+0x25>
    4d85:	00 00                	add    %al,(%rax)
    4d87:	00 f8                	add    %bh,%al
    4d89:	1f                   	(bad)  
    4d8a:	00 00                	add    %al,(%rax)
    4d8c:	00 00                	add    %al,(%rax)
    4d8e:	00 00                	add    %al,(%rax)
    4d90:	19 00                	sbb    %eax,(%rax)
    4d92:	00 00                	add    %al,(%rax)
    4d94:	00 00                	add    %al,(%rax)
    4d96:	00 00                	add    %al,(%rax)
    4d98:	50                   	push   %rax
    4d99:	4d 00 00             	rex.WRB add %r8b,(%r8)
    4d9c:	00 00                	add    %al,(%rax)
    4d9e:	00 00                	add    %al,(%rax)
    4da0:	1b 00                	sbb    (%rax),%eax
    4da2:	00 00                	add    %al,(%rax)
    4da4:	00 00                	add    %al,(%rax)
    4da6:	00 00                	add    %al,(%rax)
    4da8:	08 00                	or     %al,(%rax)
    4daa:	00 00                	add    %al,(%rax)
    4dac:	00 00                	add    %al,(%rax)
    4dae:	00 00                	add    %al,(%rax)
    4db0:	1a 00                	sbb    (%rax),%al
    4db2:	00 00                	add    %al,(%rax)
    4db4:	00 00                	add    %al,(%rax)
    4db6:	00 00                	add    %al,(%rax)
    4db8:	58                   	pop    %rax
    4db9:	4d 00 00             	rex.WRB add %r8b,(%r8)
    4dbc:	00 00                	add    %al,(%rax)
    4dbe:	00 00                	add    %al,(%rax)
    4dc0:	1c 00                	sbb    $0x0,%al
    4dc2:	00 00                	add    %al,(%rax)
    4dc4:	00 00                	add    %al,(%rax)
    4dc6:	00 00                	add    %al,(%rax)
    4dc8:	08 00                	or     %al,(%rax)
    4dca:	00 00                	add    %al,(%rax)
    4dcc:	00 00                	add    %al,(%rax)
    4dce:	00 00                	add    %al,(%rax)
    4dd0:	f5                   	cmc    
    4dd1:	fe                   	(bad)  
    4dd2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4dd5:	00 00                	add    %al,(%rax)
    4dd7:	00 b0 03 00 00 00    	add    %dh,0x3(%rax)
    4ddd:	00 00                	add    %al,(%rax)
    4ddf:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 4de5 <_DYNAMIC+0x85>
    4de5:	00 00                	add    %al,(%rax)
    4de7:	00 f0                	add    %dh,%al
    4de9:	05 00 00 00 00       	add    $0x0,%eax
    4dee:	00 00                	add    %al,(%rax)
    4df0:	06                   	(bad)  
    4df1:	00 00                	add    %al,(%rax)
    4df3:	00 00                	add    %al,(%rax)
    4df5:	00 00                	add    %al,(%rax)
    4df7:	00 e0                	add    %ah,%al
    4df9:	03 00                	add    (%rax),%eax
    4dfb:	00 00                	add    %al,(%rax)
    4dfd:	00 00                	add    %al,(%rax)
    4dff:	00 0a                	add    %cl,(%rdx)
    4e01:	00 00                	add    %al,(%rax)
    4e03:	00 00                	add    %al,(%rax)
    4e05:	00 00                	add    %al,(%rax)
    4e07:	00 26                	add    %ah,(%rsi)
    4e09:	01 00                	add    %eax,(%rax)
    4e0b:	00 00                	add    %al,(%rax)
    4e0d:	00 00                	add    %al,(%rax)
    4e0f:	00 0b                	add    %cl,(%rbx)
    4e11:	00 00                	add    %al,(%rax)
    4e13:	00 00                	add    %al,(%rax)
    4e15:	00 00                	add    %al,(%rax)
    4e17:	00 18                	add    %bl,(%rax)
    4e19:	00 00                	add    %al,(%rax)
    4e1b:	00 00                	add    %al,(%rax)
    4e1d:	00 00                	add    %al,(%rax)
    4e1f:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 4e25 <_DYNAMIC+0xc5>
	...
    4e2d:	00 00                	add    %al,(%rax)
    4e2f:	00 03                	add    %al,(%rbx)
    4e31:	00 00                	add    %al,(%rax)
    4e33:	00 00                	add    %al,(%rax)
    4e35:	00 00                	add    %al,(%rax)
    4e37:	00 50 4f             	add    %dl,0x4f(%rax)
    4e3a:	00 00                	add    %al,(%rax)
    4e3c:	00 00                	add    %al,(%rax)
    4e3e:	00 00                	add    %al,(%rax)
    4e40:	02 00                	add    (%rax),%al
    4e42:	00 00                	add    %al,(%rax)
    4e44:	00 00                	add    %al,(%rax)
    4e46:	00 00                	add    %al,(%rax)
    4e48:	50                   	push   %rax
    4e49:	01 00                	add    %eax,(%rax)
    4e4b:	00 00                	add    %al,(%rax)
    4e4d:	00 00                	add    %al,(%rax)
    4e4f:	00 14 00             	add    %dl,(%rax,%rax,1)
    4e52:	00 00                	add    %al,(%rax)
    4e54:	00 00                	add    %al,(%rax)
    4e56:	00 00                	add    %al,(%rax)
    4e58:	07                   	(bad)  
    4e59:	00 00                	add    %al,(%rax)
    4e5b:	00 00                	add    %al,(%rax)
    4e5d:	00 00                	add    %al,(%rax)
    4e5f:	00 17                	add    %dl,(%rdi)
    4e61:	00 00                	add    %al,(%rax)
    4e63:	00 00                	add    %al,(%rax)
    4e65:	00 00                	add    %al,(%rax)
    4e67:	00 a8 0a 00 00 00    	add    %ch,0xa(%rax)
    4e6d:	00 00                	add    %al,(%rax)
    4e6f:	00 07                	add    %al,(%rdi)
    4e71:	00 00                	add    %al,(%rax)
    4e73:	00 00                	add    %al,(%rax)
    4e75:	00 00                	add    %al,(%rax)
    4e77:	00 a8 07 00 00 00    	add    %ch,0x7(%rax)
    4e7d:	00 00                	add    %al,(%rax)
    4e7f:	00 08                	add    %cl,(%rax)
	...
    4e89:	03 00                	add    (%rax),%eax
    4e8b:	00 00                	add    %al,(%rax)
    4e8d:	00 00                	add    %al,(%rax)
    4e8f:	00 09                	add    %cl,(%rcx)
    4e91:	00 00                	add    %al,(%rax)
    4e93:	00 00                	add    %al,(%rax)
    4e95:	00 00                	add    %al,(%rax)
    4e97:	00 18                	add    %bl,(%rax)
    4e99:	00 00                	add    %al,(%rax)
    4e9b:	00 00                	add    %al,(%rax)
    4e9d:	00 00                	add    %al,(%rax)
    4e9f:	00 1e                	add    %bl,(%rsi)
    4ea1:	00 00                	add    %al,(%rax)
    4ea3:	00 00                	add    %al,(%rax)
    4ea5:	00 00                	add    %al,(%rax)
    4ea7:	00 08                	add    %cl,(%rax)
    4ea9:	00 00                	add    %al,(%rax)
    4eab:	00 00                	add    %al,(%rax)
    4ead:	00 00                	add    %al,(%rax)
    4eaf:	00 fb                	add    %bh,%bl
    4eb1:	ff                   	(bad)  
    4eb2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4eb5:	00 00                	add    %al,(%rax)
    4eb7:	00 01                	add    %al,(%rcx)
    4eb9:	00 00                	add    %al,(%rax)
    4ebb:	08 00                	or     %al,(%rax)
    4ebd:	00 00                	add    %al,(%rax)
    4ebf:	00 fe                	add    %bh,%dh
    4ec1:	ff                   	(bad)  
    4ec2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4ec5:	00 00                	add    %al,(%rax)
    4ec7:	00 48 07             	add    %cl,0x7(%rax)
    4eca:	00 00                	add    %al,(%rax)
    4ecc:	00 00                	add    %al,(%rax)
    4ece:	00 00                	add    %al,(%rax)
    4ed0:	ff                   	(bad)  
    4ed1:	ff                   	(bad)  
    4ed2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4ed5:	00 00                	add    %al,(%rax)
    4ed7:	00 01                	add    %al,(%rcx)
    4ed9:	00 00                	add    %al,(%rax)
    4edb:	00 00                	add    %al,(%rax)
    4edd:	00 00                	add    %al,(%rax)
    4edf:	00 f0                	add    %dh,%al
    4ee1:	ff                   	(bad)  
    4ee2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4ee5:	00 00                	add    %al,(%rax)
    4ee7:	00 16                	add    %dl,(%rsi)
    4ee9:	07                   	(bad)  
    4eea:	00 00                	add    %al,(%rax)
    4eec:	00 00                	add    %al,(%rax)
    4eee:	00 00                	add    %al,(%rax)
    4ef0:	f9                   	stc    
    4ef1:	ff                   	(bad)  
    4ef2:	ff 6f 00             	ljmp   *0x0(%rdi)
    4ef5:	00 00                	add    %al,(%rax)
    4ef7:	00 19                	add    %bl,(%rcx)
	...

Disassembly of section .got:

0000000000004f50 <_GLOBAL_OFFSET_TABLE_>:
    4f50:	60                   	(bad)  
    4f51:	4d 00 00             	rex.WRB add %r8b,(%r8)
	...
    4f68:	30 10                	xor    %dl,(%rax)
    4f6a:	00 00                	add    %al,(%rax)
    4f6c:	00 00                	add    %al,(%rax)
    4f6e:	00 00                	add    %al,(%rax)
    4f70:	40 10 00             	rex adc %al,(%rax)
    4f73:	00 00                	add    %al,(%rax)
    4f75:	00 00                	add    %al,(%rax)
    4f77:	00 50 10             	add    %dl,0x10(%rax)
    4f7a:	00 00                	add    %al,(%rax)
    4f7c:	00 00                	add    %al,(%rax)
    4f7e:	00 00                	add    %al,(%rax)
    4f80:	60                   	(bad)  
    4f81:	10 00                	adc    %al,(%rax)
    4f83:	00 00                	add    %al,(%rax)
    4f85:	00 00                	add    %al,(%rax)
    4f87:	00 70 10             	add    %dh,0x10(%rax)
    4f8a:	00 00                	add    %al,(%rax)
    4f8c:	00 00                	add    %al,(%rax)
    4f8e:	00 00                	add    %al,(%rax)
    4f90:	80 10 00             	adcb   $0x0,(%rax)
    4f93:	00 00                	add    %al,(%rax)
    4f95:	00 00                	add    %al,(%rax)
    4f97:	00 90 10 00 00 00    	add    %dl,0x10(%rax)
    4f9d:	00 00                	add    %al,(%rax)
    4f9f:	00 a0 10 00 00 00    	add    %ah,0x10(%rax)
    4fa5:	00 00                	add    %al,(%rax)
    4fa7:	00 b0 10 00 00 00    	add    %dh,0x10(%rax)
    4fad:	00 00                	add    %al,(%rax)
    4faf:	00 c0                	add    %al,%al
    4fb1:	10 00                	adc    %al,(%rax)
    4fb3:	00 00                	add    %al,(%rax)
    4fb5:	00 00                	add    %al,(%rax)
    4fb7:	00 d0                	add    %dl,%al
    4fb9:	10 00                	adc    %al,(%rax)
    4fbb:	00 00                	add    %al,(%rax)
    4fbd:	00 00                	add    %al,(%rax)
    4fbf:	00 e0                	add    %ah,%al
    4fc1:	10 00                	adc    %al,(%rax)
    4fc3:	00 00                	add    %al,(%rax)
    4fc5:	00 00                	add    %al,(%rax)
    4fc7:	00 f0                	add    %dh,%al
    4fc9:	10 00                	adc    %al,(%rax)
    4fcb:	00 00                	add    %al,(%rax)
    4fcd:	00 00                	add    %al,(%rax)
    4fcf:	00 00                	add    %al,(%rax)
    4fd1:	11 00                	adc    %eax,(%rax)
	...

Disassembly of section .data:

0000000000005000 <__data_start>:
	...

0000000000005008 <__dso_handle>:
    5008:	08 50 00             	or     %dl,0x0(%rax)
	...

0000000000005020 <host_table>:
    5020:	58                   	pop    %rax
    5021:	31 00                	xor    %eax,(%rax)
    5023:	00 00                	add    %al,(%rax)
    5025:	00 00                	add    %al,(%rax)
    5027:	00 72 31             	add    %dh,0x31(%rdx)
    502a:	00 00                	add    %al,(%rax)
    502c:	00 00                	add    %al,(%rax)
    502e:	00 00                	add    %al,(%rax)
    5030:	8c 31                	mov    %?,(%rcx)
	...

0000000000005420 <bomb_id>:
    5420:	af                   	scas   %es:(%rdi),%eax
    5421:	01 3a                	add    %edi,(%rdx)
    5423:	07                   	(bad)  
	...

0000000000005430 <node6>:
    5430:	10 02                	adc    %al,(%rdx)
    5432:	00 00                	add    %al,(%rax)
    5434:	06                   	(bad)  
	...

0000000000005440 <n48>:
    5440:	e9 03 00 00 00       	jmp    5448 <n48+0x8>
	...

0000000000005460 <n46>:
    5460:	2f                   	(bad)  
	...

0000000000005480 <n43>:
    5480:	14 00                	adc    $0x0,%al
	...

00000000000054a0 <n42>:
    54a0:	07                   	(bad)  
	...

00000000000054c0 <n44>:
    54c0:	23 00                	and    (%rax),%eax
	...

00000000000054e0 <n47>:
    54e0:	63 00                	movsxd (%rax),%eax
	...

0000000000005500 <n41>:
    5500:	01 00                	add    %eax,(%rax)
	...

0000000000005520 <n45>:
    5520:	28 00                	sub    %al,(%rax)
	...

0000000000005540 <array.3096>:
    5540:	6d                   	insl   (%dx),%es:(%rdi)
    5541:	61                   	(bad)  
    5542:	64 75 69             	fs jne 55ae <n34+0xe>
    5545:	65 72 73             	gs jb  55bb <n34+0x1b>
    5548:	6e                   	outsb  %ds:(%rsi),(%dx)
    5549:	66 6f                	outsw  %ds:(%rsi),(%dx)
    554b:	74 76                	je     55c3 <n31+0x3>
    554d:	62                   	(bad)  
    554e:	79 6c                	jns    55bc <n34+0x1c>

0000000000005550 <node5>:
    5550:	38 03                	cmp    %al,(%rbx)
    5552:	00 00                	add    %al,(%rax)
    5554:	05 00 00 00 30       	add    $0x30000000,%eax
    5559:	54                   	push   %rsp
    555a:	00 00                	add    %al,(%rax)
    555c:	00 00                	add    %al,(%rax)
	...

0000000000005560 <node4>:
    5560:	79 00                	jns    5562 <node4+0x2>
    5562:	00 00                	add    %al,(%rax)
    5564:	04 00                	add    $0x0,%al
    5566:	00 00                	add    %al,(%rax)
    5568:	50                   	push   %rax
    5569:	55                   	push   %rbp
    556a:	00 00                	add    %al,(%rax)
    556c:	00 00                	add    %al,(%rax)
	...

0000000000005570 <node3>:
    5570:	42 01 00             	rex.X add %eax,(%rax)
    5573:	00 03                	add    %al,(%rbx)
    5575:	00 00                	add    %al,(%rax)
    5577:	00 60 55             	add    %ah,0x55(%rax)
    557a:	00 00                	add    %al,(%rax)
    557c:	00 00                	add    %al,(%rax)
	...

0000000000005580 <node2>:
    5580:	8b 03                	mov    (%rbx),%eax
    5582:	00 00                	add    %al,(%rax)
    5584:	02 00                	add    (%rax),%al
    5586:	00 00                	add    %al,(%rax)
    5588:	70 55                	jo     55df <n31+0x1f>
    558a:	00 00                	add    %al,(%rax)
    558c:	00 00                	add    %al,(%rax)
	...

0000000000005590 <node1>:
    5590:	19 01                	sbb    %eax,(%rcx)
    5592:	00 00                	add    %al,(%rax)
    5594:	01 00                	add    %eax,(%rax)
    5596:	00 00                	add    %al,(%rax)
    5598:	80 55 00 00          	adcb   $0x0,0x0(%rbp)
    559c:	00 00                	add    %al,(%rax)
	...

00000000000055a0 <n34>:
    55a0:	6b 00 00             	imul   $0x0,(%rax),%eax
    55a3:	00 00                	add    %al,(%rax)
    55a5:	00 00                	add    %al,(%rax)
    55a7:	00 e0                	add    %ah,%al
    55a9:	54                   	push   %rsp
    55aa:	00 00                	add    %al,(%rax)
    55ac:	00 00                	add    %al,(%rax)
    55ae:	00 00                	add    %al,(%rax)
    55b0:	40 54                	rex push %rsp
	...

00000000000055c0 <n31>:
    55c0:	06                   	(bad)  
	...
    55c9:	55                   	push   %rbp
    55ca:	00 00                	add    %al,(%rax)
    55cc:	00 00                	add    %al,(%rax)
    55ce:	00 00                	add    %al,(%rax)
    55d0:	a0 54 00 00 00 00 00 	movabs 0x54,%al
    55d7:	00 00 
    55d9:	00 00                	add    %al,(%rax)
    55db:	00 00                	add    %al,(%rax)
    55dd:	00 00                	add    %al,(%rax)
	...

00000000000055e0 <n33>:
    55e0:	2d 00 00 00 00       	sub    $0x0,%eax
    55e5:	00 00                	add    %al,(%rax)
    55e7:	00 20                	add    %ah,(%rax)
    55e9:	55                   	push   %rbp
    55ea:	00 00                	add    %al,(%rax)
    55ec:	00 00                	add    %al,(%rax)
    55ee:	00 00                	add    %al,(%rax)
    55f0:	60                   	(bad)  
    55f1:	54                   	push   %rsp
	...

0000000000005600 <n32>:
    5600:	16                   	(bad)  
    5601:	00 00                	add    %al,(%rax)
    5603:	00 00                	add    %al,(%rax)
    5605:	00 00                	add    %al,(%rax)
    5607:	00 80 54 00 00 00    	add    %al,0x54(%rax)
    560d:	00 00                	add    %al,(%rax)
    560f:	00 c0                	add    %al,%al
    5611:	54                   	push   %rsp
	...

0000000000005620 <n22>:
    5620:	32 00                	xor    (%rax),%al
    5622:	00 00                	add    %al,(%rax)
    5624:	00 00                	add    %al,(%rax)
    5626:	00 00                	add    %al,(%rax)
    5628:	e0 55                	loopne 567f <__TMC_END__+0x7>
    562a:	00 00                	add    %al,(%rax)
    562c:	00 00                	add    %al,(%rax)
    562e:	00 00                	add    %al,(%rax)
    5630:	a0 55 00 00 00 00 00 	movabs 0x55,%al
    5637:	00 00 
    5639:	00 00                	add    %al,(%rax)
    563b:	00 00                	add    %al,(%rax)
    563d:	00 00                	add    %al,(%rax)
	...

0000000000005640 <n21>:
    5640:	08 00                	or     %al,(%rax)
    5642:	00 00                	add    %al,(%rax)
    5644:	00 00                	add    %al,(%rax)
    5646:	00 00                	add    %al,(%rax)
    5648:	c0 55 00 00          	rclb   $0x0,0x0(%rbp)
    564c:	00 00                	add    %al,(%rax)
    564e:	00 00                	add    %al,(%rax)
    5650:	00 56 00             	add    %dl,0x0(%rsi)
	...

0000000000005660 <n1>:
    5660:	24 00                	and    $0x0,%al
    5662:	00 00                	add    %al,(%rax)
    5664:	00 00                	add    %al,(%rax)
    5666:	00 00                	add    %al,(%rax)
    5668:	40 56                	rex push %rsi
    566a:	00 00                	add    %al,(%rax)
    566c:	00 00                	add    %al,(%rax)
    566e:	00 00                	add    %al,(%rax)
    5670:	20 56 00             	and    %dl,0x0(%rsi)
    5673:	00 00                	add    %al,(%rax)
    5675:	00 00                	add    %al,(%rax)
	...

Disassembly of section .bss:

0000000000005680 <stdout@GLIBC_2.2.5>:
	...

0000000000005690 <stdin@GLIBC_2.2.5>:
	...

0000000000005698 <completed.0>:
	...

00000000000056a0 <infile>:
	...

00000000000056c0 <input_strings>:
	...

0000000000005d00 <num_input_strings>:
	...

0000000000005d20 <scratch>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <__abi_tag-0x314>
   a:	74 75                	je     81 <__abi_tag-0x30b>
   c:	20 31                	and    %dh,(%rcx)
   e:	31 2e                	xor    %ebp,(%rsi)
  10:	34 2e                	xor    $0x2e,%al
  12:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 75627549 <_end+0x756217d9>
  18:	6e                   	outsb  %ds:(%rsi),(%dx)
  19:	74 75                	je     90 <__abi_tag-0x2fc>
  1b:	31 7e 32             	xor    %edi,0x32(%rsi)
  1e:	32 2e                	xor    (%rsi),%ch
  20:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  23:	20 31                	and    %dh,(%rcx)
  25:	31 2e                	xor    %ebp,(%rsi)
  27:	34 2e                	xor    $0x2e,%al
  29:	30 00                	xor    %al,(%rax)
  2b:	47                   	rex.RXB
  2c:	43                   	rex.XB
  2d:	43 3a 20             	rex.XB cmp (%r8),%spl
  30:	28 55 62             	sub    %dl,0x62(%rbp)
  33:	75 6e                	jne    a3 <__abi_tag-0x2e9>
  35:	74 75                	je     ac <__abi_tag-0x2e0>
  37:	20 39                	and    %bh,(%rcx)
  39:	2e 34 2e             	cs xor $0x2e,%al
  3c:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 75627573 <_end+0x75621803>
  42:	6e                   	outsb  %ds:(%rsi),(%dx)
  43:	74 75                	je     ba <__abi_tag-0x2d2>
  45:	31 7e 32             	xor    %edi,0x32(%rsi)
  48:	30 2e                	xor    %ch,(%rsi)
  4a:	30 34 2e             	xor    %dh,(%rsi,%rbp,1)
  4d:	32 29                	xor    (%rcx),%ch
  4f:	20 39                	and    %bh,(%rcx)
  51:	2e 34 2e             	cs xor $0x2e,%al
  54:	30 00                	xor    %al,(%rax)

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	02 00                	add    (%rax),%al
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	08 00                	or     %al,(%rax)
   c:	00 00                	add    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	e9 12 00 00 00       	jmp    27 <__abi_tag-0x365>
  15:	00 00                	add    %al,(%rax)
  17:	00 ce                	add    %cl,%dh
  19:	01 00                	add    %eax,(%rax)
	...
  2f:	00 2c 00             	add    %ch,(%rax,%rax,1)
  32:	00 00                	add    %al,(%rax)
  34:	02 00                	add    (%rax),%al
  36:	b1 03                	mov    $0x3,%cl
  38:	00 00                	add    %al,(%rax)
  3a:	08 00                	or     %al,(%rax)
  3c:	00 00                	add    %al,(%rax)
  3e:	00 00                	add    %al,(%rax)
  40:	b7 14                	mov    $0x14,%bh
  42:	00 00                	add    %al,(%rax)
  44:	00 00                	add    %al,(%rax)
  46:	00 00                	add    %al,(%rax)
  48:	45 05 00 00 00 00    	rex.RB add $0x0,%eax
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	ad                   	lods   %ds:(%rsi),%eax
   1:	03 00                	add    (%rax),%eax
   3:	00 05 00 01 08 00    	add    %al,0x80100(%rip)        # 80109 <_end+0x7a399>
   9:	00 00                	add    %al,(%rax)
   b:	00 0d 86 00 00 00    	add    %cl,0x86(%rip)        # 97 <__abi_tag-0x2f5>
  11:	1d 60 00 00 00       	sbb    $0x60,%eax
  16:	00 00                	add    %al,(%rax)
  18:	00 00                	add    %al,(%rax)
  1a:	e9 12 00 00 00       	jmp    31 <__abi_tag-0x35b>
  1f:	00 00                	add    %al,(%rax)
  21:	00 ce                	add    %cl,%dh
  23:	01 00                	add    %eax,(%rax)
	...
  2d:	00 06                	add    %al,(%rsi)
  2f:	23 00                	and    (%rax),%eax
  31:	00 00                	add    %al,(%rax)
  33:	02 d1                	add    %cl,%dl
  35:	17                   	(bad)  
  36:	3a 00                	cmp    (%rax),%al
  38:	00 00                	add    %al,(%rax)
  3a:	02 08                	add    (%rax),%cl
  3c:	07                   	(bad)  
  3d:	46 00 00             	rex.RX add %r8b,(%rax)
  40:	00 02                	add    %al,(%rdx)
  42:	04 07                	add    $0x7,%al
  44:	4b 00 00             	rex.WXB add %al,(%r8)
  47:	00 0e                	add    %cl,(%rsi)
  49:	08 02                	or     %al,(%rdx)
  4b:	01 08                	add    %ecx,(%rax)
  4d:	01 02                	add    %eax,(%rdx)
  4f:	00 00                	add    %al,(%rax)
  51:	02 02                	add    (%rdx),%al
  53:	07                   	(bad)  
  54:	9b                   	fwait
  55:	01 00                	add    %eax,(%rax)
  57:	00 02                	add    %al,(%rdx)
  59:	01 06                	add    %eax,(%rsi)
  5b:	03 02                	add    (%rdx),%eax
  5d:	00 00                	add    %al,(%rax)
  5f:	02 02                	add    (%rdx),%al
  61:	05 0f 02 00 00       	add    $0x20f,%eax
  66:	0f 04                	(bad)  
  68:	05 69 6e 74 00       	add    $0x746e69,%eax
  6d:	02 08                	add    (%rax),%cl
  6f:	05 67 00 00 00       	add    $0x67,%eax
  74:	06                   	(bad)  
  75:	07                   	(bad)  
  76:	00 00                	add    %al,(%rax)
  78:	00 03                	add    %al,(%rbx)
  7a:	98                   	cwtl   
  7b:	19 6d 00             	sbb    %ebp,0x0(%rbp)
  7e:	00 00                	add    %al,(%rax)
  80:	06                   	(bad)  
  81:	41 02 00             	add    (%r8),%al
  84:	00 03                	add    %al,(%rbx)
  86:	99                   	cltd   
  87:	1b 6d 00             	sbb    0x0(%rbp),%ebp
  8a:	00 00                	add    %al,(%rax)
  8c:	04 91                	add    $0x91,%al
  8e:	00 00                	add    %al,(%rax)
  90:	00 02                	add    %al,(%rdx)
  92:	01 06                	add    %eax,(%rsi)
  94:	0a 02                	or     (%rdx),%al
  96:	00 00                	add    %al,(%rax)
  98:	10 91 00 00 00 11    	adc    %dl,0x11000000(%rcx)
  9e:	e9 01 00 00 d8       	jmp    ffffffffd80000a4 <_end+0xffffffffd7ffa334>
  a3:	04 31                	add    $0x31,%al
  a5:	08 07                	or     %al,(%rdi)
  a7:	02 00                	add    (%rax),%al
  a9:	00 01                	add    %al,(%rcx)
  ab:	21 01                	and    %eax,(%rcx)
  ad:	00 00                	add    %al,(%rax)
  af:	33 07                	xor    (%rdi),%eax
  b1:	66 00 00             	data16 add %al,(%rax)
  b4:	00 00                	add    %al,(%rax)
  b6:	01 0f                	add    %ecx,(%rdi)
  b8:	00 00                	add    %al,(%rax)
  ba:	00 36                	add    %dh,(%rsi)
  bc:	09 8c 00 00 00 08 01 	or     %ecx,0x1080000(%rax,%rax,1)
  c3:	14 01                	adc    $0x1,%al
  c5:	00 00                	add    %al,(%rax)
  c7:	37                   	(bad)  
  c8:	09 8c 00 00 00 10 01 	or     %ecx,0x1100000(%rax,%rax,1)
  cf:	4b 02 00             	rex.WXB add (%r8),%al
  d2:	00 38                	add    %bh,(%rax)
  d4:	09 8c 00 00 00 18 01 	or     %ecx,0x1180000(%rax,%rax,1)
  db:	d3 02                	roll   %cl,(%rdx)
  dd:	00 00                	add    %al,(%rax)
  df:	39 09                	cmp    %ecx,(%rcx)
  e1:	8c 00                	mov    %es,(%rax)
  e3:	00 00                	add    %al,(%rax)
  e5:	20 01                	and    %al,(%rcx)
  e7:	8d 01                	lea    (%rcx),%eax
  e9:	00 00                	add    %al,(%rax)
  eb:	3a 09                	cmp    (%rcx),%cl
  ed:	8c 00                	mov    %es,(%rax)
  ef:	00 00                	add    %al,(%rax)
  f1:	28 01                	sub    %al,(%rcx)
  f3:	d0 01                	rolb   (%rcx)
  f5:	00 00                	add    %al,(%rax)
  f7:	3b 09                	cmp    (%rcx),%ecx
  f9:	8c 00                	mov    %es,(%rax)
  fb:	00 00                	add    %al,(%rax)
  fd:	30 01                	xor    %al,(%rcx)
  ff:	34 00                	xor    $0x0,%al
 101:	00 00                	add    %al,(%rax)
 103:	3c 09                	cmp    $0x9,%al
 105:	8c 00                	mov    %es,(%rax)
 107:	00 00                	add    %al,(%rax)
 109:	38 01                	cmp    %al,(%rcx)
 10b:	28 01                	sub    %al,(%rcx)
 10d:	00 00                	add    %al,(%rax)
 10f:	3d 09 8c 00 00       	cmp    $0x8c09,%eax
 114:	00 40 01             	add    %al,0x1(%rax)
 117:	ae                   	scas   %es:(%rdi),%al
 118:	01 00                	add    %eax,(%rax)
 11a:	00 40 09             	add    %al,0x9(%rax)
 11d:	8c 00                	mov    %es,(%rax)
 11f:	00 00                	add    %al,(%rax)
 121:	48 01 ab 02 00 00 41 	add    %rbp,0x41000002(%rbx)
 128:	09 8c 00 00 00 50 01 	or     %ecx,0x1500000(%rax,%rax,1)
 12f:	59                   	pop    %rcx
 130:	02 00                	add    (%rax),%al
 132:	00 42 09             	add    %al,0x9(%rdx)
 135:	8c 00                	mov    %es,(%rax)
 137:	00 00                	add    %al,(%rax)
 139:	58                   	pop    %rax
 13a:	01 f8                	add    %edi,%eax
 13c:	01 00                	add    %eax,(%rax)
 13e:	00 44 16 20          	add    %al,0x20(%rsi,%rdx,1)
 142:	02 00                	add    (%rax),%al
 144:	00 60 01             	add    %ah,0x1(%rax)
 147:	1c 00                	sbb    $0x0,%al
 149:	00 00                	add    %al,(%rax)
 14b:	46 14 25             	rex.RX adc $0x25,%al
 14e:	02 00                	add    (%rax),%al
 150:	00 68 01             	add    %ch,0x1(%rax)
 153:	7e 00                	jle    155 <__abi_tag-0x237>
 155:	00 00                	add    %al,(%rax)
 157:	48 07                	rex.W (bad) 
 159:	66 00 00             	data16 add %al,(%rax)
 15c:	00 70 01             	add    %dh,0x1(%rax)
 15f:	c2 01 00             	ret    $0x1
 162:	00 49 07             	add    %cl,0x7(%rcx)
 165:	66 00 00             	data16 add %al,(%rax)
 168:	00 74 01 4c          	add    %dh,0x4c(%rcx,%rax,1)
 16c:	01 00                	add    %eax,(%rax)
 16e:	00 4a 0b             	add    %cl,0xb(%rdx)
 171:	74 00                	je     173 <__abi_tag-0x219>
 173:	00 00                	add    %al,(%rax)
 175:	78 01                	js     178 <__abi_tag-0x214>
 177:	34 01                	xor    $0x1,%al
 179:	00 00                	add    %al,(%rax)
 17b:	4d 12 51 00          	rex.WRB adc 0x0(%r9),%r10b
 17f:	00 00                	add    %al,(%rax)
 181:	80 01 27             	addb   $0x27,(%rcx)
 184:	02 00                	add    (%rax),%al
 186:	00 4e 0f             	add    %cl,0xf(%rsi)
 189:	58                   	pop    %rax
 18a:	00 00                	add    %al,(%rax)
 18c:	00 82 01 2a 00 00    	add    %al,0x2a01(%rdx)
 192:	00 4f 08             	add    %cl,0x8(%rdi)
 195:	2a 02                	sub    (%rdx),%al
 197:	00 00                	add    %al,(%rax)
 199:	83 01 bc             	addl   $0xffffffbc,(%rcx)
 19c:	01 00                	add    %eax,(%rax)
 19e:	00 51 0f             	add    %dl,0xf(%rcx)
 1a1:	3a 02                	cmp    (%rdx),%al
 1a3:	00 00                	add    %al,(%rax)
 1a5:	88 01                	mov    %al,(%rcx)
 1a7:	50                   	push   %rax
 1a8:	01 00                	add    %eax,(%rax)
 1aa:	00 59 0d             	add    %bl,0xd(%rcx)
 1ad:	80 00 00             	addb   $0x0,(%rax)
 1b0:	00 90 01 43 01 00    	add    %dl,0x14301(%rax)
 1b6:	00 5b 17             	add    %bl,0x17(%rbx)
 1b9:	44 02 00             	add    (%rax),%r8b
 1bc:	00 98 01 1c 02 00    	add    %bl,0x21c01(%rax)
 1c2:	00 5c 19 4e          	add    %bl,0x4e(%rcx,%rbx,1)
 1c6:	02 00                	add    (%rax),%al
 1c8:	00 a0 01 c0 02 00    	add    %ah,0x2c001(%rax)
 1ce:	00 5d 14             	add    %bl,0x14(%rbp)
 1d1:	25 02 00 00 a8       	and    $0xa8000002,%eax
 1d6:	01 80 01 00 00 5e    	add    %eax,0x5e000001(%rax)
 1dc:	09 48 00             	or     %ecx,0x0(%rax)
 1df:	00 00                	add    %al,(%rax)
 1e1:	b0 01                	mov    $0x1,%al
 1e3:	66 02 00             	data16 add (%rax),%al
 1e6:	00 5f 0a             	add    %bl,0xa(%rdi)
 1e9:	2e 00 00             	cs add %al,(%rax)
 1ec:	00 b8 01 ca 01 00    	add    %bh,0x1ca01(%rax)
 1f2:	00 60 07             	add    %ah,0x7(%rax)
 1f5:	66 00 00             	data16 add %al,(%rax)
 1f8:	00 c0                	add    %al,%al
 1fa:	01 6d 02             	add    %ebp,0x2(%rbp)
 1fd:	00 00                	add    %al,(%rax)
 1ff:	62                   	(bad)  
 200:	08 53 02             	or     %dl,0x2(%rbx)
 203:	00 00                	add    %al,(%rax)
 205:	c4                   	(bad)  
 206:	00 06                	add    %al,(%rsi)
 208:	ed                   	in     (%dx),%eax
 209:	01 00                	add    %eax,(%rax)
 20b:	00 05 07 19 9d 00    	add    %al,0x9d1907(%rip)        # 9d1b18 <_end+0x9cbda8>
 211:	00 00                	add    %al,(%rax)
 213:	12 de                	adc    %dh,%bl
 215:	01 00                	add    %eax,(%rax)
 217:	00 04 2b             	add    %al,(%rbx,%rbp,1)
 21a:	0e                   	(bad)  
 21b:	07                   	(bad)  
 21c:	6f                   	outsl  %ds:(%rsi),(%dx)
 21d:	01 00                	add    %eax,(%rax)
 21f:	00 04 1b             	add    %al,(%rbx,%rbx,1)
 222:	02 00                	add    (%rax),%al
 224:	00 04 9d 00 00 00 08 	add    %al,0x8000000(,%rbx,4)
 22b:	91                   	xchg   %eax,%ecx
 22c:	00 00                	add    %al,(%rax)
 22e:	00 3a                	add    %bh,(%rdx)
 230:	02 00                	add    (%rax),%al
 232:	00 09                	add    %cl,(%rcx)
 234:	3a 00                	cmp    (%rax),%al
 236:	00 00                	add    %al,(%rax)
 238:	00 00                	add    %al,(%rax)
 23a:	04 13                	add    $0x13,%al
 23c:	02 00                	add    (%rax),%al
 23e:	00 07                	add    %al,(%rdi)
 240:	40 01 00             	rex add %eax,(%rax)
 243:	00 04 3f             	add    %al,(%rdi,%rdi,1)
 246:	02 00                	add    (%rax),%al
 248:	00 07                	add    %al,(%rdi)
 24a:	19 02                	sbb    %eax,(%rdx)
 24c:	00 00                	add    %al,(%rax)
 24e:	04 49                	add    $0x49,%al
 250:	02 00                	add    (%rax),%al
 252:	00 08                	add    %cl,(%rax)
 254:	91                   	xchg   %eax,%ecx
 255:	00 00                	add    %al,(%rax)
 257:	00 63 02             	add    %ah,0x2(%rbx)
 25a:	00 00                	add    %al,(%rax)
 25c:	09 3a                	or     %edi,(%rdx)
 25e:	00 00                	add    %al,(%rax)
 260:	00 13                	add    %dl,(%rbx)
 262:	00 13                	add    %dl,(%rbx)
 264:	7a 01                	jp     267 <__abi_tag-0x125>
 266:	00 00                	add    %al,(%rax)
 268:	06                   	(bad)  
 269:	8f                   	(bad)  
 26a:	0e                   	(bad)  
 26b:	6f                   	outsl  %ds:(%rsi),(%dx)
 26c:	02 00                	add    (%rax),%al
 26e:	00 04 07             	add    %al,(%rdi,%rax,1)
 271:	02 00                	add    (%rax),%al
 273:	00 02                	add    %al,(%rdx)
 275:	08 05 62 00 00 00    	or     %al,0x62(%rip)        # 2dd <__abi_tag-0xaf>
 27b:	02 08                	add    (%rax),%cl
 27d:	07                   	(bad)  
 27e:	41 00 00             	add    %al,(%r8)
 281:	00 14 58             	add    %dl,(%rax,%rbx,2)
 284:	01 00                	add    %eax,(%rax)
 286:	00 01                	add    %al,(%rcx)
 288:	22 07                	and    (%rdi),%al
 28a:	6f                   	outsl  %ds:(%rsi),(%dx)
 28b:	02 00                	add    (%rax),%al
 28d:	00 09                	add    %cl,(%rcx)
 28f:	03 a0 56 00 00 00    	add    0x56(%rax),%esp
 295:	00 00                	add    %al,(%rax)
 297:	00 05 a3 02 00 00    	add    %al,0x2a3(%rip)        # 540 <__abi_tag+0x1b4>
 29d:	09 a8 02 00 00 03    	or     %ebp,0x3000002(%rax)
 2a3:	8c 00                	mov    %es,(%rax)
 2a5:	00 00                	add    %al,(%rax)
 2a7:	00 05 9b 02 00 00    	add    %al,0x29b(%rip)        # 548 <__abi_tag+0x1bc>
 2ad:	08 b8 02 00 00 03    	or     %bh,0x3000002(%rax)
 2b3:	8c 00                	mov    %es,(%rax)
 2b5:	00 00                	add    %al,(%rax)
 2b7:	00 05 93 02 00 00    	add    %al,0x293(%rip)        # 550 <__abi_tag+0x1c4>
 2bd:	07                   	(bad)  
 2be:	c8 02 00 00          	enter  $0x2,$0x0
 2c2:	03 8c 00 00 00 00 05 	add    0x5000000(%rax,%rax,1),%ecx
 2c9:	8b 02                	mov    (%rdx),%eax
 2cb:	00 00                	add    %al,(%rax)
 2cd:	06                   	(bad)  
 2ce:	d8 02                	fadds  (%rdx)
 2d0:	00 00                	add    %al,(%rax)
 2d2:	03 8c 00 00 00 00 05 	add    0x5000000(%rax,%rax,1),%ecx
 2d9:	83 02 00             	addl   $0x0,(%rdx)
 2dc:	00 05 e8 02 00 00    	add    %al,0x2e8(%rip)        # 5ca <__abi_tag+0x23e>
 2e2:	03 8c 00 00 00 00 0a 	add    0xa000000(%rax,%rax,1),%ecx
 2e9:	70 00                	jo     2eb <__abi_tag-0xa1>
 2eb:	00 00                	add    %al,(%rax)
 2ed:	0c 05                	or     $0x5,%al
 2ef:	7b 02                	jnp    2f3 <__abi_tag-0x99>
 2f1:	00 00                	add    %al,(%rax)
 2f3:	04 fe                	add    $0xfe,%al
 2f5:	02 00                	add    (%rax),%al
 2f7:	00 03                	add    %al,(%rbx)
 2f9:	8c 00                	mov    %es,(%rax)
 2fb:	00 00                	add    %al,(%rax)
 2fd:	00 15 58 00 00 00    	add    %dl,0x58(%rip)        # 35b <__abi_tag-0x31>
 303:	08 08                	or     %cl,(%rax)
 305:	07                   	(bad)  
 306:	8c 00                	mov    %es,(%rax)
 308:	00 00                	add    %al,(%rax)
 30a:	0a 5f 01             	or     0x1(%rdi),%bl
 30d:	00 00                	add    %al,(%rax)
 30f:	09 16                	or     %edx,(%rsi)
 311:	36 02 00             	ss add (%rax),%al
 314:	00 09                	add    %cl,(%rcx)
 316:	70 02                	jo     31a <__abi_tag-0x72>
 318:	0d 23 03 00 00       	or     $0x323,%eax
 31d:	03 66 00             	add    0x0(%rsi),%esp
 320:	00 00                	add    %al,(%rax)
 322:	00 0b                	add    %cl,(%rbx)
 324:	00 00                	add    %al,(%rax)
 326:	00 00                	add    %al,(%rax)
 328:	64 01 0c 66          	add    %ecx,%fs:(%rsi,%riz,2)
 32c:	00 00                	add    %al,(%rax)
 32e:	00 3a                	add    %bh,(%rdx)
 330:	03 00                	add    (%rax),%eax
 332:	00 03                	add    %al,(%rbx)
 334:	3a 03                	cmp    (%rbx),%al
 336:	00 00                	add    %al,(%rax)
 338:	17                   	(bad)  
 339:	00 04 98             	add    %al,(%rax,%rbx,4)
 33c:	00 00                	add    %al,(%rax)
 33e:	00 18                	add    %bl,(%rax)
 340:	3a 03                	cmp    (%rbx),%al
 342:	00 00                	add    %al,(%rax)
 344:	0b f2                	or     %edx,%esi
 346:	01 00                	add    %eax,(%rax)
 348:	00 02                	add    %al,(%rdx)
 34a:	01 0e                	add    %ecx,(%rsi)
 34c:	6f                   	outsl  %ds:(%rsi),(%dx)
 34d:	02 00                	add    (%rax),%al
 34f:	00 5f 03             	add    %bl,0x3(%rdi)
 352:	00 00                	add    %al,(%rax)
 354:	03 3f                	add    (%rdi),%edi
 356:	03 00                	add    (%rax),%eax
 358:	00 03                	add    %al,(%rbx)
 35a:	3f                   	(bad)  
 35b:	03 00                	add    (%rax),%eax
 35d:	00 00                	add    %al,(%rax)
 35f:	19 ce                	sbb    %ecx,%esi
 361:	02 00                	add    (%rax),%al
 363:	00 01                	add    %al,(%rcx)
 365:	24 05                	and    $0x5,%al
 367:	66 00 00             	data16 add %al,(%rax)
 36a:	00 e9                	add    %ch,%cl
 36c:	12 00                	adc    (%rax),%al
 36e:	00 00                	add    %al,(%rax)
 370:	00 00                	add    %al,(%rax)
 372:	00 ce                	add    %cl,%dh
 374:	01 00                	add    %eax,(%rax)
 376:	00 00                	add    %al,(%rax)
 378:	00 00                	add    %al,(%rax)
 37a:	00 01                	add    %al,(%rcx)
 37c:	9c                   	pushf  
 37d:	ab                   	stos   %eax,%es:(%rdi)
 37e:	03 00                	add    (%rax),%eax
 380:	00 0c bb             	add    %cl,(%rbx,%rdi,4)
 383:	02 00                	add    (%rax),%al
 385:	00 0e                	add    %cl,(%rsi)
 387:	66 00 00             	data16 add %al,(%rax)
 38a:	00 02                	add    %al,(%rdx)
 38c:	91                   	xchg   %eax,%ecx
 38d:	5c                   	pop    %rsp
 38e:	0c 76                	or     $0x76,%al
 390:	02 00                	add    (%rax),%al
 392:	00 1a                	add    %bl,(%rdx)
 394:	ab                   	stos   %eax,%es:(%rdi)
 395:	03 00                	add    (%rax),%eax
 397:	00 02                	add    %al,(%rdx)
 399:	91                   	xchg   %eax,%ecx
 39a:	50                   	push   %rax
 39b:	1a 3b                	sbb    (%rbx),%bh
 39d:	02 00                	add    (%rax),%al
 39f:	00 01                	add    %al,(%rcx)
 3a1:	26 0b 8c 00 00 00 02 	es or  -0x6efe0000(%rax,%rax,1),%ecx
 3a8:	91 
 3a9:	68 00 04 8c 00       	push   $0x8c0400
 3ae:	00 00                	add    %al,(%rax)
 3b0:	00 47 07             	add    %al,0x7(%rdi)
 3b3:	00 00                	add    %al,(%rax)
 3b5:	05 00 01 08 87       	add    $0x87080100,%eax
 3ba:	01 00                	add    %eax,(%rax)
 3bc:	00 19                	add    %bl,(%rcx)
 3be:	86 00                	xchg   %al,(%rax)
 3c0:	00 00                	add    %al,(%rax)
 3c2:	1d 2c 01 00 00       	sbb    $0x12c,%eax
 3c7:	00 00                	add    %al,(%rax)
 3c9:	00 00                	add    %al,(%rax)
 3cb:	b7 14                	mov    $0x14,%bh
 3cd:	00 00                	add    %al,(%rax)
 3cf:	00 00                	add    %al,(%rax)
 3d1:	00 00                	add    %al,(%rax)
 3d3:	45 05 00 00 00 00    	rex.RB add $0x0,%eax
 3d9:	00 00                	add    %al,(%rax)
 3db:	e5 00                	in     $0x0,%eax
 3dd:	00 00                	add    %al,(%rax)
 3df:	08 23                	or     %ah,(%rbx)
 3e1:	00 00                	add    %al,(%rax)
 3e3:	00 02                	add    %al,(%rdx)
 3e5:	d1 17                	rcll   (%rdi)
 3e7:	3a 00                	cmp    (%rax),%al
 3e9:	00 00                	add    %al,(%rax)
 3eb:	04 08                	add    $0x8,%al
 3ed:	07                   	(bad)  
 3ee:	46 00 00             	rex.RX add %r8b,(%rax)
 3f1:	00 04 04             	add    %al,(%rsp,%rax,1)
 3f4:	07                   	(bad)  
 3f5:	4b 00 00             	rex.WXB add %al,(%r8)
 3f8:	00 1a                	add    %bl,(%rdx)
 3fa:	08 04 01             	or     %al,(%rcx,%rax,1)
 3fd:	08 01                	or     %al,(%rcx)
 3ff:	02 00                	add    (%rax),%al
 401:	00 04 02             	add    %al,(%rdx,%rax,1)
 404:	07                   	(bad)  
 405:	9b                   	fwait
 406:	01 00                	add    %eax,(%rax)
 408:	00 14 51             	add    %dl,(%rcx,%rdx,2)
 40b:	00 00                	add    %al,(%rax)
 40d:	00 04 01             	add    %al,(%rcx,%rax,1)
 410:	06                   	(bad)  
 411:	03 02                	add    (%rdx),%eax
 413:	00 00                	add    %al,(%rax)
 415:	04 02                	add    $0x2,%al
 417:	05 0f 02 00 00       	add    $0x20f,%eax
 41c:	1b 04 05 69 6e 74 00 	sbb    0x746e69(,%rax,1),%eax
 423:	04 08                	add    $0x8,%al
 425:	05 67 00 00 00       	add    $0x67,%eax
 42a:	08 07                	or     %al,(%rdi)
 42c:	00 00                	add    %al,(%rax)
 42e:	00 03                	add    %al,(%rbx)
 430:	98                   	cwtl   
 431:	19 72 00             	sbb    %esi,0x0(%rdx)
 434:	00 00                	add    %al,(%rax)
 436:	08 41 02             	or     %al,0x2(%rcx)
 439:	00 00                	add    %al,(%rax)
 43b:	03 99 1b 72 00 00    	add    0x721b(%rcx),%ebx
 441:	00 03                	add    %al,(%rbx)
 443:	9b                   	fwait
 444:	00 00                	add    %al,(%rax)
 446:	00 15 91 00 00 00    	add    %dl,0x91(%rip)        # 4dd <__abi_tag+0x151>
 44c:	04 01                	add    $0x1,%al
 44e:	06                   	(bad)  
 44f:	0a 02                	or     (%rdx),%al
 451:	00 00                	add    %al,(%rax)
 453:	14 9b                	adc    $0x9b,%al
 455:	00 00                	add    %al,(%rax)
 457:	00 1c e9             	add    %bl,(%rcx,%rbp,8)
 45a:	01 00                	add    %eax,(%rax)
 45c:	00 d8                	add    %bl,%al
 45e:	04 31                	add    $0x31,%al
 460:	08 11                	or     %dl,(%rcx)
 462:	02 00                	add    (%rax),%al
 464:	00 01                	add    %al,(%rcx)
 466:	21 01                	and    %eax,(%rcx)
 468:	00 00                	add    %al,(%rax)
 46a:	33 07                	xor    (%rdi),%eax
 46c:	6b 00 00             	imul   $0x0,(%rax),%eax
 46f:	00 00                	add    %al,(%rax)
 471:	01 0f                	add    %ecx,(%rdi)
 473:	00 00                	add    %al,(%rax)
 475:	00 36                	add    %dh,(%rsi)
 477:	09 91 00 00 00 08    	or     %edx,0x8000000(%rcx)
 47d:	01 14 01             	add    %edx,(%rcx,%rax,1)
 480:	00 00                	add    %al,(%rax)
 482:	37                   	(bad)  
 483:	09 91 00 00 00 10    	or     %edx,0x10000000(%rcx)
 489:	01 4b 02             	add    %ecx,0x2(%rbx)
 48c:	00 00                	add    %al,(%rax)
 48e:	38 09                	cmp    %cl,(%rcx)
 490:	91                   	xchg   %eax,%ecx
 491:	00 00                	add    %al,(%rax)
 493:	00 18                	add    %bl,(%rax)
 495:	01 d3                	add    %edx,%ebx
 497:	02 00                	add    (%rax),%al
 499:	00 39                	add    %bh,(%rcx)
 49b:	09 91 00 00 00 20    	or     %edx,0x20000000(%rcx)
 4a1:	01 8d 01 00 00 3a    	add    %ecx,0x3a000001(%rbp)
 4a7:	09 91 00 00 00 28    	or     %edx,0x28000000(%rcx)
 4ad:	01 d0                	add    %edx,%eax
 4af:	01 00                	add    %eax,(%rax)
 4b1:	00 3b                	add    %bh,(%rbx)
 4b3:	09 91 00 00 00 30    	or     %edx,0x30000000(%rcx)
 4b9:	01 34 00             	add    %esi,(%rax,%rax,1)
 4bc:	00 00                	add    %al,(%rax)
 4be:	3c 09                	cmp    $0x9,%al
 4c0:	91                   	xchg   %eax,%ecx
 4c1:	00 00                	add    %al,(%rax)
 4c3:	00 38                	add    %bh,(%rax)
 4c5:	01 28                	add    %ebp,(%rax)
 4c7:	01 00                	add    %eax,(%rax)
 4c9:	00 3d 09 91 00 00    	add    %bh,0x9109(%rip)        # 95d8 <_end+0x3868>
 4cf:	00 40 01             	add    %al,0x1(%rax)
 4d2:	ae                   	scas   %es:(%rdi),%al
 4d3:	01 00                	add    %eax,(%rax)
 4d5:	00 40 09             	add    %al,0x9(%rax)
 4d8:	91                   	xchg   %eax,%ecx
 4d9:	00 00                	add    %al,(%rax)
 4db:	00 48 01             	add    %cl,0x1(%rax)
 4de:	ab                   	stos   %eax,%es:(%rdi)
 4df:	02 00                	add    (%rax),%al
 4e1:	00 41 09             	add    %al,0x9(%rcx)
 4e4:	91                   	xchg   %eax,%ecx
 4e5:	00 00                	add    %al,(%rax)
 4e7:	00 50 01             	add    %dl,0x1(%rax)
 4ea:	59                   	pop    %rcx
 4eb:	02 00                	add    (%rax),%al
 4ed:	00 42 09             	add    %al,0x9(%rdx)
 4f0:	91                   	xchg   %eax,%ecx
 4f1:	00 00                	add    %al,(%rax)
 4f3:	00 58 01             	add    %bl,0x1(%rax)
 4f6:	f8                   	clc    
 4f7:	01 00                	add    %eax,(%rax)
 4f9:	00 44 16 2a          	add    %al,0x2a(%rsi,%rdx,1)
 4fd:	02 00                	add    (%rax),%al
 4ff:	00 60 01             	add    %ah,0x1(%rax)
 502:	1c 00                	sbb    $0x0,%al
 504:	00 00                	add    %al,(%rax)
 506:	46 14 2f             	rex.RX adc $0x2f,%al
 509:	02 00                	add    (%rax),%al
 50b:	00 68 01             	add    %ch,0x1(%rax)
 50e:	7e 00                	jle    510 <__abi_tag+0x184>
 510:	00 00                	add    %al,(%rax)
 512:	48 07                	rex.W (bad) 
 514:	6b 00 00             	imul   $0x0,(%rax),%eax
 517:	00 70 01             	add    %dh,0x1(%rax)
 51a:	c2 01 00             	ret    $0x1
 51d:	00 49 07             	add    %cl,0x7(%rcx)
 520:	6b 00 00             	imul   $0x0,(%rax),%eax
 523:	00 74 01 4c          	add    %dh,0x4c(%rcx,%rax,1)
 527:	01 00                	add    %eax,(%rax)
 529:	00 4a 0b             	add    %cl,0xb(%rdx)
 52c:	79 00                	jns    52e <__abi_tag+0x1a2>
 52e:	00 00                	add    %al,(%rax)
 530:	78 01                	js     533 <__abi_tag+0x1a7>
 532:	34 01                	xor    $0x1,%al
 534:	00 00                	add    %al,(%rax)
 536:	4d 12 51 00          	rex.WRB adc 0x0(%r9),%r10b
 53a:	00 00                	add    %al,(%rax)
 53c:	80 01 27             	addb   $0x27,(%rcx)
 53f:	02 00                	add    (%rax),%al
 541:	00 4e 0f             	add    %cl,0xf(%rsi)
 544:	5d                   	pop    %rbp
 545:	00 00                	add    %al,(%rax)
 547:	00 82 01 2a 00 00    	add    %al,0x2a01(%rdx)
 54d:	00 4f 08             	add    %cl,0x8(%rdi)
 550:	34 02                	xor    $0x2,%al
 552:	00 00                	add    %al,(%rax)
 554:	83 01 bc             	addl   $0xffffffbc,(%rcx)
 557:	01 00                	add    %eax,(%rax)
 559:	00 51 0f             	add    %dl,0xf(%rcx)
 55c:	44 02 00             	add    (%rax),%r8b
 55f:	00 88 01 50 01 00    	add    %cl,0x15001(%rax)
 565:	00 59 0d             	add    %bl,0xd(%rcx)
 568:	85 00                	test   %eax,(%rax)
 56a:	00 00                	add    %al,(%rax)
 56c:	90                   	nop
 56d:	01 43 01             	add    %eax,0x1(%rbx)
 570:	00 00                	add    %al,(%rax)
 572:	5b                   	pop    %rbx
 573:	17                   	(bad)  
 574:	4e 02 00             	rex.WRX add (%rax),%r8b
 577:	00 98 01 1c 02 00    	add    %bl,0x21c01(%rax)
 57d:	00 5c 19 58          	add    %bl,0x58(%rcx,%rbx,1)
 581:	02 00                	add    (%rax),%al
 583:	00 a0 01 c0 02 00    	add    %ah,0x2c001(%rax)
 589:	00 5d 14             	add    %bl,0x14(%rbp)
 58c:	2f                   	(bad)  
 58d:	02 00                	add    (%rax),%al
 58f:	00 a8 01 80 01 00    	add    %ch,0x18001(%rax)
 595:	00 5e 09             	add    %bl,0x9(%rsi)
 598:	48 00 00             	rex.W add %al,(%rax)
 59b:	00 b0 01 66 02 00    	add    %dh,0x26601(%rax)
 5a1:	00 5f 0a             	add    %bl,0xa(%rdi)
 5a4:	2e 00 00             	cs add %al,(%rax)
 5a7:	00 b8 01 ca 01 00    	add    %bh,0x1ca01(%rax)
 5ad:	00 60 07             	add    %ah,0x7(%rax)
 5b0:	6b 00 00             	imul   $0x0,(%rax),%eax
 5b3:	00 c0                	add    %al,%al
 5b5:	01 6d 02             	add    %ebp,0x2(%rbp)
 5b8:	00 00                	add    %al,(%rax)
 5ba:	62                   	(bad)  
 5bb:	08 5d 02             	or     %bl,0x2(%rbp)
 5be:	00 00                	add    %al,(%rax)
 5c0:	c4                   	(bad)  
 5c1:	00 08                	add    %cl,(%rax)
 5c3:	ed                   	in     (%dx),%eax
 5c4:	01 00                	add    %eax,(%rax)
 5c6:	00 05 07 19 a7 00    	add    %al,0xa71907(%rip)        # a71ed3 <_end+0xa6c163>
 5cc:	00 00                	add    %al,(%rax)
 5ce:	1d de 01 00 00       	sbb    $0x1de,%eax
 5d3:	04 2b                	add    $0x2b,%al
 5d5:	0e                   	(bad)  
 5d6:	0f 6f 01             	movq   (%rcx),%mm0
 5d9:	00 00                	add    %al,(%rax)
 5db:	03 25 02 00 00 03    	add    0x3000002(%rip),%esp        # 30005e3 <_end+0x2ffa873>
 5e1:	a7                   	cmpsl  %es:(%rdi),%ds:(%rsi)
 5e2:	00 00                	add    %al,(%rax)
 5e4:	00 09                	add    %cl,(%rcx)
 5e6:	9b                   	fwait
 5e7:	00 00                	add    %al,(%rax)
 5e9:	00 44 02 00          	add    %al,0x0(%rdx,%rax,1)
 5ed:	00 06                	add    %al,(%rsi)
 5ef:	3a 00                	cmp    (%rax),%al
 5f1:	00 00                	add    %al,(%rax)
 5f3:	00 00                	add    %al,(%rax)
 5f5:	03 1d 02 00 00 0f    	add    0xf000002(%rip),%ebx        # f0005fd <_end+0xeffa88d>
 5fb:	40 01 00             	rex add %eax,(%rax)
 5fe:	00 03                	add    %al,(%rbx)
 600:	49 02 00             	rex.WB add (%r8),%al
 603:	00 0f                	add    %cl,(%rdi)
 605:	19 02                	sbb    %eax,(%rdx)
 607:	00 00                	add    %al,(%rax)
 609:	03 53 02             	add    0x2(%rbx),%edx
 60c:	00 00                	add    %al,(%rax)
 60e:	09 9b 00 00 00 6d    	or     %ebx,0x6d000000(%rbx)
 614:	02 00                	add    (%rax),%al
 616:	00 06                	add    %al,(%rsi)
 618:	3a 00                	cmp    (%rax),%al
 61a:	00 00                	add    %al,(%rax)
 61c:	13 00                	adc    (%rax),%eax
 61e:	10 7a 01             	adc    %bh,0x1(%rdx)
 621:	00 00                	add    %al,(%rax)
 623:	06                   	(bad)  
 624:	8f                   	(bad)  
 625:	78 02                	js     629 <__abi_tag+0x29d>
 627:	00 00                	add    %al,(%rax)
 629:	03 11                	add    (%rcx),%edx
 62b:	02 00                	add    (%rax),%al
 62d:	00 15 78 02 00 00    	add    %dl,0x278(%rip)        # 8ab <__abi_tag+0x51f>
 633:	10 7e 04             	adc    %bh,0x4(%rsi)
 636:	00 00                	add    %al,(%rax)
 638:	06                   	(bad)  
 639:	90                   	nop
 63a:	78 02                	js     63e <__abi_tag+0x2b2>
 63c:	00 00                	add    %al,(%rax)
 63e:	04 08                	add    $0x8,%al
 640:	05 62 00 00 00       	add    $0x62,%eax
 645:	04 08                	add    $0x8,%al
 647:	07                   	(bad)  
 648:	41 00 00             	add    %al,(%r8)
 64b:	00 03                	add    %al,(%rbx)
 64d:	58                   	pop    %rax
 64e:	00 00                	add    %al,(%rax)
 650:	00 03                	add    %al,(%rbx)
 652:	a2 00 00 00 1e 07 04 	movabs %al,0x4104071e000000
 659:	41 00 
 65b:	00 00                	add    %al,(%rax)
 65d:	0c 2f                	or     $0x2f,%al
 65f:	01 04 03             	add    %eax,(%rbx,%rax,1)
 662:	00 00                	add    %al,(%rax)
 664:	05 56 04 00 00       	add    $0x456,%eax
 669:	00 01                	add    %al,(%rcx)
 66b:	05 e1 03 00 00       	add    $0x3e1,%eax
 670:	00 02                	add    %al,(%rdx)
 672:	05 75 04 00 00       	add    $0x475,%eax
 677:	00 04 05 40 03 00 00 	add    %al,0x340(,%rax,1)
 67e:	00 08                	add    %cl,(%rax)
 680:	05 ba 03 00 00       	add    $0x3ba,%eax
 685:	00 10                	add    %dl,(%rax)
 687:	05 87 03 00 00       	add    $0x387,%eax
 68c:	00 20                	add    %ah,(%rax)
 68e:	05 4d 04 00 00       	add    $0x44d,%eax
 693:	00 40 05             	add    %al,0x5(%rax)
 696:	06                   	(bad)  
 697:	03 00                	add    (%rax),%eax
 699:	00 00                	add    %al,(%rax)
 69b:	80 0c 75 03 00 00 01 	orb    $0xc,0x1000003(,%rsi,2)
 6a2:	0c 
 6a3:	e2 02                	loop   6a7 <__abi_tag+0x31b>
 6a5:	00 00                	add    %al,(%rax)
 6a7:	02 0c fd 02 00 00 04 	add    0x4000002(,%rdi,8),%cl
 6ae:	0c 7e                	or     $0x7e,%al
 6b0:	03 00                	add    (%rax),%eax
 6b2:	00 08                	add    %cl,(%rax)
 6b4:	00 08                	add    %cl,(%rax)
 6b6:	ab                   	stos   %eax,%es:(%rdi)
 6b7:	03 00                	add    (%rax),%eax
 6b9:	00 07                	add    %al,(%rdi)
 6bb:	48 10 10             	rex.W adc %dl,(%rax)
 6be:	03 00                	add    (%rax),%eax
 6c0:	00 03                	add    %al,(%rbx)
 6c2:	15 03 00 00 1f       	adc    $0x1f000003,%eax
 6c7:	20 03                	and    %al,(%rbx)
 6c9:	00 00                	add    %al,(%rax)
 6cb:	02 6b 00             	add    0x0(%rbx),%ch
 6ce:	00 00                	add    %al,(%rax)
 6d0:	00 09                	add    %cl,(%rcx)
 6d2:	91                   	xchg   %eax,%ecx
 6d3:	00 00                	add    %al,(%rax)
 6d5:	00 30                	add    %dh,(%rax)
 6d7:	03 00                	add    (%rax),%eax
 6d9:	00 06                	add    %al,(%rsi)
 6db:	3a 00                	cmp    (%rax),%al
 6dd:	00 00                	add    %al,(%rax)
 6df:	7f 00                	jg     6e1 <__abi_tag+0x355>
 6e1:	0d a0 03 00 00       	or     $0x3a0,%eax
 6e6:	08 0c 07             	or     %cl,(%rdi,%rax,1)
 6e9:	20 03                	and    %al,(%rbx)
 6eb:	00 00                	add    %al,(%rax)
 6ed:	09 03                	or     %eax,(%rbx)
 6ef:	20 50 00             	and    %dl,0x0(%rax)
 6f2:	00 00                	add    %al,(%rax)
 6f4:	00 00                	add    %al,(%rax)
 6f6:	00 10                	add    %dl,(%rax)
 6f8:	58                   	pop    %rax
 6f9:	01 00                	add    %eax,(%rax)
 6fb:	00 01                	add    %al,(%rcx)
 6fd:	21 78 02             	and    %edi,0x2(%rax)
 700:	00 00                	add    %al,(%rax)
 702:	09 9b 00 00 00 67    	or     %ebx,0x67000000(%rbx)
 708:	03 00                	add    (%rax),%eax
 70a:	00 06                	add    %al,(%rsi)
 70c:	3a 00                	cmp    (%rax),%al
 70e:	00 00                	add    %al,(%rax)
 710:	13 06                	adc    (%rsi),%eax
 712:	3a 00                	cmp    (%rax),%al
 714:	00 00                	add    %al,(%rax)
 716:	4f 00 0d 5a 03 00 00 	rex.WRXB add %r9b,0x35a(%rip)        # a77 <__abi_tag+0x6eb>
 71d:	01 24 06             	add    %esp,(%rsi,%rax,1)
 720:	51                   	push   %rcx
 721:	03 00                	add    (%rax),%eax
 723:	00 09                	add    %cl,(%rcx)
 725:	03 c0                	add    %eax,%eax
 727:	56                   	push   %rsi
 728:	00 00                	add    %al,(%rax)
 72a:	00 00                	add    %al,(%rax)
 72c:	00 00                	add    %al,(%rax)
 72e:	0d 56 03 00 00       	or     $0x356,%eax
 733:	01 25 05 6b 00 00    	add    %esp,0x6b05(%rip)        # 723e <_end+0x14ce>
 739:	00 09                	add    %cl,(%rcx)
 73b:	03 00                	add    (%rax),%eax
 73d:	5d                   	pop    %rbp
 73e:	00 00                	add    %al,(%rax)
 740:	00 00                	add    %al,(%rax)
 742:	00 00                	add    %al,(%rax)
 744:	09 9b 00 00 00 a3    	or     %ebx,-0x5d000000(%rbx)
 74a:	03 00                	add    (%rax),%eax
 74c:	00 06                	add    %al,(%rsi)
 74e:	3a 00                	cmp    (%rax),%al
 750:	00 00                	add    %al,(%rax)
 752:	4f 00 0d 98 03 00 00 	rex.WRXB add %r9b,0x398(%rip)        # af1 <__abi_tag+0x765>
 759:	01 28                	add    %ebp,(%rax)
 75b:	06                   	(bad)  
 75c:	93                   	xchg   %eax,%ebx
 75d:	03 00                	add    (%rax),%eax
 75f:	00 09                	add    %cl,(%rcx)
 761:	03 20                	add    (%rax),%esp
 763:	5d                   	pop    %rbp
 764:	00 00                	add    %al,(%rax)
 766:	00 00                	add    %al,(%rax)
 768:	00 00                	add    %al,(%rax)
 76a:	20 68 03             	and    %ch,0x3(%rax)
 76d:	00 00                	add    %al,(%rax)
 76f:	0d 0f 06 c7 03       	or     $0x3c7060f,%eax
 774:	00 00                	add    %al,(%rax)
 776:	11 00                	adc    %eax,(%rax)
 778:	0a ea                	or     %dl,%ch
 77a:	03 00                	add    (%rax),%eax
 77c:	00 09                	add    %cl,(%rcx)
 77e:	97                   	xchg   %eax,%edi
 77f:	01 0f                	add    %ecx,(%rdi)
 781:	2e 00 00             	cs add %al,(%rax)
 784:	00 de                	add    %bl,%dh
 786:	03 00                	add    (%rax),%eax
 788:	00 02                	add    %al,(%rdx)
 78a:	a0 02 00 00 00 0a 49 	movabs 0x3490a00000002,%al
 791:	03 00 
 793:	00 0a                	add    %cl,(%rdx)
 795:	81 02 0e 91 00 00    	addl   $0x910e,(%rdx)
 79b:	00 f5                	add    %dh,%ch
 79d:	03 00                	add    (%rax),%eax
 79f:	00 02                	add    %al,(%rdx)
 7a1:	a0 02 00 00 00 0a 50 	movabs 0x3500a00000002,%al
 7a8:	03 00 
 7aa:	00 06                	add    %al,(%rsi)
 7ac:	50                   	push   %rax
 7ad:	02 0e                	add    (%rsi),%cl
 7af:	91                   	xchg   %eax,%ecx
 7b0:	00 00                	add    %al,(%rax)
 7b2:	00 16                	add    %dl,(%rsi)
 7b4:	04 00                	add    $0x0,%al
 7b6:	00 02                	add    %al,(%rdx)
 7b8:	96                   	xchg   %eax,%esi
 7b9:	00 00                	add    %al,(%rax)
 7bb:	00 02                	add    %al,(%rdx)
 7bd:	6b 00 00             	imul   $0x0,(%rax),%eax
 7c0:	00 02                	add    %al,(%rdx)
 7c2:	7d 02                	jge    7c6 <__abi_tag+0x43a>
 7c4:	00 00                	add    %al,(%rax)
 7c6:	00 21                	add    %ah,(%rcx)
 7c8:	3f                   	(bad)  
 7c9:	04 00                	add    $0x0,%al
 7cb:	00 0c 4f             	add    %cl,(%rdi,%rcx,2)
 7ce:	23 22                	and    (%rdx),%esp
 7d0:	04 00                	add    $0x0,%al
 7d2:	00 03                	add    %al,(%rbx)
 7d4:	9b                   	fwait
 7d5:	02 00                	add    (%rax),%al
 7d7:	00 16                	add    %dl,(%rsi)
 7d9:	da 03                	fiaddl (%rbx)
 7db:	00 00                	add    %al,(%rax)
 7dd:	07                   	(bad)  
 7de:	58                   	pop    %rax
 7df:	17                   	(bad)  
 7e0:	04 03                	add    $0x3,%al
 7e2:	00 00                	add    %al,(%rax)
 7e4:	42 04 00             	rex.X add $0x0,%al
 7e7:	00 02                	add    %al,(%rdx)
 7e9:	6b 00 00             	imul   $0x0,(%rax),%eax
 7ec:	00 02                	add    %al,(%rdx)
 7ee:	04 03                	add    $0x3,%al
 7f0:	00 00                	add    %al,(%rax)
 7f2:	00 22                	add    %ah,(%rdx)
 7f4:	cd 03                	int    $0x3
 7f6:	00 00                	add    %al,(%rax)
 7f8:	06                   	(bad)  
 7f9:	b7 01                	mov    $0x1,%bh
 7fb:	0c c4                	or     $0xc4,%al
 7fd:	03 00                	add    (%rax),%eax
 7ff:	00 6b 00             	add    %ch,0x0(%rbx)
 802:	00 00                	add    %al,(%rax)
 804:	63 04 00             	movsxd (%rax,%rax,1),%eax
 807:	00 02                	add    %al,(%rdx)
 809:	a0 02 00 00 02 a0 02 	movabs 0x2a002000002,%al
 810:	00 00 
 812:	11 00                	adc    %eax,(%rax)
 814:	23 36                	and    (%rsi),%esi
 816:	02 00                	add    (%rax),%al
 818:	00 0a                	add    %cl,(%rdx)
 81a:	70 02                	jo     81e <__abi_tag+0x492>
 81c:	0d 76 04 00 00       	or     $0x476,%eax
 821:	02 6b 00             	add    0x0(%rbx),%ch
 824:	00 00                	add    %al,(%rax)
 826:	00 16                	add    %dl,(%rsi)
 828:	12 04 00             	adc    (%rax,%rax,1),%al
 82b:	00 06                	add    %al,(%rsi)
 82d:	e6 0c                	out    %al,$0xc
 82f:	6b 00 00             	imul   $0x0,(%rax),%eax
 832:	00 8c 04 00 00 02 78 	add    %cl,0x78020000(%rsp,%rax,1)
 839:	02 00                	add    (%rax),%al
 83b:	00 00                	add    %al,(%rax)
 83d:	0a 00                	or     (%rax),%al
 83f:	00 00                	add    %al,(%rax)
 841:	00 06                	add    %al,(%rsi)
 843:	64 01 0c 6b          	add    %ecx,%fs:(%rbx,%rbp,2)
 847:	00 00                	add    %al,(%rax)
 849:	00 a4 04 00 00 02 a0 	add    %ah,-0x5ffe0000(%rsp,%rax,1)
 850:	02 00                	add    (%rax),%al
 852:	00 11                	add    %dl,(%rcx)
 854:	00 0a                	add    %cl,(%rdx)
 856:	d4                   	(bad)  
 857:	03 00                	add    (%rax),%eax
 859:	00 0b                	add    %cl,(%rbx)
 85b:	d0 01                	rolb   (%rcx)
 85d:	15 41 00 00 00       	adc    $0x41,%eax
 862:	bb 04 00 00 02       	mov    $0x2000004,%ebx
 867:	41 00 00             	add    %al,(%r8)
 86a:	00 00                	add    %al,(%rax)
 86c:	24 70                	and    $0x70,%al
 86e:	00 00                	add    %al,(%rax)
 870:	00 01                	add    %al,(%rcx)
 872:	15 01 06 2e 19       	adc    $0x192e0601,%eax
 877:	00 00                	add    %al,(%rax)
 879:	00 00                	add    %al,(%rax)
 87b:	00 00                	add    %al,(%rax)
 87d:	ce                   	(bad)  
 87e:	00 00                	add    %al,(%rax)
 880:	00 00                	add    %al,(%rax)
 882:	00 00                	add    %al,(%rax)
 884:	00 01                	add    %al,(%rcx)
 886:	9c                   	pushf  
 887:	1b 05 00 00 0e 19    	sbb    0x190e0000(%rip),%eax        # 190e088d <_end+0x190dab1d>
 88d:	04 00                	add    $0x0,%al
 88f:	00 17                	add    %dl,(%rdi)
 891:	01 0a                	add    %ecx,(%rdx)
 893:	93                   	xchg   %eax,%ebx
 894:	03 00                	add    (%rax),%eax
 896:	00 03                	add    %al,(%rbx)
 898:	91                   	xchg   %eax,%ecx
 899:	90                   	nop
 89a:	7f 0e                	jg     8aa <__abi_tag+0x51e>
 89c:	fc                   	cld    
 89d:	03 00                	add    (%rax),%eax
 89f:	00 18                	add    %bl,(%rax)
 8a1:	01 09                	add    %ecx,(%rcx)
 8a3:	6b 00 00             	imul   $0x0,(%rax),%eax
 8a6:	00 03                	add    %al,(%rbx)
 8a8:	91                   	xchg   %eax,%ecx
 8a9:	84 7f 0e             	test   %bh,0xe(%rdi)
 8ac:	01 04 00             	add    %eax,(%rax,%rax,1)
 8af:	00 18                	add    %bl,(%rax)
 8b1:	01 0f                	add    %ecx,(%rdi)
 8b3:	6b 00 00             	imul   $0x0,(%rax),%eax
 8b6:	00 03                	add    %al,(%rbx)
 8b8:	91                   	xchg   %eax,%ecx
 8b9:	88 7f 0e             	mov    %bh,0xe(%rdi)
 8bc:	24 04                	and    $0x4,%al
 8be:	00 00                	add    %al,(%rax)
 8c0:	18 01                	sbb    %al,(%rcx)
 8c2:	15 6b 00 00 00       	adc    $0x6b,%eax
 8c7:	03 91 8c 7f 00 25    	add    0x25007f8c(%rcx),%edx
 8cd:	f0 02 00             	lock add (%rax),%al
 8d0:	00 01                	add    %al,(%rcx)
 8d2:	09 01                	or     %eax,(%rcx)
 8d4:	06                   	(bad)  
 8d5:	fe                   	(bad)  
 8d6:	18 00                	sbb    %al,(%rax)
 8d8:	00 00                	add    %al,(%rax)
 8da:	00 00                	add    %al,(%rax)
 8dc:	00 30                	add    %dh,(%rax)
 8de:	00 00                	add    %al,(%rax)
 8e0:	00 00                	add    %al,(%rax)
 8e2:	00 00                	add    %al,(%rax)
 8e4:	00 01                	add    %al,(%rcx)
 8e6:	9c                   	pushf  
 8e7:	12 58 00             	adc    0x0(%rax),%bl
 8ea:	00 00                	add    %al,(%rax)
 8ec:	c3                   	ret    
 8ed:	07                   	(bad)  
 8ee:	91                   	xchg   %eax,%ecx
 8ef:	00 00                	add    %al,(%rax)
 8f1:	00 6b 17             	add    %ch,0x17(%rbx)
 8f4:	00 00                	add    %al,(%rax)
 8f6:	00 00                	add    %al,(%rax)
 8f8:	00 00                	add    %al,(%rax)
 8fa:	93                   	xchg   %eax,%ebx
 8fb:	01 00                	add    %eax,(%rax)
 8fd:	00 00                	add    %al,(%rax)
 8ff:	00 00                	add    %al,(%rax)
 901:	00 01                	add    %al,(%rcx)
 903:	9c                   	pushf  
 904:	74 05                	je     90b <__abi_tag+0x57f>
 906:	00 00                	add    %al,(%rax)
 908:	07                   	(bad)  
 909:	6c                   	insb   (%dx),%es:(%rdi)
 90a:	65 6e                	outsb  %gs:(%rsi),(%dx)
 90c:	00 c5                	add    %al,%ch
 90e:	09 6b 00             	or     %ebp,0x0(%rbx)
 911:	00 00                	add    %al,(%rax)
 913:	02 91 64 07 73 74    	add    0x74730764(%rcx),%dl
 919:	72 00                	jb     91b <__abi_tag+0x58f>
 91b:	c6                   	(bad)  
 91c:	0b 91 00 00 00 02    	or     0x2000000(%rcx),%edx
 922:	91                   	xchg   %eax,%ecx
 923:	68 00 26 eb 02       	push   $0x2eb2600
 928:	00 00                	add    %al,(%rax)
 92a:	01 b2 07 91 00 00    	add    %esi,0x9107(%rdx)
 930:	00 09                	add    %cl,(%rcx)
 932:	17                   	(bad)  
 933:	00 00                	add    %al,(%rax)
 935:	00 00                	add    %al,(%rax)
 937:	00 00                	add    %al,(%rax)
 939:	62                   	(bad)  
 93a:	00 00                	add    %al,(%rax)
 93c:	00 00                	add    %al,(%rax)
 93e:	00 00                	add    %al,(%rax)
 940:	00 01                	add    %al,(%rcx)
 942:	9c                   	pushf  
 943:	a3 05 00 00 07 70 00 	movabs %eax,0xbb4007007000005
 94a:	b4 0b 
 94c:	91                   	xchg   %eax,%ecx
 94d:	00 00                	add    %al,(%rax)
 94f:	00 02                	add    %al,(%rdx)
 951:	91                   	xchg   %eax,%ecx
 952:	68 00 12 f1 03       	push   $0x3f11200
 957:	00 00                	add    %al,(%rax)
 959:	a9 05 6b 00 00       	test   $0x6b05,%eax
 95e:	00 ae 16 00 00 00    	add    %ch,0x16(%rsi)
 964:	00 00                	add    %al,(%rax)
 966:	00 5b 00             	add    %bl,0x0(%rbx)
 969:	00 00                	add    %al,(%rax)
 96b:	00 00                	add    %al,(%rax)
 96d:	00 00                	add    %al,(%rax)
 96f:	01 9c d3 05 00 00 13 	add    %ebx,0x13000005(%rbx,%rdx,8)
 976:	73 74                	jae    9ec <__abi_tag+0x660>
 978:	72 00                	jb     97a <__abi_tag+0x5ee>
 97a:	a9 16 91 00 00       	test   $0x9116,%eax
 97f:	00 02                	add    %al,(%rdx)
 981:	91                   	xchg   %eax,%ecx
 982:	68 00 27 5f 04       	push   $0x45f2700
 987:	00 00                	add    %al,(%rax)
 989:	01 a4 06 a3 16 00 00 	add    %esp,0x16a3(%rsi,%rax,1)
 990:	00 00                	add    %al,(%rax)
 992:	00 00                	add    %al,(%rax)
 994:	0b 00                	or     (%rax),%eax
 996:	00 00                	add    %al,(%rax)
 998:	00 00                	add    %al,(%rax)
 99a:	00 00                	add    %al,(%rax)
 99c:	01 9c 28 5f 01 00 00 	add    %ebx,0x15f(%rax,%rbp,1)
 9a3:	01 7a 06             	add    %edi,0x6(%rdx)
 9a6:	84 16                	test   %dl,(%rsi)
 9a8:	00 00                	add    %al,(%rax)
 9aa:	00 00                	add    %al,(%rax)
 9ac:	00 00                	add    %al,(%rax)
 9ae:	1f                   	(bad)  
 9af:	00 00                	add    %al,(%rax)
 9b1:	00 00                	add    %al,(%rax)
 9b3:	00 00                	add    %al,(%rax)
 9b5:	00 01                	add    %al,(%rcx)
 9b7:	9c                   	pushf  
 9b8:	12 2e                	adc    (%rsi),%ch
 9ba:	03 00                	add    (%rax),%eax
 9bc:	00 5f 05             	add    %bl,0x5(%rdi)
 9bf:	6b 00 00             	imul   $0x0,(%rax),%eax
 9c2:	00 ff                	add    %bh,%bh
 9c4:	15 00 00 00 00       	adc    $0x0,%eax
 9c9:	00 00                	add    %al,(%rax)
 9cb:	85 00                	test   %eax,(%rax)
 9cd:	00 00                	add    %al,(%rax)
 9cf:	00 00                	add    %al,(%rax)
 9d1:	00 00                	add    %al,(%rax)
 9d3:	01 9c 5d 06 00 00 0b 	add    %ebx,0xb000006(%rbp,%rbx,2)
 9da:	2f                   	(bad)  
 9db:	04 00                	add    $0x0,%al
 9dd:	00 5f 1d             	add    %bl,0x1d(%rdi)
 9e0:	91                   	xchg   %eax,%ecx
 9e1:	00 00                	add    %al,(%rax)
 9e3:	00 02                	add    %al,(%rdx)
 9e5:	91                   	xchg   %eax,%ecx
 9e6:	50                   	push   %rax
 9e7:	0b 37                	or     (%rdi),%esi
 9e9:	04 00                	add    $0x0,%al
 9eb:	00 5f 2c             	add    %bl,0x2c(%rdi)
 9ee:	91                   	xchg   %eax,%ecx
 9ef:	00 00                	add    %al,(%rax)
 9f1:	00 02                	add    %al,(%rdx)
 9f3:	91                   	xchg   %eax,%ecx
 9f4:	48 07                	rex.W (bad) 
 9f6:	70 00                	jo     9f8 <__abi_tag+0x66c>
 9f8:	61                   	(bad)  
 9f9:	0b 91 00 00 00 02    	or     0x2000000(%rcx),%edx
 9ff:	91                   	xchg   %eax,%ecx
 a00:	58                   	pop    %rax
 a01:	07                   	(bad)  
 a02:	71 00                	jno    a04 <__abi_tag+0x678>
 a04:	61                   	(bad)  
 a05:	0f 91 00             	setno  (%rax)
 a08:	00 00                	add    %al,(%rax)
 a0a:	02 91 60 00 29 85    	add    -0x7ad6ffa0(%rcx),%dl
 a10:	04 00                	add    $0x0,%al
 a12:	00 01                	add    %al,(%rcx)
 a14:	4f 05 6b 00 00 00    	rex.WRXB add $0x6b,%rax
 a1a:	c9                   	leave  
 a1b:	15 00 00 00 00       	adc    $0x0,%eax
 a20:	00 00                	add    %al,(%rax)
 a22:	36 00 00             	ss add %al,(%rax)
 a25:	00 00                	add    %al,(%rax)
 a27:	00 00                	add    %al,(%rax)
 a29:	00 01                	add    %al,(%rcx)
 a2b:	9c                   	pushf  
 a2c:	aa                   	stos   %al,%es:(%rdi)
 a2d:	06                   	(bad)  
 a2e:	00 00                	add    %al,(%rax)
 a30:	0b 90 03 00 00 4f    	or     0x4f000003(%rax),%edx
 a36:	19 91 00 00 00 02    	sbb    %edx,0x2000000(%rcx)
 a3c:	91                   	xchg   %eax,%ecx
 a3d:	58                   	pop    %rax
 a3e:	17                   	(bad)  
 a3f:	8c 04 00             	mov    %es,(%rax,%rax,1)
 a42:	00 51 09             	add    %dl,0x9(%rcx)
 a45:	6b 00 00             	imul   $0x0,(%rax),%eax
 a48:	00 02                	add    %al,(%rdx)
 a4a:	91                   	xchg   %eax,%ecx
 a4b:	64 07                	fs (bad) 
 a4d:	70 74                	jo     ac3 <__abi_tag+0x737>
 a4f:	72 00                	jb     a51 <__abi_tag+0x6c5>
 a51:	52                   	push   %rdx
 a52:	0b 91 00 00 00 02    	or     0x2000000(%rcx),%edx
 a58:	91                   	xchg   %eax,%ecx
 a59:	68 00 18 1d 03       	push   $0x31d1800
 a5e:	00 00                	add    %al,(%rax)
 a60:	45 07                	rex.RB (bad) 
 a62:	5a                   	pop    %rdx
 a63:	15 00 00 00 00       	adc    $0x0,%eax
 a68:	00 00                	add    %al,(%rax)
 a6a:	6f                   	outsl  %ds:(%rsi),(%dx)
 a6b:	00 00                	add    %al,(%rax)
 a6d:	00 00                	add    %al,(%rax)
 a6f:	00 00                	add    %al,(%rax)
 a71:	00 01                	add    %al,(%rcx)
 a73:	9c                   	pushf  
 a74:	f2 06                	repnz (bad) 
 a76:	00 00                	add    %al,(%rax)
 a78:	0b 3b                	or     (%rbx),%edi
 a7a:	02 00                	add    (%rax),%al
 a7c:	00 45 1e             	add    %al,0x1e(%rbp)
 a7f:	91                   	xchg   %eax,%ecx
 a80:	00 00                	add    %al,(%rax)
 a82:	00 02                	add    %al,(%rdx)
 a84:	91                   	xchg   %eax,%ecx
 a85:	58                   	pop    %rax
 a86:	0b 26                	or     (%rsi),%esp
 a88:	03 00                	add    (%rax),%eax
 a8a:	00 45 2a             	add    %al,0x2a(%rbp)
 a8d:	f2 06                	repnz (bad) 
 a8f:	00 00                	add    %al,(%rax)
 a91:	02 91 50 17 24 04    	add    0x4241750(%rcx),%dl
 a97:	00 00                	add    %al,(%rax)
 a99:	47 07                	rex.RXB (bad) 
 a9b:	6b 00 00             	imul   $0x0,(%rax),%eax
 a9e:	00 02                	add    %al,(%rdx)
 aa0:	91                   	xchg   %eax,%ecx
 aa1:	6c                   	insb   (%dx),%es:(%rdi)
 aa2:	00 03                	add    %al,(%rbx)
 aa4:	6b 00 00             	imul   $0x0,(%rax),%eax
 aa7:	00 18                	add    %bl,(%rax)
 aa9:	0f 03 00             	lsl    (%rax),%eax
 aac:	00 3e                	add    %bh,(%rsi)
 aae:	06                   	(bad)  
 aaf:	25 15 00 00 00       	and    $0x15,%eax
 ab4:	00 00                	add    %al,(%rax)
 ab6:	00 35 00 00 00 00    	add    %dh,0x0(%rip)        # abc <__abi_tag+0x730>
 abc:	00 00                	add    %al,(%rax)
 abe:	00 01                	add    %al,(%rcx)
 ac0:	9c                   	pushf  
 ac1:	21 07                	and    %eax,(%rdi)
 ac3:	00 00                	add    %al,(%rax)
 ac5:	13 73 00             	adc    0x0(%rbx),%esi
 ac8:	3e 1a 91 00 00 00 02 	ds sbb 0x2000000(%rcx),%dl
 acf:	91                   	xchg   %eax,%ecx
 ad0:	68 00 2a 06 04       	push   $0x4062a00
 ad5:	00 00                	add    %al,(%rax)
 ad7:	01 2e                	add    %ebp,(%rsi)
 ad9:	0d b7 14 00 00       	or     $0x14b7,%eax
 ade:	00 00                	add    %al,(%rax)
 ae0:	00 00                	add    %al,(%rax)
 ae2:	6e                   	outsb  %ds:(%rsi),(%dx)
 ae3:	00 00                	add    %al,(%rax)
 ae5:	00 00                	add    %al,(%rax)
 ae7:	00 00                	add    %al,(%rax)
 ae9:	00 01                	add    %al,(%rcx)
 aeb:	9c                   	pushf  
 aec:	13 73 69             	adc    0x69(%rbx),%esi
 aef:	67 00 2e             	add    %ch,(%esi)
 af2:	1d 6b 00 00 00       	sbb    $0x6b,%eax
 af7:	02                   	.byte 0x2
 af8:	91                   	xchg   %eax,%ecx
 af9:	6c                   	insb   (%dx),%es:(%rdi)
	...

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 0d 00 03 0e 3a    	add    %ecx,0x3a0e0300(%rip)        # 3a0e0306 <_end+0x3a0da596>
   6:	21 04 3b             	and    %eax,(%rbx,%rdi,1)
   9:	0b 39                	or     (%rcx),%edi
   b:	0b 49 13             	or     0x13(%rcx),%ecx
   e:	38 0b                	cmp    %cl,(%rbx)
  10:	00 00                	add    %al,(%rax)
  12:	02 24 00             	add    (%rax,%rax,1),%ah
  15:	0b 0b                	or     (%rbx),%ecx
  17:	3e 0b 03             	ds or  (%rbx),%eax
  1a:	0e                   	(bad)  
  1b:	00 00                	add    %al,(%rax)
  1d:	03 05 00 49 13 00    	add    0x134900(%rip),%eax        # 134923 <_end+0x12ebb3>
  23:	00 04 0f             	add    %al,(%rdi,%rcx,1)
  26:	00 0b                	add    %cl,(%rbx)
  28:	21 08                	and    %ecx,(%rax)
  2a:	49 13 00             	adc    (%r8),%rax
  2d:	00 05 2e 01 3f 19    	add    %al,0x193f012e(%rip)        # 193f0161 <_end+0x193ea3f1>
  33:	03 0e                	add    (%rsi),%ecx
  35:	3a 21                	cmp    (%rcx),%ah
  37:	07                   	(bad)  
  38:	3b 0b                	cmp    (%rbx),%ecx
  3a:	39 21                	cmp    %esp,(%rcx)
  3c:	0d 27 19 3c 19       	or     $0x193c1927,%eax
  41:	01 13                	add    %edx,(%rbx)
  43:	00 00                	add    %al,(%rax)
  45:	06                   	(bad)  
  46:	16                   	(bad)  
  47:	00 03                	add    %al,(%rbx)
  49:	0e                   	(bad)  
  4a:	3a 0b                	cmp    (%rbx),%cl
  4c:	3b 0b                	cmp    (%rbx),%ecx
  4e:	39 0b                	cmp    %ecx,(%rbx)
  50:	49 13 00             	adc    (%r8),%rax
  53:	00 07                	add    %al,(%rdi)
  55:	13 00                	adc    (%rax),%eax
  57:	03 0e                	add    (%rsi),%ecx
  59:	3c 19                	cmp    $0x19,%al
  5b:	00 00                	add    %al,(%rax)
  5d:	08 01                	or     %al,(%rcx)
  5f:	01 49 13             	add    %ecx,0x13(%rcx)
  62:	01 13                	add    %edx,(%rbx)
  64:	00 00                	add    %al,(%rax)
  66:	09 21                	or     %esp,(%rcx)
  68:	00 49 13             	add    %cl,0x13(%rcx)
  6b:	2f                   	(bad)  
  6c:	0b 00                	or     (%rax),%eax
  6e:	00 0a                	add    %cl,(%rdx)
  70:	2e 00 3f             	cs add %bh,(%rdi)
  73:	19 03                	sbb    %eax,(%rbx)
  75:	0e                   	(bad)  
  76:	3a 21                	cmp    (%rcx),%ah
  78:	08 3b                	or     %bh,(%rbx)
  7a:	0b 39                	or     (%rcx),%edi
  7c:	21 06                	and    %eax,(%rsi)
  7e:	27                   	(bad)  
  7f:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
  82:	00 00                	add    %al,(%rax)
  84:	0b 2e                	or     (%rsi),%ebp
  86:	01 3f                	add    %edi,(%rdi)
  88:	19 03                	sbb    %eax,(%rbx)
  8a:	0e                   	(bad)  
  8b:	3a 21                	cmp    (%rcx),%ah
  8d:	06                   	(bad)  
  8e:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270bcd <_end+0x1926ae5d>
  94:	49 13 3c 19          	adc    (%r9,%rbx,1),%rdi
  98:	01 13                	add    %edx,(%rbx)
  9a:	00 00                	add    %al,(%rax)
  9c:	0c 05                	or     $0x5,%al
  9e:	00 03                	add    %al,(%rbx)
  a0:	0e                   	(bad)  
  a1:	3a 21                	cmp    (%rcx),%ah
  a3:	01 3b                	add    %edi,(%rbx)
  a5:	21 24 39             	and    %esp,(%rcx,%rdi,1)
  a8:	0b 49 13             	or     0x13(%rcx),%ecx
  ab:	02 18                	add    (%rax),%bl
  ad:	00 00                	add    %al,(%rax)
  af:	0d 11 01 25 0e       	or     $0xe250111,%eax
  b4:	13 0b                	adc    (%rbx),%ecx
  b6:	03 1f                	add    (%rdi),%ebx
  b8:	1b 1f                	sbb    (%rdi),%ebx
  ba:	11 01                	adc    %eax,(%rcx)
  bc:	12 07                	adc    (%rdi),%al
  be:	10 17                	adc    %dl,(%rdi)
  c0:	00 00                	add    %al,(%rax)
  c2:	0e                   	(bad)  
  c3:	0f 00 0b             	str    (%rbx)
  c6:	0b 00                	or     (%rax),%eax
  c8:	00 0f                	add    %cl,(%rdi)
  ca:	24 00                	and    $0x0,%al
  cc:	0b 0b                	or     (%rbx),%ecx
  ce:	3e 0b 03             	ds or  (%rbx),%eax
  d1:	08 00                	or     %al,(%rax)
  d3:	00 10                	add    %dl,(%rax)
  d5:	26 00 49 13          	es add %cl,0x13(%rcx)
  d9:	00 00                	add    %al,(%rax)
  db:	11 13                	adc    %edx,(%rbx)
  dd:	01 03                	add    %eax,(%rbx)
  df:	0e                   	(bad)  
  e0:	0b 0b                	or     (%rbx),%ecx
  e2:	3a 0b                	cmp    (%rbx),%cl
  e4:	3b 0b                	cmp    (%rbx),%ecx
  e6:	39 0b                	cmp    %ecx,(%rbx)
  e8:	01 13                	add    %edx,(%rbx)
  ea:	00 00                	add    %al,(%rax)
  ec:	12 16                	adc    (%rsi),%dl
  ee:	00 03                	add    %al,(%rbx)
  f0:	0e                   	(bad)  
  f1:	3a 0b                	cmp    (%rbx),%cl
  f3:	3b 0b                	cmp    (%rbx),%ecx
  f5:	39 0b                	cmp    %ecx,(%rbx)
  f7:	00 00                	add    %al,(%rax)
  f9:	13 34 00             	adc    (%rax,%rax,1),%esi
  fc:	03 0e                	add    (%rsi),%ecx
  fe:	3a 0b                	cmp    (%rbx),%cl
 100:	3b 0b                	cmp    (%rbx),%ecx
 102:	39 0b                	cmp    %ecx,(%rbx)
 104:	49 13 3f             	adc    (%r15),%rdi
 107:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 10a:	00 00                	add    %al,(%rax)
 10c:	14 34                	adc    $0x34,%al
 10e:	00 03                	add    %al,(%rbx)
 110:	0e                   	(bad)  
 111:	3a 0b                	cmp    (%rbx),%cl
 113:	3b 0b                	cmp    (%rbx),%ecx
 115:	39 0b                	cmp    %ecx,(%rbx)
 117:	49 13 3f             	adc    (%r15),%rdi
 11a:	19 02                	sbb    %eax,(%rdx)
 11c:	18 00                	sbb    %al,(%rax)
 11e:	00 15 2e 00 3f 19    	add    %dl,0x193f002e(%rip)        # 193f0152 <_end+0x193ea3e2>
 124:	03 0e                	add    (%rsi),%ecx
 126:	3a 0b                	cmp    (%rbx),%cl
 128:	3b 0b                	cmp    (%rbx),%ecx
 12a:	39 0b                	cmp    %ecx,(%rbx)
 12c:	27                   	(bad)  
 12d:	19 49 13             	sbb    %ecx,0x13(%rcx)
 130:	3c 19                	cmp    $0x19,%al
 132:	00 00                	add    %al,(%rax)
 134:	16                   	(bad)  
 135:	2e 01 3f             	cs add %edi,(%rdi)
 138:	19 03                	sbb    %eax,(%rbx)
 13a:	0e                   	(bad)  
 13b:	3a 0b                	cmp    (%rbx),%cl
 13d:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270c7c <_end+0x1926af0c>
 143:	87 01                	xchg   %eax,(%rcx)
 145:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 148:	01 13                	add    %edx,(%rbx)
 14a:	00 00                	add    %al,(%rax)
 14c:	17                   	(bad)  
 14d:	18 00                	sbb    %al,(%rax)
 14f:	00 00                	add    %al,(%rax)
 151:	18 37                	sbb    %dh,(%rdi)
 153:	00 49 13             	add    %cl,0x13(%rcx)
 156:	00 00                	add    %al,(%rax)
 158:	19 2e                	sbb    %ebp,(%rsi)
 15a:	01 3f                	add    %edi,(%rdi)
 15c:	19 03                	sbb    %eax,(%rbx)
 15e:	0e                   	(bad)  
 15f:	3a 0b                	cmp    (%rbx),%cl
 161:	3b 0b                	cmp    (%rbx),%ecx
 163:	39 0b                	cmp    %ecx,(%rbx)
 165:	27                   	(bad)  
 166:	19 49 13             	sbb    %ecx,0x13(%rcx)
 169:	11 01                	adc    %eax,(%rcx)
 16b:	12 07                	adc    (%rdi),%al
 16d:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
 172:	13 00                	adc    (%rax),%eax
 174:	00 1a                	add    %bl,(%rdx)
 176:	34 00                	xor    $0x0,%al
 178:	03 0e                	add    (%rsi),%ecx
 17a:	3a 0b                	cmp    (%rbx),%cl
 17c:	3b 0b                	cmp    (%rbx),%ecx
 17e:	39 0b                	cmp    %ecx,(%rbx)
 180:	49 13 02             	adc    (%r10),%rax
 183:	18 00                	sbb    %al,(%rax)
 185:	00 00                	add    %al,(%rax)
 187:	01 0d 00 03 0e 3a    	add    %ecx,0x3a0e0300(%rip)        # 3a0e048d <_end+0x3a0da71d>
 18d:	21 04 3b             	and    %eax,(%rbx,%rdi,1)
 190:	0b 39                	or     (%rcx),%edi
 192:	0b 49 13             	or     0x13(%rcx),%ecx
 195:	38 0b                	cmp    %cl,(%rbx)
 197:	00 00                	add    %al,(%rax)
 199:	02 05 00 49 13 00    	add    0x134900(%rip),%al        # 134a9f <_end+0x12ed2f>
 19f:	00 03                	add    %al,(%rbx)
 1a1:	0f 00 0b             	str    (%rbx)
 1a4:	21 08                	and    %ecx,(%rax)
 1a6:	49 13 00             	adc    (%r8),%rax
 1a9:	00 04 24             	add    %al,(%rsp)
 1ac:	00 0b                	add    %cl,(%rbx)
 1ae:	0b 3e                	or     (%rsi),%edi
 1b0:	0b 03                	or     (%rbx),%eax
 1b2:	0e                   	(bad)  
 1b3:	00 00                	add    %al,(%rax)
 1b5:	05 28 00 03 0e       	add    $0xe030028,%eax
 1ba:	1c 05                	sbb    $0x5,%al
 1bc:	00 00                	add    %al,(%rax)
 1be:	06                   	(bad)  
 1bf:	21 00                	and    %eax,(%rax)
 1c1:	49 13 2f             	adc    (%r15),%rbp
 1c4:	0b 00                	or     (%rax),%eax
 1c6:	00 07                	add    %al,(%rdi)
 1c8:	34 00                	xor    $0x0,%al
 1ca:	03 08                	add    (%rax),%ecx
 1cc:	3a 21                	cmp    (%rcx),%ah
 1ce:	01 3b                	add    %edi,(%rbx)
 1d0:	0b 39                	or     (%rcx),%edi
 1d2:	0b 49 13             	or     0x13(%rcx),%ecx
 1d5:	02 18                	add    (%rax),%bl
 1d7:	00 00                	add    %al,(%rax)
 1d9:	08 16                	or     %dl,(%rsi)
 1db:	00 03                	add    %al,(%rbx)
 1dd:	0e                   	(bad)  
 1de:	3a 0b                	cmp    (%rbx),%cl
 1e0:	3b 0b                	cmp    (%rbx),%ecx
 1e2:	39 0b                	cmp    %ecx,(%rbx)
 1e4:	49 13 00             	adc    (%r8),%rax
 1e7:	00 09                	add    %cl,(%rcx)
 1e9:	01 01                	add    %eax,(%rcx)
 1eb:	49 13 01             	adc    (%r9),%rax
 1ee:	13 00                	adc    (%rax),%eax
 1f0:	00 0a                	add    %cl,(%rdx)
 1f2:	2e 01 3f             	cs add %edi,(%rdi)
 1f5:	19 03                	sbb    %eax,(%rbx)
 1f7:	0e                   	(bad)  
 1f8:	3a 0b                	cmp    (%rbx),%cl
 1fa:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270d39 <_end+0x1926afc9>
 200:	49 13 3c 19          	adc    (%r9,%rbx,1),%rdi
 204:	01 13                	add    %edx,(%rbx)
 206:	00 00                	add    %al,(%rax)
 208:	0b 05 00 03 0e 3a    	or     0x3a0e0300(%rip),%eax        # 3a0e050e <_end+0x3a0da79e>
 20e:	21 01                	and    %eax,(%rcx)
 210:	3b 0b                	cmp    (%rbx),%ecx
 212:	39 0b                	cmp    %ecx,(%rbx)
 214:	49 13 02             	adc    (%r10),%rax
 217:	18 00                	sbb    %al,(%rax)
 219:	00 0c 28             	add    %cl,(%rax,%rbp,1)
 21c:	00 03                	add    %al,(%rbx)
 21e:	0e                   	(bad)  
 21f:	1c 0b                	sbb    $0xb,%al
 221:	00 00                	add    %al,(%rax)
 223:	0d 34 00 03 0e       	or     $0xe030034,%eax
 228:	3a 0b                	cmp    (%rbx),%cl
 22a:	3b 0b                	cmp    (%rbx),%ecx
 22c:	39 0b                	cmp    %ecx,(%rbx)
 22e:	49 13 3f             	adc    (%r15),%rdi
 231:	19 02                	sbb    %eax,(%rdx)
 233:	18 00                	sbb    %al,(%rax)
 235:	00 0e                	add    %cl,(%rsi)
 237:	34 00                	xor    $0x0,%al
 239:	03 0e                	add    (%rsi),%ecx
 23b:	3a 21                	cmp    (%rcx),%ah
 23d:	01 3b                	add    %edi,(%rbx)
 23f:	05 39 0b 49 13       	add    $0x13490b39,%eax
 244:	02 18                	add    (%rax),%bl
 246:	00 00                	add    %al,(%rax)
 248:	0f 13 00             	movlps %xmm0,(%rax)
 24b:	03 0e                	add    (%rsi),%ecx
 24d:	3c 19                	cmp    $0x19,%al
 24f:	00 00                	add    %al,(%rax)
 251:	10 34 00             	adc    %dh,(%rax,%rax,1)
 254:	03 0e                	add    (%rsi),%ecx
 256:	3a 0b                	cmp    (%rbx),%cl
 258:	3b 0b                	cmp    (%rbx),%ecx
 25a:	39 21                	cmp    %esp,(%rcx)
 25c:	0e                   	(bad)  
 25d:	49 13 3f             	adc    (%r15),%rdi
 260:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 263:	00 00                	add    %al,(%rax)
 265:	11 18                	adc    %ebx,(%rax)
 267:	00 00                	add    %al,(%rax)
 269:	00 12                	add    %dl,(%rdx)
 26b:	2e 01 3f             	cs add %edi,(%rdi)
 26e:	19 03                	sbb    %eax,(%rbx)
 270:	0e                   	(bad)  
 271:	3a 21                	cmp    (%rcx),%ah
 273:	01 3b                	add    %edi,(%rbx)
 275:	0b 39                	or     (%rcx),%edi
 277:	0b 27                	or     (%rdi),%esp
 279:	19 49 13             	sbb    %ecx,0x13(%rcx)
 27c:	11 01                	adc    %eax,(%rcx)
 27e:	12 07                	adc    (%rdi),%al
 280:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
 285:	13 00                	adc    (%rax),%eax
 287:	00 13                	add    %dl,(%rbx)
 289:	05 00 03 08 3a       	add    $0x3a080300,%eax
 28e:	21 01                	and    %eax,(%rcx)
 290:	3b 0b                	cmp    (%rbx),%ecx
 292:	39 0b                	cmp    %ecx,(%rbx)
 294:	49 13 02             	adc    (%r10),%rax
 297:	18 00                	sbb    %al,(%rax)
 299:	00 14 26             	add    %dl,(%rsi,%riz,1)
 29c:	00 49 13             	add    %cl,0x13(%rcx)
 29f:	00 00                	add    %al,(%rax)
 2a1:	15 37 00 49 13       	adc    $0x13490037,%eax
 2a6:	00 00                	add    %al,(%rax)
 2a8:	16                   	(bad)  
 2a9:	2e 01 3f             	cs add %edi,(%rdi)
 2ac:	19 03                	sbb    %eax,(%rbx)
 2ae:	0e                   	(bad)  
 2af:	3a 0b                	cmp    (%rbx),%cl
 2b1:	3b 0b                	cmp    (%rbx),%ecx
 2b3:	39 0b                	cmp    %ecx,(%rbx)
 2b5:	27                   	(bad)  
 2b6:	19 49 13             	sbb    %ecx,0x13(%rcx)
 2b9:	3c 19                	cmp    $0x19,%al
 2bb:	01 13                	add    %edx,(%rbx)
 2bd:	00 00                	add    %al,(%rax)
 2bf:	17                   	(bad)  
 2c0:	34 00                	xor    $0x0,%al
 2c2:	03 0e                	add    (%rsi),%ecx
 2c4:	3a 21                	cmp    (%rcx),%ah
 2c6:	01 3b                	add    %edi,(%rbx)
 2c8:	0b 39                	or     (%rcx),%edi
 2ca:	0b 49 13             	or     0x13(%rcx),%ecx
 2cd:	02 18                	add    (%rax),%bl
 2cf:	00 00                	add    %al,(%rax)
 2d1:	18 2e                	sbb    %ch,(%rsi)
 2d3:	01 3f                	add    %edi,(%rdi)
 2d5:	19 03                	sbb    %eax,(%rbx)
 2d7:	0e                   	(bad)  
 2d8:	3a 21                	cmp    (%rcx),%ah
 2da:	01 3b                	add    %edi,(%rbx)
 2dc:	0b 39                	or     (%rcx),%edi
 2de:	0b 27                	or     (%rdi),%esp
 2e0:	19 11                	sbb    %edx,(%rcx)
 2e2:	01 12                	add    %edx,(%rdx)
 2e4:	07                   	(bad)  
 2e5:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
 2ea:	13 00                	adc    (%rax),%eax
 2ec:	00 19                	add    %bl,(%rcx)
 2ee:	11 01                	adc    %eax,(%rcx)
 2f0:	25 0e 13 0b 03       	and    $0x30b130e,%eax
 2f5:	1f                   	(bad)  
 2f6:	1b 1f                	sbb    (%rdi),%ebx
 2f8:	11 01                	adc    %eax,(%rcx)
 2fa:	12 07                	adc    (%rdi),%al
 2fc:	10 17                	adc    %dl,(%rdi)
 2fe:	00 00                	add    %al,(%rax)
 300:	1a 0f                	sbb    (%rdi),%cl
 302:	00 0b                	add    %cl,(%rbx)
 304:	0b 00                	or     (%rax),%eax
 306:	00 1b                	add    %bl,(%rbx)
 308:	24 00                	and    $0x0,%al
 30a:	0b 0b                	or     (%rbx),%ecx
 30c:	3e 0b 03             	ds or  (%rbx),%eax
 30f:	08 00                	or     %al,(%rax)
 311:	00 1c 13             	add    %bl,(%rbx,%rdx,1)
 314:	01 03                	add    %eax,(%rbx)
 316:	0e                   	(bad)  
 317:	0b 0b                	or     (%rbx),%ecx
 319:	3a 0b                	cmp    (%rbx),%cl
 31b:	3b 0b                	cmp    (%rbx),%ecx
 31d:	39 0b                	cmp    %ecx,(%rbx)
 31f:	01 13                	add    %edx,(%rbx)
 321:	00 00                	add    %al,(%rax)
 323:	1d 16 00 03 0e       	sbb    $0xe030016,%eax
 328:	3a 0b                	cmp    (%rbx),%cl
 32a:	3b 0b                	cmp    (%rbx),%ecx
 32c:	39 0b                	cmp    %ecx,(%rbx)
 32e:	00 00                	add    %al,(%rax)
 330:	1e                   	(bad)  
 331:	04 01                	add    $0x1,%al
 333:	3e 0b 0b             	ds or  (%rbx),%ecx
 336:	0b 49 13             	or     0x13(%rcx),%ecx
 339:	3a 0b                	cmp    (%rbx),%cl
 33b:	3b 0b                	cmp    (%rbx),%ecx
 33d:	39 0b                	cmp    %ecx,(%rbx)
 33f:	01 13                	add    %edx,(%rbx)
 341:	00 00                	add    %al,(%rax)
 343:	1f                   	(bad)  
 344:	15 01 27 19 01       	adc    $0x1192701,%eax
 349:	13 00                	adc    (%rax),%eax
 34b:	00 20                	add    %ah,(%rax)
 34d:	2e 01 3f             	cs add %edi,(%rdi)
 350:	19 03                	sbb    %eax,(%rbx)
 352:	0e                   	(bad)  
 353:	3a 0b                	cmp    (%rbx),%cl
 355:	3b 0b                	cmp    (%rbx),%ecx
 357:	39 0b                	cmp    %ecx,(%rbx)
 359:	3c 19                	cmp    $0x19,%al
 35b:	01 13                	add    %edx,(%rbx)
 35d:	00 00                	add    %al,(%rax)
 35f:	21 2e                	and    %ebp,(%rsi)
 361:	00 3f                	add    %bh,(%rdi)
 363:	19 03                	sbb    %eax,(%rbx)
 365:	0e                   	(bad)  
 366:	3a 0b                	cmp    (%rbx),%cl
 368:	3b 0b                	cmp    (%rbx),%ecx
 36a:	39 0b                	cmp    %ecx,(%rbx)
 36c:	27                   	(bad)  
 36d:	19 49 13             	sbb    %ecx,0x13(%rcx)
 370:	3c 19                	cmp    $0x19,%al
 372:	00 00                	add    %al,(%rax)
 374:	22 2e                	and    (%rsi),%ch
 376:	01 3f                	add    %edi,(%rdi)
 378:	19 03                	sbb    %eax,(%rbx)
 37a:	0e                   	(bad)  
 37b:	3a 0b                	cmp    (%rbx),%cl
 37d:	3b 05 39 0b 6e 0e    	cmp    0xe6e0b39(%rip),%eax        # e6e0ebc <_end+0xe6db14c>
 383:	27                   	(bad)  
 384:	19 49 13             	sbb    %ecx,0x13(%rcx)
 387:	3c 19                	cmp    $0x19,%al
 389:	01 13                	add    %edx,(%rbx)
 38b:	00 00                	add    %al,(%rax)
 38d:	23 2e                	and    (%rsi),%ebp
 38f:	01 3f                	add    %edi,(%rdi)
 391:	19 03                	sbb    %eax,(%rbx)
 393:	0e                   	(bad)  
 394:	3a 0b                	cmp    (%rbx),%cl
 396:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270ed5 <_end+0x1926b165>
 39c:	87 01                	xchg   %eax,(%rcx)
 39e:	19 3c 19             	sbb    %edi,(%rcx,%rbx,1)
 3a1:	01 13                	add    %edx,(%rbx)
 3a3:	00 00                	add    %al,(%rax)
 3a5:	24 2e                	and    $0x2e,%al
 3a7:	01 3f                	add    %edi,(%rdi)
 3a9:	19 03                	sbb    %eax,(%rbx)
 3ab:	0e                   	(bad)  
 3ac:	3a 0b                	cmp    (%rbx),%cl
 3ae:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270eed <_end+0x1926b17d>
 3b4:	11 01                	adc    %eax,(%rcx)
 3b6:	12 07                	adc    (%rdi),%al
 3b8:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
 3bd:	13 00                	adc    (%rax),%eax
 3bf:	00 25 2e 00 3f 19    	add    %ah,0x193f002e(%rip)        # 193f03f3 <_end+0x193ea683>
 3c5:	03 0e                	add    (%rsi),%ecx
 3c7:	3a 0b                	cmp    (%rbx),%cl
 3c9:	3b 05 39 0b 27 19    	cmp    0x19270b39(%rip),%eax        # 19270f08 <_end+0x1926b198>
 3cf:	11 01                	adc    %eax,(%rcx)
 3d1:	12 07                	adc    (%rdi),%al
 3d3:	40 18 7c 19 00       	sbb    %dil,0x0(%rcx,%rbx,1)
 3d8:	00 26                	add    %ah,(%rsi)
 3da:	2e 01 3f             	cs add %edi,(%rdi)
 3dd:	19 03                	sbb    %eax,(%rbx)
 3df:	0e                   	(bad)  
 3e0:	3a 0b                	cmp    (%rbx),%cl
 3e2:	3b 0b                	cmp    (%rbx),%ecx
 3e4:	39 0b                	cmp    %ecx,(%rbx)
 3e6:	49 13 11             	adc    (%r9),%rdx
 3e9:	01 12                	add    %edx,(%rdx)
 3eb:	07                   	(bad)  
 3ec:	40 18 7c 19 01       	sbb    %dil,0x1(%rcx,%rbx,1)
 3f1:	13 00                	adc    (%rax),%eax
 3f3:	00 27                	add    %ah,(%rdi)
 3f5:	2e 00 3f             	cs add %bh,(%rdi)
 3f8:	19 03                	sbb    %eax,(%rbx)
 3fa:	0e                   	(bad)  
 3fb:	3a 0b                	cmp    (%rbx),%cl
 3fd:	3b 0b                	cmp    (%rbx),%ecx
 3ff:	39 0b                	cmp    %ecx,(%rbx)
 401:	27                   	(bad)  
 402:	19 11                	sbb    %edx,(%rcx)
 404:	01 12                	add    %edx,(%rdx)
 406:	07                   	(bad)  
 407:	40 18 7a 19          	sbb    %dil,0x19(%rdx)
 40b:	00 00                	add    %al,(%rax)
 40d:	28 2e                	sub    %ch,(%rsi)
 40f:	00 3f                	add    %bh,(%rdi)
 411:	19 03                	sbb    %eax,(%rbx)
 413:	0e                   	(bad)  
 414:	3a 0b                	cmp    (%rbx),%cl
 416:	3b 0b                	cmp    (%rbx),%ecx
 418:	39 0b                	cmp    %ecx,(%rbx)
 41a:	27                   	(bad)  
 41b:	19 11                	sbb    %edx,(%rcx)
 41d:	01 12                	add    %edx,(%rdx)
 41f:	07                   	(bad)  
 420:	40 18 7c 19 00       	sbb    %dil,0x0(%rcx,%rbx,1)
 425:	00 29                	add    %ch,(%rcx)
 427:	2e 01 3f             	cs add %edi,(%rdi)
 42a:	19 03                	sbb    %eax,(%rbx)
 42c:	0e                   	(bad)  
 42d:	3a 0b                	cmp    (%rbx),%cl
 42f:	3b 0b                	cmp    (%rbx),%ecx
 431:	39 0b                	cmp    %ecx,(%rbx)
 433:	27                   	(bad)  
 434:	19 49 13             	sbb    %ecx,0x13(%rcx)
 437:	11 01                	adc    %eax,(%rcx)
 439:	12 07                	adc    (%rdi),%al
 43b:	40 18 7a 19          	sbb    %dil,0x19(%rdx)
 43f:	01 13                	add    %edx,(%rbx)
 441:	00 00                	add    %al,(%rax)
 443:	2a 2e                	sub    (%rsi),%ch
 445:	01 03                	add    %eax,(%rbx)
 447:	0e                   	(bad)  
 448:	3a 0b                	cmp    (%rbx),%cl
 44a:	3b 0b                	cmp    (%rbx),%ecx
 44c:	39 0b                	cmp    %ecx,(%rbx)
 44e:	27                   	(bad)  
 44f:	19 11                	sbb    %edx,(%rcx)
 451:	01 12                	add    %edx,(%rdx)
 453:	07                   	(bad)  
 454:	40 18 7c 19 00       	sbb    %dil,0x0(%rcx,%rbx,1)
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	e1 00                	loope  2 <__abi_tag-0x38a>
   2:	00 00                	add    %al,(%rax)
   4:	05 00 08 00 62       	add    $0x62000800,%eax
   9:	00 00                	add    %al,(%rax)
   b:	00 01                	add    %al,(%rcx)
   d:	01 01                	add    %eax,(%rcx)
   f:	fb                   	sti    
  10:	0e                   	(bad)  
  11:	0d 00 01 01 01       	or     $0x1010100,%eax
  16:	01 00                	add    %eax,(%rax)
  18:	00 00                	add    %al,(%rax)
  1a:	01 00                	add    %eax,(%rax)
  1c:	00 01                	add    %al,(%rcx)
  1e:	01 01                	add    %eax,(%rcx)
  20:	1f                   	(bad)  
  21:	05 00 00 00 00       	add    $0x0,%eax
  26:	67 00 00             	add    %al,(%eax)
  29:	00 90 00 00 00 b3    	add    %dl,-0x4d000000(%rax)
  2f:	00 00                	add    %al,(%rax)
  31:	00 dc                	add    %bl,%ah
  33:	00 00                	add    %al,(%rax)
  35:	00 02                	add    %al,(%rdx)
  37:	01 1f                	add    %ebx,(%rdi)
  39:	02 0f                	add    (%rdi),%cl
  3b:	0a 60 00             	or     0x0(%rax),%ah
  3e:	00 00                	add    %al,(%rax)
  40:	00 60 00             	add    %ah,0x0(%rax)
  43:	00 00                	add    %al,(%rax)
  45:	00 e9                	add    %ch,%cl
  47:	00 00                	add    %al,(%rax)
  49:	00 01                	add    %al,(%rcx)
  4b:	f2 00 00             	repnz add %al,(%rax)
  4e:	00 02                	add    %al,(%rdx)
  50:	fa                   	cli    
  51:	00 00                	add    %al,(%rax)
  53:	00 03                	add    %al,(%rbx)
  55:	01 01                	add    %eax,(%rcx)
  57:	00 00                	add    %al,(%rax)
  59:	03 08                	add    (%rax),%ecx
  5b:	01 00                	add    %eax,(%rax)
  5d:	00 04 10             	add    %al,(%rax,%rdx,1)
  60:	01 00                	add    %eax,(%rax)
  62:	00 00                	add    %al,(%rax)
  64:	19 01                	sbb    %eax,(%rcx)
  66:	00 00                	add    %al,(%rax)
  68:	00 23                	add    %ah,(%rbx)
  6a:	01 00                	add    %eax,(%rax)
  6c:	00 04 05 01 00 09 02 	add    %al,0x2090001(,%rax,1)
  73:	e9 12 00 00 00       	jmp    8a <__abi_tag-0x302>
  78:	00 00                	add    %al,(%rax)
  7a:	00 03                	add    %al,(%rbx)
  7c:	24 01                	and    $0x1,%al
  7e:	05 08 08 36 05       	add    $0x5360808,%eax
  83:	09 67 05             	or     %esp,0x5(%rdi)
  86:	0d 08 35 05 24       	or     $0x24053508,%eax
  8b:	67 05 1a 82 05 18    	addr32 add $0x1805821a,%eax
  91:	08 4a 05             	or     %cl,0x5(%rdx)
  94:	06                   	(bad)  
  95:	75 05                	jne    9c <__abi_tag-0x2f0>
  97:	05 74 05 3b 59       	add    $0x593b0574,%eax
  9c:	05 06 82 08 f3       	add    $0xf3088206,%eax
  a1:	05 02 a4 08 c9       	add    $0xc908a402,%eax
  a6:	05 05 a2 5a e5       	add    $0xe55aa205,%eax
  ab:	05 0d e7 05 05       	add    $0x505e70d,%eax
  b0:	91                   	xchg   %eax,%ecx
  b1:	bb 5a 05 0d e8       	mov    $0xe80d055a,%ebx
  b6:	05 05 91 bb 59       	add    $0x59bb9105,%eax
  bb:	05 0d e8 05 05       	add    $0x505e80d,%eax
  c0:	91                   	xchg   %eax,%ecx
  c1:	bb 59 05 0d e7       	mov    $0xe70d0559,%ebx
  c6:	05 05 91 bb 59       	add    $0x59bb9105,%eax
  cb:	05 0d e7 05 05       	add    $0x505e70d,%eax
  d0:	91                   	xchg   %eax,%ecx
  d1:	bb 59 05 0d e8       	mov    $0xe80d0559,%ebx
  d6:	05 05 91 bb 05       	add    $0x5bb9105,%eax
  db:	0c 5d                	or     $0x5d,%al
  dd:	05 01 59 02 02       	add    $0x2025901,%eax
  e2:	00 01                	add    %al,(%rcx)
  e4:	01 dd                	add    %ebx,%ebp
  e6:	01 00                	add    %eax,(%rax)
  e8:	00 05 00 08 00 76    	add    %al,0x76000800(%rip)        # 760008ee <_end+0x75ffab7e>
  ee:	00 00                	add    %al,(%rax)
  f0:	00 01                	add    %al,(%rcx)
  f2:	01 01                	add    %eax,(%rcx)
  f4:	fb                   	sti    
  f5:	0e                   	(bad)  
  f6:	0d 00 01 01 01       	or     $0x1010100,%eax
  fb:	01 00                	add    %eax,(%rax)
  fd:	00 00                	add    %al,(%rax)
  ff:	01 00                	add    %eax,(%rax)
 101:	00 01                	add    %al,(%rcx)
 103:	01 01                	add    %eax,(%rcx)
 105:	1f                   	(bad)  
 106:	05 00 00 00 00       	add    $0x0,%eax
 10b:	67 00 00             	add    %al,(%eax)
 10e:	00 90 00 00 00 b3    	add    %dl,-0x4d000000(%rax)
 114:	00 00                	add    %al,(%rax)
 116:	00 dc                	add    %bl,%ah
 118:	00 00                	add    %al,(%rax)
 11a:	00 02                	add    %al,(%rdx)
 11c:	01 1f                	add    %ebx,(%rdi)
 11e:	02 0f                	add    (%rdi),%cl
 120:	0e                   	(bad)  
 121:	2c 01                	sub    $0x1,%al
 123:	00 00                	add    %al,(%rax)
 125:	00 2c 01             	add    %ch,(%rcx,%rax,1)
 128:	00 00                	add    %al,(%rax)
 12a:	00 e9                	add    %ch,%cl
 12c:	00 00                	add    %al,(%rax)
 12e:	00 01                	add    %al,(%rcx)
 130:	f2 00 00             	repnz add %al,(%rax)
 133:	00 02                	add    %al,(%rdx)
 135:	fa                   	cli    
 136:	00 00                	add    %al,(%rax)
 138:	00 03                	add    %al,(%rbx)
 13a:	01 01                	add    %eax,(%rcx)
 13c:	00 00                	add    %al,(%rax)
 13e:	03 08                	add    (%rax),%ecx
 140:	01 00                	add    %eax,(%rax)
 142:	00 04 36             	add    %al,(%rsi,%rsi,1)
 145:	01 00                	add    %eax,(%rax)
 147:	00 04 3f             	add    %al,(%rdi,%rdi,1)
 14a:	01 00                	add    %eax,(%rax)
 14c:	00 00                	add    %al,(%rax)
 14e:	48 01 00             	add    %rax,(%rax)
 151:	00 04 23             	add    %al,(%rbx,%riz,1)
 154:	01 00                	add    %eax,(%rax)
 156:	00 04 51             	add    %al,(%rcx,%rdx,2)
 159:	01 00                	add    %eax,(%rax)
 15b:	00 04 5a             	add    %al,(%rdx,%rbx,2)
 15e:	01 00                	add    %eax,(%rax)
 160:	00 04 19             	add    %al,(%rcx,%rbx,1)
 163:	01 00                	add    %eax,(%rax)
 165:	00 00                	add    %al,(%rax)
 167:	05 01 00 09 02       	add    $0x2090001,%eax
 16c:	b7 14                	mov    $0x14,%bh
 16e:	00 00                	add    %al,(%rax)
 170:	00 00                	add    %al,(%rax)
 172:	00 00                	add    %al,(%rax)
 174:	03 2e                	add    (%rsi),%ebp
 176:	01 05 05 e5 e5 9f    	add    %eax,-0x601a1afb(%rip)        # ffffffff9fe5e681 <_end+0xffffffff9fe58911>
 17c:	08 3d e5 9f e5 05    	or     %bh,0x5e59fe5(%rip)        # 5e5a167 <_end+0x5e543f7>
 182:	01 03                	add    %eax,(%rbx)
 184:	09 9e 05 05 f3 08    	or     %ebx,0x8f30505(%rsi)
 18a:	9f                   	lahf   
 18b:	05 01 a3 05 14       	add    $0x1405a301,%eax
 190:	08 3d 05 06 02 4d    	or     %bh,0x4d020605(%rip)        # 4d02079b <_end+0x4d01aa2b>
 196:	15 05 05 67 05       	adc    $0x5670505,%eax
 19b:	01 59 40             	add    %ebx,0x40(%rcx)
 19e:	05 09 be 05 0c       	add    $0xc05be09,%eax
 1a3:	83 05 0b 76 05 05 2f 	addl   $0x2f,0x505760b(%rip)        # 50577b5 <_end+0x5051a45>
 1aa:	05 09 59 05 0c       	add    $0xc055909,%eax
 1af:	48 05 11 74 05 0c    	add    $0xc057411,%rax
 1b5:	4e 05 01 3d 32 05    	rex.WRX add $0x5323d01,%rax
 1bb:	09 08                	or     %ecx,(%rax)
 1bd:	4d 05 23 d6 05 08    	rex.WRB add $0x805d623,%rax
 1c3:	ba 05 09 4b 05       	mov    $0x54b0905,%edx
 1c8:	07                   	(bad)  
 1c9:	76 83                	jbe    14e <__abi_tag-0x23e>
 1cb:	05 0b 84 05 06       	add    $0x605840b,%eax
 1d0:	2f                   	(bad)  
 1d1:	05 0c 74 05 05       	add    $0x505740c,%eax
 1d6:	74 05                	je     1dd <__abi_tag-0x1af>
 1d8:	0d 4b 05 03 75       	or     $0x7503054b,%eax
 1dd:	59                   	pop    %rcx
 1de:	05 0c 54 05 0f       	add    $0xf05540c,%eax
 1e3:	74 05                	je     1ea <__abi_tag-0x1a2>
 1e5:	0c 50                	or     $0x50,%al
 1e7:	05 01 59 03 0b       	add    $0xb035901,%eax
 1ec:	66 05 05 03          	add    $0x305,%ax
 1f0:	09 82 05 01 03 1b    	or     %eax,0x1b030105(%rdx)
 1f6:	08 3c 42             	or     %bh,(%rdx,%rax,2)
 1f9:	83 40 05 0b          	addl   $0xb,0x5(%rax)
 1fd:	f3 05 07 2f 05 05    	repz add $0x5052f07,%eax
 203:	02 2c 12             	add    (%rdx,%rdx,1),%ch
 206:	05 0d 4b 05 0c       	add    $0xc054b0d,%eax
 20b:	72 af                	jb     1bc <__abi_tag-0x1d0>
 20d:	05 01 59 32 05       	add    $0x5325901,%eax
 212:	06                   	(bad)  
 213:	be 05 19 74 05       	mov    $0x5741905,%esi
 218:	06                   	(bad)  
 219:	08 f2                	or     %dh,%dl
 21b:	05 05 08 13 05       	add    $0x5130805,%eax
 220:	17                   	(bad)  
 221:	00 02                	add    %al,(%rdx)
 223:	04 01                	add    $0x1,%al
 225:	74 05                	je     22c <__abi_tag-0x160>
 227:	12 00                	adc    (%rax),%al
 229:	02 04 01             	add    (%rcx,%rax,1),%al
 22c:	ba 05 0d 4b 05       	mov    $0x54b0d05,%edx
 231:	01 4c 03 09          	add    %ecx,0x9(%rbx,%rax,1)
 235:	2e 05 0b bf 05 08    	cs add $0x805bf0b,%eax
 23b:	d7                   	xlat   %ds:(%rbx)
 23c:	05 0d ad 05 05       	add    $0x505ad0d,%eax
 241:	d6                   	(bad)  
 242:	05 06 59 e5 05       	add    $0x5e55906,%eax
 247:	0a a3 05 09 e4 05    	or     0x5e40905(%rbx),%ah
 24d:	03 59 05             	add    0x5(%rcx),%ebx
 250:	0a a3 05 09 d7 05    	or     0x5d70905(%rbx),%ah
 256:	06                   	(bad)  
 257:	d7                   	xlat   %ds:(%rbx)
 258:	05 07 75 e5 05       	add    $0x5e57507,%eax
 25d:	1f                   	(bad)  
 25e:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
 25f:	05 0b 08 f2 05       	add    $0x5f2080b,%eax
 264:	09 82 05 07 3d 05    	or     %eax,0x53d0705(%rdx)
 26a:	02 67 05             	add    0x5(%rdi),%ah
 26d:	28 e5                	sub    %ah,%ch
 26f:	05 16 e4 05 02       	add    $0x205e416,%eax
 274:	08 9e 08 9f 05 25    	or     %bl,0x25059f08(%rsi)
 27a:	5c                   	pop    %rsp
 27b:	05 29 66 05 2d       	add    $0x2d056629,%eax
 280:	66 05 2b 02          	add    $0x22b,%ax
 284:	25 13 05 0c e4       	and    $0xe40c0513,%eax
 289:	05 01 08 9f 03       	add    $0x39f0801,%eax
 28e:	1e                   	(bad)  
 28f:	2e 05 05 83 e5 ea    	cs add $0xeae58305,%eax
 295:	05 01 a2 ba 05       	add    $0x5baa201,%eax
 29a:	1b ec                	sbb    %esp,%ebp
 29c:	05 08 66 05 0f       	add    $0xf056608,%eax
 2a1:	91                   	xchg   %eax,%ecx
 2a2:	05 05 02 36 14       	add    $0x14360205,%eax
 2a7:	05 07 00 02 04       	add    $0x4020007,%eax
 2ac:	01 67 05             	add    %esp,0x5(%rdi)
 2af:	18 00                	sbb    %al,(%rax)
 2b1:	02 04 01             	add    (%rcx,%rax,1),%al
 2b4:	08 57 05             	or     %dl,0x5(%rdi)
 2b7:	06                   	(bad)  
 2b8:	4c e5 e5             	rex.WR in $0xe5,%eax
 2bb:	05 02 a0 05 01       	add    $0x105a002,%eax
 2c0:	e9 02 17 00 01       	jmp    10019c7 <_end+0xffbc57>
 2c5:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	70 72                	jo     74 <__abi_tag-0x318>
   2:	69 6e 74 66 00 5f 5f 	imul   $0x5f5f0066,0x74(%rsi),%ebp
   9:	6f                   	outsl  %ds:(%rsi),(%dx)
   a:	66 66 5f             	data16 pop %di
   d:	74 00                	je     f <__abi_tag-0x37d>
   f:	5f                   	pop    %rdi
  10:	49                   	rex.WB
  11:	4f 5f                	rex.WRXB pop %r15
  13:	72 65                	jb     7a <__abi_tag-0x312>
  15:	61                   	(bad)  
  16:	64 5f                	fs pop %rdi
  18:	70 74                	jo     8e <__abi_tag-0x2fe>
  1a:	72 00                	jb     1c <__abi_tag-0x370>
  1c:	5f                   	pop    %rdi
  1d:	63 68 61             	movsxd 0x61(%rax),%ebp
  20:	69 6e 00 73 69 7a 65 	imul   $0x657a6973,0x0(%rsi),%ebp
  27:	5f                   	pop    %rdi
  28:	74 00                	je     2a <__abi_tag-0x362>
  2a:	5f                   	pop    %rdi
  2b:	73 68                	jae    95 <__abi_tag-0x2f7>
  2d:	6f                   	outsl  %ds:(%rsi),(%dx)
  2e:	72 74                	jb     a4 <__abi_tag-0x2e8>
  30:	62 75 66 00 5f 49 4f 	vmaxsh 0x9e(%rcx),%xmm19,%xmm9
  37:	5f                   	pop    %rdi
  38:	62 75 66 5f 62       	(bad)
  3d:	61                   	(bad)  
  3e:	73 65                	jae    a5 <__abi_tag-0x2e7>
  40:	00 6c 6f 6e          	add    %ch,0x6e(%rdi,%rbp,2)
  44:	67 20 6c 6f 6e       	and    %ch,0x6e(%edi,%ebp,2)
  49:	67 20 75 6e          	and    %dh,0x6e(%ebp)
  4d:	73 69                	jae    b8 <__abi_tag-0x2d4>
  4f:	67 6e                	outsb  %ds:(%esi),(%dx)
  51:	65 64 20 69 6e       	gs and %ch,%fs:0x6e(%rcx)
  56:	74 00                	je     58 <__abi_tag-0x334>
  58:	72 65                	jb     bf <__abi_tag-0x2cd>
  5a:	61                   	(bad)  
  5b:	64 5f                	fs pop %rdi
  5d:	6c                   	insb   (%dx),%es:(%rdi)
  5e:	69 6e 65 00 6c 6f 6e 	imul   $0x6e6f6c00,0x65(%rsi),%ebp
  65:	67 20 6c 6f 6e       	and    %ch,0x6e(%edi,%ebp,2)
  6a:	67 20 69 6e          	and    %ch,0x6e(%ecx)
  6e:	74 00                	je     70 <__abi_tag-0x31c>
  70:	70 68                	jo     da <__abi_tag-0x2b2>
  72:	61                   	(bad)  
  73:	73 65                	jae    da <__abi_tag-0x2b2>
  75:	5f                   	pop    %rdi
  76:	64 65 66 75 73       	fs gs data16 jne ee <__abi_tag-0x29e>
  7b:	65 64 00 5f 66       	gs add %bl,%fs:0x66(%rdi)
  80:	69 6c 65 6e 6f 00 47 	imul   $0x4e47006f,0x6e(%rbp,%riz,2),%ebp
  87:	4e 
  88:	55                   	push   %rbp
  89:	20 43 31             	and    %al,0x31(%rbx)
  8c:	37                   	(bad)  
  8d:	20 31                	and    %dh,(%rcx)
  8f:	31 2e                	xor    %ebp,(%rsi)
  91:	34 2e                	xor    $0x2e,%al
  93:	30 20                	xor    %ah,(%rax)
  95:	2d 6d 74 75 6e       	sub    $0x6e75746d,%eax
  9a:	65 3d 67 65 6e 65    	gs cmp $0x656e6567,%eax
  a0:	72 69                	jb     10b <__abi_tag-0x281>
  a2:	63 20                	movsxd (%rax),%esp
  a4:	2d 6d 61 72 63       	sub    $0x6372616d,%eax
  a9:	68 3d 78 38 36       	push   $0x3638783d
  ae:	2d 36 34 20 2d       	sub    $0x2d203436,%eax
  b3:	67 20 2d 66 61 73 79 	and    %ch,0x79736166(%eip)        # 79736220 <_end+0x797304b0>
  ba:	6e                   	outsb  %ds:(%rsi),(%dx)
  bb:	63 68 72             	movsxd 0x72(%rax),%ebp
  be:	6f                   	outsl  %ds:(%rsi),(%dx)
  bf:	6e                   	outsb  %ds:(%rsi),(%dx)
  c0:	6f                   	outsl  %ds:(%rsi),(%dx)
  c1:	75 73                	jne    136 <__abi_tag-0x256>
  c3:	2d 75 6e 77 69       	sub    $0x69776e75,%eax
  c8:	6e                   	outsb  %ds:(%rsi),(%dx)
  c9:	64 2d 74 61 62 6c    	fs sub $0x6c626174,%eax
  cf:	65 73 20             	gs jae f2 <__abi_tag-0x29a>
  d2:	2d 66 73 74 61       	sub    $0x61747366,%eax
  d7:	63 6b 2d             	movsxd 0x2d(%rbx),%ebp
  da:	70 72                	jo     14e <__abi_tag-0x23e>
  dc:	6f                   	outsl  %ds:(%rsi),(%dx)
  dd:	74 65                	je     144 <__abi_tag-0x248>
  df:	63 74 6f 72          	movsxd 0x72(%rdi,%rbp,2),%esi
  e3:	2d 73 74 72 6f       	sub    $0x6f727473,%eax
  e8:	6e                   	outsb  %ds:(%rsi),(%dx)
  e9:	67 20 2d 66 73 74 61 	and    %ch,0x61747366(%eip)        # 61747456 <_end+0x617416e6>
  f0:	63 6b 2d             	movsxd 0x2d(%rbx),%ebp
  f3:	63 6c 61 73          	movsxd 0x73(%rcx,%riz,2),%ebp
  f7:	68 2d 70 72 6f       	push   $0x6f72702d
  fc:	74 65                	je     163 <__abi_tag-0x229>
  fe:	63 74 69 6f          	movsxd 0x6f(%rcx,%rbp,2),%esi
 102:	6e                   	outsb  %ds:(%rsi),(%dx)
 103:	20 2d 66 63 66 2d    	and    %ch,0x2d666366(%rip)        # 2d66646f <_end+0x2d6606ff>
 109:	70 72                	jo     17d <__abi_tag-0x20f>
 10b:	6f                   	outsl  %ds:(%rsi),(%dx)
 10c:	74 65                	je     173 <__abi_tag-0x219>
 10e:	63 74 69 6f          	movsxd 0x6f(%rcx,%rbp,2),%esi
 112:	6e                   	outsb  %ds:(%rsi),(%dx)
 113:	00 5f 49             	add    %bl,0x49(%rdi)
 116:	4f 5f                	rex.WRXB pop %r15
 118:	72 65                	jb     17f <__abi_tag-0x20d>
 11a:	61                   	(bad)  
 11b:	64 5f                	fs pop %rdi
 11d:	65 6e                	outsb  %gs:(%rsi),(%dx)
 11f:	64 00 5f 66          	add    %bl,%fs:0x66(%rdi)
 123:	6c                   	insb   (%dx),%es:(%rdi)
 124:	61                   	(bad)  
 125:	67 73 00             	addr32 jae 128 <__abi_tag-0x264>
 128:	5f                   	pop    %rdi
 129:	49                   	rex.WB
 12a:	4f 5f                	rex.WRXB pop %r15
 12c:	62 75 66 5f 65       	(bad)
 131:	6e                   	outsb  %ds:(%rsi),(%dx)
 132:	64 00 5f 63          	add    %bl,%fs:0x63(%rdi)
 136:	75 72                	jne    1aa <__abi_tag-0x1e2>
 138:	5f                   	pop    %rdi
 139:	63 6f 6c             	movsxd 0x6c(%rdi),%ebp
 13c:	75 6d                	jne    1ab <__abi_tag-0x1e1>
 13e:	6e                   	outsb  %ds:(%rsi),(%dx)
 13f:	00 5f 49             	add    %bl,0x49(%rdi)
 142:	4f 5f                	rex.WRXB pop %r15
 144:	63 6f 64             	movsxd 0x64(%rdi),%ebp
 147:	65 63 76 74          	movsxd %gs:0x74(%rsi),%esi
 14b:	00 5f 6f             	add    %bl,0x6f(%rdi)
 14e:	6c                   	insb   (%dx),%es:(%rdi)
 14f:	64 5f                	fs pop %rdi
 151:	6f                   	outsl  %ds:(%rsi),(%dx)
 152:	66 66 73 65          	data16 data16 jae 1bb <__abi_tag-0x1d1>
 156:	74 00                	je     158 <__abi_tag-0x234>
 158:	69 6e 66 69 6c 65 00 	imul   $0x656c69,0x66(%rsi),%ebp
 15f:	69 6e 69 74 69 61 6c 	imul   $0x6c616974,0x69(%rsi),%ebp
 166:	69 7a 65 5f 62 6f 6d 	imul   $0x6d6f625f,0x65(%rdx),%edi
 16d:	62                   	(bad)  
 16e:	00 5f 49             	add    %bl,0x49(%rdi)
 171:	4f 5f                	rex.WRXB pop %r15
 173:	6d                   	insl   (%dx),%es:(%rdi)
 174:	61                   	(bad)  
 175:	72 6b                	jb     1e2 <__abi_tag-0x1aa>
 177:	65 72 00             	gs jb  17a <__abi_tag-0x212>
 17a:	73 74                	jae    1f0 <__abi_tag-0x19c>
 17c:	64 69 6e 00 5f 66 72 	imul   $0x6572665f,%fs:0x0(%rsi),%ebp
 183:	65 
 184:	65 72 65             	gs jb  1ec <__abi_tag-0x1a0>
 187:	73 5f                	jae    1e8 <__abi_tag-0x1a4>
 189:	62 75 66 00 5f 49 4f 	vmaxsh 0x9e(%rcx),%xmm19,%xmm9
 190:	5f                   	pop    %rdi
 191:	77 72                	ja     205 <__abi_tag-0x187>
 193:	69 74 65 5f 70 74 72 	imul   $0x727470,0x5f(%rbp,%riz,2),%esi
 19a:	00 
 19b:	73 68                	jae    205 <__abi_tag-0x187>
 19d:	6f                   	outsl  %ds:(%rsi),(%dx)
 19e:	72 74                	jb     214 <__abi_tag-0x178>
 1a0:	20 75 6e             	and    %dh,0x6e(%rbp)
 1a3:	73 69                	jae    20e <__abi_tag-0x17e>
 1a5:	67 6e                	outsb  %ds:(%esi),(%dx)
 1a7:	65 64 20 69 6e       	gs and %ch,%fs:0x6e(%rcx)
 1ac:	74 00                	je     1ae <__abi_tag-0x1de>
 1ae:	5f                   	pop    %rdi
 1af:	49                   	rex.WB
 1b0:	4f 5f                	rex.WRXB pop %r15
 1b2:	73 61                	jae    215 <__abi_tag-0x177>
 1b4:	76 65                	jbe    21b <__abi_tag-0x171>
 1b6:	5f                   	pop    %rdi
 1b7:	62 61                	(bad)  
 1b9:	73 65                	jae    220 <__abi_tag-0x16c>
 1bb:	00 5f 6c             	add    %bl,0x6c(%rdi)
 1be:	6f                   	outsl  %ds:(%rsi),(%dx)
 1bf:	63 6b 00             	movsxd 0x0(%rbx),%ebp
 1c2:	5f                   	pop    %rdi
 1c3:	66 6c                	data16 insb (%dx),%es:(%rdi)
 1c5:	61                   	(bad)  
 1c6:	67 73 32             	addr32 jae 1fb <__abi_tag-0x191>
 1c9:	00 5f 6d             	add    %bl,0x6d(%rdi)
 1cc:	6f                   	outsl  %ds:(%rsi),(%dx)
 1cd:	64 65 00 5f 49       	fs add %bl,%gs:0x49(%rdi)
 1d2:	4f 5f                	rex.WRXB pop %r15
 1d4:	77 72                	ja     248 <__abi_tag-0x144>
 1d6:	69 74 65 5f 65 6e 64 	imul   $0x646e65,0x5f(%rbp,%riz,2),%esi
 1dd:	00 
 1de:	5f                   	pop    %rdi
 1df:	49                   	rex.WB
 1e0:	4f 5f                	rex.WRXB pop %r15
 1e2:	6c                   	insb   (%dx),%es:(%rdi)
 1e3:	6f                   	outsl  %ds:(%rsi),(%dx)
 1e4:	63 6b 5f             	movsxd 0x5f(%rbx),%ebp
 1e7:	74 00                	je     1e9 <__abi_tag-0x1a3>
 1e9:	5f                   	pop    %rdi
 1ea:	49                   	rex.WB
 1eb:	4f 5f                	rex.WRXB pop %r15
 1ed:	46                   	rex.RX
 1ee:	49                   	rex.WB
 1ef:	4c                   	rex.WR
 1f0:	45 00 66 6f          	add    %r12b,0x6f(%r14)
 1f4:	70 65                	jo     25b <__abi_tag-0x131>
 1f6:	6e                   	outsb  %ds:(%rsi),(%dx)
 1f7:	00 5f 6d             	add    %bl,0x6d(%rdi)
 1fa:	61                   	(bad)  
 1fb:	72 6b                	jb     268 <__abi_tag-0x124>
 1fd:	65 72 73             	gs jb  273 <__abi_tag-0x119>
 200:	00 75 6e             	add    %dh,0x6e(%rbp)
 203:	73 69                	jae    26e <__abi_tag-0x11e>
 205:	67 6e                	outsb  %ds:(%esi),(%dx)
 207:	65 64 20 63 68       	gs and %ah,%fs:0x68(%rbx)
 20c:	61                   	(bad)  
 20d:	72 00                	jb     20f <__abi_tag-0x17d>
 20f:	73 68                	jae    279 <__abi_tag-0x113>
 211:	6f                   	outsl  %ds:(%rsi),(%dx)
 212:	72 74                	jb     288 <__abi_tag-0x104>
 214:	20 69 6e             	and    %ch,0x6e(%rcx)
 217:	74 00                	je     219 <__abi_tag-0x173>
 219:	5f                   	pop    %rdi
 21a:	49                   	rex.WB
 21b:	4f 5f                	rex.WRXB pop %r15
 21d:	77 69                	ja     288 <__abi_tag-0x104>
 21f:	64 65 5f             	fs gs pop %rdi
 222:	64 61                	fs (bad) 
 224:	74 61                	je     287 <__abi_tag-0x105>
 226:	00 5f 76             	add    %bl,0x76(%rdi)
 229:	74 61                	je     28c <__abi_tag-0x100>
 22b:	62                   	(bad)  
 22c:	6c                   	insb   (%dx),%es:(%rdi)
 22d:	65 5f                	gs pop %rdi
 22f:	6f                   	outsl  %ds:(%rsi),(%dx)
 230:	66 66 73 65          	data16 data16 jae 299 <__abi_tag-0xf3>
 234:	74 00                	je     236 <__abi_tag-0x156>
 236:	65 78 69             	gs js  2a2 <__abi_tag-0xea>
 239:	74 00                	je     23b <__abi_tag-0x151>
 23b:	69 6e 70 75 74 00 5f 	imul   $0x5f007475,0x70(%rsi),%ebp
 242:	5f                   	pop    %rdi
 243:	6f                   	outsl  %ds:(%rsi),(%dx)
 244:	66 66 36 34 5f       	data16 data16 ss xor $0x5f,%al
 249:	74 00                	je     24b <__abi_tag-0x141>
 24b:	5f                   	pop    %rdi
 24c:	49                   	rex.WB
 24d:	4f 5f                	rex.WRXB pop %r15
 24f:	72 65                	jb     2b6 <__abi_tag-0xd6>
 251:	61                   	(bad)  
 252:	64 5f                	fs pop %rdi
 254:	62 61                	(bad)  
 256:	73 65                	jae    2bd <__abi_tag-0xcf>
 258:	00 5f 49             	add    %bl,0x49(%rdi)
 25b:	4f 5f                	rex.WRXB pop %r15
 25d:	73 61                	jae    2c0 <__abi_tag-0xcc>
 25f:	76 65                	jbe    2c6 <__abi_tag-0xc6>
 261:	5f                   	pop    %rdi
 262:	65 6e                	outsb  %gs:(%rsi),(%dx)
 264:	64 00 5f 5f          	add    %bl,%fs:0x5f(%rdi)
 268:	70 61                	jo     2cb <__abi_tag-0xc1>
 26a:	64 35 00 5f 75 6e    	fs xor $0x6e755f00,%eax
 270:	75 73                	jne    2e5 <__abi_tag-0xa7>
 272:	65 64 32 00          	gs xor %fs:(%rax),%al
 276:	61                   	(bad)  
 277:	72 67                	jb     2e0 <__abi_tag-0xac>
 279:	76 00                	jbe    27b <__abi_tag-0x111>
 27b:	70 68                	jo     2e5 <__abi_tag-0xa7>
 27d:	61                   	(bad)  
 27e:	73 65                	jae    2e5 <__abi_tag-0xa7>
 280:	5f                   	pop    %rdi
 281:	31 00                	xor    %eax,(%rax)
 283:	70 68                	jo     2ed <__abi_tag-0x9f>
 285:	61                   	(bad)  
 286:	73 65                	jae    2ed <__abi_tag-0x9f>
 288:	5f                   	pop    %rdi
 289:	32 00                	xor    (%rax),%al
 28b:	70 68                	jo     2f5 <__abi_tag-0x97>
 28d:	61                   	(bad)  
 28e:	73 65                	jae    2f5 <__abi_tag-0x97>
 290:	5f                   	pop    %rdi
 291:	33 00                	xor    (%rax),%eax
 293:	70 68                	jo     2fd <__abi_tag-0x8f>
 295:	61                   	(bad)  
 296:	73 65                	jae    2fd <__abi_tag-0x8f>
 298:	5f                   	pop    %rdi
 299:	34 00                	xor    $0x0,%al
 29b:	70 68                	jo     305 <__abi_tag-0x87>
 29d:	61                   	(bad)  
 29e:	73 65                	jae    305 <__abi_tag-0x87>
 2a0:	5f                   	pop    %rdi
 2a1:	35 00 70 68 61       	xor    $0x61687000,%eax
 2a6:	73 65                	jae    30d <__abi_tag-0x7f>
 2a8:	5f                   	pop    %rdi
 2a9:	36 00 5f 49          	ss add %bl,0x49(%rdi)
 2ad:	4f 5f                	rex.WRXB pop %r15
 2af:	62 61                	(bad)  
 2b1:	63 6b 75             	movsxd 0x75(%rbx),%ebp
 2b4:	70 5f                	jo     315 <__abi_tag-0x77>
 2b6:	62 61                	(bad)  
 2b8:	73 65                	jae    31f <__abi_tag-0x6d>
 2ba:	00 61 72             	add    %ah,0x72(%rcx)
 2bd:	67 63 00             	movsxd (%eax),%eax
 2c0:	5f                   	pop    %rdi
 2c1:	66 72 65             	data16 jb 329 <__abi_tag-0x63>
 2c4:	65 72 65             	gs jb  32c <__abi_tag-0x60>
 2c7:	73 5f                	jae    328 <__abi_tag-0x64>
 2c9:	6c                   	insb   (%dx),%es:(%rdi)
 2ca:	69 73 74 00 6d 61 69 	imul   $0x69616d00,0x74(%rbx),%esi
 2d1:	6e                   	outsb  %ds:(%rsi),(%dx)
 2d2:	00 5f 49             	add    %bl,0x49(%rdi)
 2d5:	4f 5f                	rex.WRXB pop %r15
 2d7:	77 72                	ja     34b <__abi_tag-0x41>
 2d9:	69 74 65 5f 62 61 73 	imul   $0x65736162,0x5f(%rbp,%riz,2),%esi
 2e0:	65 
 2e1:	00 5f 49             	add    %bl,0x49(%rdi)
 2e4:	53                   	push   %rbx
 2e5:	63 6e 74             	movsxd 0x74(%rsi),%ebp
 2e8:	72 6c                	jb     356 <__abi_tag-0x36>
 2ea:	00 73 6b             	add    %dh,0x6b(%rbx)
 2ed:	69 70 00 65 78 70 6c 	imul   $0x6c707865,0x0(%rax),%esi
 2f4:	6f                   	outsl  %ds:(%rsi),(%dx)
 2f5:	64 65 5f             	fs gs pop %rdi
 2f8:	62                   	(bad)  
 2f9:	6f                   	outsl  %ds:(%rsi),(%dx)
 2fa:	6d                   	insl   (%dx),%es:(%rdi)
 2fb:	62                   	(bad)  
 2fc:	00 5f 49             	add    %bl,0x49(%rdi)
 2ff:	53                   	push   %rbx
 300:	70 75                	jo     377 <__abi_tag-0x15>
 302:	6e                   	outsb  %ds:(%rsi),(%dx)
 303:	63 74 00 5f          	movsxd 0x5f(%rax,%rax,1),%esi
 307:	49 53                	rex.WB push %r11
 309:	67 72 61             	addr32 jb 36d <__abi_tag-0x1f>
 30c:	70 68                	jo     376 <__abi_tag-0x16>
 30e:	00 69 6e             	add    %ch,0x6e(%rcx)
 311:	76 61                	jbe    374 <__abi_tag-0x18>
 313:	6c                   	insb   (%dx),%es:(%rdi)
 314:	69 64 5f 70 68 61 73 	imul   $0x65736168,0x70(%rdi,%rbx,2),%esp
 31b:	65 
 31c:	00 72 65             	add    %dh,0x65(%rdx)
 31f:	61                   	(bad)  
 320:	64 5f                	fs pop %rdi
 322:	73 69                	jae    38d <__abi_tag+0x1>
 324:	78 5f                	js     385 <__abi_tag-0x7>
 326:	6e                   	outsb  %ds:(%rsi),(%dx)
 327:	75 6d                	jne    396 <__abi_tag+0xa>
 329:	62 65                	(bad)  
 32b:	72 73                	jb     3a0 <__abi_tag+0x14>
 32d:	00 73 74             	add    %dh,0x74(%rbx)
 330:	72 69                	jb     39b <__abi_tag+0xf>
 332:	6e                   	outsb  %ds:(%rsi),(%dx)
 333:	67 73 5f             	addr32 jae 395 <__abi_tag+0x9>
 336:	6e                   	outsb  %ds:(%rsi),(%dx)
 337:	6f                   	outsl  %ds:(%rsi),(%dx)
 338:	74 5f                	je     399 <__abi_tag+0xd>
 33a:	65 71 75             	gs jno 3b2 <__abi_tag+0x26>
 33d:	61                   	(bad)  
 33e:	6c                   	insb   (%dx),%es:(%rdi)
 33f:	00 5f 49             	add    %bl,0x49(%rdi)
 342:	53                   	push   %rbx
 343:	64 69 67 69 74 00 67 	imul   $0x65670074,%fs:0x69(%rdi),%esp
 34a:	65 
 34b:	74 65                	je     3b2 <__abi_tag+0x26>
 34d:	6e                   	outsb  %ds:(%rsi),(%dx)
 34e:	76 00                	jbe    350 <__abi_tag-0x3c>
 350:	66 67 65 74 73       	data16 addr32 gs je 3c8 <__abi_tag+0x3c>
 355:	00 6e 75             	add    %ch,0x75(%rsi)
 358:	6d                   	insl   (%dx),%es:(%rdi)
 359:	5f                   	pop    %rdi
 35a:	69 6e 70 75 74 5f 73 	imul   $0x735f7475,0x70(%rsi),%ebp
 361:	74 72                	je     3d5 <__abi_tag+0x49>
 363:	69 6e 67 73 00 73 65 	imul   $0x65730073,0x67(%rsi),%ebp
 36a:	63 72 65             	movsxd 0x65(%rdx),%esi
 36d:	74 5f                	je     3ce <__abi_tag+0x42>
 36f:	70 68                	jo     3d9 <__abi_tag+0x4d>
 371:	61                   	(bad)  
 372:	73 65                	jae    3d9 <__abi_tag+0x4d>
 374:	00 5f 49             	add    %bl,0x49(%rdi)
 377:	53                   	push   %rbx
 378:	62                   	(bad)  
 379:	6c                   	insb   (%dx),%es:(%rdi)
 37a:	61                   	(bad)  
 37b:	6e                   	outsb  %ds:(%rsi),(%dx)
 37c:	6b 00 5f             	imul   $0x5f,(%rax),%eax
 37f:	49 53                	rex.WB push %r11
 381:	61                   	(bad)  
 382:	6c                   	insb   (%dx),%es:(%rdi)
 383:	6e                   	outsb  %ds:(%rsi),(%dx)
 384:	75 6d                	jne    3f3 <__abi_tag+0x67>
 386:	00 5f 49             	add    %bl,0x49(%rdi)
 389:	53                   	push   %rbx
 38a:	73 70                	jae    3fc <__abi_tag+0x70>
 38c:	61                   	(bad)  
 38d:	63 65 00             	movsxd 0x0(%rbp),%esp
 390:	61                   	(bad)  
 391:	53                   	push   %rbx
 392:	74 72                	je     406 <__abi_tag+0x7a>
 394:	69 6e 67 00 73 63 72 	imul   $0x72637300,0x67(%rsi),%ebp
 39b:	61                   	(bad)  
 39c:	74 63                	je     401 <__abi_tag+0x75>
 39e:	68 00 68 6f 73       	push   $0x736f6800
 3a3:	74 5f                	je     404 <__abi_tag+0x78>
 3a5:	74 61                	je     408 <__abi_tag+0x7c>
 3a7:	62                   	(bad)  
 3a8:	6c                   	insb   (%dx),%es:(%rdi)
 3a9:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 3ad:	73 69                	jae    418 <__abi_tag+0x8c>
 3af:	67 68 61 6e 64 6c    	addr32 push $0x6c646e61
 3b5:	65 72 5f             	gs jb  417 <__abi_tag+0x8b>
 3b8:	74 00                	je     3ba <__abi_tag+0x2e>
 3ba:	5f                   	pop    %rdi
 3bb:	49 53                	rex.WB push %r11
 3bd:	78 64                	js     423 <__abi_tag+0x97>
 3bf:	69 67 69 74 00 5f 5f 	imul   $0x5f5f0074,0x69(%rdi),%esp
 3c6:	69 73 6f 63 39 39 5f 	imul   $0x5f393963,0x6f(%rbx),%esi
 3cd:	73 73                	jae    442 <__abi_tag+0xb6>
 3cf:	63 61 6e             	movsxd 0x6e(%rcx),%esp
 3d2:	66 00 73 6c          	data16 add %dh,0x6c(%rbx)
 3d6:	65 65 70 00          	gs gs jo 3da <__abi_tag+0x4e>
 3da:	73 69                	jae    445 <__abi_tag+0xb9>
 3dc:	67 6e                	outsb  %ds:(%esi),(%dx)
 3de:	61                   	(bad)  
 3df:	6c                   	insb   (%dx),%es:(%rdi)
 3e0:	00 5f 49             	add    %bl,0x49(%rdi)
 3e3:	53                   	push   %rbx
 3e4:	6c                   	insb   (%dx),%es:(%rdi)
 3e5:	6f                   	outsl  %ds:(%rsi),(%dx)
 3e6:	77 65                	ja     44d <__abi_tag+0xc1>
 3e8:	72 00                	jb     3ea <__abi_tag+0x5e>
 3ea:	73 74                	jae    460 <__abi_tag+0xd4>
 3ec:	72 6c                	jb     45a <__abi_tag+0xce>
 3ee:	65 6e                	outsb  %gs:(%rsi),(%dx)
 3f0:	00 62 6c             	add    %ah,0x6c(%rdx)
 3f3:	61                   	(bad)  
 3f4:	6e                   	outsb  %ds:(%rsi),(%dx)
 3f5:	6b 5f 6c 69          	imul   $0x69,0x6c(%rdi),%ebx
 3f9:	6e                   	outsb  %ds:(%rsi),(%dx)
 3fa:	65 00 74 6d 70       	add    %dh,%gs:0x70(%rbp,%rbp,2)
 3ff:	31 00                	xor    %eax,(%rax)
 401:	74 6d                	je     470 <__abi_tag+0xe4>
 403:	70 32                	jo     437 <__abi_tag+0xab>
 405:	00 73 69             	add    %dh,0x69(%rbx)
 408:	67 5f                	addr32 pop %rdi
 40a:	68 61 6e 64 6c       	push   $0x6c646e61
 40f:	65 72 00             	gs jb  412 <__abi_tag+0x86>
 412:	66 66 6c             	data16 data16 insb (%dx),%es:(%rdi)
 415:	75 73                	jne    48a <__abi_tag+0xfe>
 417:	68 00 70 61 73       	push   $0x73617000
 41c:	73 70                	jae    48e <__abi_tag+0x102>
 41e:	68 72 61 73 65       	push   $0x65736172
 423:	00 6e 75             	add    %ch,0x75(%rsi)
 426:	6d                   	insl   (%dx),%es:(%rdi)
 427:	53                   	push   %rbx
 428:	63 61 6e             	movsxd 0x6e(%rcx),%esp
 42b:	6e                   	outsb  %ds:(%rsi),(%dx)
 42c:	65 64 00 73 74       	gs add %dh,%fs:0x74(%rbx)
 431:	72 69                	jb     49c <__abi_tag+0x110>
 433:	6e                   	outsb  %ds:(%rsi),(%dx)
 434:	67 31 00             	xor    %eax,(%eax)
 437:	73 74                	jae    4ad <__abi_tag+0x121>
 439:	72 69                	jb     4a4 <__abi_tag+0x118>
 43b:	6e                   	outsb  %ds:(%rsi),(%dx)
 43c:	67 32 00             	xor    (%eax),%al
 43f:	5f                   	pop    %rdi
 440:	5f                   	pop    %rdi
 441:	63 74 79 70          	movsxd 0x70(%rcx,%rdi,2),%esi
 445:	65 5f                	gs pop %rdi
 447:	62                   	(bad)  
 448:	5f                   	pop    %rdi
 449:	6c                   	insb   (%dx),%es:(%rdi)
 44a:	6f                   	outsl  %ds:(%rsi),(%dx)
 44b:	63 00                	movsxd (%rax),%eax
 44d:	5f                   	pop    %rdi
 44e:	49 53                	rex.WB push %r11
 450:	70 72                	jo     4c4 <__abi_tag+0x138>
 452:	69 6e 74 00 5f 49 53 	imul   $0x53495f00,0x74(%rsi),%ebp
 459:	75 70                	jne    4cb <__abi_tag+0x13f>
 45b:	70 65                	jo     4c2 <__abi_tag+0x136>
 45d:	72 00                	jb     45f <__abi_tag+0xd3>
 45f:	69 6e 69 74 69 61 6c 	imul   $0x6c616974,0x69(%rsi),%ebp
 466:	69 7a 65 5f 62 6f 6d 	imul   $0x6d6f625f,0x65(%rdx),%edi
 46d:	62                   	(bad)  
 46e:	5f                   	pop    %rdi
 46f:	73 6f                	jae    4e0 <__abi_tag+0x154>
 471:	6c                   	insb   (%dx),%es:(%rdi)
 472:	76 65                	jbe    4d9 <__abi_tag+0x14d>
 474:	00 5f 49             	add    %bl,0x49(%rdi)
 477:	53                   	push   %rbx
 478:	61                   	(bad)  
 479:	6c                   	insb   (%dx),%es:(%rdi)
 47a:	70 68                	jo     4e4 <__abi_tag+0x158>
 47c:	61                   	(bad)  
 47d:	00 73 74             	add    %dh,0x74(%rbx)
 480:	64 6f                	outsl  %fs:(%rsi),(%dx)
 482:	75 74                	jne    4f8 <__abi_tag+0x16c>
 484:	00 73 74             	add    %dh,0x74(%rbx)
 487:	72 69                	jb     4f2 <__abi_tag+0x166>
 489:	6e                   	outsb  %ds:(%rsi),(%dx)
 48a:	67 5f                	addr32 pop %rdi
 48c:	6c                   	insb   (%dx),%es:(%rdi)
 48d:	65 6e                	outsb  %gs:(%rsi),(%dx)
 48f:	67 74 68             	addr32 je 4fa <__abi_tag+0x16e>
	...

Disassembly of section .debug_line_str:

0000000000000000 <.debug_line_str>:
   0:	2f                   	(bad)  
   1:	68 6f 6d 65 2f       	push   $0x2f656d6f
   6:	70 75                	jo     7d <__abi_tag-0x30f>
   8:	72 65                	jb     6f <__abi_tag-0x31d>
   a:	69 6e 2f e6 a1 8c e9 	imul   $0xe98ca1e6,0x2f(%rsi),%ebp
  11:	9d                   	popf   
  12:	a2 2f e6 96 b0 e5 bb 	movabs %al,0xe6babbe5b096e62f
  19:	ba e6 
  1b:	96                   	xchg   %eax,%esi
  1c:	87 e4                	xchg   %esp,%esp
  1e:	bb b6 e5 a4 b9       	mov    $0xb9a4e5b6,%ebx
  23:	2f                   	(bad)  
  24:	e5 ae                	in     $0xae,%eax
  26:	9e                   	sahf   
  27:	e9 aa 8c 32 e4       	jmp    ffffffffe4328cd6 <_end+0xffffffffe4322f66>
  2c:	bb bb e5 8a a1       	mov    $0xa18ae5bb,%ebx
  31:	e4 b9                	in     $0xb9,%al
  33:	a6                   	cmpsb  %es:(%rdi),%ds:(%rsi)
  34:	2f                   	(bad)  
  35:	e5 ae                	in     $0xae,%eax
  37:	9e                   	sahf   
  38:	e9 aa 8c 32 5f       	jmp    5f328ce7 <_end+0x5f322f77>
  3d:	e4 ba                	in     $0xba,%al
  3f:	8c e8                	mov    %gs,%eax
  41:	bf 9b e5 88 b6       	mov    $0xb688e59b,%edi
  46:	e7 a8                	out    %eax,$0xa8
  48:	8b e5                	mov    %ebp,%esp
  4a:	ba 8f e5 88 86       	mov    $0x8688e58f,%edx
  4f:	e6 9e                	out    %al,$0x9e
  51:	90                   	nop
  52:	2f                   	(bad)  
  53:	62                   	(bad)  
  54:	6f                   	outsl  %ds:(%rsi),(%dx)
  55:	6d                   	insl   (%dx),%es:(%rdi)
  56:	62                   	(bad)  
  57:	5f                   	pop    %rdi
  58:	73 74                	jae    ce <__abi_tag-0x2be>
  5a:	75 64                	jne    c0 <__abi_tag-0x2cc>
  5c:	65 6e                	outsb  %gs:(%rsi),(%dx)
  5e:	74 00                	je     60 <__abi_tag-0x32c>
  60:	62                   	(bad)  
  61:	6f                   	outsl  %ds:(%rsi),(%dx)
  62:	6d                   	insl   (%dx),%es:(%rdi)
  63:	62                   	(bad)  
  64:	2e 63 00             	cs movsxd (%rax),%eax
  67:	2f                   	(bad)  
  68:	75 73                	jne    dd <__abi_tag-0x2af>
  6a:	72 2f                	jb     9b <__abi_tag-0x2f1>
  6c:	6c                   	insb   (%dx),%es:(%rdi)
  6d:	69 62 2f 67 63 63 2f 	imul   $0x2f636367,0x2f(%rdx),%esp
  74:	78 38                	js     ae <__abi_tag-0x2de>
  76:	36 5f                	ss pop %rdi
  78:	36 34 2d             	ss xor $0x2d,%al
  7b:	6c                   	insb   (%dx),%es:(%rdi)
  7c:	69 6e 75 78 2d 67 6e 	imul   $0x6e672d78,0x75(%rsi),%ebp
  83:	75 2f                	jne    b4 <__abi_tag-0x2d8>
  85:	31 31                	xor    %esi,(%rcx)
  87:	2f                   	(bad)  
  88:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  8f:	00 2f                	add    %ch,(%rdi)
  91:	75 73                	jne    106 <__abi_tag-0x286>
  93:	72 2f                	jb     c4 <__abi_tag-0x2c8>
  95:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  9c:	2f                   	(bad)  
  9d:	78 38                	js     d7 <__abi_tag-0x2b5>
  9f:	36 5f                	ss pop %rdi
  a1:	36 34 2d             	ss xor $0x2d,%al
  a4:	6c                   	insb   (%dx),%es:(%rdi)
  a5:	69 6e 75 78 2d 67 6e 	imul   $0x6e672d78,0x75(%rsi),%ebp
  ac:	75 2f                	jne    dd <__abi_tag-0x2af>
  ae:	62                   	(bad)  
  af:	69 74 73 00 2f 75 73 	imul   $0x7273752f,0x0(%rbx,%rsi,2),%esi
  b6:	72 
  b7:	2f                   	(bad)  
  b8:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  bf:	2f                   	(bad)  
  c0:	78 38                	js     fa <__abi_tag-0x292>
  c2:	36 5f                	ss pop %rdi
  c4:	36 34 2d             	ss xor $0x2d,%al
  c7:	6c                   	insb   (%dx),%es:(%rdi)
  c8:	69 6e 75 78 2d 67 6e 	imul   $0x6e672d78,0x75(%rsi),%ebp
  cf:	75 2f                	jne    100 <__abi_tag-0x28c>
  d1:	62                   	(bad)  
  d2:	69 74 73 2f 74 79 70 	imul   $0x65707974,0x2f(%rbx,%rsi,2),%esi
  d9:	65 
  da:	73 00                	jae    dc <__abi_tag-0x2b0>
  dc:	2f                   	(bad)  
  dd:	75 73                	jne    152 <__abi_tag-0x23a>
  df:	72 2f                	jb     110 <__abi_tag-0x27c>
  e1:	69 6e 63 6c 75 64 65 	imul   $0x6564756c,0x63(%rsi),%ebp
  e8:	00 73 74             	add    %dh,0x74(%rbx)
  eb:	64 64 65 66 2e 68 00 	fs fs gs cs pushw $0x7400
  f2:	74 
  f3:	79 70                	jns    165 <__abi_tag-0x227>
  f5:	65 73 2e             	gs jae 126 <__abi_tag-0x266>
  f8:	68 00 73 74 72       	push   $0x72747300
  fd:	75 63                	jne    162 <__abi_tag-0x22a>
  ff:	74 5f                	je     160 <__abi_tag-0x22c>
 101:	46                   	rex.RX
 102:	49                   	rex.WB
 103:	4c                   	rex.WR
 104:	45                   	rex.RB
 105:	2e 68 00 73 74 64    	cs push $0x64747300
 10b:	69 6f 2e 68 00 70 68 	imul   $0x68700068,0x2e(%rdi),%ebp
 112:	61                   	(bad)  
 113:	73 65                	jae    17a <__abi_tag-0x212>
 115:	73 2e                	jae    145 <__abi_tag-0x247>
 117:	68 00 73 75 70       	push   $0x70757300
 11c:	70 6f                	jo     18d <__abi_tag-0x1ff>
 11e:	72 74                	jb     194 <__abi_tag-0x1f8>
 120:	2e 68 00 73 74 64    	cs push $0x64747300
 126:	6c                   	insb   (%dx),%es:(%rdi)
 127:	69 62 2e 68 00 73 75 	imul   $0x75730068,0x2e(%rdx),%esp
 12e:	70 70                	jo     1a0 <__abi_tag-0x1ec>
 130:	6f                   	outsl  %ds:(%rsi),(%dx)
 131:	72 74                	jb     1a7 <__abi_tag-0x1e5>
 133:	2e 63 00             	cs movsxd (%rax),%eax
 136:	73 69                	jae    1a1 <__abi_tag-0x1eb>
 138:	67 6e                	outsb  %ds:(%esi),(%dx)
 13a:	61                   	(bad)  
 13b:	6c                   	insb   (%dx),%es:(%rdi)
 13c:	2e 68 00 63 6f 6e    	cs push $0x6e6f6300
 142:	66 69 67 2e 68 00    	imul   $0x68,0x2e(%rdi),%sp
 148:	73 74                	jae    1be <__abi_tag-0x1ce>
 14a:	72 69                	jb     1b5 <__abi_tag-0x1d7>
 14c:	6e                   	outsb  %ds:(%rsi),(%dx)
 14d:	67 2e 68 00 75 6e 69 	addr32 cs push $0x696e7500
 154:	73 74                	jae    1ca <__abi_tag-0x1c2>
 156:	64 2e 68 00 63 74 79 	fs cs push $0x79746300
 15d:	70 65                	jo     1c4 <__abi_tag-0x1c8>
 15f:	2e                   	cs
 160:	68                   	.byte 0x68
	...
