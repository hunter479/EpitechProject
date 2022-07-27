--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Check_clean
--

module Check_clean
    ( doClean
    , cleanTab
    ) where

import System.Environment
import System.Exit
import Unique_command

check_doublon :: String -> [String] -> Bool
check_doublon ref [] = True
check_doublon ref tab = do
    if (strcmp ref (tab!!0) 0 == True)
        then False
    else check_doublon ref (drop 1 tab)

print_Tab :: [String] -> IO ()
print_Tab tab = do
    if (tab /= [])
        then do
            putStrLn (tab!!0)
            print_Tab (drop 1 tab)
    else putStr ""

cleanTab :: Int -> String -> [String] -> [String] -> Int -> [String]
cleanTab _ _ [] _ _ = []
cleanTab size alpha tab ret n = do
    if (n == length tab)
        then ret
        else do
            let (a, b) = splitAt 1 tab
            if ((checkUnique (a!!0) b (0) size alpha) == True) && ((check_doublon (a!!0) ret) == True)
                then cleanTab size alpha (b ++ a) (ret ++ a) (n + 1)
            else
                cleanTab size alpha (b ++ a) (ret) (n + 1)

doClean :: Int -> String -> [String] -> IO()
doClean size alpha tab = do
    str <- getLine
    if (str == "END")
        then do
            if (tab == []) then exitWith (ExitFailure 84)
            else do
                let clean = (cleanTab size alpha tab [] 0)
                print_Tab clean
    else
        doClean size alpha (if str == [] then tab else (tab ++ [str]))
