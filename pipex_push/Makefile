# Directories
OBJDIR    := obj
SRC_DIR   := src
LIBFT_DIR := libft

# Library
LIBFT     := $(LIBFT_DIR)/libft.a

# Compiler
CC        := cc
CFLAGS    := -Wall -Wextra -Werror

# Executable
NAME      := pipex

# Source and Object Files
SRC_SRCS := $(SRC_DIR)/children.c \
            $(SRC_DIR)/pipex.c \
            $(SRC_DIR)/utils0.c \
            $(SRC_DIR)/utils1.c

OBJS := $(SRC_SRCS:src/%.c=$(OBJDIR)/%.o)

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I$(LIBFT_DIR) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
