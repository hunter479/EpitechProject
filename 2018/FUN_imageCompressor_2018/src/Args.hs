--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Args
--

module  Args (verifArgs, isInt) where

import  Text.Read
import  Control.Monad

isInt :: String -> Int
isInt [] = -1
isInt arg = case readMaybe arg :: Maybe Int of
            Nothing -> -1
            Just _ -> read arg :: Int

verifArgs :: [String] -> Int
verifArgs args
    | ((length args) /= 3) = -1
    | ((isInt (args !! 0)) < 0) = -1
    | otherwise = 0