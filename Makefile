
NAME = fractol

SRCS = main.c mlx_utils.c \
		utils.c julia.c  mandelbrot.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Ofast

all: $(NAME)

%.o: %.c fractol.h
	$(CC)  $(FlAGS) -Imlx -c $< -o $@ -I fractol.h

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FlAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)