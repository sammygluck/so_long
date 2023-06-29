#current project
NAME= so_long
SRCDIR= src
SRCS= $(wildcard $(SRCDIR)/*.c)
OBJDIR= obj
OBJ= $(SRCS:$(SRCDIR)/%.c = $(OBJDIR)/%.o)
BINDIR= bin

#external projects
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a
GNLDIR = gnl 
GNL = $(GNLDIR)/gnl.a
MLXDIR = mlx_linux
MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#MLX_I =

#compiler stuff
CC = gcc
CFLAGS = -Wall -Wextra -g -I/usr/include -Imlx_linux -I$(LIBFTDIR) -I$(PRINTFDIR) -I$(GNLDIR)

#targets

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLXDIR)
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) -C $(PRINTFDIR)
	@$(MAKE) -C $(GNLDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@
