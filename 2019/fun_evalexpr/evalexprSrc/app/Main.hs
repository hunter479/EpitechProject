module Main where

import System.Environment
import System.Exit
import Text.Printf
import Error
import Parser
import ShuntingYard
import Calc

main :: IO ()
main = do
    args <- getArgs
    case args of
        [] -> myExit ("Error: missing argument")
        (c:[]) -> do
            let cl = (filter (/=' ') c)
            case errorCheck cl of
                NotOK final -> myExit final
                OK -> do
                    p <- exec cl
                    case doCalc p of
                        IParse total -> printf "%.2f\n" total
                        NoIParse -> myExit ("Error: error in expression")
        (c:_) -> myExit ("Error: too many arguments")