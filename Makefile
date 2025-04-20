## Directories
OBJDIR    := obj
SRC_DIR   := src
LIBFT_DIR := libft

# Compiler
CC        := cc
#CFLAGS    := -Wall -Wextra -Werror

# Executable
NAME      := pipex

# Source and Object Files
SRC_SRCS   := $(wildcard $(SRC_DIR)/*.c)
LIBFT_SRCS := $(wildcard $(LIBFT_DIR)/*.c)
ALL_SRCS   := $(SRC_SRCS) $(LIBFT_SRCS)

# Object file paths under obj/, preserving directory structure
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(ALL_SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile source files into obj/ subdirectories
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
