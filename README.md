LibTI
=====

LibTI is a C library for TI-based calculators. It relies on SDCC and a bunch of tools to compile to the TI-84+.

The library itself consists of useful functions I'll add over time. Standard algorithms will stay close to the C stdlib, but glue functions (such as the IO ones in src/cio.h) most probably won't!

Make it work
------------

In case you happen to want to make it work, here's some tips:

* It only works for linux now, but I don't think you should have too much trouble creating a script that replicates the (terrible) Makefile.
* It is meant to run on the TI-84+, but you can probably make it run on any related z80-based calculator. Replace binpac8x program by its equivalent, check the tios_crt0.s file (especially the .org directives, I don't know if you are supposed to have the same offset on other calculators. Make sure the second org directive is equals to the first one plus 8) and create another mapping file from your calculator's assembly library (like ti83plus.inc). Oh, and did I mention courage?
* Wabbitemu happens to have a very decent debugger, so if you managed to compile some stuff but it doesn't work, check that ! (tip: on the 84+, your assembled code will start at 0x9D9B)
* Don't ever fucking run any program on a real calculator until fully tested, and even then keep your other programs in the archive. RAM clears happen very often. Once again, Wabbitemu is your friend!
