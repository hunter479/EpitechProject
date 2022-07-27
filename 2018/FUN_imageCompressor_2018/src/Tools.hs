--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Tools
--

module Tools
    ( split,
    tuppleIt
    ) where

split :: String -> [String]
split [] = [[]]
split (',':cs) = [] : split cs
split (c:cs) = (c:cellCompletion) : otherCells
    where cellCompletion : otherCells = split cs

tuppleIt :: String -> (Float, Float, Float)
tuppleIt [] = (0, 0, 0)
tuppleIt str = do
    let tab = (split str)
    (read(tail(tab!!0))::Float, read(tab!!1)::Float, read(init(tab!!2))::Float)
