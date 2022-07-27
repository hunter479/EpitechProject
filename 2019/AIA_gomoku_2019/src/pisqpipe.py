##
## EPITECH PROJECT, 2019
## src
## File description:
## pisqpipe
##

import sys
import time
from threading import Thread
from threading import Event

DEBUG      = False
ABOUT_FUNC = True
DEBUG_EVAL = True

width, height = None, None
th = 0
MAX_BOARD = 19
info_timeout_turn = 30000
info_timeout_match = 1000000000
info_time_left = 1000000000
info_max_memory = 0
info_game_type = 1
info_exact5 = 0
info_renju = 0
info_continuous = 0
terminateAI = None
start_time = None
dataFolder = ""
event1, event2, run_loop = None, None, None
infotext = ""

def brain_init():
	raise NotImplementedError

def brain_restart():
	raise NotImplementedError

def brain_turn():
	raise NotImplementedError

def brain_my(x, y):
	raise NotImplementedError

def brain_opponents(x, y):
	raise NotImplementedError

def brain_block(x, y):
	raise NotImplementedError

def brain_takeback(x, y):
	raise NotImplementedError

def brain_end():
	raise NotImplementedError

def brain_eval(x, y):
	raise NotImplementedError

def brain_about():
	raise NotImplementedError

def pipeOut(what):
	print(what)
	sys.stdout.flush()

def do_mymove(x, y):
	brain_my(x, y)
	pipeOut("{},{}".format(x,y))

def suggest(x, y):
	pipeOut("SUGGEST {},{}".format(x,y))

def safeInt(v):
	try:
		ret = int(v)
		return ret
	except:
		return None

def get_line():
	return sys.stdin.readline().strip()

def parse_coord(param):
	if param.count(",") != 1:
		return None
	x, comma, y = param.partition(',')
	x, y = [safeInt(v) for v in (x, y)]
	if any(v is None for v in (x,y)):
		return None, None
	if x < 0 or y < 0 or x >= width or y >= height:
		return None, None
	return x, y

def parse_3int_chk(param):
	if param.count(',') != 2:
		return None, None, None
	x, y, z = param.split(',')
	x, y, z = [safeInt(v) for v in (x,y,z)]
	if any(v is None for v in (x,y,z)):
		return None, None, None
	return x, y, z

def get_cmd_param(command, input):
	cl = command.lower()
	il = input.lower()
	n1 = len(command)
	n2 = len(input)
	if n1 > n2 or not il.startswith(cl):
		return None
	return input[n1:].lstrip()

def threadLoop():
	global event1, event2, run_loop
	while run_loop.is_set() == True:
		event1.wait()
		if (run_loop.is_set() == True):
			brain_turn()
		event2.set()

def turn():
	global event1, event2
	global terminateAI
	terminateAI = 0
	event2.clear()
	event1.set()

def stop():
	global event1, event2
	global terminateAI
	terminateAI = 1
	event2.wait()

def start():
	stop()
	global width, height
	if not width:
		width = height = 19
		brain_init()

def do_command(cmd):
	global info_max_memory, info_timeout_match, info_timeout_turn, info_time_left, info_game_type, info_exact5, info_continuous, info_renju, dataFolder
	global width, height, MAX_BOARD
	global run_loop, event1
	#
	param = get_cmd_param("info", cmd)
	if param is not None:
		info = get_cmd_param("max_memory", param)
		if info is not None:
			info_max_memory = int(info)
			return
		#
		info = get_cmd_param("timeout_match", param)
		if info is not None:
			info_timeout_match = int(info)
			return
		#
		info = get_cmd_param("timeout_turn", param)
		if info is not None:
			info_timeout_turn = int(info)
			return
		#
		info = get_cmd_param("time_left", param)
		if info is not None:
			info_time_left = int(info)
			return
		#
		info = get_cmd_param("game_type", param)
		if info is not None:
			info_game_type = int(info)
			return
		#
		info = get_cmd_param("rule", param)
		if info is not None:
			e = int(info)
			info_exact5 = e & 1
			info_continuous = (e >> 1) & 1
			info_renju = (e >> 2) & 1
			return
		#
		info = get_cmd_param("folder", param)
		if info is not None:
			dataFolder = info
			return
		#
		info = get_cmd_param("evaluate", param)
		if DEBUG_EVAL and info is not None:
			x, y = parse_coord(info)
			if x is not None and y is not None:
				brain_eval(x, y)
			return
		return
	#
	param = get_cmd_param("start", cmd)
	if param is not None:
		width = safeInt(param)
		if width is None or width < 5:
			width = 0
			pipeOut("ERROR message - unsupported size or other error")
			event1.set()
			run_loop.clear()
			stop()
			brain_end()
			sys.exit(0)
		else:
			height = width
			MAX_BOARD = height
			start()
			brain_init()
		return
	#
	param = get_cmd_param("rectstart", cmd)
	if param is not None:
		if param.count(',') != 1:
			width = height = 0
		else:
			width,c,height = param.partition(',')
			width,height = [safeInt(v) for v in (width,height)]
		if width is None or width < 5 or height is None or height < 5:
			width = height = 0
			pipeOut("ERROR bad RECTSTART parameters")
		else:
			start()
			brain_init()
		return
	#
	param = get_cmd_param("restart", cmd)
	if param is not None:
		start()
		brain_restart()
		return
	#
	param = get_cmd_param("turn", cmd)
	if param is not None:
		start()
		x, y = parse_coord(param)
		if x is None or y is None:
			pipeOut("ERROR bad coordinates")
		else:
			brain_opponents(x, y)
			turn()
		return
	#
	param = get_cmd_param("play", cmd)
	if param is not None:
		start()
		x, y = parse_coord(param)
		if x is None or y is None:
			pipeOut("ERROR bad coordinates")
		else:
			do_mymove(x, y)
		return
	#
	param = get_cmd_param("begin", cmd)
	if param is not None:
		start()
		turn()
		return
	#
	param = get_cmd_param("about", cmd)
	if param is not None:
		if ABOUT_FUNC:
			brain_about()
		else:
			pipeOut(infotext)
		return
	#
	param = get_cmd_param("end", cmd)
	if param is not None:
		event1.set()
		run_loop.clear()
		stop()
		brain_end()
		sys.exit(0)
		return
	#
	param = get_cmd_param("board", cmd)
	if param is not None:
		start()
		while True:
			cmd = get_line()
			x,y,who = parse_3int_chk(cmd)
			if who == 1:
				brain_my(x, y)
			elif who == 2:
				brain_opponents(x, y)
			elif who == 3:
				brain_block(x, y)
			else:
				if cmd.lower() != "done":
					pipeOut("ERROR x,y,who or DONE expected after BOARD")
				break
		turn()
		return
	#
	param = get_cmd_param("takeback", cmd)
	if param is not None:
		start()
		txt = "ERROR bad coordinates"
		x, y = parse_coord(param)
		if x is not None and y is not None:
			e = brain_takeback(x, y)
			if e == 0:
				txt = "OK"
			elif e == 1:
				txt = "UNKNOWN"
		pipeOut(txt)
		return
	#
	pipeOut("UNKNOWN command {}".format(cmd))

def main():
	global th
	global event1, event2, run_loop
	th = Thread(target= threadLoop)
	event1 = Event()
	event2 = Event()
	run_loop = Event()
	event2.set()
	run_loop.set()
	th.start()
	while True:
		cmd = get_line()
		do_command(cmd)
