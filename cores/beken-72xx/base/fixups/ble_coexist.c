/* Copyright (c) Kuba Szczodrzyński 2026-04-16. */

#include <stdint.h>
#include <stdbool.h>

#include "sys_config.h"

#if !CFG_SUPPORT_BLE

uint8_t ble_active = 0;
uint8_t ble_switch_mac_sleeped = 0;

int wifi_notice_ble_status(int evt, unsigned int param, unsigned int param2) {
    return 0;
}

int wn_txl_hd_pending_is_allow(
    uint8_t flag,
    void *first_thd,
    void *last_thd,
    uint8_t access_category
) {
    return 1;
}

uint8_t if_ble_sleep(void) {
    return 1;
}

void ble_switch_rf_to_wifi(void) {}

int rwip_get_current_time(void) {
    return 0;
}

int rwip_get_next_target_time(void) {
    return 0;
}

bool ble_thread_is_busy(void) {
    return false;
}

bool ble_coex_pta_is_on(void) {
    return false;
}

#endif
