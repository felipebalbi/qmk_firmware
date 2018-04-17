#include "../../config.h"

/* Remove Backlight */
#undef BACKLIGHT_LEVELS

/* Remove Underlight */
#undef RGBLED_NUM
#undef RGBLIGHT_HUE_STEP
#undef RGBLIGHT_SAT_STEP
#undef RGBLIGHT_VAL_STEP

#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION

#undef TAPPING_TERM

#define VENDOR_ID       0xfeed
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0628
#define MANUFACTURER    Satan
#define PRODUCT         GH60
#define DESCRIPTION     QMK keyboard firmware for Satan GH60 with WS2812 support
#define TAPPING_TERM	200
