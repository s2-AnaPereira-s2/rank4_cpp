NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Animal.cpp \
	$(SRC_DIR)/Dog.cpp \
	$(SRC_DIR)/Cat.cpp \
	$(SRC_DIR)/WrongAnimal.cpp \
	$(SRC_DIR)/WrongCat.cpp \
	$(SRC_DIR)/Brain.cpp


OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re