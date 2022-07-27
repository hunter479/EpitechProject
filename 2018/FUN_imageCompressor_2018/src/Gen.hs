--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2018
-- File description:
-- Gen
--

module Gen(genNewCurrent, genNewRes, minDistance) where

genNewCurrent :: Int -> Int -> Int -> [(String, (Float, Float, Float))] -> [(String, (Float, Float, Float))] -> [(String, (Float, Float, Float))]
genNewCurrent pos nincre incre old new
    | (incre < length (old) && incre /= pos) = genNewCurrent pos (nincre + 1) (incre + 1) old (new ++ [(old !! incre)])
    | (incre < length (old) && incre == pos) = genNewCurrent pos nincre (incre + 1) old new
    | otherwise = new

genNewRes :: Int -> Int -> (String, (Float, Float, Float)) -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]] -> [[(String, (Float, Float, Float))]]
genNewRes incre min newtupple old new
    | incre < length (old) = do
        if (incre == min) then do
            genNewRes (incre + 1) min newtupple old (new ++ [put])
        else
            genNewRes (incre + 1) min newtupple old (new ++ [tmp])
    | otherwise = new
    where
        tmp = old !! incre
        put = tmp ++ [newtupple]

calcMin :: Int -> (Int, Float) -> (Float, Float, Float) -> (Float, Float, Float) -> (Int, Float)
calcMin incre min (r, g, b) (r2, g2, b2)
    -- | min == (0, 0.0) = (incre, calc)
    | calc < snd min = (incre, calc)
    | otherwise = min
    where
        calc = sqrt (((r - r2)**2) + ((g - g2)**2) + ((b - b2)**2))

minDistance :: Int -> (Int, Float) -> (String, (Float, Float, Float)) -> [[(String, (Float, Float, Float))]] -> Int
minDistance incre min color res
    | incre < length res = minDistance (incre + 1) (calcMin incre min (snd color) (snd (res !! incre !! 0))) color res
    | otherwise = fst min
