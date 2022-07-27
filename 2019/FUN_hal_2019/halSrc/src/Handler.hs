--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- Handler
--

module Handler
(
    pairToList,
    findValue,
    addBinding,
    printResult,
    myExit
) where

import Data
import System.Exit
import Text.Printf

myExit :: String -> Int -> IO()
myExit msg code = do
    printf "%s" msg
    if (code == 84) then exitWith (ExitFailure 84)
    else exitWith (ExitSuccess)

pairToList :: Expression -> [Expression]
pairToList Null = []
pairToList (Pair first rest) = first : pairToList rest

findValue :: Env -> String -> Expression
findValue expr val@"+" = Prim val
findValue expr val@"-" = Prim val
findValue expr val@"*" = Prim val
findValue expr val@"<" = Prim val
findValue expr val@"div" = Prim val
findValue expr val@"mod" = Prim val
findValue expr val@"cons" = Prim val
findValue expr val@"car" = Prim val
findValue expr val@"cdr" = Prim val
findValue expr val@"list" = Prim val
findValue expr val@"eq?" = Prim val
findValue [] toFind = Exception ("*** ERROR : variable " ++ toFind ++ " is not bound.")
findValue ((str, val):xs) toFind = if (str == toFind) then (val) else (findValue xs toFind)

addBinding :: Env -> String -> Expression -> Env
addBinding env name value = env ++ [(name, value)]

isList :: Expression -> Bool
isList Null = True
isList (Pair _ second) = isList second
isList _ = False

showPairList :: Expression -> String
showPairList Null = ""
showPairList (Pair first (Null)) = (exprToString first)
showPairList (Pair first second) = (exprToString first) ++ " " ++ (showPairList second)

exprToString :: Expression -> String
exprToString (Number val) = show val
exprToString (Variable val) = show val

arrayToString :: [String] -> IO ()
arrayToString [] = putStr ""
arrayToString (x:")":xs) = do
    putStr x
    putStr ")"
    arrayToString xs
arrayToString ("(":xs) = do
    putStr "("
    arrayToString xs
arrayToString (x:[]) = do
    putStr x
arrayToString (x:xs) = do
    putStr x
    putStr " "
    arrayToString xs

printResult :: Expression -> IO ()
printResult (Number val) = print val
printResult (Array val) = (arrayToString val)
printResult (Boolean val) = case val of
    True -> putStrLn "#t"
    False -> putStrLn "#f"
printResult (Variable val) = print val
printResult pair@(Pair first second)
    | isList pair = putStrLn ("(" ++ (showPairList pair) ++ ")")
    | otherwise = putStrLn ("(" ++ (exprToString first) ++ " . " ++ (exprToString second) ++ ")")
printResult (Exception val) = putStrLn val
printResult _ = putStr ""