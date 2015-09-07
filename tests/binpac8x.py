#!/usr/bin/env python
import sys, os, time, platform, struct, math;

def safeprint(*args):
	print(" ".join([str(arg) for arg in args]))

def disphelp():
	safeprint("\n BinPac8x Help Menu:\n======================\n",\
		"binpac8x.py [<type>] [-O <oncalcname>] <source bin> [<destination .8*p>]\n",\
		"-h:     Display this help menu\n",\
		"source bin: A .bin file to process\n",\
		"destination: Filename of output.  If omitted, output name derived from input\n",\
		"-O:     Specify optional oncalcname, should be <=8 chars and ALL UPPERCASE\n\n",\
		"By default produces a .8xp file.  To build for a different calculator than\n",\
		"the TI-83+/TI-84+ series, use ONE of these <type> flags:\n",\
		"-2:     TI-82 program (.82p)\n",\
		"-3:     TI-83 program (.83p)\n",\
		"-5:     TI-85 string  (.85s)\n",\
		"-6:     TI-86 program (.86p)\n",\
		"-7:     TI-86 string  (.86s)\n")
	sys.exit(0)
	return

t_start = time.localtime()

def parsefile(fnamein,fnameout,abspath,calctype,oncalcname):

	fullpathin = os.path.join(abspath,fnamein)
	if not(os.path.exists(fullpathin)):
		safeprint("Error: Input file "+fullpathin+" was not found!")
		return
	if fnameout == "":
		if 1 > fnamein.find("."):
			fnameout = fnamein + ".bin"
		else:
			if calctype!="7" and calctype!="5":
				fnameout = fnamein[:fnamein.find(".")+1] + "8" + calctype + "p"
			elif calctype=="5":
				fnameout = fnamein[:fnamein.find(".")+1] + "85s"
			elif calctype=="7":
				fnameout = fnamein[:fnamein.find(".")+1] + "86s"

	fullpathout = os.path.join(abspath,fnameout)
	if os.path.exists(fullpathout):
		safeprint("Warning: Input file "+fullpathout+" exists, overwriting.")
	
	fhi = open(fullpathin,'rb')
	fho = open(fullpathout,'wb')

	if calctype=="2":
		fho.write(bytearray(b'**TI82**'))				#byte 00, length 08
		fho.write(mybytearray([26,10,0]))					#byte 08, length 03
	elif calctype=="3":
		fho.write(bytearray(b'**TI83**'))				#byte 00, length 08
		fho.write(mybytearray([26,10,0]))					#byte 08, length 03
	elif calctype=="5":
		fho.write(bytearray(b'**TI85**'))				#byte 00, length 08
		fho.write(mybytearray([26,12,0]))					#byte 08, length 03
	elif calctype=="6" or calctype=="7":
		fho.write(bytearray(b'**TI86**'))				#byte 00, length 08
		fho.write(mybytearray([26,10,0]))					#byte 08, length 03
	else:													#case "x"
		fho.write(bytearray(b'**TI83F*'))				#byte 00, length 08
		fho.write(mybytearray([26,10,0]))					#byte 08, length 03
	
	fho.write(bytearray(b'BinPac8x (c)2010 Cemetech.net&Kerm Martian'))
															#byte 11, length 42
	
	bincontents = fhi.read();
	fhi.close();
	binsize = len(bincontents);
	bbsize_hb = math.floor(binsize/256)
	bbsize_lb = binsize - 256*bbsize_hb
	binsize = binsize + 2
	bincontents = mybytearray([bbsize_lb,bbsize_hb]) + bincontents
	
	if oncalcname == "":
		oncalcname = fnameout[:fnameout.find(".")].upper();
	else:
		oncalcname = oncalcname.upper()
	if len(oncalcname) >=8 or calctype != "5":				#TI-85 has variable-len name
		while len(oncalcname) != 8:
			if len(oncalcname) > 8:
				oncalcname = oncalcname[:8]
			else:
				if calctype != "6" and calctype != "7":
					oncalcname = oncalcname + chr(0);
				else:
					oncalcname = oncalcname + " ";			#TI-86 uses space-padded name

	if calctype=="2":
		headersize = 15
	elif calctype=="3":
		headersize = 15
	elif calctype=="5":
		headersize = 8+len(oncalcname)
	elif calctype=="6" or calctype=="7":
		headersize = 16
	else:													#case "x"
		headersize = 17										# 17-byte header
	
	datasize = binsize + headersize
	size_hb = math.floor(datasize/256);
	size_lb = datasize - 256*size_hb;
	fho.write(mybytearray([size_lb,size_hb]));				#byte 53, length 02
	safeprint("On-calc name: "+oncalcname)
	oncalcname.encode()
	bsize_hb = math.floor(binsize/256);
	bsize_lb = binsize - 256*bsize_hb;

	# Construct the header in the data field
	if calctype=="2" or calctype=="3":
		fho.write(mybytearray([11,0]));					#byte 55, length 02
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 57, length 02
		fho.write(mybytearray([6]));						#byte 59, length 01
		fho.write((mybytes(oncalcname, encoding='ascii'))) #byte 60, length 08
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 68, length 02
	elif calctype=="5":
		fho.write(mybytearray([headersize-2,0]))			#byte 55, length 02
		fho.write(mybytearray([bsize_lb,bsize_hb]))		#byte 57, length 02
		fho.write(mybytearray([12]))						#byte 59, length 01
		fho.write(mybytearray([len(oncalcname)]))			#byte 60, length 01
		fho.write((mybytes(oncalcname, encoding='ascii'))) #byte 61, length varies
		fho.write(mybytearray([bsize_lb,bsize_hb]))		#byte 62-69, length 02
	elif calctype=="6":
		fho.write(mybytearray([12,0]));					#byte 55, length 02
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 57, length 02
		fho.write(mybytearray([18]));						#byte 59, length 01
		fho.write(mybytearray([8]))						#byte 60, length 01
		fho.write((mybytes(oncalcname, encoding='ascii'))) #byte 61, length 08
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 69, length 02
	elif calctype=="7":
		fho.write(mybytearray([12,0]));					#byte 55, length 02
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 57, length 02
		fho.write(mybytearray([12]));						#byte 59, length 01
		fho.write(mybytearray([8]))						#byte 60, length 01
		fho.write((mybytes(oncalcname, encoding='ascii'))) #byte 61, length 08
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 69, length 02
	else:
		fho.write(mybytearray([13,0]));					#byte 55, length 02
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 57, length 02
		fho.write(mybytearray([6]));						#byte 59, length 01
		fho.write((mybytes(oncalcname, encoding='ascii'))) #byte 60, length 08
		fho.write(mybytearray([0]));						#byte 68, length 01
		fho.write(mybytearray([0]));						#byte 69, length 01
		fho.write(mybytearray([bsize_lb,bsize_hb]));		#byte 70, length 02
	
	fho.write(bincontents);									#byte 72, length binsize

	if calctype=="2" or calctype=="3":
		chksum = 2*bsize_lb + 2*bsize_hb + 11 + 0 + 6;
	elif calctype=="5":
		chksum = 2*bsize_lb + 2*bsize_hb + (headersize - 2) + 0 + 12 + len(oncalcname);
	elif calctype=="6":
		chksum = 2*bsize_lb + 2*bsize_hb + 12 + 0 + 18 + 8;
	elif calctype=="7":
		chksum = 2*bsize_lb + 2*bsize_hb + 12 + 0 + 12 + 8;
	else:
		chksum = 2*bsize_lb + 2*bsize_hb + 6 + 0 + 0 + 13 + 0;	#including [13,0]

	for c in oncalcname:
		chksum += ord(c);
	if sys.version[0] == '2':
		for c in bincontents:
			chksum += ord(c);
	else:
		for c in bincontents:
			chksum += c;
	chksum = chksum % 65536
	cs_hb = math.floor(chksum/256);
	cs_lb = chksum - 256*cs_hb;
	fho.write(mybytearray([cs_lb,cs_hb]));					#byte 63, length 02
	fho.close();
	return

