
##
## EPITECH PROJECT, 2019
## AIA_gomoku_2019
## File description:
## algo
##

import pisqpipe as pp

played_first = False

def vertical_count(Move, board, crd, who):
    srt = [c for c in Move if c['x'] == crd['x']]
    srt.sort(key=lambda i:i['y'])
    nbp, block, p, bound = 0, 0, 0, 0
    for x in range(srt.index(crd), len(srt)):
        if (srt[x]['y'] == crd['y'] + p and srt[x]['y'] != crd['y']):
            nbp += 1
            bound = x
        p += 1
    if (bound == 0):
        bound = (crd['y'] + 1, crd['y'])[(crd['y'] + 1) == len(board)]
    else:
        bound = (srt[bound]['y'] + 1, srt[bound]['y'])[(srt[bound]['y'] + 1) == len(board)]
    if (board[bound][crd['x']] != 0):
        block += 1
    p = 0
    i = srt.index(crd)
    while i >= 0:
        if (srt[i]['y'] == crd['y'] - p):
            nbp += 1
            bound = i
        p += 1
        i -= 1
    if (srt[bound]['y'] == 0):
        return ((nbp, 0)[block == 1])
    if (board[srt[bound]['y'] - 1][crd['x']] != 0):
        block += 1
    return ((nbp, 0)[block == 2])

def horizontal_count(Move, board, crd, who):
    srt = [c for c in Move if c['y'] == crd['y']]
    srt.sort(key=lambda i:i['x'])
    nbp, block, p, bound = 0, 0, 0, 0
    for x in range(srt.index(crd), len(srt)):
        if (srt[x]['x'] == crd['x'] + p and srt[x]['x'] != crd['x']):
            nbp += 1
            bound = x
        p += 1
    if (bound == 0):
        bound = (crd['x'] + 1, crd['x'])[crd['x'] + 1 == len(board[crd['y']])]
    else:
        bound = srt[bound]['x'] + 1
    if (board[crd['y']][bound] != 0):
        block += 1
    p = 0
    i = srt.index(crd)
    while i >= 0:
        if (srt[i]['x'] == crd['x'] - p):
            nbp += 1
            bound = i
        p += 1
        i -= 1
    if (srt[bound]['x'] == 0):
        return ((nbp, 0)[block == 1])
    if (board[crd['y']][srt[bound]['x'] - 1] != 0):
        block += 1
    return ((nbp, 0)[block == 2])

def diag_m_count(Move, board, crd, who):
    srt = [c for c in Move if c['diag_m'] == crd['diag_m']]
    srt.sort(key=lambda i:i['x'])
    nbp, block, p, bound = 0, 0, 0, 0
    i = srt.index(crd)
    for x in range(i, len(srt)):
        if (srt[x]['x'] == crd['x'] + p and srt[x]['y'] == crd['y'] + p and srt[x]['x'] != crd['x']):
            nbp += 1
            bound = srt[x]
        p += 1
    if (bound == 0):
        if (crd['x'] + 1 == len(board[crd['y']]) or crd['y'] + 1 == len(board)):
            bound = (crd['y'], crd['x'])
        else:
            bound = (crd['y'] + 1, crd['x'] + 1)
    else:
        if (bound['y'] + 1 >= len(board[0]) or bound['x'] + 1 >= len(board[0])):
            bound = (bound['y'], bound['x'])
        else:
            bound = (bound['y'] + 1, bound['x'] + 1)
    if (board[bound[0]][bound[1]] != 0):
        block += 1
    p = 0
    bound = 0
    while i >= 0:
        if (srt[i]['x'] == crd['x'] - p or crd['y'] - p == srt[i]['y']):
            nbp += 1
            bound = srt[i]
        p += 1
        i -= 1
    if (board[bound['y']][bound['x']] == 0):
        return ((nbp, 0)[block == 1])
    if (bound['y'] - 1 < 0 or bound['x'] - 1 < 0 or board[bound['y'] - 1][bound['x'] - 1] != 0):
        block += 1
    return ((nbp, 0)[block == 2])

def diag_p_count(Move, board, crd, who):
    srt = [c for c in Move if c['diag_p'] == crd['diag_p']]
    srt.sort(key=lambda i:i['y'])
    nbp, block, p, bound = 0, 0, 0, 0
    i = srt.index(crd)
    for x in range(i, len(srt)):
        if (srt[x]['x'] == crd['x'] - p and srt[x]['y'] == crd['y'] + p and srt[x]['x'] != crd['x']):
            nbp += 1
            bound = srt[x]
        p += 1
    if (bound == 0):
        if (crd['x'] + 1 == len(board[crd['y']]) or crd['y'] + 1 == len(board)):
            bound = (crd['y'], crd['x'])
        else:
            bound = (crd['y'] + 1, crd['x'] - 1)
    else:
        if (bound['y'] + 1 >= len(board) or bound['x'] + 1 >= len(board[0])):
            bound = (bound['y'], bound['x'])
        else:
            bound = (bound['y'] + 1, bound['x'] - 1)
    if (board[bound[0]][bound[1]] != 0):
        block += 1
    p = 0
    bound = 0
    while i >= 0:
        if (srt[i]['x'] == crd['x'] + p or crd['y'] - p == srt[i]['y']):
            nbp += 1
            bound = srt[i]
        p += 1
        i -= 1
    if (board[bound['y']][bound['x']] == 0):
        return ((nbp, 0)[block == 1])
    if (bound['y'] - 1 < 0 or bound['x'] + 1 < len(board[0]) or board[bound['y'] - 1][bound['x'] - 1] != 0):
        block += 1
    return ((nbp, 0)[block == 2])

