helloworld: helloworld.ihx
	hex2bin -e bin helloworld.ihx
	python binpac8x.py helloworld.bin
	#packihx helloworld.ihx > helloworld.hex

%.ihx:
	sdasz80 -p -g -o tios_crt0.rel tios_crt0.s
	sdcc -Ilibti --no-std-crt0 --code-loc 40347 --data-loc 0 --std-sdcc99 -mz80 --reserve-regs-iy -o $*.ihx tios_crt0.rel $*.c
	#sdcc -S --no-std-crt0 --code-loc 40347 --data-loc 0 --std-sdcc99 -mz80 --reserve-regs-iy -o $*.asm.tmp tios_crt0.rel $*.c
	#cat header.asm > $*.asm
	#cat $*.asm.tmp >> $*.asm
	#sdasz80	-plosgffw $*.rel $*.asm
	#sdldz80 -nf $*.lk

8xk:
	rabbitsign -t 8xk -g -o helloworld.8xk helloworld.hex

clean:
	rm helloworld.ihx helloworld.hex helloworld.noi helloworld.map helloworld.rel helloworld.sym tios_crt0.rel helloworld.bin helloworld.asm helloworld.asm.tmp helloworld.lst helloworld.lk
