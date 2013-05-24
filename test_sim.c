#include "sim.h"
#include "dbg.h"
#include "type.h"

int test_sim()
{
    u32 i, j;
    u8 data;
    if(sim_init() != 0) {
        DBG("sim:init failed\n");
        return -1;
    }
    // test all 0xff
    for (i = 0;i < FLASH_SIZE;i++) {
        if (sim_read_byte(i, &data) != 0 && data != 0xff) {
            DBG("sim:sim read failed or init failed(not all 0xff\n");
            return -1;
        }
    }

    // test write and read
    for (i = 0;i < FLASH_SIZE;i++) {
        if (sim_write_byte(i, 0xaa) != 0) {
            DBG("sim:write failed\n");
            return -1;
        }
    }
    
    for (i = 0;i < FLASH_SIZE;i++) {
        if (sim_read_byte(i, &data) != 0 && data != 0xaa) {
            DBG("sim:read failed or write data error\n");
            return -1;
        }
    }
    
    for (i = 0;i < FLASH_SIZE;i++) {
        if (sim_write_byte(i, 0x55) != 0) {
            DBG("sim:write failed\n");
            return -1;
        }
    }
    
    for (i = 0;i < FLASH_SIZE;i++) {
        if (sim_read_byte(i, &data) != 0 && data != 0x00) {
            DBG("sim:read failed or write data error\n");
            return -1;
        }
    }
    
    // test sector erase
    for (i = 0;i < FLASH_SECOTR_NUM;i++) {
        if (sim_erase_sector(i) != 0) {
            DBG("sim:sector erase failed\n");
            return -1;
        }

        for (j = 0; j < FLASH_SECTOR_SIZE;j++) {
            if (sim_read_byte(i * FLASH_SECTOR_SIZE + j, &data) != 0 
                && data != 0xff) 
            {
                DBG("sim:sector is not erased\n");
                return -1;
            }
        }
    }
    
    return 0;
}

