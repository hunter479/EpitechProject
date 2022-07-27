--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Gen
--

module Gen
( getLast_Nchar
, getLast_Poschar
, genFst_sq
, deBruijn_gen
) where

import Data.List
import Data.Maybe (catMaybes)

count :: Eq a => [a] -> [a] -> Int
count sub = length . catMaybes . map (stripPrefix sub) . tails

getLast_Poschar :: Int -> String -> String
getLast_Poschar n str = do
    let ref = drop ((length str) - n) str
    let (a, b) = splitAt 1 ref
    a

getLast_Nchar :: Int -> String -> String
getLast_Nchar n str = do
    let ref = drop ((length str) - n) str
    let (a, b) = splitAt n ref
    a

genFst_sq :: Int -> Int -> Char -> String -> String
genFst_sq n size c ret = do
    if (n /= size)
        then genFst_sq (n + 1) size c (ret ++ [c])
    else
        ret

deBruijn_gen :: Int -> Int -> String -> String -> String
deBruijn_gen _ 0 _ _ = []
deBruijn_gen _ _ [] _ = []

deBruijn_gen n size alpha [] = do
    let ret = (genFst_sq 0 size (alpha!!0) [])
    deBruijn_gen n size alpha ret

deBruijn_gen n size alpha ret = do
    let char = (getLast_Poschar n alpha)
    let tmp = (getLast_Nchar (size - 1) ret) ++ char
    if (n == length(alpha) + 1)
        then fst (splitAt ((length ret) - size + 1) ret)
    else if ((count tmp ret) == 0)
        then deBruijn_gen 1 size alpha (ret ++ char)
    else deBruijn_gen (n + 1) size alpha (ret)
