#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <fdtdec.h>
#include <asm/arch/pinmux.h>
#include "pinctrl-exynos.h"

static const struct pinctrl_ops exynos3475_pinctrl_ops = {
	.set_state	= exynos_pinctrl_set_state
};

/* pin banks of exynos3475 pin-controller 0 (ALIVE) */
static const struct samsung_pin_bank_data exynos3475_pin_banks0[] = {
    EXYNOS_PIN_BANK(8, 0x000, "gpa0"),
	EXYNOS_PIN_BANK(8, 0x020, "gpa1"),
	EXYNOS_PIN_BANK(3, 0x040, "gpq0"),
};

/* pin banks of exynos3475 pin-controller 1 (AUD) */
static const struct samsung_pin_bank_data exynos3475_pin_banks1[] = {
    EXYNOS_PIN_BANK(4, 0x000, "gpz0"),
	EXYNOS_PIN_BANK(4, 0x020, "gpz1"),
};

/* pin banks of exynos3475 pin-controller 2 (ESE) */
static const struct samsung_pin_bank_data exynos3475_pin_banks2[] = {
	EXYNOS_PIN_BANK(4, 0x000, "gpc4"),
};

/* pin banks of exynos3475 pin-controller 3 (FSYS) */
static const struct samsung_pin_bank_data exynos3475_pin_banks3[] = {
	EXYNOS_PIN_BANK(3, 0x000, "gpr0"),
	EXYNOS_PIN_BANK(8, 0x020, "gpr1"),
	EXYNOS_PIN_BANK(2, 0x040, "gpr2"),
	EXYNOS_PIN_BANK(4, 0x060, "gpr3"),
	EXYNOS_PIN_BANK(6, 0x080, "gpr4"),
};

/* pin banks of exynos3475 pin-controller 4 (MIF) */
static struct samsung_pin_bank_data exynos3475_pin_banks4[] = {
	EXYNOS_PIN_BANK(2, 0x000, "gpm0"),
};

/* pin banks of exynos3475 pin-controller 5 (NFC) */
static struct samsung_pin_bank_data exynos3475_pin_banks5[] = {
	EXYNOS_PIN_BANK(4, 0x000, "gpc2"),
};

/* pin banks of exynos3475 pin-controller 6 (TOP) */
static const struct samsung_pin_bank_data exynos3475_pin_banks6[] = {
	EXYNOS_PIN_BANK(8, 0x020, "gpb0"),
	EXYNOS_PIN_BANK(2, 0x040, "gpb1"),
	EXYNOS_PIN_BANK(3, 0x060, "gpc0"),
	EXYNOS_PIN_BANK(4, 0x080, "gpc1"),
	EXYNOS_PIN_BANK(8, 0x0A0, "gpd0"),
	EXYNOS_PIN_BANK(8, 0x0C0, "gpd1"),
	EXYNOS_PIN_BANK(4, 0x0E0, "gpd2"),
	EXYNOS_PIN_BANK(3, 0x100, "gpe0"),
	EXYNOS_PIN_BANK(4, 0x120, "gpf0"),
	EXYNOS_PIN_BANK(4, 0x140, "gpf1"),
};

/* pin banks of exynos3475 pin-controller 7 (TOUCH) */
static struct samsung_pin_bank_data exynos3475_pin_banks7[] = {
	EXYNOS_PIN_BANK(3, 0x000, "gpc3"),
};

const struct samsung_pin_ctrl exynos3475_pin_ctrl[] = {
	{
		/* pin-controller instance 0 Alive data */
		.pin_banks	= exynos3475_pin_banks0,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks0),
	}, {
		/* pin-controller instance 1 AUD data */
		.pin_banks	= exynos3475_pin_banks1,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks1),
	}, {
		/* pin-controller instance 2 ESE data */
		.pin_banks	= exynos3475_pin_banks2,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks2),
		}, {
		/* pin-controller instance 3 FSYS data */
		.pin_banks	= exynos3475_pin_banks3,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks3),
	}, {
		/* pin-controller instance 4 MIF data */
		.pin_banks	= exynos3475_pin_banks4,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks4),
	}, {
		/* pin-controller instance 5 NFC data */
		.pin_banks	= exynos3475_pin_banks5,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks5),
	}, {
		/* pin-controller instance 6 TOP data */
		.pin_banks	= exynos3475_pin_banks6,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks6),
	}, {
		/* pin-controller instance 7 TOUCH data */
		.pin_banks	= exynos3475_pin_banks7,
		.nr_banks	= ARRAY_SIZE(exynos3475_pin_banks7),
	},
	{/* list terminator */}
};

static const struct udevice_id exynos3475_pinctrl_ids[] = {
	{ .compatible = "samsung,exynos3475-pinctrl",
		.data = (ulong)exynos3475_pin_ctrl },
	{ }
};

U_BOOT_DRIVER(pinctrl_exynos3475) = {
	.name		= "pinctrl_exynos3475",
	.id		= UCLASS_PINCTRL,
	.of_match	= exynos3475_pinctrl_ids,
	.priv_auto = sizeof(struct exynos_pinctrl_priv),
	.ops		= &exynos3475_pinctrl_ops,
	.probe		= exynos_pinctrl_probe,
};
