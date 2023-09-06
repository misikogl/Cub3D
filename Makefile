NAME = cub3D

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -Iincludes/ -Isrc/libft/

LIBFT = $(addprefix $(OUTPREFIX), libft.a)

MINILIBX = $(addprefix $(OUTPREFIX), libmlx.a)
MINILIBXFLAGS = -framework OpenGL -framework AppKit # -Lmlx -lmlx
EXTRAMINILIBXFLAGS = -Imlx -Iminilibx-macos


#* FINDING ALL C FILES IN SRC FOLDER
SRC = $(shell find src -name "*.c" | grep -v "libft")
SRCDIR = $(sort $(dir $(SRC)))
SRCFLS = $(notdir $(SRC))

#* BUILDING OBJECT FILES
OUTPREFIX = builds/
OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.c=.o))

vpath %.c $(SRCDIR)
$(OUTPREFIX)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(EXTRAMINILIBXFLAGS) -c $< -o $@

$(OUTPREFIX)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(EXTRAMINILIBXFLAGS) -c $< -o $@

all: $(OUTPREFIX) $(LIBFT) $(MINILIBX) $(NAME)

#* BUILDING FOLDER
$(OUTPREFIX):
	mkdir -p $(OUTPREFIX);

#* COMPILING CUB3D
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MINILIBX) $(LIBFT) $(MINILIBXFLAGS) -o $(NAME)

#* LIBFT COMPILATION
$(LIBFT):
	make -C src/libft
	cp src/libft/libft.a $(OUTPREFIX)/.

$(MINILIBX):
	make -C minilibx-macos
	cp minilibx-macos/libmlx.a $(MINILIBX)



clean:
	if [ -d $(OUTPREFIX) ]; then rm -rf $(OUTPREFIX); fi
	make -C src/libft fclean
	make -C minilibx-macos clean


fclean: clean
	if [ ! -d $(NAME) ]; then rm -rf $(NAME); fi

re: fclean  all