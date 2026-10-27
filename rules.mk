# If you have Left LEDs (see
# https://geekhack.org/index.php?topic=22780.msg873819#msg873819 for
# details), include the following define:
# OPT_DEFS += -DLEFT_LEDS

# OS selection: default Linux, override with make ergodox_ez:c0r73x KBD_OS=macos
ifeq ($(KBD_OS),macos)
  OPT_DEFS += -DKBD_OS_MACOS
else
  OPT_DEFS += -DKBD_OS_LINUX
endif

CUSTOM_MATRIX    = lite # Custom matrix file for the ErgoDox EZ

# project specific files
SRC += matrix.c
I2C_DRIVER_REQUIRED = yes

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

MOUSE_SHARED_EP = no
COMBO_ENABLE = yes

DEFAULT_FOLDER = ergodox_ez/base
