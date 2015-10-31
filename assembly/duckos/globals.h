#define DISPLAY_SIZE 2000
#define KERNEL_VIRTUAL_BASE 0xC0000000
#define KERNEL_PAGE_TABLE (KERNEL_VIRTUAL_BASE >> 22)

//nop is required after sti/cli becausee they do not go into effect until after the next instruction runs.
//start interrupts
#define STI \
__asm__\
(\
        "sti\n"\
        "nop\n"\
);

//clear interrupts
#define CLI \
__asm__\
(\
        "cli\n"\
        "nop\n"\
);



