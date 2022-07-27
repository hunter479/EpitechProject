--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Algo
--

module  Algo(kmeans, usage) where

import  Gen
import  Misc
import  System.Random

removeLastAverage :: Int -> [(Int, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> IO ()
removeLastAverage incre meansValue clusters new averages
    | incre < length (clusters) = removeLastAverage (incre + 1) meansValue clusters (new ++ (createCleanCluster 0 (clusters !! incre) [])) averages
    | hasSameResult 0 meansValue new == 0 = printRes 0 averages new
    | otherwise = computeMean 0 [] new

genNewCluster :: [[(String, (Float, Float, Float))]] -> [(String, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]]
genNewCluster res current newAverage
    | length (current) /= 0 = genNewCluster (genNewRes 0 min cluster res []) (genNewCurrent ((length current) - 1) 0 0 current []) newAverage
    | otherwise = res
    where
        cluster = (current !! ((length current) -1))
        min = minDistance 0 (0, 1000.0) cluster newAverage

lastStep :: Int -> [(Int, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> IO ()
lastStep incre meansValue old newAverage newCluster
    | incre < length old = do
        lastStep (incre + 1) meansValue old newAverage (genNewCluster newCluster (old !! incre) newAverage)
    | otherwise = do
        removeLastAverage 0 meansValue newCluster [] newAverage

replaceCentroids :: Int -> [(Int, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> IO ()
replaceCentroids incre meansValue old new
    | incre < (length old) =  replaceCentroids (incre + 1) meansValue old (new ++ newCentroid)
    | otherwise = do
        lastStep 0 meansValue old new new
    where
        meanValue = snd (meansValue !! incre)
        newCentroid = [[(fst(old !! incre !! 0), meanValue)]]

buildMean :: Int -> Int -> (Float, Float, Float) -> [(String, (Float, Float, Float))] -> (Int, (Float, Float, Float))
buildMean incre colors (r, g, b) res
    | incre < length res = buildMean (incre + 1) colors (r + r2, g + g2, b + b2) res
    | otherwise = (colors, (r / nbCols, g / nbCols, b / nbCols))
    where
        (r2, g2, b2) = snd (res !! incre)
        nbCols = fromIntegral (colors)

computeMean :: Int -> [(Int, (Float, Float, Float))] -> [[(String, (Float, Float, Float))]] -> IO ()
computeMean incre meansValue res
    | incre < length res = computeMean (incre + 1) (meansValue ++ [colorsTab]) res
    | otherwise = do
        replaceCentroids 0 meansValue res []
    where
        colors = length (res !! incre)
        colorsTab = buildMean 0 colors (0.0, 0.0, 0.0) (res !! incre)

genCluster :: [[(String, (Float, Float, Float))]] -> [(String, (Float, Float, Float))] -> IO ()
genCluster res current
    | length (current) /= 0 = genCluster (genNewRes 0 min cluster res []) (genNewCurrent ((length current) - 1) 0 0 current [])
    | otherwise = computeMean 0 [] res
    where
        cluster = (current !! ((length current) - 1))
        min = minDistance 0 (0, 1000.0) cluster res

kmeans :: StdGen -> Int -> Int -> [[(String, (Float, Float, Float))]] -> [(String, (Float, Float, Float))] -> IO ()
kmeans seed incre k res current
    | incre < k - 1 = do
        seed <- newStdGen
        if (res == []) then do
            kmeans seed (incre + 1) k [[(current !! rand)]] (genNewCurrent rand 0 0 current [])
        else do kmeans seed (incre + 1) k (res ++ [[(current !! rand)]]) (genNewCurrent rand 0 0 current [])
    | otherwise = genCluster res current
    where
        rand = (doRandom seed ((length current) - 1)) !! 0