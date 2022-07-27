--
-- EPITECH PROJECT, 2019
-- fun_evalexpr
-- File description:
-- Parser
--

module Parser where

data DFc v =
    DParsed v
    | NoDParse
    deriving (Eq, Ord, Show)

isChrValid :: Char -> DFc Char
isChrValid '0' = DParsed '0'
isChrValid '1' = DParsed '1'
isChrValid '2' = DParsed '2'
isChrValid '3' = DParsed '3'
isChrValid '4' = DParsed '4'
isChrValid '5' = DParsed '5'
isChrValid '6' = DParsed '6'
isChrValid '7' = DParsed '7'
isChrValid '8' = DParsed '8'
isChrValid '9' = DParsed '9'
isChrValid ')' = DParsed ')'
isChrValid _ = NoDParse

isVal :: String -> Bool
isVal [] = True
isVal (x:xs) = case isChrValid x of
    DParsed _ -> isVal xs
    NoDParse -> False

split :: String -> [String]
split [] = [[]]
split ('-':cs) = []:['-']:split cs
split ('+':cs) = []:['+']:split cs
split ('/':cs) = []:['/']:split cs
split ('*':cs) = []:['*']:split cs
split ('(':cs) = []:['(']:split cs
split ('^':cs) = []:['^']:split cs
split (')':cs) = []:[')']:split cs
split (c:cs) = (c:cellCompletion) : otherCells
    where cellCompletion : otherCells = split cs

mulMinus :: [String] -> [String] -> [String]
mulMinus [] res = res
mulMinus ("-":r) [] = mulMinus r (["-1"] ++ ["*"])
mulMinus ("-":r) res = case isVal (last res) of
    True -> mulMinus r (res ++ ["-"])
    False -> mulMinus r (res ++ ["-1"] ++ ["*"])
mulMinus (c:r) res = mulMinus r (res ++ [c])

rmEmpty :: [String] -> [String] -> [String]
rmEmpty [] [] = [[]]
rmEmpty ("":cs) [] = rmEmpty cs []
rmEmpty ("":cs) tab = rmEmpty cs tab
rmEmpty (c:[]) tab = rmEmpty [] (tab ++ [c])
rmEmpty [] tab = tab
rmEmpty (c:cs) tab = (rmEmpty cs (tab ++ [c]))

fCutStr :: String -> [String]
fCutStr s = mulMinus (rmEmpty(split s) []) []