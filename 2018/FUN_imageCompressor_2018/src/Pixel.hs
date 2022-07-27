--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Pixel
--

module Pixel
    ( doPixel,
    pixelTab
    ) where

import Distance
import Tools

pixelTab :: [String] -> [(String, (Float, Float, Float))]
pixelTab [] = [doPixel []]
pixelTab (c:[]) = [doPixel c]
pixelTab (c:cs) = (doPixel c) : (pixelTab cs)

doPixel :: String -> (String, (Float, Float, Float))
doPixel [] = ([], (0, 0 ,0))
doPixel str = do
    let (a, x) = getCoord str
    let b = tuppleIt x
    (a, b)