import Data.List;

-- Problem 1 --
myLast :: [a] -> a
myLast = head . reverse

-- Problem 2 --
myButLast :: [a] -> a
myButLast = head . tail . reverse

-- Problem 3 --
elementAt :: [a] -> Int -> a
elementAt x k = x !! (k-1)

-- Problem 4 --
myLength :: [a] -> Int
myLength = length

-- Problem 5 --
myReverse :: [a] -> [a]
myReverse = reverse

-- Problem 6 --
isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome xs = (xs == reverse xs)

-- Problem 7 --
data NestedList a = Elem a | List [NestedList a]
flatten :: NestedList a -> [a]
flatten (Elem x) = [x]
flatten (List x) = concatMap flatten x

-- Problem 8 --
compress :: (Eq a) => [a] -> [a]
compress = map head . group

-- Problem 9 --
pack :: (Eq a) => [a] -> [[a]]
pack = group

-- Problem 10 --
encode :: (Eq a) => [a] -> [(Int, a)]
encode = map (\x -> (length x, head x)) . group
