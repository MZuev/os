	.code64
	.extern c_hand

#define INTERRUPT(n)\
handler##n:\
	push $0;\
	push $##n;\
	jmp start_hand\


#define EXCEPTION(n)\
handler##n:\
	push $##n;\
	jmp start_hand\


start_hand:
	mov  (%rsp), %rdi
	
	push %rdi	
	push %rax
	push %rbx
	push %rcx
	push %rdx
	push %rbp
	push %rsi
	push %r8
	push %r9
	push %r10
	push %r11
	push %r12
	push %r13
	push %r14
	push %r15

	cld
	call c_hand

	pop %r15
	pop %r14
	pop %r13
	pop %r12
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rsi
	pop %rbp
	pop %rdx
	pop %rcx
	pop %rbx
	pop %rax
	pop %rdi

	add $16, %rsp

	iretq

INTERRUPT(0)
INTERRUPT(1)
INTERRUPT(2)
INTERRUPT(3)
INTERRUPT(4)
INTERRUPT(5)
INTERRUPT(6)
INTERRUPT(7)
EXCEPTION(8)
INTERRUPT(9)
EXCEPTION(10)
EXCEPTION(11)
EXCEPTION(12)
EXCEPTION(13)
EXCEPTION(14)
INTERRUPT(15)
INTERRUPT(16)
EXCEPTION(17)
INTERRUPT(18)
INTERRUPT(19)
INTERRUPT(20)
INTERRUPT(21)
INTERRUPT(22)
INTERRUPT(23)
INTERRUPT(24)
INTERRUPT(25)
INTERRUPT(26)
INTERRUPT(27)
INTERRUPT(28)
INTERRUPT(29)
INTERRUPT(30)
INTERRUPT(31)
INTERRUPT(32)
INTERRUPT(33)
INTERRUPT(34)
INTERRUPT(35)
INTERRUPT(36)
INTERRUPT(37)
INTERRUPT(38)
INTERRUPT(39)
INTERRUPT(40)
INTERRUPT(41)
INTERRUPT(42)
INTERRUPT(43)
INTERRUPT(44)
INTERRUPT(45)
INTERRUPT(46)
INTERRUPT(47)
INTERRUPT(48)
INTERRUPT(49)
INTERRUPT(50)
INTERRUPT(51)
INTERRUPT(52)
INTERRUPT(53)
INTERRUPT(54)
INTERRUPT(55)
INTERRUPT(56)
INTERRUPT(57)
INTERRUPT(58)
INTERRUPT(59)
INTERRUPT(60)
INTERRUPT(61)
INTERRUPT(62)
INTERRUPT(63)
INTERRUPT(64)
INTERRUPT(65)
INTERRUPT(66)
INTERRUPT(67)
INTERRUPT(68)
INTERRUPT(69)
INTERRUPT(70)
INTERRUPT(71)
INTERRUPT(72)
INTERRUPT(73)
INTERRUPT(74)
INTERRUPT(75)
INTERRUPT(76)
INTERRUPT(77)
INTERRUPT(78)
INTERRUPT(79)
INTERRUPT(80)
INTERRUPT(81)
INTERRUPT(82)
INTERRUPT(83)
INTERRUPT(84)
INTERRUPT(85)
INTERRUPT(86)
INTERRUPT(87)
INTERRUPT(88)
INTERRUPT(89)
INTERRUPT(90)
INTERRUPT(91)
INTERRUPT(92)
INTERRUPT(93)
INTERRUPT(94)
INTERRUPT(95)
INTERRUPT(96)
INTERRUPT(97)
INTERRUPT(98)
INTERRUPT(99)
INTERRUPT(100)
INTERRUPT(101)
INTERRUPT(102)
INTERRUPT(103)
INTERRUPT(104)
INTERRUPT(105)
INTERRUPT(106)
INTERRUPT(107)
INTERRUPT(108)
INTERRUPT(109)
INTERRUPT(110)
INTERRUPT(111)
INTERRUPT(112)
INTERRUPT(113)
INTERRUPT(114)
INTERRUPT(115)
INTERRUPT(116)
INTERRUPT(117)
INTERRUPT(118)
INTERRUPT(119)
INTERRUPT(120)
INTERRUPT(121)
INTERRUPT(122)
INTERRUPT(123)
INTERRUPT(124)
INTERRUPT(125)
INTERRUPT(126)
INTERRUPT(127)
INTERRUPT(128)
INTERRUPT(129)
INTERRUPT(130)
INTERRUPT(131)
INTERRUPT(132)
INTERRUPT(133)
INTERRUPT(134)
INTERRUPT(135)
INTERRUPT(136)
INTERRUPT(137)
INTERRUPT(138)
INTERRUPT(139)
INTERRUPT(140)
INTERRUPT(141)
INTERRUPT(142)
INTERRUPT(143)
INTERRUPT(144)
INTERRUPT(145)
INTERRUPT(146)
INTERRUPT(147)
INTERRUPT(148)
INTERRUPT(149)
INTERRUPT(150)
INTERRUPT(151)
INTERRUPT(152)
INTERRUPT(153)
INTERRUPT(154)
INTERRUPT(155)
INTERRUPT(156)
INTERRUPT(157)
INTERRUPT(158)
INTERRUPT(159)
INTERRUPT(160)
INTERRUPT(161)
INTERRUPT(162)
INTERRUPT(163)
INTERRUPT(164)
INTERRUPT(165)
INTERRUPT(166)
INTERRUPT(167)
INTERRUPT(168)
INTERRUPT(169)
INTERRUPT(170)
INTERRUPT(171)
INTERRUPT(172)
INTERRUPT(173)
INTERRUPT(174)
INTERRUPT(175)
INTERRUPT(176)
INTERRUPT(177)
INTERRUPT(178)
INTERRUPT(179)
INTERRUPT(180)
INTERRUPT(181)
INTERRUPT(182)
INTERRUPT(183)
INTERRUPT(184)
INTERRUPT(185)
INTERRUPT(186)
INTERRUPT(187)
INTERRUPT(188)
INTERRUPT(189)
INTERRUPT(190)
INTERRUPT(191)
INTERRUPT(192)
INTERRUPT(193)
INTERRUPT(194)
INTERRUPT(195)
INTERRUPT(196)
INTERRUPT(197)
INTERRUPT(198)
INTERRUPT(199)
INTERRUPT(200)
INTERRUPT(201)
INTERRUPT(202)
INTERRUPT(203)
INTERRUPT(204)
INTERRUPT(205)
INTERRUPT(206)
INTERRUPT(207)
INTERRUPT(208)
INTERRUPT(209)
INTERRUPT(210)
INTERRUPT(211)
INTERRUPT(212)
INTERRUPT(213)
INTERRUPT(214)
INTERRUPT(215)
INTERRUPT(216)
INTERRUPT(217)
INTERRUPT(218)
INTERRUPT(219)
INTERRUPT(220)
INTERRUPT(221)
INTERRUPT(222)
INTERRUPT(223)
INTERRUPT(224)
INTERRUPT(225)
INTERRUPT(226)
INTERRUPT(227)
INTERRUPT(228)
INTERRUPT(229)
INTERRUPT(230)
INTERRUPT(231)
INTERRUPT(232)
INTERRUPT(233)
INTERRUPT(234)
INTERRUPT(235)
INTERRUPT(236)
INTERRUPT(237)
INTERRUPT(238)
INTERRUPT(239)
INTERRUPT(240)
INTERRUPT(241)
INTERRUPT(242)
INTERRUPT(243)
INTERRUPT(244)
INTERRUPT(245)
INTERRUPT(246)
INTERRUPT(247)
INTERRUPT(248)
INTERRUPT(249)
INTERRUPT(250)
INTERRUPT(251)
INTERRUPT(252)
INTERRUPT(253)
INTERRUPT(254)
INTERRUPT(255)

