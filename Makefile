test: test.ihx
	objcopy -Iihex -Obinary test.ihx test.bin
	python binpac8x.py test.bin
	packihx test.ihx > test.hex

%.ihx:
	sdasz80 -p -g -o tios_crt0.rel tios_crt0.s
	sdcc -Iincludes --no-std-crt0 --code-loc 40347 --data-loc 0 --std-sdcc99 -mz80 --reserve-regs-iy -o $*.ihx tios_crt0.rel $*.c
	#sdcc -S --no-std-crt0 --code-loc 40347 --data-loc 0 --std-sdcc99 -mz80 --reserve-regs-iy -o $*.asm.tmp tios_crt0.rel $*.c
	#cat header.asm > $*.asm
	#cat $*.asm.tmp >> $*.asm
	#sdasz80	-plosgffw $*.rel $*.asm
	#sdldz80 -nf $*.lk

8xk:
	rabbitsign -t 8xk -g -o test.8xk test.hex

clean:
	rm test.ihx test.hex test.noi test.map test.rel test.sym tios_crt0.rel test.bin test.asm test.asm.tmp test.lst
