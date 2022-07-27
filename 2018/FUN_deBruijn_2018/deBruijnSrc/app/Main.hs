--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Main
--

module Main where

import System.Environment
import System.Exit
import Gen
import Check
import Check_sq
import Check_clean
import Check_command
import Unique_command

launch_gen :: Int -> String -> IO()
launch_gen size alpha = do
    if (size <= 0) then exitWith (ExitFailure 84)
    else
        putStrLn (deBruijn_gen 1 size alpha [])

launch_cmd :: Int -> String -> String -> IO()
launch_cmd size alpha command = do
    if (size <= 0)
        then do
            printUsage
            exitWith (ExitFailure 84)
    else if (command == "--check")
        then (doCheck size alpha)
    else if (command == "--unique")
        then (doUnique size alpha)
    else if (command == "--clean")
        then (doClean size alpha [])
    else do
        printUsage
        exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    if ((check_args args) == False)
        then do
            printUsage
            exitWith (ExitFailure 84)
    else if (length args == 2 && (is_command (args!!1)) == True)
        then launch_cmd (read (args!!0) :: Int) "01" (args!!1)
    else if (length args == 3)
        then launch_cmd (read (args!!0) :: Int) (args!!1) (args!!2)
    else if (length args == 1)
        then launch_gen (read (args!!0) :: Int) "01"
    else
        launch_gen (read (args!!0) :: Int) (args!!1)