--
-- EPITECH PROJECT, 2020
-- FUN_hal_2019
-- File description:
-- Function
--

module Function where

import Data


eqExpr :: [Expression] -> Expression
eqExpr ((Number num1):(Number num2):[]) = Boolean (num1 == num2)

modNumbers :: [Expression] -> Expression
modNumbers ((Number num1):(Number num2):[]) = Number (mod num1 num2)

divNumbers :: [Expression] -> Expression
divNumbers ((Number num1):(Number num2):[]) = Number (div num1 num2)

addNumbers :: [Expression] -> Expression
addNumbers ((Number num1):(Number num2):[]) = Number (num1 + num2)
addNumbers _ = Exception "Can only add two numbers"

subNumbers :: [Expression] -> Expression
subNumbers ((Number num1):(Number num2):[]) = Number (num1 - num2)
subNumbers _ = Exception "Can only subtract 2 numbers"

nbLessThan :: [Expression] -> Expression
nbLessThan ((Number num1):(Number num2):[]) = (Boolean (num1 < num2))
nbLessThan _ = Exception "Can't compare non-numbers."

mulNumbers :: [Expression] -> Expression
mulNumbers ((Number num1):(Number num2):[]) = Number (num1 * num2)
mulNumbers _ = Exception "Can only add two numbers"

pairFirst :: [Expression] -> Expression
pairFirst ((Pair first second):[]) = first
pairFirst _ = Exception "'car' is an operation defined on a pair."

pairSecond :: [Expression] -> Expression
pairSecond ((Pair first second):[]) = second
pairSecond _ = Exception "'cdr' is an operation defined on a pair."

createList :: [Expression] -> Expression
createList [] = Null
createList (e:es) = Pair e (createList es)

createPair :: [Expression] -> Expression
createPair (first:second:[]) = Pair first second
createPair _ = Exception "A pair can only be created from 2 values"
