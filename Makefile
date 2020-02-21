NAME	=	uls

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	main.c mx_check_device.c mx_del_files.c mx_del_liarr.c \
			mx_edit_time.c mx_flag_l.c mx_get_files.c \
			mx_get_major_and_minor.c mx_get_names.c mx_join.c mx_opendir.c \
			mx_output.c mx_output_C.c mx_output_G.c mx_output_M.c \
			mx_output_X.c mx_pars.c mx_print_all.c mx_print_group.c \
			mx_print_lnk.c mx_print_permission.c mx_print_size.c \
			mx_print_symblink.c mx_printcharerr.c mx_printstr_g.c \
			mx_sort.c

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
