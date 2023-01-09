PROGRAM		= test_imgio
SRC_DIR		= src test
INC_DIR		= include test/include
BUILD_DIR	= build
BIN_DIR		= bin
OUT_DIR		= out

SRCS		= $(foreach srcdir, $(SRC_DIR), $(shell find $(srcdir) -type f -name *.c))
OBJS		= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
INCLUDE		= $(addprefix -I, $(INC_DIR))

CC			= gcc
CFLAGS		= -Wall
CLIBS		= -lm

TARGET		= $(BIN_DIR)/$(PROGRAM)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $@

$(BUILD_DIR)/%.o: %.c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(INCLUDE) $(CLIBS) -c $< -o $@

run:
	@mkdir -p $(OUT_DIR)
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(OUT_DIR)