def mybytes(string, encoding):
	if sys.version[0] == '2':
		return bytes(string);
	else:
		return bytes(string,encoding)

def mybytearray(thisblist):									#this stunningly awkward hack is for 2.x/3.x compat
	if sys.version[0] == '2':
		mystr = ""
		for i in range(0,len(thisblist)):
			mystr += chr(int(thisblist[i]));
		return mybytes(mystr,encoding="ascii");
	else:
		return bytearray(thisblist);

if __name__ == "__main__":
	safeprint(" --+=====================+--")
	safeprint(" --|    BinPac8x v1.2    |--")
	safeprint(" --|   by Kerm Martian   |--")
	safeprint(" --|   www.Cemetech.net  |--")
	safeprint(" --|  admin@cemetech.net |--")
	safeprint(" --+=====================+--")
	fnamein = ""
	fnameout = ""
	oncalcname = ""
	if (len(sys.argv) > 1):
		prefix = ""
		calc = "x";
		skipiter = 0;
		for i in range(1,len(sys.argv)):
			if skipiter == 0:
				if sys.argv[i][0] == "-":
					if sys.argv[i][1] == "h":
						disphelp()
					if sys.argv[i][1]=="2" or sys.argv[i][1]=="3" or sys.argv[i][1]=="5" or sys.argv[i][1]=="6" or sys.argv[i][1]=="x" or sys.argv[i][1]=="7":
						calc = sys.argv[i][1]
					elif sys.argv[i][1] == "O":
						oncalcname = sys.argv[i+1];
						skipiter = 1;
					else:
						safeprint("\nUnknown switch: ",sys.argv[i])
						disphelp()
					#prefix = sys.argv[i][1]
				else:
					if prefix == "":
						if (fnamein == ''):
							fnamein = sys.argv[i]
						else:
							fnmeout = sys.argv[i]
					else:
						safeprint("\nUnknown switch: -",prefix,"\n")
			else:
				skipiter = 0;

	if fnamein == "":
		safeprint("\nPlease enter the relative path to the bincontents file to pack as a .8*p: ")
		fnamein = sys.stdin.readline()[:-1]

	basepath = os.path.dirname(fnamein)
	safeprint("**Pass 1/1: .8"+calc+"p Construction**")
	parsefile(fnamein,fnameout,basepath,calc,oncalcname)
	safeprint("Total time:",str(time.mktime(time.localtime())-time.mktime(t_start)) + "s")
	sys.exit()
