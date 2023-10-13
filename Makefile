SHELL = /bin/sh
NAME = gnl
SRCS = \
	srcs/main.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c

INC = includes/

# **************************************************************************** #

OBJDIR	= objs/
OBJS = $(patsubst srcs/%.c, $(OBJDIR)%.o, $(SRCS))
DEPS	= $(OBJS:.o=.d)

BUFFER = 3

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= -MMD -MP -g
CFLAGS	+= $(addprefix -I,$(INC))
BFLAG	= -D BUFFER_SIZE=$(BUFFER)
RM		= rm -f

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# **************************************************************************** #

all: $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	@printf "\n$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	@printf "$(YE)&&& Linked [$(CC)] &&&\n--- $(NAME)$(RC)\n"
	$(CC) $(CFLAGS) $(BFLAG) $(OBJS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "$(GR)=== Compiling ... [$(CC) $(CFLAGS) $(BFLAG)] ===$(RC)\n"

$(OBJDIR)%.o: srcs/%.c
	@$(CC) $(CFLAGS) $(BFLAG) -c -o $@ $<
	@printf "$(GR)+$(RC)"

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	@printf "$(RE)=== Removing $(NAME) ===$(RC)\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)