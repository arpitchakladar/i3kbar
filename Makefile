TARGET_EXEC ?= a.out

BUILD_DIR ?= build
OBJ_DIR ?= $(BUILD_DIR)/obj
SRC_DIRS ?= src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

ifeq ($(mode), desktop)
	DEFINES += -DDESKTOP_MODE
endif

CFLAGS = $(INC_FLAGS) $(DEFINES)

ifeq ($(config), release)
	LDFLAGS := -O3 -Wl,--gc-section
	CFLAGS +=  -fdata-sections -ffunction-sections -O3
else
	CFLAGS += -MMD -MP
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
