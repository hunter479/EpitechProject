--
-- EPITECH PROJECT, 2019
-- fun_evalexpr
-- File description:
-- Calc
--

module Calc where

import ShuntingYard

data Result v = IParse v | NoIParse

toFloat :: String -> Float
toFloat [] = 0
toFloat s = read s :: Float

myAdd :: String -> String -> Float
myAdd [] s2 = toFloat s2
myAdd s1 [] = toFloat s1
myAdd s1 s2 = (toFloat s1) + (toFloat s2)

mySub :: String -> String -> Float
mySub [] s2 = toFloat s2
mySub s1 [] = toFloat s1
mySub s1 s2 = (toFloat s1) - (toFloat s2)

myMul :: String -> String -> Float
myMul [] s2 = toFloat s2
myMul s1 [] = toFloat s1
myMul s1 s2 = (toFloat s1) * (toFloat s2)

myDiv :: String -> String -> Float
myDiv [] s2 = toFloat s2
myDiv s1 [] = toFloat s1
myDiv s1 s2 = (toFloat s1) / (toFloat s2)

myPow :: String -> String -> Float
myPow [] s2 = toFloat s2
myPow s1 [] = toFloat s1
myPow s1 s2 = (toFloat s1) ** (toFloat s2)

isCalc :: String -> String -> String -> Result Float
isCalc [] [] [] = NoIParse
isCalc _ "0" "/" = NoIParse
isCalc "0" _ "*" = IParse 0
isCalc _ "0" "*" = IParse 0
isCalc a b "+" = IParse (myAdd a b)
isCalc a b "-" = IParse (mySub a b)
isCalc a b "*" = IParse (myMul a b)
isCalc a b "/" = IParse (myDiv a b)
isCalc a b "^" = IParse (myPow a b)
isCalc _ _ _ = NoIParse

calc :: [String] -> [String] -> Result [String]
calc (a:[]) [] = IParse [a]
calc (a:b:[]) [] = case isCalc a b [] of
    IParse d -> IParse [show d]
    NoIParse -> NoIParse
calc (a:b:c:rest) [] = case isCalc a b c of
    NoIParse -> calc ([b]++[c]++rest) ([a])
    IParse d -> calc ([show d] ++ rest) []
calc (a:b:c:rest) (x:xs) = case isCalc a b c of
    NoIParse -> calc ([b]++[c]++rest) ([a] ++ [x] ++ xs)
    IParse d -> calc ([x] ++[show d] ++ rest) (xs)

doCalc :: [String] -> Result Float
doCalc st = case calc (reverseList st) [] of
    IParse v -> case ((length v) == 1) of
            True -> IParse (read (v!!0) :: Float)
            False -> NoIParse
    NoIParse -> NoIParse