.global inter_hand
inter_hand:
	.quad handler0
	.quad handler1
	.quad handler2
	.quad handler3
	.quad handler4
	.quad handler5
	.quad handler6
	.quad handler7
	.quad handler8
	.quad handler9
	.quad handler10
	.quad handler11
	.quad handler12
	.quad handler13
	.quad handler14
	.quad handler15
	.quad handler16
	.quad handler17
	.quad handler18
	.quad handler19
	.quad handler20
	.quad handler21
	.quad handler22
	.quad handler23
	.quad handler24
	.quad handler25
	.quad handler26
	.quad handler27
	.quad handler28
	.quad handler29
	.quad handler30
	.quad handler31
	.quad handler32
	.quad handler33
	.quad handler34
	.quad handler35
	.quad handler36
	.quad handler37
	.quad handler38
	.quad handler39
	.quad handler40
	.quad handler41
	.quad handler42
	.quad handler43
	.quad handler44
	.quad handler45
	.quad handler46
	.quad handler47
	.quad handler48
	.quad handler49
	.quad handler50
	.quad handler51
	.quad handler52
	.quad handler53
	.quad handler54
	.quad handler55
	.quad handler56
	.quad handler57
	.quad handler58
	.quad handler59
	.quad handler60
	.quad handler61
	.quad handler62
	.quad handler63
	.quad handler64
	.quad handler65
	.quad handler66
	.quad handler67
	.quad handler68
	.quad handler69
	.quad handler70
	.quad handler71
	.quad handler72
	.quad handler73
	.quad handler74
	.quad handler75
	.quad handler76
	.quad handler77
	.quad handler78
	.quad handler79
	.quad handler80
	.quad handler81
	.quad handler82
	.quad handler83
	.quad handler84
	.quad handler85
	.quad handler86
	.quad handler87
	.quad handler88
	.quad handler89
	.quad handler90
	.quad handler91
	.quad handler92
	.quad handler93
	.quad handler94
	.quad handler95
	.quad handler96
	.quad handler97
	.quad handler98
	.quad handler99
	.quad handler100
	.quad handler101
	.quad handler102
	.quad handler103
	.quad handler104
	.quad handler105
	.quad handler106
	.quad handler107
	.quad handler108
	.quad handler109
	.quad handler110
	.quad handler111
	.quad handler112
	.quad handler113
	.quad handler114
	.quad handler115
	.quad handler116
	.quad handler117
	.quad handler118
	.quad handler119
	.quad handler120
	.quad handler121
	.quad handler122
	.quad handler123
	.quad handler124
	.quad handler125
	.quad handler126
	.quad handler127
	.quad handler128
	.quad handler129
	.quad handler130
	.quad handler131
	.quad handler132
	.quad handler133
	.quad handler134
	.quad handler135
	.quad handler136
	.quad handler137
	.quad handler138
	.quad handler139
	.quad handler140
	.quad handler141
	.quad handler142
	.quad handler143
	.quad handler144
	.quad handler145
	.quad handler146
	.quad handler147
	.quad handler148
	.quad handler149
	.quad handler150
	.quad handler151
	.quad handler152
	.quad handler153
	.quad handler154
	.quad handler155
	.quad handler156
	.quad handler157
	.quad handler158
	.quad handler159
	.quad handler160
	.quad handler161
	.quad handler162
	.quad handler163
	.quad handler164
	.quad handler165
	.quad handler166
	.quad handler167
	.quad handler168
	.quad handler169
	.quad handler170
	.quad handler171
	.quad handler172
	.quad handler173
	.quad handler174
	.quad handler175
	.quad handler176
	.quad handler177
	.quad handler178
	.quad handler179
	.quad handler180
	.quad handler181
	.quad handler182
	.quad handler183
	.quad handler184
	.quad handler185
	.quad handler186
	.quad handler187
	.quad handler188
	.quad handler189
	.quad handler190
	.quad handler191
	.quad handler192
	.quad handler193
	.quad handler194
	.quad handler195
	.quad handler196
	.quad handler197
	.quad handler198
	.quad handler199
	.quad handler200
	.quad handler201
	.quad handler202
	.quad handler203
	.quad handler204
	.quad handler205
	.quad handler206
	.quad handler207
	.quad handler208
	.quad handler209
	.quad handler210
	.quad handler211
	.quad handler212
	.quad handler213
	.quad handler214
	.quad handler215
	.quad handler216
	.quad handler217
	.quad handler218
	.quad handler219
	.quad handler220
	.quad handler221
	.quad handler222
	.quad handler223
	.quad handler224
	.quad handler225
	.quad handler226
	.quad handler227
	.quad handler228
	.quad handler229
	.quad handler230
	.quad handler231
	.quad handler232
	.quad handler233
	.quad handler234
	.quad handler235
	.quad handler236
	.quad handler237
	.quad handler238
	.quad handler239
	.quad handler240
	.quad handler241
	.quad handler242
	.quad handler243
	.quad handler244
	.quad handler245
	.quad handler246
	.quad handler247
	.quad handler248
	.quad handler249
	.quad handler250
	.quad handler251
	.quad handler252
	.quad handler253
	.quad handler254
	.quad handler255
