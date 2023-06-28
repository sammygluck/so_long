#current project
NAME= so_long
SRCDIR= src
SRCS= $(wildcard $(SRCDIR)/*.c)
OBJDIR= obj
OBJ= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BINDIR= bin

#external projects
#LIBFTDIR = 
#LIBFT =
#PRINTFDIR = 
#PRINTF = 
#GNLDIR = 
#GNL =
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
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

	
