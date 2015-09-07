#define appBackupScreen	#0x9872	// 768 bytes
#define _ldhlind	#0x4009
#define _htimesl	#0x4276
#define _convop1	#0x4AEF
#define contrast	 #0x8447
#define _darkline	#0x47DD
#define _darkpoint	#0x47F2
#define _archUnarch	#0x4FD8
#define _enoughRam	#0x42FD
#define usermemoff	#0x89EC
#define libstart	#0x0004
#define progstart	 #0x9D95
//saferam1	 #0x86EC
#define saferam1	 #0x9872
#define saferam2	 #0x858f
#define saferam3	 #0x8508
#define saferam4	 #0x8478
#define saferamp	 #0x9872
#define saferamp2	 #0x8251
#define _homeup		#0x4558
#define _newline	#0x452E
#define _cleargbuf	 #0x4BD0
#define _indicatorOn	 #0x456D
#define _indicatorOff	 #0x4570
#define _copygbuf	 #0x486A
#define _clrlcdf	 #0x4540
#define _cleartextshad	 #0x454C
#define _clrscr		 #0x4543
#define _clrscrf	 #0x4546
#define _cline		 #0x4798
#define _iline		 #0x47E0
#define _ipoint		 #0x47E3
#define _ParseInp	 #0x4A9B
#define _divhlby10	 #0x400F
#define _cphlde		 #0x400C
#define _disphl		 #0x4507
#define _divhlbya	 #0x4012
#define _hltimes9	 #0x40F9
#define _vputmap	 #0x455E
#define _vputs		 #0x4561
#define _vputsn		 #0x4564
#define _putmap		 #0x4501
#define _puts		 #0x450A
#define _putps		 #0x4510
#define _putc		 #0x4504
#define _getkey		 #0x4972
#define _getk		 #0x4744
#define _getcsc		 #0x4018
//_RCLY		 #0x4EE0
//_RCLX		 #0x4EE8
#define _memfree	#0x42E5
#define _chksysvar	 #0x42F1
#define _findsym	 #0x42F4
//_CREATEGDB	 #0x4486
//_CREATEREAL	 #0x4452
//_CREATESTRNG	 #0x4472
#define _createprog	#0x4339
#define _createprotprog	#0x4E6D
#define _delvar		 #0x4351
#define _insertmem	 #0x42F7
#define _deletemem	 #0x4357
#define _lcdbusy	 #0x4051
#define op1		 #0x8478
#define op2		 #0x8483
#define op3		 #0x8499
#define op4		 #0x8499
#define op5		 #0x84A4
#define op6		 #0x84AF
#define imathptr1	 #0x84D3
#define imathptr2	 #0x84D5
#define imathptr3	 #0x84D7
#define imathptr4	 #0x84D9
#define imathptr5	 #0x84DB
#define progptr		 #0x9830
#define cmdshad		 #0x966E
#define plotsscreen	 #0x9340
#define symtable	#0xFE6E
#define currow		 #0x844B
#define curcol		 #0x844C
#define pencol		 #0x86D7
#define penrow		 #0x86D8
#define curgy		 #0x8D18
#define curgx		 #0x8D19
#define _PushRealO1	  #0x43BA
#define _PushRealO2	  #0x43B7
#define _PushRealO3	  #0x43B4
#define _PushRealO4	  #0x43B1
#define _PushRealO5	  #0x43AE
#define _PushRealO6	  #0x43AB
#define _FPAdd	  #0x4072
#define _FPDiv	  #0x4099
#define _FPMult	  #0x4084
#define _OP1ExOP4	  #0x421C
#define _OP1Set0	  #0x41BF
#define _OP3SET2	  #0x41A4
#define _PopRealO1	 #0x4390
#define _PopRealO2	 #0x438D
#define _PopRealO3	 #0x438A
#define _PopRealO4	 #0x4387
#define _PopRealO5	 #0x4384
#define _PopRealO6	 #0x4381
#define _op5exop6	 #0x420A
#define _op5set0	 #0x41B3
#define _cpop1op2	#0x4111
#define _op3toop4	#0x4114
#define _op1toop4	#0x4117
#define _op2toop4	#0x411A
#define _op4toop2	#0x411D
#define _op3toop2	#0x4120
#define _op1toop3	#0x4123
#define _op5toop2	#0x4126
#define _op5toop6	#0x4129
#define _op5toop4	#0x412C
#define _op1toop2	#0x412F
#define _op6toop2	#0x4132
#define _op6toop1	#0x4135
#define _op4toop1	#0x4138
#define _op5toop1	#0x413B
#define _op3toop1	#0x413E
#define _op6toop5	#0x4141
#define _op4toop5	#0x4144
#define _op3toop5	#0x4147
#define _op2toop5	#0x414A
#define _op2toop6	#0x414D
#define _op1toop6	#0x4150
#define _op1toop5	#0x4153
#define _op2toop1	#0x4156
#define _op2toop3	#0x416E
#define _op4toop3	#0x4171
#define _op5toop3	#0x4174
#define _op4toop6	#0x4177
#define _OP1Set1	  #0x419B
#define _OP1Set2	  #0x41A7
#define _OP1Set3	  #0x41A1
#define _OP1Set4	  #0x419E
#define _pushop1	#0x43C9
#define _popop1		#0x437E
#define _arc_unarc	  #0x4FD8
#define _sin		 #0x40BD
#define _zeroop1	#0x41C5
#define _zeroop2	#0x41C8
#define _zeroop3	#0x41CB
#define _setxxop1	#0x478C
#define _setxxop2	#0x478F
#define _setxxxxop2	#0x4792
#define _dispop1a	 #0x4BF7
#define _mov9toop1	#0x417A
#define _delvararc	#0x4fC6
#define ptemp		 #0x982E

