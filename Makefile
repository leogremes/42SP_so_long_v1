SRC		=		utils/*		\
				src/*		\

all:
	cc -Wall -Werror -Wextra $(SRC) -L. -lmlx -Iinc -lX11 -lXext -g
#	cc -Wall -Werror -Wextra $(SRC) -Iinc -lX11 -lXext -lmlx