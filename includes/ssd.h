#ifndef SSD_H
#define SSD_H

#define MEM_SIZE 100
#define NAND_FILE "nand"
#define RESULT_FILE "result"

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool ssd_init();
bool init_nand();
bool ssd_write(uint32_t addr, uint32_t data);
uint32_t ssd_read(uint32_t addr);
bool nand_write(uint32_t addr);
bool result_write(uint32_t data);

#endif
