#current project
NAME= so_long
SRCDIR= src
SRCS= $(wildcard $(SRCDIR)/*.c)
OBJDIR= obj
OBJ= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
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
CFLAGS = -Wall -Wextra  -g

#targets

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLXDIR)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	@$(MAKE) -C $(GNL)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTFDIR) $(GNL) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

	
