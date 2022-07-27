--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Main
--

module  Main where

import  Lib
import  Algo
import  Args
import  Pixel
import  Tools
import  Distance
import  System.Exit
import  System.Random
import  Control.Monad
import  System.Environment

printCluster :: StdGen -> Int -> String -> [String] -> IO()
printCluster seed k content args
    | k == 0 = usage
    | k > length pixt = usage
    | otherwise = kmeans seed (-1) k []  pixt
    where
        tab = (lines content)
        pixt = (pixelTab tab)

main :: IO ()
main = do
    g <- getStdGen
    args <- getArgs
    if (verifArgs args < 0) then
        usage
    else do
        content <- readFile (args!!2)
        let tab = (lines content)
        let pixt = (pixelTab tab)
        printCluster g (isInt (args !! 0)) content args