def axe_score(Move, board, crd, who):
    result = []
    result += [("vertical", vertical_count(Move, board, crd, who))]
    result += [("horizontal", horizontal_count(Move, board, crd, who))]
    result += [("diag_m", diag_m_count(Move, board, crd, who))]
    result += [("diag_p", diag_p_count(Move, board, crd, who))]
    return (crd, max(result, key=lambda result:result[1]))

def check_all_threat(myMove, oppMove, board):
    listMe = [axe_score(myMove, board, c, 1) for c in myMove]
    listOpp = [axe_score(oppMove, board, c, 2) for c in oppMove]
    if (len(listMe) != 0):
        meThreat = max(listMe, key=lambda listMe:listMe[1][1])
    else:
        meThreat = 0
    if (len(listOpp) != 0):
        oppThreat = max(listOpp, key=lambda listOpp:listOpp[1][1])
    else:
        oppThreat = 0
    return (meThreat, oppThreat)

def get_y_free(board, crd, who):
    res = 0
    if (who == "2"):
        block = 1
    else:
        block = 2
    for y in range(crd['y'], len(board)):
        if (board[y][crd['x']] == 0):
            res = y
            break
        elif (board[y][crd['x']] == block):
            break
    if (res != 0):
        return (res, crd['x'])
    y = crd['y']
    while (y > 0):
        if (board[y][crd['x']] == 0):
            res = y
            break
        y -= 1
    return (res, crd['x'])

def get_x_free(board, crd, who):
    res = 0
    if (who == "2"):
        block = 1
    else:
        block = 2
    for x in range(crd['x'], len(board[crd['y']])):
        if (board[crd['y']][x] == 0):
            res = x
            break
        elif (board[crd['y']][x] == block):
            break
    if (res != 0):
        return (crd['y'], res)
    x = crd['x']
    while (x > 0):
        if (board[crd['y']][x] == 0):
            res = x
            break
        x -= 1
    return (crd['y'], res)

def get_diag_m_free(board, crd, who):
    i = 0
    if (who == "2"):
        block = 1
    else:
        block = 2
    while (crd['y'] + i < len(board) and crd['x'] + i < len(board[0])):
        if (board[crd['y'] + i][crd['x'] + i] == 0):
            return (crd['y'] + i, crd['x'] + i)
        elif (board[crd['y'] + i][crd['x'] + i] == block):
            break
        i += 1
    i = 0
    while (crd['y'] - i > 0 or crd['x'] - i > 0):
        if (board[crd['y'] - i][crd['x'] - i] == 0):
            break
        i += 1
    return (crd['y'] - i, crd['x'] - i)

def get_diag_p_free(board, crd, who):
    i = 0
    if (who == "2"):
        block = 1
    else:
        block = 2
    while (board[crd['y'] - i][crd['x'] + i] == int(who) and crd['y'] - i > 0 and crd['x'] + i < len(board[0])):
        if (board[crd['y'] - i][crd['x'] + i] == 0):
            return (crd['y'] - i, crd['x'] + i)
        elif (board[crd['y'] - i][crd['x'] + i] == block):
            break
        i += 1
    i = 0
    while (crd['y'] - i > 0 and crd['x'] + i < len(board[0])):
        if (board[crd['y'] - i][crd['x'] + i] == 0):
            break
        i += 1
    return (crd['y'] - i, crd['x'] + i)

def print_board(arr):
    for i in arr:
        print(i)

def do_move(Threat, board, who):
    if (Threat[1][0] == "vertical"):
        cord = get_y_free(board, Threat[0], who)
    elif (Threat[1][0] == "horizontal"):
        cord = get_x_free(board, Threat[0], who)
    elif (Threat[1][0] == "diag_m"):
        cord = get_diag_m_free(board, Threat[0], who)
    elif (Threat[1][0] == "diag_p"):
        cord = get_diag_p_free(board, Threat[0], who)
    return (cord)

def determine_Move(meThreat, oppThreat, board):
    global played_first
    if (meThreat == 0):
        return ("2")
    elif (oppThreat == 0):
        return ("1")
    if (meThreat[1][1] == oppThreat[1][1] and played_first == True):
        return ("1")
    if (meThreat[1][1] > oppThreat[1][1]):
        return ("1")
    else:
        return ("2")

def choose_move(board, me, opp):
    threatList = check_all_threat(me, opp, board)
    who = determine_Move(threatList[0], threatList[1], board)
    if (who == "1"):
        return (do_move(threatList[0], board, who))
    else:
        return (do_move(threatList[1], board, who))

def make_Move(board, myMove, oppMove):
    global played_first
    if (len(myMove) != 0 or len(oppMove) != 0):
        return (choose_move(board, myMove, oppMove))
    else:
        played_first = True
        return (int((pp.MAX_BOARD)/2), int((pp.MAX_BOARD)/2))
