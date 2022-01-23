NAME_FT		= ft
NAME_STD	= std
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -std=c++98 
SRCS_FT     = main/test_ft.cpp
SRCS_STD 	= main/test_std.cpp
OBJ_FT 		= $(SRCS_FT:.cpp=.o)
OBJ_STD 	= $(SRCS_STD:.cpp=.o)
INC			= $(shell find . -type f -name "*.hpp")

all				:	$(NAME_FT) $(NAME_STD)
					@ echo "Compilation done"

					
$(NAME_STD)			: $(OBJ_STD)
				 	 $(CC) $(CFLAGS) -o std $(OBJ_STD)

$(NAME_FT)			: $(OBJ_FT) $(INC)
				 	 $(CC) $(CFLAGS) -o ft $(OBJ_FT)

%.o: %.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

clean			:
					@ rm -rf $(OBJ_FT) $(OBJ_STD)

fclean			:	clean
					@ rm -rf $(NAME_STD) $(NAME_FT)

re				: 	fclean all


.PHONY: 		all fclean clean re
