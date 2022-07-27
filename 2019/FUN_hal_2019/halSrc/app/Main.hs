module Main where

import System.Environment
import System.IO

import Data
import Parser
import Tokenize
import AnalyseExp
import Handler
import Expr

core :: Env -> String -> IO (Env, Expression)
core env line = do
    let token = tokenize line
    let parse = parsingSequence token
    let expr = analyzeExpressionSequence parse
    -- let parse = analyzeExpressionSequence . parsingSequence . tokenize
    -- let expr = parse line
    let (newEnv, res) = (evalSequence env expr)
    return (newEnv, res)

loadEnv :: String -> IO Env
loadEnv path = do
    loaded <- readFile path
    (env, _) <- (core [] loaded)
    return env

execInterpreter :: Env -> Bool -> IO()
execInterpreter env False = do
    end <- isEOF
    if end then (myExit "" 0)
    else do
        line <- getLine
        (_, res) <- (core env line)
        printResult res
        hFlush stdout
execInterpreter env True = do
    end <- isEOF
    if end then (myExit "" 0)
    else do
        line <- getLine
        (newEnv, res) <- (core env line)
        printResult res
        hFlush stdout
        execInterpreter newEnv True

main :: IO ()
main = do
    args <- getArgs
    case args of
        [] -> execInterpreter [] True
        x:[] -> case x of
            "-i" -> execInterpreter [] True
            file -> do
                cmd <- readFile file
                (_, res) <- (core [] cmd)
                printResult res
                case res of
                    Exception _ -> (myExit "" 84)
                    _ -> (myExit "" 0)
        x:xs:[] -> case xs of
            "-i" -> do
                env <- loadEnv x
                execInterpreter env True
            file -> do
                env <- loadEnv x
                cmd <- readFile file
                (_, res) <- (core env cmd)
                printResult res
                case res of
                    Exception _ -> (myExit "" 84)
                    _ -> (myExit "" 0)
        x:xs:rest -> (myExit "Too many arguments\n" 84)