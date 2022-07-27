--
-- EPITECH PROJECT, 2019
-- FUN_deBruijn_2018
-- File description:
-- Check_sq
--

module Check_sq
    ( deBruijn_cut_sq
    , is_deBruijn
    ) where

frequency :: String -> [String] -> Int -> Int
frequency str [] result = result
frequency str list result = do
    if (str == (list!!0))
        then frequency str (drop 1 list) (result + 1)
    else frequency str (drop 1 list) result

cut_sq :: Int -> String -> [String] -> [String]
cut_sq 0 _ _ = []
cut_sq 1 str _ = [str]
cut_sq n str tab = do
    let (a, b) = splitAt n str
    if (length b == 0)
        then do
            tab ++ [a]
    else
        cut_sq n (drop 1 str) (tab ++ [a])

checkOccur :: String -> String -> Int -> Int
checkOccur alphabet str idx = do
    if (idx == length str)
        then 0
    else do
        if (length $ filter (== (str !! idx)) alphabet) == 0
            then -1
        else checkOccur alphabet str (idx + 1)

deBruijn_cut_sq :: Int -> String -> String -> [String]
deBruijn_cut_sq n str alpha = do
    if (length str == 0)
        then []
    else if (((length alpha)^n) /= (length str)) || ((checkOccur alpha str 0 )== -1)
        then []
    else do
        let (a, b) = splitAt (n - 1) str
        cut_sq n (str ++ a) []

is_deBruijn :: [String] -> Int -> Int -> Bool
is_deBruijn _ _ 1 = True
is_deBruijn list n size = do
    if (length list == 0)
        then False
    else if n == (length list)
        then True
    else if ((frequency (list!!n) list 0) /= 1)
        then False
    else is_deBruijn (list) (n + 1) size
