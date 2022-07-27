--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Misc
--

module Misc (doRandom, printRes, usage, hasSameResult, createCleanCluster) where

import  Text.Printf
import  System.Exit
import  System.Random

usage = do readFile "usage.txt" >>= putStr; exitWith (ExitFailure 84)

printSubRes :: Int -> [(String, (Float, Float, Float))] -> IO ()
printSubRes incre res
    | incre < (length res) = do
        putStr pos
        putStr " "
        print ((round r, round g, round b))
        printSubRes (incre + 1) res
    | otherwise = putStr ""
    where
        pos = fst (res !! incre)
        (r, g, b) = snd (res !! incre)

printRes :: Int -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> IO ()
printRes incre averages res
    | incre < (length averages) = do
        putStrLn "--"
        printf "(%.2f, %.2f, %.2f)\n" r g b
        putStrLn "-"
        printSubRes 0 (res !! incre)
        printRes (incre + 1) averages res
    | otherwise = putStr ""
    where
        (r, g, b) = snd (averages !! incre !! 0)

doRandom :: StdGen -> Int -> [Int]
doRandom seed limit = take 1 (randomRs (0, limit) seed :: [Int])

calcMean :: Int -> Int -> (Float, Float, Float) -> [(String, (Float, Float, Float))] -> (Int, (Float, Float, Float))
calcMean incre colors (r, g, b) res
    | incre < length res = calcMean (incre + 1) colors (r + r2, g + g2, b + b2) res
    | otherwise = (colors, (r / nbCols, g / nbCols, b / nbCols))
    where
        (r2, g2, b2) = snd (res !! incre)
        nbCols = fromIntegral (colors)

hasSameResult :: Int -> [(Int, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> Int
hasSameResult incre means res
    | (incre < (length means) && lastTotal == previousTotal && (r == r2) && (g == g2) && (b == b2) ) = hasSameResult (incre + 1) means res
    | incre /= (length means) = 1
    | otherwise = 0
    where
        (r, g, b) = snd (means !! incre)
        (r2, g2, b2) = snd (calcMean 0 (length (res !! incre)) (0.0, 0.0, 0.0) (res !! incre))
        previousTotal = (fst (means !! incre))
        lastTotal = (length (res !! incre))

createCleanCluster :: Int -> [(String, (Float, Float, Float))] -> [(String, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]]
createCleanCluster incre toDup res
    | incre < length toDup && incre == 0 = createCleanCluster (incre + 1) toDup res
    | incre < length toDup && incre /= 0 = createCleanCluster (incre + 1) toDup (res ++ [toDup !! incre])
    | otherwise = [res]