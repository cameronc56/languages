echo "Executing NASM..."
nasm -g -f elf -o kernel.o kernel.asm

echo "Executing GCC..."
gcc kernel.o main.c -o kernel.bin -T linker.ld -m32 -nostartfiles -nostdlib
#Linker not needed when executing GCC...
#echo "Executing linker (ld)...#"
#ld -m elf_i386 -s -T linker.ld -o kernel.bin kernel.o
echo "Copying bin file..."
cp kernel.bin ISO/kernel.bin
echo "Making ISO Image..."
cd ISO
mkisofs -o ../samplekernel.iso -b isolinux-debug.bin -no-emul-boot -boot-load-size 4 -boot-info-table .

# qemu-system-i386 -cdrom samplekernel.iso
