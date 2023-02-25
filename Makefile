TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
OBJ_DIR ?= $(BUILD_DIR)/obj
SRC_DIR ?= src

SRCS := $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

ifeq ($(mode), desktop)
	DEFINES += -DDESKTOP_MODE
endif

CFLAGS = $(INC_FLAGS) $(DEFINES)

ifeq ($(config), release)
	LDFLAGS += -O3 -Wl,--gc-section -march=native
	CFLAGS += -fdata-sections -ffunction-sections -O3 -march=native
else
	CFLAGS += -MMD -MP
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
