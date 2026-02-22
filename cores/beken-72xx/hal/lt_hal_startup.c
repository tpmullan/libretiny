#include <stdint.h>

extern uint32_t _sbss, _ebss, _sdata, _edata, _etext;

void Reset_Handler(void) {
    uint32_t *src, *dst;

    // copy .data
    src = &_etext;
    dst = &_sdata;
    while (dst < &_edata)
        *dst++ = *src++;

    // zero .bss
    for (dst = &_sbss; dst < &_ebss; dst++)
        *dst = 0;

    // relocate vector table (openbeken-required)
    SCB->VTOR = 0x00011000;

    main();
}