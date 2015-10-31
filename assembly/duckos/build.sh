echo "Executing NASM..."
nasm -g -f elf -o kernel.o kernel.asm
#echo "Executing GCC 1..."
#this compiles without linking.. need to ask ed what this is for.
#gcc -S main.c -nostartfiles -nostdlib -masm=intel
echo "Executing GCC..."
#gcc kernel.o main.c -o kernel.bin -T linker.ld -m32 -nostartfiles -nostdlib -masm=intel
i686-elf-4.9.1-Linux-x86_64/bin/i686-elf-gcc kernel.o main.c -o kernel.bin -T linker.ld -nostartfiles -nostdlib -masm=intel
#Linker not needed when executing GCC...
#echo "Executing linker (ld)...#"
#ld -m elf_i386 -s -T linker.ld -o kernel.bin kernel.o
echo "Copying bin file..."
cp kernel.bin ISO/kernel.bin
echo "Making ISO Image..."
cd ISO
# mkisofs same as genisoimage
mkisofs -o ../samplekernel.iso -b isolinux-debug.bin -no-emul-boot -input-charset utf8 -quiet -boot-load-size 4 -boot-info-table .

# qemu-system-i386 -cdrom samplekernel.iso
