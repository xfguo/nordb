/**
 * SPI NOR Flash Simulation Library
 */

#include "dbg.h"
#include "sim.h"
#include <string.h>
#include <stdlib.h>

static u8 flash_mem[FLASH_SIZE]; // flash memory

int sim_init() 
{
    memset(flash_mem, 0xff, FLASH_SIZE);
    return 0;
}

int sim_read_byte(u32 addr, u8* data) 
{
    if (addr > FLASH_SIZE)
        return -1;

    *data = flash_mem[addr];
    return 0;
}

int sim_write_byte(u32 addr, u8 data)
{
    if (addr > FLASH_SIZE)
        return -1;
    flash_mem[addr] &= data;
    return 0;
}

int sim_erase_sector(u32 sector)
{
    if (sector > FLASH_SECOTR_NUM) {
        return -1;
    }
    memset(&flash_mem[sector * FLASH_SECTOR_SIZE], 0xff, FLASH_SECTOR_SIZE);
    return 0;
}
