#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## src
## File description:
## pbrain_gomoku_ai
##

import random
import pisqpipe as pp
import algo as al
from pisqpipe import DEBUG_EVAL, DEBUG

pp.infotext = 'name="pbrain-gomoku-ai", author="Eddy && Nicolas", version="0.01", country="Réunion"'
MAX_BOARD = pp.MAX_BOARD
board = [[0 for i in range(MAX_BOARD)] for j in range(MAX_BOARD)]
myMove = []
oppMove = []

def build_crd(y, x):
    ret = dict()
    ret['x'] = x
    ret['y'] = y
    ret['diag_m'] = ret['y'] - ret['x']
    ret['diag_p'] = ret['y'] + ret['x']
    return (ret)

def isFree(x, y):
	return x >= 0 and y >= 0 and x < pp.width and y < pp.height and board[x][y] == 0

def brain_turn():
	global board, myMove, oppMove
	if pp.terminateAI:
		return
	(y, x) = al.make_Move(board, myMove, oppMove)
	pp.do_mymove(y, x)

def brain_init():
	if pp.width < 5 or pp.height < 5:
		pp.pipeOut("ERROR size of the board")
		return
	pp.pipeOut("OK")

def brain_restart():
	global myMove, oppMove, board
	for x in range(pp.width):
		for y in range(pp.height):
			board[x][y] = 0
	myMove = []
	oppMove = []
	pp.pipeOut("OK")

def brain_my(x, y):
	global myMove, board
	if isFree(x,y):
		board[x][y] = 1
		myMove += [build_crd(x, y)]
	else:
		pp.pipeOut("ERROR my move [{},{}]".format(x, y))

def print_board(arr):
    for i in arr:
        print(i)

def brain_opponents(x, y):
	global oppMove, board
	if isFree(x,y):
		board[x][y] = 2
		oppMove += [build_crd(x, y)]
	else:
		pp.pipeOut("ERROR opponents's move [{},{}]".format(x, y))

def brain_block(x, y):
	global board
	if isFree(x,y):
		board[x][y] = 3
	else:
		pp.pipeOut("ERROR winning move [{},{}]".format(x, y))

def brain_takeback(x, y):
	global myMove, oppMove, board
	if x >= 0 and y >= 0 and x < pp.width and y < pp.height and board[x][y] != 0:
		if (board[x][y] == 1):
			myMove.remove(build_crd(x, y))
		elif (board[x][y] == 2):
			oppMove.remove(build_crd(x, y))
		board[x][y] = 0
		return 0
	return 2

def brain_end():
	pass

def brain_about():
	pp.pipeOut(pp.infotext)

pp.brain_init = brain_init
pp.brain_restart = brain_restart
pp.brain_my = brain_my
pp.brain_opponents = brain_opponents
pp.brain_block = brain_block
pp.brain_takeback = brain_takeback
pp.brain_turn = brain_turn
pp.brain_end = brain_end
pp.brain_about = brain_about

def main():
	pp.main()

if __name__ == "__main__":
	main()
