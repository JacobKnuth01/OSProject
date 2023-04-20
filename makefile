CFiles = $(wildcard CPU/*.c k/*.c devices/*.c)
HFiles = $(wildcard CPU/*.h k/*.h devices/*.h)
OFiles = $(CFiles:.c=.o)



OS.bin: CPU/bootSec.bin k.bin filler app/test2.bin
	cat CPU/bootSec.bin k.bin > OS.bin
	val=$$(stat -c %s OS.bin); \
	val2="$$(( 0x5000 - (val-0x200+0x1000)))";\
	dd if=/dev/zero of=filler bs=$$val2 count=1
	cat OS.bin filler app/test2.bin  > tmp.bin
	mv tmp.bin OS.bin
	

k.bin: k/enterK.o ${OFiles} CPU/asmInt.o CPU/switchSegments.o CPU/copy_to_userspace.o
	ld -o $@ -Ttext 0x1000 $^ --oformat binary -melf_i386
%.o:%.c
	gcc -c $< -o $@ -ffreestanding -fno-stack-protector -z execstack -m32 -no-pie -fno-pic 
app/test2.bin: app/appEnter.o app/test2.o  
	ld -o $@ -Ttext 0x0 $^ --oformat binary -melf_i386

%.o: %.asm
	nasm $< -f elf -o $@
%.bin: %.asm
	nasm $< -f bin -o $@


rm:
	rm -rf *.bin *.dis *.o *.elf app/*.bin
	rm -rf devices/*.o CPU/*.bin CPU/*.o k/*.o app/*.o