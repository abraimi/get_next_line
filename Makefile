NAME=gnl.a
BUILDDIR=build
SRCS= get_next_line_utils.c get_next_line.c
OBJS= $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCS))

all: $(BUILDDIR) $(NAME)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(NAME): $(OBJS)
	$(AR) rsc $(NAME) $(OBJS)

$(BUILDDIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
