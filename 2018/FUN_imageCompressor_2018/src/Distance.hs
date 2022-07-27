--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Distance
--

module Distance
    ( vectorDistance,
    getCoord,
    toMiddle
    ) where

vectorDistance :: (Float, Float, Float) -> (Float, Float, Float) -> Float
vectorDistance (x1 , y1, z1) (x2 , y2, z2) = sqrt (x'*x' + y'*y' + z'*z')
    where
        x' = x1 - x2
        y' = y1 - y2
        z' = z1 - z2

toMiddle :: String -> Int -> Int -> Int
toMiddle [] _ _ = 0
toMiddle str 2 x = (x - 1)
toMiddle str findTime x = do
    if (str!!0 == '(') then (toMiddle (drop 1 str) (findTime + 1) (x + 1))
    else (toMiddle (drop 1 str) (findTime) (x + 1))

getCoord :: String -> (String, String)
getCoord [] = ([], [])
getCoord str = ((init(a)), b)
    where
        (a, b) = (splitAt (toMiddle str 0 0) str)
