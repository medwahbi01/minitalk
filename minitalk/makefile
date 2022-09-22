INC = minitalk.h
INC_BONUS = minitalk_bonus.h
CC = gcc
W = -Wall -Wextra -Werror

all : server client

bonus : client_bonus server_bonus

server: server.c util.c $(INC)
	${CC} $(W) server.c util.c -o server

client: client.c util.c $(INC)
	${CC} $(W) client.c util.c -o client

server_bonus: server_bonus.c util.c $(INC_BONUS)
	${CC} $(W) server_bonus.c util.c -o server_bonus

client_bonus: client_bonus.c util.c $(INC_BONUS)
	${CC} $(W)  client_bonus.c util.c -o client_bonus
clean:
	rm -rf server server_bonus client client_bonus

fclean : clean
	rm -rf server server_bonus client client_bonus

re : fclean all
