#include "ssd.h"

uint32_t mem[MEM_SIZE];

bool ssd_init()
{
    FILE *fp = fopen(NAND_FILE, "rb");
    if (!fp && !init_nand())
        return false;
    fp = fopen(NAND_FILE, "rb");
    if (!fp)
        return false;
    fread(mem, sizeof(uint32_t), MEM_SIZE, fp);
    fclose(fp);
    return true;
}

bool init_nand()
{
    FILE *fp = fopen(NAND_FILE, "wb");
    if (!fp)
        return false;
    for (uint32_t i = 0; i < MEM_SIZE; ++i)
        mem[i] = 0;
    fwrite(mem, sizeof(uint32_t), MEM_SIZE, fp);
    fclose(fp);
    return true;
}

bool ssd_write(uint32_t addr, uint32_t data)
{
    if (addr < 0 || addr >= MEM_SIZE)
        return false;
    mem[addr] = data;
    if (!nand_write(addr))
        return false;
    return true;
}

uint32_t ssd_read(uint32_t addr)
{
    if (addr < 0 || addr >= MEM_SIZE)
        return 0;

    result_write(mem[addr]);

    return mem[addr];
}

bool nand_write(uint32_t addr)
{
    FILE *fp = fopen(NAND_FILE, "rb+");
    if (!fp)
        return false;

    fseek(fp, addr * sizeof(uint32_t), SEEK_SET);
    fwrite(mem + addr, sizeof(uint32_t), 1, fp);

    fclose(fp);
    return true;
}

bool result_write(uint32_t data)
{
    FILE *fp = fopen(RESULT_FILE, "wb");
    if (!fp)
        return false;

    fwrite(&data, sizeof(uint32_t), 1, fp);

    fclose(fp);
    return true;
}