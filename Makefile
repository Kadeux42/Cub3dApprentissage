# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shlu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 21:01:19 by shlu              #+#    #+#              #
#    Updated: 2021/04/19 12:01:42 by shlu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCS			=	./incs/cub3d.h

LIBS			=	libmlx_Linux.a libft.a -lXext -lX11 -lm

SRCS			=	$(addprefix cub3d/srcs/,\
main.c \
ft_cub3d_init.c \
ft_display_floor_and_ceiling.c \
ft_display_sprite.c \
ft_display_stripe.c \
ft_error.c \
ft_free_all_struct.c \
ft_free_graph.c \
ft_free_source.c \
ft_free_table.c \
ft_graphics.c \
ft_identifier.c \
ft_key_hook.c \
ft_map_id.c \
ft_map_check.c \
ft_map_check_utils.c \
ft_map_count_line.c \
ft_map_save.c \
ft_move.c \
ft_path.c \
ft_perp_wall_dist.c \
ft_pick_texture.c \
ft_r.c \
ft_raycasting.c \
ft_rgb.c \
ft_sprite.c \
ft_sprite_data.c \
ft_struct_g_init.c \
ft_struct_r_init.c \
ft_struct_s_init.c \
ft_resolution_correct.c \
ft_identifier_check.c \
ft_struct_s_init_null.c \
ft_screenshot.c \
ft_win_bmp.c \
ft_win_bmp_utils.c \
)

OBJS			=	${SRCS:.c=.o}

NAME			=	cub3D

CC				=	clang

FLAGS			=	-Wall -Wextra -Werror

%.o				:	%.c
					@$(CC) $(FLAGS) -o $@ -c $<

${NAME}			:	ft_libft ${OBJS}
					@echo "make cub3D."
					@${CC} ${FLAGS} -o ${NAME} ${OBJS} -L. ${LIBS} -I ${INCS} -D LINUX
					@echo "cub3D done\n"

ft_libft			:
					@make bonus -C ./libft/
					@cp libft/libft.a .
					@echo "\nlibft.a copied."

all				:	${NAME}

clean			:
					@rm -rf ${OBJS}
					@echo "\ncub3d clean done."

fclean			:	clean
					@rm -f libft.a
					@make fclean -C libft/
					@rm -f cub3D
					@echo "\ncub3d fclean done.\n--------We are all clear--------"

re				:	fclean all

.PHONY			:	all clean fclean re
