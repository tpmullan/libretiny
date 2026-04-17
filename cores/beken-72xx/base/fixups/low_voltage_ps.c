/* Copyright (c) Kuba Szczodrzyński 2026-04-17. */

#include "include.h"

#if CFG_LOW_VOLTAGE_PS
/*
 * BDK 3.0.56 declares this callback from low_voltage_ps.c but doesn't provide
 * an implementation in the BK7238 source set. Keep it weak so a future BDK
 * implementation can override the fallback without changing LibreTiny.
 */
__attribute__((weak)) void ps_send_connection_loss(void) {}
#endif
