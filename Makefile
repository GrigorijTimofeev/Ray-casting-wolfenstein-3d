NAME := cub3D

SRCS := main/main.c gnl/get_next_line.c gnl/get_next_line_utils.c parser/ft_parser.c \
		parser/ft_parser_args_1.c parser/ft_parser_args_2.c \
		parser/ft_parser_dop.c parser/ft_parser_map.c parser/ft_parser_map_dop_1.c \
		parser/ft_parser_map_dop_2.c engine/ft_map_creator_1.c \
		engine/ft_engine_dop_1.c engine/ft_engine_sprites_1.c \
		engine/ft_engine_sprites_2.c engine/ft_bmp.c \
		engine/ft_engine_dop_2.c engine/ft_map_creator_2.c engine/ft_map_creator_3.c \
		engine/ft_map_creator_4.c

OBJS := ${patsubst %.c,%.o,${SRCS}}

D_FILES := ${patsubst %.c,%.d,${SRCS}}

FLAGS := -Wall -Wextra -Werror
FRAMEWORK_FLAGS := -framework OpenGL -framework Appkit
GCC := gcc
INLUDES := includes/
LIBFT := libft.a
LIBFT_DIR := ./libft/
MLX := libmlx.dylib
MLX_DIR := ./minilibx_mms_20200219/
IMAGE := image.bmp

all: ${NAME}
  
${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	make -C ${LIBFT_DIR} bonus
	make -C ${MLX_DIR}
	cp ${MLX_DIR}${MLX} ./
	cp ${LIBFT_DIR}${LIBFT} ./
	gcc ${OBJS} ${LIBFT} ${MLX} ${FRAMEWORK_FLAGS}  -o ${NAME}

%.o: %.c
	${GCC} ${FLAGS} -I ${INLUDES} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:
	rm -f ${OBJS} ${LIBFT} ${D_FILES}
	make -C $(LIBFT_DIR) fclean
	make -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME} ${MLX}
	rm -f ${IMAGE}

re: fclean all

.PHONY: all clean fclean re