--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- Parser
--

module Parser
(
    parsingSequence
) where

import Data

parsingSequence :: [String] -> [Expression]
parsingSequence [] = []
parsingSequence tokens = expr : parsingSequence rest
    where (expr, rest) = parsing tokens

parsing :: [String] -> (Expression, [String])
parsing [] = (Null, [])
parsing (x:xs)
    | x == "quote" = (Array (init xs), [])
    | x == "(" = parsingList xs
    | isNumber x = ((Number (read x :: Integer)), xs)
    | isSymbol x = ((Variable x), xs)
    | otherwise = (Null, [])

parsingList :: [String] -> (Expression, [String])
parsingList [] = (Null, [])
parsingList pattern@(x:xs)
    | x == ")" = (Null, xs)
    | otherwise = ((Pair a b), bs)
                where (a, as) = parsing pattern
                      (b, bs) = parsingList as
