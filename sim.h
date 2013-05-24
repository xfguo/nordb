/**
 * SPI NOR Flash Simulation Library
 */
#ifndef __NORDB_SIM
#define __NORDB_SIM
#include "type.h"
// Reference Device : W25Q128BV
#define FLASH_SECTOR_SIZE (4 * 1024) // 4K
#define FLASH_SECOTR_NUM (256 * 16) // 256 Groups * 16 sectors
#define FLASH_SIZE (FLASH_SECTOR_SIZE * FLASH_SECOTR_NUM) // 128Mbit

int sim_init();
int sim_read_byte(u32 addr, u8* data);
int sim_write_byte(u32 addr, u8 data);
int sim_erase_sector(u32 sector);
#endif
