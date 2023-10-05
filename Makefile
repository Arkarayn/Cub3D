NAME = cub3d

RM_DIR = rm -rf

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

HEADER_1 = headers/cub3d.h

HEADER_2 = ctm/ctm_libs/ctm_libs.h

SRCS_DIR = srcs/

OBJ_DIR = obj/

LIB_DIR = ctm/lib/

LIB = ctm_libs.a

SRCS_FILES = main.c  error_handling.c\

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR), $(SRCS_FILES:.c=.o))

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADER_1) $(HEADER_2)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

BARS := "▰▰▱▱▱▱▱▱▱▱▱ 17%" "▰▰▰▱▱▱▱▱▱▱▱ 23%" "▰▰▰▰▱▱▱▱▱▱▱ 38%" "▰▰▰▰▰▱▱▱▱▱▱ 42%" "▰▰▰▰▰▰▱▱▱▱▱ 51%" \
    	"▰▰▰▰▰▰▰▱▱▱▱ 65%" "▰▰▰▰▰▰▰▰▱▱▱ 79%" "▰▰▰▰▰▰▰▰▰▱▱ 87%" "▰▰▰▰▰▰▰▰▰▰ 94%" "▰▰▰▰▰▰▰▰▰▰ 100%" \

all: $(LIB_PATH) $(NAME)
	@for bar in $(BARS); do \
		clear; \
        echo "\n\n\n\t\t\t\033[1;31m$$bar\033[0m"; \
        sleep 0.08; \
    done
	clear
	@echo "\n\n\t\t❈────────•✦•❅•✦•───────❈";
	@echo "\t\t\033[1;3;5;32m    LOADING COMPLETED\033[0m";
	@echo "\t\t❈────────•✦•❅•✦•───────❈\n\n";

$(NAME): $(SRCS) $(O_SRCS)
	clear
	@$(MAKE) -C ctm all
	@$(MAKE) -C minilibx-linux all
	@$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIB_DIR)$(LIB)
	clear

clean:
	@$(MAKE) -C ctm/ clean
	@$(MAKE) -C minilibx-linux clean
	@$(RM_DIR) $(OBJ_DIR)
	@rm $(O_SRCS)
	clear

fclean: clean 
	@$(RM_DIR) $(LIB_DIR)
	@rm $(NAME)
	clear

re: fclean all
	clear

push:
	git add .
	git commit -m "auto commit"
	git push

.PHONY: all clean fclean re push
.SILENT:
