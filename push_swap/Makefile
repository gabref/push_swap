# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.template                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 10:00:31 by tmatis            #+#    #+#              #
#    Updated: 2024/02/02 14:09:38 by galves-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################


NAME	= push_swap
NAME_B	= checker
CC 		= cc
CFLAGS	= -Wall -Werror -Wextra
AUTHOR	= galves-f
DATE	= 2024/01/24

NOVISU 	= 0 # 1 = no progress bar usefull when tty is not available

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

FILE_EXTENSION	= .c

SRCS_PATH		= .

INCLUDE_PATH	= .

SRCS			= initializers.c \
				  	print.c \
				  	free_utils.c \
				  	sorting.c \
				  	utils.c \
				  	utils_ds.c \
				  	utils_sorting.c \
				  	utils_finders.c \
				  	split.c \
					operation_swap.c \
					operation_push.c \
					operation_rotate.c
MAIN			= main.c

SRCS_B			= initializers.c \
				  	print.c \
				  	get_next_line.c \
				  	get_next_line_utils.c \
				  	free_utils.c \
				  	checker_utils.c \
				  	utils.c \
				  	utils_ds.c \
				  	utils_sorting.c \
				  	utils_finders.c \
				  	split.c \
					operation_swap.c \
					operation_push.c \
					operation_rotate.c
MAIN_B			= checker.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL := /bin/bash


OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
DEPS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

OBJS_B				= $(addprefix objs/, ${SRCS_B:$(FILE_EXTENSION)=.o})
OBJ_MAIN_B			= $(addprefix objs/, ${MAIN_B:$(FILE_EXTENSION)=.o})
DEPS_B				= $(addprefix objs/, ${SRCS_B:$(FILE_EXTENSION)=.d})
DEPS_MAIN_B			= $(addprefix objs/, ${MAIN_B:$(FILE_EXTENSION)=.d})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"

HASH	= 

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	DATE	:= $(shell git log -1 --date=format:"%Y/%m/%d %T" --format="%ad")
	HASH	:= $(shell git rev-parse --short HEAD)
endif

define save_files_changed
	FILE_CPP=`echo $(SRCS) $(MAIN) $(SRCS_B) $(MAIN_B)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
	for FILE in $$FILE_CPP; do \
		for OBJ in $$FILE_OBJ; do \
			if [ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]; then \
				if [ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]; then \
					FILE_DEP=`echo objs/$$OBJ | sed 's/\.o/\.d/'`; \
					HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [ $$RECOMPILE -eq 0 ]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

define draw_bar
	FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
	FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
	if [ $$FILE_TOTAL -eq 0 ]; then \
		FILE_TOTAL=1; \
		FILE_DONE=1; \
	fi; \
	RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
	RES=`echo $${RES%%.*}`; \
	printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
	i=0; \
	while [ $$i -lt 48 ]; do \
		if [ $$i -lt $$RES ]; then \
			printf "$(OK_COLOR)█$(NO_COLOR)"; \
		else \
			printf "$(COM_COLOR)▒$(NO_COLOR)"; \
		fi; \
		((i=$$i+1)); \
	done; \
	printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
	printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
	printf " "; \
	((FILE_DONE=$$FILE_DONE+1)); \
	echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

define display_progress_bar
	if [ $(NOVISU) -eq 0 ]; then \
		line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
		max_line=`tput lines`; \
		((max_line=$$max_line-2));\
		new_line=0; \
		tput sc; \
		i=0; \
		while [ $$i -lt 60 ]; do \
			printf " "; \
			((i=$$i+1)); \
		done; \
		tput rc; \
		if [ $$line -gt $$max_line ]; then \
			new_line=1; \
			echo ; \
		else \
			((line=$$line+1));\
		fi; \
		tput sc; \
		tput cup $$line; \
		$(draw_bar) \
		if [ $$new_line -eq 1 ]; then \
			((line=$$line-1));\
			tput cup $$line; \
		else \
			tput rc; \
		fi; \
	fi
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
	@echo "OS : $(detected_OS)"
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo


$(NAME):	${OBJS} ${OBJ_MAIN}
			$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -o $@ ${OBJS} ${OBJ_MAIN}

bonus:	${OBJS_B} ${OBJ_MAIN_B}
		$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -o $(NAME_B) ${OBJS_B} ${OBJ_MAIN_B}

setup:
	@$(call save_files_changed)

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_PATH)

clean:		header
			@rm -rf objs objs_tests
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		header clean
			@rm -rf $(NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

test2:$(NAME)
	$(eval ARG = $(shell gshuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3:$(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5:$(NAME)					
	$(eval ARG = $(shell gshuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100:$(NAME)
	$(eval ARG = $(shell gshuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500:$(NAME)
	$(eval ARG = $(shell gshuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test1000:$(NAME)
	$(eval ARG = $(shell gshuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY:		all clean fclean re header test2 test3 test5 test100 test500 test1000
