#######################################################################
#
#  The MIT License (MIT)
# 
#  
#  Copyright (C) 2013 Yu Jing (yujing5b5d@gmail.com)
#
#  Permission is hereby granted, free of charge, to any person 
#  obtaining a copy of this software and associated documentation files 
#  (the "Software"), to deal in the Software without restriction,  
#  including without limitation the rights to use, copy, modify, merge, 
#  publish, distribute,sublicense, and/or sell copies of the Software, 
#  and to permit persons to whom the Software is furnished to do so,  
#  subject to the following conditions:
# 
#  The above copyright notice and this permission notice shall be 
#  included in all copies or substantial portions of the Software.
# 
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
#  EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
#  MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
#  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
#  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
#  TORT OR OTHERWISE,ARISING FROM,OUT OF OR IN CONNECTION WITH THE 
#  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# 
########################################################################

########################################################################
#
# Makefile
#
# Edited By Yu Jing @ Mar. 24 , 2013
#
########################################################################


########################SYSTEM SETTINGS#################################
CC			:= gcc
CP			:= @cp
DEL			:= @rm -rf
MV			:= @mv
SAY			:= @echo
GADD			:= @git add 
GCMT			:= @git commit -m 


########################COMPILE SETTINGS################################
VPATH			:= .:include/:src/:lib/:obj/
	export	VPATH
LIBS			:= -L lib/ -ldl -lpthread  -lm 
INCFLAG			:= -I include/
CFLAGS			:= -Wall	${INCFLAG} -std=c99
GNUFLAGS		:= -Wall	${INCFLAG} -std=gnu99
OBJS			:= 
PROGS			:= gitupdate

.PHONY			: all clean succ gitupdate
########################################################################
all			: ${PROGS} succ

	
gitupdate		:
	-${GADD} .
	-${GCMT} `date "+auto:%Y%m%d%H%M%S"`




succ			:
	${SAY} "Complete !" 

clean			: 
	-${DEL} ${PROGS} doclassify
	-${DEL} ${OBJS} 
	-${DEL} *~ include/*~ src/*~ data/*~
	-${DEL} *.swp
	-${DEL} svm_model svm_predictions
	-${DEL} data/fa/*~ data/oraby/*~ data/orbz/*~ data/orbz_sec/*~

dbclean			:
	${DEL} db/features.db
