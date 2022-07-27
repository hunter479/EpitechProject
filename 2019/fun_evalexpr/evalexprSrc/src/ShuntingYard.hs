--
-- EPITECH PROJECT, 2019
-- fun_evalexpr
-- File description:
-- ShuntingYard
--

module ShuntingYard where

import Parser
import Text.Printf

data Token v =
        Parsed v
        | NoParse
        deriving (Eq, Ord, Show)

data Pref = PrLeft | PrRight | PrSame
    deriving (Eq, Ord, Show, Read, Bounded, Enum)

isOp :: String -> Token String
isOp "+" = Parsed "+"
isOp "-" = Parsed "-"
isOp "/" = Parsed "/"
isOp "*" = Parsed "*"
isOp "^" = Parsed "^"
isOp "(" = Parsed "("
isOp ")" = Parsed ")"
isOp _ = NoParse

opPrio :: String -> Token Int
opPrio "+" = Parsed 2
opPrio "-" = Parsed 2
opPrio "/" = Parsed 3
opPrio "*" = Parsed 3
opPrio "^" = Parsed 4
opPrio "(" = Parsed 1
opPrio ")" = Parsed 1
opPrio _ = NoParse

checkPrio :: Token Int -> Token Int -> Pref
checkPrio l r
    | l > r = PrLeft
    | l < r = PrRight
    | l == r = PrSame

pushPop :: String -> ([String], [String]) -> ([String], [String])
pushPop token ((p:ps), output) = (([token] ++ ps), ([p] ++ output))

freePile :: String -> ([String], [String]) -> ([String], [String])
freePile token ([], output) = ([token], output)
freePile token (("(":ps), output) = (([token] ++ ps), (output))
freePile token ((p:ps), output) = freePile token (ps, ([p] ++ output))

pushUntilRP :: ([String], [String]) -> ([String], [String])
pushUntilRP ([], output) = ([], output)
pushUntilRP (("(":ps), output) = (ps, output)
pushUntilRP ((p:ps), output) = case  isOp p of
    Parsed _ -> pushUntilRP (ps, ([p] ++ output))

toPile :: String -> ([String], [String]) ->  ([String], [String])
toPile token ([], output) = ([token], output)
toPile ")" (pile, output) = (pushUntilRP(pile, output))
toPile "(" (pile, output) = ((["("] ++ pile), output)
toPile "^" (pile, output) = ((["^"] ++ pile), output)
toPile token (pile, output) = case (checkPrio (opPrio token) (opPrio (pile!!0))) of
    PrLeft -> ([token] ++ pile, output)
    PrRight -> (freePile token (pile, output))
    PrSame -> (pushPop token (pile, output))

reverseList [] = []
reverseList (x:xs) = reverseList xs ++ [x]

shuntingYard :: [String] -> ([String], [String]) -> IO [String]
shuntingYard [] ([], output) = return output
shuntingYard [] ((p:ps), output) = shuntingYard [] (ps, ([p] ++ output))
shuntingYard (c:cs) (pile, output) = case isOp c of
        Parsed _ -> do
            -- print(cs)
            -- printf ("[%s] | ") c
            -- print (pile, reverseList output)
            -- printf ("\n")
            (shuntingYard cs (toPile c (pile, output)))
        NoParse -> do
            -- print(cs)
            -- printf ("[%s] | ") c
            -- print (pile, reverseList output)
            -- printf ("\n")
            (shuntingYard cs (pile, ([c] ++ output)))

exec :: String -> IO [String]
exec s = shuntingYard (fCutStr s) ([], [])