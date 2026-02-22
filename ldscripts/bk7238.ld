ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00011000, LENGTH = 0x109000
  RAM   (rwx): ORIGIN = 0x00400000, LENGTH = 0x80000
}

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.vectors))
  } > FLASH

  .text :
  {
    *(.text*)
    *(.rodata*)
    _etext = .;
  } > FLASH

  .data : AT (_etext)
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  PROVIDE(end = .);
}