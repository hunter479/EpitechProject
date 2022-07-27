--
-- EPITECH PROJECT, 2019
-- fun_evalexpr
-- File description:
-- Error
--

module Error where

import System.Exit
import Text.Printf

data Val = IsVal | NotVal
    deriving (Eq, Ord, Show)

data Ans v = NotOK v | OK

chrCheck :: Char -> Val
chrCheck '0' = IsVal
chrCheck '1' = IsVal
chrCheck '2' = IsVal
chrCheck '3' = IsVal
chrCheck '4' = IsVal
chrCheck '5' = IsVal
chrCheck '6' = IsVal
chrCheck '7' = IsVal
chrCheck '8' = IsVal
chrCheck '9' = IsVal
chrCheck '.' = IsVal
chrCheck '+' = IsVal
chrCheck '-' = IsVal
chrCheck '/' = IsVal
chrCheck '*' = IsVal
chrCheck '(' = IsVal
chrCheck ')' = IsVal
chrCheck '^' = IsVal
chrCheck _ = NotVal

myExit :: String -> IO()
myExit msg = do
        printf "%s\n" msg
        exitWith (ExitFailure 84)

nbCountLP :: String -> Int -> Int
nbCountLP [] i = i
nbCountLP ('(':cs) i = nbCountLP (cs) (i + 1)
nbCountLP (c:cs) i = nbCountLP (cs) i

nbCountRP :: String -> Int -> Int
nbCountRP [] i = i
nbCountRP (')':cs) i = nbCountRP (cs) (i + 1)
nbCountRP (c:cs) i = nbCountRP (cs) i

checkPNb :: String -> Ans String
checkPNb s = do
    if ((nbCountLP s 0) == (nbCountRP s 0)) then OK else do
        NotOK ("Error: missing parentheses")

myStrCheck :: String -> Ans String
myStrCheck [] = OK
myStrCheck ('(':')':_) = NotOK "Error: Empty parenthesis"
myStrCheck (c:cs) = case chrCheck c of
    IsVal -> myStrCheck (cs)
    NotVal -> NotOK ("Error: Illegal character")

errorCheck :: String -> Ans String
errorCheck s = case ((length s == 0)) of
        True -> NotOK "Error: Empty string"
        _ -> case myStrCheck s of
                NotOK v -> NotOK v
                _ -> case checkPNb s of
                    NotOK v -> NotOK v
                    _ -> OK
