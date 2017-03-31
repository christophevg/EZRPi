PROJECT      = blink
SDK          = ../../lib/Gecko_SDK
DEVICE       = EZR32LG330F128R60

# a few short-hands into the SDK
PLATFORM     = $(SDK)/platform
EZR32        = $(PLATFORM)/Device/SiliconLabs/EZR32LG
EMLIB        = $(PLATFORM)/emlib

# sources

SRC = $(EZR32)/Source/system_ezr32lg.c \
			$(EZR32)/Source/GCC/startup_ezr32lg.S \
			$(EMLIB)/src/em_assert.c \
			$(EMLIB)/src/em_cmu.c \
			$(EMLIB)/src/em_ebi.c \
			$(EMLIB)/src/em_emu.c \
			$(EMLIB)/src/em_gpio.c \
			$(EMLIB)/src/em_system.c \
			$(EMLIB)/src/em_usart.c \
			blink.c

# toolchain

CC           = arm-none-eabi-gcc
CXX          = arm-none-eabi-g++
LD           = arm-none-eabi-ld
AR           = arm-none-eabi-ar
OBJCOPY      = arm-none-eabi-objcopy
DUMP         = arm-none-eabi-objdump

BUILD_DIR    = .build

JLINK        = JLinkExe
FLASH_SCRIPT = flash.script

CFLAGS       = -D$(DEVICE) -Wall -Wextra -mcpu=cortex-m3 -mthumb
CFLAGS      += -mfix-cortex-m3-ldrd -ffunction-sections
CFLAGS      += -fdata-sections -fomit-frame-pointer -std=c99 -DDEBUG_EFM
CFLAGS      += -DDEBUG -O0 -g

ASMFLAGS     = -x assembler-with-cpp -D$(DEVICE)
ASMFLAGS    += -Wall -Wextra -mcpu=cortex-m3 -mthumb -DDEBUG_EFM

LDFLAGS      = -Xlinker -Map=$(BUILD_DIR)/$(PROJECT).map -mcpu=cortex-m3
LDFLAGS     += -mthumb -T$(EZR32)/Source/GCC/ezr32lg.ld
LDFLAGS     += --specs=nano.specs -Wl,--gc-sections 

LIBS         = -Wl,--start-group -lgcc -lc -lnosys   -Wl,--end-group

INC = -I$(PLATFORM)/CMSIS/Include \
			-I$(EZR32)/Include \
			-I$(EMLIB)/inc

OBJS = $(addprefix $(BUILD_DIR)/, \
				$(patsubst %.c,%.o, \
				$(patsubst %.S,%.o, \
					$(notdir $(SRC)))))

vpath %.c $(EZR32)/Source/ \
          $(EMLIB)/src/ \
					./
vpath %.S $(EZR32)/Source/GCC/

all: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/%.o: %.c
	@echo "*** compiling $<"
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILD_DIR)/%.o: %.S
	@echo "*** assembling $<"
	@$(CC) $(ASMFLAGS) $(INC) -c -o $@ $<

$(BUILD_DIR)/$(PROJECT).out: $(BUILD_DIR) $(OBJS)
	@echo "*** linking $@"
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).out
	@echo "*** creating $@"
	@$(OBJCOPY) -O binary $< $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

program: $(BUILD_DIR)/$(FLASH_SCRIPT)
	@echo "*** programming"
	@$(JLINK) < $<

$(BUILD_DIR)/$(FLASH_SCRIPT): $(BUILD_DIR)/$(PROJECT).bin
	@echo "*** generating programming script $@"
	@echo "si SWD"                       > $@
	@echo "speed 4000"                  >> $@
	@echo "device $(DEVICE)"            >> $@
	@echo "loadfile $<"                 >> $@
	@echo "verifybin $<, 0x0"           >> $@
	@echo "r"                           >> $@
	@echo "g"                           >> $@
	@echo "exit"                        >> $@

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all program clean
