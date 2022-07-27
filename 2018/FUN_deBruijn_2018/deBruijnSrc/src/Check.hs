--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Check
--

module Check
( printUsage
, is_command
, check_nbr
, check_args
) where

import System.Environment
import System.Exit

printUsage :: IO ()
printUsage = do
    putStrLn "USAGE: ./deBruijn n [a] [--check|--unique|--clean]\n"
    putStrLn "--check     check if a sequence is a de Bruijn sequence"
    putStrLn "--unique    check if 2 sequences are distinct de Bruijn sequences"
    putStrLn "--clean     list cleaning"
    putStrLn "n           order of the sequence"
    putStrLn "a           alphabet [def: “01”]"

is_command :: String -> Bool
is_command str = do
    if str == "--check"
        then True
    else if str == "--unique"
        then True
    else if str == "--clean"
        then True
    else
        False

check_nbr :: String -> Int -> Bool
check_nbr str n = do
    if (n == length str)
        then True
    else if ((str!!n) >= '0' && (str!!n) <= '9')
        then check_nbr str (n + 1)
    else
        False

check_args :: [String] -> Bool
check_args array = do
    let sizeArray = length array
    if ((sizeArray == 0) || (sizeArray > 3))
        then False
    else if ((check_nbr (array!!0) 0) == False)
        then False
    else if (sizeArray == 3)
        then (((is_command (array!!1)) == False) && (is_command (array!!2)) == True)
    else
        True
