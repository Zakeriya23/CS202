
ok_mult:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 8a 2f 00 00    	push   0x2f8a(%rip)        # 3fb0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 8b 2f 00 00 	bnd jmp *0x2f8b(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x10>
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

Disassembly of section .plt.got:

0000000000001060 <__cxa_finalize@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 8d 2f 00 00 	bnd jmp *0x2f8d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001070 <__stack_chk_fail@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 45 2f 00 00 	bnd jmp *0x2f45(%rip)        # 3fc0 <__stack_chk_fail@GLIBC_2.4>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001080 <printf@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 3d 2f 00 00 	bnd jmp *0x2f3d(%rip)        # 3fc8 <printf@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <__assert_fail@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 35 2f 00 00 	bnd jmp *0x2f35(%rip)        # 3fd0 <__assert_fail@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010a0 <_start>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	31 ed                	xor    %ebp,%ebp
    10a6:	49 89 d1             	mov    %rdx,%r9
    10a9:	5e                   	pop    %rsi
    10aa:	48 89 e2             	mov    %rsp,%rdx
    10ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10b1:	50                   	push   %rax
    10b2:	54                   	push   %rsp
    10b3:	45 31 c0             	xor    %r8d,%r8d
    10b6:	31 c9                	xor    %ecx,%ecx
    10b8:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 1189 <main>
    10bf:	ff 15 13 2f 00 00    	call   *0x2f13(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    10c5:	f4                   	hlt    
    10c6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10cd:	00 00 00 

00000000000010d0 <deregister_tm_clones>:
    10d0:	48 8d 3d 39 2f 00 00 	lea    0x2f39(%rip),%rdi        # 4010 <__TMC_END__>
    10d7:	48 8d 05 32 2f 00 00 	lea    0x2f32(%rip),%rax        # 4010 <__TMC_END__>
    10de:	48 39 f8             	cmp    %rdi,%rax
    10e1:	74 15                	je     10f8 <deregister_tm_clones+0x28>
    10e3:	48 8b 05 f6 2e 00 00 	mov    0x2ef6(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10ea:	48 85 c0             	test   %rax,%rax
    10ed:	74 09                	je     10f8 <deregister_tm_clones+0x28>
    10ef:	ff e0                	jmp    *%rax
    10f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10f8:	c3                   	ret    
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <register_tm_clones>:
    1100:	48 8d 3d 09 2f 00 00 	lea    0x2f09(%rip),%rdi        # 4010 <__TMC_END__>
    1107:	48 8d 35 02 2f 00 00 	lea    0x2f02(%rip),%rsi        # 4010 <__TMC_END__>
    110e:	48 29 fe             	sub    %rdi,%rsi
    1111:	48 89 f0             	mov    %rsi,%rax
    1114:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1118:	48 c1 f8 03          	sar    $0x3,%rax
    111c:	48 01 c6             	add    %rax,%rsi
    111f:	48 d1 fe             	sar    %rsi
    1122:	74 14                	je     1138 <register_tm_clones+0x38>
    1124:	48 8b 05 c5 2e 00 00 	mov    0x2ec5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    112b:	48 85 c0             	test   %rax,%rax
    112e:	74 08                	je     1138 <register_tm_clones+0x38>
    1130:	ff e0                	jmp    *%rax
    1132:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1138:	c3                   	ret    
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <__do_global_dtors_aux>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	80 3d c5 2e 00 00 00 	cmpb   $0x0,0x2ec5(%rip)        # 4010 <__TMC_END__>
    114b:	75 2b                	jne    1178 <__do_global_dtors_aux+0x38>
    114d:	55                   	push   %rbp
    114e:	48 83 3d a2 2e 00 00 	cmpq   $0x0,0x2ea2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1155:	00 
    1156:	48 89 e5             	mov    %rsp,%rbp
    1159:	74 0c                	je     1167 <__do_global_dtors_aux+0x27>
    115b:	48 8b 3d a6 2e 00 00 	mov    0x2ea6(%rip),%rdi        # 4008 <__dso_handle>
    1162:	e8 f9 fe ff ff       	call   1060 <__cxa_finalize@plt>
    1167:	e8 64 ff ff ff       	call   10d0 <deregister_tm_clones>
    116c:	c6 05 9d 2e 00 00 01 	movb   $0x1,0x2e9d(%rip)        # 4010 <__TMC_END__>
    1173:	5d                   	pop    %rbp
    1174:	c3                   	ret    
    1175:	0f 1f 00             	nopl   (%rax)
    1178:	c3                   	ret    
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <frame_dummy>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	e9 77 ff ff ff       	jmp    1100 <register_tm_clones>

0000000000001189 <main>:
    1189:	f3 0f 1e fa          	endbr64 
    118d:	55                   	push   %rbp
    118e:	48 89 e5             	mov    %rsp,%rbp
    1191:	48 83 ec 40          	sub    $0x40,%rsp
    1195:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    119c:	00 00 
    119e:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11a2:	31 c0                	xor    %eax,%eax
    11a4:	c7 45 d8 9b c4 20 00 	movl   $0x20c49b,-0x28(%rbp)
    11ab:	c7 45 dc 0a 00 00 00 	movl   $0xa,-0x24(%rbp)
    11b2:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%rbp)
    11b9:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
    11c0:	48 8d 55 d4          	lea    -0x2c(%rbp),%rdx
    11c4:	8b 4d dc             	mov    -0x24(%rbp),%ecx
    11c7:	8b 45 d8             	mov    -0x28(%rbp),%eax
    11ca:	89 ce                	mov    %ecx,%esi
    11cc:	89 c7                	mov    %eax,%edi
    11ce:	e8 4e 02 00 00       	call   1421 <ok_mult_int>
    11d3:	89 45 e0             	mov    %eax,-0x20(%rbp)
    11d6:	83 7d e0 00          	cmpl   $0x0,-0x20(%rbp)
    11da:	75 09                	jne    11e5 <main+0x5c>
    11dc:	48 8d 05 25 0e 00 00 	lea    0xe25(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    11e3:	eb 07                	jmp    11ec <main+0x63>
    11e5:	48 8d 05 20 0e 00 00 	lea    0xe20(%rip),%rax        # 200c <_IO_stdin_used+0xc>
    11ec:	8b 4d d4             	mov    -0x2c(%rbp),%ecx
    11ef:	8b 55 dc             	mov    -0x24(%rbp),%edx
    11f2:	8b 75 d8             	mov    -0x28(%rbp),%esi
    11f5:	49 89 c0             	mov    %rax,%r8
    11f8:	48 8d 05 11 0e 00 00 	lea    0xe11(%rip),%rax        # 2010 <_IO_stdin_used+0x10>
    11ff:	48 89 c7             	mov    %rax,%rdi
    1202:	b8 00 00 00 00       	mov    $0x0,%eax
    1207:	e8 74 fe ff ff       	call   1080 <printf@plt>
    120c:	83 7d e0 00          	cmpl   $0x0,-0x20(%rbp)
    1210:	74 28                	je     123a <main+0xb1>
    1212:	48 8d 05 df 0e 00 00 	lea    0xedf(%rip),%rax        # 20f8 <__PRETTY_FUNCTION__.0>
    1219:	48 89 c1             	mov    %rax,%rcx
    121c:	ba 19 00 00 00       	mov    $0x19,%edx
    1221:	48 8d 05 17 0e 00 00 	lea    0xe17(%rip),%rax        # 203f <_IO_stdin_used+0x3f>
    1228:	48 89 c6             	mov    %rax,%rsi
    122b:	48 8d 05 17 0e 00 00 	lea    0xe17(%rip),%rax        # 2049 <_IO_stdin_used+0x49>
    1232:	48 89 c7             	mov    %rax,%rdi
    1235:	e8 56 fe ff ff       	call   1090 <__assert_fail@plt>
    123a:	c7 45 e4 ff ff ff 7f 	movl   $0x7fffffff,-0x1c(%rbp)
    1241:	c7 45 e8 e8 03 00 00 	movl   $0x3e8,-0x18(%rbp)
    1248:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%rbp)
    124f:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    1256:	48 8d 55 d4          	lea    -0x2c(%rbp),%rdx
    125a:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    125d:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1260:	89 ce                	mov    %ecx,%esi
    1262:	89 c7                	mov    %eax,%edi
    1264:	e8 b8 01 00 00       	call   1421 <ok_mult_int>
    1269:	89 45 ec             	mov    %eax,-0x14(%rbp)
    126c:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
    1270:	75 09                	jne    127b <main+0xf2>
    1272:	48 8d 05 8f 0d 00 00 	lea    0xd8f(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    1279:	eb 07                	jmp    1282 <main+0xf9>
    127b:	48 8d 05 8a 0d 00 00 	lea    0xd8a(%rip),%rax        # 200c <_IO_stdin_used+0xc>
    1282:	8b 4d d4             	mov    -0x2c(%rbp),%ecx
    1285:	8b 55 e8             	mov    -0x18(%rbp),%edx
    1288:	8b 75 e4             	mov    -0x1c(%rbp),%esi
    128b:	49 89 c0             	mov    %rax,%r8
    128e:	48 8d 05 c3 0d 00 00 	lea    0xdc3(%rip),%rax        # 2058 <_IO_stdin_used+0x58>
    1295:	48 89 c7             	mov    %rax,%rdi
    1298:	b8 00 00 00 00       	mov    $0x0,%eax
    129d:	e8 de fd ff ff       	call   1080 <printf@plt>
    12a2:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
    12a6:	74 28                	je     12d0 <main+0x147>
    12a8:	48 8d 05 49 0e 00 00 	lea    0xe49(%rip),%rax        # 20f8 <__PRETTY_FUNCTION__.0>
    12af:	48 89 c1             	mov    %rax,%rcx
    12b2:	ba 23 00 00 00       	mov    $0x23,%edx
    12b7:	48 8d 05 81 0d 00 00 	lea    0xd81(%rip),%rax        # 203f <_IO_stdin_used+0x3f>
    12be:	48 89 c6             	mov    %rax,%rsi
    12c1:	48 8d 05 be 0d 00 00 	lea    0xdbe(%rip),%rax        # 2086 <_IO_stdin_used+0x86>
    12c8:	48 89 c7             	mov    %rax,%rdi
    12cb:	e8 c0 fd ff ff       	call   1090 <__assert_fail@plt>
    12d0:	66 c7 45 cc d0 07    	movw   $0x7d0,-0x34(%rbp)
    12d6:	66 c7 45 ce 0a 00    	movw   $0xa,-0x32(%rbp)
    12dc:	66 c7 45 d4 00 00    	movw   $0x0,-0x2c(%rbp)
    12e2:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
    12e9:	0f bf 4d ce          	movswl -0x32(%rbp),%ecx
    12ed:	0f bf 45 cc          	movswl -0x34(%rbp),%eax
    12f1:	48 8d 55 d4          	lea    -0x2c(%rbp),%rdx
    12f5:	89 ce                	mov    %ecx,%esi
    12f7:	89 c7                	mov    %eax,%edi
    12f9:	e8 59 01 00 00       	call   1457 <ok_mult_short>
    12fe:	89 45 f0             	mov    %eax,-0x10(%rbp)
    1301:	83 7d f0 00          	cmpl   $0x0,-0x10(%rbp)
    1305:	75 09                	jne    1310 <main+0x187>
    1307:	48 8d 05 fa 0c 00 00 	lea    0xcfa(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    130e:	eb 07                	jmp    1317 <main+0x18e>
    1310:	48 8d 05 f5 0c 00 00 	lea    0xcf5(%rip),%rax        # 200c <_IO_stdin_used+0xc>
    1317:	0f b7 55 d4          	movzwl -0x2c(%rbp),%edx
    131b:	0f bf ca             	movswl %dx,%ecx
    131e:	0f bf 55 ce          	movswl -0x32(%rbp),%edx
    1322:	0f bf 75 cc          	movswl -0x34(%rbp),%esi
    1326:	49 89 c0             	mov    %rax,%r8
    1329:	48 8d 05 60 0d 00 00 	lea    0xd60(%rip),%rax        # 2090 <_IO_stdin_used+0x90>
    1330:	48 89 c7             	mov    %rax,%rdi
    1333:	b8 00 00 00 00       	mov    $0x0,%eax
    1338:	e8 43 fd ff ff       	call   1080 <printf@plt>
    133d:	83 7d f0 00          	cmpl   $0x0,-0x10(%rbp)
    1341:	74 28                	je     136b <main+0x1e2>
    1343:	48 8d 05 ae 0d 00 00 	lea    0xdae(%rip),%rax        # 20f8 <__PRETTY_FUNCTION__.0>
    134a:	48 89 c1             	mov    %rax,%rcx
    134d:	ba 2f 00 00 00       	mov    $0x2f,%edx
    1352:	48 8d 05 e6 0c 00 00 	lea    0xce6(%rip),%rax        # 203f <_IO_stdin_used+0x3f>
    1359:	48 89 c6             	mov    %rax,%rsi
    135c:	48 8d 05 e6 0c 00 00 	lea    0xce6(%rip),%rax        # 2049 <_IO_stdin_used+0x49>
    1363:	48 89 c7             	mov    %rax,%rdi
    1366:	e8 25 fd ff ff       	call   1090 <__assert_fail@plt>
    136b:	66 c7 45 d0 ff 7f    	movw   $0x7fff,-0x30(%rbp)
    1371:	66 c7 45 d2 e8 03    	movw   $0x3e8,-0x2e(%rbp)
    1377:	66 c7 45 d4 00 00    	movw   $0x0,-0x2c(%rbp)
    137d:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1384:	0f bf 4d d2          	movswl -0x2e(%rbp),%ecx
    1388:	0f bf 45 d0          	movswl -0x30(%rbp),%eax
    138c:	48 8d 55 d4          	lea    -0x2c(%rbp),%rdx
    1390:	89 ce                	mov    %ecx,%esi
    1392:	89 c7                	mov    %eax,%edi
    1394:	e8 be 00 00 00       	call   1457 <ok_mult_short>
    1399:	89 45 f4             	mov    %eax,-0xc(%rbp)
    139c:	83 7d f4 00          	cmpl   $0x0,-0xc(%rbp)
    13a0:	75 09                	jne    13ab <main+0x222>
    13a2:	48 8d 05 5f 0c 00 00 	lea    0xc5f(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    13a9:	eb 07                	jmp    13b2 <main+0x229>
    13ab:	48 8d 05 5a 0c 00 00 	lea    0xc5a(%rip),%rax        # 200c <_IO_stdin_used+0xc>
    13b2:	0f b7 55 d4          	movzwl -0x2c(%rbp),%edx
    13b6:	0f bf ca             	movswl %dx,%ecx
    13b9:	0f bf 55 d2          	movswl -0x2e(%rbp),%edx
    13bd:	0f bf 75 d0          	movswl -0x30(%rbp),%esi
    13c1:	49 89 c0             	mov    %rax,%r8
    13c4:	48 8d 05 fd 0c 00 00 	lea    0xcfd(%rip),%rax        # 20c8 <_IO_stdin_used+0xc8>
    13cb:	48 89 c7             	mov    %rax,%rdi
    13ce:	b8 00 00 00 00       	mov    $0x0,%eax
    13d3:	e8 a8 fc ff ff       	call   1080 <printf@plt>
    13d8:	83 7d f4 01          	cmpl   $0x1,-0xc(%rbp)
    13dc:	74 28                	je     1406 <main+0x27d>
    13de:	48 8d 05 13 0d 00 00 	lea    0xd13(%rip),%rax        # 20f8 <__PRETTY_FUNCTION__.0>
    13e5:	48 89 c1             	mov    %rax,%rcx
    13e8:	ba 39 00 00 00       	mov    $0x39,%edx
    13ed:	48 8d 05 4b 0c 00 00 	lea    0xc4b(%rip),%rax        # 203f <_IO_stdin_used+0x3f>
    13f4:	48 89 c6             	mov    %rax,%rsi
    13f7:	48 8d 05 88 0c 00 00 	lea    0xc88(%rip),%rax        # 2086 <_IO_stdin_used+0x86>
    13fe:	48 89 c7             	mov    %rax,%rdi
    1401:	e8 8a fc ff ff       	call   1090 <__assert_fail@plt>
    1406:	b8 00 00 00 00       	mov    $0x0,%eax
    140b:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    140f:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    1416:	00 00 
    1418:	74 05                	je     141f <main+0x296>
    141a:	e8 51 fc ff ff       	call   1070 <__stack_chk_fail@plt>
    141f:	c9                   	leave  
    1420:	c3                   	ret    

0000000000001421 <ok_mult_int>:
    1421:	f3 0f 1e fa          	endbr64 
    1425:	55                   	push   %rbp
    1426:	48 89 e5             	mov    %rsp,%rbp
    1429:	89 7d ec             	mov    %edi,-0x14(%rbp)
    142c:	89 75 e8             	mov    %esi,-0x18(%rbp)
    142f:	48 89 55 e0          	mov    %rdx,-0x20(%rbp)
    1433:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    143a:	8b 45 ec             	mov    -0x14(%rbp),%eax
    143d:	0f af 45 e8          	imul   -0x18(%rbp),%eax
    1441:	89 c2                	mov    %eax,%edx
    1443:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1447:	89 10                	mov    %edx,(%rax)
    1449:	0f 90 c2             	seto   %dl
    144c:	0f b6 c2             	movzbl %dl,%eax
    144f:	89 45 fc             	mov    %eax,-0x4(%rbp)
    1452:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1455:	5d                   	pop    %rbp
    1456:	c3                   	ret    

0000000000001457 <ok_mult_short>:
    1457:	f3 0f 1e fa          	endbr64 
    145b:	55                   	push   %rbp
    145c:	48 89 e5             	mov    %rsp,%rbp
    145f:	89 f9                	mov    %edi,%ecx
    1461:	89 f0                	mov    %esi,%eax
    1463:	48 89 55 e0          	mov    %rdx,-0x20(%rbp)
    1467:	89 ca                	mov    %ecx,%edx
    1469:	66 89 55 ec          	mov    %dx,-0x14(%rbp)
    146d:	66 89 45 e8          	mov    %ax,-0x18(%rbp)
    1471:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
    1478:	0f b7 55 ec          	movzwl -0x14(%rbp),%edx
    147c:	0f b7 45 e8          	movzwl -0x18(%rbp),%eax
    1480:	0f af c2             	imul   %edx,%eax
    1483:	89 c2                	mov    %eax,%edx
    1485:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1489:	66 89 10             	mov    %dx,(%rax)
    148c:	0f 90 c2             	seto   %dl
    148f:	0f b6 c2             	movzbl %dl,%eax
    1492:	89 45 fc             	mov    %eax,-0x4(%rbp)
    1495:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1498:	5d                   	pop    %rbp
    1499:	c3                   	ret    

Disassembly of section .fini:

000000000000149c <_fini>:
    149c:	f3 0f 1e fa          	endbr64 
    14a0:	48 83 ec 08          	sub    $0x8,%rsp
    14a4:	48 83 c4 08          	add    $0x8,%rsp
    14a8:	c3                   	ret    