#define grbuf		plotsscreen
#define graph_mem	plotsscreen
#define gbuf		plotsscreen
#define sram		saferam1
#define apdram		saferam1
#define statram		saferam2
#define statvars	saferam2
#define vat		progptr
#define saferam5	imathptr1
#define _grbufcpy	_copygbuf
#define _grbufclr	_cleargbuf
#define _clrlcdfull     _clrlcdf
#define _clrscrnfull	_clrscrf
#define _chkfindsym     _chksysvar
#define textshadow	saferam3
#define savesscreen     saferam1
//-----> Ion Functions
#define lVectors	cmdshad+80
#define ionVersion	lVectors
#define ionRandom	lVectors+3
#define ionPutSprite	lVectors+6
#define ionLargeSprite	lVectors+9
#define ionGetPixel	lVectors+12
#define ionFastCopy	lVectors+15
#define ionDetect	lVectors+18
#define ionDecompress	lVectors+21


#define trigflags              0           // IY OFFSET VALUE
#define trigdeg                2
//
#define plotflags              2           // IY OFFSET VALUE
#define plotloc                1
#define plotdisp               2
//
#define grfmodeflags           2           // IY OFFSET VALUE
#define grffuncm               4
#define grfpolarm              5
#define grfparamm              6
#define grfrecurm              7
//
#define graphflags             3           // IY OFFSET VALUE
#define graphdraw              0
#define graphcursor            2
//
#define grfdbflags             4           // IY OFFSET VALUE
#define grfdot                 0
#define grfsimul               1
#define grfgrid                2
#define grfpolar               3
#define grfnocoord             4
#define grfnoaxis              5
#define grflabel               6
//
#define textflags              5           // IY OFFSET VALUE
#define textEraseBelow         1
#define textScrolled           2
#define textInverse            3
//
#define onflags                9           // IY OFFSET VALUE
#define onRunning              3
#define onInterrupt            4
//
#define statflags              9           // IY OFFSET VALUE
#define statsvalid             6
//
#define fmtflags               10          // IY OFFSET VALUE
#define fmtExponent            0
#define fmtEng                 1
//
#define nummode                10          // IY OFFSET VALUE
#define FMTREAL                5
#define FMTRECT                6
#define FMTPOLAR               7
//
#define curflags               12          // IY OFFSET VALUE
#define curAble                2
#define curOn                  3
#define curLock                4
//
#define appflags               13          // IY OFFSET VALUE
#define appTextSave            1
#define appAutoScroll          2
//
#define PLOTFLAG2              17          // IY OFFSET VALUE
#define EXPR_PARAM             3
#define EXPR_WRITING           4
//
#define indicflags             18          // IY OFFSET VALUE
#define indicRun               0
#define indicOnly              2
//
#define shiftflags             18          // IY OFFSET VALUE
#define shift2nd               3
#define shiftAlpha             4
#define shiftALock             6
//
#define tblflags               19          // IY OFFSET VALUE
#define AutoFill               4
#define AutoCalc               5
//
#define sgrflags               20          // IY OFFSET VALUE
#define grfSplit               0
#define VertSplit              1
#define WRITE_ON_GRAPH         4
#define textwrite              7
//
#define asm_flag1              33          // IY OFFSET VALUE
#define asm_flag1_0            0
#define asm_flag1_1            1
#define asm_flag1_2            2
#define asm_flag1_3            3
#define asm_flag1_4            4
#define asm_flag1_5            5
#define asm_flag1_6            6
#define asm_flag1_7            7
//
#define asm_flag2              34          // IY OFFSET VALUE
#define asm_flag2_0            0
#define asm_flag2_1            1
#define asm_flag2_2            2
#define asm_flag2_3            3
#define asm_flag2_4            4
#define asm_flag2_5            5
#define asm_flag2_6            6
#define asm_flag2_7            7
//
#define asm_flag3              35          // IY OFFSET VALUE
#define asm_flag3_0            0
#define asm_flag3_1            1
#define asm_flag3_2            2
#define asm_flag3_3            3
#define asm_flag3_4            4
#define asm_flag3_5            5
#define asm_flag3_6            6
#define asm_flag3_7            7
