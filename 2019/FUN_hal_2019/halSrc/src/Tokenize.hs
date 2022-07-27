--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- Tokenize
--

module Tokenize
(
    tokenize
) where

import Data

tokenize :: String -> [String]
tokenize [] = []
tokenize (x:xs)
    | x == '(' = [x] : tokenize xs
    | x == ')' = [x] : tokenize xs
    | isNumberCharacter x = tokenizeNumber (x:xs) ""
    | isSymbolCharacter x = tokenizeSymbol (x:xs) ""
    | otherwise = tokenize xs

tokenizeNumber :: String -> String -> [String]
tokenizeNumber [] number = [number]
tokenizeNumber (x:xs) number
    | isNumberCharacter x = tokenizeNumber xs (number ++ [x])
    | otherwise = number : tokenize (x:xs)

tokenizeSymbol :: String -> String -> [String]
tokenizeSymbol [] symbol = [symbol]
tokenizeSymbol (x:xs) number
    | isSymbolCharacter x = tokenizeSymbol xs (number ++ [x])
    | otherwise = number : tokenize (x:xs)
