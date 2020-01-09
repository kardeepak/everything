-- Problem 1 --
myLast :: [a] -> a
myLast [] = error "No such element"
myLast (x:[]) = x
myLast (x:xs) = myLast xs


-- Problem 2 --
myButLast :: [a] -> a
myButLast (x:[]) = error "No such element"
myButLast (x:y:[]) = x
myButLast (x:y:xs) = myButLast (y:xs)


-- Problem 3 --
elementAt :: [a] -> Int -> a
elementAt (x:_) 1 = x
elementAt (_:xs) k
    | k <= 0  = error "Index Out of Bounds"
    | otherwise = elementAt xs (k-1)
elementAt _ _ = error "Index Out of Bounds"


-- Problem 4 --
myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs


-- Problem 5 --
myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myReverse xs ++ [x]


-- Problem 6 --
isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome x = (x == reverse x)


-- Problem 7 --
data NestedList a = Elem a | List [NestedList a]
flatten :: NestedList a -> [a]
flatten (Elem x) = [x]
flatten (List x) = concatMap flatten x


-- Problem 8 --
compress :: [a] -> [a]
compress (x:x:xs) = x:xs
