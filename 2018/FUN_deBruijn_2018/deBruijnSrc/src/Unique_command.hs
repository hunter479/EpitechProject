--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Unique_command
--

module Unique_command
( isUnique
, doUnique
, checkUnique
, strcmp
) where

import Data.String
import Check
import Check_command
import Check_sq
import System.Exit

strcmp :: String -> String -> Int -> Bool
strcmp ref str n = do
    if (n == (length str))
        then False else do
        if (ref == str)
            then True
        else do
            let (a, b) = splitAt 1 ref
            strcmp (b ++ a) str (n + 1)

checkUnique :: String -> [String] -> Int -> Int -> String -> Bool
checkUnique _ [] _ _ _ = False
checkUnique ref list n size alpha = do
    if ((n + 1) == length list)
        then True
    else if (((isCheck size alpha ref) == False))
        then False
    else if ((strcmp ref (list!!n) 0) == True)
        then True
    else checkUnique ref list (n + 1) size alpha

isUnique :: Int -> String -> [String] -> Bool
isUnique size alpha list = do
    if (((isCheck size alpha (list!!0)) == False))
        then False
    else if (((isCheck size alpha (list!!1)) == False))
        then False
    else if ((strcmp (list!!0) (list!!1) 0) == True)
        then False
    else True

doUnique :: Int -> String -> IO()
doUnique size alpha = do
    a <- getLine
    b <- getLine
    let tab = [a, b]
    if ((length a) == 0 || (length b) == 0)
        then do
            printUsage
            exitWith (ExitFailure 84)
    else getStatus (isUnique size alpha tab)