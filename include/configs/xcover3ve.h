/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration settings for the SAMSUNG XCOVER3VE board.
 */

#ifndef __CONFIG_XCOVER3VE_H
#define __CONFIG_XCOVER3VE_H

#include <configs/exynos3-common.h>

#define CONFIG_BOARD_COMMON

#define CONFIG_XCOVER3VE

#define CONFIG_SYS_SDRAM_BASE		0x20000000
//#define CONFIG_SPL_STACK		CONFIG_IRAM_END
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_TEXT_BASE + SZ_2M - GENERATED_GBL_DATA_SIZE)

/* DRAM Memory Banks */
#define SDRAM_BANK_SIZE		(256UL << 20UL)	/* 256 MB */

#endif	/* __CONFIG_XCOVER3_H */
