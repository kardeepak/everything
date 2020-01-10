import Data.List;

-- Problem 11 --
data Encoded a = Single a | Multiple Int a deriving Show
encodeModified :: (Eq a) => [a] -> [Encoded a]
encodeModified = map (\x -> encode (length x) (head x)) . group
    where   
        encode 1 x = Single x
        encode t x = Multiple t x

-- Problem 12 --
decodeModified :: [Encoded a] -> [a]
decodeModified = concatMap decode
    where
        decode (Single x) = [x]
        decode (Multiple t x) = replicate t x

-- Problem 13 --
