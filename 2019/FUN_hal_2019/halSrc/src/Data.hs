--
-- EPITECH PROJECT, 2019
-- FUN_hal_2019
-- File description:
-- Data
--

module Data where

type Env = [(String, Expression)]

data Expression = Null
                | Number Integer
                | Boolean Bool
                | Variable String
                | Array [String]
                | Prim String
                | Pair Expression Expression
                | Exception String
                | Lambda [Expression] Expression
                | Application Expression [Expression]
                | Definition Expression Expression
                | If Expression Expression Expression
                | Cond [(Expression, Expression)]
                deriving (Show, Eq)

symbolCharacters :: String
symbolCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_!?-+*/%<>#"

numberCharacters :: String
numberCharacters = "0123456789."

isSymbolCharacter :: Char -> Bool
isSymbolCharacter c = elem c symbolCharacters

isNumberCharacter :: Char -> Bool
isNumberCharacter c = elem c numberCharacters

isSymbol :: String -> Bool
isSymbol = all isSymbolCharacter

isNumber :: String -> Bool
isNumber = all isNumberCharacter
