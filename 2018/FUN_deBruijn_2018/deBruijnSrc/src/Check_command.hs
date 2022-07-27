--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Command
--

module Check_command
    ( getStatus
    , isCheck
    , doCheck
    ) where

import Check_sq
import Check
import System.Exit

getStatus :: Bool -> IO()
getStatus bool = do
    if (bool == True)
        then putStrLn "OK"
    else putStrLn "KO"

isCheck :: Int -> String -> String -> Bool
isCheck size alpha input = do
    let tab = deBruijn_cut_sq size input alpha
    let status = is_deBruijn tab 0 size
    status

doCheck :: Int -> String -> IO ()
doCheck size alpha = do
    input <- getLine
    if (length input == 0)
        then do
            printUsage
            exitWith (ExitFailure 84)
    else getStatus (isCheck size alpha input)